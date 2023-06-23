#ifndef parser_hpp
#define parser_hpp

#include "lexer.hpp"

struct Node
{
    Token token;
    Node *a;
    Node *b;
};

struct ParserSettings
{
    bool debug_ast;
};

class Parser
{
    private:
        std::vector<Token> tokens;
        ParserSettings settings;
        Node *baseNode;

    public:
        Parser(std::vector<Token> tokens, ParserSettings settings);
        void parse();
};

#endif