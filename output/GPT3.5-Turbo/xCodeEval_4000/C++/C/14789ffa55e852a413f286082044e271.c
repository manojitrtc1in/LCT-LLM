#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

typedef struct {
    int x, y, i;
} point;

point make_point(int x, int y, int i) {
    point p;
    p.x = x;
    p.y = y;
    p.i = i;
    return p;
}

point operator_minus(point a, point b) {
    return make_point(a.x - b.x, a.y - b.y, -1);
}

point operator_plus(point a, point b) {
    return make_point(a.x + b.x, a.y + b.y, -1);
}

int operator_equal(point a, point b) {
    return (a.x == b.x && a.y == b.y);
}

li sdist(point a, point b) {
    return sqr(li(a.x - b.x)) + sqr(li(a.y - b.y));
}

li dot(point a, point b) {
    return a.x * li(b.x) + a.y * li(b.y);
}

li cross(point a, point b) {
    return a.x * li(b.y) - a.y * li(b.x);
}

const int N = 2000 + 7;

point a[N];
int n;
char s[N];

int read() {
    if (scanf("%d", &n) != 1)
        return 0;
    forn(i, n) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].i = i + 1;
    }
    scanf("%s", s);
    return 1;
}

void print_point(point p) {
    printf("(%d, %d)", p.x, p.y);
}

void print_vector(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_pair_int_int(pt p) {
    printf("(%d, %d)", p.x, p.y);
}

void print_pair_A_B(pt* p) {
    printf("(%d, %d)", p->x, p->y);
}

void print_pair_A_B_ostream(pt* p) {
    printf("(%d, %d)", p->x, p->y);
}

void print_vector_A(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

void print_vector_A_B_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream_ostream(point* v, int size) {
    printf("[");
    forn(i, size) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

