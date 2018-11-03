CPP			= g++
CFLAGS		= -Wall -std=c++11
LFLAGS		= -lboost_system -lpthread

SRC_DIR		= src
BUILD_DIR	= build
BIN_DIR		= bin

SOURCES 	:= $(shell find $(SRC_DIR) -type f -name *.cpp)
OBJECTS 	:= $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.cpp=.o))

TARGET		:= $(BIN_DIR)/kademlia

all: $(TARGET)

run: $(TARGET)
	@./$(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CPP) $^ -o $@ $(LFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CPP) $(CFLAGS) -c -o $@ $<

clean:
	rm -R $(BUILD_DIR) $(BIN_DIR)

.PHONY: clean
