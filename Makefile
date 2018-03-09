CFLAGS=-Wall -O2 -std=c++14

SRCFOLDER=src
BINFOLDER=bin
TESTFLAG=-I $(SRCFOLDER)/

CPP_FILES = $(filter-out $(SRCFOLDER)/main.cpp, $(wildcard $(SRCFOLDER)/*.cpp))
OBJ_FILES = $(addprefix $(BINFOLDER)/, $(notdir $(CPP_FILES:.cpp=.o)))

all: bin/neuralnet


# Creates the executable
bin/neuralnet: $(OBJ_FILES) src/main.cpp
	g++ $(CFLAGS) $^ -o $@



# Compiling all classes into object files
bin/%.o: src/%.cpp
	@mkdir -p bin
	g++ $(CFLAGS) -c $< -o $@

# ---- Test ---------------------------
bin/neuron: bin/neuron.o test/neuron.cpp
	g++ $(CFLAGS) $(TESTFLAG) $^ -o $@

#bin/memBlockTest: bin/memblockdevice.o test/memBlockTest.cpp bin/blockdevice.o bin/block.o
	#g++ $(CFLAGS) $(TESTFLAG) $^ -o $@

clean:
	rm -rf bin
