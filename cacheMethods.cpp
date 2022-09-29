#include "cacheSetup.h"

cache::cache(size_t numOfElems_, size_t sizeOfCache_) : 
    numOfElems(numOfElems_), sizeOfCache(sizeOfCache_), 
    sizeOfLfu(sizeOfCache_ / (2*NUMOFLEVELS)), sizeOfLru(sizeOfCache_ - (sizeOfLfu * NUMOFLEVELS)), 
    numOfHits(0) {

    std::string* stringArr = new std::string[NUMOFLEVELS];
    int_list* listArr = new int_list[NUMOFLEVELS];

    for (size_t i = 0; i < NUMOFLEVELS; i++) {
        stringArr[i] = "Level ";
        stringArr[i] += char(NUMOFLEVELS - i - 1 + '0');
        lfu_map[stringArr[i]] = listArr[i];
    }
}

void cache::dump() {
    std::cout << "DUMP: \n" << 
    " Number of elements = " << numOfElems << ". \n" <<
    " Size of cache = " << sizeOfCache << ". \n" <<
    " Size of LFU = NUMOFLEVELS(" << NUMOFLEVELS << ") * NUMOFELEMSINLEVEL(" << sizeOfLfu << ")" << ". \n" <<
    " Size of LRU = " << sizeOfLru << ". \n" << 
    " Number of hits = " << numOfHits << ". \n" << std::endl;

    level_map::iterator mapIter = lfu_map.begin();
    std::cout << " LFU part: " << std::endl;
    while (mapIter != lfu_map.end()) {
        std::cout << "   Ключ: " << mapIter -> first << ". Значения: ";
        copy((mapIter -> second).begin(), (mapIter -> second).end(), std::ostream_iterator<int>(std::cout, "; "));
        std::cout << "\n";
        mapIter++;
    }
    std::cout << std::endl;

    std::cout << " LRU part: ";
    copy(lru_list.begin(), lru_list.end(), std::ostream_iterator<int>(std::cout, ";"));
    std::cout << "\n" << std::endl;
}

int_list::iterator cache::list_find(int x, int_list& currentList) {
    int_list::iterator listIter = currentList.begin();
    while(listIter != currentList.end()) {
        if(*listIter == x) break;
        listIter++;
    }
    return listIter;
}

level_map::iterator cache::map_find(int x) {
    level_map::iterator mapIter = lfu_map.begin();
    while (mapIter != lfu_map.end()) {
        if(list_find(x, mapIter -> second) != (mapIter -> second).end()) return mapIter;
        mapIter++;
    }
    return lfu_map.end();
}

void cache::list_add(int x, level_map::iterator mapIter)
{
    if((mapIter -> second).size() >= sizeOfLfu) {
        if(mapIter -> first == "Level 0")
            (mapIter -> second).pop_front();
        else {
            int tmp = *((mapIter -> second).begin());
            (mapIter -> second).pop_front();   
            list_add(tmp, std::prev(mapIter));
        }
    }
    (mapIter -> second).push_back(x);
}

level_map::iterator cache::lfu(int x) {
    level_map::iterator resOfFind = map_find(x);

    if (resOfFind == lfu_map.end()) {
        list_add(x, lfu_map.begin());
        std::cout << "Число " << x << " было добавлено. \n" << std::endl;
    }

    else {
        level_map::iterator itCopy = resOfFind;
        itCopy++;

        if (itCopy == lfu_map.end()) {
            std::cout << "Число " << x << " стоит на последнем уровне. \n" << std::endl;
        }

        else {
            std::cout << "Число " << x << " стоит на " << resOfFind -> first << "." << std::endl;
            (resOfFind -> second).remove(x);
            resOfFind++;
            list_add(x, resOfFind);
            std::cout << "Число " << x << " переместилось на " << resOfFind -> first << ". \n" << std::endl;
        }

        numOfHits++;
    }

    return resOfFind;
}

int_list::iterator cache::lru(int x) {
    int_list::iterator resOfFind = list_find(x, lru_list);

    lru_list.push_front(x);

    if(resOfFind != lru_list.end()) {
        std::cout << "Попадание." << std::endl;
        lru_list.erase(resOfFind);
    }

    else {
        std::cout << "Новый элемент." << std::endl;
        if(lru_list.size() > sizeOfLfu) { 
            std::cout << "Переполнение." << std::endl;
            lru_list.pop_back();
        }
    }

    return resOfFind;
}