int main() {
  int A[25][25];
  int B[25][25];
  int C[25][25];
  int i = 0;
  int j = 0;
  int k = 0;
  int Ma = 0;
  int Na = 0;
  int Mb = 0;
  int Nb = 0;
  scanf("%d %d", Ma, Na);
  for (i = 0; i < Ma; i++) {
    for (j = 0; j < Na; j++) {
      scanf("%6d", A[i][j]);
    }
  }

  scanf("%d %d", Mb, Nb);
  for (i = 0; i < Mb; i++) {
    for (j = 0; j < Nb; j++) {
      scanf("%6d", B[i][j]);
    }
  }

  //无法计算
  if (Na != Mb) {
    printf("Incompatible Dimensions\n");
    return 0;
  }

  //进行矩阵计算
  for (i = 0; i < Ma; i++) {
    for (j = 0; j < Nb; j++) {
      C[i][j] = 0;
      for (k = 0; k < Na; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  //打印结果，每个输出结果占10个字符
  for (i = 0; i < Ma; i++) {
    for (j = 0; j < Nb; j++) {
      printf("%10d", C[i][j]);
    }
    printf("\n");
  }
  return 0;
}