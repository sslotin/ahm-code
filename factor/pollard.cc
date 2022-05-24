#include "factor.hh"

u64 f(u64 x, u64 a, u64 mod) {
    return ((u128) x * x + a) % mod;
}

u64 rho(u64 n, u64 x0 = 2, u64 a = 1) {
    u64 x = x0, y = x0, g = 1;
    while (g == 1) {
        x = f(x, a, n);
        y = f(y, a, n);
        y = f(y, a, n);
        g = gcd(x > y ? x - y : y - x, n); // x and y are unsigned and so is x - y
    }
    return g;
}

u64 find_factor(u64 n) {
    return rho(n);
}
