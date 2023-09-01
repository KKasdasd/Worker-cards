#include <gtest/gtest.h>
#include "worker.hpp"
#include "card.hpp"

TEST(WorkerTest, ConstructorInitialization)
{
    std::string name = "name example";
    std::string surname = "surname example";
    long int id_number = 12345678901;
    std::string address = "adress example";
    std::string state = "state example";
    Gender gender = Gender::Male;
    std::shared_ptr<Card> cardPtr = std::make_shared<Card>();

    Worker w1(name,surname,id_number,address,state,gender,cardPtr);

    EXPECT_EQ(w1.getName(), name);
    EXPECT_EQ(w1.getSurname(), surname);
    EXPECT_EQ(w1.getIdNumber(), id_number);
    EXPECT_EQ(w1.getAddress(), address);
    EXPECT_EQ(w1.getState(), state);
    EXPECT_EQ(w1.getGender(), gender);
    EXPECT_TRUE(w1.getCard() != nullptr);
}