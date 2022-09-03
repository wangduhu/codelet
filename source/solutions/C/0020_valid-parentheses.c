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
