#include "Worker.hpp"

Worker::Worker(
    const std::string &name,
    const std::string &surname,
    unsigned long int idNumber,
    const std::string &address,
    const std::string &jobTitle,
    Gender gender,
    double salaryPerHour)
    : name_(name),
      surname_(surname),
      idNumber_(idNumber),
      address_(address),
      jobTitle_(jobTitle),
      gender_(gender),
      cardPtr_(std::make_shared<Card>()),
      salaryPerHour_(salaryPerHour) {}

// getters
std::string Worker::getName() const
{
    return name_;
}
std::string Worker::getSurname() const
{
    return surname_;
}
unsigned long int Worker::getIdNumber() const
{
    return idNumber_;
}
std::string Worker::getAddress() const
{
    return address_;
}
std::string Worker::getJobTitle() const
{
    return jobTitle_;
}
Gender Worker::getGender() const
{
    return gender_;
}
std::shared_ptr<Card> Worker::getCard() const
{
    return cardPtr_;
}

double Worker::getSalaryPerHour() const
{
    return salaryPerHour_;
}

// setters
void Worker::setName(const std::string &name)
{
    name_ = name;
}
void Worker::setSurname(const std::string &surname)
{
    surname_ = surname;
}
void Worker::setIdNumber(unsigned long int idNumber)
{
    idNumber_ = idNumber;
}
void Worker::setAddress(const std::string &address)
{
    address_ = address;
}
void Worker::setJobTitle(const std::string &jobTitle)
{
    jobTitle_ = jobTitle;
}
void Worker::setGender(const Gender &gender)
{
    gender_ = gender;
}

void Worker::setSalaryPerHour(double salaryPerHour)
{
    salaryPerHour_ = salaryPerHour;
}

// methods
void Worker::printWorkerData() const
{
    std::cout << "Worker informations\n\n";
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Surname: " << getSurname() << std::endl;
    std::cout << "Id number: " << getIdNumber() << std::endl;
    std::cout << "Address: " << getAddress() << std::endl;
    std::cout << "Job title: " << getJobTitle() << std::endl;
    std::cout << "Gender: " << getGenderAsString() << std::endl;
    std::cout << "Salary per hour: " << getSalaryPerHour() << std::endl;
}

std::string Worker::getGenderAsString() const
{
    switch (getGender())
    {
    case Male:
        return "Male";
    case Female:
        return "Female";
    case Other:
        return "Other";
    default:
        return "Unknow";
    }
}

