#include "card.hpp"
#include<chrono>
#include<ctime>


Card::Card() : timeIn_(0), timeOut_(0){}

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

const std::vector<std::string>& Card::getArrivalTimes() const
{
    return arrivalTimes_;
}
const std::vector<std::string>& Card::getDparureTimes() const
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

