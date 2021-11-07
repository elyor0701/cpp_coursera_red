/*
* В данной задаче необходимо оптимизировать код, использующийся для сортировки студентов по рейтингу. Данные каждого студента находятся в структуре Student, объявленной в файле student.h. Рейтинг студента записан в поле rating:
* Для сортировки студентов по рейтингу используется функция сравнения, возвращающая true, если рейтинг студента first выше рейтинга студента second. 
* Было выявлено, что эта функция является узким местом процесса сортировки, и именно её нужно оптимизировать.
*/

#include "student.h"
#include "../test_runner.h"
#include "../profile.h"

#include <algorithm>

using namespace std;

//Оптимизируйте эту функцию
bool Compare(const Student& first, const Student& second) {
//	LOG_DURATION("compare");
 	return first.Less(second);
}

void TestSpeed () {
	vector<Student> students;
	{
		LOG_DURATION("push elements");
		for (int i = 0; i < 1000000; i++) {
			students.push_back(
				{"first_" + to_string(i), "second_" + to_string(i),
				{{"math_" + to_string(i), (double)i}}, (double)i}
			);
		}		
	}
	{
		LOG_DURATION("function sort");
		sort(begin(students), end(students), Compare);
	}
}

void TestComparison() {
  Student newbie {
    "Ivan", "Ivanov", {
      {"c++", 1.0},
      {"algorithms", 3.0}
    },
    2.0
  };

  Student cpp_expert {
    "Petr", "Petrov", {
      {"c++", 9.5},
      {"algorithms", 6.0}
    },
    7.75
  };

  Student guru {
    "Sidor", "Sidorov", {
      {"c++", 10.0},
      {"algorithms", 10.0}
    },
    10.0
  };
  ASSERT(Compare(guru, newbie));
  ASSERT(Compare(guru, cpp_expert));
  ASSERT(!Compare(newbie, cpp_expert));
}

void TestSorting() {
  vector<Student> students {
    {"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
    {"Semen", "Semenov", {{"maths", 4.}}, 4.},
    {"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
    {"Petr", "Petrov", {{"maths", 3.}}, 3.},
    {"Alexander", "Alexandrov", {{"maths", 1.}}, 1.}
  };
  sort(students.begin(), students.end(), Compare);
  ASSERT(is_sorted(students.begin(), students.end(),
    [](Student first, Student second) {
      return first.Less(second);
    })
  );
}

int main() {
	LOG_DURATION("total");
 	TestRunner tr;
//	RUN_TEST(tr, TestComparison);
//	RUN_TEST(tr, TestSorting);
	RUN_TEST(tr, TestSpeed);
	return 0;
}
