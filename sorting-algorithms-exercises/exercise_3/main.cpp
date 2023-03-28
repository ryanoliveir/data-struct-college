#include <iostream>
#include <string>
#include <vector>

#include <windows.h>

// Uncomment the following line to compile in DEV-C++
// #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

class LOG {
    private:
        std::string blue_ansi = "\033[1;34m";
        std::string yellow_ansi = "\033[33m";
        std::string reset_ansi = "\033[0m";
        std::string red_ansi = "\033[31m";
        std::string green_ansi = "\033[32m";

    public:

        std::string blue() {
            return this->blue_ansi;
        }

        std::string yellow() {
            return this->yellow_ansi;
        }

        std::string reset() {
            return this->reset_ansi;
        }

         std::string red() {
            return this->red_ansi;
        }

        std::string green() {
            return this->green_ansi;
        }


        void log(std::string message) {
            std::cout << blue_ansi + message + reset_ansi << std::endl; 
        }

        void warning(std::string message) {
            std::cout << this->yellow_ansi + message + this->reset_ansi << std::endl;
        }

        void error(std::string message) {
            std::cout << this->red_ansi + message + this->reset_ansi << std::endl;
        }

        void sucess(std::string message) {
            std::cout << this->green_ansi + message + this->reset_ansi << std::endl;
        }

        void message(std::string message) {
            std::cout << this->reset_ansi + message << std::endl;
        }

        void enableColorMode() {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD dwMode = 0;
            GetConsoleMode(hOut, &dwMode);

            if (!GetConsoleMode(hOut, &dwMode)) {
                std::cerr << "Failed to get console mode" << std::endl;
                return;
            }  

            if (!(dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
                dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
                if (!SetConsoleMode(hOut, dwMode)) {
                    std::cerr << "Failed to set console mode" << std::endl;
                    return;
                }
            }
        }
};



struct Student {
    std::string name;
    float grade1, grade2;
    float arithmeticAverage;

};

const float GRADE_PARAMETER_1 = 2.0;
const float GRADE_PARAMETER_2 = 3.0;
const float APROVED_PARAMETER = 7.0;
const int AMOUNT_STUDENTS = 3;


void registerStudent(std::string student_name, float grade_1, float grade_2, std::vector<Student> &students);
void listStudents(const std::vector<Student>& students, std::string option);

//bubble_sort_v3
void sortByAverage(std::vector<Student> &vector);
//insertion sort
void sortByGrade(std::vector<Student> &vector);

//selection sort
void sortByDisapproved(std::vector<Student> &vector);

float arithmeticAverage(float grade_1, float grade_2);
bool compareByName(const Student &student_1, const Student &student_2);

int main(){

    LOG console;
    
    console.enableColorMode();

    std::vector<Student> students;
    std::string name_input;
    float grade1_input, grade2_input;    


    

    console.log("[*] Please, provide the following data:");
    

    int count = 0;
    do {
        
        std::cout << "\n[*] Student "<< count + 1 << std::endl;


        std::cout << console.blue() <<"[*] Name: " << console.reset();
        std::cin >> name_input;

        std::cout << console.blue() << "[*] Grade (1): " << console.reset();
        std::cin >> grade1_input;
        
         std::cout << console.blue() << "[*] Grade (2): " << console.reset();
        std::cin >> grade2_input;
        

        registerStudent(name_input, grade1_input, grade2_input, students);

        count++;

    } while (count < AMOUNT_STUDENTS);


    std::cout << console.blue() <<"\n[*] Students registered: " << console.reset() << students.size() << std::endl;
    listStudents(students, "default");
    std::cout << console.blue() <<"\n[*] ======================================== " << console.reset() << std::endl;


    sortByAverage(students);

    std::cout << console.yellow() <<"\n[*] Students registered (sorted by average): " << console.reset() << students.size() << std::endl;
    listStudents(students, "default");
    std::cout << console.yellow() <<"\n[*] ======================================== " << console.reset() << std::endl;

    sortByGrade(students);

    std::cout << console.green() <<"\n[*] Students registered (sorted by grade 1): " << console.reset() << students.size() << std::endl;
    listStudents(students, "default");
    std::cout << console.green() <<"\n[*] ======================================== " << console.reset() << std::endl;

    sortByDisapproved(students);

    std::cout << console.red() <<"\n[*] Students disapproved (sorted by disapproved): " <<  console.reset() << std::endl;
    listStudents(students, "disapproved");
    std::cout << console.red() <<"\n[*] ============================================= " << console.reset() << std::endl;
    return 0;
}


void registerStudent(std::string student_name, float grade_1, float grade_2, std::vector<Student> &students){
    
    Student student;

    student.name = student_name;
    student.grade1 = grade_1;
    student.grade2 = grade_2;
    student.arithmeticAverage = arithmeticAverage(grade_1, grade_2);

    students.push_back(student);

}

float arithmeticAverage(float grade_1, float grade_2){
    float average = (grade_1 * GRADE_PARAMETER_1 + grade_2 * GRADE_PARAMETER_2) / (GRADE_PARAMETER_1 + GRADE_PARAMETER_2);
    return average;
}


void listStudents(const std::vector<Student>& students, std::string option){

    if (option == "default")
    {
    
        for (const auto& student : students) {
            std::cout << "[>] Name: "<<student.name << std::endl;
            std::cout << "    Grade 1: "<< student.grade1 << std::endl;
            std::cout << "    Grade 2: "<< student.grade2 << std::endl;
            std::cout << "    Arithmetic Average: "<<student.arithmeticAverage << std::endl;
            std::cout << std::endl;
        }

    } 
    else if (option ==  "disapproved") 
    {
   
        for (const auto& student : students) {

            if ( student.arithmeticAverage < APROVED_PARAMETER){
                std::cout << "[>] Name: "<<student.name << std::endl;
                std::cout << "    Grade 1: "<< student.grade1 << std::endl;
                std::cout << "    Grade 2: "<< student.grade2 << std::endl;
                std::cout << "    Arithmetic Average: "<<student.arithmeticAverage << std::endl;
                std::cout << std::endl;
            }
            
        }
    }
    

}

//bubble_sort_v3
void sortByAverage(std::vector<Student> &vector){

    int troca = 1;
    Student temporary_buffer;
    int iterations = 0;

    while (troca == 1) {
        
        troca = 0;

        for (int i = 0; i < vector.size() - 1; i++){

            if (vector[i].arithmeticAverage < vector[i + 1].arithmeticAverage) {

                troca = 1;
                temporary_buffer = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = temporary_buffer; 
            }
        }   
    
    }
}

//insertion sort
void sortByGrade(std::vector<Student> &vector){


    int i, j, n = vector.size();
    Student key;

    for (i = 1; i < n; i++) {
        key = vector[i]; 
        j = i - 1; 

        while (j >=0 && vector[j].grade1 > key.grade1) {
            vector[j + 1] = vector[j];
            j = j - 1;
        }

        vector[j + 1] = key;
    }

}


void sortByDisapproved(std::vector<Student> &vector){
    for (int i = 0; i < vector.size() - 1; i++){
        int minIndex = i;

        for (int j = i + 1; j < vector.size(); j++){

            if (compareByName(vector[j], vector[minIndex])) {

                minIndex = j;
            }

        }

        if (minIndex != i) {
            Student temp = vector[i];
            vector[i] = vector[minIndex];
            vector[minIndex] = temp;
        }

    }
}


bool compareByName(const Student &student_1, const Student &student_2) {
    return student_1.name < student_2.name;
}
