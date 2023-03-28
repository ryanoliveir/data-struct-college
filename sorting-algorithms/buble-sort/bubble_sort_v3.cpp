#include <iostream>
#include <vector>
#include <stdlib.h>



void bubble_sort_v3(std::vector<int> &vector);
void showVector(const std::vector<int> &vector);
void clear();

int main(){
   
    // std::vector<int> vector = {5, 2, 1, 8, 4, 182, 32, 12 , 1, 1, 2, 45};
    std::vector<int> vector = {9, 5, 7, 3 , 1};
    // clear();
    showVector(vector);
    bubble_sort_v3(vector);
    showVector(vector);
    


    return 0;
}


void bubble_sort_v3(std::vector<int>& vector){

    // int n = 1;
    int troca = 1;
    int temporary_buffer;
    int iterations = 0;

    while (troca == 1) {
        
        troca = 0;

        for (int i = 0; i < vector.size() - 1; i++){

            if (vector[i] < vector[i + 1]) {

                troca = 1;
                temporary_buffer = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = temporary_buffer; 

                std::cout << "Troca realizada: " << vector[i] << " e " << vector[i+1] << "\n";
                showVector(vector);
               
            } else {
                std::cout << "Troca nao realizada: " << vector[i] << " e " << vector[i+1] << "\n";
                showVector(vector);
            }

        }

        std::cout << "Iteracao: " << iterations++ << std::endl;
        showVector(vector);
        std::cout << std::endl;
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


void clear() {
    system("cls || clear");
}
