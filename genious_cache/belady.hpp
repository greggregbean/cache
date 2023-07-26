#include <iostream>
#include <array>
#include <vector>

class data {
    std::vector<int> data_vec;
    size_t           max_size; 

    public:
        data (size_t capacity) : max_size(capacity) { }
        
        void show () {

            std::cout << "Belady's data: ";

            for (int value : data_vec) {
                std::cout << "[ " << value << " ] ";
            }

            std::cout << std::endl;
        }

        size_t get_max_size() { 
            return max_size; 
        }
        size_t get_size() { 
            return data_vec.size(); 
        }

        bool can_place_val() {
            if (data_vec.size() < max_size) 
                return true;
            else                            
                return false;
        }
        
        void replace_val (int new_val, size_t pos_of_old_val) { 
            data_vec[pos_of_old_val] = new_val; 
        } 
        void place_val (int new_val) { 
            data_vec.push_back(new_val); 
        }

        bool contain (int val) {
            for (int value : data_vec) {
                if (value == val) {
                    return true;
                }
            }

            return false;
        }

        size_t will_use_later (const std::vector<int>& i_values, size_t pos) {
            size_t most_useless;
            size_t max_future_pos = pos;

            for(size_t i = 0; i < max_size; i++) {
                size_t future_pos = pos + 1;

                while ( future_pos < i_values.size()        && 
                        i_values[future_pos] != data_vec[i] ) {
                    future_pos++;
                }

                if (max_future_pos < future_pos) {
                    max_future_pos = future_pos;
                    most_useless = i;
                }
            }

            return most_useless;
        }
};

size_t belady (const std::vector<int>& i_values, size_t capacity) {
    data beladys_data (capacity);

    size_t num_of_hits = 0;

    for (size_t pos = 0; pos < i_values.size(); pos++) {

        if (beladys_data.contain(i_values[pos])) {
            num_of_hits++;
        }

        else if (beladys_data.can_place_val()) {
            beladys_data.place_val(i_values[pos]);
        }

        else {
            size_t replace_pos = beladys_data.will_use_later(i_values, pos);
            beladys_data.replace_val(i_values[pos], replace_pos);
        }

    }

    return num_of_hits;
}