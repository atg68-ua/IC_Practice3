# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# OpenMP flag for parallelization
OPENMP = -fopenmp

# Executable filenames
EXE_NumericalIntegration = numericalintegration
EXE_MonteCarlo = montecarlo

# Source files
SRC_NumericalIntegration = pi.cpp
SRC_MonteCarlo = montecarlo.cpp

# Targets
all: $(EXE_NumericalIntegration) $(EXE_MonteCarlo)

# Task 5.1
$(EXE_NumericalIntegration): $(SRC_NumericalIntegration)
	$(CXX) $(CXXFLAGS) $(OPENMP) -o $(EXE_NumericalIntegration) $(SRC_NumericalIntegration)

# Task 5.2
$(EXE_MonteCarlo): $(SRC_MonteCarlo)
	$(CXX) $(CXXFLAGS) $(OPENMP) -o $(EXE_MonteCarlo) $(SRC_MonteCarlo)

# Clean target to remove compiled executables
clean:
	rm -f $(EXE_NumericalIntegration) $(EXE_MonteCarlo)

# Phony targets
.PHONY: all clean
