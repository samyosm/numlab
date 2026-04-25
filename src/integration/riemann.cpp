#include "../../include/numlab.hpp"

namespace numlab {
double riemann_integration(const numlab::real_function &f, const double &a,
                           const double &b, const int &max_iter) {

  const double dx = (b - a) / max_iter;

  double result = 0;

  for (int i = 0; i < max_iter; i++) {
    result += f(a + i * dx) * dx;
  }

  return result;
}

double riemann_integration(const numlab::real_function &f, const double &a,
                           const double &b, const double &dx = 0.01) {
  const int N = (b - a) / dx;
  return riemann_integration(f, a, b, N);
}

} // namespace numlab
