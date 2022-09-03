#include <string>

class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    for (string::iterator it = s.begin(); it != s.end(); it++) {
      if (*it == '(' || *it == '[' || *it == '{') {
        stk.push(*it);
      } else {
        if (stk.empty() || stk.top() != getPair(*it)) {
          return false;
        }
        stk.pop();
      }
    }
    return stk.empty();
  }

private:
  inline char getPair(char c) {
    switch (c) {
    case ')':
      return '(';
    case ']':
      return '[';
    case '}':
      return '{';
    }
    return 0;
  }
};
