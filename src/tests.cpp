#include <gtest/gtest.h>
#include "worker.hpp"
#include "card.hpp"

TEST(WorkerTest, ConstructorInitialization)
{
  std::string name = "name example";
  std::string surname = "surname example";
  long int idNumber = 12345678901;
  std::string address = "adress example";
  std::string state = "state example";
  Gender gender = Gender::Male;
  std::shared_ptr<Card> cardPtr = std::make_shared<Card>();

  Worker w1(name, surname, idNumber, address, state, gender, cardPtr);

  EXPECT_EQ(w1.getName(), name);
  EXPECT_EQ(w1.getSurname(), surname);
  EXPECT_EQ(w1.getIdNumber(), idNumber);
  EXPECT_EQ(w1.getAddress(), address);
  EXPECT_EQ(w1.getState(), state);
  EXPECT_EQ(w1.getGender(), gender);
  EXPECT_TRUE(w1.getCard() != nullptr);
}

TEST(WorkerTest, SetterMethods)
{
  std::string name = "name example";
  std::string surname = "surname example";
  long int idNumber = 12345678901;
  std::string address = "adress example";
  std::string state = "state example";
  Gender gender = Gender::Male;
  std::shared_ptr<Card> cardPtr = nullptr;

  Worker w1(name, surname, idNumber, address, state, gender, cardPtr);
  std::shared_ptr<Card> newCard = std::make_shared<Card>();

  w1.setName("New name");
  w1.setSurname("New surname");
  w1.setIdNumber(12345);
  w1.setAddress("New address");
  w1.setState("New state");
  w1.setGender(Gender::Female);
  w1.setCard(newCard);

  EXPECT_EQ(w1.getName(), "New name");
  EXPECT_EQ(w1.getSurname(), "New surname");
  EXPECT_EQ(w1.getIdNumber(), 12345);
  EXPECT_EQ(w1.getAddress(), "New address");
  EXPECT_EQ(w1.getState(), "New state");
  EXPECT_EQ(w1.getGender(), Gender::Female);
  EXPECT_TRUE(w1.getCard() != nullptr);
}

TEST(CardTest, InitialValues)
{
  Card card;
  
  EXPECT_TRUE(card.getArrivalTimes().empty());
  EXPECT_TRUE(card.getDparureTimes().empty());

  EXPECT_EQ(card.getTimeIn(), 0);
  EXPECT_EQ(card.getTimeOut(), 0);

}

TEST(CardTest, ClockInAndOut)
{
  Card card;

  card.clockIn();
  EXPECT_FALSE(card.getArrivalTimes().empty());

  card.clockOut();
  EXPECT_FALSE(card.getDparureTimes().empty());
}