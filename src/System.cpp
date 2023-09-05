#include "System.hpp"
#include <algorithm>
#include <fstream>
void System::addWorker(const Worker &worker)
{
    workers.push_back(worker);
}
std::vector<Worker> System::getWorkers() const
{
    return workers;
}
bool System::removeWorkerByIdNumber(long int idNumber)
{
    auto it = std::remove_if(workers.begin(), workers.end(),
                             [idNumber](const Worker &worker)
                             { return worker.getIdNumber() == idNumber; });

    if (it != workers.end())
    {
        workers.erase(it, workers.end());
        return true;
    }
    else
        return false;
}
Worker *System::findBySurname(const std::string &surname) 
{
    for (auto &worker : workers)
        if (worker.getSurname() == surname)
            return &worker;
    return nullptr;
}

Worker *System::findByIdNumber(long int idNumber)
{
    for (auto &worker : workers)
        if (worker.getIdNumber() == idNumber)
            return &worker;
    return nullptr;
}

void System::SortBySurname()
{
    std::sort(workers.begin(), workers.end(),
              [](const Worker &a, const Worker &b)
              { return a.getSurname() < b.getSurname(); });
}

void System::generateWorkersReport(const std::string &filename) const
{
    std::ofstream reportFile(filename);

    if (reportFile)
    {
        std::cerr << "Failed to open the raport file" << std::endl;
        return;
    }

    reportFile << "Employee Raport" << std::endl;
    reportFile << "------------------\n\n";

    for (const auto &worker : workers)
    {
        reportFile << "Name: " << worker.getName() << std::endl;
        reportFile << "Surname: " << worker.getSurname() << std::endl;
        reportFile << "ID Number: " << worker.getIdNumber() << std::endl;
        reportFile << "Address: " << worker.getAddress() << std::endl;
        reportFile << "Job Title: " << worker.getJobTitle() << std::endl;
        reportFile << "Gender: " << worker.getGenderAsString() << std::endl;
        reportFile << "------------------" << std::endl;
    }

    reportFile.close();
}

void System::generateArrivalDepartureReport(const std::string filename) const
{
    std::ofstream reportFile(filename);

    if (!reportFile)
    {
        std::cerr << "Failed to open the raport file" << std::endl;
        return;
    }

    reportFile << "Arrival and Departure Raport\n\n";

    for (const auto &worker : workers)
    {
        reportFile << "Worker: " << worker.getName() << " " << worker.getSurname()
                   << ", Id Number: " << worker.getIdNumber() << std::endl;

        const std::vector<std::string> &arrivalTimes = worker.getCard()->getArrivalTimes();
        const std::vector<std::string> &departureTimes = worker.getCard()->getDeparureTimes();

        reportFile << "Arrival Times:\n";
        for(const auto& arrival : arrivalTimes)
            reportFile << " " << arrival << std::endl;
        
        reportFile << "Departure Times:\n";
        for(const auto& departure : departureTimes)
            reportFile << " " << departure << std::endl;
    }
}
