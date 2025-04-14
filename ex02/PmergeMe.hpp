#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <string>
# include <deque>
# include <algorithm>
# include <ctime>
# include <cstdlib>
# include <sstream>


template <typename T>
void print_container(const std::string &msg, const T &container)
{
    std::cout << msg;
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << ((it + 1 != container.end()) ? " " : "\n");
    }
}

std::vector<size_t> jacobsthal(size_t n);

template <typename T>
T ford_johnson_sort(T arr)
{
    if (arr.size() < 2)
        return arr;

    T main_chain, pend;

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
            std::swap(arr[i], arr[i + 1]);

        pend.push_back(arr[i]);
        main_chain.push_back(arr[i + 1]);
    }

    if (arr.size() % 2 == 1)
        main_chain.push_back(arr.back());

    main_chain = ford_johnson_sort(main_chain);

    std::vector<size_t> insertion_order = jacobsthal(pend.size());
    for (size_t i = 0; i < insertion_order.size(); ++i)
    {
        typename T::value_type value = pend[insertion_order[i]];
        typename T::iterator pos = std::upper_bound(main_chain.begin(), main_chain.end(), value);
        main_chain.insert(pos, value);
    }

    return main_chain;
}

#endif