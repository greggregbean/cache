#include "cacheSetup.h"

void cache::lru_list_add (int x) {
    if(sizeOfLru == capacityOfLru) {
        if(sizeOfLfu == capacityOfLfu) {
            // std::cout << "Cache overflow! (⌣̀_⌣́)" << std::endl;
            if(sizeOfLru != 0) {
                lru_list.pop_back();
                lru_list.push_front(x);
                // std::cout << "New element in LRU. \n" << std::endl;
            }
            else {
                level_map::iterator mapIter = lfu_map.begin();
                while((mapIter -> second).empty()) ++mapIter;
                (mapIter -> second).pop_front();
                ++sizeOfLru;
                --sizeOfLfu;
                ++capacityOfLru;
                --capacityOfLfu;  
                lru_list.push_front(x);
                // std::cout << "New element in LRU. \n" << std::endl;
            }
        }
        
        else {
            --capacityOfLfu;
            ++capacityOfLru;
            // std::cout << "Memory replacement in lru_list_add.\n" << 
            // "- Capacity of LFU = " << capacityOfLfu << ".\n" <<
            // "- Capacity of LRU = " << capacityOfLru << ".\n" << std::endl;
            lru_list.push_front(x);
            ++sizeOfLru;
            // std::cout << "New element in LRU. \n" << std::endl;
        }
    }

    else {
        lru_list.push_front(x);
        ++sizeOfLru;
        // std::cout << "New element in LRU. \n" << std::endl;
    }
}

int_list::iterator cache::lru(int x) {
    int_list::iterator resOfFind = remove_constness(lru_list, list_find(x, lru_list));

    if(resOfFind != lru_list.end()) {
        // std::cout << "LRU HIT! (◕‿◕)\n" << std::endl;
        ++numOfHits;

        lru_list.erase(resOfFind);
        --sizeOfLru;
        lfu_list_add(x, "Level 0");
    }

    else lru_list_add(x);

    return resOfFind;
}