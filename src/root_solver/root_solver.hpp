#pragma once

#include "../../include/numlab.hpp"

namespace numlab {

double bisection(const numlab::real_function f, const double &a,
                 const double &b, const double &tol = 0.01,
                 const int &max_iter = 1000);
} // namespace numlab
