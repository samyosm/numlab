#include "cmath"
#include "root_solver.hpp"
#include <stdexcept>
namespace numlab {

double bisection(const real_function f, const double &a, const double &b,
                 const double &tol, const int &max_iter) {
  if (f(a) * f(b) > 0) {
    throw std::runtime_error("Error: must be of different signs");
  }

  double root = (a + b) / 2;

  if (std::abs(f(root)) < tol || max_iter == 0)
    return root;

  if (f(a) * f(root) > 0) {
    return bisection(f, root, b, tol, max_iter - 1);
  } else {
    return bisection(f, a, root, tol, max_iter - 1);
  }
}

} // namespace numlab
