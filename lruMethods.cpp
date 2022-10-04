#include "cacheSetup.h"

void cache::lru_list_add (int x) {
    sizeOfLru++;
    if(sizeOfLru > capacityOfLru) {
        if(sizeOfLfu == capacityOfLfu) {
            std::cout << "Cache overflow! (⌣̀_⌣́)" << std::endl;
            std::cout << "LAST "; dump();
            exit(-1);
        }
        
        else {
            capacityOfLfu--;
            capacityOfLru++;
            std::cout << "Memory replacement in lru_list_add.\n" << 
            "- Capacity of LFU = " << capacityOfLfu << ".\n" <<
            "- Capacity of LRU = " << capacityOfLru << ".\n" << std::endl;
        }
    }
    lru_list.push_front(x);
}

int_list::iterator cache::lru(int x) {
    int_list::iterator resOfFind = list_find(x, lru_list);

    if(resOfFind != lru_list.end()) {
        std::cout << "LRU HIT! (◕‿◕)\n" << std::endl;
        numOfHits++;

        lru_list.erase(resOfFind);
        sizeOfLru--;
        sizeOfLfu++;
        lfu_list_add(x, "Level 0");
    }

    else {
        std::cout << "New element in LRU. \n" << std::endl;
        lru_list_add(x);
    }

    return resOfFind;
}