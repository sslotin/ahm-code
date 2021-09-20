#include "fft.hh"

const double pi = acos(-1);

void solve(ftype *a, int n, ftype wn) {
    //if (n == 1)
    //    cout << a[0] << " " << wn << endl;
    if (n > 1) {
        int k = (n >> 1);
        solve(a, k, wn * wn);
        solve(a + k, k, wn * wn);
        ftype w = 1;
        for (int i = 0; i < k; i++) {
            ftype t = w * a[i + k];
            a[i + k] = a[i] - t; 
            a[i] = a[i] + t;
            w *= wn;
        }
    }
}

/*
struct Precalc {
    char rev[256];

    constexpr Precalc() : rev{} {
        for (int i = 0; i < 256; i++)
            for (int l = 0; l < 8; l++)
                rev[i] |= ((i >> l & 1) << (7 - l));        
    }
};*/

//constexpr Precalc precalc{};

void fft(ftype *a, int n) {
    ftype wn = polar(1., - 2 * pi / n); // 1/w?
    const int logn = __lg(n);

    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int l = 0; l < logn; l++)
            k |= ((i >> l & 1) << (logn - l - 1));
        if (i < k)
            swap(a[i], a[k]);
    }

    //for (int i = 0; i < n; i++)
    //    cout << a[i] << " ";
    //cout << endl; exit(0);

    solve(a, n, wn);
}
