#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#include "lexer.hpp"

void checkargs(int argc, char *argv[]);
std::string readfile(char *argv[]);

int main(int argc, char *argv[])
{
    // Double check command line arguments
    checkargs(argc, argv);

    // Open and read file
    std::string fcontents;
    fcontents = readfile(argv);

    // Lexer
    Lexer lexer(fcontents);
    lexer.lex();
}

void checkargs(int argc, char *argv[])
{
    // Double check command line arguments
    if (argc == 1)
    {
        std::cout << "Please include the name of the file to be parsed\n";
        exit(1);
    } 
    else if (argc > 2)
    {
        std::cout << "Please only include the name of the file to be parsed\n";
        exit(1);
    }
}

std::string readfile(char *argv[])
{
    std::fstream file;
    file.open(argv[1], std::ios::in);

    if (file.is_open())
    {
        std::ostringstream ss;
        ss << file.rdbuf() << "\n";
        return ss.str();

        file.close();
    }
    else
    {
        std::cout << "File not found";
        exit(2);
    }

    return "";
}