#pragma once

#include <iostream>
#include <map>
#include <iterator>

template <typename container, typename const_it>
typename container::iterator remove_constness(container& c, const_it it);

template <typename list_t>
list_t::const_iterator list_find (int x, const list_t& list) const;

using level_map = std::map <int, std::list <int>>;

class lfu_cache final 
{
    private:
        level_map map;
        
        size_t capacity = 0;
        size_t size = 0;
        size_t levels = 0;

        level_map::iterator last_found;

        bool add (int x, int level);
        
    public:
        lfu_cache (size_t i_capacity, size_t i_levels): capacity (i_capacity), levels (i_levels) {}
        
        level_map::const_iterator find (int x) const;
        level_map::iterator get_pos (int x);
        bool is_inside (int x);

        void up_level_last_found ();

        void inc_capacity () {++capacity;}
        void dec_capacity () {--capacity;}

        void dump () const;
};