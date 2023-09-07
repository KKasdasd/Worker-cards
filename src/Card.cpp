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

// Methods
void Card::clockIn(System &system)
{
    system.clockIn(cardId_);
}
void Card::clockOut(System &system)
{
    system.clockOut(cardId_);
}

// Methods for tests issue
void Card::resetCardIdTracker()
{
    cardIdTracker_ = 1;
}
