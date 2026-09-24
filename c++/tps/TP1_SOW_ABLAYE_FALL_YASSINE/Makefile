CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -O0

# Les sources sont dans src/ si ce dossier existe, sinon a cote du Makefile.
SRC := $(if $(wildcard src/enum.cpp),src,.)

BINS = enum_demo memory_1 memory_2 memory_3 data_2

all: $(BINS)

enum_demo: $(SRC)/enum.cpp $(SRC)/enum_demo.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

memory_1: $(SRC)/inheritance.cpp $(SRC)/memory_1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

memory_2: $(SRC)/inheritance.cpp $(SRC)/memory_2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

memory_3: $(SRC)/inheritance.cpp $(SRC)/memory_3.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

data_2: $(SRC)/data_2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

# cible volontairement en echec : c'est la question B.1o)
data_1: $(SRC)/data_1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

valgrind: memory_1 memory_2 memory_3
	valgrind --leak-check=yes ./memory_1
	valgrind --leak-check=yes ./memory_2
	valgrind --leak-check=yes ./memory_3

clean:
	rm -f $(BINS) data_1

.PHONY: all valgrind clean
