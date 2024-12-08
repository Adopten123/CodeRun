#include <stdio.h>

void find_missing_cards(int N, long long S, long long S_square, long long S_cube) {
    long long S_total = (long long)N * (N + 1) / 2;
    long long S_square_total = (long long)N * (N + 1) * (2 * N + 1) / 6;
    long long S_cube_total = S_total * S_total;

    long long d1 = S_total - S;
    long long d2 = S_square_total - S_square;
    long long d3 = S_cube_total - S_cube;

    for (int x = 1; x <= N; ++x) {
        for (int y = x + 1; y <= N; ++y) {
            int z = d1 - (x + y);
            if (z <= y || z > N) continue;
            if ((long long)x * x + (long long)y * y + (long long)z * z == d2 &&
                (long long)x * x * x + (long long)y * y * y + (long long)z * z * z == d3) {
                printf("%d %d %d\n", x, y, z);
                return;
                }
        }
    }
}

int main() {
    int N;
    long long S1, S2, S3;

    scanf("%d", &N);
    scanf("%lld %lld %lld", &S1, &S2, &S3);

    find_missing_cards(N, S1, S2, S3);

    return 0;
}
