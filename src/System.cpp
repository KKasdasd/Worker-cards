#include "System.hpp"
#include <algorithm>
#include <fstream>

void System::addWorker(Worker &worker)
{
    for (const auto &existingWorker : workers_)
    {
        if ((existingWorker.getName() == worker.getName()) &&
            (existingWorker.getSurname() == worker.getSurname()))
        {
            int uniqueIndex = 1;
            std::string uniqueName = worker.getName() + "." + std::to_string(uniqueIndex);
            while (std::any_of(workers_.begin(), workers_.end(),
                               [uniqueName](const Worker &w)
                               { return w.getName() == uniqueName; }))
            {
                uniqueIndex++;
                uniqueName = worker.getName() + "." + std::to_string(uniqueIndex);
            }
            worker.setName(uniqueName);
            break;
        }
    }
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

void System::generateArrivalDepartureReport(const std::string filename) const
{
    std::ofstream reportFile(filename);

    if (!reportFile)
    {
        std::cerr << "Failed to open the raport file" << std::endl;
        return;
    }

    reportFile << "Arrival and Departure Raport\n\n";

    for (const auto &worker : workers_)
    {
        reportFile << "Worker: " << worker.getName() << " " << worker.getSurname()
                   << ", Id Number: " << worker.getIdNumber() << std::endl;

        auto range = clockTimes_.equal_range(worker.getIdNumber());

        reportFile << "Arrival Times:\n";
        for(auto it = range.first; it != range.second; it++)
            reportFile << " " << std::asctime(std::localtime(&it->second.first));

        reportFile << "Departure Times:\n";
        for(auto it = range.first; it != range.second; it++)
            reportFile << " " << std::asctime(std::localtime(&it->second.second));
    }
}

void System::clockIn(unsigned long int idNumber)
{
    std::time_t currentTime = std::time(nullptr);
    auto it = clockTimes_.find(idNumber);

    if (it != clockTimes_.end())
        it->second.first = currentTime;
    else
        std::cerr << "Worker not found" << std::endl;
}

void System::clockOut(unsigned long int idNumber)
{
    std::time_t currentTime = std::time(nullptr);
    auto it = clockTimes_.find(idNumber);

    if (it != clockTimes_.end())
        it->second.second = currentTime;
    else
        std::cerr << "Worker not found" << std::endl;
}

std::map<unsigned long int, Worker> System::findWorker(
    const std::string &name,
    const std::string &surname,
    unsigned long int id) const
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

std::time_t System::getTotalWorkHours(unsigned long int cardId) const
{
    auto range = clockTimes_.equal_range(cardId);
    std::time_t totalWorkHours = 0;

    for (auto it = range.first; it != range.second; it++)
    {
        std::time_t clockInTime = it->second.first;
        std::time_t clockOutTime = it->second.second;

        if(clockOutTime != 0)
            totalWorkHours += (clockOutTime - clockInTime) / 3600;
    }
    return totalWorkHours;
}

// methodes for tests
