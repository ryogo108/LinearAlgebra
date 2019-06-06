#include"Matrix.h"
#include<iostream>

using namespace std;

//使用する型について明示的にインスタンスを作る必要があるらしい
template void printVector<Q>(const vector<Q>& v);
template void printMatrix<Q>(const Mat<Q>& m);
template int matrixRank<Q>(Mat<Q>& m);
template vector<Q> GaussianElimination(Mat<Q>& m);

template vector<Q> operator+(const vector<Q>& vl,const vector<Q>& vr);
template vector<Q> operator-(const vector<Q>& vl,const vector<Q>& vr);
template vector<Q> operator*(const vector<Q>& vl,const Q& r);
template vector<Q> operator*(const Q& l,const vector<Q>& vr);
template vector<Q> operator-(const vector<Q>& v);

template vector<Q> operator*(const Mat<Q>& ml,const vector<Q>& vr);
template Mat<Q> operator+(const Mat<Q>& ml,const Mat<Q>& mr);
template Mat<Q> operator-(const Mat<Q>& ml,const Mat<Q>& mr);
template Mat<Q> operator*(const Mat<Q>& ml,const Mat<Q>& mr);
template Mat<Q> operator*(const Q& l,const Mat<Q>& mr);
template Mat<Q> operator*(const Mat<Q>& ml,const Q& r);
template Mat<Q> operator/(const Mat<Q>& ml,const Q& r);
template Mat<Q> operator-(const Mat<Q>& m);

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


template<class T> vector<T> operator+(const vector<T>& vl,const vector<T>& vr){
  if(vl.size()!=vr.size())throw invalid_argument("a vector cannot add to a vector which has different size");
  vector<T> v(vl);
  for(int i=0;i<v.size();i++)v[i]=v[i]+vr[i];
  return v;
}
template <class T> vector<T> operator-(const vector<T>& vl,const vector<T>& vr){
  if(vl.size()!=vr.size())throw invalid_argument("a vector cannot  subtract with a vector which has different size");
  vector<T> v(vl);
  for(int i=0;i<v.size();i++)v[i]=v[i]-vr[i];
  return v;
}
template <class T> vector<T> operator*(const vector<T>& vl,const T& r){
  vector<T> v(vl);
  for(int i=0;i<v.size();i++)v[i]=v[i]*r;
  return v;
}
template <class T> vector<T> operator*(const T& l,const vector<T>& vr){
  vector<T> v(vr);
  for(int i=0;i<v.size();i++)v[i]=v[i]*l;
  return v;

}
template <class T> vector<T> operator-(const vector<T>& v){
  vector<T> rev(v);
  for(int i=0;i<rev.size();i++)rev[i]=-v[i];
  return rev;

}
template <class T> vector<T> operator*(const Mat<T>& ml,const vector<T>& vr){ 
  if(ml.empty())throw invalid_argument("empty matrix cannot time to a vector");
  if(ml[0].size()!=vr.size())throw invalid_argument("a matrix cannot time  to a vector which has different size");
  vector<T> v(ml.size(),0);
  for(int i=0;i<v.size();i++){
    T sum=0;
    for(int j=0;j<ml[i].size();j++)sum+=ml[i][j]*vr[j];
    v[i]=sum;
  }
  return v;
}
template <class T> Mat<T> operator+(const Mat<T>& ml,const Mat<T>& mr){
  if(ml.empty() || mr.empty())throw invalid_argument("empty matrix cannto add to a matrix");
  if(ml.size()!=mr.size() || ml[0].size()!=mr[0].size())throw invalid_argument("a matrix cannot add to a matrix which has different shape");
  Mat<T> m(ml.size(),vector<T>(ml[0].size(),0));
  for(int i=0;i<m.size();i++){
    for(int j=0;j<m[i].size();j++){
      m[i][j]=ml[i][j]+mr[i][j];
    }
  }
  return m;
}
template <class T> Mat<T> operator-(const Mat<T>& ml,const Mat<T>& mr){
  if(ml.empty() || mr.empty())throw invalid_argument("empty matrix cannot subtract with a matrix");
  if(ml.size()!=mr.size() || ml[0].size()!=mr[0].size())throw invalid_argument("a matrix cannot subtract with a matrix which has different shape");
  Mat<T> m(ml.size(),vector<T>(ml[0].size(),0));
  for(int i=0;i<m.size();i++){
    for(int j=0;j<m[i].size();j++){
      m[i][j]=ml[i][j]-mr[i][j];
    }
  }
  return m;
  
}
template <class T> Mat<T> operator*(const Mat<T>& ml,const Mat<T>& mr){
  if(ml.empty() || mr.empty())throw invalid_argument("empty matrix cannot time to a matrix");
  if(ml[0].size()!=mr.size())throw invalid_argument("a matrix cannot time to a matrix which has invalid shape");
  Mat<T> m(ml.size(),vector<T>(mr[0].size(),0));
  for(int i=0;i<m.size();i++){
    for(int j=0;j<m[i].size();j++){
      for(int k=0;k<ml[0].size();k++){
        m[i][j]+=ml[i][k]*mr[k][j];
      }
    }
  }
  return m;

}
template <class T> Mat<T> operator*(const T& l,const Mat<T>& mr){
  Mat<T> m(mr.size(),vector<T>(mr[0].size(),0));
  for(int i=0;i<m.size();i++){
    for(int j=0;j<m[i].size();j++){
      m[i][j]=mr[i][j]*l;
    }
  }
  return m;

};
template <class T> Mat<T> operator*(const Mat<T>& ml,const T& r){
  Mat<T> m(ml.size(),vector<T>(ml[0].size(),0));
  for(int i=0;i<m.size();i++){
    for(int j=0;j<m[i].size();j++){
      m[i][j]=ml[i][j]*r;
    }
  }
  return m;

}
template <class T> Mat<T> operator/(const Mat<T>& ml,const T& r){
  Mat<T> m(ml.size(),vector<T>(ml[0].size(),0));
  for(int i=0;i<m.size();i++){
    for(int j=0;j<m[i].size();j++){
      m[i][j]=ml[i][j]/r;
    }
  }
  return m;

}
template <class T> Mat<T> operator-(const Mat<T>& m){
  Mat<T> rem(m.size(),vector<T>(m[0].size(),0));
  for(int i=0;i<rem.size();i++){
    for(int j=0;j<rem[i].size();j++){
      rem[i][j]=-m[i][j];
    }
  }
  return rem;
}
