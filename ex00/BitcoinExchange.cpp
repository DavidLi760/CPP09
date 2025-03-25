#include "BitcoinExchange.hpp"

void Bitcoin::convert(std::ifstream &database)
{
    std::string lines;
    std::string date;
    float value;

    while (std::getline(database, lines))
    {
        std::istringstream line(lines);
        if (std::getline(line, date, '|'))
            std::cerr << "Error : bad input =>"
        if (std::getline(line, date, '|') && (line >> value))
            _data[date] = value;
    }
    database.close();
}