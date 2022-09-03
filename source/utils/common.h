#ifndef _MYUTILS_COMMON_H_
#define _MYUTILS_COMMON_H_

#include <iostream>
#include <vector>

#include <cmath>

using namespace std;

inline bool equal(double a, double b) {
  return fabs(a-b) < 1e-7;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T>& v) {
  out << '{' << ' ';
  for (auto it = v.cbegin(); it != v.cend(); ++it) {
    out << *it << ' ';
  }
  out << '}';
  return out;
}

template<typename T>
ostream& operator<<(ostream& out, vector<vector<T>> m) {
  out << '{' << endl;
  for (auto& row : m) {
    out << row << endl;
  }
  out << '}' << endl;
  return out;
}

template<typename T>
void print_vector(vector<T> v) {
  for (typename vector<T>::const_iterator it = v.cbegin(); it != v.cend(); it++) {
    cout << *it << ' ';
  }
  cout << endl;
}

template<typename T>
bool operator==(const vector<T>& v1, const vector<T>& v2) {
  if (v1.size() != v2.size()) {
    return false;
  }
  for (size_t i = 0; i < v1.size(); i++) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

template<typename T>
bool operator==(const vector<vector<T>>& m1, const vector<vector<T>>& m2) {
  if (m1.size() != m2.size()) {
    return false;
  }

  for (size_t i = 0; i < m1.size(); i++) {
    if (!(m1[i] == m2[i])) {
      return false;
    }
  }
  return true;
}

#endif
