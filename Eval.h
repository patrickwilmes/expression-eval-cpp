#ifndef EXPRESSION_EVAL_EVAL_H
#define EXPRESSION_EVAL_EVAL_H

#include <vector>
#include <memory>
#include <stack>
#include <functional>
#include "Tokenizer.h"

class Eval {
public:
    explicit Eval(std::shared_ptr<std::vector<Token>> tokens);
    int eval();
private:
    void executeOperatorOnStack(const std::function<bool()> &predicate);
    static int precedence(TokenType op);
    std::stack<int> _values{};
    std::stack<TokenType> _operators{};
    std::shared_ptr<std::vector<Token>> _tokens;
};

#endif //EXPRESSION_EVAL_EVAL_H
