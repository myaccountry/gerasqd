static: libgeraqueue.a

libgeraqueue.a: geraqueue.o
	ar rcs $@ $^

geraqueue.o: geraqueue.cpp geraqueue.hpp
	g++ -c $< -o $@

clean:
	rm geraqueue.o libgeraqueue.a

install:
	sudo cp libgeraqueue.a /usr/local/lib/ && sudo cp geraqueue.hpp /usr/local/include/

all:
	make && make install && make clean