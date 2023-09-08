#include <gtest/gtest.h>
#include "../src/Worker.hpp"
#include "../src/Card.hpp"
#include "../src/System.hpp"

class WorkerTest : ::testing::Test
{
protected:
  Worker worker;
public:
  void setUp() 
  {
    worker = Worker("Example name",
                    "Example surname",
                    12345678901,
                    "Example address",
                    "Example job title",
                    Gender::Male,
                    1000.0,
                    25.0);
  }
};

// TEST_F(WorkerTest, ConstructorAndGetters)
// {
//   EXPECT_EQ(worker.getName(), "Example name");
//   EXPECT_EQ(worker.getSurname(), "Example surname");
//   EXPECT_EQ(worker.getIdNumber(), 11345678901);
//   EXPECT_EQ(worker.getAddress(), "Example address");
//   EXPECT_EQ(worker.getJobTitle(), "Example job title");
//   EXPECT_EQ(worker.getGender(), Gender::Male);
//   EXPECT_EQ(worker.getPension(), 1000.0);
//   EXPECT_EQ(worker.getSalaryPerHour(), 25.0);
  
// }


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