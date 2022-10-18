#include "cacheSetup.h"

void cache::list_garphdump(const int_list& lst, std::ofstream& file) const { 
    int_list::const_iterator iter = lst.begin();
    while(iter != lst.end()) {
        file << std::setw(9) << *iter << " [ label = \" "<< *iter << " \"] \n";
        iter++;
    }

    iter = lst.begin();
    int_list::const_iterator next_iter = lst.begin();
    next_iter++;

    while(next_iter != lst.end()) {
        file << std::setw(9) << *iter << " -> " << *next_iter << "; \n";
        iter++; next_iter++;
    }
}

void cache::graphdump() const {
    std::ofstream file;
    file.open("graph.dot", std::ofstream::out);
    file << "digraph {\n\
    subgraph cluster_lfu {\n\
        node [shape=record, fillcolor = darkolivegreen2, style = filled ]\n\
        label = \"LFU part\";" << std::endl;
    
    level_map::const_iterator mapIter = lfu_map.begin();
    int i = 0;
    while(mapIter != lfu_map.end()) {
        file << std::setw(14) <<"Level_" << i << "[ fillcolor = darkolivegreen, label = \"" << mapIter -> first << "\"] \n";
        list_garphdump(mapIter -> second, file);
        if((mapIter -> second).begin() != (mapIter -> second).end())
            file << std::setw(14) << "Level_" << i << " -> " << (mapIter -> second).front() << "; \n\n";
        mapIter++;
        i++;
    }
    file << std::setw(4) << "}\n\
    subgraph cluster_lru {\n\
        node [shape=record, fillcolor = darkolivegreen2, style = filled ]\n\
        label = \"LRU part\";\n";
    list_garphdump(lru_list, file);
    file << std::setw(4) << "}\n\n}";

    file.close();
}

