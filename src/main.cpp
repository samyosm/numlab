#include "integration/integration.hpp"
#include <iostream>

double f(double x) { return x; }

int main() {

  double a = 0;
  double b = 100;

  double area = numlab::riemann_integration(f, a, b);

  std::cout << "Area: " << area << "\n";

  return 0;
}
