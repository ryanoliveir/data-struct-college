# Data Struct
Repository responsible for storing studies and example on data structure from college



> Todo: Implement this function
```c++
bool verifyType()

```


Notes 
> "Always initialize a auxiliary variable"



```c++
//Default file
#include <iostream>

using namespace std;

int main(){

    return 0;
}
```

About the Exercise_3 from __function-exercises__

>"The results are related to the second number provided, if the first is divisible by it, otherwise, find the next number that is divisible by it. The second number given is constant"

    


About the Exercise_10 from __function-exercises__


```c++
#include <iostream>

using namespace std;

// função que calcula a soma dos N primeiros termos da sequência harmônica
float sequence(int n){

    float sum = 0;

    // iterações para somar cada termo da sequência
    for(int i = 1; i <= n; i++){
        sum += 1.0f / i;
    }

    // retorna a soma
    return sum;
}

int main(){

    int number_of_terms;

    // solicita que o usuário insira o número de termos
    cout << "Please, enter the number of terms: ";

    // lê o número de termos inserido pelo usuário
    cin >> number_of_terms;

    // verifica se o número de termos é válido
    while(number_of_terms < 1){
        cout << "[ERROR] Number of terms must be positive and greater than 1.\n";
        cout << "Please, enter the number of terms again: ";
        cin >> number_of_terms;
    }

    // calcula a soma dos termos da sequência e exibe o resultado
    float result = sequence(number_of_terms);
    cout << "[RESULT] The sum of the first " << number_of_terms << " terms is: " << result << "\n";

    return 0;
}
```


## The Virtual Terminal Processing

The Virtual Terminal Processing is a feature added to the Windows console from version 10 onwards that allows applications to control the behavior of the console, such as text formatting, colors, styles, and other visual features.

Before the support for Virtual Terminal Processing, the Windows console did not provide a direct API for controlling these features, which made it difficult for developers to create advanced and custom console interfaces.

With Virtual Terminal Processing, applications can emit ANSI escape sequences to control text formatting and other console features, and the Windows console will interpret these sequences appropriately. This allows developers to create richer and more personalized console interfaces.

In summary, Virtual Terminal Processing is a feature that allows applications to control the appearance and behavior of the Windows console more flexibly and customarily.


> O operador const auto& a define uma referência constante para cada elemento do vetor. Isso significa que o valor do elemento não pode ser alterado dentro do loop.


```c++
std::pair<int, int> max_min_Age(const std::vector<int> &age) {

    int max_Age = age[0];
    int min_Age = age[0];

    // for (int i = 1; i < age.size(); i++){
    //     if (max_Age > age[i]) max_Age = age[i];
    //     if (min_Age < age[i]) min_Age = age[i];
    // }

    for (const auto &age_value : age){ 
        if (max_Age > age_value) max_Age = age_value;
        if (min_Age < age_value) min_Age = age_value;
    }

    return std::make_pair(max_Age, min_Age);

}
```



## What is Searching Algorithm?

> "Searching Algorithms are designed to check for an element or retrieve an element from any data structure where it is stored."

## About binary search Approach

> "__Binary Search__ is a search algorithm use in a __sorted array__ by repeatedly deviding the search interval in half. The idea of bynary search is to use information that arrya is sorted and reduce time complexity to 0 (log n)"

```c++
// binary_search.cpp (recursive approach)


const None = 0;

bool binarySearch(std::vector<int>& vector, int target, int begin = 0, int end = None );

int  main(){

    //...

    return 0;
}

bool binarySearch(std::vector<int>& vector, int target, int begin, int end){

    if (end == None ) end = vector.size() -1 ;

    if (begin <= end){
        int m = (begin + end) / 2;

        if(vector[m] == target) return true; // finded 

        if(target < vector[m]){
            return binarySearch(vector, target, begin, m - 1);
        } else {
            return binarySearch(vector, target, m + 1, end);
        }
    }

    return false;
}


```


# Linked Lists 








