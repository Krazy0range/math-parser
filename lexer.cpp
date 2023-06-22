#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>

#include "lexer.hpp"

/*
    Constants
*/

class Constants
{
    private:
        static const char operators[5];
        static const char pareno = '(';
        static const char parenc = ')';
        static const char equals = '=';
    
    public:
        static bool isLetter(char c) { return isalpha(c); }
        static bool isNumber(char c) { return isdigit(c); }
        static bool isOperator(char c)
        {
            return std::find(std::begin(operators), std::end(operators), c) != std::end(operators);
        }
        static bool isPareno(char c) { return c == pareno; }
        static bool isParenc(char c) { return c == parenc; }
        static bool isEquals(char c) { return c == equals; }
};

const char Constants::operators[5] = {
    '+',
    '-',
    '*',
    '/',
    '^'
};

/*
    Token
*/

Token::Token(int data, TokenType type)
{
    this->data = data;
    this->type = type;
}

int Token::getData()
{
    return data;
}

TokenType Token::getType()
{
    return type;
}

std::string Token::getTypeStr()
{
    switch (type)
    {
        case TokenType::letter: return "letter";
        case TokenType::number: return "number";
        case TokenType::operat: return "operat";
        case TokenType::equals: return "equals";
        case TokenType::pareno: return "pareno";
        case TokenType::parenc: return "parenc";
        case TokenType::none:   return "none";
    }
    return "invalid";
}

/*
    Lexer
*/

Lexer::Lexer(std::string fcontents, LexerSettings settings)
{
    this->fcontents = fcontents;
    this->settings = settings;
}

// Prototypes
std::vector<char> split(std::string text);
void make_token(std::vector<Token> & tokens, int symbol, TokenType type);

void Lexer::lex()
{
    std::vector<char> symbols = split(fcontents);
    std::string number;

    for (auto & symbol : symbols)
    {
        // Combine multiple numbers into a single number token
        if (!Constants::isNumber(symbol) && number != "")
        {
            int integer = std::stoi(number.c_str());
            make_token(tokens, integer, TokenType::number);
            number = "";
        }

        // Make a token with the correct type based off of the symbol

        if (Constants::isLetter(symbol))                        // Letter
        {
            make_token(tokens, symbol, TokenType::letter);
        }
        else if (Constants::isNumber(symbol))                   // Number
        {
            number += symbol;
        }
        else if (Constants::isOperator(symbol))                 // Operator
        {
            make_token(tokens, symbol, TokenType::operat);
        }
        else if (Constants::isEquals(symbol))                   // Equals
        {
            make_token(tokens, symbol, TokenType::equals);
        }
        else if (Constants::isPareno(symbol))                   // Paren open
        {
            make_token(tokens, symbol, TokenType::pareno);
        }
        else if (Constants::isParenc(symbol))                   // Paren close
        {
            make_token(tokens, symbol, TokenType::parenc);
        }
        else                                                    // None
        {
            make_token(tokens, symbol, TokenType::none);
        }
    }

    // Don't forget if the last symbol is a number
    if (number != "")
    {
        int integer = std::stoi(number.c_str());
        make_token(tokens, integer, TokenType::number);
    }

    if (settings.debug_tokens)
        debugTokens();
}

// Debug tokens
void Lexer::debugTokens()
{
    std::cout << "TOKENS" << std::endl;
    std::cout << tokens.size() << " tokens made" << std::endl;
    for (auto & token : tokens)
    {
        std::cout << '\t' << token.getTypeStr() << "\t-\t";

        // If the token is a number then ouput normally, otherwise cast to char
        if (token.getType() == TokenType::number)
            std::cout << token.getData();
        else
            std::cout << (char) token.getData();
        std::cout << std::endl;
    }
}

// Make token shortcut
void make_token(std::vector<Token> & tokens, int symbol, TokenType type)
{
    tokens.push_back(Token(symbol, type));
}

// Split text into its letters, discluding whitespace
std::vector<char> split(std::string text)
{
    std::vector<char> symbols;
    
    for (auto & c : text)
    {
        if (c != ' ' && c != '\n')
        {
            symbols.push_back(c);
        }
    }

    return symbols;
}