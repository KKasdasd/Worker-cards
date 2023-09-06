#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <iostream>
#include <map>
#include "Worker.hpp"
#include "Card.hpp"

class Worker;
class System
{
private:
    std::vector<Worker> workers_;
    std::multimap<unsigned long int, std::pair<std::time_t, std::time_t>> clockTimes_;

public:
    // worker methodes
    void addWorker(Worker &worker);
    bool removeWorker(unsigned long int idNumber);
    std::vector<Worker> getWorkers() const;
    Worker *findBySurname(const std::string &surname);
    Worker *findByIdNumber(long int idNumber);
    void SortBySurname();
    void generateWorkersReport(const std::string &filename) const;
    void generateArrivalDepartureReport(const std::string filename) const;
    std::map<unsigned long int, Worker> findWorker(
        const std::string &name = "",
        const std::string &surname = "",
        unsigned long int id = 0) const;
    std::time_t getTotalWorkHours(unsigned long int cardId) const;

    // card methodes
    void clockIn(unsigned long int idNumber);
    void clockOut(unsigned long int idNumber);
    

    // Methodes for tests issue
};

#endif