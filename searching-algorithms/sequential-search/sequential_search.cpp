#include <iostream>
#include <vector>
#include <random>
#include <string>

const int VECTOR_SIZE = 10;


void showVector(const std::vector<int> &vector, std::string vector_name);
void populateVector(std::vector<int> &vector);

void quickSort(std::vector<int>& vector, int begin, int end);
int partition(std::vector<int>& vector, int begin, int end);
void sort(std::vector<int>& vector);

bool sequencialSearch(std::vector<int>& vector, int target);

int main(){

    std::vector<int> vector_x(VECTOR_SIZE);
    int target_input;

    populateVector(vector_x);
    showVector(vector_x, "vector_x");


    sort(vector_x);

    showVector(vector_x, "vector_x");

    std::cout << "[*]  Provide number to search in vector: ";
    std::cin >> target_input;

    
    if(sequencialSearch(vector_x, target_input)){
        std::cout << "[*]  The value '"<< target_input <<"' was finded in vector";
    } else {
        std::cout << "[*]  The value '"<< target_input <<"' not finded";
    }

    return 0;
}


bool sequencialSearch(std::vector<int>& vector, int target){

    for (int i = 0; i < vector.size(); i++){
        if (vector[i] == target) return true;
    }

    return false;


    // for (const auto& value : vector){
    //     if (value == target) return true; 
    // }

    // return false;

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


int partition(std::vector<int>& vector, int begin, int end) {
    int pivot = vector[end];
    int i = begin;

    int temp;

    for (int j = begin; j < end; j++) {
        if (vector[j] >= pivot ) {
            temp = vector[j];
            vector[j] = vector[i];
            vector[i] = temp;
            i++;
        }
    }

    temp = vector[end];
    vector[end] = vector[i];
    vector[i] = temp;

    return i;
}


void quickSort(std::vector<int>& vector, int begin, int end){

    if (begin < end) {
        int pivot = partition(vector, begin, end);
        quickSort(vector, begin, pivot - 1);
        quickSort(vector, pivot + 1, end);


    }
    

}


void sort(std::vector<int>& vector){
    int begin = 0;
    int end = vector.size() - 1;

    quickSort(vector, begin, end);
}