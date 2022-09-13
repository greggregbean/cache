#include "cacheSetup.h"

cache::cache(int numOfLevels)
{
    int_list* listArr = new int_list[numOfLevels];
    std::string* stringArr = new std::string[numOfLevels];

    for (int i = 0; i < numOfLevels; i++)
    {
        stringArr[i] = "Level ";
        stringArr[i] += char(i+'0');
        listArr[i].push_back(0);
        map[stringArr[i]] = listArr[i];
    }
}

void cache::dump()
{
    level_map :: iterator MapIter = map.begin();
    std::cout << "Level map: " << std::endl;
    while (MapIter != map.end()) 
    {
        std::cout << "Ключ: " << MapIter -> first << ". Значения: ";
        copy((MapIter -> second).begin(), (MapIter -> second).end(), std::ostream_iterator<int>(std::cout, "; "));
        std::cout << "\n";
        MapIter++;
    }
}