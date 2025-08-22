static: libgerastack.a

libgerastack.a: gerastack.o
	ar rcs $@ $^

gerastack.o: gerastack.cpp gerastack.hpp
	g++ -c $< -o $@

clean:
	rm gerastack.o libgerastack.a

install:
	sudo cp libgerastack.a /usr/local/lib/ && sudo cp gerastack.hpp /usr/local/include/

all:
	make && make install && make clean