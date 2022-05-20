char s[10];

int main() {
  int i = 0;
  scanf("%s", s);
  for (i = 0; i < 5; ++i) {
    if (s[i] == 'c') {
      s[i] = 'a';
    }
  }
  printf("%s", s);
  return 0;
}
