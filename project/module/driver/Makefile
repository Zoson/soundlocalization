$(OBJS_DIR)sounddetect.o:sounddetect.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
head:=/home/zoson/soundlocalization/project/include
test:test.o sounddetect.o
	g++  $^ -o $@ -I$(head) 
sounddetect.o:sounddetect.cpp
	g++ -c $^ -o $@ -I$(head) 
test.o:test.cpp
	g++ -o test.o -c test.cpp -I$(head)

.Phony:clean
clean:
	rm -f *.o test
