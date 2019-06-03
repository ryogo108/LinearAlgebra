#include<vector>
#include<gmpxx.h>
using namespace std;

typedef mpq_class Q;
typedef mpz_class Z;
typedef vector<vector<Q> > Mat;

template <class T> void printMatrix(const vector<vector<T> >&  m);

int matrixRank(Mat& m);
