#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <iostream>
#include "Worker.hpp"

class System
{
private:
    std::vector<Worker> workers;

public:
    void addWorker(const Worker &worker);
    bool removeWorkerByIdNumber(long int idNumber);
    std::vector<Worker> getWorkers() const;
    Worker *findBySurname(const std::string &surname);
    Worker *findByIdNumber(long int idNumber);
    void SortBySurname();
    void generateWorkersReport(const std::string& filename) const;
    void generateArrivalDepartureReport(const std::string filename) const;
};

#endif