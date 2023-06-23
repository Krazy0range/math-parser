#include "parser.hpp"

Parser::Parser(std::vector<Token> tokens, ParserSettings settings)
{
    this->tokens = tokens;
    this->settings = settings;
}

void Parser::parse()
{
    // TODO
    /*
        Order of precedence:
            Parentheses
            Exponents
            Multiplication & Division
            Addition & Subtraction

        Algorithm:
            Loop through the tokens
            Find the lowest precedence operator
                (eg. A plus sign outside of all parentheses)
            From that operator, go out in either direction and
                get the stuff on either side
            For each of those:
                Find lowest operator, go out on each side, repeat
            This will form an AST
    */

    Token & lowest = findLowestOperator(tokens);

}