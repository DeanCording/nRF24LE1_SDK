###############################################
### Begin user-specific portion of Makefile ###
###############################################

# Add directories here that appear under the <top level>/src folder that should not be compiled
SUBSRCDIRSTOFILTER =

# If the build target name is non-standard, enter the standard build target found in libraries here to override.
#  Leave this blank if this build target has a standard name.
EXTERNALTARGETNAME =

# If the source code requires a minimum version of a compiler build, then enter it here.  This value must be an integer!
#  Leave this blank if the source can be built with any compiler version.
export MINCOMPILERBUILD =

#############################################
### End user-specific portion of Makefile ###
#############################################

# Functions needed by this makefile and the one that builds the source libraries (MakefileSrc)
export ECHO = @echo
export RM = rm
export SED = sed
export MKDIR = mkdir -p
export TR = tr
export BLACKHOLE = /dev/null
export PWD = pwd
export CD = cd
export LS = ls

# Name for this build target
export TARGETNAME := $(shell $(PWD) | $(SED) -e 's_/.*/__' | $(SED) -e 's_\S.*\\__')

# Name for external build target
ifeq ($(EXTERNALTARGETNAME),)
EXTERNALTARGETNAMELCL = $(TARGETNAME)
else
EXTERNALTARGETNAMELCL = $(EXTERNALTARGETNAME)
endif

# Directories related to the library and location of the local source tree
TOPLEVELREL = ..
LIBNAME := $(shell $(CD) .. && $(PWD) | $(SED) -e 's_/.*/__' | $(SED) -e 's_\S.*\\__' && $(CD) $(TARGETNAME))
TARGETTOSRCDIRREL = $(TOPLEVELREL)/src
SRCTOTARGETDIRREL = ../$(TARGETNAME)
LOCALSRCRELTOTARGET = ../../$(TARGETNAME)

# Include directories (outside this folder) that the sub makes need to know about
EXTERNLIBS = $(filter-out $(LIBNAME),$(filter lib_%,$(subst /.,,$(strip $(shell $(CD) ../.. && $(LS) -d */. && $(CD) $(LIBNAME)/$(TARGETNAME))))))
export EXTERNINCDIRS = $(foreach dir,$(EXTERNLIBS),../../$(dir)/include ../../$(dir)/$(EXTERNALTARGETNAMELCL)/include)

# Directories related to the build process of the target
export TARGETDIR = $(TARGETNAME)
export TARGETLIBDIRREL = lib
export TARGETOBJDIRREL = obj
export TARGETDEPDIRREL = dep
export TARGETSRCMAKEFILE = $(LOCALSRCRELTOTARGET)/MakefileSrc
export TARGETRELTOSUBSRCREL = ../../$(TARGETNAME)
TARGETLIB = $(TARGETLIBDIRREL)/nrf24le1.lib

# Directories inside the local source tree
SUBSRCDIRSRAW := $(subst /.,,$(strip $(shell $(CD) $(TARGETTOSRCDIRREL) && $(LS) -d */. && $(CD) $(SRCTOTARGETDIRREL))))
ifeq ($(SUBSRCDIRSRAW),)
$(error There are no source directories to clean/build)
endif
SUBSRCDIRSRAWFILT := $(filter-out $(SUBSRCDIRSTOFILTER),$(SUBSRCDIRSRAW))
ifeq ($(SUBSRCDIRSRAWFILT),)
$(error There are available source directories to clean/build, but they have been filtered out by SUBSRCDIRSTOFILTER)
endif
SUBSRCDIRS := $(foreach dir,$(SUBSRCDIRSRAWFILT),$(TARGETTOSRCDIRREL)/$(dir))


all:
	$(ECHO)
	$(ECHO) "Building target '$(TARGETNAME)' for library collection '$(LIBNAME)'"
	@$(MAKE) $(SUBSRCDIRS)
	-rm $(TARGETLIB)
	sdcclib a $(TARGETLIB) obj/*/*.rel
	$(ECHO)
	$(ECHO) "Finished building target '$(TARGETNAME)' for library collection '$(LIBNAME)'"

$(SUBSRCDIRS):
	$(ECHO)
	$(ECHO) "Building library '$(@F)'"
	$(MAKE) -C $@ all
	$(ECHO) "Finished building library '$(@F)'"

clean:
	$(ECHO)
	$(ECHO) "Cleaning target '$(TARGETNAME)' for library '$(LIBNAME)'"
	$(if $(TARGETLIBDIRREL),$(RM) -rf $(TARGETLIBDIRREL)/*)
	$(if $(TARGETOBJDIRREL),$(RM) -rf $(TARGETOBJDIRREL)/*)
	$(if $(TARGETDEPDIRREL),$(RM) -rf $(TARGETDEPDIRREL)/*)
	$(ECHO) "Finished cleaning target '$(TARGETNAME)' for library '$(LIBNAME)'"

.PHONY: $(SUBSRCDIRS)
