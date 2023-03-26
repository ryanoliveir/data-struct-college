#include <iostream>
#include <vector>



void bubble_sort_v3(std::vector<int> &vector);
void showVector(const std::vector<int> &vector);

int main(){

    std::vector<int> vector = {5, 2, 1, 8, 4, 182, 32, 12 , 1, 1, 2, 45};

    showVector(vector);
    bubble_sort_v3(vector);
    showVector(vector);
    


    return 0;
}


void bubble_sort_v3(std::vector<int>& vector){

    // TODO: implement this function
    

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
