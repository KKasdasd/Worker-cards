#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <memory>
#include "Card.hpp"

class Card;

enum Gender
{
    Male,
    Female,
    Other
};

class Worker
{
protected:
    std::string name_;
    std::string surname_;
    unsigned long int idNumber_;
    std::string address_;
    std::string jobTitle_;
    Gender gender_;
    std::shared_ptr<Card> cardPtr_;
    double salaryPerHour_;

public:
    Worker() = default;
    Worker(
        const std::string &name = "",
        const std::string &surname = "",
        unsigned long int id_number = 0,
        const std::string &address = 0,
        const std::string &jobTitle = 0,
        Gender gender = Gender::Other,
        double salaryPerHour_ = 0);





    // getters
    std::string getName() const;
    std::string getSurname() const;
    unsigned long int getIdNumber() const;
    std::string getAddress() const;
    std::string getJobTitle() const;
    Gender getGender() const;
    std::shared_ptr<Card> getCard() const;
    double getSalaryPerHour() const;

    // setters
    void setName(const std::string &name);
    void setSurname(const std::string &surname);
    void setIdNumber(unsigned long int idNumber);
    void setAddress(const std::string &address);
    void setJobTitle(const std::string &state);
    void setGender(const Gender &gender);
    void setSalaryPerHour(double salaryPerHour);

    // Methods
    void printWorkerData() const;
    std::string getGenderAsString() const;

};

#endif