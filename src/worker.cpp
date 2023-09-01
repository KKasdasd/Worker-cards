#include "worker.hpp"

Worker::Worker(
    const std::string& name,
    const std::string& surname,
    long int id_number,
    const std::string& address,
    const std::string& state,
    Gender gender,
    std::shared_ptr<Card> cardPtr
) 
    : name_(name),
      surname_(surname),
      id_number_(id_number),
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
    return id_number_;
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