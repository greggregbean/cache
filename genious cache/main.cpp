#include "belady.hpp"

int main() {
    int numOfElems;
    int capacityOfCache;

    std::cin >> numOfElems;
    std::cin >> capacityOfCache;

    std::vector<int> i_values;

    int value;

    for (int i = 0; i < numOfElems; ++i) {
        std::cin >> value;
        i_values.push_back(value);
    }

    belady(i_values);
}