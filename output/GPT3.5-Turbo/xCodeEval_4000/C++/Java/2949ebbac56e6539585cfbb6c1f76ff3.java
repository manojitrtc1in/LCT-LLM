import java.util.*;

class Main {
    static class PT {
        double x, y;

        PT(double x, double y) {
            this.x = x;
            this.y = y;
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

        double distance() {
            return Math.sqrt(x * x + y * y);
        }

        double distance(PT p) {
            return subtract(p).distance();
        }

        double distanceSquared() {
            return x * x + y * y;
        }

        double distanceSquared(PT p) {
            return subtract(p).distanceSquared();
        }

        PT project(PT p1, PT p2) {
            PT v = p2.subtract(p1);
            double t = v.dotProduct(subtract(p1)) / v.distanceSquared();
            return p1.add(v.multiply(t));
        }

        PT rotate(double t) {
            return new PT(x * Math.cos(t) - y * Math.sin(t), x * Math.sin(t) + y * Math.cos(t));
        }

        PT rotate(PT o, double t) {
            return subtract(o).rotate(t).add(o);
        }

        PT polar(PT o, double r, double t) {
            return o.add(new PT(r * Math.cos(t), r * Math.sin(t)));
        }

        double dotProduct(PT v) {
            return x * v.x + y * v.y;
        }

        double crossProduct(PT v) {
            return x * v.y - y * v.x;
        }

        int sector() {
            if (x == 0 && y == 0) return 0;
            if (x == 0) return y > 0 ? 2 : 4;
            if (y == 0) return x > 0 ? 1 : 3;
            if (x > 0) return y > 0 ? 1 : 4;
            return y > 0 ? 2 : 3;
        }

        double angle() {
            return Math.atan2(y, x);
        }

        double angle(PT p) {
            return p.subtract(this).angle();
        }

        double angle(PT p, PT p1, PT p2) {
            double dy = p.subtract(this).crossProduct(p1.subtract(this));
            double dx = p.subtract(this).dotProduct(p1.subtract(this));
            if (dy == 0) dy = 0;
            if (dx == 0) dx = 0;
            return Math.atan2(dy, dx);
        }

        double angle2(PT p, PT p1, PT p2) {
            return Math.acos(p.subtract(this).dotProduct(p1.subtract(this)) / distance(p) / distance(p2));
        }

        double distanceToLine(PT p1, PT p2) {
            return Math.abs(p.subtract(p1).crossProduct(p2.subtract(p1))) / p1.distance(p2);
        }

        double distanceToSegment(PT p1, PT p2) {
            if (p1.subtract(p).dotProduct(p2.subtract(p)) < 0) return distance(p1);
            if (p2.subtract(p).dotProduct(p1.subtract(p)) < 0) return distance(p2);
            return distanceToLine(p1, p2);
        }

        boolean onLine(PT p1, PT p2) {
            return subtract(p1).crossProduct(p2.subtract(p1)) == 0;
        }

        boolean onSegment(PT p1, PT p2) {
            return onLine(p1, p2) && subtract(p1).dotProduct(p2.subtract(p1)) <= 0;
        }

        boolean inAngle(PT p, PT p0, PT p1, PT p2) {
            double d0 = p0.subtract(p1).crossProduct(p2.subtract(p1));
            double d1 = p0.subtract(p1).crossProduct(p.subtract(p1));
            double d2 = p0.subtract(p2).crossProduct(p.subtract(p2));
            if (d0 >= 0) return d1 >= 0 && d2 <= 0;
            return d1 >= 0 || d2 <= 0;
        }

        int inConvex(PT[] q, int n) {
            PT o = new PT((q[0].x + q[1].x + q[2].x) / 3, (q[0].y + q[1].y + q[2].y) / 3);
            if (o.equals(this)) return 1;
            int l = 0, h = n;
            while (h - l > 1) {
                int m = (l + h) / 2;
                if (inAngle(q[l % n], o, q[m % n], this)) h = m;
                else l = m;
            }
            l %= n;
            h %= n;
            if (vect(q[l], q[h], this) == 0) return 2;
            return vect(q[l], q[h], o) * vect(q[l], q[h], this) > 0 ? 0 : 2;
        }

        int positionLineLine(PT p1, PT p2, PT p3, PT p4, PT p) {
            double s1 = p1.subtract(p2).crossProduct(p3.subtract(p2));
            double s2 = p1.subtract(p2).crossProduct(p4.subtract(p2));
            if (s1 == s2) return s1 != 0 ? 0 : 2;
            p = p3.subtract(p4).multiply(s1).subtract(p1.subtract(p2).multiply(s2)).divide(s1 - s2);
            return 1;
        }

        int positionSegmentSegment(PT p1, PT p2, PT p3, PT p4, PT p) {
            int ret = positionLineLine(p1, p2, p3, p4, p);
            if (ret == 1) return onSegment(p, p1, p2) && onSegment(p, p3, p4) ? 1 : 0;
            if (ret == 2 && (onSegment(p1, p3, p4) || onSegment(p2, p3, p4))) return 2;
            return 0;
        }

        int inPolygon(PT[] q, int n) {
            int c = 0;
            PT r = new PT(Double.POSITIVE_INFINITY, Double.POSITIVE_INFINITY * Math.sqrt(3));
            for (int i = 0; i < n; i++) {
                if (onLine(q[i], q[(i + 1) % n])) return 2;
                if (positionSegmentSegment(p, r, q[i], q[(i + 1) % n], new PT()) == 1) c++;
            }
            return c % 2;
        }

        int positionCircleLine(PT o, double r, PT p1, PT p2, PT[] q) {
            double a = p1.distanceSquared(p2);
            double b = p1.dotProduct(o, p2);
            double c = p1.distanceSquared(o) - r * r;
            double d2 = b * b - a * c;
            if (d2 < 0) return 0;
            double d = Math.sqrt(Math.abs(d2));
            if (q != null) q[0] = p1.add(p2.subtract(p1).multiply((b + d) / a));
            if (d2 == 0) return 1;
            if (q != null) q[1] = p1.add(p2.subtract(p1).multiply((b - d) / a));
            return 2;
        }

        int positionCircleCircle(PT o1, double r1, PT o2, double r2, PT[] q) {
            if (o1.equals(o2)) return r1 == r2 ? 3 : 0;
            double d = o1.distance(o2);
            double e = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
            double f2 = r1 * r1 - e * e;
            if (f2 < 0) return 0;
            double f = Math.sqrt(Math.abs(f2));
            double dx = o2.x - o1.x, dy = o2.y - o1.y;
            if (q != null) q[0] = new PT(o1.x + (e * dx - f * dy) / d, o1.y + (e * dy + f * dx) / d);
            if (f2 == 0) return 1;
            if (q != null) q[1] = new PT(o1.x + (e * dx + f * dy) / d, o1.y + (e * dy - f * dx) / d);
            return 2;
        }

        PT normalLine(PT p1, PT p2) {
            return new PT(-(p2.y - p1.y), p2.x - p1.x);
        }

        PT innerCenter(PT a, PT b, PT c) {
            double A = b.distance(c);
            double B = c.distance(a);
            double C = a.distance(b);
            return new PT((A * a.x + B * b.x + C * c.x) / (A + B + C), (A * a.y + B * b.y + C * c.y) / (A + B + C));
        }

        PT outerCenter(PT a, PT b, PT c) {
            double d1 = (a.distanceSquared() - b.distanceSquared()) / 2;
            double d2 = (a.distanceSquared() - c.distanceSquared()) / 2;
            double x = (d1 * (a.y - c.y) - d2 * (a.y - b.y)) / a.subtract(b).crossProduct(a.subtract(c));
            double y = (d1 * (a.x - c.x) - d2 * (a.x - b.x)) / a.subtract(c).crossProduct(a.subtract(b));
            return new PT(x, y);
        }

        PT gravityCenter(PT[] p) {
            PT o = new PT();
            for (PT pt : p) {
                o = o.add(pt);
            }
            return o.divide(p.length);
        }

        double circleSharedArea(PT p1, double r1, PT p2, double r2) {
            double d = p1.distance(p2);
            if (d >= r1 + r2) return 0;
            double p = (r1 + r2 + d) / 2;
            double s = Math.sqrt(p * (p - r1) * (p - r2) * (p - d));
            double l = 2 * s / d;
            return r1 * r1 * Math.asin(l / r1) + r2 * r2 * Math.asin(l / r2) - s * 2;
        }

        boolean isSimple(PT[] p) {
            for (int i = 0; i < p.length; i++) {
                for (int j = i + 3; j < p.length; j++) {
                    if (p[i].equals(p[j])) return false;
                }
            }
            return true;
        }

        boolean isConvex(PT[] p) {
            for (int i = 0; i < p.length; i++) {
                if (p[i].subtract(p[(i + 1) % p.length]).crossProduct(p[(i + 2) % p.length].subtract(p[(i + 1) % p.length])) <= 0) return false;
            }
            return true;
        }

        double polygonArea(PT[] p) {
            double S = 0;
            for (int i = 0; i < p.length; i++) {
                S += p[i].subtract(p[(i + 1) % p.length]).crossProduct(p[i]);
            }
            return Math.abs(S) / 2;
        }

        int convexHull(PT[] p, PT[] q) {
            Arrays.sort(p, new Comparator<PT>() {
                public int compare(PT a, PT b) {
                    if (a.sector() != b.sector()) return a.sector() - b.sector();
                    double d = a.crossProduct(b);
                    return d > 0 ? -1 : d < 0 ? 1 : 0;
                }
            });
            int n = p.length;
            int m = 0;
            for (int i = 0; i < n; i++) {
                for (; m >= 2 && p[i].subtract(q[m - 2]).crossProduct(q[m - 1].subtract(q[m - 2])) <= 0; m--);
                q[m++] = p[i];
            }
            for (int i = n - 2, m0 = m; i >= 0; i--) {
                for (; m > m0 && p[i].subtract(q[m - 1]).crossProduct(q[m - 2].subtract(q[m - 1])) <= 0; m--);
                q[m++] = p[i];
            }
            return m - 1;
        }

        static class HP {
            PT s, e;

            HP(PT s, PT e) {
                this.s = s;
                this.e = e;
            }

            boolean equals(HP o) {
                return s.equals(o.s) && e.equals(o.e);
            }
        }

        static class HPComparator implements Comparator<HP> {
            public int compare(HP a, HP b) {
                if (a.e.subtract(a.s).crossProduct(b.e.subtract(b.s)) != 0) return a.e.subtract(a.s).crossProduct(b.e.subtract(b.s)) > 0 ? -1 : 1;
                return a.sector() - b.sector();
            }
        }

        int halfPlaneIntersection(HP[] p, int n) {
            p[n++] = new HP(new PT(Double.NEGATIVE_INFINITY, Double.NEGATIVE_INFINITY), new PT(Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY));
            p[n++] = new HP(new PT(Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY), new PT(Double.POSITIVE_INFINITY, Double.POSITIVE_INFINITY));
            p[n++] = new HP(new PT(Double.POSITIVE_INFINITY, Double.POSITIVE_INFINITY), new PT(Double.NEGATIVE_INFINITY, Double.POSITIVE_INFINITY));
            p[n++] = new HP(new PT(Double.NEGATIVE_INFINITY, Double.POSITIVE_INFINITY), new PT(Double.NEGATIVE_INFINITY, Double.NEGATIVE_INFINITY));
            Arrays.sort(p, 0, n, new HPComparator());
            int m = 0;
            for (int i = 0; i < n; i++) {
                PT c = new PT();
                for (; m >= 2; m--) {
                    if (p[m - 2].s.positionLineLine(p[m - 2].s, p[m - 2].e, p[m - 1].s, p[m - 1].e, c) == 1 && c.subtract(p[i].s).crossProduct(p[i].e.subtract(p[i].s)) > 0) break;
                }
                for (; m >= 2; m--) {
                    if (p[m - 1].s.positionLineLine(p[m - 1].s, p[m - 1].e, p[m].s, p[m].e, c) == 1 && c.subtract(p[i].s).crossProduct(p[i].e.subtract(p[i].s)) > 0) break;
                }
                if (m < 2) p[m++] = p[i];
                else {
                    p[m - 1].s.positionLineLine(p[m - 1].s, p[m - 1].e, p[i].s, p[i].e, c);
                    if (c.subtract(p[0].s).crossProduct(p[0].e.subtract(p[0].s)) > 0) p[m++] = p[i];
                }
            }
            int k = 0;
            for (int i = 0; i < m; i++) {
                double t = Double.POSITIVE_INFINITY;
                t = Math.min(t, Math.abs(p[i].s.x));
                t = Math.min(t, Math.abs(p[i].s.y));
                t = Math.min(t, Math.abs(p[i].e.x));
                t = Math.min(t, Math.abs(p[i].e.y));
                if (t != Double.POSITIVE_INFINITY) p[k++] = p[i];
            }
            return k;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        PT[] p = new PT[n];
        for (int i = 0; i < n; i++) {
            p[i] = new PT(sc.nextDouble(), sc.nextDouble());
        }
        PT g = PT.gravityCenter(p);
        for (int i = 0; i < n; i++) {
            p[i] = p[i].subtract(g);
        }
        Arrays.sort(p, new Comparator<PT>() {
            public int compare(PT a, PT b) {
                if (a.sector() != b.sector()) return a.sector() - b.sector();
                double d = a.crossProduct(b);
                return d > 0 ? -1 : d < 0 ? 1 : 0;
            }
        });
        PT q = null;
        for (int i = 0; i < n; i++) {
            int fp = Arrays.binarySearch(p, PT.multiply(-1, p[i]), new Comparator<PT>() {
                public int compare(PT a, PT b) {
                    if (a.sector() != b.sector()) return a.sector() - b.sector();
                    double d = a.crossProduct(b);
                    return d > 0 ? -1 : d < 0 ? 1 : 0;
                }
            });
            if (fp < 0 || !p[fp].equals(PT.multiply(-1, p[i]))) {
                q = p[i];
                break;
            }
            if (i == n - 1) {
                System.out.println("-1");
                return;
            }
        }
        PT[] v = new PT[n];
        int m = 0;
        for (int i = 0; i < n; i++) {
            PT m1 = PT.divide(PT.add(p[i], q), 2);
            PT nv = PT.normalLine(new PT(), m1);
            if (nv.sector() >= 3) nv = PT.multiply(-1, nv);
            v[m++] = nv;
        }
        Arrays.sort(v, 0, m, new Comparator<PT>() {
            public int compare(PT a, PT b) {
                if (a.sector() != b.sector()) return a.sector() - b.sector();
                return a.crossProduct(b) == 0 ? 0 : a.crossProduct(b) > 0 ? -1 : 1;
            }
        });
        int ans = 0;
        for (int i = 0; i < m; i++) {
            double[] d = new double[n];
            for (int j = 0; j < n; j++) {
                d[j] = v[i].dotProduct(PT.project(p[j], new PT(), v[i])) / v[i].distanceSquared();
            }
            Arrays.sort(d);
            boolean flg = true;
            for (int j = 0; j < n / 2; j++) {
                if (d[j] + d[n - 1 - j] != 0) {
                    flg = false;
                    break;
                }
            }
            if (flg) ans++;
        }
        System.out.println(ans);
    }
}
