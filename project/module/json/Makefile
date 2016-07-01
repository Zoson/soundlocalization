all:$(OBJS_DIR)reader.o $(OBJS_DIR)writer.o $(OBJS_DIR)value.o
$(OBJS_DIR)reader.o:json_reader.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(OBJS_DIR)writer.o:json_writer.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(OBJS_DIR)value.o:json_value.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(OBJS_DIR)json.o:json_reader.cpp json_writer.cpp json_value.cpp
	g++ -o $(OBJS_DIR)json.o -c json_reader.cpp json_writer.cpp json_value.cpp -I$(INCLUDE)
$(OBJS_DIR)libjson.so:reader.o writer.o value.o
	g++ -fpic -shared -o $(OBJS_DIR)libjson.so reader.o writer.o value.o
.Phony:clean
clean:
	rm -f *.o