#include <iostream>
#include <unordered_map>

using namespace std;

// Map to store the numeric value of each month depending on
// its occurrence i.e. Jan = 1, Feb = 2 and so on.
unordered_map<string, int> monthsMap{
    {"Dec", 12}, {"May", 5}, {"Sep", 9}, {"Jan", 1},  {"Apr", 4}, {"Aug", 8},
    {"Feb", 2},  {"Jun", 6}, {"Jul", 7}, {"Oct", 10}, {"Mar", 3}, {"Nov", 11}};

// Comparator function to sort an array of dates
bool comp(const string& a, const string& b) {
  // Comparing the years
  string str1 = a.substr(7, 5);
  string str2 = b.substr(7, 5);
  if (str1.compare(str2) != 0) {
    if (str1.compare(str2) < 0) return true;
    return false;
  }

  // Comparing the months
  string month_sub_a = a.substr(3, 3);
  string month_sub_b = b.substr(3, 3);

  // Taking numeric value of months from monthsMap
  int month_a = monthsMap[month_sub_a];
  int month_b = monthsMap[month_sub_b];
  if (month_a != month_b) {
    return month_a < month_b;
  }

  // Comparing the days
  string day_a = a.substr(0, 2);
  string day_b = b.substr(0, 2);
  if (day_a.compare(day_b) < 0) return true;
  return false;
}

// Utility function to print the contents
// of the array
void printDates(string dates[], int n) {
  for (int i = 0; i < n; i++) {
    cout << dates[i] << endl;
  }
}

// Date representation example:
// 11 Jun 1996
// 01 Jan 1997
// 12 Aug 2005
// 24 Jul 2017
// 25 Jul 2017
// 01 Jan 2019

int main() {

  //sort(vec.begin(), vec.end(), comp);

  return 0;
}
