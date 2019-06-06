#include<iostream>
#include"Matrix.h"

using namespace std;

template<class T> T generateRandomValue(unsigned long seed);
template<> Q generateRandomValue(unsigned long seed){
  gmp_randclass r1(gmp_randinit_mt);
  r1.seed(seed);
  return Q(r1.get_z_bits(Z(10)));

}

template<class T> Mat<T> generateRandomMatrix(int n,int m){
  //return random matrix which has shape of n*m;
  Mat<T> A(n,vector<T>(m,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      A[i][j]=generateRandomValue<T>(i*j+i+j);
    }
  }
  return A;
}

int main(int argc,char *argv[]){
  int n=atoi(argv[1]),m=atoi(argv[2]);
  printMatrixInRow(generateRandomMatrix<Q>(n,m));
}
