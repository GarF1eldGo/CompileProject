#include<stdio.h>

#define max 25

int main(){
    int A[max][max];
    int B[max][max];

    int Ma,Na;
    scanf("%d %d",&Ma,&Na);
    for(int i=0;i<Ma;i++){
        for(int j=0;j<Na;j++){
            scanf("%6d",&A[i][j]);
        }
    }

    int Mb,Nb;
    scanf("%d %d",&Mb,&Nb);
    for(int i=0;i<Mb;i++){
        for(int j=0;j<Nb;j++){
            scanf("%6d",&B[i][j]);
        }
    }

    //无法计算
    if(Na != Mb){
        printf("Incompatible Dimensions\n");
        return 0;
    }

    //进行矩阵计算
    int C[Ma][Nb];
    for(int i=0;i<Ma;i++){
        for(int j=0;j<Nb;j++){
            C[i][j] = 0;
            for(int k=0;k<Na;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    //打印结果，每个输出结果占10个字符
    for(int i=0;i<Ma;i++){
        for(int j=0;j<Nb;j++){
            printf("%10d",C[i][j]);
        }
        printf("\n");
    }
}