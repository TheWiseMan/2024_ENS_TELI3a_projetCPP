compile = g++
outputex = ./bin/main
flags = -lstdc++ -lstdc++fs -lncursesw
classfiles = $(wildcard ./src/*.cpp)
basefiles = $(patsubst ./src/%.cpp,./obj/%.o,$(classfiles))
version = $(shell head -1 ./src/main.cpp | sed 's/#define version //g' | sed 's/"//g' | sed -e s/\\./_/g | cat)

# Linking
$(outputex): $(basefiles)
	gcc -o $(outputex) ./obj/*.o $(flags)

# Compiling
#$(basefiles): ./src/$@.cpp
#	$(compile) -o ./obj/$@.o -c ./src/$@.cpp -Wall;

./obj/%.o: ./src/%.cpp
	$(compile) -o $@ -c $(patsubst obj/%.o,src/%.cpp,$@) -Wall;

test: $(outputex)
	@chmod +x $(outputex)
	@cd ./res; ../$(outputex)

archive: $(outputex)
	cp $(outputex) ./exarchive/archive_$(version)

clean:
	rm ./obj/*
	rm ./bin/*

debug:
	@echo $(classfiles);
	@echo $(basefiles);