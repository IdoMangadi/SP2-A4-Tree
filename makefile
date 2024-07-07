#!make -f
# ID: 315310250
# EMAIL: IDOIZHAR.Mangadi@msmail.ariel.ac.il
# GMAIL: idomangadi@gmail.com

CXX = g++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES = Complex.cpp Demo.cpp
OBJECTS = Complex.o Demo.o
TOBJECTS = Complex.o test.o

.PHONY: all clean valgrind cps run_test test

all: tree test

tree: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

run_test: test
	./test

test: $(TOBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

valgrind: tree test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./Demo 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f *.o test Demo tree

cps:
	git commit -a -m "$(m)"
	git push
	git status