# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -I./include

# Build directories
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Source files
SRC_DIRS = src/core src/demos
SRC_FILES = $(wildcard src/core/*.cpp) $(wildcard src/demos/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Output executable
EXECUTABLE = $(BIN_DIR)/physics_engine

# Default target
all: directories $(EXECUTABLE)

# Create build directories
directories:
	mkdir -p $(OBJ_DIR)/core $(OBJ_DIR)/demos $(BIN_DIR)

# Compile source files
$(OBJ_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files
$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Run the executable
run: all
	$(EXECUTABLE)

# Debug target for use with gdb
debug: all
	lldb $(EXECUTABLE)
# gdb $(EXECUTABLE)

.PHONY: all clean run debug directories