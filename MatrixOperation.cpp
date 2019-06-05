#include"Matrix.h"
#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;



int main(int argc,char* argv[]){
  int I=atoi(argv[1]),J=atoi(argv[2]);
  Mat<Q> A(I,vector<Q>(J,0));
  for(int i=0;i<I;i++){
    for(int j=0;j<J;j++){
      A[i][j]=Q(argv[i*J+j+3]);
    }
  }
  printMatrix(A);
  Q a=Q("3/2");
  printVector(A[0]);
  printVector(A[0]+A[1]);
  printVector(A[0]-A[1]);
  printVector(-A[0]);
  printVector(Q(3)*A[0]);
  printMatrix(Q(3)*A);
  printMatrix(A+A);
  printMatrix(A-(Q("1/2")*A));
  printMatrix(A/Q(2));
  printMatrix(-A);
  printMatrix(A*A);
  printVector(A*A[0]);
}
