#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    Bitcoin b;
    std::ifstream database(argv[1]);
    if (!database)
    {
        std::cerr << "Error : Can't open file" << std::endl;
        return (1);
    }
    b.convert(database);

    return (0);
}