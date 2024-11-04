import java.util.*;

class Main {
    static class PT {
        double x, y;

        PT(double x, double y) {
            this.x = x;
            this.y = y;
        }

        PT() {
            this(0, 0);
        }

        PT add(PT o) {
            return new PT(x + o.x, y + o.y);
        }

        PT subtract(PT o) {
            return new PT(x - o.x, y - o.y);
        }

        PT multiply(double c) {
            return new PT(x * c, y * c);
        }

        PT divide(double c) {
            return new PT(x / c, y / c);
        }

        boolean equals(PT o) {
            return Math.abs(x - o.x) < EPS && Math.abs(y - o.y) < EPS;
        }
    }

    static class HP {
        PT s, e;

        HP(PT s, PT e) {
            this.s = s;
            this.e = e;
        }
    }

    static final double EPS = 1e-8;
    static final double INF = 1e10;

    static double sqr(double v) {
        return v * v;
    }

    static int sgn(double v) {
        return v < -EPS ? -1 : v > EPS ? 1 : 0;
    }

    static double dis(PT v) {
        return Math.sqrt(sqr(v.x) + sqr(v.y));
    }

    static double dis2(PT v) {
        return sqr(v.x) + sqr(v.y);
    }

    static double dis(PT p1, PT p2) {
        return dis(p1.subtract(p2));
    }

    static double dis2(PT p1, PT p2) {
        return dis2(p1.subtract(p2));
    }

    static double vect(PT v1, PT v2) {
        return v1.x * v2.y - v2.x * v1.y;
    }

    static double vect(PT p, PT p1, PT p2) {
        return vect(p1.subtract(p), p2.subtract(p));
    }

