/*
* Студента попросили написать класс Learner, помогающий изучать иностранный язык. В публичном интерфейсе класса должны быть две функции:  
* Функция Learn должна получать порцию слов, "запоминать" их и возвращать количество различных новых слов. Функция KnownWords должна возвращать отсортированный по алфавиту список всех выученных слов. В списке не должно быть повторов.

* Студент написал следующее решение этой задачи, однако оно почему-то работает очень медленно. Вам надо его ускорить.

* Вам дан файл learner.cpp с медленным решением задачи. Не меняя публичный интерфейс класса Learner, найдите в нём узкие места, исправьте их и сдайте переделанный класс в тестирующую систему.

*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include "../profile.h"

using namespace std;

class Learner {
 private:
	set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    int newWords = 0;
    for (const auto& word : words) {
		if (dict.count(word) == 0) {
			++newWords;
			dict.insert(word);
		}
    }
    return newWords;
  }

	vector<string> KnownWords() {
		return {dict.begin(), dict.end()};
	}
};

int main() {
  Learner learner;
  string line;
  LOG_DURATION("total");
  while (getline(cin, line)) {
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
      words.push_back(word);
    }
    learner.Learn(words);
  }
  cout << "=== known words ===\n";
  for (auto word : learner.KnownWords()) {
    cout << word << "\n";
  }
  return 0;
}
