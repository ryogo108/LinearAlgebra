#include"Matrix.h"
#include<iostream>

using namespace std;

int main(int argc,char* argv[]){
  int I=atoi(argv[1]),J=atoi(argv[2]);
  Mat<Q> A(I,vector<Q>(J,0));
  for(int i=0;i<I;i++){
    for(int j=0;j<J;j++){
      A[i][j]=Q(argv[i*J+j+3]);
    }
  }
  cout<<"A ="<<endl;
  printMatrix(A);
  vector<Q> x=GaussianElimination(A);
  cout<<"x = ";
  printVector(x);
  cout<<"Ax = ";
  printVector(A*x);
}
