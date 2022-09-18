#ifndef DIFFERENTIATOR_H
#define DIFFERENTIATOR_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>

enum {
    NOTFOUND = -1,
    FOUND = 1,
    NUMOFLEVELS = 4
};

typedef std::list <int> int_list;
typedef std::unordered_map <std::string, int_list> level_map;

class cache {
    private:
        level_map map;
        size_t numOfElems;
        size_t numOfElemsInList;
        void list_add(int x, level_map::iterator mapIter);
    
    public:
        void dump();
        cache(size_t numOfElems, size_t numOfElemsInList);
        level_map::iterator lfu(int x);
        int list_find(int x, level_map::iterator MapIter);
        level_map::iterator map_find(int x);
};


#endif