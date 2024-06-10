// All coments are for debugging. Don't pay attention to them.

#include "fr_cache.hpp"

namespace fr_cache 
{

void fr_cache::dump() const 
{
    std::cout << "<-----------------------FR----------------------->" << std::endl 
              << "capacity = " << capacity << std::endl
              << "hits = "     << hits     << std::endl;

    lfu.dump();
    std::cout << std::endl;

    lru.dump();
    std::cout << std::endl;

    std::cout << "<------------------------------------------------>" << std::endl;
}

void inc_lfu_capacity () 
{
    lfu.inc_capacity();
    lru.dec_capacity()
}

void inc_lru_capacity () 
{
    lru.inc_capacity();
    lfu.dec_capacity()
}

level_map::iterator cache (int x) 
{
    /* LFU hit. */
    if (lfu.is_inside(x)) 
    {
        ++hits;
        if (!lfu.up_level_last_found (x))
        {
            give_lfu_more_capacity ();
            lfu.up_level_last_found (x);
        }
        
    }

    /* LFU miss. */
    else 
    {   
        /* LRU hit. */
        if (lru.is_nside(x))
        {
            ++hits;
            lru.erase_last_found();
        }

        /* LRU miss. */
        else
        {

        }
    }

    return pos;
}

};
