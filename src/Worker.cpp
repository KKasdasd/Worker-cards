#include "Worker.hpp"

Worker::Worker(
    const std::string &name,
    const std::string &surname,
    long int idNumber,
    const std::string &address,
    const std::string &jobTitle,
    Gender gender)
    : name_(name),
      surname_(surname),
      idNumber_(idNumber),
      address_(address),
      jobTitle_(jobTitle),
      gender_(gender),
      cardPtr_(std::make_shared<Card>()) {}

Worker::~Worker(){}

// getters
std::string Worker::getName() const
{
    return name_;
}
std::string Worker::getSurname() const
{
    return surname_;
}
long int Worker::getIdNumber() const
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

// setters
void Worker::setName(const std::string &name)
{
    name_ = name;
}
void Worker::setSurname(const std::string &surname)
{
    surname_ = surname;
}
void Worker::setIdNumber(long int idNumber)
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
