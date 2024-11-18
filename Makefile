compile = g++
mainfile = ./src/main.cpp
outputex = ./bin/main
classfiles = $(wildcard ./src/*.cpp)
objfiles = $(patsubst ./src/%.cpp,./obj/%.o,$(classfiles))
basefiles = $(patsubst ./src/%.cpp,%,$(classfiles))

# Linking
$(outputex): $(basefiles)
	gcc -o $(outputex) ./obj/*.o -lstdc++

# Compiling
$(basefiles):
	$(compile) -o ./obj/$@.o -c ./src/$@.cpp -Wall

test: $(outputex)
	@chmod +x $(outputex)
	@cd ./res
	@$(outputex)

clean:
	rm ./obj/*
	rm ./bin/*

debug:
	@echo $(classfiles);
	@echo $(objfiles);