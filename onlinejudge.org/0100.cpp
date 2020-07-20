
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int get_cycle_length(int x) {
    int n = 1;
    while (x != 1) {
        if ((x % 2)) {
            x = 3 * x + 1;
        } else {
            x = x / 2;
        }
        n++;
    }
    return n;
}

int main(int argc, char** argv) {
    for (;;) {
        int a = -1, b = -1;

        scanf("%d %d\n", &a, &b);

        if (a == -1 || b == -1) {
            break;
        }

        int x = a, y = b;

        if (y < x) {
            swap(x, y);
        }

        int mm = 0;

        for (int i = x; i <= y; ++i) {
            int n = get_cycle_length(i);
            if (n > mm) mm = n;
        }

        printf("%d %d %d\n", a, b, mm);
    }

    return 0;
}