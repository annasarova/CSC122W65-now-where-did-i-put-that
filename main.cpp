#include <iostream>
#include <string>

#include "src/where.hpp"

int main()
{
  // Your driver program goes here
    std::string text;
    std::cout << "Enter text: ";
    getline(std::cin, text);

    std::string query;
    std::cout << "Enter search query: ";
    getline(std::cin, query);

    size_t start;
    std::cout << "Enter starting position (0 if none): ";
    std::cin >> start;

    char cs;
    std::cout << "Case sensitive? (y/n): ";
    std::cin >> cs;

    bool caseSensitive = (cs == 'y' || cs == 'Y');

    std::cout << "Result: " << find(text,query,start,caseSensitive) << "\n";
    return 0;
}