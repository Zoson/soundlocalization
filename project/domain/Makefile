$(BIN_DIR)main:$(OBJS_DIR)main.o $(OBJS_DIR)slocmanager.o $(OBJS_DIR)reader.o $(OBJS_DIR)writer.o $(OBJS_DIR)value.o $(OBJS_DIR)entity.o $(OBJS_DIR)server.o $(OBJS_DIR)calculoc.o $(OBJS_DIR)sounddetect.o 
	$(CC) $^ -o $@ -lpthread
$(OBJS_DIR)main.o:main.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(OBJS_DIR)slocmanager.o:slocmanager.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)