#include "inverse.hh"

/*
int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
*/

void gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return;
    }
    int x1, y1;
    gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
}

int inverse(int a) {
    int x, y;
    gcd(a, m, x, y);
    if (x < 0)
        x += m;
    //cout << a << " " << x << " " << y << " " << x * a % m << endl;
    return x;
}
