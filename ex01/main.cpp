#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }

    std::stack<int> stack;

    for (int i = 1; i < argc; ++i) {
        std::string token = argv[i];

        // Si le token est un nombre, on le pousse sur la pile
        if (token.length() == 1 && token[0] >= '0' && token[0] <= '9') {
            stack.push(token[0] - '0');
        }
        // Si le token est un opérateur
        else if (is_operator(token)) {
            if (stack.size() < 2) {
                std::cerr << "Error: Not enough operands for operation." << std::endl;
                return 1;
            }

            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            try {
                int result = apply_operator(a, b, token);
                stack.push(result);
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return 1;
            }
        }
        // Si le token est inconnu
        else {
            std::cerr << "Error: Invalid token '" << token << "'." << std::endl;
            return 1;
        }
    }

    // Si tout s'est bien passé, la pile devrait contenir un seul résultat
    if (stack.size() != 1) {
        std::cerr << "Error: Invalid RPN expression." << std::endl;
        return 1;
    }

    std::cout << "Result: " << stack.top() << std::endl;
    return 0;
}
