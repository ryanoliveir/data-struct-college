#include <iostream>
#include <windows.h>
#include <string>

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



int main(){

    // enable Virtual Terminal Processing 
    ;

    // create Log object 
    LOG console;
    console.enableColorMode();

    // methods available on 
    console.warning("[WARNING]");
    console.log("[LOG]");
    console.error("[ERROR]");
    console.message("[MESSAGE]");

    
    return 0;
}
