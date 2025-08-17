# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Iinclude -I/opt/homebrew/include
LDFLAGS := -L/opt/homebrew/lib -lCatch2Main -lCatch2

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TEST_DIR := tests

# Target executables
APP := $(BIN_DIR)/acm
TEST_BIN := $(BIN_DIR)/tests

# Source files
APP_MAIN := $(SRC_DIR)/main.cpp
SRC_FILES := $(filter-out $(APP_MAIN), $(wildcard $(SRC_DIR)/*.cpp))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
APP_OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(APP_MAIN))

# Test files
TEST_SRC := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SRC))

# Default target
all: $(APP)

# Build the app (main + library objects)
$(APP): $(OBJ_FILES) $(APP_OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build tests (only library + test objects, no main.cpp!)
$(TEST_BIN): $(OBJ_FILES) $(TEST_OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile rules
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
test: $(TEST_BIN)
	./$(TEST_BIN)

# Utility targets
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean test