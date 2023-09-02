#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <memory>
#include "card.hpp"

// using cardPtr = std::shared_ptr<Card>();

enum class Gender
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
    long int idNumber_;
    std::string address_;
    std::string state_;
    Gender gender_;
    std::shared_ptr<Card> cardPtr_;

public:
    Worker(
        const std::string &name,
        const std::string &surname,
        long int id_number,
        const std::string &address,
        const std::string &state,
        Gender gender,
        std::shared_ptr<Card> cardPtr);

    ~Worker();

    // getters
    std::string getName() const;
    std::string getSurname() const;
    long int getIdNumber() const;
    std::string getAddress() const;
    std::string getState() const;
    Gender getGender() const;
    std::shared_ptr<Card> getCard() const;

    // setters
    void setName(const std::string &name);
    void setSurname(const std::string &surname);
    void setIdNumber(long int idNumber);
    void setAddress(const std::string &address);
    void setState(const std::string &state);
    void setGender(const Gender &gender);
    void setCard(std::shared_ptr<Card> cardPtr);
};

#endif