#include "cacheSetup.h"

int main() {
  size_t numOfElems;
  size_t capacityOfCache;
  std::cout << "Enter number of elements and capacity of cache:" << std::endl;
  std::cin >> numOfElems;
  std::cin >> capacityOfCache;
  cache cacheMem (capacityOfCache);
  cacheMem.dump();

  int x;
  for(size_t i = 0; i < numOfElems; i++) {
    std::cout << "Left " << numOfElems - i << " numbers. Enter a number: " << std::endl;
    std::cin >> x;
    cacheMem.lfu(x);
    cacheMem.graphdump();
  } 
  cacheMem.dump();
}













// int_list list1;
//   int_list list2;
//   list1.push_back(3);
//   list1.push_back(5);
//   list2.push_back(2);
//   list2.push_back(4);
//   std::cout << "list1: ";
//   copy(list1.begin(), list1.end(), std::ostream_iterator<int>(std::cout, " "));
//   std::cout << "\nlist2: ";
//   copy(list2.begin(), list2.end(), std::ostream_iterator<int>(std::cout, " "));
//   std::cout << "\n";

//   level_map map;
//   map.insert(std::make_pair("Level 1", list1));
//   map.insert(std::make_pair("Level 2", list2));
//   level_map :: iterator MapIter = map.begin();
//   std::cout << "My level map: " << std::endl;
//   for (int i = 0; MapIter != map.end(); MapIter++, i++) 
//   {
//     std::cout << "Ключ: " << MapIter -> first << ". Значения: ";
//     copy((MapIter -> second).begin(), (MapIter -> second).end(), std::ostream_iterator<int>(std::cout, "; "));
//     std::cout << "\n";
//   }