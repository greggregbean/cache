#include <iostream>
#include <map>
#include <vector>
#include <iterator>

void belady (std::vector<int> i_values) {

    std::map<int,int> data;
    std::map<int, int>::iterator iter;
    std::map<int, int>::iterator end = data.end();

    for (auto value : i_values) {
        iter = data.find(value);

        if (iter != end) {
            ++(iter -> second);
        }

        else {
            data.insert(std::make_pair(value, 1));
        }
    }

    for (auto pair : data) {
        std::cout << "Val = " << pair.first << " Quantity = " << pair.second << std::endl;
    }
}