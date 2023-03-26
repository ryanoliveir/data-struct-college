#include <iostream>
#include <vector>



void bubble_sort_v2(std::vector<int> &vector);
void showVector(const std::vector<int> &vector);

int main(){

    std::vector<int> vector = {5, 2, 1, 8, 4, 182, 32, 12 , 1, 1, 2, 45};

    showVector(vector);
    bubble_sort_v2(vector);
    showVector(vector);
    


    return 0;
}


void bubble_sort_v2(std::vector<int>& vector){

    size_t size = vector.size();
    size_t last_position = size - 1;

    if( size == 0) return;

    int temporary_buffer;


    for (size_t i = 0; i < size; i++) {

        for(size_t j = last_position; j > i; j--){

            if ( vector[j] < vector[j - 1]) {

                temporary_buffer = vector[j];
                vector[j] = vector[j - 1];
                vector[j - 1] = temporary_buffer;
            }
        }
    }

}

void showVector(const std::vector<int> &vector){

    std::cout << "[*] X["<< vector.size() <<"] = { ";
    for(const auto& element : vector){
        
        if (&element == &vector.back()) {
            std::cout << element << " ";

        } else {
            std::cout << element << ", ";
        }
    }

    std::cout << "}\n"<< std::endl;
}
