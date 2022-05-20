int main(){
  int A[25][25];
  int B[25][25];
  int C[25][25];

    
  int Ma,Na;
  int Mb,Nb;
  int i,j,k;


  scanf("%d %d",&Ma,&Na);
  for(i=0;i<Ma;i++){
    for(j=0;j<Na;j++){
      scanf("%d",A[i][j]);
    }
  }
  
    scanf("%d %d",&Mb,&Nb);
  for(i=0;i<Mb;i++){
    for(j=0;j<Nb;j++){
      scanf("%d",&B[i][j]);
    }
  }



  if(Na != Mb){
    printf("Incompatible Dimensions\n");
    return 0;
  }
  
  for(i=0;i<Ma;i++){
    for(j=0;j<Nb;j++){
      C[i][j] = 0;
      for(k=0;k<Na;k++){
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  for (i = 0; i < Ma; ++i) {
    for (j = 0; j < Nb; ++j) {
      printf("%d\n", C[i][j]);
      


    }
    
  }
  i = 1;
  return 0;
}
