compile = g++
mainfile = ./src/main.cpp
outputex = ./bin/main
classfiles = $(wildcard ./src/*.cpp)
objfiles = $(wildcard ./obj/*.o)

# Linking
$(outputex): ./obj/main.o
	gcc -o $(outputex) $(objfiles)

# Compiling
./obj/main.o: $(classfiles)
	$(compile) -o $@ -c ./$^ -Wall