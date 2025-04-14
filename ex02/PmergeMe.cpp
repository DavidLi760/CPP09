#include "PmergeMe.hpp"

std::vector<size_t> jacobsthal(size_t n)
{
    std::vector<size_t> seq;
    if (n == 0) return seq;

    size_t j1 = 1, j2 = 0;
    seq.push_back(0);

    while (j1 < n)
    {
        seq.push_back(j1);
        size_t tmp = j1;
        j1 = j1 + 2 * j2;
        j2 = tmp;
    }

    for (size_t i = 0; i < n; ++i)
    {
        if (std::find(seq.begin(), seq.end(), i) == seq.end())
            seq.push_back(i);
    }

    return seq;
}