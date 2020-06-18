#include <stdio.h>

char map[50];

bool calc(long long a, long long b) {
    int index = 0;
    while (1) {
        map[index] = a % b;
        a /= b;
        if (a == 0) break;
        index++;
    }

    bool ok = true;
    int c = index;
    for (int i = 0; i < index; i++) {
        if (i >= c) break;

        if (map[i] != map[c]) {
            ok = false;
            break;
        }
        c--;
    }
    return ok;
}

int main()
{
    int t;

    scanf("%d", &t);

    long long a, b;
    for (int ii = 0; ii < t; ii++) {
        scanf("%lld %lld", &a, &b);

        bool ok = calc(a, b);

        printf("%d\n", ok);
    }

    return 0;
}
