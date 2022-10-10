run: lfuMethods.o lruMethods.o cacheMethods.o graphdump.o main.o
	g++ -std=c++11 -Wall -Wextra -Wpedantic lfuMethods.o lruMethods.o cacheMethods.o graphdump.o main.o -o run

main.o:
	g++ -std=c++11 -c -Wall -Wextra -Wpedantic main.cpp -o main.o

cacheMethods.o:
	g++ -std=c++11 -c -Wall -Wextra -Wpedantic cacheMethods.cpp -o cacheMethods.o

lruMethods.o:
	g++ -std=c++11 -c -Wall -Wextra -Wpedantic lruMethods.cpp -o lruMethods.o

lfuMethods.o:
	g++ -std=c++11 -c -Wall -Wextra -Wpedantic lfuMethods.cpp -o lfuMethods.o

graphdump.o:
	g++ -std=c++11 -c -Wall -Wextra -Wpedantic graphdump.cpp -o graphdump.o
