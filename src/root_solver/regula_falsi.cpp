#include "cmath"
#include "root_solver.hpp"
#include <stdexcept>
namespace numlab {

double regula_falsi(const real_function f, const double &a, const double &b,
                    const double &tol, const int &max_iter) {
  if (f(a) * f(b) > 0) {
    throw std::runtime_error("Error: must be of different signs");
  }

  double root = (a * f(b) - b * f(a)) / (f(b) - f(a));

  if (std::abs(f(root)) < tol || max_iter == 0)
    return root;

  if (f(a) * f(root) > 0) {
    return regula_falsi(f, root, b, tol, max_iter - 1);
  } else {
    return regula_falsi(f, a, root, tol, max_iter - 1);
  }
}

} // namespace numlab
