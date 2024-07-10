#!make -f
# ID: 315310250
# EMAIL: IDOIZHAR.Mangadi@msmail.ariel.ac.il
# GMAIL: idomangadi@gmail.com

CXX = g++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all  --error-exitcode=99
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SOURCES = Complex.cpp Demo.cpp
OBJECTS = Complex.o Demo.o
TOBJECTS = Complex.o test.o testCounter.o

.PHONY: all clean valgrind cps run_test test

all: tree test

tree: Demo
	./Demo

Demo: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(SFML_FLAGS) -o $@

run_test: test
	./test

test: $(TOBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

Complex.o: Complex.cpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Demo.o: Demo.cpp Node.hpp Tree.hpp TreeIterators.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test.o: Test.cpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

testCounter.o: TestCounter.cpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

valgrind: tree test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./Demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f *.o test Demo tree

cps:
	git commit -a -m "$(m)"
	git push
	git status