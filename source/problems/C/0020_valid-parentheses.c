#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static inline int isLeft(char c) { return (c == '(') || (c == '[') || (c == '{'); }

static inline int isPair(char l, char r) {
  return ((l == '(') && (r == ')')) || ((l == '[') && (r == ']')) ||
      ((l == '{') && (r == '}'));
}

int isValid(char * s) {
  int len = strlen(s);
  char *stack = (char *)malloc(len);
  int n = 0;
  int ans = true;
  for (int i = 0; i < len; i++) {
    char c = s[i];
    if (isLeft(c)) {
      stack[n++] = c;
    } else {
      if (n == 0 || !isPair(stack[--n], c)) {
        ans = false;
        break;
      }
    }
  }
  free(stack);
  return n == 0 && ans;
}

/*
  Status: Accepted (92/92)
  Runtime: 0 ms, faster than 100.00% of C submissions.
  Memory Usage: 5.8 MB, less than 17.58% of C submissions.
 */
