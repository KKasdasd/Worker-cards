#ifndef CARD_HPP
#define CARD_HPP

#include <ctime>
#include "System.hpp"


class Card
{
protected:
    unsigned long int cardId_;

public:
    Card();
    // getters
    unsigned long int getCardId() const;

    // Methods
    std::time_t clockIn() const;
    std::time_t clockOut() const;

    //test issue
    std::time_t timeTravel() const;
};

#endif