#include"Matrix.h"
#include<iostream>

using namespace std;

//使用する型について明示的にインスタンスを作る必要があるらしい
template void printVector<Q>(const vector<Q>& v);
template void printMatrix<Q>(const Mat<Q>& m);
template int matrixRank<Q>(Mat<Q>& m);
template vector<Q> GaussianElimination(Mat<Q>& m);

template <class T> void printVector(const vector<T>& v){
  for(int i=0;i<v.size();i++){
    if(i)cout<<" ";
    cout<<v[i];
  }
  cout<<endl<<endl;
}


template <class T> void printMatrix(const Mat<T>&  m){
  for(int i=0;i<m.size();i++){
    for(int j=0;j<m[i].size();j++){
      cout<<m[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
template<class T> int matrixRank(Mat<T>& m){
  if(m.empty())return 0;
  int rank=0;
  for(int pivot=0;pivot<m[0].size();pivot++){
    printMatrix(m);
    for(int i=rank;i<m.size();i++){ //search nonzero pivot
      if(m[i][pivot]!=0){
        m[rank].swap(m[i]);
        for(int j=m[rank].size()-1;j>=pivot;j--){ //normalize of pivot row
           m[rank][j]/=m[rank][pivot];
        }
        for(int i=0;i<m.size();i++){ //subtraction of every row with pivot row
          if(i==rank)continue;
          for(int j=m[i].size()-1;j>=pivot;j--){
            m[i][j]-=m[i][pivot]*m[rank][j];
          }
        }
        rank++;
        break;
      }
    }
  }
  return rank;
}

template<class T> vector<T> GaussianElimination(Mat<T>& A){
  int rank=matrixRank(A);
  vector<T> x(A[0].size(),0);
  if(rank==A[0].size())return x;
  int row=0;
  int pick=0;
  for(int j=0;j<A[0].size();j++){
    if(row==rank){
      x[j]=1;
      pick=j;
      break;
    }
    if(A[row][j]!=1){
      x[j]=1;
      pick=j;
      break;
    }
    else row++;
  }
  row=0;
  for(int j=0;j<A[0].size();j++){
    if(A[row][j]==1){
      x[j]=-1*A[row][pick];
      row++;
    }
    if(row==rank)break;
  }
  return x;
}
