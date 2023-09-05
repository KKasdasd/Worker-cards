#include "Card.hpp"
#include <chrono>
#include <ctime>

unsigned int Card::cardIdTracker_ = 1;
Card::Card() : cardId_(cardIdTracker_)
{
    cardIdTracker_++;
}
Card::~Card() {}
// getters

unsigned long int Card::getCardId() const
{
    return cardId_;
}

// Methodes
void Card::clockIn(System &system)
{
    system.clockIn(cardId_);
}
void Card::clockOut(System &system)
{
    system.clockOut(cardId_);
}

// Methodes for tests issue
void Card::resetCardIdTracker()
{
    cardIdTracker_ = 1;
}
