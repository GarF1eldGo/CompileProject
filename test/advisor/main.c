int myStrcmp(char preCourseName[100], int len1, char takenCourseName[100][100],
             int len2) {
  int flag = 1;
  int i = 0;
  int j = 0;

  for (i = 0; i < len2; i++) {
    flag = 1;

    for (j = 0; j < 5; j++) {
      if (preCourseName[j] == 0 && takenCourseName[i][j] != 0) {
        flag = 0;
      } else if (preCourseName[j] != 0 && takenCourseName[i][j] == 0) {
        flag = 0;
      } else if (takenCourseName[i][j] != preCourseName[j]) {
        flag = 0;
      }
    }

    if (flag > 0) {
      return 1;
    }
  }
  return 0;
}

int boolExpression(char name[100], char token[100], int begin1, int len1,
                   int preCourseTrue[100], int begin2, int len2) {
  int result = preCourseTrue[begin2];
  int i = 0;
  int j = 0;
  int courseIndex = begin2 + 1;
  int flag = 1;
  for (i = begin1; i < len1 && flag == 1; i++) {
    if (token[i] == ',') {
      if (result == 1 && preCourseTrue[courseIndex] == 1) {
        result = 1;
      } else {
        result = 0;
      }
      courseIndex++;
    } else if (token[i] == ';') {
      if (result == 1 || boolExpression(name, token, i + 1, len1, preCourseTrue,
                                        courseIndex, len2) == 1) {
        result = 1;
      }
      flag = 0;
    }
  }

  return result;
}
char preCourse[100][200];

int main() {
  int maxNum = 100;
  int maxInput = 100;
  int nameLen = 5;

  char courseName[100][100];
  int credit[100];

  int score[100];

  int curNum = 0;

  int emptyLine = 0;

  char inputStr[500];

  int tempIndex = 1;
  int newLine = 0;

  int curIndex = 0;
  int index = 0;

  float gpa = 0.0;
  int tryCredit = 0;
  int takenCredit = 0;
  int remainCredit = 0;

  char takenCourseName[100][100];
  int takenIndex = 0;

  int untakenCourseIndex[100];
  int untakenIndex = 0;

  int creditNum = 0;
  float scoreNum = 0.0;

  int j = 0;
  int ii = 0;
  int iii = 0;
  int preCourseTrue[100];
  int trueIndex = 0;

  char token[100];
  int tokenIndex = 0;

  int result = 0;

  char tempName[100];
  int i = 0;
  int k = 0;
  for (i = 0; i < 100; i++) {
    credit[i] = 0;
    score[i] = 0;
    untakenCourseIndex[i] = 0;
    preCourseTrue[i] = 0;
    token[i] = 0;
  }

  for (i = 0; i < 100; i++) {
    for (j = 0; j < 5; j++) {
      courseName[i][j] = 0;
      takenCourseName[i][j] = 0;
    }
  }

  for (i = 0; i < 100; i++) {
    for (j = 0; j < 200; j++) {
      preCourse[i][j] = 0;
    }
  }

  for (i = 0; i < 300; i++) {
    inputStr[i] = 0;
  }

  while (emptyLine == 0) {
    for (i = 0; i < 300; i++) {
      inputStr[i] = 0;
    }

    scanf("%c", inputStr[0]);
    if (inputStr[0] == 10) {
      emptyLine = 1;
    } else {
      tempIndex = 1;
      newLine = 0;
      while (newLine == 0) {
        scanf("%c", inputStr[tempIndex]);
        tempIndex++;
        if (inputStr[tempIndex - 1] == 10) {
          inputStr[tempIndex - 1] = 0;
          newLine = 1;
        }
      }

      curIndex = 0;
      while (inputStr[curIndex] != '|') {
        courseName[curNum][curIndex] = inputStr[curIndex];
        curIndex++;
      }
      curIndex++;

      while (inputStr[curIndex] != '|') {
        credit[curNum] = inputStr[curIndex] - '0';
        curIndex++;
      }
      curIndex++;

      index = 0;
      while (inputStr[curIndex] != '|') {
        preCourse[curNum][index] = inputStr[curIndex];
        curIndex++;
        index++;
      }
      curIndex++;

      if (inputStr[curIndex] != 0) {
        if (inputStr[curIndex] == 'A') {
          score[curNum] = 4;
        } else if (inputStr[curIndex] == 'B') {
          score[curNum] = 3;
        } else if (inputStr[curIndex] == 'C') {
          score[curNum] = 2;
        } else if (inputStr[curIndex] == 'D') {
          score[curNum] = 1;
        } else if (inputStr[curIndex] == 'F') {
          score[curNum] = 0;
        }
      } else {
        score[curNum] = -1;
      }

      curNum++;
    }
  }

  for (i = 0; i < curNum; i++) {
    creditNum = credit[i];
    scoreNum = 0;

    if (score[i] == -1 || score[i] == 0) {
      if (score[i] == 0) {
        tryCredit += credit[i];
      }
      remainCredit += credit[i];
      untakenCourseIndex[untakenIndex] = i;
      untakenIndex++;
    } else {
      scoreNum = score[i];
      tryCredit += credit[i];
      takenCredit += credit[i];

      for (j = 0; courseName[i][j] != 0; j++) {
        takenCourseName[takenIndex][j] = courseName[i][j];
      }
      takenIndex++;
    }

    gpa += scoreNum * creditNum;
  }
  if (tryCredit != 0) {
    gpa /= tryCredit;
  }

  printf("GPA: %0.1f\n", gpa);

  printf("Hours Attempted: %d\n", tryCredit);

  printf("Hours Completed: %d\n", takenCredit);

  printf("Credits Remaining: %d\n\n", remainCredit);

  printf("Possible Courses to Take Next\n");

  if (remainCredit == 0) {
    printf("  None - Congratulations!\n");
    return 0;
  }

  for (i = 0; i < untakenIndex; i++) {
    j = untakenCourseIndex[i];

    if (preCourse[j][0] == 0) {
      printf("%c%c", 32, 32);
      for (k = 0; courseName[j][k] != 0; k++) {
        printf("%c", courseName[j][k]);
      }
      printf("%c", 10);
    } else {
      for (ii = 0; ii < 100; ii++) {
        preCourseTrue[ii] = 0;
        token[ii] = 0;
      }
      trueIndex = 0;
      tokenIndex = 0;

      for (k = 0; preCourse[j][k] != 0; k++) {
        for (iii = 0; iii < 5; iii++) {
          tempName[iii] = 0;
        }
        tempIndex = 0;

        while (preCourse[j][k] != ',' && preCourse[j][k] != ';' &&
               preCourse[j][k] != 0) {
          tempName[tempIndex] = preCourse[j][k];
          tempIndex++;
          k++;
        }
        if (preCourse[j][k] != 0) {
          token[tokenIndex] = preCourse[j][k];
          tokenIndex++;
        }

        if (myStrcmp(tempName, tempIndex, takenCourseName, takenIndex) > 0) {
          preCourseTrue[trueIndex] = 1;
        } else {
          preCourseTrue[trueIndex] = 0;
        }
        trueIndex++;
      }

      result = boolExpression(courseName[j], token, 0, tokenIndex,
                              preCourseTrue, 0, trueIndex);

      if (result > 0) {
        printf("%c%c", 32, 32);
        for (k = 0; courseName[j][k] != 0; k++) {
          printf("%c", courseName[j][k]);
        }
        printf("%c", 10);
      }
    }
  }
  return 0;
}
