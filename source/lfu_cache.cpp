#include "lfu.hpp"
#include "lfu_cache.hpp"

namespace lfu_cache 
{

/* It's recomended to use 1 of 3 wrappers bellow instead of
   calling this function directly. */
level_map::const_iterator find (int x) const 
{
    level_map::const_iterator map_it = lfu_map.begin();
    int_list cur_list = map_it -> second;
    int_list::const_iterator list_it = cur_list.begin();
    bool found = false;

    while (map_it != lfu_map.end()) 
    {
        while (list_it != cur_list.end()) 
        {
            if (*list_it == x)
            {
                found = true;
                break;
            } 
                
            ++list_it;
        }

        if (found) 
            break;

        ++map_it;
        cur_list = map_it -> second;
        list_it = cur_list.begin();
    }

    last_found = remove_constness(map, map_it);
    return map_it;
}

level_map::iterator get_pos (int x)
{
    find (x);
    return last_found;
}

level_map::iterator get_last_found ()
{
    return last_found;
}

bool is_inside (int x) 
{
    find (x);
    return last_found != map.end();
}

bool up_level_last_found () 
{
    level_map::iterator pos = last_found;
    level_map::iterator pos_inc = pos;
    ++pos_inc;

    /* Last found is on the last level. */
    if (pos_inc == map.end()) 
    {
        ++levels;
        (pos -> second).remove(x);
        (map[levels]).push_back(x);

        return true;
    }

    /* Last found is not on the last level. */
    if (size == capacity)
        return false;

    (pos -> second).remove(x);
    add (x, pos_inc -> first);
}

void add (int x, int level) 
{
    (map[level]).push_back(x);
    ++size;
}

void dump () const
{
    std::cout << "---------LFU---------"   << std::endl
              << "capacity = " << capacity << std::endl 
              << "size = "     << size     << std::endl
              << "levels = "   << levels   << std::endl;

    level_map::const_iterator map_it = map.begin();

    while (map_it != map.end()) 
    {
        std::cout << "[" << map_it -> first << "]: ";
        copy((map_it -> second).begin(), (map_it -> second).end(), std::ostream_iterator<int>(std::cout, "; "));
        std::cout << std::endl;

        ++map_it;
    }

    std::cout << "---------------------" << std::endl;
}

};