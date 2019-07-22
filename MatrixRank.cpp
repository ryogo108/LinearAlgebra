#include<iostream>
#include"Matrix.h"

int main(int argc,char* argv[]){
  /*int I=atoi(argv[1]),J=atoi(argv[2]);
  Mat<Q> m(I,vector<Q>(J,0));
  for(int i=0;i<I;i++){
    for(int j=0;j<J;j++){
      m[i][j]=Q(argv[i*J+j+3]);
    }
  }*/
  int I,J;
  cin>>I>>J;
  Mat<Q> m(I,vector<Q>(J,0));
  for(int i=0;i<I;i++){
    for(int j=0;j<J;j++){
      double x;
      cin>>x;
      m[i][j]=Q(x);
    }
  }

  cout<<matrixRank(m)<<endl;
  printMatrix(m);
}
