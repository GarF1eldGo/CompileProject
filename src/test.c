int main() {
  int i = 0;
  int j = 0;
  int n = 5;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (j == 3) {
        break;
      }
      printf("%d %d\n", i, j);
    }
  }
  return 0;
}
