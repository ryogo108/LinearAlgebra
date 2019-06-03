#include<iostream>
#include<gmpxx.h>

using namespace std;
mpq_class factorial(mpz_class n){
  if(n==0){
    return 1;
  }else{
    return n*factorial(n-1);
  }
}
int main(int argc,char* argv[]){
  mpq_class p=atoi(argv[1]);
  mpq_class q=atoi(argv[2]);
  mpq_class r=atoi(argv[3]);
  cout<<(p/q)*r<<endl;
}
