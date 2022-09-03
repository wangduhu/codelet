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

/*
  Status: Accepted (92/92)
  Runtime: 2 ms, faster than 53.35% of C++ submissions.
  Memory Usage: 6.4 MB, less than 50.82% of C++ submissions.
 */
