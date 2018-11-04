CPP			= g++
CFLAGS		= -Wall -std=c++11 --coverage
LFLAGS		= -lboost_system -lpthread --coverage

SRC_DIR		= src
BUILD_DIR	= build
BIN_DIR		= bin
TESTS_DIR	= tests
COVERAGE_DIR = coverage

BIN_SRC 	:= $(shell find $(SRC_DIR) -type f -name *.cpp)
BIN_OBJS 	:= $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(BIN_SRC:.cpp=.o))

TESTS_SRC	:= $(shell find $(TESTS_DIR) -type f -name *.cpp)
TESTS_OBJS 	:= $(patsubst $(TESTS_DIR)/%,$(BUILD_DIR)/%,$(TESTS_SRC:.cpp=.o)) \
			   $(filter-out build/main.o, $(BIN_OBJS))

BIN_TARGET	:= $(BIN_DIR)/kademlia
TEST_TARGET := $(BIN_DIR)/tests

all: $(BIN_TARGET)

run: $(BIN_TARGET)
	@./$(BIN_TARGET)

tests: $(TEST_TARGET)
	@./$(TEST_TARGET)

tests-coverage: tests
	@mkdir $(COVERAGE_DIR)
	lcov --capture --directory . --output-file $(COVERAGE_DIR)/coverage.info
	genhtml $(COVERAGE_DIR)/coverage.info --output-directory $(COVERAGE_DIR)

$(BIN_TARGET): $(BIN_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CPP) $^ -o $@ $(LFLAGS)

$(TEST_TARGET): $(TESTS_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CPP) $^ -o $@ $(LFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CPP) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(TESTS_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CPP) $(CFLAGS) -c -o $@ $<

clean:
	rm -R $(BUILD_DIR) $(BIN_DIR) $(COVERAGE_DIR)

.PHONY: clean
