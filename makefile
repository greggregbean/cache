all:
	g++ -std=c++11 -Wall -Wextra -Wpedantic lfuMethods.cpp lruMethods.cpp cacheMethods.cpp graphdump.cpp main.cpp -o run

cache:
	g++ -std=c++11 -Wall -Wextra -Wpedantic cacheMethods.cpp -o cache

lru:
	g++ -std=c++11 -Wall -Wextra -Wpedantic lruMethods.cpp -o lru

lfu:
	g++ -std=c++11 -Wall -Wextra -Wpedantic lfuMethods.cpp -o lfu

graph:
	g++ -std=c++11 -Wall -Wextra -Wpedantic graphdump.cpp -o graphdump
