#include "cacheSetup.h"

int main(int argc, char* argv[]) {
  int numOfElems;
  int capacityOfCache;

  if ((argv[1] != nullptr) && (strcmp(argv[1], "detailed") == 0)) {
    std::cout << "Enter capacity of cache and  number of elements:" << std::endl;

    std::cin >> capacityOfCache;
    while(capacityOfCache <= 0) { 
      std::cout << "Wrong capacity!!!" << std::endl;
      std::cin >> capacityOfCache;
    }

    std::cin >> numOfElems;
    while(numOfElems <= 0) {
      std::cout << "Wrong num of elements!!!" << std::endl;
      std::cin >> numOfElems;
    }
    
    cache cacheMem (capacityOfCache);
    cacheMem.dump();
    cacheMem.graphdump();

    int x;
    for(int i = 0; i < numOfElems; ++i) {
      std::cout << i <<") Left " << numOfElems - i << " numbers. Enter a number: " << std::endl;
      std::cin >> x;
      cacheMem.lfu(x);
      cacheMem.dump();
      cacheMem.graphdump();
    } 

    cacheMem.dump();

    std::cout << "Total num of hits: ";
    cacheMem.show_hits();
  }

  else {
    std::cin >> capacityOfCache;
    std::cin >> numOfElems;
    cache cacheMem (capacityOfCache);

    int x;
    for(int i = 0; i < numOfElems; ++i) {
      std::cin >> x;
      cacheMem.lfu(x);
    } 

    cacheMem.show_hits();
  }
}
