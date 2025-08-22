static: libgerasqd.a

libgerasqd.a: gerasqd.o
	ar rcs $@ $^

gerasqd.o: gerasqd.cpp gerasqd.hpp
	g++ -c $< -o $@ -I./geradeque -I./geraqueue -I./gerastack

clean:
	rm gerasqd.o libgerasqd.a

install:
	sudo cp libgerasqd.a /usr/local/lib/ && sudo cp gerasqd.hpp /usr/local/include/

all:
	make && make install && make clean