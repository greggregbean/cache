#include "cacheSetup.hpp"

void run_test(int& num_of_test, const std::vector<int>& args, int right_answer) {
    std::cout << "Test "<< num_of_test <<". Args: ";
    std::copy(args.begin(), args.end(), std::ostream_iterator<int>(std::cout, "; "));
    
    int capacity = args[0];
    cache::FR cacheMem(capacity);

    int num_of_elements = args[1];
    if(num_of_elements != (static_cast<int>(args.size()) - 2)) 
        std::cout << "Wrong number of args!" << std::endl;

    for(int i = 2; (i < num_of_elements + 2); ++i) {
        cacheMem.lfu(args[i]);
    }

    int num_of_hits = cacheMem.return_hits();

    std::cout << std::endl << "Num of hits = " << num_of_hits << ". "; 
    if(num_of_hits == right_answer) std::cout << "Test " << num_of_test << " succesfully completed! \n" << std::endl;
    else std::cout << "Test " << num_of_test << " failed! \n" << std::endl;

    ++num_of_test;
}

void testing() {
    std::cout << "TESTING: \n" << std::endl;
    int num_of_test = 1;
    run_test(num_of_test, {2, 6, 1, 2, 1, 2, 1, 2}, 4);
    run_test(num_of_test, {10, 6, 1, 2, 3, 4, 5, 6}, 0);
    run_test(num_of_test, {10, 6, 1, 1, 1, 1, 1, 1}, 5);
    run_test(num_of_test, {2, 6, 1, 2, 1, 2, 3, 3}, 3);
    run_test(num_of_test, {2, 6, 1, 0, 0, 0, 0, 1}, 4);
    run_test(num_of_test, {2, 6, 263, 263, 263, 0, 0, 0}, 4);
    run_test(num_of_test, {1, 6, 1, 2, 1, 2, 1, 2}, 0);
    run_test(num_of_test, {20, 1, 3}, 0);
    run_test(num_of_test, {20, 2, 1, 1}, 1);
    run_test(num_of_test, {2, 7, 1, 1, 0, 0, 1, 2, 0}, 3);
}
