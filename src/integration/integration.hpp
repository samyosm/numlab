
#include "../../include/numlab.hpp"

namespace numlab {
double riemann_integration(const numlab::real_function &f, const double &a,
                           const double &b, const int &max_iter);
double riemann_integration(const numlab::real_function &f, const double &a,
                           const double &b, const double &dx = 0.01);

} // namespace numlab
