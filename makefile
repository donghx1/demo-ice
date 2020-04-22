

server: server.o Hello.o HelloI.o
	g++ -g server.o HelloI.o Hello.o -lIce -lpthread -o server

client: client.o Hello.o HelloI.o
	g++ -g client.o HelloI.o Hello.o -lIce -lpthread -o client



server.o: server.cpp 
	g++ -I. -c server.cpp -o server.o 
client.o: client.cpp
	g++ -I. -c client.cpp -o client.o 

Hello.o: Hello.cpp  Hello.h
	g++ -I. -c Hello.cpp -o Hello.o 

HelloI.o: HelloI.cpp  HelloI.h
	g++ -I. -c HelloI.cpp -o HelloI.o 


clean:
	rm *.o server client
