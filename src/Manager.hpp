#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "Worker.hpp"

class Manager : public Worker
{
private:
    std::vector<Worker*> team_;

public:
    Manager(
        const std::string &name = "",
        const std::string &surname = "",
        unsigned long int id_number = 0,
        const std::string &address = "",
        const std::string &jobTitle = "Manager",
        Gender gender = Gender::Other,
        double salaryPerHour = 0);

    void addWorker(Worker &worker);
    std::vector<Worker*> getTeam() const;
    void showWorkers() const;
    bool removeWorker(unsigned long int idNumber);
    unsigned int getTeamSize() const;
    void updateSalary(unsigned long int idNumber, double newSalary);
};

#endif