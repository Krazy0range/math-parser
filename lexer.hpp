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
    equals,
    none
};

class Token
{
    private:
        int data;
        TokenType type;
    
    public:
        Token(int data, TokenType type);
        int getData();
        TokenType getType();
        std::string getTypeStr();
};

struct LexerSettings
{
    bool debug_tokens;
};

class Lexer
{
    private:
        std::string fcontents;
        std::vector<Token> tokens;
        LexerSettings settings;
        void debugTokens();

    public:
        Lexer(std::string fcontents, LexerSettings settings);
        void lex();
};

#endif