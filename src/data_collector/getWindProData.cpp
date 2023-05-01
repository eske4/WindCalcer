#include "getWindProData.h"

void printDate()
{
    boost::gregorian::date current_date = boost::gregorian::day_clock::local_day();
    std::cout << "Current date: " << current_date << std::endl;
}