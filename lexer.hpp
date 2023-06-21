#ifndef lexer_hpp
#define lexer_hpp

#include <string>
#include <vector>

enum class TokenType
{
    letter,
    number,
    operat,
    pareno,
    parenc,
    none
};

class Token
{
    private:
        char word;
        TokenType type;
    
    public:
        Token(char word, TokenType type);
        char getWord();
        TokenType getType();
};

class Lexer
{
    private:
        std::string fcontents;
        std::vector<Token> tokens;

    public:
        Lexer(std::string fcontents);
        void lex();
};

#endif