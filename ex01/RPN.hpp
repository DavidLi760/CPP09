#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <stdexcept>

bool is_operator(const std::string& token);
int apply_operator(int a, int b, const std::string& op);

#endif