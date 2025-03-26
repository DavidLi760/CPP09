#include "BitcoinExchange.hpp"

void BitcoinExchange::loadDatabase(const std::string &files)
{
    std::ifstream file(files.c_str());
    std::string line, date, value_str;
    float value;

    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        if (std::getline(iss, date, ',') && std::getline(iss, value_str))
        {
            value = static_cast<float>(std::atof(value_str.c_str()));
            _database[date] = value;
        }
    }
}

float BitcoinExchange::getExchangeRate(const std::string &date)
{
    std::map<std::string, float>::iterator it = _database.lower_bound(date);
    if (it == _database.begin())
    {
        return -1;
    }
    --it;
    return it->second;
}

void BitcoinExchange::convert(std::ifstream &inputFile) {
    std::string line, date;
    float amount;

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        if (std::getline(iss, date, '|') && (iss >> amount))
        {
            if (amount < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            if (amount > 1000)
            {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            float rate = getExchangeRate(date);
            if (rate == -1)
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }

            std::cout << date << " => " << amount << " = " << rate * amount << std::endl;
        }
        else
        {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
}