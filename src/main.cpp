#include "integration/integration.hpp"
#include "root_solver/root_solver.hpp"
#include <cmath>
#include <iostream>

double f(double x) { return x * x - 2; }

void print_error(double root) {

  double real_value = sqrt(2);

  auto error = (root - real_value) / real_value;

  std::cout << "Error: " << error * 100 << "%\n";
}

int main() {

  double a = 0;
  double b = 2;

  auto root_bisection = numlab::bisection(f, a, b);
  auto root_regula_falsi = numlab::regula_falsi(f, a, b);

  std::cout << "Bisection: " << root_bisection << "\n";
  print_error(root_bisection);
  std::cout << "Regula Falsi: " << root_regula_falsi << "\n";
  print_error(root_regula_falsi);

  return 0;
}
