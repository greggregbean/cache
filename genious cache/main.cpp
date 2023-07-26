#include "belady.hpp"

int main() {
    int numOfElems;
    size_t capacityOfCache;

    std::cin >> numOfElems;
    std::cin >> capacityOfCache;

    std::vector<int> i_values;

    int value;

    for (int i = 0; i < numOfElems; ++i) {
        std::cin >> value;
        i_values.push_back(value);
    }

    std::cout << "Total num of hits = " << belady(i_values, capacityOfCache) << std::endl;
}