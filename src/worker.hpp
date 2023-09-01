#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <memory>
#include "card.hpp"

// using cardPtr = std::shared_ptr<Card>();

enum class Gender {Male, Female, Other};

class Worker
{
protected:
    std::string name_;
    std::string surname_;
    long int id_number_;
    std::string address_;
    std::string state_;
    Gender gender_;
    std::shared_ptr<Card> cardPtr_;
public:
    Worker(
        const std::string& name,
        const std::string& surname,
        long int id_number,
        const std::string& address,
        const std::string& state,
        Gender gender,
        std::shared_ptr<Card> cardPtr
        );
    std::string getName() const;
    std::string getSurname() const;
    long int getIdNumber() const;
    std::string getAddress() const;
    std::string getState() const;
    Gender getGender() const;
    std::shared_ptr<Card> getCard() const;

};

#endif