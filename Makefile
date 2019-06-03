rank: Matrix.cpp MatrixRank.cpp
	c++ -o rank.out Matrix.cpp MatrixRank.cpp -lgmp -lgmpxx -std=c++11 -stdlib=libc++ -Wall
GaussianElimination: Matrix.cpp GaussianElimination.cpp
	c++ -o GaussianElimination.out Matrix.cpp GaussianElimination.cpp -lgmp -lgmpxx -std=c++11 -stdlib=libc++
