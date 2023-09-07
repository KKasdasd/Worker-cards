#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <iostream>
#include <map>
#include "Worker.hpp"
#include "Card.hpp"

class Worker;
class Card;
class System
{
private:
    std::vector<Worker> workers_;
    std::multimap<unsigned long int, std::pair<std::time_t, std::time_t>> clockTimes_;
    

public:
    // worker methods
    void addWorker(Worker &worker);
    bool removeWorker(unsigned long int idNumber);
    std::vector<Worker> getWorkers() const;
    const Worker* findWorker(unsigned long int idNumber) const;
    void SortBySurname();
    void generateWorkersReport(const std::string &filename) const;
    void generateArrivalDepartureReport(const std::string filename) const;
    std::time_t getTotalWorkHours(unsigned long int workerId) const;
    void clockIn(const Worker &worker);
    void clockOut(const Worker &worker);
    

    // Methods for tests issue
};

#endif