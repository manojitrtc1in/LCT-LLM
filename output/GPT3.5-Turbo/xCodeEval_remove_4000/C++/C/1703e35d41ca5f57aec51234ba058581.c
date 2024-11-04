#include <stdio.h>
#include <math.h>

typedef struct {
    long double x;
    long double y;
} point;

point rotate(point p, long double angle) {
    point result;
    result.x = p.x * cos(angle) - p.y * sin(angle);
    result.y = p.x * sin(angle) + p.y * cos(angle);
    return result;
}

long double length(point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

long double angle(point p) {
    return atan2(p.y, p.x);
}

long double arc_length(point a, point b, long double r) {
    long double ang = angle(a) - angle(b);
    if (ang < 0) {
        ang += 2 * M_PI;
    }
    if (ang > M_PI) {
        ang = 2 * M_PI - ang;
    }
    return ang * r;
}

int main() {
    int Xc, Yc, Vc;
    int Xb, Yb, Vb, r;
    point planet;
    point ship;
    long double pi = acos(-1.0);
    
    scanf("%d %d %d", &Xc, &Yc, &Vc);
    scanf("%d %d %d %d", &Xb, &Yb, &Vb, &r);
    
    planet.x = Xc;
    planet.y = Yc;
    ship.x = Xb;
    ship.y = Yb;
    
    long double R = length(planet);
    long double w = Vc / R;
    long double left = 0, right = 1ll << 30;
    
    for (int i = 0; i < 300; i++) {
        long double mid = (right + left) / 2;
        point id23 = rotate(planet, w * mid);
        long double distance;
        
        if (length(ship, id23) < r) {
            point a, b, c, d;
            id1(point(0, 0), r, ship, a, b);
            id1(point(0, 0), r, id23, c, d);
            
            distance = 1ll << 30;
            distance = min(distance, length(ship, a) + length(c, id23) + arc_length(a, c, r));
            distance = min(distance, length(ship, b) + length(c, id23) + arc_length(b, c, r));
            distance = min(distance, length(ship, a) + length(d, id23) + arc_length(a, d, r));
            distance = min(distance, length(ship, b) + length(d, id23) + arc_length(b, d, r));
        } else {
            distance = length(ship, id23);
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
