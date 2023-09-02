#include "worker.hpp"

Worker::Worker(
    const std::string& name,
    const std::string& surname,
    long int idNumber,
    const std::string& address,
    const std::string& state,
    Gender gender,
    std::shared_ptr<Card> cardPtr
) 
    : name_(name),
      surname_(surname),
      idNumber_(idNumber),
      address_(address),
      state_(state),
      gender_(gender),
      cardPtr_(std::make_shared<Card>()) {}

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
std::string Worker::getState() const
{
    return state_;
}
Gender Worker::getGender() const
{
    return gender_;
}
std::shared_ptr<Card> Worker::getCard() const
{
    return cardPtr_;
}

void Worker::setName(const std::string& name)
{
    name_ = name;
}
void Worker::setSurname(const std::string& surname)
{
    surname_ = surname;
}
void Worker::setIdNumber(long int idNumber)
{
    idNumber_ = idNumber;
}
void Worker::setAddress(const std::string& address)
{
    address_ = address;
}
void Worker::setState(const std::string& state)
{
    state_ = state;
}
void Worker::setGender(const Gender& gender)
{
    gender_ = gender;
}
void Worker::setCard(std::shared_ptr<Card> cardPtr)
{
    cardPtr_ = cardPtr;
}