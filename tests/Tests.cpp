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

class CardTest : public ::testing::Test
{
protected:
  Card card;
};

class SystemTest : public ::testing::Test
{
protected:
  System system;

public:
  void AddWorkerWihHours(const std::string &name, 
                        const std::string &surname,
                        unsigned long int id,
                        double hourlyRate,
                        double hoursWorked)
{
  Worker worker(name, surname, id, "address", "job title", Gender::Other, hourlyRate);
  system.addWorker(worker);

  for(int i = 0; i < hoursWorked; i++) 
  {
    system.clockIn(worker);
    system.clockOut(worker);
  }
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
  worker.setSalaryPerHour(15.0);

  EXPECT_EQ(worker.getName(), "New name");
  EXPECT_EQ(worker.getSurname(), "New surname");
  EXPECT_EQ(worker.getIdNumber(), 123);
  EXPECT_EQ(worker.getAddress(), "New address");
  EXPECT_EQ(worker.getJobTitle(), "New job title");
  EXPECT_EQ(worker.getGender(), Gender::Female);
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
  std::streambuf *oldCoutBuffer = std::cout.rdbuf();
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

// Card tests

TEST_F(CardTest, DefaultConstructor)
{
  EXPECT_NE(card.getCardId(), 0);
}

TEST_F(CardTest, ClockInAndOut)
{
  std::time_t startTime = card.clockIn();
  std::time_t endTime = card.clockOut();

  EXPECT_NE(startTime, static_cast<std::time_t>(-1));
  EXPECT_NE(endTime, static_cast<std::time_t>(-1));

  EXPECT_LE(startTime, endTime);
}
// System tests
TEST_F(SystemTest, AddWorkerGetWorkersGetIdCard)
{
  system.resetIdCardCounter();

  Worker w1("name", "surname", 123, "address", "job title", Gender::Other, 15.0);

  Worker w2("name2", "surname2", 123, "address2", "job title2", Gender::Female, 10.0);
  Worker w3("name", "surname", 123456, "address", "job title", Gender::Other, 15.0);

  system.addWorker(w1);
  system.addWorker(w2);
  system.addWorker(w3);

  std::vector<Worker> workers = system.getWorkers();
  EXPECT_EQ(workers.size(), 3);
  EXPECT_NE(w1.getName(), w3.getName());
  EXPECT_FALSE(system.getClockTimes().empty());

  EXPECT_EQ(w1.getCard()->getCardId(), 1);
  EXPECT_EQ(w2.getCard()->getCardId(), 2);
  EXPECT_EQ(w3.getCard()->getCardId(), 3);
}

TEST_F(SystemTest, RemoveWorkerFindWorker)
{
  Worker w1("name", "surname", 123, "address", "job title", Gender::Other, 15.0);
  system.addWorker(w1);
  const Worker *w2 = system.findWorker(w1.getIdNumber());
  EXPECT_EQ(w1.getIdNumber(), w2->getIdNumber());

  system.removeWorker(w1.getIdNumber());
  EXPECT_EQ(system.getWorkers().size(), 0);
  EXPECT_TRUE(system.getClockTimes().empty());
}

TEST_F(SystemTest, SortBySurname)
{
  Worker w1("name", "Smith", 123, "address", "job title", Gender::Other, 15.0);
  Worker w2("name", "Johnson", 123, "address", "job title", Gender::Other, 15.0);

  std::vector<Worker> workers;
  system.addWorker(w1);
  system.addWorker(w2);

  system.SortBySurname();
  for (size_t i = 1; i < system.getWorkers().size(); i++)
    EXPECT_LE(workers[i - 1].getSurname(), workers[i].getSurname());
}

TEST_F(SystemTest, CalculateMonthlySalaries)
{
  system.resetIdCardCounter();
  AddWorkerWihHours("Jhon", "Smith", 1, 20.0, 160);
  AddWorkerWihHours("Jhon2", "Smith3", 2, 30.0, 170);
  AddWorkerWihHours("Jhon3", "Smith3", 3, 40.0, 180);

  system.calculateMonthlySalaries();
  std::multimap<std::string, std::pair<Worker, double>> salaryReport =
  system.getMonthlySalaryReport();

  EXPECT_EQ(salaryReport.count(system.getCurrentMonthAndYear()), 3);
    for (const auto& entry : salaryReport)
    {
        const Worker& worker = entry.second.first;
        double salary = entry.second.second;

        if (worker.getIdNumber() == 1) // John's ID is 1
        {
            EXPECT_DOUBLE_EQ(salary, 3200.0);
        }
        else if (worker.getIdNumber() == 2) // Jane's ID is 2
        {
            EXPECT_DOUBLE_EQ(salary, 2100.0);
        }
        else if (worker.getIdNumber() == 3) // Alice's ID is 3
        {
            EXPECT_DOUBLE_EQ(salary, 4500.0);
        }
    }
}
