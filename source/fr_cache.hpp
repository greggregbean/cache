#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <vector>

#include "lfu_cache.hpp"
#include "lru_cache.hpp"

template <typename container, typename const_it>
typename container::iterator remove_constness(container& c, const_it it) {return c.erase(it, it);}

template <typename list_t>
list_t::const_iterator list_find (int x, const list_t& list) const 
{
    list_t::const_iterator list_it = list.begin();
    while(list_it != list.end()) {
        if(*list_it == x) break;
        ++list_it;
    }
    return list_it;
}

class fr_cache final 
{
    private:
        class lfu_cache lfu;
        class lru_cache lru;

        size_t capacity = 0;
        size_t size = 0;
        size_t hits = 0;

        void add(int x);

        void list_graphdump (const int_list& lst, std::ofstream& file) const;
    
    public:
        fr_cache (size_t i_capacity, size_t lfu_levels): 
            capacity (i_capacity), 
            lfu (i_capacity/2, lfu_levels), 
            lru (i_capacity - i_capacity/2) {}

        level_map::iterator cache (int x);
        void inc_lfu_capacity ();
        void inc_lru_capacity (); 
        
        void dump() const;
        void graphdump() const;

        void show_hits()   {std::cout << hits << std::endl;}
        int  return_hits() {return hits;}
};

void run_test(int& num_of_test, const std::vector<int>& args, int right_answer);
void testing();


