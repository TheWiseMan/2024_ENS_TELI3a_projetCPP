#include <iostream>
#include <filesystem>

#define version "0.0.12"

#include "GoldReader.h"

namespace Utils {
    void displayMap(std::map<std::string, std::string> map) {
        for (auto &&entry : map)
        {
            std::cout << entry.first + " : " + entry.second << std::endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Utils::displayMap(GoldReader::parse("salut").front());
    std::cout << "Current path is " << std::filesystem::current_path().string()
         << std::endl;
    std::cout << "Hello World !" << std::endl;
    std::cout << "Goodbye World !" << std::endl;
    return 0;
}
