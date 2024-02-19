#include <iostream>
#include <algorithm>
#include "Tokenizer.h"
#include "Eval.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./expression-eval <EXPRESSION>\n" << std::flush;
        return -1;
    }

    char *expression = argv[1];
    std::cout << expression << '\n' << std::flush;

    Tokenizer tokenizer(expression);
    auto tokens = tokenizer.tokenize();

    std::for_each(tokens->begin(), tokens->end(), [](const Token& token){
        std::cout << token.value << '\n';
    });
    std::cout << std::flush;

    Eval eval(tokens);
    std::cout << "Expression " << expression << " was evaluated to " << eval.eval() << '\n' << std::flush;
    return 0;
}
