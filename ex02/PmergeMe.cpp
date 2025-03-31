#include "PmergeMe.hpp"

void print_container(const std::string &msg, const std::vector<int> &container)
{
    std::cout << msg;
    for (size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container[i] << (i + 1 < container.size() ? " " : "\n");
    }
}

std::vector<int> merge_sorted_vectors(const std::vector<int> &left, const std::vector<int> &right)
{
    std::vector<int> result;
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            result.push_back(left[i++]);
        }
        else
        {
            result.push_back(right[j++]);
        }
    }
    while (i < left.size())
        result.push_back(left[i++]);
    while (j < right.size())
        result.push_back(right[j++]);
    return result;
}

std::vector<int> ford_johnson_sort(std::vector<int> arr)
{
    if (arr.size() < 2)
        return arr;
    
    std::vector<int> main_chain, pend;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
            std::swap(arr[i], arr[i + 1]);
        main_chain.push_back(arr[i + 1]);
        pend.push_back(arr[i]);
    }
    if (arr.size() % 2 == 1)
        main_chain.push_back(arr.back());
    
    main_chain = ford_johnson_sort(main_chain);
    
    for (size_t i = 0; i < pend.size(); ++i)
    {
        std::vector<int>::iterator pos = std::upper_bound(main_chain.begin(), main_chain.end(), pend[i]);
        main_chain.insert(pos, pend[i]);
    }
    
    return main_chain;
}

void ford_johnson_sort(std::deque<int> &arr)
{
    std::vector<int> temp(arr.begin(), arr.end());
    temp = ford_johnson_sort(temp);
    std::copy(temp.begin(), temp.end(), arr.begin());
}