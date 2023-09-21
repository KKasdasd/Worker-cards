#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <iostream>
#include <map>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Worker.hpp"
#include "Card.hpp"

class Worker;
class Card;
class System
{
private:
    std::vector<Worker> workers_;
    std::multimap<unsigned long int, std::pair<std::time_t, std::time_t>> clockTimes_;
    static unsigned long int cardIdCounter_;
    std::multimap<std::string, std::pair<Worker, double>> monthlySalaryReport_;
    

public:
    // worker methods
    void addWorker(Worker &worker);
    bool removeWorker(unsigned long int idNumber);
    std::vector<Worker> getWorkers() const;
    std::multimap<unsigned long int, std::pair<std::time_t, std::time_t>> getClockTimes() const;
    const Worker* findWorker(unsigned long int idNumber) const;
    void SortBySurname();
    void generateWorkersReport(const std::string &filename) const;
    void generateArrivalDepartureReport(const std::string filename) const;
    std::time_t getTotalWorkHours(unsigned long int workerId) const;
    void clockIn(const Worker &worker);
    void clockOut(const Worker &worker);
    static unsigned long int generateCardId();
    std::string getCurrentMonthAndYear() const;
    void calculateMonthlySalaries();
    std::multimap<std::string, std::pair<Worker, double>> getMonthlySalaryReport() const;
    void generateSalaryReport(const std::string &filename) const;
    
    

    // Methods for tests issue
    void resetIdCardCounter();
    void timeTravel(const Worker &worker);

};

#endif