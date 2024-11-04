









struct point {
    double x;
    double y;
};

typedef struct point point;



void inputPoint(point *p) {
    scanf("%lf %lf", &p->x, &p->y);
}



void outputPoint(point p) {
    printf("(%.3lf; %.3lf)", p.x, p.y);
}



void inputPoints(point *p, int n) {
    for (int i = 0; i < n; i++) {
        inputPoint(&p[i]);
    }
}



void outputPoints(point *p, int n) {
    for (int i = 0; i < n; i++) {
        outputPoint(p[i]);

        printf("\n");
    }
}



point id2(point p1, point p2) {
    return (point) {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
}




bool id21(point p1, point p2) {
    double deltaX = fabs(p1.x - p2.x);
    double deltaY = fabs(p1.y - p2.y);
    return deltaX < DBL_EPSILON && deltaY < DBL_EPSILON;
}






bool id11(point p1, point p2, point p3) {
    return id21(id2(p1, p2), p3);
}





void swapCoordinates(point *p) {
    double t = p->x;
    p->x = p->y;
    p->y = t;
}



void swapPoints(point *p1, point *p2) {
    point t = *p1;
    *p1 = *p2;
    *p2 = t;
}






















double getDistance(point p1, point p2) {
    return sqrtf(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}





int compare(const void *a, const void *b) {
    point p1 = *(point *) a;
    point p2 = *(point *) b;
    if (id21(p1, p2)) {
        return 0;
    } else if (p2.x < p1.x || p1.x == p2.x && p2.y < p1.y) {
        return 1;
    }
    return -1;
}





int compare_(const void *a, const void *b) {
    static point p3 = {0, 0};
    point p1 = *(point *) a;
    point p2 = *(point *) b;
    if (getDistance(p1, p3) > getDistance(p2, p3)) {
        return 1;
    } else if (getDistance(p1, p3) == getDistance(p2, p3)) {
        return 0;
    }
    return -1;
}

struct line {
    double a;
    double b;
    double c;
};

typedef struct line line;



void inputLine(line *line) {
    scanf("%lf %lf %lf", &line->a, &line->b, &line->c);

}



line id15(point p1, point p2) {
    return (line) {p2.y - p1.y, p1.x - p2.x, p2.x * p1.y - p1.x * p2.y};
}



line getLine(double x1, double y1, double x2, double y2) {
    return (line) {y2 - y1, x1 - x2, x2 * y1 - x1 * y2};
}



void id7(line line) {
    printf("%.2lfx + %.2lfy + %.2lf = 0", line.a, line.b, line.c);
}




bool isParallel(line l1, line l2) {
    return -l1.a / l1.b == -l2.a / l2.b;
}




bool id6(line l1, line l2) {
    return (-l1.a / l1.b) * (-l2.a / l2.b) == -1;
}




bool id24(line *lines, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (-lines[i].a / lines[i].b == -lines[j].a / lines[j].b) {
                return true;
            }
        }
    }
    return false;
}





void id10(line line1, line line2) {
    double b1 = -line1.c / line1.b;
    double b2 = -line2.c / line2.b;
    double k1 = -line1.a / line1.b;
    double k2 = -line2.a / line2.b;
    if (k1 == k2) {
        printf("Точки пересечения отсутствуют");

    } else {
        double x = (b1 - b2) / (k2 - k1);
        printf("(%.2lf:%.2lf)", x, k1 * x + b1);
    }
}

struct circle {
    point center;
    double r;
};

typedef struct circle circle;



void inputCircle(circle *a) {
    scanf("%lf %lf %lf", &a->center.x, &a->center.y, &a->r);

}



void outputCircle(circle a) {
    printf("%lf %lf %lf", a.center.x, a.center.y, a.r);
}



void id26(circle *a, int size) {
    for (int i = 0; i < size; i++) {
        inputCircle(&a[i]);

    }
}



void id18(circle *a, int size) {
    for (int i = 0; i < size; i++) {
        outputCircle(a[i]);

    }
}




bool id4(circle c1, circle c2) {
    double distance = sqrt(pow((c1.center.x - c2.center.x), 2) + pow((c1.center.y - c2.center.y), 2));
    return distance == c1.r + c2.r;
}

double id12(circle circle1, circle circle2) {
    return (double) sqrt(pow((circle1.center.x - circle2.center.x), 2) + pow((circle1.center.y - circle2.center.y), 2));
}





circle id22(circle *circle1, int size) {
    long long maxCount = 0;
    int index = 0;
    int id0 = 0;
    for (int i = 0; i < size; i++) {
        int currentCount = 0;
        for (int j = 0; j < size; j++) {
            if (id12(circle1[i], circle1[j]) + circle1[j].r <= circle1[i].r) {
                currentCount++;
            }
        }
        --currentCount;
        if (currentCount > maxCount) {
            maxCount = currentCount;
            index = i;
        } else if (currentCount == maxCount && circle1[i].r < circle1[index].r) {
            id0 = i;
        }
    }
    if (id0 == 0) {
        return (circle) circle1[index];
    }
    return (circle) circle1[id0];
}





