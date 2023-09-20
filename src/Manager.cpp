#include "Manager.hpp"
#include <algorithm>

Manager::Manager(
    const std::string &name,
    const std::string &surname,
    unsigned long int id_number,
    const std::string &address,
    const std::string &jobTitle,
    Gender gender,
    double salaryPerHour)
    : Worker(name, surname, id_number, address, jobTitle, gender, salaryPerHour) {}

void Manager::addWorker(Worker &worker)
{
    team_.push_back(&worker);
}

std::vector<Worker *> Manager::getTeam() const
{
    return team_;
}
void Manager::showWorkers() const
{
    for (const auto &worker : team_)
        std::cout << worker << std::endl;
}
bool Manager::removeWorker(unsigned long int idNumber)
{
    auto it = std::find_if(team_.begin(), team_.end(),
                           [&](const Worker *workerPtr)
                           { return workerPtr->getIdNumber() == idNumber; });
    if (it != team_.end())
    {
        team_.erase(it, team_.end());
        std::cout << "Worker: " << (*it)->getName() << " " << (*it)->getSurname()
                  << "id: " << (*it)->getIdNumber() << " successfully removed from team";
        team_.erase(it);
        return true;
    }
    std::cout << "Could not find worker for given parameter: " << idNumber;
    return false;
}

unsigned int Manager::getTeamSize() const
{
    return team_.size();
}

void Manager::updateSalary(unsigned long int idNumber, double newSalary)
{
    for (auto workerPtr : team_)
    {
        if (workerPtr->getIdNumber() == idNumber)
            workerPtr->setSalaryPerHour(newSalary);
    }
}