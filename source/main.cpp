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