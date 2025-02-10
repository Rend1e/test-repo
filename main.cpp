#include <vector>
#include <functional>
#include <iostream>
#include "candle.h"
#include "tests.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

//тест 1
bool test1()
{
  //пример какого-то теста
  return 42 == (41 + 1); //passed
}

//тест 2
bool test2()
{
  //пример какого-то теста
  return 42 != (41 + 1); //failed
}

//тест 3
bool test3()
{
  Candle candle{ 0.0, 3.0, 3.0, 3.0 };

  //пример какого-то теста
  return candle.high == 3.0;
}

void initTests()
{
  tests.push_back(test1);
  tests.push_back(test2);
  tests.push_back(test3);
  tests.push_back(body_contains1);
  tests.push_back(body_contains2);
  tests.push_back(body_contains3);
  tests.push_back(contains1);
  tests.push_back(contains2);
  tests.push_back(contains3);
  tests.push_back(full_size1);
  tests.push_back(full_size2);
  tests.push_back(full_size3);
  tests.push_back(body_size1);
  tests.push_back(body_size2);
  tests.push_back(body_size3);
  tests.push_back(is_green1);
  tests.push_back(is_green2);
  tests.push_back(is_green3);
  tests.push_back(is_red1);
  tests.push_back(is_red2);
  tests.push_back(is_red3);

  //tests.push_back(test4);
  //tests.push_back(test5);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
