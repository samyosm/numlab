#include "cmath"
#include "root_solver.hpp"
namespace numlab {
double fixed_point(const numlab::real_function f, const double &x,
                   const double &tol, const int &max_iter) {

  double guess = f(x);

  if (std::isinf(guess)) {
    return guess;
  }

  if (std::abs(guess) < tol || max_iter == 0) {
    return guess;
  }

  return fixed_point(f, guess, tol, max_iter - 1);
}
} // namespace numlab
