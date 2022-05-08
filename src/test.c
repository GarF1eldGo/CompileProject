//#include<stdio.h>
//#define max 100000

int max = 100000;

void quickSort(int numArray[],int left,int right);

int main(){
    int num = 0;
    //scanf("%d",&num);

    //读取数据
    int numArray[max];

    for(int i=0;i<num;i++){
        //scanf("%d",&numArray[i]);
    }

    //快速排序
    quickSort(numArray,0,num-1);
    
    //输出数据
    for(int i=0;i<num;i++){
        //printf("%d\n",numArray[i]);
    }
}



void quickSort(int numArray[],int left,int right){
    int i,j,temp,key;
    if(left>=right)
        return;
    key = numArray[left];
    i = left;
    j = right;
    while(i<j){
        while(i<j && numArray[j]>=key)
            j--;
        numArray[i] = numArray[j];
        while(i<j && numArray[i]<=key)
            i++;
        numArray[j] = numArray[i];
    }
    numArray[i] = key;
    quickSort(numArray,left,i-1);
    quickSort(numArray,i+1,right);
}