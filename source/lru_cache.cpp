#include "lru_cache.hpp"

namespace lru_cache
{

void lru_list_add (int x) {
    if(sizeOfLru == capacityOfLru) {
        if(sizeOfLfu == capacityOfLfu) {
            // std::cout << "Cache overflow! (⌣̀_⌣́)" << std::endl;
            if(sizeOfLru != 0) {
                lru_list.pop_back();
                lru_list.push_front(x);
                // std::cout << "New element in LRU. \n" << std::endl;
            }
            else {
                level_map::iterator mapIter = lfu_map.begin();
                while((mapIter -> second).empty()) ++mapIter;
                (mapIter -> second).pop_front();
                ++sizeOfLru;
                --sizeOfLfu;
                ++capacityOfLru;
                --capacityOfLfu;  
                lru_list.push_front(x);
                // std::cout << "New element in LRU. \n" << std::endl;
            }
        }
        
        else {
            --capacityOfLfu;
            ++capacityOfLru;
            // std::cout << "Memory replacement in lru_list_add.\n" << 
            // "- Capacity of LFU = " << capacityOfLfu << ".\n" <<
            // "- Capacity of LRU = " << capacityOfLru << ".\n" << std::endl;
            lru_list.push_front(x);
            ++sizeOfLru;
            // std::cout << "New element in LRU. \n" << std::endl;
        }
    }

    else {
        lru_list.push_front(x);
        ++sizeOfLru;
        // std::cout << "New element in LRU. \n" << std::endl;
    }
}

/* It's recomended to use 1 of 3 wrappers bellow instead of
   calling this function directly. */
int_list::const_iterator find (int x) const 
{
    int_list::const_iterator list_it = list.begin();

    while(list_it != cur_list.end()) 
    {
        if(*list_it == x)
            break; 
            
        ++list_it;
    }

    return list_it;
}

int_list::iterator get_pos (int x)
{
    find (x);
    return last_found;
}

int_list::iterator get_last_found ()
{
    return last_found;
}

bool is_inside (int x) 
{
    find (x);
    return last_found != list.end();
}

void erase_last_found ()
{
    
}

void dump() const
{
    std::cout << "---------LRU---------"   << std::endl
              << "capacity = " << capacity << std::endl 
              << "size = "     << size     << std::endl;

    copy(lru_list.begin(), lru_list.end(), std::ostream_iterator<int>(std::cout, ";"));

    std::cout << "---------------------" << std::endl;
}

};
