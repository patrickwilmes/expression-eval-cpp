#ifndef EXPRESSION_EVAL_TOKENIZER_H
#define EXPRESSION_EVAL_TOKENIZER_H

#include <vector>
#include <memory>
#include <string>

enum TokenType {
    NUM, ADD, SUB, DIV, MUL, LEFTP, RIGHTP
};

struct Token {
    std::string value;
    TokenType type;
};

class Tokenizer {
public:
    explicit Tokenizer(char *expression);
    std::shared_ptr<std::vector<Token>> tokenize();
private:
    void pushNumberOntoTokenVector();
    char *_expression;
    std::string _currentToken{};
    std::shared_ptr<std::vector<Token>> _tokens = std::make_shared<std::vector<Token>>();
};

#endif //EXPRESSION_EVAL_TOKENIZER_H
