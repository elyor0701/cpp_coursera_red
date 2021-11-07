//#include "../test_runner.h"

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

using namespace std;

template <typename T>
class Deque {
private:
	vector<T> back_;
	vector<T> front_;
	
public:
	Deque () {}
	bool Empty () const {
		if (back_.empty() && front_.empty())
			return true;
		return false;
	}
	size_t Size () const {
		return back_.size() + front_.size(); 
	}
	T& operator [] (size_t index) {
		if (index >= front_.size())
			return back_[index - front_.size()];
		return front_[front_.size() - index - 1];
	}
	const T& operator [] (size_t index) const {
		if (index >= front_.size())
			return back_[index - front_.size()];
		return front_[front_.size() - index - 1];
	}
	T& At (size_t index) {
		if (index >= (front_.size() + back_.size()))
			throw out_of_range("");
		if (index >= front_.size())
			return back_[index - front_.size()];
		return front_[front_.size() - index - 1];
	}													// для исключение
	const T& At (size_t index) const {
		if (index >= (front_.size() + back_.size()))
			throw out_of_range("");
		if (index >= front_.size())
			return back_[index - front_.size()];
		return front_[front_.size() - index - 1];
	}
	T& Front () {
		if (front_.empty()) {
			return back_[0];
		}
		return front_.back();
	}
	const T& Front () const {
		if (front_.empty()) {
			return back_[0];
		}
		return front_.back();
	}
	T& Back () {
		if (back_.empty()) {
			return front_[0];
		}
		return back_.back();
	}
	const T& Back () const {
		if (back_.empty()) {
			return front_[0];
		}
		return back_.back();
	}
	void PushFront (const T& elem) {
		front_.push_back(elem);		
	}
	void PushBack (const T& elem) {
		back_.push_back(elem);
	}
};
/*
void TestDeque () {
	{
		Deque<int> d;
		ASSERT_EQUAL(d.Empty(), true);
		ASSERT_EQUAL(d.Size(), 0u);
		d.PushFront(1);
		ASSERT_EQUAL(d.Empty(), false);
		ASSERT_EQUAL(d.Size(), 1u);
		d.PushBack(2);
		ASSERT_EQUAL(d.Empty(), false);
		ASSERT_EQUAL(d.Size(), 2u);
	}
	{
		Deque<int> d;
		d.PushFront(1);
		d.PushFront(3);
		d.PushFront(2);
		d.PushFront(10);
		d.PushBack(4);
		d.PushBack(12);
		d.PushBack(20);
		d.PushBack(16);
		d[0] = 50;
		ASSERT_EQUAL(d[0], 50);
		ASSERT_EQUAL(d[4], 4);
		ASSERT_EQUAL(d[5], 12);
		ASSERT_EQUAL(d[6], 20);
		ASSERT_EQUAL(d.Size(), 8u);
	}
	{
		Deque<int> d;
		d.PushFront(1);
		d.PushFront(3);
		d.PushFront(2);
		d.PushFront(10);
		d.PushBack(4);
		d.PushBack(12);
		d.PushBack(20);
		d.PushBack(16);
		d.At(0) = 50;
		ASSERT_EQUAL(d[0], 50);
		ASSERT_EQUAL(d.At(0), 50);
		try {
			d.At(50) = 80;
			throw exception();
		} catch (out_of_range& o) {}
	}
	{
		Deque<string> d;
		d.PushFront("test1");
		d.PushFront("test2");
		d.PushFront("test3");
		d.PushFront("test4");
		d.PushBack("test5");
		d.PushBack("test6");
		d.PushBack("test7");
		d.PushBack("test8");
		ASSERT_EQUAL(d.Front(), "test4");
		ASSERT_EQUAL(d.Back(), "test8");
	}
	{
		Deque<int> d;
		d.PushBack(4);
		d.PushBack(12);
		d.PushBack(20);
		d.PushBack(16);
		ASSERT_EQUAL(d.Front(), 4);
		ASSERT_EQUAL(d.Back(), 16);
	}
	{
		Deque<string> d;
		d.PushFront("test1");
		d.PushFront("test2");
		d.PushFront("test3");
		d.PushFront("test4");
		ASSERT_EQUAL(d.Back(), "test1");
	}
}

int main () {
	TestRunner tr;
	RUN_TEST(tr, TestDeque);

	return 0;
}
*/
