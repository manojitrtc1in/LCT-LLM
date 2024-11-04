#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int q;
} Frac;

typedef struct {
    int x;
    int v;
    int p;
} Car;

typedef struct {
    int a[2][2];
} Mat;

typedef struct {
    int l;
    int r;
} Range;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

Frac simplify(Frac f) {
    int g = gcd(f.p, f.q);
    f.p /= g;
    f.q /= g;
    return f;
}

int compareFrac(Frac f1, Frac f2) {
    int num1 = f1.p * f2.q;
    int num2 = f2.p * f1.q;
    if (num1 < num2) {
        return -1;
    } else if (num1 > num2) {
        return 1;
    } else {
        return 0;
    }
}

Mat multiplyMat(Mat m1, Mat m2) {
    Mat res;
    res.a[0][0] = m1.a[0][0] * m2.a[0][0] + m1.a[0][1] * m2.a[1][0];
    res.a[0][1] = m1.a[0][0] * m2.a[0][1] + m1.a[0][1] * m2.a[1][1];
    res.a[1][0] = m1.a[1][0] * m2.a[0][0] + m1.a[1][1] * m2.a[1][0];
    res.a[1][1] = m1.a[1][0] * m2.a[0][1] + m1.a[1][1] * m2.a[1][1];
    return res;
}

Mat getIdentityMat() {
    Mat mat;
    mat.a[0][0] = 1;
    mat.a[0][1] = 0;
    mat.a[1][0] = 0;
    mat.a[1][1] = 1;
    return mat;
}

Mat getCollisionMat(int p) {
    Mat mat;
    mat.a[0][0] = 0;
    mat.a[0][1] = p;
    mat.a[1][0] = 1 - p;
    mat.a[1][1] = 0;
    return mat;
}

Frac getProb(Mat mat, int toRight) {
    Frac prob;
    prob.p = toRight * (mat.a[1][0] + mat.a[1][1]) + (1 - toRight) * (mat.a[0][0] + mat.a[0][1]);
    prob.q = 1;
    return simplify(prob);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    Car* cars = (Car*) malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &cars[i].x, &cars[i].v, &cars[i].p);
    }
    Mat* allowedCollisions = (Mat*) malloc((n - 1) * sizeof(Mat));
    for (int i = 0; i < n - 1; i++) {
        allowedCollisions[i] = getCollisionMat(cars[i + 1].p);
    }
    Mat* a = (Mat*) malloc((2 * (n - 1) - 1) * sizeof(Mat));
    Range* ranges = (Range*) malloc((2 * (n - 1) - 1) * sizeof(Range));
    for (int i = 0; i < n - 1; i++) {
        ranges[i].l = i;
        ranges[i].r = i;
    }
    for (int i = n - 2; i >= 0; i--) {
        ranges[2 * i].l = ranges[i].l;
        ranges[2 * i].r = (ranges[i].l + ranges[i].r) / 2;
        ranges[2 * i + 1].l = (ranges[i].l + ranges[i].r) / 2 + 1;
        ranges[2 * i + 1].r = ranges[i].r;
    }
    for (int i = 0; i < 2 * (n - 1) - 1; i++) {
        if (ranges[i].l == ranges[i].r) {
            a[i] = allowedCollisions[ranges[i].l];
        } else {
            a[i] = multiplyMat(a[2 * i], a[2 * i + 1]);
        }
    }
    Frac prevProb = getProb(a[0], cars[0].p), ans = {0, 1};
    Frac* events = (Frac*) malloc(3 * (n - 1) * sizeof(Frac));
    int* eventIndices = (int*) malloc(3 * (n - 1) * sizeof(int));
    for (int i = 0; i < n - 1; i++) {
        int d = cars[i + 1].x - cars[i].x;
        events[i * 3].p = d;
        events[i * 3].q = cars[i + 1].v + cars[i].v;
        eventIndices[i * 3] = i << 2 | 1;
        if (cars[i].v < cars[i + 1].v) {
            events[i * 3 + 1].p = d;
            events[i * 3 + 1].q = cars[i + 1].v - cars[i].v;
            eventIndices[i * 3 + 1] = i << 2 | 0;
        } else {
            events[i * 3 + 1].p = 1;
            events[i * 3 + 1].q = 0;
            eventIndices[i * 3 + 1] = i << 2 | 0;
        }
        if (cars[i].v > cars[i + 1].v) {
            events[i * 3 + 2].p = d;
            events[i * 3 + 2].q = cars[i].v - cars[i + 1].v;
            eventIndices[i * 3 + 2] = i << 2 | 3;
        } else {
            events[i * 3 + 2].p = 1;
            events[i * 3 + 2].q = 0;
            eventIndices[i * 3 + 2] = i << 2 | 3;
        }
    }
    for (int i = 0; i < 3 * (n - 1); i++) {
        for (int j = i + 1; j < 3 * (n - 1); j++) {
            if (compareFrac(events[i], events[j]) > 0) {
                Frac temp = events[i];
                events[i] = events[j];
                events[j] = temp;
                int tempIndex = eventIndices[i];
                eventIndices[i] = eventIndices[j];
                eventIndices[j] = tempIndex;
            }
        }
    }
    for (int i = 3 * (n - 1) - 1; i >= 0; i--) {
        int index = eventIndices[i] >> 2;
        int dir1 = (eventIndices[i] >> 0) & 1;
        int dir2 = (eventIndices[i] >> 1) & 1;
        allowedCollisions[index].a[dir1][dir2] = (dir2 == 1) ? cars[index + 1].p : 1 - cars[index + 1].p;
        for (int j = 0; j < 2 * (n - 1) - 1; j++) {
            if (ranges[j].l <= index && index <= ranges[j].r) {
                if (ranges[j].l == ranges[j].r) {
                    a[j] = allowedCollisions[ranges[j].l];
                } else {
                    a[j] = multiplyMat(a[2 * j], a[2 * j + 1]);
                }
            }
        }
        Frac prob = getProb(a[0], cars[0].p);
        if (events[i].q != 0) {
            Frac diffProb;
            diffProb.p = prob.p - prevProb.p;
            diffProb.q = prob.q;
            ans.p = ans.p * diffProb.q + ans.q * diffProb.p;
            ans.q *= diffProb.q;
            int g = gcd(ans.p, ans.q);
            ans.p /= g;
            ans.q /= g;
        }
        prevProb = prob;
    }
    printf("%d\n", ans.p);
    free(cars);
    free(allowedCollisions);
    free(a);
    free(ranges);
    free(events);
    free(eventIndices);
    return 0;
}