circle id9(circle *circles, const size_t n) {
    circle bestCircle = {{0, 0}, 0};
    int id13 = -1;
    for (size_t i = 0; i < n; ++i) {
        int intersectionCount = 0;
        circle circle = *(circles + i);
        for (size_t j = 0; j < n; ++j)
            if (i != j) {
                if (id4(circle, *(circles + j)))
                    ++intersectionCount;
            }
        if (intersectionCount > id13) {
            bestCircle = circle;
            id13 = intersectionCount;
        } else if (intersectionCount == id13)
            if (circle.r < bestCircle.r)
                bestCircle = circle;
    }
    return bestCircle;
}

struct fraction {
    int numerator;
    int denumenator;
};

typedef struct fraction fraction;



void inputFraction(fraction *f) {
    scanf("%d / %d", &f->numerator, &f->denumenator);
}



void id17(fraction *f, size_t n) {
    for (size_t i = 0; i < n; ++i)
        inputFraction(f + i);
}



void outputFraction(fraction f) {
    printf("%d/%d\n", f.numerator, f.denumenator);
}



void id5(fraction *f, size_t n) {
    for (size_t i = 0; i < n; ++i)
        outputFraction(*(f + i));
}



long long gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}



long long lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}



void simpleFraction(fraction *f) {
    long long _gcd = gcd(f->numerator, f->denumenator);
    f->numerator /= _gcd;
    f->denumenator /= _gcd;
}



fraction id3(fraction f1, fraction f2) {
    simpleFraction(&f1);
    simpleFraction(&f2);
    return (fraction) {f1.numerator * f2.numerator, f1.denumenator * f2.denumenator};
}



fraction id20(fraction f1, fraction f2) {
    return id3(f1, (fraction) {f2.denumenator, f2.numerator});
}



fraction id8(fraction f1, fraction f2) {
    simpleFraction(&f1);
    simpleFraction(&f2);
    return (fraction) {f1.numerator * f2.denumenator + f2.numerator * f1.denumenator, f1.denumenator * f2.denumenator};
}












fraction id16(fraction *f, size_t n) {
    fraction result = *f;
    for (size_t i = 1; i < n; ++i)
        result = id8(result, *(f + i));
    return result;
}




struct student {
    char surname[20];
    int marks[id25];
};

typedef struct student student;

bool id19(student s) {
    int badMarks = 0;
    for (int i = 0; i < id25; ++i)
        if (s.marks[i] < 3)
            ++badMarks;
    return badMarks < 2;
}

void id23(student *s, int *n, const int index) {
    for (int i = index; i < *n; ++i)
        s[i] = s[i + 1];
    --*n;
}

void id1(student *s, int *n) {
    for (int i = 0; i < n; ++i)
        if (!id19(*(s + i)))
            id23(s, n, i);
}

void printStudents(student *s, const int n) {
    for (int i = 0; i < n; ++i) {
        student t = *(s + i);
        if ((s + i) != 0) {
            printf("surname: %s marks: ", t.surname);
            for (int j = 0; j < id25; ++j)
                printf("%d ", t.marks[j]);
            printf("\n");
        }
    }
}

struct time {
    int hour;
    int min;
    int sec;
};

typedef struct time time;

void swap(time *t1, time *t2) {
    time temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}

bool timeCompare(time t, time t1) {
    return t.hour * 60 * t.min + t.sec < t1.hour * 60 * t.min + t.sec;

}

void sortTime(time *t, const size_t n) {
    for (size_t i = 0; i <= n; ++i) {
        int minIndex = i;
        for (size_t j = i + 1; j < n; ++j)
            if (timeCompare(t[j], t[minIndex])) {
                minIndex = j;
            }
        swap(&t[i], &t[minIndex]);
    }
}

void id14(time t1, time t2, time *diff) {
    if (t2.sec > t1.sec) {
        --t1.min;
        t1.sec += 60;
    }
    diff->sec = t1.sec - t2.sec;
    if (t2.min > t1.min) {
        --t1.hour;
        t1.min += 60;
    }
    diff->min = t1.min - t2.min;
    diff->hour = t1.hour - t2.hour;
}

int main() {
    int t;
    scanf("%d", &t);

    for (register int i = 0; i < t; ++i) {
        int b[7];
        for (register int j = 0; j < 7; ++j) {
            scanf("%d", &b[j]);
        }
        printf("%d %d %d\n", b[0], b[1], b[6] - b[0] - b[1]);
    }
    return 0;
}