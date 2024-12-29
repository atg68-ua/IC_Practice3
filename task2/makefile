# Compiler and flags
CXX = g++
CXXFLAGS = -fopenmp -std=c++17 -O2

# Targets
TARGETS = omp_program async_program

# Object files
OBJS_OMP = omp_program.o
OBJS_ASYNC = async_program.o

# Default rule
all: $(TARGETS)

# Rule to build the OpenMP program
omp_program: $(OBJS_OMP)
	$(CXX) $(CXXFLAGS) -o $@ $^

omp_program.o: omp_program.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Rule to build the async program
async_program: $(OBJS_ASYNC)
	$(CXX) $(CXXFLAGS) -o $@ $^

async_program.o: async_program.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean rule
clean:
	rm -f $(OBJS_OMP) $(OBJS_ASYNC) $(TARGETS)

# Phony targets
.PHONY: all clean
