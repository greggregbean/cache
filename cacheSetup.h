#ifndef DIFFERENTIATOR_H
#define DIFFERENTIATOR_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>

#define NOTFOUND -1
#define FOUND 1

typedef std::list <int> int_list;
typedef std::unordered_map <std::string, int_list> level_map;

class cache {
    private:
        level_map map;
        size_t numOfElems;
        size_t numOfLevels;
    
    public:
        void dump();
        cache(size_t numOfElems, size_t numOfLevels);
        level_map::iterator lfu(int x);
        int list_find(int x, level_map::iterator MapIter);
        level_map::iterator map_find(int x);
};


#endif