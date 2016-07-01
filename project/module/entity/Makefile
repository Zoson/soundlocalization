$(OBJS_DIR)entity.o:entity.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
test:entity.o main.o
	g++ -o test main.o entity.o $(OBJS_DIR)reader.o $(OBJS_DIR)writer.o $(OBJS_DIR)value.o -I$(INCLUDE)
main.o:test.cpp
	g++ -o main.o -c test.cpp -I$(INCLUDE)
