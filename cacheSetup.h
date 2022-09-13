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
    
    public:
        void dump();
        cache(int numOfLevels);
};


#endif