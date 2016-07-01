$(BIN_DIR)main:$(OBJS_DIR)main.o $(OBJS_DIR)slocmanager.o
	$(CC) $^ -o $@ -lpthread
$(OBJS_DIR)main.o:main.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(OBJS_DIR)slocmanager.o:slocmanager.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)