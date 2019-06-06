#include<iostream>
#include"Matrix.h"

using namespace std;

template<class T> T generateRandomValue();
template<> Q generateRandomValue(){
  return Q("1/2");
}

template<class T> Mat<T> generateRandomMatrix(int n,int m){
  //return random matrix which has shape of n*m;
  Mat<T> A(n,vector<T>(m,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      A[i][j]=generateRandomValue<T>();
    }
  }
  return A;
}

int main(int argc,char *argv[]){
  int n=atoi(argv[1]),m=atoi(argv[2]);
  printMatrix(generateRandomMatrix<Q>(n,m));
}
