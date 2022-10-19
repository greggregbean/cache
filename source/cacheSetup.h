#ifndef CACHESETUP_H
#define CACHESETUP_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>
#include <string.h>
#include <fstream>
#include <iomanip>

#define NUM_OF_LEVELS 7

typedef std::list <int> int_list;
typedef std::unordered_map <std::string, int_list> level_map;

class cache {
    private:
        level_map lfu_map;
        int_list lru_list;

        size_t capacityOfCache;
        size_t capacityOfLfu;
        size_t capacityOfLru;
        size_t sizeOfLfu;
        size_t sizeOfLru;
        size_t numOfHits;

        void lfu_list_add(int x, const std::string& level);
        void lru_list_add(int x);
        void list_garphdump(const int_list& lst, std::ofstream& file) const;
    
    public:
        cache(size_t capacityOfCache_);

        int_list::const_iterator list_find(int x, const int_list& currentList) const;
        level_map::const_iterator map_find(int x) const;

        level_map::iterator lfu(int x);
        int_list::iterator lru(int x);
        
        void dump() const;
        void graphdump() const;

        void hits_into_file (std::ofstream& file) {file << numOfHits;};
};

template <typename Container, typename ConstIterator>
typename Container::iterator remove_constness(Container& c, ConstIterator it) {
    return c.erase(it, it);
}


#endif