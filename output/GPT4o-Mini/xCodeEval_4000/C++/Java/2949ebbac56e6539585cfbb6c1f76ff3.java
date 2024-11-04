import java.util.*;

class Main {
    static final double PI = Math.acos(-1);
    static final double INF = 1e10;
    static final double EPS = 1e-8;

    static double sqr(double v) { return v * v; }
    static int sgn(double v) { return v < -EPS ? -1 : v > EPS ? 1 : 0; }

    static class PT {
        double x, y;
        PT(double x, double y) { this.x = x; this.y = y; }
        PT() { this(0, 0); }

        PT add(PT o) { return new PT(x + o.x, y + o.y); }
        PT subtract(PT o) { return new PT(x - o.x, y - o.y); }
        PT multiply(double c) { return new PT(x * c, y * c); }
        PT divide(double c) { return new PT(x / c, y / c); }
        PT negate() { return new PT(-x, -y); }

        boolean lessThan(PT o) {
            return sgn(x - o.x) < 0 || (sgn(x - o.x) == 0 && sgn(y - o.y) < 0);
        }
        boolean equals(PT o) { return sgn(x - o.x) == 0 && sgn(y - o.y) == 0; }
        boolean notEquals(PT o) { return sgn(x - o.x) != 0 || sgn(y - o.y) != 0; }
    }

    static double dis(PT v) { return Math.sqrt(sqr(v.x) + sqr(v.y)); }
    static double dis2(PT v) { return sqr(v.x) + sqr(v.y); }
    static double dis(PT p1, PT p2) { return dis(p1.subtract(p2)); }
    static double dis2(PT p1, PT p2) { return dis2(p1.subtract(p2)); }

    static double vect(PT v1, PT v2) { return v1.x * v2.y - v2.x * v1.y; }
    static double scal(PT v1, PT v2) { return v1.x * v2.x + v1.y * v2.y; }

    static int sect(PT p) {
        if (sgn(p.x) == 0 && sgn(p.y) == 0) return 0;
        if (sgn(p.x) == 0) return sgn(p.y) > 0 ? 2 : 4;
        if (sgn(p.y) == 0) return sgn(p.x) > 0 ? 1 : 3;
        if (sgn(p.x) == 1) return sgn(p.y) == 1 ? 1 : 4;
        return sgn(p.y) == 1 ? 2 : 3;
    }

    static double ang(PT v) { return Math.atan2(v.y, v.x); }
    static double ang(PT p1, PT p2) { return ang(p2.subtract(p1)); }

    static PT proj(PT p, PT p1, PT p2) {
        return p1.add(p2.subtract(p1).multiply(scal(p1, p, p2) / dis2(p1, p2)));
    }

    static PT normalLine(PT p1, PT p2) { return new PT(-(p2.y - p1.y), p2.x - p1.x); }

    static PT gravityCenter(PT[] p, int n) {
        PT o = new PT();
        for (int i = 0; i < n; ++i) o = o.add(p[i]);
        return o.divide(n);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        PT[] p = new PT[n];
        for (int i = 0; i < n; ++i) p[i] = new PT(scanner.nextDouble(), scanner.nextDouble());
        
        PT g = gravityCenter(p, n);
        for (int i = 0; i < n; ++i) p[i] = p[i].subtract(g);
        Arrays.sort(p, Comparator.comparingDouble(a -> a.x));

        PT q = null;
        for (int i = 0; i < n; ++i) {
            int fp = Arrays.binarySearch(p, new PT(-p[i].x, -p[i].y), Comparator.comparingDouble(a -> a.x));
            if (fp < 0) fp = -fp - 1;
            if (fp >= n || !p[fp].equals(new PT(-p[i].x, -p[i].y))) {
                q = p[i];
                break;
            }
            if (i == n - 1) {
                System.out.println("-1");
                return;
            }
        }

        List<PT> v = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            PT m = p[i].add(q).divide(2);
            PT nv = normalLine(new PT(), m);
            if (sect(nv) >= 3) nv = nv.negate();
            v.add(nv);
        }

        Collections.sort(v, (a, b) -> {
            if (sect(a) != sect(b)) return Integer.compare(sect(a), sect(b));
            double d = vect(a, b);
            return -sgn(d);
        });

        v = new ArrayList<>(new HashSet<>(v));
        int ans = 0;
        double[] d = new double[n];
        for (PT vi : v) {
            for (int j = 0; j < n; ++j)
                d[j] = scal(vi, proj(p[j], new PT(), vi)) / dis(vi);
            Arrays.sort(d);
            boolean flg = true;
            for (int j = 0; j < n / 2; ++j)
                if (sgn(d[j] + d[n - 1 - j]) != 0) flg = false;
            ans += flg ? 1 : 0;
        }
        System.out.println(ans);
    }
}
