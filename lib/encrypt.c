int hash(int x) { return x % 10007; }

int decrypted[10007];

char *__encrypt(char *encStr) {
  decrypted[hash(encStr)] = 0;
  char *curr = encStr;
  while (*curr) {
    *curr ^= 42;
    curr++;
  }
  return encStr;
}

char *__decrypt(char *originStr) {
  if (!decrypted[hash(originStr)]) {
    char *curr = originStr;
    while (*curr) {
      *curr ^= 42;
      curr++;
    }
    decrypted[hash(originStr)] = 1;
    return originStr;
  }
  return originStr;
}
