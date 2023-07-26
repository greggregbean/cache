#include "belady.hpp"

int main() {
    size_t capacityOfCache;
    int numOfElems;

    std::cin >> capacityOfCache;
    std::cin >> numOfElems;

    std::vector<int> i_values;

    int value;

    for (int i = 0; i < numOfElems; ++i) {
        std::cin >> value;
        i_values.push_back(value);
    }

    std::cout << belady(i_values, capacityOfCache) << std::endl;
}