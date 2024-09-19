
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

SRC_DIR := src
INCLUDE_DIR := include
BIN_DIR := bin

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
HDRS := $(wildcard $(INCLUDE_DIR)/*.h)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))

TARGET := $/quizMaker

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

clean:
	rm -rf $(BIN_DIR)/*.o $(TARGET)

run:
	./quizMaker ./Inputs/input.txt