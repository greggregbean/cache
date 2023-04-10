TARGET = ./build/run
HEADER = ./source/cacheSetup.hpp

CC = g++
override CXXFLAGS += -std=c++11 -Wall -Wextra -Wpedantic

PREF_SRC = ./source/
PREF_OBJ = ./build/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp $(HEADER)
	$(CC) -c $(CXXFLAGS) $< -o $@

clean :
	rm $(TARGET) $(PREF_OBJ)*.o 
