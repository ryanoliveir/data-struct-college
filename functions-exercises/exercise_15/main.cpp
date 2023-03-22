#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h>

void populateVector(std::vector<int> &vector);
void showVector(const std::vector<int> &vector);
int sumOfEvenNumbers( const std::vector<int> &vector);

int main(){

    int elements = 15;
    std::vector<int> x_vector(15);

    std::cout << "[*] Generating vector with "<<  elements <<" elements...\n" << std::endl;
    populateVector(x_vector);


    
    std::cout << "[*] X["<< elements <<"] = { ";
    showVector(x_vector);
    std::cout << "}\n"<< std::endl;

    std::cout << "[*] Sum of even number from X["<< elements <<"]: " << sumOfEvenNumbers(x_vector) << std::endl;;


    return 0;
}




void populateVector(std::vector<int> &vector) {

    int index = 0;

    srand(time(0));
    for (int i = 0; i < vector.size(); i++) {  
        vector[i] = rand() % 101 - 99;
    }
}


void showVector(const std::vector<int> &vector){

    for(int i = 0; i < vector.size(); i++){
        
        if(i == vector.size() -1){
            std::cout << vector[i] << " ";

        } else {
            std::cout << vector[i] << ", ";
        }
    }
}


int sumOfEvenNumbers( const std::vector<int> &vector){
    int sum = 0;
    for (const auto& number : vector) {
        if (number % 2 == 0) {
            sum += number;
        }
    }

    return sum;
}

