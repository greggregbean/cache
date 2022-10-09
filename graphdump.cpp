#include "cacheSetup.h"

void list_garphdump(int_list& lst, std::ofstream& file) { 
    int_list::iterator iter = lst.begin();
    while(iter != lst.end()) {
        file << "        " << *iter << " [ label = \" "<< *iter << " \"] \n";
        iter++;
    }

    iter = lst.begin();
    int_list::iterator next_iter = lst.begin();
    next_iter++;

    while(next_iter != lst.end()) {
        file << "        " << *iter << " -> " << *next_iter << "; \n";
        iter++; next_iter++;
    }
}

void cache::graphdump() {
    std::ofstream file;
    file.open("graph.dot", std::ofstream::out);
    file << "digraph {\n\
    subgraph cluster_lfu {\n\
        node [shape=record, fillcolor = darkolivegreen2, style = filled ]\n\
        label = \"LFU part\";\n";
    
    level_map::iterator mapIter = lfu_map.begin();
    int i = 0;
    while(mapIter != lfu_map.end()) {
        file << "        Level_" << i << "[ fillcolor = darkolivegreen, label = \"" << mapIter -> first << "\"] \n";
        list_garphdump(mapIter -> second, file);
        if((mapIter -> second).begin() != (mapIter -> second).end())
            file << "        Level_" << i << " -> " << (mapIter -> second).front() << "; \n\n";
        mapIter++;
        i++;
    }
    file << "    }\n\
    subgraph cluster_lru {\n\
        node [shape=record, fillcolor = darkolivegreen2, style = filled ]\n\
        label = \"LRU part\";\n";
    list_garphdump(lru_list, file);
    file << "    }\n\n}";

    file.close();
}

