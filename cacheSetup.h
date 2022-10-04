#ifndef CACHESETUP_H
#define CACHESETUP_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>
#include <string.h>

#define NUM_OF_LEVELS 5

typedef std::list <int> int_list;
typedef std::unordered_map <std::string, int_list> level_map;

class cache {
    private:
        level_map lfu_map;
        int_list lru_list;

        size_t capacityOfCache;
        size_t capacityOfLfu;
        size_t capacityOfLru;

        size_t sizeOfCahce;
        size_t sizeOfLfu;
        size_t sizeOfLru;

        size_t numOfHits;
        void lfu_list_add(int x, const std::string& level);
        void lru_list_add(int x);
    
    public:
        void dump();
        cache(size_t capacityOfCache_);
        int_list::iterator list_find(int x, int_list& currentList);
        level_map::iterator map_find(int x);
        level_map::iterator lfu(int x);
        int_list::iterator lru(int x);
};


#endif