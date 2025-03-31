#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>

void print_container(const std::string &msg, const std::vector<int> &container);
std::vector<int> merge_sorted_vectors(const std::vector<int> &left, const std::vector<int> &right);
std::vector<int> ford_johnson_sort(std::vector<int> arr);
void ford_johnson_sort(std::deque<int> &arr);

#endif