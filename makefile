TARGET = run
CC = g++
CFLAGS = -std=c++11 -c -Wall -Wextra -Wpedantic

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) -std=c++11 -Wall -Wextra -Wpedantic $(OBJ) -o $(TARGET)

%.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm $(TARGET) *.o 
