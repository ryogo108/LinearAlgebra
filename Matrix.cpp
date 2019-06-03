#include"Matrix.h"
#include<iostream>

using namespace std;

template <class T> void printMatrix(const vector<vector<T> >&  m){
  for(int i=0;i<m.size();i++){
    for(int j=0;j<m[i].size();j++){
      cout<<m[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
int matrixRank(Mat& m){
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
