static: libgeradeque.a

libgeradeque.a: geradeque.o
	ar rcs $@ $^

geradeque.o: geradeque.cpp geradeque.hpp
	g++ -c $< -o $@

clean:
	rm geradeque.o libgeradeque.a

install:
	sudo cp libgeradeque.a /usr/local/lib/ && sudo cp geradeque.hpp /usr/local/include/

all:
	make && make install && make clean