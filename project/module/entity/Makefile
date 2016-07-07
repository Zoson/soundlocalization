$(OBJS_DIR)entity.o:entity.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
head=/home/zoson/soundlocalization/project/include
obj=/home/zoson/soundlocalization/project/obj/
test:main.o
	g++ -o test main.o $(obj)entity.o $(obj)reader.o $(obj)writer.o $(obj)value.o -I$(head)
main.o:test.cpp
	g++ -o main.o -c test.cpp -I$(head)
