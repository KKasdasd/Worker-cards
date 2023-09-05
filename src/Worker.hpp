#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <memory>
#include "Card.hpp"

// using cardPtr = std::shared_ptr<Card>();

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

public:
    Worker(
        const std::string &name,
        const std::string &surname,
        unsigned long int id_number,
        const std::string &address,
        const std::string &jobTitle,
        Gender gender);

    ~Worker();

    // getters
    std::string getName() const;
    std::string getSurname() const;
    unsigned long int getIdNumber() const;
    std::string getAddress() const;
    std::string getJobTitle() const;
    Gender getGender() const;
    std::shared_ptr<Card> getCard() const;

    // setters
    void setName(const std::string &name);
    void setSurname(const std::string &surname);
    void setIdNumber(unsigned long int idNumber);
    void setAddress(const std::string &address);
    void setJobTitle(const std::string &state);
    void setGender(const Gender &gender);

    //Methodes
    void printWorkerData() const;
    std::string getGenderAsString() const;

};

#endif