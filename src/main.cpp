#include "integration/integration.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>

double f(double x) {
  x += x;
  return x;
}

void f(int *x) { *x += *x; }

int *wst(std::size_t size) {
  int *ptr = (int *)malloc(size * sizeof(int));

  return ptr;
}

int main() {

  int *ptr = wst(4);
  *ptr = 2;

  f(ptr);

  std::cout << "Ptr: " << ptr << "\n";
  std::cout << "Value: " << *ptr << "\n";

  free(ptr);
  std::cout << "Ptr: " << ptr << "\n";
  std::cout << "Value: " << *ptr << "\n";

  return 0;
}
