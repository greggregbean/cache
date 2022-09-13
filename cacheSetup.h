#ifndef DIFFERENTIATOR_H
#define DIFFERENTIATOR_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>
#include <map>

typedef std::list <int> int_list;
typedef std::unordered_map <std::string, int_list> level_map;

class cache
{
    private:
        level_map map;
        size_t numOfElems;
    
    public:
        void dump();
        cache(size_t numOfElems, size_t numOfLevels);
};


#endif