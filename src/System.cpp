#include "System.hpp"
#include <algorithm>
#include <fstream>

void System::addWorker(const Worker &worker)
{
    workers_.push_back(worker);
}
std::vector<Worker> System::getWorkers() const
{
    return workers_;
}
bool System::removeWorker(unsigned long int idNumber)
{
    std::map<unsigned long int, Worker> workerToRemove = findWorker("", "", idNumber);

    if (workerToRemove.empty())
    {
        std::cerr << "Worker with ID: " << idNumber << " not found." << std::endl;
        return false;
    }

    for (const auto &entry : workerToRemove)
    {
        auto it = std::remove_if(workers_.begin(), workers_.end(),
                                 [entry](const Worker &worker)
                                 { return worker.getIdNumber() == entry.first; });
        if (it != workers_.end())
        {
            workers_.erase(it, workers_.end());
            return true;
        }
    }
    return false;
}
Worker *System::findBySurname(const std::string &surname)
{
    for (auto &worker : workers_)
        if (worker.getSurname() == surname)
            return &worker;
    return nullptr;
}

Worker *System::findByIdNumber(long int idNumber)
{
    for (auto &worker : workers_)
        if (worker.getIdNumber() == idNumber)
            return &worker;
    return nullptr;
}

void System::SortBySurname()
{
    std::sort(workers_.begin(), workers_.end(),
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

    for (const auto &worker : workers_)
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

// void System::generateArrivalDepartureReport(const std::string filename) const
// {
//     std::ofstream reportFile(filename);

//     if (!reportFile)
//     {
//         std::cerr << "Failed to open the raport file" << std::endl;
//         return;
//     }

//     reportFile << "Arrival and Departure Raport\n\n";

//     for (const auto &worker : workers)
//     {
//         reportFile << "Worker: " << worker.getName() << " " << worker.getSurname()
//                    << ", Id Number: " << worker.getIdNumber() << std::endl;

//         const std::vector<std::string> &arrivalTimes = worker.getCard()->getArrivalTimes();
//         const std::vector<std::string> &departureTimes = worker.getCard()->getDeparureTimes();

//         reportFile << "Arrival Times:\n";
//         for(const auto& arrival : arrivalTimes)
//             reportFile << " " << arrival << std::endl;

//         reportFile << "Departure Times:\n";
//         for(const auto& departure : departureTimes)
//             reportFile << " " << departure << std::endl;
//     }
// }

void System::clockIn(unsigned long int cardId)
{
    std::time_t currentTime = std::time(nullptr);
    auto it = clockTimes_.find(cardId);

    if (it != clockTimes_.end())
        it->second.first = currentTime;
    else
        std::cerr << "Worker not found" << std::endl;
}

void System::clockOut(unsigned long int cardId)
{
    std::time_t currentTime = std::time(nullptr);
    auto it = clockTimes_.find(cardId);

    if (it != clockTimes_.end())
        it->second.second = currentTime;
    else
        std::cerr << "Worker not found" << std::endl;
}

std::map<unsigned long int, Worker> System::findWorker(
    const std::string &name = "",
    const std::string &surname = "",
    unsigned long int id = 0) const
{
    std::map<unsigned long int, Worker> matchingWorkers;

    for (const auto &worker : workers_)
    {
        if ((name.empty() || worker.getName() == name) &&
            (surname.empty() || worker.getSurname() == surname) &&
            (id == 0 || worker.getIdNumber() == id))
        {
            matchingWorkers[worker.getIdNumber()] = worker;
        }
    }
    return matchingWorkers;
}

// methodes for tests
