#include<stdio.h>

// 字符串查找+比较
int myStrcmp(char preCourseName[],int len1,char takenCourseName[][5],int len2){
    
    //遍历所有已经修读的课程名称
    for(int i=0;i<len2;i++){
        int flag = 1;
        //判断是否匹配
        for(int j=0;j<5;j++){
            if(preCourseName[j] == '\0' && takenCourseName[i][j] != '\0'){//长度不匹配
                flag = 0;
                break;
            }
            else if(preCourseName[j] != '\0' && takenCourseName[i][j] == '\0'){//长度不匹配
                flag = 0;
                break;
            }
            else if(takenCourseName[i][j] != preCourseName[j]){//字符不匹配
                flag = 0;
                break;
            }
        }
        if(flag){
            return 1;
        }
    }
    return 0;
}


//实现bool表达式
int boolExpression(char token[],int begin1,int len1,int preCourseTrue[],int begin2,int len2){
    // if(name[1] == '2' && name[2] == '3' && begin1 == 0){
    //    printf("name : %s\n",name);
    //     for(int i=0;i<len1;i++){
    //         printf("%d",preCourseTrue[i]);
    //         printf("%c",token[i]);
    //     }
    //     printf("%d",preCourseTrue[len2-1]);
    //     printf("\n");
    // }  

    int result = preCourseTrue[begin2];

    int courseIndex = begin2+1;
    for(int i=begin1;i<len1;i++){
        if(token[i] == ','){//and 操作
            result = result && preCourseTrue[courseIndex];
            courseIndex++;
        }
        else if(token[i] == ';'){//or 操作
            result = result || boolExpression(token,i+1,len1,preCourseTrue,courseIndex,len2);
            break;
        }
    }


    return result;
}


int main(){
    int maxNum = 100;
    int maxInput = 100;
    int nameLen = 5;

    //用于存储输入的信息
    char courseName[100][5] = {'\0'};
    int credit[100] = {'\0'};
    char preCourse[100][200] = {'\0'};
    int score[100] = {0};
    
    int curNum = 0; //记录培养方案中的课程数目

    //读取输入
    while(1){
        char inputStr[300] = {'\0'};
        scanf("%c",&inputStr[0]);
        if(inputStr[0] == '\n'){ //读取到空行则退出
            break;
        }
        int tempIndex = 1;
        while(1){
            scanf("%c",&inputStr[tempIndex]);
            tempIndex++;
            if(inputStr[tempIndex-1] == '\n'){
                inputStr[tempIndex-1] = '\0';
                break;
            }
        }

        //解析课程名称
        int curIndex = 0;
        while(inputStr[curIndex] != '|'){
            courseName[curNum][curIndex] = inputStr[curIndex];
            curIndex++;
        }
        curIndex++;//跳过'|'

        //解析学分, 0<credit<5
        while(inputStr[curIndex] != '|'){
            credit[curNum] = inputStr[curIndex] - '0';//转换为整数类型
            curIndex++;
        }
        curIndex++;//跳过'|'
        
        //解析先修课程，可能没有先修课程
        int i = 0;
        while(inputStr[curIndex] != '|'){
            preCourse[curNum][i] = inputStr[curIndex];
            curIndex++;
            i++;
        }
        curIndex++;//跳过'|'

        //解析成绩，可能没有成绩
        if(inputStr[curIndex] != '\0'){
            if(inputStr[curIndex] == 'A'){
                score[curNum] = 4;
            }
            else if(inputStr[curIndex] == 'B'){
                score[curNum] = 3;
            }
            else if(inputStr[curIndex] == 'C'){
                score[curNum] = 2;
            }
            else if(inputStr[curIndex] == 'D'){
                score[curNum] = 1;
            }
            else if(inputStr[curIndex] == 'F'){
                score[curNum] = 0;
            }
        }
        else{
            score[curNum] = -1;
        }

        curNum++;//更新课程数目
    }

    //计算GPA与相关学分
    double gpa = 0;
    int tryCredit = 0;//尝试学分
    int takenCredit = 0;//已获学分
    int remainCredit = 0;//剩余学分

    char takenCourseName[100][5] = {'\0'};//记录已获得学分的课程名称
    int takenIndex = 0;//记录已获得学分的课程个数

    int untakenCourseIndex[100] = {'\0'};//记录没有获得学分的课程下标
    int untakenIndex = 0;//记录没有获得学分的课程个数

    //统计每门课的情况
    for(int i=0;i<curNum;i++){
        
        int creditNum = credit[i];//学分
        double scoreNum = 0;


        if(score[i] == -1 || score[i] == 0){//没有成绩或者不及格
            if(score[i] == 0){
                tryCredit += credit[i];
            }
            remainCredit += credit[i];
            untakenCourseIndex[untakenIndex] = i;
            untakenIndex++;
        }
        else{//获得了成绩
            scoreNum = score[i];
            tryCredit += credit[i];
            takenCredit += credit[i];

            for(int j=0;courseName[i][j] != '\0';j++){
                takenCourseName[takenIndex][j] = courseName[i][j];
            }
            takenIndex++;
        }

        gpa += scoreNum * creditNum;
    }
    if(tryCredit != 0){
        gpa /= tryCredit;
    }


    //输出gpa
    printf("GPA: %0.1f\n",gpa);

    //输出尝试学分
    printf("Hours Attempted: %d\n",tryCredit);

    //输出已修学分
    printf("Hours Completed: %d\n",takenCredit);

    //输出剩余学分
    printf("Credits Remaining: %d\n\n",remainCredit);

    //输出推荐课程
    printf("Possible Courses to Take Next\n");

    if(remainCredit == 0.0){
        printf("  None - Congratulations!\n");
        return 0;
    }

    //统计可以修读的课程
    for(int i=0;i<untakenIndex;i++){
        //判断先修条件是否满足
        int j = untakenCourseIndex[i];
        
        if(preCourse[j][0] == '\0'){//没有先修课程
            printf("  %s\n",courseName[j]);
        }
        else{
            //首先获得所有先修课程的true/false情况
            int preCourseTrue[maxNum];
            int trueIndex = 0;
            
            char token[maxNum];
            int tokenIndex = 0;

            for(int k=0;preCourse[j][k] != '\0';k++){
                char tempName[nameLen];
                int tempIndex = 0;
                while(preCourse[j][k] != ',' && preCourse[j][k] != ';' && preCourse[j][k] != '\0'){//是一个课程名称
                    tempName[tempIndex] = preCourse[j][k];
                    tempIndex++;
                    k++;
                }
                if(preCourse[j][k] != '\0'){//此时是标点符号
                    token[tokenIndex] = preCourse[j][k];
                    tokenIndex++;
                }

                //在已经修读的课程中查找
                if(myStrcmp(tempName,tempIndex,takenCourseName,takenIndex)){
                    preCourseTrue[trueIndex] = 1;
                }
                else{
                    preCourseTrue[trueIndex] = 0;
                }
                trueIndex++;
            }

            //获得bool表达式的值
            int result = boolExpression(token,0,tokenIndex,preCourseTrue,0,trueIndex);
            
            if(result){
                printf("  %s\n",courseName[j]);
            }

        }
    }
}