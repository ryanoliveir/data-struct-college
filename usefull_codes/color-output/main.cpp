#include <iostream>
#include <windows.h>
#include <string>

// Uncomment the following line to compile in DEV-C++
// #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

class LOG {
    private:
        std::string blue = "\033[1;34m";
        std::string yellow = "\033[33m";
        std::string reset = "\033[0m";
        std::string red = "\033[31m";


    public:
        void log(std::string message) {
            std::cout << blue + message + reset << std::endl; 
        }

        void warning(std::string message) {
            std::cout << this->yellow + message + this->reset << std::endl; 
        }

        void error(std::string message) {
            std::cout << this->red + message + this->reset << std::endl; 
        }

        void message(std::string message) {
            std::cout << this->reset + message << std::endl; 
        }
};

void enableColorMode() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);

    if (!GetConsoleMode(hOut, &dwMode)) {
        std::cerr << "Failed to get console mode" << std::endl;
        return;
    }

    if(!(dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING)){
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        if (!SetConsoleMode(hOut, dwMode)){
            std::cerr << "Failed to set console mode" << std::endl;
            return;
        }
    }
    
    // std::cout << "Virtual Terminal processing enabled" << std::endl;

}


int main(){

    // enable Virtual Terminal Processing 
    enableColorMode();

    // create Log object 
    LOG console;

    // methods available on 
    console.warning("[WARNING]");
    console.log("[LOG]");
    console.error("[ERROR]");
    console.message("[MESSAGE]");

    
    return 0;
}
