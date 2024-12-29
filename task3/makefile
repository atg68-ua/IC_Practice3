# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# OpenMP flag for parallelization
OPENMP = -fopenmp

# Executable filenames
EXE_TASK3 = task3
EXE_TASK3_2 = task3_2
EXE_TASK3_3 = task3_3
EXE_TASK3_4 = task3_4
EXE_TASK3_5 = task3_5
EXE_TASK3_6 = task3_6

# Source files
SRC_TASK3 = task3.cpp
SRC_TASK3_2 = task3_2.cpp
SRC_TASK3_3 = task3_3.cpp
SRC_TASK3_4 = task3_4.cpp
SRC_TASK3_5 = task3_5.cpp
SRC_TASK3_6 = task3_6.cpp

# Targets
all: $(EXE_TASK3) $(EXE_TASK3_2) $(EXE_TASK3_3) $(EXE_TASK3_4) $(EXE_TASK3_5) $(EXE_TASK3_6)

# Task 3.1: Sequential version
$(EXE_TASK3): $(SRC_TASK3)
	$(CXX) $(CXXFLAGS) -o $(EXE_TASK3) $(SRC_TASK3)

# Task 3.2: Use OpenMP parallel for
$(EXE_TASK3_2): $(SRC_TASK3_2)
	$(CXX) $(CXXFLAGS) $(OPENMP) -o $(EXE_TASK3_2) $(SRC_TASK3_2)

# Task 3.3: Use OpenMP sections
$(EXE_TASK3_3): $(SRC_TASK3_3)
	$(CXX) $(CXXFLAGS) $(OPENMP) -o $(EXE_TASK3_3) $(SRC_TASK3_3)

# Task 3.4: Use std::async without OpenMP
$(EXE_TASK3_4): $(SRC_TASK3_4)
	$(CXX) $(CXXFLAGS) -o $(EXE_TASK3_4) $(SRC_TASK3_4)

# Task 3.5: Combine OpenMP reduction with sections
$(EXE_TASK3_5): $(SRC_TASK3_5)
	$(CXX) $(CXXFLAGS) $(OPENMP) -o $(EXE_TASK3_5) $(SRC_TASK3_5)

# Task 3.6: Combine OpenMP reduction with std::async
$(EXE_TASK3_6): $(SRC_TASK3_6)
	$(CXX) $(CXXFLAGS) $(OPENMP) -o $(EXE_TASK3_6) $(SRC_TASK3_6)

# Clean target to remove compiled executables
clean:
	rm -f $(EXE_TASK3_3) $(EXE_TASK3_4) $(EXE_TASK3_5) $(EXE_TASK3_6)

# Phony targets
.PHONY: all clean
