char s[10];

int main() {
  int i = 0;
  scanf("%s", s);
  for (i = 0; i < 5; ++i) {
    if (s[i] == 'c') {
      s[i] = 'a';
    }
  }
  for (i = 0; i < 10; ++i) {
    if (s[i] == 0) {
      
    }
    else{
      printf("%c", s[i]);
    }
  }
  printf("\n");
  return 0;
}
