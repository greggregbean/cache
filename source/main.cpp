#include "cacheSetup.h"


int main() {
  int numOfElems;
  int capacityOfCache;
  std::cout << "Enter number of elements and capacity of cache:" << std::endl;
  std::cin >> numOfElems;
  while(numOfElems <= 0) {
    std::cout << "Wrong num of elements!!!" << std::endl;
    std::cin >> numOfElems;
  }
  std::cin >> capacityOfCache;
  while(capacityOfCache <= 0) { 
    std::cout << "Wrong capacity!!!" << std::endl;
    std::cin >> capacityOfCache;
  }
  cache cacheMem (capacityOfCache);
  cacheMem.dump();
  cacheMem.graphdump();

  std::ofstream result ("result.txt");

  int x;
  for(int i = 0; i < numOfElems; ++i) {
    std::cout << i <<") Left " << numOfElems - i << " numbers. Enter a number: " << std::endl;
    std::cin >> x;
    result << x << " ";
    cacheMem.lfu(x);
    cacheMem.dump();
    cacheMem.graphdump();
  } 

  result << std::endl;
  cacheMem.hits_into_file(result);
  result.close();
  cacheMem.dump();
}
