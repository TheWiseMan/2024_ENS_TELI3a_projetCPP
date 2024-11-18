compile = g++
outputex = ./bin/main
flags = -lstdc++ -lstdc++fs
classfiles = $(wildcard ./src/*.cpp)
basefiles = $(patsubst ./src/%.cpp,%,$(classfiles))

# Linking
$(outputex): $(basefiles)
	gcc -o $(outputex) ./obj/*.o $(flags)

# Compiling
$(basefiles):
	$(compile) -o ./obj/$@.o -c ./src/$@.cpp -Wall

test: $(outputex)
	@chmod +x $(outputex)
	@cd ./res; ../$(outputex)

clean:
	rm ./obj/*
	rm ./bin/*

debug:
	@echo $(classfiles);
	@echo $(basefiles);