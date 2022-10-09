#include "cacheSetup.h"

void list_garphdump(int_list& lst, std::ofstream& file) { 
    int_list::iterator iter = lst.begin();
    while(iter != lst.end()) {
        file << " " << *iter << " [shape=record, fillcolor = darkolivegreen2, style = filled, label = \" "<< *iter << " \"] \n";
        iter++;
    }

    iter = lst.begin();
    int_list::iterator next_iter = lst.begin();
    next_iter++;

    while(next_iter != lst.end()) {
        file << " " << *iter << " -> " << *next_iter << "; \n";
        iter++; next_iter++;
    }
}

// {
//     listEl* next = lst.head;

//     size_t i = 1;

//     while (next != nullptr)
//     {
//         (*textGraph) << " " << (*next).word << " [shape=record, fillcolor = darkolivegreen2, style = filled, label = \" " 
//         << i << " | {Word: " << (*next).word << "| Addr: "
//         << next << "| Next: "<< (*next).next <<"} \"]" << std::endl;

//         next = (*next).next;
//         i++;
//     }
    
//     next = lst.head;

//     while ( (next != nullptr) && ((*next).next != nullptr) )
//     {
//         (*textGraph) << " " << (*next).word << " -> " << (*(*next).next).word << ";" << std::endl;
//         next = (*next).next;
//     }
// }

void cache::graphdump() {
    std::ofstream file;
    file.open("graph.dot", std::ofstream::out);
    file << "digraph \n{\n";

    list_garphdump(lru_list, file);
    
    level_map::iterator mapIter = lfu_map.begin();
    int i = 0;

    while(mapIter != lfu_map.end()) {
        file << " Level_" << i << " [shape=record, fillcolor = darkolivegreen, style = filled, label = \"" << mapIter -> first << "\"] \n";
        list_garphdump(mapIter -> second, file);
        file << " Level_" << i << " -> " << (mapIter -> second).front() << "; \n\n";
        mapIter++;
        i++;
    }

    file << "}";

    file.close();
}

// {
//     (*textGraph) << "digraph \n{\n";

//     for (size_t i = 0; i < this -> size_; i++)
//     {
//         (*textGraph) << " " << (lists_[i]).hash << " [shape=record, fillcolor = darkolivegreen, style = filled, label = \"List "
//         << i << " | Hash: " << (lists_[i]).hash << "\"]" << std::endl;

//         listGraphDump(textGraph, this -> lists_[i]);

//         (*textGraph) << " " << (lists_[i]).hash << " -> " << (*((lists_[i]).head)).word << "; \n" << std::endl;
//     }

//     (*textGraph) << "}";
// }