# Programs to use for creating dependencies, compiling source files, and creating the library file, respectively
DEP = sdcc
CC  = sdcc
LIB = sdcclib

# Flags for above programs when calling them from the command line
DFLAGS = -MM $(INCDIRS) $<
CFLAGS = --model-large --std-c99 $(INCDIRS) -c $< -o "$(OBJDIR)/"
LFLAGS =

# File extensions for dependency files, source files, object files, and library files, respectively
DEPEXT = d
SRCEXT = c
OBJEXT = rel
LIBEXT = lib

# Compiler version
ifneq ($(MINCOMPILERBUILD),)
CCVERSION := $(subst \#,,$(filter \#%,$(strip $(shell $(CC) -v))))
CCVERSIONOK := $(shell [ $(CCVERSION) -ge $(MINCOMPILERBUILD) ] && echo "YES" || echo "NO")
ifeq ($(CCVERSIONOK),NO)
$(error "The build has detected an SDCC build of #$(CCVERSION). This library must be built by an SDCC build of at least #$(MINCOMPILERBUILD). Please update your SDCC installation.")
endif
endif

# Target directory
TARGETDIR = $(TARGETRELTOSUBSRCREL)

# Source dir name, include directories, and sub source dir
NAME := $(shell $(PWD) | $(SED) -e 's_/.*/__' | $(SED) -e 's_\S.*\\__')
INCDIRS = -I../../include -I$(TARGETDIR)/include $(foreach dir,$(strip $(EXTERNINCDIRS)),-I../$(dir))
LCLSRCDIR = src

# Directories for objects, dependencies, and library files
OBJDIR = $(TARGETDIR)/$(TARGETOBJDIRREL)/$(NAME)
DEPDIR = $(TARGETDIR)/$(TARGETDEPDIRREL)/$(NAME)
LIBDIR = $(TARGETDIR)/$(TARGETLIBDIRREL)

# Name of library file, list of source files, object files, and dependency files
LIBFILE = $(LIBDIR)/$(NAME).$(LIBEXT)
SRCFILES := $(shell $(LS) $(LCLSRCDIR)/*.$(SRCEXT))
OBJFILES = $(subst .$(SRCEXT),.$(OBJEXT),$(subst $(LCLSRCDIR),$(OBJDIR),$(SRCFILES)))
DEPFILES = $(subst .$(SRCEXT),.$(DEPEXT),$(subst $(LCLSRCDIR),$(DEPDIR),$(SRCFILES)))

# Used to makes sure source files get built if their dependency files are modified
-include $(DEPFILES)

all: build

build: $(LIBFILE)

$(LIBDIR)/%.$(LIBEXT): $(OBJFILES)
	$(ECHO)
	$(ECHO) "Building library file '$@'"
	[ -d $(LIBDIR) ] || $(MKDIR) $(LIBDIR) > $(BLACKHOLE)
	$(LIB) $(LFLAGS) $@ $(OBJFILES)
	$(ECHO) "Finished building library file '$@'"
	$(ECHO)

$(OBJDIR)/%.$(OBJEXT) : $(LCLSRCDIR)/%.$(SRCEXT) $(DEPDIR)/%.$(DEPEXT)
	$(ECHO)
	$(ECHO) "Building object file '$@'"
	[ -d $(OBJDIR) ] || $(MKDIR) $(OBJDIR) > $(BLACKHOLE)
	$(CC) $(CFLAGS)
	$(ECHO) "Finished building object file '$@'"

$(DEPDIR)/%.$(DEPEXT): $(LCLSRCDIR)/%.$(SRCEXT)
	$(ECHO)
	$(ECHO) "Building dependency file '$@'"
	[ -d $(DEPDIR) ] || $(MKDIR) $(DEPDIR) > $(BLACKHOLE)
	$(ECHO) "$(OBJDIR)/" | $(TR) -d '\n' | $(TR) -d '\r' > $@.tmp
	$(DEP) $(DFLAGS) >> $@.tmp
	$(SED) 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@
	$(RM) -f $@.tmp
	$(ECHO) "Finished building dependency file '$@'"

.SECONDARY: $(OBJFILES) $(DEPFILES)
