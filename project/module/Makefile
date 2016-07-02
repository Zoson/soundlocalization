SUBDIRS=net json entity algorithm driver
export CC INCLUDE OBJS_DIR

all:$(SUBDIRS)
$(SUBDIRS):ECHO
	$(MAKE) -C $@
ECHO:
	@echo $(SUBDIRS)
	@echo begin complie
CLEAN:
	@$(RM) $(OBJS_DIR)/*.o
	$rm -rf $(BIN_DIR)