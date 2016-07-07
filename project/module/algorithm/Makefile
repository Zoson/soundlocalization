$(OBJS_DIR)calculoc.o:calculoc.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
	
head:=/home/zoson/soundlocalization/project/include
test:test.o calculoc.o
	g++  $^ -o $@ -I$(head)
calculoc.o:calculoc.cpp
	g++ -c $^ -o $@ -I$(head) 
test.o:test.cpp
	g++ -o test.o -c test.cpp -I$(head)

.Phony:clean
clean:
	rm -f *.o test