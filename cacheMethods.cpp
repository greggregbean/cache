#include "cacheSetup.h"

cache::cache(size_t numOfElems, size_t numOfLevels)
{
    cache::numOfElems = numOfElems;
    cache::numOfLevels = numOfLevels;

    int_list* listArr = new int_list[numOfLevels];
    std::string* stringArr = new std::string[numOfLevels];

    for (size_t i = 0; i < numOfLevels; i++) {
        stringArr[i] = "Level ";
        stringArr[i] += char(numOfLevels - i - 1 + '0');
        map[stringArr[i]] = listArr[i];
    }
}

void cache::dump()
{
    std::cout << "DUMP: \n" << 
    " Number of elements = " << cache::numOfElems << ". \n" <<
    " Number of levels = " << cache::numOfLevels << "." << std::endl; 
    level_map::iterator mapIter = map.begin();
    std::cout << " Level map: " << std::endl;
    while (mapIter != map.end()) {
        std::cout << "   Ключ: " << mapIter -> first << ". Значения: ";
        copy((mapIter -> second).begin(), (mapIter -> second).end(), std::ostream_iterator<int>(std::cout, "; "));
        std::cout << "\n";
        mapIter++;
    }
    std::cout << std::endl;
}

int cache::list_find(int x, level_map::iterator mapIter)
{
    int_list currentList = mapIter -> second;
    int_list::iterator listIter = currentList.begin();
    while(listIter != currentList.end()) {
        if(*listIter == x) return FOUND;
        listIter++;
    }
    return NOTFOUND;
}

level_map::iterator cache::map_find(int x)
{
    level_map::iterator mapIter = map.begin();
    while (mapIter != map.end()) {
        if(list_find(x, mapIter) == FOUND) return mapIter;
        mapIter++;
    }
    return map.end();
}

level_map::iterator cache::lfu(int x)
{
    level_map::iterator resOfFind = map_find(x);

    if (resOfFind == map.end()) {
        ((map.begin()) -> second).push_back(x);
        std::cout << "Число " << x << " было добавлено. \n" << std::endl;
    }

    else {
        level_map::iterator itCopy = resOfFind;
        itCopy++;
        if (itCopy == map.end()) {
             std::cout << "Число " << x << " стоит на последнем уровне. \n" << std::endl;
        }

        else {
            std::cout << "Число " << x << " стоит на " << resOfFind -> first << "." << std::endl;
            (resOfFind -> second).remove(x);
            resOfFind++;
            (resOfFind -> second).push_back(x);
            std::cout << "Число " << x << " переместилось на " << resOfFind -> first << ". \n" << std::endl;
        }
    }

    return resOfFind;
}