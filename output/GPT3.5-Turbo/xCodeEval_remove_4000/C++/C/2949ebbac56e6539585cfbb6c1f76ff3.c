#include <stdio.h>
#include <math.h>

#define DB double
#define INF 1e10
#define EPS 1e-8

typedef struct PT
{
    DB x, y;
} PT;

PT PT_create(DB x, DB y)
{
    PT p;
    p.x = x;
    p.y = y;
    return p;
}

PT PT_add(PT p1, PT p2)
{
    PT p;
    p.x = p1.x + p2.x;
    p.y = p1.y + p2.y;
    return p;
}

PT PT_sub(PT p1, PT p2)
{
    PT p;
    p.x = p1.x - p2.x;
    p.y = p1.y - p2.y;
    return p;
}

PT PT_mul(PT p, DB c)
{
    PT res;
    res.x = p.x * c;
    res.y = p.y * c;
    return res;
}

PT PT_div(PT p, DB c)
{
    PT res;
    res.x = p.x / c;
    res.y = p.y / c;
    return res;
}

DB PT_dis(PT p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

DB PT_dis2(PT p)
{
    return p.x * p.x + p.y * p.y;
}

DB PT_dis_between(PT p1, PT p2)
{
    PT diff = PT_sub(p1, p2);
    return PT_dis(diff);
}

DB PT_dis2_between(PT p1, PT p2)
{
    PT diff = PT_sub(p1, p2);
    return PT_dis2(diff);
}

DB PT_vect(PT v1, PT v2)
{
    return v1.x * v2.y - v2.x * v1.y;
}

DB PT_scal(PT v1, PT v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

int PT_sect(PT p)
{
    if (p.x == 0 && p.y == 0)
        return 0;
    if (p.x == 0)
        return p.y > 0 ? 2 : 4;
    if (p.y == 0)
        return p.x > 0 ? 1 : 3;
    if (p.x == 1)
        return p.y == 1 ? 1 : 4;
    return p.y == 1 ? 2 : 3;
}

DB PT_ang(PT v)
{
    return atan2(v.y, v.x);
}

DB PT_ang_between(PT p1, PT p2)
{
    PT diff = PT_sub(p2, p1);
    return PT_ang(diff);
}

PT PT_proj(PT p, PT p1, PT p2)
{
    PT diff = PT_sub(p2, p1);
    DB scal = PT_scal(p1, p, p2);
    DB dis2 = PT_dis2_between(p1, p2);
    return PT_add(p1, PT_mul(diff, scal / dis2));
}

PT PT_rot(PT v, DB t)
{
    PT res;
    res.x = v.x * cos(t) - v.y * sin(t);
    res.y = v.x * sin(t) + v.y * cos(t);
    return res;
}

PT PT_polar(PT o, DB r, DB t)
{
    PT res;
    res.x = o.x + r * cos(t);
    res.y = o.y + r * sin(t);
    return res;
}

DB PT_id2(PT p, PT p1, PT p2)
{
    return fabs(PT_vect(p, p1, p2)) / PT_dis_between(p1, p2);
}

DB PT_id8(PT p, PT p1, PT p2)
{
    if (PT_scal(p1, p, p2) < 0)
        return PT_dis_between(p, p1);
    if (PT_scal(p2, p, p1) < 0)
        return PT_dis_between(p, p2);
    return PT_id2(p, p1, p2);
}

int PT_onLine(PT p, PT p1, PT p2)
{
    return PT_vect(p, p1, p2) == 0;
}

int PT_onSeg(PT p, PT p1, PT p2)
{
    return !PT_onLine(p, p1, p2) && PT_scal(p, p1, p2) <= 0;
}

int PT_inAngle(PT p, PT p0, PT p1, PT p2)
{
    DB d0 = PT_vect(p0, p1, p2);
    DB d1 = PT_vect(p0, p1, p);
    DB d2 = PT_vect(p0, p2, p);
    if (d0 >= 0)
        return d1 >= 0 && d2 <= 0;
    return d1 >= 0 || d2 <= 0;
}

int PT_id12(PT p, PT q[], int n)
{
    PT o = PT_div(PT_add(PT_add(q[0], q[1]), q[2]), 3);
    if (o.x == p.x && o.y == p.y)
        return 1;
    int l = 0, h = n;
    while (h - l > 1)
    {
        int m = (l + h) / 2;
        if (PT_inAngle(p, o, q[l % n], q[m % n]))
            h = m;
        else
            l = m;
    }
    l %= n;
    h %= n;
    if (PT_vect(q[l], q[h], p) == 0)
        return 2;
    return PT_vect(q[l], q[h], o) * PT_vect(q[l], q[h], p) > 0;
}

int PT_id6(PT p1, PT p2, PT p3, PT p4, PT *p)
{
    DB s1 = PT_vect(p1, p2, p3);
    DB s2 = PT_vect(p1, p2, p4);
    if (s1 == s2)
        return s1 ? 0 : 2;
    p->x = p3.x - (p4.x - p3.x) * s1 / (s2 - s1);
    p->y = p3.y - (p4.y - p3.y) * s1 / (s2 - s1);
    return 1;
}

int PT_id0(PT p1, PT p2, PT p3, PT p4, PT *p)
{
    int ret = PT_id6(p1, p2, p3, p4, p);
    if (ret == 1)
        return PT_onSeg(*p, p1, p2) && PT_onSeg(*p, p3, p4);
    if (ret == 2 && (PT_onSeg(p1, p3, p4) || PT_onSeg(p2, p3, p4)))
        return 2;
    return 0;
}

int PT_inPolygon(PT p, PT q[], int n)
{
    int c = 0;
    PT r = PT_create(INF, INF * sqrt(3));
    PT t;
    for (int i = 0; i < n; ++i)
    {
        if (PT_onLine(p, q[i], q[(i + 1) % n]))
            return 2;
        if (PT_id0(p, r, q[i], q[(i + 1) % n], &t) == 1)
            ++c;
    }
    return c % 2;
}

int PT_id7(PT o, DB r, PT p1, PT p2, PT q[])
{
    DB a = PT_dis2(p1, p2);
    DB b = PT_scal(p1, o, p2);
    DB c = PT_dis2(o, p1) - r * r;
    DB d2 = b * b - a * c;
    if (d2 < 0)
        return 0;
    DB d = sqrt(fabs(d2));
    q[0] = PT_add(p1, PT_mul(PT_sub(p2, p1), (b + d) / a));
    if (d2 == 0)
        return 1;
    q[1] = PT_add(p1, PT_mul(PT_sub(p2, p1), (b - d) / a));
    return 2;
}

int PT_id3(PT o1, DB r1, PT o2, DB r2, PT q[])
{
    if (o1.x == o2.x && o1.y == o2.y)
        return r1 == r2 ? 3 : 0;
    DB d = PT_dis(o1, o2);
    DB e = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
    DB f2 = r1 * r1 - e * e;
    if (f2 < 0)
        return 0;
    DB f = sqrt(fabs(f2));
    DB dx = o2.x - o1.x, dy = o2.y - o1.y;
    q[0].x = o1.x + (e * dx - f * dy) / d;
    q[0].y = o1.y + (e * dy + f * dx) / d;
    if (f2 == 0)
        return 1;
    q[1].x = o1.x + (e * dx + f * dy) / d;
    q[1].y = o1.y + (e * dy - f * dx) / d;
    return 2;
}

PT PT_normalLine(PT p1, PT p2)
{
    PT res;
    res.x = -(p2.y - p1.y);
    res.y = p2.x - p1.x;
    return res;
}

PT PT_innerCenter(PT a, PT b, PT c)
{
    DB A = PT_dis(b, c);
    DB B = PT_dis(c, a);
    DB C = PT_dis(a, b);
    PT res;
    res.x = (A * a.x + B * b.x + C * c.x) / (A + B + C);
    res.y = (A * a.y + B * b.y + C * c.y) / (A + B + C);
    return res;
}

PT PT_outerCenter(PT a, PT b, PT c)
{
    DB d1 = (PT_dis2(a) - PT_dis2(b)) / 2;
    DB d2 = (PT_dis2(a) - PT_dis2(c)) / 2;
    DB x = (d1 * (a.y - c.y) - d2 * (a.y - b.y)) / PT_vect(a, b, c);
    DB y = (d1 * (a.x - c.x) - d2 * (a.x - b.x)) / PT_vect(a, c, b);
    PT res;
    res.x = x;
    res.y = y;
    return res;
}

PT PT_gravityCenter(PT p[], int n)
{
    PT o;
    o.x = 0;
    o.y = 0;
    for (int i = 0; i < n; ++i)
    {
        o.x += p[i].x;
        o.y += p[i].y;
    }
    o.x /= n;
    o.y /= n;
    return o;
}

DB PT_id9(PT p1, DB r1, PT p2, DB r2)
{
    DB d = PT_dis(p1, p2);
    if (d >= r1 + r2)
        return 0;
    DB p = (r1 + r2 + d) / 2;
    DB s = sqrt(p * (p - r1) * (p - r2) * (p - d));
    DB l = 2 * s / d;
    return r1 * r1 * asin(l / r1) + r2 * r2 * asin(l / r2) - s * 2;
}

int PT_isSimple(PT p[], int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = i + 3; j < n; ++j)
            if (0)
                return 0;
    return 1;
}

int PT_id1(PT p[], int n)
{
    for (int i = 0; i < n; ++i)
        if (PT_vect(p[i], p[(i + 1) % n], p[(i + 2) % n]) <= 0)
            return 0;
    return 1;
}

DB PT_id10(PT p[], int n)
{
    DB S = 0;
    for (int i = 0; i < n; ++i)
        S += PT_vect(p[i], p[(i + 1) % n]);
    return fabs(S) / 2;
}

int PT_id5(PT p[], int n, PT q[])
{
    for (int i = 0; i < n; ++i)
        q[i] = p[i];
    n = unique(q, q + n) - q;
    if (n == 1)
        return 1;
    int m = 0;
    for (int i = 0; i < n; ++i)
    {
        for (; m >= 2 && PT_vect(q[m - 2], q[m - 1], p[i]) <= 0; --m)
            ;
        q[m++] = p[i];
    }
    for (int i = n - 2, m0 = m; i >= 0; --i)
    {
        for (; m > m0 && PT_vect(q[m - 2], q[m - 1], p[i]) <= 0; --m)
            ;
        q[m++] = p[i];
    }
    return --m;
}

typedef struct HP
{
    PT s, e;
} HP;

HP HP_create(PT s, PT e)
{
    HP h;
    h.s = s;
    h.e = e;
    return h;
}

int HP_id4(HP *p, int n)
{
    p[n++] = HP_create(PT_create(-INF, -INF), PT_create(INF, -INF));
    p[n++] = HP_create(PT_create(INF, -INF), PT_create(INF, INF));
    p[n++] = HP_create(PT_create(INF, INF), PT_create(-INF, INF));
    p[n++] = HP_create(PT_create(-INF, INF), PT_create(-INF, -INF));
    // sort(p, p + n);
    n = 4;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i)
    {
        PT c;
        for (; r - l >= 2; --r)
        {
            PT_id6(p[r - 2].s, p[r - 2].e, p[r - 1].s, p[r - 1].e, &c);
            if (PT_vect(p[i].s, p[i].e, c) > 0)
                break;
        }
        for (; r - l >= 2; ++l)
        {
            PT_id6(p[l].s, p[l].e, p[l + 1].s, p[l + 1].e, &c);
            if (PT_vect(p[i].s, p[i].e, c) > 0)
                break;
        }
        if (r - l < 2)
            p[r++] = p[i];
        else
        {
            PT_id6(p[r - 1].s, p[r - 1].e, p[i].s, p[i].e, &c);
            if (PT_vect(p[0].s, p[0].e, c) > 0)
                p[r++] = p[i];
        }
    }
    int m = 0;
    for (int i = l; i < r; ++i)
    {
        DB t = INF;
        t = fmin(t, fabs(p[i].s.x));
        t = fmin(t, fabs(p[i].s.y));
        t = fmin(t, fabs(p[i].e.x));
        t = fmin(t, fabs(p[i].e.y));
        if (t < INF)
            p[m++] = p[i];
    }
    return m;
}

