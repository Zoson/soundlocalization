CC=g++
DIR=$(shell pwd)/
INCLUDE=$(DIR)include
SUBDIRS=module domain
BIN=main
OBJS_DIR=$(DIR)obj/
BIN_DIR=$(DIR)
export CC SUBDIRS BIN BIN_DIR INCLUDE OBJS_DIR

all:CHECK_DIR $(SUBDIRS)
CHECK_DIR:
	mkdir -p $(BIN_DIR)
$(SUBDIRS):ECHO
	$(MAKE) -C $@
ECHO:
	@echo $(SUBDIRS)
	@echo begin complie
clean:
	rm $(OBJS_DIR)*.o $(BIN_DIR)$(BIN)
