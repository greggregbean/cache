#ifndef DIFFERENTIATOR_H
#define DIFFERENTIATOR_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>
#include <string.h>

enum {
    NOTFOUND = -1,
    FOUND = 1,
    NUMOFLEVELS = 5
};

typedef std::list <int> int_list;
typedef std::unordered_map <std::string, int_list> level_map;

class cache {
    private:
        level_map lfu_map;
        int_list lru_list;
        size_t numOfElems;
        size_t numOfElemsInList;
        size_t numOfHits;
        void list_add(int x, level_map::iterator mapIter);
    
    public:
        void dump();
        cache(size_t numOfElems, size_t numOfElemsInList);
        int_list::iterator list_find(int x, int_list& currentList);
        level_map::iterator map_find(int x);
        level_map::iterator lfu(int x);
        int_list::iterator lru(int x);
};


#endif