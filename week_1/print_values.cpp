#include "../test_runner.h"

#include <ostream>
#include <string>
using namespace std;

#define PRINT_VALUES(out, x, y) 					\
			out << (x) << endl << (y) << endl		

void TestPrint () {
	{
		ostringstream output;
		PRINT_VALUES(output, 5, "red belt");
		ASSERT_EQUAL(output.str(), "5\nred belt\n");
		PRINT_VALUES(output, 5 + 6, "test");
		ASSERT_EQUAL(output.str(), "5\nred belt\n11\ntest\n");
	}
	{
		ostringstream out;
		for (int i = 0; i < 3; ++i)
			PRINT_VALUES(out, "a", "b");
		ASSERT_EQUAL(out.str(), "a\nb\na\nb\na\nb\n");
	}
	{
		ostringstream out;
		if(true)
			PRINT_VALUES(out, "a", "b");
		else
			out << "zero";
		ASSERT_EQUAL(out.str(), "a\nb\n");
	}
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestPrint);
  return 0;
}
