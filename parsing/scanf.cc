#include "read.hh"

void prepare() {}

int read(int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        s ^= x;
    }
    return s;
}
