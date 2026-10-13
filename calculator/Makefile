CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2
TARGET   = calculator
SRC      = calculator.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
