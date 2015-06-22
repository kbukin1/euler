#include <iostream>
#include <math.h>

// See p190.pdf for details
typedef unsigned long long Int;

double prod(Int n) {
  double ret = 1;

  for (Int i = 2; i <=n; ++i)
    ret *= pow(i,i);

  return ret;
}

double P(Int i) {
  return pow(2, i*(i+1)/2) * prod(i) / pow(i+1, i*(i+1)/2);
}

int main(){

  Int sum = 0;

  for (int i = 2; i <= 15; ++i)
    sum += Int(P(i)); // XXX overflow check is missing

  std::cout << "Sum: " << sum << std::endl;
  return 0;
}