    static double scal(PT v1, PT v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    static double scal(PT p, PT p1, PT p2) {
        return scal(p1.subtract(p), p2.subtract(p));
    }

    static int sect(PT p) {
        if (sgn(p.x) == 0 && sgn(p.y) == 0) return 0;
        if (sgn(p.x) == 0) return sgn(p.y) > 0 ? 2 : 4;
        if (sgn(p.y) == 0) return sgn(p.x) > 0 ? 1 : 3;
        if (sgn(p.x) == 1) return sgn(p.y) == 1 ? 1 : 4;
        return sgn(p.y) == 1 ? 2 : 3;
    }

    static double ang(PT v) {
        return Math.atan2(v.y, v.x);
    }

    static double ang(PT p1, PT p2) {
        return ang(p2.subtract(p1));
    }

    static double ang(PT p, PT p1, PT p2) {
        double dy = vect(p, p1, p2);
        double dx = scal(p, p1, p2);
        if (sgn(dy) == 0) dy = 0;
        if (sgn(dx) == 0) dx = 0;
        return Math.atan2(dy, dx);
    }

    static double ang2(PT p, PT p1, PT p2) {
        return Math.acos(scal(p, p1, p2) / dis(p, p1) / dis(p, p2));
    }

    static PT proj(PT p, PT p1, PT p2) {
        return p1.add(p2.subtract(p1).multiply(scal(p1, p, p2) / dis2(p1, p2)));
    }

    static PT rot(PT v, double t) {
        return new PT(v.x * Math.cos(t) - v.y * Math.sin(t), v.x * Math.sin(t) + v.y * Math.cos(t));
    }

    static PT rot(PT p, PT o, double t) {
        return rot(p.subtract(o), t).add(o);
    }

    static PT polar(PT o, double r, double t) {
        return o.add(new PT(r * Math.cos(t), r * Math.sin(t)));
    }

    static double id2(PT p, PT p1, PT p2) {
        return Math.abs(vect(p, p1, p2)) / dis(p1, p2);
    }

    static double id8(PT p, PT p1, PT p2) {
        if (sgn(scal(p1, p, p2)) < 0) return dis(p, p1);
        if (sgn(scal(p2, p, p1)) < 0) return dis(p, p2);
        return id2(p, p1, p2);
    }

    static boolean onLine(PT p, PT p1, PT p2) {
        return sgn(vect(p, p1, p2)) == 0;
    }

    static boolean onSeg(PT p, PT p1, PT p2) {
        return onLine(p, p1, p2) && sgn(scal(p, p1, p2)) <= 0;
    }

    static boolean inAngle(PT p, PT p0, PT p1, PT p2) {
        double d0 = vect(p0, p1, p2);
        double d1 = vect(p0, p1, p);
        double d2 = vect(p0, p2, p);
        if (sgn(d0) >= 0) return sgn(d1) >= 0 && sgn(d2) <= 0;
        return sgn(d1) >= 0 || sgn(d2) <= 0;
    }

    static int id12(PT p, PT[] q, int n) {
        PT o = new PT((q[0].x + q[1].x + q[2].x) / 3, (q[0].y + q[1].y + q[2].y) / 3);
        if (o.equals(p)) return 1;
        int l = 0, h = n;
        while (h - l > 1) {
            int m = (l + h) / 2;
            if (inAngle(p, o, q[l % n], q[m % n])) h = m;
            else l = m;
        }
        l %= n;
        h %= n;
        if (sgn(vect(q[l], q[h], p)) == 0) return 2;
        return sgn(vect(q[l], q[h], o) * vect(q[l], q[h], p)) > 0 ? 0 : 2;
    }

    static int id6(PT p1, PT p2, PT p3, PT p4, PT p) {
        double s1 = vect(p1, p2, p3);
        double s2 = vect(p1, p2, p4);
        if (sgn(s1 - s2) == 0) return sgn(s1) != 0 ? 0 : 2;
        p.x = p3.x - (p4.x - p3.x) * s1 / (s2 - s1);
        p.y = p3.y - (p4.y - p3.y) * s1 / (s2 - s1);
        return 1;
    }

    static int id0(PT p1, PT p2, PT p3, PT p4, PT p) {
        int ret = id6(p1, p2, p3, p4, p);
        if (ret == 1) return onSeg(p, p1, p2) && onSeg(p, p3, p4) ? 1 : 0;
        if (ret == 2 && (onSeg(p1, p3, p4) || onSeg(p2, p3, p4))) return 2;
        return 0;
    }

    static int inPolygon(PT p, PT[] q, int n) {
        int c = 0;
        PT r = new PT(INF, INF * Math.sqrt(3));
        PT t;
        for (int i = 0; i < n; ++i) {
            if (onLine(p, q[i], q[(i + 1) % n])) return 2;
            if (id0(p, r, q[i], q[(i + 1) % n], t) == 1) ++c;
        }
        return c % 2;
    }

    static int id7(PT o, double r, PT p1, PT p2, PT[] q) {
        double a = dis2(p1, p2);
        double b = scal(p1, o, p2);
        double c = dis2(o, p1) - sqr(r);
        double d2 = sqr(b) - a * c;
        if (sgn(d2) < 0) return 0;
        double d = Math.sqrt(Math.abs(d2));
        if (q != null) q[0] = p1.add(p2.subtract(p1).multiply((b + d) / a));
        if (sgn(d2) == 0) return 1;
        if (q != null) q[1] = p1.add(p2.subtract(p1).multiply((b - d) / a));
        return 2;
    }

    static int id3(PT o1, double r1, PT o2, double r2, PT[] q) {
        if (o1.equals(o2)) return sgn(r1 - r2) != 0 ? 0 : 3;
        double d = dis(o1, o2);
        double e = (sqr(r1) - sqr(r2) + sqr(d)) / (2 * d);
        double f2 = sqr(r1) - sqr(e);
        if (sgn(f2) < 0) return 0;
        double f = Math.sqrt(Math.abs(f2));
        double dx = o2.x - o1.x, dy = o2.y - o1.y;
        if (q != null) q[0] = new PT(o1.x + (e * dx - f * dy) / d, o1.y + (e * dy + f * dx) / d);
        if (sgn(f2) == 0) return 1;
        if (q != null) q[1] = new PT(o1.x + (e * dx + f * dy) / d, o1.y + (e * dy - f * dx) / d);
        return 2;
    }

    static PT normalLine(PT p1, PT p2) {
        return new PT(-(p2.y - p1.y), p2.x - p1.x);
    }

    static PT innerCenter(PT a, PT b, PT c) {
        double A = dis(b, c);
        double B = dis(c, a);
        double C = dis(a, b);
        return new PT((A * a.x + B * b.x + C * c.x) / (A + B + C), (A * a.y + B * b.y + C * c.y) / (A + B + C));
    }

    static PT outerCenter(PT a, PT b, PT c) {
        double d1 = (dis2(a) - dis2(b)) / 2;
        double d2 = (dis2(a) - dis2(c)) / 2;
        double x = (d1 * (a.y - c.y) - d2 * (a.y - b.y)) / vect(a.subtract(b), a.subtract(c));
        double y = (d1 * (a.x - c.x) - d2 * (a.x - b.x)) / vect(a.subtract(c), a.subtract(b));
        return new PT(x, y);
    }

    static PT gravityCenter(PT[] p, int n) {
        PT o = new PT();
        for (int i = 0; i < n; ++i) {
            o = o.add(p[i]);
        }
        return o.divide(n);
    }

    static double id9(PT p1, double r1, PT p2, double r2) {
        double d = dis(p1, p2);
        if (sgn(d - r1 - r2) >= 0) return 0;
        double p = (r1 + r2 + d) / 2;
        double s = Math.sqrt(p * (p - r1) * (p - r2) * (p - d));
        double l = 2 * s / d;
        return r1 * r1 * Math.asin(l / r1) + r2 * r2 * Math.asin(l / r2) - s * 2;
    }

    static boolean isSimple(PT[] p, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 3; j < n; ++j) {
                if (id0(p[i], p[(i + 1) % n], p[j], p[(j + 1) % n], new PT()) == 1) {
                    return false;
                }
            }
        }
        return true;
    }

    static boolean id1(PT[] p, int n) {
        for (int i = 0; i < n; ++i) {
            if (sgn(vect(p[i], p[(i + 1) % n], p[(i + 2) % n])) <= 0) {
                return false;
            }
        }
        return true;
    }

    static double id10(PT[] p, int n) {
        double S = 0;
        for (int i = 0; i < n; ++i) {
            S += vect(p[i], p[(i + 1) % n]);
        }
        return Math.abs(S) / 2;
    }

    static int id5(PT[] p, int n, PT[] q) {
        Arrays.sort(p, 0, n, new Comparator<PT>() {
            public int compare(PT a, PT b) {
                if (sect(a) != sect(b)) return sect(a) - sect(b);
                double d = vect(a, b);
                return sgn(d) > 0 ? -1 : sgn(d) < 0 ? 1 : 0;
            }
        });
        int m = 0;
        for (int i = 0; i < n; ++i) {
            for (; m >= 2 && sgn(vect(q[m - 2], q[m - 1], p[i])) <= 0; --m);
            q[m++] = p[i];
        }
        for (int i = n - 2, m0 = m; i >= 0; --i) {
            for (; m > m0 && sgn(vect(q[m - 2], q[m - 1], p[i])) <= 0; --m);
            q[m++] = p[i];
        }
        return --m;
    }

    static int id4(HP[] p, int n) {
        p[n++] = new HP(new PT(-INF, -INF), new PT(INF, -INF));
        p[n++] = new HP(new PT(INF, -INF), new PT(INF, INF));
        p[n++] = new HP(new PT(INF, INF), new PT(-INF, INF));
        p[n++] = new HP(new PT(-INF, INF), new PT(-INF, -INF));
        Arrays.sort(p, 0, n, new Comparator<HP>() {
            public int compare(HP a, HP b) {
                if (sect(a.e.subtract(a.s)) != sect(b.e.subtract(b.s))) return sect(a.e.subtract(a.s)) - sect(b.e.subtract(b.s));
                double d = vect(a.s, a.e, b.e.subtract(b.s).add(a.s));
                return sgn(d) > 0 ? -1 : sgn(d) < 0 ? 1 : 0;
            }
        });
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            PT c = new PT();
            for (; r - l >= 2; --r) {
                id6(p[r - 2].s, p[r - 2].e, p[r - 1].s, p[r - 1].e, c);
                if (sgn(vect(p[i].s, p[i].e, c)) > 0) break;
            }
            for (; r - l >= 2; ++l) {
                id6(p[l].s, p[l].e, p[l + 1].s, p[l + 1].e, c);
                if (sgn(vect(p[i].s, p[i].e, c)) > 0) break;
            }
            if (r - l < 2) p[r++] = p[i];
            else {
                id6(p[r - 1].s, p[r - 1].e, p[i].s, p[i].e, c);
                if (sgn(vect(p[0].s, p[0].e, c)) > 0) p[r++] = p[i];
            }
        }
        int m = 0;
        for (int i = l; i < r; ++i) {
            double t = INF;
            t = Math.min(t, Math.abs(p[i].s.x));
            t = Math.min(t, Math.abs(p[i].s.y));
            t = Math.min(t, Math.abs(p[i].e.x));
            t = Math.min(t, Math.abs(p[i].e.y));
            if (sgn(t - INF) != 0) p[m++] = p[i];
        }
        return m;
    }

    static class PT3 {
        double x, y, z;

        PT3(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        PT3() {
            this(0, 0, 0);
        }

        PT3 add(PT3 o) {
            return new PT3(x + o.x, y + o.y, z + o.z);
        }

        PT3 subtract(PT3 o) {
            return new PT3(x - o.x, y - o.y, z - o.z);
        }

        PT3 multiply(double c) {
            return new PT3(x * c, y * c, z * c);
        }

        PT3 divide(double c) {
            return new PT3(x / c, y / c, z / c);
        }

        boolean equals(PT3 o) {
            return Math.abs(x - o.x) < EPS && Math.abs(y - o.y) < EPS && Math.abs(z - o.z) < EPS;
        }
    }

    static void makePlane(PT3 p1, PT3 p2, PT3 p3, double[] a, double[] b, double[] c, double[] d) {
        PT3 q = vect(p1, p2, p3);
        a[0] = q.x;
        b[0] = q.y;
        c[0] = q.z;
        d[0] = -(a[0] * p1.x + b[0] * p1.y + c[0] * p1.z);
    }

    static final int N = 2100;
    static double[] d = new double[N];
    static PT[] p = new PT[N];
    static List<PT> v = new ArrayList<>();

    static boolean cmp1(PT a, PT b) {
        if (sect(a) != sect(b)) return sect(a) < sect(b);
        double d = vect(a, b);
        return sgn(d) > 0;
    }

    static boolean cmp2(PT a, PT b) {
        return sect(a) == sect(b) && sgn(vect(a, b)) == 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            p[i] = new PT(sc.nextDouble(), sc.nextDouble());
        }
        PT g = gravityCenter(p, n);
        for (int i = 0; i < n; ++i) {
            p[i] = p[i].subtract(g);
        }
        Arrays.sort(p, 0, n, new Comparator<PT>() {
            public int compare(PT a, PT b) {
                if (Math.abs(a.x - b.x) > EPS) return a.x < b.x ? -1 : 1;
                if (Math.abs(a.y - b.y) > EPS) return a.y < b.y ? -1 : 1;
                return 0;
            }
        });
        PT q = new PT();
        for (int i = 0; i < n; ++i) {
            int fp = Arrays.binarySearch(p, 0, n, p[i].multiply(-1), new Comparator<PT>() {
                public int compare(PT a, PT b) {
                    if (Math.abs(a.x - b.x) > EPS) return a.x < b.x ? -1 : 1;
                    if (Math.abs(a.y - b.y) > EPS) return a.y < b.y ? -1 : 1;
                    return 0;
                }
            });
            if (fp < 0 || !p[fp].equals(p[i].multiply(-1))) {
                q = p[i];
                break;
            }
            if (i == n - 1) {
                System.out.println("-1");
                return;
            }
        }
        for (int i = 0; i < n; ++i) {
            PT m = p[i].add(q).divide(2);
            PT nv = normalLine(new PT(), m);
            if (sect(nv) >= 3) nv = nv.multiply(-1);
            v.add(nv);
        }
        Collections.sort(v, new Comparator<PT>() {
            public int compare(PT a, PT b) {
                if (sect(a) != sect(b)) return sect(a) - sect(b);
                double d = vect(a, b);
                return sgn(d) > 0 ? -1 : sgn(d) < 0 ? 1 : 0;
            }
        });
        int ans = 0;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                d[j] = scal(v.get(i), proj(p[j], new PT(), v.get(i))) / dis2(v.get(i));
            }
            Arrays.sort(d, 0, n);
            boolean flg = true;
            for (int j = 0; j < n / 2; ++j) {
                if (sgn(d[j] + d[n - 1 - j]) != 0) {
                    flg = false;
                    break;
                }
            }
            if (flg) ++ans;
        }
        System.out.println(ans);
    }
}
