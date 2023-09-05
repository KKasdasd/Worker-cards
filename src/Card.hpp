#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <ctime>
#include <vector>
class Card
{
protected:
    std::time_t timeIn_;
    std::time_t timeOut_;
    std::vector<std::string> arrivalTimes_;
    std::vector<std::string> departureTimes_;
    unsigned long int cardId_;
    static unsigned int cardIdTracker_;


public:
    Card();
    ~Card();
    // getters
    std::time_t getTimeIn() const;
    std::time_t getTimeOut() const;
    unsigned long int getCardId() const;
    const std::vector<std::string>& getArrivalTimes() const;
    const std::vector<std::string>& getDeparureTimes() const;
    //Methodes
    void clockIn();
    void clockOut();
    //Methodes for tests issue
    static void resetCardIdTracker();
    void clockIn(const std::time_t& customTime);
    void clockOut(const std::time_t& customTime);
};

#endif