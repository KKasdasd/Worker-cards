#include "System.hpp"
#include <algorithm>
#include <fstream>

unsigned long int System::cardIdCounter_ = 1;

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
    clockTimes_.emplace(worker.getIdNumber(), std::make_pair(0, 0));
}
bool System::removeWorker(unsigned long int idNumber)
{
    auto it = std::remove_if(workers_.begin(), workers_.end(),
                             [idNumber](const Worker &w)
                             { return w.getIdNumber() == idNumber; });

    if (it != workers_.end())
    {
        clockTimes_.erase(idNumber);
        workers_.erase(it, workers_.end());
        std::cout << "Worker: " << it->getName() << " " << it->getSurname()
                  << " id: " << it->getIdNumber() << " successfully removed";
        return true;
    }
    std::cout << "Could not find worker for given parameter: " << idNumber;
    return false;
}

std::vector<Worker> System::getWorkers() const
{
    return workers_;
}
std::multimap<unsigned long int, std::pair<std::time_t, std::time_t>> System::getClockTimes() const 
{
    return clockTimes_;
}

const Worker *System::findWorker(unsigned long int idNumber) const
{
    for (const auto &worker : workers_)
    {
        if (worker.getIdNumber() == idNumber)
            return &worker;
    }
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
        reportFile << "Pension: " << worker.getPension() << std::endl;
        reportFile << "Salary per hour: " << worker.getSalaryPerHour() << std::endl;
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
        for (auto it = range.first; it != range.second; it++)
            reportFile << " " << std::asctime(std::localtime(&it->second.first));

        reportFile << "Departure Times:\n";
        for (auto it = range.first; it != range.second; it++)
            reportFile << " " << std::asctime(std::localtime(&it->second.second));
    }
}

std::time_t System::getTotalWorkHours(unsigned long int workerId) const
{
    std::time_t totalWorkHours = 0;

    for (const auto &entry : clockTimes_)
    {
        if (entry.first == workerId)
        {
            std::time_t clockInTime = entry.second.first;
            std::time_t clockOutTime = entry.second.second;

            if (clockOutTime != 0)
                totalWorkHours = (clockOutTime - clockInTime) / 3600;
        }
    }
    return totalWorkHours;
}
void System::clockIn(const Worker &worker)
{
    std::time_t currentTime = worker.getCard()->clockIn();
    auto it = clockTimes_.find(worker.getIdNumber());
    if (it != clockTimes_.end())
        it->second.first = currentTime;
    else
        std::cerr << "Worker not found" << std::endl;
}

void System::clockOut(const Worker &worker)
{
    std::time_t currentTime = worker.getCard()->clockOut();
    auto it = clockTimes_.find(worker.getIdNumber());
    if (it != clockTimes_.end())
        it->second.second = currentTime;
    else
        std::cerr << "Worker not found" << std::endl;
}

unsigned long int System::generateCardId()
{
    return cardIdCounter_++;
}

// methods for tests
void System::resetIdCardCounter()
{
    cardIdCounter_ = 1;
}
