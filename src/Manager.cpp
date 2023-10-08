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

void Manager::addWorker(Worker worker)
{
    team_.push_back(worker);
}

std::vector<Worker> Manager::getTeam() const
{
    return team_;
}
bool Manager::removeWorker(unsigned long int idNumber)
{
    auto it = std::remove_if(team_.begin(), team_.end(),
                           [&](const  Worker &w)
                           { return w.getIdNumber() == idNumber; });
    if (it != team_.end())
    {
        team_.erase(it, team_.end());
        std::cout << "Worker: " << it->getName() << " " << it->getSurname()
                  << "id: " << it->getIdNumber() << " successfully removed from team";
        team_.erase(it, team_.end());
        return true;
    }
    std::cout << "Could not find worker for given parameter: " << idNumber;
    return false;
}

unsigned int Manager::getTeamSize() const
{
    return team_.size();
}

