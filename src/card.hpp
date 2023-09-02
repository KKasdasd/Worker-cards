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

public:
    Card();
    ~Card();
    // getters
    std::time_t getTimeIn() const;
    std::time_t getTimeOut() const;
    const std::vector<std::string>& getArrivalTimes() const;
    const std::vector<std::string>& getDparureTimes() const;
    //Methodes
    void clockIn();
    void clockOut();
};

#endif