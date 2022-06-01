void quickSort(int numArray[100000], int left, int right) {
  int i = 0;
  int j = 0;
  int temp = 0;
  int key = 0;

  if (left >= right) return;
  key = numArray[left];
  i = left;
  j = right;
  while (i < j) {
    while (i < j && numArray[j] >= key) j--;
    numArray[i] = numArray[j];
    while (i < j && numArray[i] <= key) i++;
    numArray[j] = numArray[i];
  }
  numArray[i] = key;
  quickSort(numArray, left, i - 1);
  quickSort(numArray, i + 1, right);
  return;
}

int main() {
  int num = 0;
  int i = 0;
  int numArray[100000];
  scanf("%d", num);

  //读取数据
  for (i = 0; i < num; i++) {
    scanf("%d", numArray[i]);
  }

  //快速排序
  quickSort(numArray, 0, num - 1);

  //输出数据
  for (i = 0; i < num; i++) {
    printf("%d\n", numArray[i]);
  }
  return 0;
}
