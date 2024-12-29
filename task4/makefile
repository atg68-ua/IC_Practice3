# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# OpenMP flag for parallelization
OPENMP = -fopenmp

# Executable filenames
EXE_TASK4_1 = task4_1
EXE_TASK4_2 = task4_2
EXE_TASK4_3 = task4_3
EXE_TASK4_5 = task4_5

# Source files
SRC_TASK4_1 = task4_1.cpp
SRC_TASK4_2 = task4_2.cpp
SRC_TASK4_3 = task4_3.cpp
SRC_TASK4_5 = task4_5.cpp


# Targets
all: $(EXE_TASK4_1) $(EXE_TASK4_2) $(EXE_TASK4_3) $(EXE_TASK4_5)

# Task 4.1
$(EXE_TASK4_1): $(SRC_TASK4_1)
	$(CXX) $(CXXFLAGS) $(OPENMP) -o $(EXE_TASK4_1) $(SRC_TASK4_1)

# Task 4.2
$(EXE_TASK4_2): $(SRC_TASK4_2)
	$(CXX) $(CXXFLAGS) $(OPENMP) -o $(EXE_TASK4_2) $(SRC_TASK4_2)

# Task 4.3
$(EXE_TASK4_3): $(SRC_TASK4_3)
	$(CXX) $(CXXFLAGS) $(OPENMP) -o $(EXE_TASK4_3) $(SRC_TASK4_3)

# Task 4.5
$(EXE_TASK4_5): $(SRC_TASK4_5)
	$(CXX) $(CXXFLAGS) $(OPENMP) -o $(EXE_TASK4_5) $(SRC_TASK4_5)


# Clean target to remove compiled executables
clean:
	rm -f $(EXE_TASK4_1) $(EXE_TASK4_2) $(EXE_TASK4_3) $(EXE_TASK4_5)

# Phony targets
.PHONY: all clean