#define N 2100

DB d[N];
PT p[N];
PT v[N];
int cmp1(const void *a, const void *b)
{
    PT *p1 = (PT *)a;
    PT *p2 = (PT *)b;
    if (PT_sect(*p1) != PT_sect(*p2))
        return PT_sect(*p1) - PT_sect(*p2);
    DB d = PT_vect(*p1, *p2);
    return d > 0 ? 1 : -1;
}

int cmp2(const void *a, const void *b)
{
    PT *p1 = (PT *)a;
    PT *p2 = (PT *)b;
    return PT_sect(*p1) == PT_sect(*p2) && PT_vect(*p1, *p2) == 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    PT g = PT_gravityCenter(p, n);
    for (int i = 0; i < n; ++i)
        p[i] = PT_sub(p[i], g);
    qsort(p, n, sizeof(PT), cmp1);
    PT q;
    for (int i = 0; i < n; ++i)
    {
        int fp = 0;
        for (int j = 0; j < n; ++j)
        {
            if (p[j].x == -p[i].x && p[j].y == -p[i].y)
            {
                fp = 1;
                break;
            }
        }
        if (!fp)
        {
            q = p[i];
            break;
        }
        if (i == n - 1)
        {
            printf("-1\n");
            return 0;
        }
    }
    int v_size = 0;
    for (int i = 0; i < n; ++i)
    {
        PT m = PT_div(PT_add(p[i], q), 2);
        PT nv = PT_normalLine(PT_create(0, 0), m);
        if (PT_sect(nv) >= 3)
            nv = PT_mul(nv, -1);
        v[v_size++] = nv;
    }
    qsort(v, v_size, sizeof(PT), cmp1);
    int v_new_size = 1;
    for (int i = 1; i < v_size; ++i)
    {
        if (PT_sect(v[i]) == PT_sect(v[v_new_size - 1]) && PT_vect(v[i], v[v_new_size - 1]) == 0)
            continue;
        v[v_new_size++] = v[i];
    }
    int ans = 0;
    for (int i = 0; i < v_new_size; ++i)
    {
        for (int j = 0; j < n; ++j)
            d[j] = PT_scal(v[i], PT_proj(p[j], PT_create(0, 0), v[i])) / PT_dis(v[i]);
        qsort(d, n, sizeof(DB), cmp2);
        int flg = 1;
        for (int j = 0; j < n / 2; ++j)
            if (d[j] + d[n - 1 - j])
                flg = 0;
        ans += flg;
    }
    printf("%d\n", ans);
    return 0;
}
