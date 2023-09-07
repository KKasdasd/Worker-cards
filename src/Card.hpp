#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <ctime>
#include <vector>
#include "System.hpp"

class System;
class Card
{
protected:
    unsigned long int cardId_;


public:
    Card();
    ~Card();
    // getters
    unsigned long int getCardId() const;

    //Methods
    std::time_t clockIn() const;
    std::time_t clockOut() const;
    //Methods for tests issue
    static void resetCardIdTracker();

};

#endif