#ifndef CACHESETUP_H
#define CACHESETUP_H

#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <iterator>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <vector>

using int_list = std::list <int>;
using level_map = std::map <int, int_list>;

class cache  final {
    private:
        level_map lfu_map;
        int_list lru_list;

        size_t capacityOfCache;
        size_t capacityOfLfu;
        size_t capacityOfLru;
        size_t sizeOfLfu;
        size_t num_of_levels;
        size_t sizeOfLru;
        size_t numOfHits;

        void lfu_list_add(int x, const int& level);
        void lru_list_add(int x);
        void list_garphdump(const int_list& lst, std::ofstream& file) const;
        int new_level();
    
    public:
        cache(size_t capacityOfCache_);

        int_list::const_iterator list_find(int x, const int_list& currentList) const;
        level_map::const_iterator map_find(int x) const;

        level_map::iterator lfu(int x);
        int_list::iterator lru(int x);
        
        void dump() const;
        void graphdump() const;

        void show_hits() {std::cout << numOfHits << std::endl;}
        int return_hits() {return numOfHits;}
};

int run_test(const std::vector<int>& args);
void testing();

template <typename Container, typename ConstIterator>
typename Container::iterator remove_constness(Container& c, ConstIterator it) {
    return c.erase(it, it);
}

#endif