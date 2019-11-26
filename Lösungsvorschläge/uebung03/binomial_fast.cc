#include "../fcpp.hh"

int fac_helper(int prod, int counter, int end) {
  return cond(counter > end, prod,
              fac_helper(prod * counter, counter + 1, end));
}

int factorial(int n) { return fac_helper(1, 1, n); }

int binomial_fast(int n, int k) {
  return cond(k > n, -1, factorial(n) / (factorial(k) * factorial(n - k)));
}

int main(int argc, char **argv) {
  return print(
      binomial_fast(readarg_int(argc, argv, 1), readarg_int(argc, argv, 2)));
}
