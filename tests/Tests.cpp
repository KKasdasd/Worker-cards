#include <gtest/gtest.h>
#include "../src/Worker.hpp"
#include "../src/Card.hpp"
#include "../src/System.hpp"

class WorkerTest : public ::testing::Test
{
protected:
  Worker worker;
  std::ostringstream outputBuffer;

public:
  WorkerTest() : worker("Example name",
                        "Example surname",
                        12345678901,
                        "Example address",
                        "Example job title",
                        Gender::Male,
                        1000.0,
                        25.0) {}
  std::string getPrintedOutput() const
  {
    return outputBuffer.str();
  }
  void resetOutputBuffer()
  {
    outputBuffer.str("");
  }
};


TEST_F(WorkerTest, ConstructorAndGetters)
{
  EXPECT_EQ(worker.getName(), "Example name");
  EXPECT_EQ(worker.getSurname(), "Example surname");
  EXPECT_EQ(worker.getIdNumber(), 12345678901);
  EXPECT_EQ(worker.getAddress(), "Example address");
  EXPECT_EQ(worker.getJobTitle(), "Example job title");
  EXPECT_EQ(worker.getGender(), Gender::Male);
  EXPECT_EQ(worker.getPension(), 1000.0);
  EXPECT_EQ(worker.getSalaryPerHour(), 25.0);
}

TEST_F(WorkerTest, Setters)
{
  worker.setName("New name");
  worker.setSurname("New surname");
  worker.setIdNumber(123);
  worker.setAddress("New address");
  worker.setJobTitle("New job title");
  worker.setGender(Gender::Female);
  worker.setPension(500.0);
  worker.setSalaryPerHour(15.0);

  EXPECT_EQ(worker.getName(), "New name");
  EXPECT_EQ(worker.getSurname(), "New surname");
  EXPECT_EQ(worker.getIdNumber(), 123);
  EXPECT_EQ(worker.getAddress(), "New address");
  EXPECT_EQ(worker.getJobTitle(), "New job title");
  EXPECT_EQ(worker.getGender(), Gender::Female);
  EXPECT_EQ(worker.getPension(), 500.0);
  EXPECT_EQ(worker.getSalaryPerHour(), 15.0);
}

TEST_F(WorkerTest, GetGenderAsString)
{
  EXPECT_EQ(worker.getGenderAsString(), "Male");

  worker.setGender(Gender::Female);
  EXPECT_EQ(worker.getGenderAsString(), "Female");

  worker.setGender(Gender::Other);
  EXPECT_EQ(worker.getGenderAsString(), "Other");
}

TEST_F(WorkerTest, PrintWorkerData)
{
  std::streambuf* oldCoutBuffer = std::cout.rdbuf();
  std::cout.rdbuf(outputBuffer.rdbuf());

  worker.printWorkerData();

  std::cout.rdbuf(oldCoutBuffer);

  std::string expectedOutput =
    "Worker informations\n\n"
    "Name: Example name\n"
    "Surname: Example surname\n"
    "Id number: 12345678901\n"
    "Address: Example address\n"
    "Job title: Example job title\n"
    "Gender: Male\n"
    "Pension: 1000\n"
    "Salary per hour: 25\n";

  EXPECT_EQ(outputBuffer.str(), expectedOutput);
}

#if 0
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