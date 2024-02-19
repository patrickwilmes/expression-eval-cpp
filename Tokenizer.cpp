#include "Tokenizer.h"

Tokenizer::Tokenizer(char *expression) : _expression(expression) {}

std::shared_ptr<std::vector<Token>> Tokenizer::tokenize() {
    for (size_t i = 0; _expression[i] != '\0'; i++) {
        switch (_expression[i]) {
            case '+':
                pushNumberOntoTokenVector();
                _tokens->push_back({"+", ADD});
                break;
            case '-':
                pushNumberOntoTokenVector();
                _tokens->push_back({"-", SUB});
                break;
            case '*':
                pushNumberOntoTokenVector();
                _tokens->push_back({"*", MUL});
                break;
            case '/':
                pushNumberOntoTokenVector();
                _tokens->push_back({"/", DIV});
                break;
            case '(':
                pushNumberOntoTokenVector();
                _tokens->push_back({"(", LEFTP});
                break;
            case ')':
                pushNumberOntoTokenVector();
                _tokens->push_back({")", RIGHTP});
                break;
            default:
                _currentToken.push_back(_expression[i]);
                break;
        }
    }
    pushNumberOntoTokenVector();
    return _tokens;
}

void Tokenizer::pushNumberOntoTokenVector() {
    if (!_currentToken.empty()) {
        _tokens->push_back({_currentToken, NUM});
        _currentToken.clear();
    }
}
