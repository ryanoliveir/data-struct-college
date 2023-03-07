#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// using namespace std;

void populateVector(std::vector<int> &vector);

void showVector(std::vector<int> &vector);

void getValues(std::vector<int> &vector, std::vector<int> &positive_values, std::vector<int> &negative_values);

int main(){

    std::vector<int> x_vector(30);
    std::vector<int> positive_values;
    std::vector<int> negative_values;

    std::cout << "[*] Generating vector with 30 elements...\n" << std::endl;
    populateVector(x_vector);

    std::cout << "[*] X[30] = { ";
    showVector(x_vector);
    std::cout << "}\n"<< std::endl;
    
    getValues(x_vector,positive_values, negative_values);

    std::cout << "[+] Positive_Values["<< positive_values.size() << "] = { ";
    showVector(positive_values);
    std::cout << "}"<< std::endl;


    std::cout << "[+] Negative_Values["<< negative_values.size() << "] = { ";
    showVector(negative_values);
    std::cout << "}"<< std::endl;
    
    return 0;
}


void populateVector(std::vector<int> &vector){
    
    srand(time(0));
    for (int i = 0; i < vector.size(); i++){
        vector[i] = rand() % 201 - 100;
    }

}


void getValues(std::vector<int> &vector, std::vector<int> &positive_values, std::vector<int> &negative_values){
    
    for (int i = 0; i < vector.size(); i++)
    {

        if(vector[i] > 0){
            positive_values.push_back(vector[i]);
            

        } else if (vector[i] < 0) {
            negative_values.push_back(vector[i]);

        }
    }    
}



void showVector(std::vector<int> &vector){

    for(int i = 0; i < vector.size(); i++){
        
        if(i == vector.size() -1){
            std::cout << vector[i] << " ";

        }else {
            std::cout << vector[i] << ", ";
        }
    }
}