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
    static unsigned int cardIdTracker_;


public:
    Card();
    ~Card();
    // getters
    unsigned long int getCardId() const;

    //Methods
    void clockIn(System& system);
    void clockOut(System& system);
    //Methods for tests issue
    static void resetCardIdTracker();

};

#endif