$(OBJS_DIR)server.o:server.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)

head=/home/zoson/soundlocalization/project/include
tests:tests.o server.o 
	g++ -o tests tests.o server.o -I$(head)
server.o:server.cpp
	g++ -o server.o -c server.cpp -I$(head)
tests.o:tests.cpp
	g++ -o tests.o -c tests.cpp -I$(head)

.Phony:clean
clean:
	rm -f *.o main