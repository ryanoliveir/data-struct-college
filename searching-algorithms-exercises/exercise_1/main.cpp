#include <iostream>
#include <string>
#include <vector>
#include <random>


const int VECTOR_SIZE = 10;

int searchLR(std::vector<int>& vector, int target, int index = 0);


void showVector(const std::vector<int> &vector, std::string vector_name);
void populateVector(std::vector<int> &vector);


int main(){

    std::vector<int> vector_x(VECTOR_SIZE);
    int target_input, index;
    populateVector(vector_x);
    showVector(vector_x, "vector_x");


    std::cout << "[*]  Provide number to search in vector: ";
    std::cin >> target_input;

    index = searchLR(vector_x, target_input);

    if(index == -1){
        std::cout << "[*]  The value '"<< target_input <<"' not finded"; 
    } else {
        std::cout << "[*]  The value '"<< target_input <<"' was finded in vector_x["<< index <<"]";
    }

    return 0;

}


int searchLR(std::vector<int>& vector, int target, int index){

    if(index == vector.size()){
        return -1;
    }


    if(vector[index] == target){
        return index;
    }


    return searchLR(vector, target, index + 1);


}


void showVector(const std::vector<int> &vector, std::string vector_name){

    std::cout << "[*] "<< vector_name <<"["<< vector.size() <<"] = { ";
    for(const auto& element : vector){
        
        if (&element == &vector.back()) {
            std::cout << element << " ";

        } else {
            std::cout << element << ", ";
        }
    }

    std::cout << "}\n"<< std::endl;
}


void populateVector(std::vector<int> &vector){
    std::random_device rd;
    std::mt19937 gen(rd());
   

    for (int i = 0; i < vector.size(); i++){
        std::uniform_int_distribution<> dis(-200, 100);
        vector[i] = dis(gen);
    }

}
