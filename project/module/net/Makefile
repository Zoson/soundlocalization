$(OBJS_DIR)server.o:server.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
	
tests:tests.o server.o reader.o writer.o value.o
	g++ -o $(OBJS_DIR)tests $(OBJS_DIR)tests.o $(OBJS_DIR)server.o reader.o writer.o value.o  -I$(INCLUDE)

tests.o:tests.cpp
	g++ -o $(OBJS_DIR)tests.o -c tests.cpp -I$(INCLUDE)

.Phony:clean
clean:
	rm -f *.o main