TARGET = run

CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -Wpedantic

PREF_SRC = ./source/
PREF_OBJ = ./object/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm $(TARGET) $(PREF_OBJ)*.o 
