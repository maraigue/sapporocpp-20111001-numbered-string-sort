CC = g++
BOOST_PATH = /usr/include/boost

default: problem1

test:
	

problem1: problem1.cpp parse_result.o char_or_number.o
	$(CC) -I $(BOOST_PATH) $+ -o $@

.cpp.o:
	$(CC) -c $< -o $@

parse_result.o: char_or_number.hpp parse_result.hpp
char_or_number.o: char_or_number.hpp

clean:
	rm -f problem1 parse_result.o char_or_number.o

