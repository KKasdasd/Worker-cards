#include <gtest/gtest.h>
#include "worker.hpp"
#include "card.hpp"

Worker createDefaultWorker()
{
  std::string name = "name example";
  std::string surname = "surname example";
  long int idNumber = 12345678901;
  std::string address = "address example";
  std::string jobTitle = "job title example";
  Gender gender = Gender::Male;

  return Worker(name, surname, idNumber, address, jobTitle, gender);
}

TEST(WorkerTest, ConstructorInitialization)
{

  Worker w1 = createDefaultWorker();

  EXPECT_EQ(w1.getName(), "name example");
  EXPECT_EQ(w1.getSurname(), "surname example");
  EXPECT_EQ(w1.getIdNumber(), 12345678901);
  EXPECT_EQ(w1.getAddress(), "address example");
  EXPECT_EQ(w1.getJobTitle(), "job title example");
  EXPECT_EQ(w1.getGender(), Gender::Male);
  EXPECT_TRUE(w1.getCard() != nullptr);
}

TEST(WorkerTest, SetterMethods)
{

  Worker w1 = createDefaultWorker();

  w1.setName("New name");
  w1.setSurname("New surname");
  w1.setIdNumber(12345);
  w1.setAddress("New address");
  w1.setJobTitle("New job title");
  w1.setGender(Gender::Female);

  EXPECT_EQ(w1.getName(), "New name");
  EXPECT_EQ(w1.getSurname(), "New surname");
  EXPECT_EQ(w1.getIdNumber(), 12345);
  EXPECT_EQ(w1.getAddress(), "New address");
  EXPECT_EQ(w1.getJobTitle(), "New job title");
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

TEST(WorkerCardInteractionTest, WorkerCreatesCard)
{
  Worker w1 = createDefaultWorker();

  EXPECT_TRUE(w1.getCard() != nullptr);
}

TEST(WorkerCardInteractionTest, WorkerClockInClockOut)
{

  Worker w1 = createDefaultWorker();

  w1.getCard()->clockIn();
  w1.getCard()->clockOut();

  EXPECT_FALSE(w1.getCard()->getArrivalTimes().empty());
  EXPECT_FALSE(w1.getCard()->getDparureTimes().empty());
}