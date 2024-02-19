#include "Eval.h"

#include <utility>

Eval::Eval(std::shared_ptr<std::vector<Token>> tokens): _tokens(std::move(tokens)) {}

int Eval::eval() {
    for (auto [value, tokenType] : *_tokens) {
        switch (tokenType) {
            case NUM:
                _values.push(std::stoi(value));
                break;
            case ADD:
            case SUB:
            case DIV:
            case MUL:
                executeOperatorOnStack([this, &tokenType]()->bool  {
                    return !_operators.empty() && precedence(_operators.top()) >= precedence(tokenType) ;
                });
                _operators.push(tokenType);
                break;
            case LEFTP:
                _operators.push(tokenType);
                break;
            case RIGHTP:
                executeOperatorOnStack([this]()->bool  {
                    return !_operators.empty() && _operators.top() != LEFTP;
                });
                break;
        }
    }
    executeOperatorOnStack([this]()->bool  {
        return !_operators.empty();
    });
    return _values.top();
}

int Eval::precedence(TokenType op) {
    if (op == ADD || op == SUB) return 1;
    if (op == MUL || op == DIV) return 2;
    return 0;
}

void Eval::executeOperatorOnStack(const std::function<bool()> &predicate) {
    while (predicate()) {
        auto op = _operators.top();
        _operators.pop();
        auto first = _values.top();
        _values.pop();
        auto second = _values.top();
        _values.pop();
        switch (op) {
            case ADD:
                _values.push(first + second);
                break;
            case SUB:
                _values.push(first - second);
                break;
            case DIV:
                _values.push(first / second);
                break;
            case MUL:
                _values.push(first * second);
                break;
        }
        if (!_operators.empty()) {
            _operators.pop();
        }
    }
}
