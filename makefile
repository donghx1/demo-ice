

server: server.o Hello.o HelloI.o
	g++ -O0 server.o HelloI.o Hello.o -lIce -lpthread -o server

client: client.o Hello.o HelloI.o
	g++ -O0 client.o HelloI.o Hello.o -lIce -lpthread -o client



server.o: server.cpp 
	g++ -I. -g -c server.cpp -o server.o 

client.o: client.cpp
	g++ -I. -g -c client.cpp -o client.o 

HelloI.o: HelloI.cpp  HelloI.h
	g++ -I. -g -c HelloI.cpp -o HelloI.o 

Hello.o: Hello.cpp  Hello.h
	g++ -I. -g -c Hello.cpp -o Hello.o 



clean:
	rm -rf *.o server client
