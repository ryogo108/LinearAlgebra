#include<vector>
#include<gmpxx.h>
using namespace std;

using Q=mpq_class;
using Z=mpz_class;
template<class T> using Mat=vector<vector<T> >;

template <class T> void printVector(const vector<T>& v);
template <class T> void printMatrix(const Mat<T>&  m);
template <class T> void printMatrixInRow(const Mat<T>&  m);

template<class T> int matrixRank(Mat<T>& m);

//solve Ax=b
template<class T> vector<vector<T> > GaussianElimination(Mat<T>& A);


template <class T> vector<T> operator+(const vector<T>& vl,const vector<T>& vr);
template <class T> vector<T> operator-(const vector<T>& vl,const vector<T>& vr);
template <class T> vector<T> operator*(const vector<T>& vl,const T& r);
template <class T> vector<T> operator*(const T& l,const vector<T>& vr);
template <class T> vector<T> operator-(const vector<T>& v);

template <class T> vector<T> operator*(const Mat<T>& ml,const vector<T>& vr);
template <class T> Mat<T> operator+(const Mat<T>& ml,const Mat<T>& mr);
template <class T> Mat<T> operator-(const Mat<T>& ml,const Mat<T>& mr);
template <class T> Mat<T> operator*(const Mat<T>& ml,const Mat<T>& mr);
template <class T> Mat<T> operator*(const T& l,const Mat<T>& mr);
template <class T> Mat<T> operator*(const Mat<T>& ml,const T& r);
template <class T> Mat<T> operator/(const Mat<T>& ml,const T& r);
template <class T> Mat<T> operator-(const Mat<T>& m);
