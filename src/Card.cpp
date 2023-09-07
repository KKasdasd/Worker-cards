#include "Card.hpp"



Card::Card() : cardId_(System::generateCardId()){}
// getters

unsigned long int  Card::getCardId() const
{
    return cardId_;
}

// Methods
std::time_t Card::clockIn() const
{
    std::time_t currentTime = std::time(nullptr);
    return currentTime;
}
std::time_t Card::clockOut() const
{
    std::time_t currentTime = std::time(nullptr);
    return currentTime;
}



// Methods for tests issue
