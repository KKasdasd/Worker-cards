#include <gtest/gtest.h>
#include "../src/Worker.hpp"
#include "../src/Card.hpp"
#include "../src/System.hpp"

#if 0

Worker createDefaultWorker()
{
  std::string name = "name example";
  std::string surname = "surname example";
  unsigned long int idNumber = 12345678901;
  std::string address = "address example";
  std::string jobTitle = "job title example";
  Gender gender = Gender::Male;

  return Worker(name, surname, idNumber, address, jobTitle, gender);
}

Worker createDefaultWorker2()
{
  std::string name = "name example2";
  std::string surname = "surname example2";
  unsigned long int idNumber = 2137;
  std::string address = "address example2";
  std::string jobTitle = "job title example2";
  Gender gender = Gender::Female;

  return Worker(name, surname, idNumber, address, jobTitle, gender);
}

// Worker Tests
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

TEST(WorkerTest, PrintWorkerData)
{
  Worker w1 = createDefaultWorker();

  std::stringstream output;
  std::streambuf *oldStdout = std::cout.rdbuf(output.rdbuf());

  w1.printWorkerData();

  std::cout.rdbuf(oldStdout);

  std::string expectedOutput =
      "Worker informations\n\n"
      "Name: name example\n"
      "Surname: surname example\n"
      "Id number: 12345678901\n"
      "Address: address example\n"
      "Job title: job title example\n"
      "Gender: Male\n";

  EXPECT_EQ(output.str(), expectedOutput);
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
// Card tests
TEST(CardTest, InitialValues)
{
  Card::resetCardIdTracker();
  Card card;
  Card card2;

  EXPECT_EQ(card.getCardId(), 1);
  EXPECT_EQ(card2.getCardId(), 2);
}

TEST(CardTest, clockInOut)
{
}

TEST(CardTest, ClockInOutCustomTime)
{
  Card card;
  std::tm customTime{};
  customTime.tm_year = 123;
  customTime.tm_year = 0;
  customTime.tm_mday = 1;
  customTime.tm_hour = 12;
  customTime.tm_min = 30;
  customTime.tm_sec = 0;

  std::time_t customClockTime = std::mktime(&customTime);
}

TEST(WorkerCardInteractionTest, WorkerCreatesCard)
{
  Worker w1 = createDefaultWorker();

  EXPECT_TRUE(w1.getCard() != nullptr);
}

// System tests
TEST(SystemTest, AddRemoveWorker)
{
  System mySystem;
  Worker w1 = createDefaultWorker();
  Worker w2 = createDefaultWorker2();
  mySystem.addWorker(w1);

  EXPECT_TRUE(!mySystem.getWorkers().empty());
  EXPECT_TRUE(mySystem.removeWorkerByIdNumber(w1.getIdNumber()));
  EXPECT_FALSE(mySystem.removeWorkerByIdNumber(w2.getIdNumber()));
  EXPECT_FALSE(mySystem.removeWorkerByIdNumber(w1.getIdNumber()));
}

TEST(SystemTest, FindBySurname)
{
  System mySystem;
  Worker w1 = createDefaultWorker();
  Worker w2 = createDefaultWorker2();

  mySystem.addWorker(w1);
  mySystem.addWorker(w2);

  Worker *foundWorker = mySystem.findBySurname(w1.getSurname());
  EXPECT_EQ(foundWorker->getIdNumber(), w1.getIdNumber());

  foundWorker = mySystem.findBySurname("No Existent Surname");
  EXPECT_EQ(foundWorker, nullptr);
}

TEST(SystemTest, FindByIdNumber)
{
  System mySystem;
  Worker w1 = createDefaultWorker();
  Worker w2 = createDefaultWorker2();

  mySystem.addWorker(w1);
  mySystem.addWorker(w2);

  Worker *foundWorker = mySystem.findByIdNumber(w1.getIdNumber());
  EXPECT_EQ(foundWorker->getSurname(), w1.getSurname());

  foundWorker = mySystem.findByIdNumber(000000);
  EXPECT_EQ(foundWorker, nullptr);
}
#endif