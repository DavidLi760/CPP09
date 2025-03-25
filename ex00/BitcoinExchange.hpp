#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class Bitcoin
{
    private:
        std::map<std::string, int> _data;
    public:
        void convert(std::ifstream &database);
};

#endif