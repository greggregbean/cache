#include "cacheSetup.h"

cache::cache(size_t capacityOfCache_): 
    capacityOfCache(capacityOfCache_), 
    capacityOfLfu(capacityOfCache_ / 2), 
    capacityOfLru(capacityOfCache_ - capacityOfLfu), 
    sizeOfLfu(0),
    sizeOfLru(0),
    numOfHits(0) {
    for (size_t i = 0; i < NUM_OF_LEVELS; ++i) {
        std::string level = "Level ";
        level += (NUM_OF_LEVELS - i - 1 + '0');
        std::cout << level << std::endl;
        int_list lst;
        lfu_map[level] =  lst;
    }
}

void cache::dump() const {
    std::cout << "DUMP: \n" << 
    " Capacity of cache = " << capacityOfCache << ". Capacity of LFU = " << capacityOfLfu <<". Capacity of LRU = " << capacityOfLru << ". \n" <<
    " Size of LFU = " << sizeOfLfu << ". Size of LRU = " << sizeOfLru << ". \n" 
    " Number of hits = " << numOfHits << ". \n" << std::endl;

    level_map::const_iterator mapIter = lfu_map.begin();
    std::cout << " LFU part: " << std::endl;
    while (mapIter != lfu_map.end()) {
        std::cout << "   Key: " << mapIter -> first << ". Value: ";
        copy((mapIter -> second).begin(), (mapIter -> second).end(), std::ostream_iterator<int>(std::cout, "; "));
        std::cout << "\n";
        ++mapIter;
    }
    std::cout << std::endl;

    std::cout << " LRU part: ";
    copy(lru_list.begin(), lru_list.end(), std::ostream_iterator<int>(std::cout, ";"));
    std::cout << "\n" << std::endl;
}

int_list::const_iterator cache::list_find (int x, const int_list& currentList) const {
    int_list::const_iterator listIter = currentList.begin();
    while(listIter != currentList.end()) {
        if(*listIter == x) break;
        ++listIter;
    }
    return listIter;
}
