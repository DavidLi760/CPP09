#include "RPN.hpp"

bool is_operator(const std::string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int apply_operator(int a, int b, const std::string& op)
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error: Division by zero.");
        return a / b;
    }
    throw std::invalid_argument("Unknown operator");
}