I=5
J=5
testSubject=GaussianElimination.out
rank.out: Matrix.cpp MatrixRank.cpp
	c++ -o rank.out MatrixRank.cpp -lgmp -lgmpxx -std=c++11 -stdlib=libc++ -Wall
GaussianElimination.out: Matrix.cpp GaussianElimination.cpp
	c++ -o GaussianElimination.out GaussianElimination.cpp -lgmp -lgmpxx -std=c++11 -stdlib=libc++
MatrixOperation.out: Matrix.cpp MatrixOperation.cpp
	c++ -o MatrixOperation.out MatrixOperation.cpp -lgmp -lgmpxx -std=c++11 -stdlib=libc++
GenerateRandomMatrix.out: Matrix.cpp GenerateRandomMatrix.cpp
	c++ -o GenerateRandomMatrix.out  GenerateRandomMatrix.cpp -lgmp -lgmpxx -std=c++11 -stdlib=libc++

testRandomMatrix: GenerateRandomMatrix.out ${testSubject}
	./GenerateRandomMatrix.out ${I} ${J} | ./${testSubject}
