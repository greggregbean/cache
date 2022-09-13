#include "cacheSetup.h"

cache::cache(size_t numOfElems, size_t numOfLevels)
{
    cache::numOfElems = numOfElems;

    int_list* listArr = new int_list[numOfLevels];
    std::string* stringArr = new std::string[numOfLevels];

    for (size_t i = 0; i < numOfLevels; i++)
    {
        stringArr[i] = "Level ";
        stringArr[i] += char(i+'0');
        listArr[i].push_back(0);
        map[stringArr[i]] = listArr[i];
    }
}

void cache::dump()
{
    std::cout << "Number of elements = " << cache::numOfElems << "." <<std::endl; 
    level_map :: iterator MapIter = map.begin();
    std::cout << "Level map: " << std::endl;
    while (MapIter != map.end()) 
    {
        std::cout << "  Ключ: " << MapIter -> first << ". Значения: ";
        copy((MapIter -> second).begin(), (MapIter -> second).end(), std::ostream_iterator<int>(std::cout, "; "));
        std::cout << "\n";
        MapIter++;
    }
}