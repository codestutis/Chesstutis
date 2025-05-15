CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC = src/main.cpp src/Board.cpp src/MoveGen.cpp src/GameState.cpp
TARGET = chess

all: $(TARGET)

# Rule to build the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
