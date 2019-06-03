#include<iostream>
#include"Matrix.h"

int main(int argc,char* argv[]){
  int I=atoi(argv[1]),J=atoi(argv[2]);
  Mat<Q> m(I,vector<Q>(J,0));
  for(int i=0;i<I;i++){
    for(int j=0;j<J;j++){
      m[i][j]=Q(argv[i*J+j+3]);
    }
  }
  cout<<matrixRank(m)<<endl;
  printMatrix(m);
}
