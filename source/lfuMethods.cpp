#include "cacheSetup.h"

level_map::const_iterator cache::map_find(int x) const {
    level_map::const_iterator mapIter = lfu_map.begin();
    while (mapIter != lfu_map.end()) {
        if(list_find(x, mapIter -> second) != (mapIter -> second).end()) break;
        ++mapIter;
    }
    return mapIter;
}

void cache::lfu_list_add(int x, const std::string& level) {
    if(sizeOfLfu == capacityOfLfu) {
            ++capacityOfLfu;
            --capacityOfLru;
            // std::cout << "Memory replacement in lfu_list_add.\n" << 
            // "- Capacity of LFU = " << capacityOfLfu << ".\n" <<
            // "- Capacity of LRU = " << capacityOfLru << ".\n" << std::endl;
            ++sizeOfLfu;
            (lfu_map[level]).push_back(x);
            // std::cout << "New element in LFU. \n" << std::endl;
    }
    else {
        (lfu_map[level]).push_back(x);
        ++sizeOfLfu;
        // std::cout << "New element in LFU. \n" << std::endl;
    }
}

level_map::iterator cache::lfu(int x) {
    level_map::iterator resOfFind = remove_constness(lfu_map, map_find(x));

    if (resOfFind == lfu_map.end()) {
        lru(x);
    }

    else {
        // std::cout << "LFU HIT! (◕‿◕)\n" << std::endl;
        ++numOfHits;

        level_map::iterator itCopy = resOfFind;
        ++itCopy;

        if (itCopy == lfu_map.end()) {
            // std::cout << "Number " << x << " is on the last level. \n" << std::endl;
        }

        else {
            // std::cout << "Number " << x << " is on " << resOfFind -> first << "." << std::endl;
            (resOfFind -> second).remove(x);
            --sizeOfLfu;
            ++resOfFind;
            lfu_list_add(x, resOfFind -> first);
            // std::cout << "Number " << x << " has moved to " << resOfFind -> first << ". \n" << std::endl;
        }
    }

    return resOfFind;
}