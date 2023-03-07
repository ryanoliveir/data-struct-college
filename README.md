# Data Struct
Repository responsible for storing studies and example on data structure from college



```c++
bool verifyType()

```


Notes 


Always initialize a auxiliary variable

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