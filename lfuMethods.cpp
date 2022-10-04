#include "cacheSetup.h"

level_map::iterator cache::map_find(int x) {
    level_map::iterator mapIter = lfu_map.begin();
    while (mapIter != lfu_map.end()) {
        if(list_find(x, mapIter -> second) != (mapIter -> second).end()) return mapIter;
        mapIter++;
    }
    return lfu_map.end();
}

void cache::lfu_list_add(int x, const std::string& level)
{
    if(sizeOfLfu > capacityOfLfu) {
        if(sizeOfLru == capacityOfLru) {
            lru_list.pop_back();
            lru_list.push_front((lfu_map["Level 0"]).front());
            (lfu_map["Level 0"]).pop_front();
        }

        else {
            capacityOfLfu++;
            capacityOfLru--;
            std::cout << "Memory replacement in lfu_list_add.\n" << 
            "- Capacity of LFU = " << capacityOfLfu << ".\n" <<
            "- Capacity of LRU = " << capacityOfLru << ".\n" << std::endl;
        }
    }
    (lfu_map[level]).push_back(x);
}

level_map::iterator cache::lfu(int x) {
    level_map::iterator resOfFind = map_find(x);

    if (resOfFind == lfu_map.end()) {
        lru(x);
    }

    else {
        std::cout << "LFU HIT! (◕‿◕)\n" << std::endl;
        numOfHits++;

        level_map::iterator itCopy = resOfFind;
        itCopy++;

        if (itCopy == lfu_map.end()) {
            std::cout << "Number " << x << " is on the last level. \n" << std::endl;
        }

        else {
            std::cout << "Number " << x << " is on " << resOfFind -> first << "." << std::endl;
            (resOfFind -> second).remove(x);
            resOfFind++;
            lfu_list_add(x, resOfFind -> first);
            std::cout << "Number " << x << " has moved to " << resOfFind -> first << ". \n" << std::endl;
        }
    }

    return resOfFind;
}