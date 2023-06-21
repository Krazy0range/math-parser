#include "lexer.hpp"

/*
    Token
*/

Token::Token(char word, TokenType type)
{
    this->word = word;
    this->type = type;
}

char Token::getWord()
{
    return word;
}

TokenType Token::getType()
{
    return type;
}

/*
    Lexer
*/

Lexer::Lexer(std::string fcontents)
{
    this->fcontents = fcontents;
}

void Lexer::lex()
{

}