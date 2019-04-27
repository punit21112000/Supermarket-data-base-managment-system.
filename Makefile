administrator.o:  administrator.h administrator.cpp
	g++ -c administrator.cpp
customer.o: customer.h customer.cpp
	g++ -c customer.cpp
mainfile.o: mainfile.cpp
	g++ -c mainfile.cpp
all: mainfile.o administrator.o customer.o
	g++ mainfile.o administrator.o customer.o -o all
clean:
	rm all mainfile.o administrator.o customer.o
