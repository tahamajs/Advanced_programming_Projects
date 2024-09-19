# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

# Target executable
TARGET = ModelSim.out

# Directories
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

# Source files
SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/GateNand.cpp \
       $(SRC_DIR)/Utils.cpp \
       $(SRC_DIR)/Module.cpp \
       $(SRC_DIR)/GateXor.cpp \
       $(SRC_DIR)/GateOr.cpp \
       $(SRC_DIR)/GateNot.cpp \
       $(SRC_DIR)/GateNor.cpp \
       $(SRC_DIR)/GateAnd.cpp \
       $(SRC_DIR)/Gate.cpp \
       $(SRC_DIR)/Exceptions.cpp \
       $(SRC_DIR)/Circuit.cpp \
       $(SRC_DIR)/InputHandler.cpp \
       $(SRC_DIR)/Wire.cpp

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

# Header files (for dependencies)
HDRS = $(INCLUDE_DIR)/Exceptions.hpp \
       $(INCLUDE_DIR)/Constant.hpp \
       $(INCLUDE_DIR)/GateAnd.hpp \
       $(INCLUDE_DIR)/InputHandler.hpp \
       $(INCLUDE_DIR)/Gate.hpp \
       $(INCLUDE_DIR)/Circuit.hpp \
       $(INCLUDE_DIR)/Utils.hpp \
       $(INCLUDE_DIR)/Wire.hpp

# Default rule
all: $(TARGET)

# Rule to link the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRS)
	@mkdir -p $(BIN_DIR) # Ensure the bin directory exists
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
