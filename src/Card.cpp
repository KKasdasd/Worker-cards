#include "Card.hpp"
#include<chrono>
#include<ctime>

unsigned int Card::cardIdTracker_ = 1;
Card::Card() : cardId_(cardIdTracker_)
{
    cardIdTracker_ ++;
}
Card::~Card(){}
//getters
std::time_t Card::getTimeIn() const
{
    return timeIn_;
}
std::time_t Card::getTimeOut() const
{
    return timeOut_;
}
unsigned long int Card::getCardId() const
{
    return cardId_;
}
const std::vector<std::string>& Card::getArrivalTimes() const
{
    return arrivalTimes_;
}
const std::vector<std::string>& Card::getDeparureTimes() const
{
    return departureTimes_;
}
//Methodes
void Card::clockIn()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::string timeString = std::ctime(&currentTime);
    arrivalTimes_.push_back(timeString);
}
void Card::clockOut()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::string timeString = std::ctime(&currentTime);
    departureTimes_.push_back(timeString);
}

void Card::resetCardIdTracker()
{
    cardIdTracker_ = 1;
}

