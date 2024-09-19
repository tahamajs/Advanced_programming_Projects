CC = g++
CFLAGS = -std=c++11
SRCDIR = src
INCDIR = include
OBJDIR = obj
TARGET = main

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEP = $(OBJ:%.o=%.d)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -MMD -MP -c -o $@ $< -I$(INCDIR)

-include $(DEP)

.PHONY: clean, run

clean:
	rm -f $(OBJDIR)/*.o $(OBJDIR)/*.d $(TARGET)

run: $(TARGET)
	./$(TARGET)