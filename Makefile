TARGETS := $(strip $(shell ls -d _target*))
ifeq ($(TARGETS),)
$(error There are no targets to clean/build)
endif
MAKE_PREFIX = make_
CLEAN_PREFIX = clean_
MAKE_TARGETS := $(foreach dir,$(TARGETS),$(MAKE_PREFIX)$(dir))
CLEAN_TARGETS := $(foreach dir,$(TARGETS),$(CLEAN_PREFIX)$(dir))

all: $(MAKE_TARGETS)

$(MAKE_TARGETS):
	$(MAKE) -C ./$(subst $(MAKE_PREFIX),,$@) all

clean: $(CLEAN_TARGETS)

$(CLEAN_TARGETS):
	$(MAKE) -C ./$(subst $(CLEAN_PREFIX),,$@) clean