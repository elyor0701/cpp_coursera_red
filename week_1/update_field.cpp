#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;

bool operator== (const Date& lth, const Date& rth) {
	return vector<int>{lth.year, lth.month, lth.day} ==
		vector<int>{rth.year, rth.month, rth.day};
}

bool operator== (const Time& lth, const Time& rth) {
	return vector<int>{lth.hours, lth.minutes} ==
		vector<int>{rth.hours, rth.minutes};
}

istream& operator>>(istream& is, Date& d) {
	is >> d.year;
	is.get();
	is >> d.month;
	is.get();
	is >> d.day;
	return is;
}

istream& operator>>(istream& is, Time& t) {
	is >> t.hours;
	is.get();
	is >> t.minutes;
	return is;
}

ostream& operator<< (ostream& os, const Date& d) {
	os << d.year << "/" << d.month << "/" << d.day;
	return os;
}

ostream& operator<< (ostream& os, const Time& t) {
	os << t.hours << ":" << t.minutes;
	return os;
}
/*
#define UPDATE_FIELD(ticket, field, values)  				\
		it = values.find(#field);							\
		if (it != values.end()) {							\
			istringstream is(it->second);					\
			is >> ticket.field;								\
		}													\
*/

#define UPDATE_FIELD(ticket, field, values)					\
		if (values.count(#field) == 1) {					\
			istringstream is(values.at(#field));			\
			is >> ticket.field;								\
		}													\
		
void TestUpdate() {
  AirlineTicket t;
  t.price = 0;
  map<string, string>::const_iterator it;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
  return 0;
}
