# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -I./include -I/opt/homebrew/include/SDL2 -I/opt/homebrew/opt/googletest/include
LDFLAGS = -L/opt/homebrew/lib -lgtest -lgtest_main -pthread -lSDL2
# CXXFLAGS = -std=c++17 -Wall -Wextra -g -I./include -I/opt/homebrew/include -I/opt/homebrew/opt/googletest/include
# LDFLAGS = -L/opt/homebrew/lib -lgtest -lgtest_main -pthread -lglfw -framework OpenGL

# Build directories
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Source files
SRC_DIRS = src/core src/demos
SRC_FILES = $(wildcard src/core/*.cpp) $(wildcard src/demos/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Test files
TEST_DIR = tests
TEST_SRC_FILES = $(wildcard $(TEST_DIR)/*.cpp) $(wildcard $(TEST_DIR)/core/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/$(TEST_DIR)/%.o,$(TEST_SRC_FILES))
TEST_EXECUTABLE = $(BIN_DIR)/run_tests

# Core source files for tests (excluding main.cpp)
CORE_SRC_FILES = $(wildcard src/core/*.cpp)
CORE_OBJ_FILES = $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(CORE_SRC_FILES))

# Output executable
EXECUTABLE = $(BIN_DIR)/physics_engine

# Default target
all: directories $(EXECUTABLE) $(TEST_EXECUTABLE)

# Create build directories
directories:
	mkdir -p $(OBJ_DIR)/core $(OBJ_DIR)/demos $(OBJ_DIR)/$(TEST_DIR) $(OBJ_DIR)/$(TEST_DIR)/core $(BIN_DIR)


# Compile source files
$(OBJ_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
# Replace your current test compilation rules with this
$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Add this rule for subdirectory tests
$(OBJ_DIR)/$(TEST_DIR)/core/%.o: $(TEST_DIR)/core/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Link object files
$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Link test executable with GTest
$(TEST_EXECUTABLE): $(TEST_OBJ_FILES) $(CORE_OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Run the executable
run: $(EXECUTABLE)
	$(EXECUTABLE)

# Run the tests
test: $(TEST_EXECUTABLE)
	$(TEST_EXECUTABLE)

# Debug targets
debug: $(EXECUTABLE)
	lldb $(EXECUTABLE)

debug-test: $(TEST_EXECUTABLE)
	lldb $(TEST_EXECUTABLE)

.PHONY: all clean run debug test debug-test directories