#include <stdio.h>
#include <math.h>

typedef struct {
    long double x;
    long double y;
} point;

point complex(long double x, long double y) {
    point p;
    p.x = x;
    p.y = y;
    return p;
}

long double real(point p) {
    return p.x;
}

long double imag(point p) {
    return p.y;
}

point vec(point a, point b) {
    point v;
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    return v;
}

long double length(point v) {
    return sqrt(v.y * v.y + v.x * v.x);
}

point rotate(point v, long double t) {
    point p;
    p.x = v.x * cos(t) - v.y * sin(t);
    p.y = v.x * sin(t) + v.y * cos(t);
    return p;
}

long double dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

long double cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

point normalize(point p) {
    long double len = length(p);
    point n;
    n.x = p.x / len;
    n.y = p.y / len;
    return n;
}

int main() {
    int Xc, Yc, Vc;
    int Xb, Yb, Vb, r;
    long double pi = acos(-1.0);
    point planet;
    point ship;

    scanf("%d %d %d", &Xc, &Yc, &Vc);
    scanf("%d %d %d %d", &Xb, &Yb, &Vb, &r);
    planet = complex(Xc, Yc);
    ship = complex(Xb, Yb);
    long double R = length(planet);
    long double w = Vc / R;
    long double left = 0, right = 1e30;
    for (int i = 0; i < 300; i++) {
        long double mid = (right + left) / 2;
        point new_planet = rotate(planet, w * mid);
        long double distance;
        if (length(vec(ship, new_planet)) < r) {
            point a, b, c, d;
            long double ang = acos(r / length(ship));
            a = rotate(ship, ang);
            b = rotate(ship, -ang);
            c = rotate(new_planet, ang);
            d = rotate(new_planet, -ang);
            distance = 1e30;
            distance = fmin(distance, length(vec(ship, a))
                    + length(vec(c, new_planet))
                    + (ang * r)
                    );

            distance = fmin(distance, length(vec(ship, b))
                    + length(vec(c, new_planet))
                    + (ang * r)
                    );

            distance = fmin(distance, length(vec(ship, a))
                    + length(vec(d, new_planet))
                    + (ang * r)
                    );
            distance = fmin(distance, length(vec(ship, b))
                    + length(vec(d, new_planet))
                    + (ang * r)
                    );
        } else {
            distance = length(vec(ship, new_planet));
        }

        if (distance / Vb < mid) {
            right = mid;
        } else {
            left = mid;
        }
    }
    printf("%.10Lf\n", left);
    return 0;
}
