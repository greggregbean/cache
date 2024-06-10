#pragma once

#include <iostream>
#include <list>
#include <iterator>

template <typename container, typename const_it>
typename container::iterator remove_constness(container& c, const_it it);

template <typename list_t>
list_t::const_iterator list_find (int x, const list_t& list) const;

using int_list = std::list <int>;

class lru_cache final 
{
    private:
        int_list list;

        size_t capacity = 0;
        size_t size = 0;

        int_list::iterator last_found;

        void add (int x);
    
    public:
        lru_cache (size_t i_capacity): capacity (i_capacity) {}

        int_list::const_iterator find (int x) const;
        level_map::iterator get_pos (int x);
        bool is_inside (int x);

        void inc_capacity () {++capacity;}
        void dec_capacity () {--capacity;}

        void erase_last_found ();

        void dump () const;
};