#include"Matrix.cpp"
#include<iostream>

#include<gmpxx.h>
using namespace std;

using Q=mpq_class;
using Z=mpz_class;

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
  Mat<Q> A(I,vector<Q>(J,0));
  for(int i=0;i<I;i++){
    for(int j=0;j<J;j++){
      double x;
      cin>>x;
      A[i][j]=Q(x);
    }
  }
  cout<<endl<<"A ="<<endl;
  printMatrix(A);
  vector<vector<Q> > KerA=GaussianElimination(A);
  cout<<"Basis of KerA = "<<endl;
  printMatrix(KerA);
}
