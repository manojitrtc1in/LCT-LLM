import java.util.*;
import java.awt.geom.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double xp = sc.nextDouble();
        double yp = sc.nextDouble();
        double vp = sc.nextDouble();
        double x = sc.nextDouble();
        double y = sc.nextDouble();
        double v = sc.nextDouble();
        double r = sc.nextDouble();
        double R = Math.sqrt(xp * xp + yp * yp);
        double ans = 10000000;
        double hi = 1000000;
        double lo = 0.0;
        for (int iter = 0; iter < 100; iter++) {
            double m = lo + (hi - lo) / 2.0;
            if (can(m, xp, yp, vp, x, y, v, r, R)) {
                ans = m;
                hi = m - 1e-9;
            } else {
                lo = m + 1e-9;
            }
        }
        System.out.printf("%.10f\n", ans);
    }

    public static boolean can(double t, double xp, double yp, double vp, double x, double y, double v, double r, double R) {
        double start_x = x;
        double start_y = y;
        double fin_x = xp * Math.cos(t * vp / R) - yp * Math.sin(t * vp / R);
        double fin_y = xp * Math.sin(t * vp / R) + yp * Math.cos(t * vp / R);
        double theta = t * vp / R;
        double a_x = 0;
        double a_y = 0;
        double b_x = 0;
        double b_y = 0;
        boolean intersection = false;
        int num = circleLineIntersection(start_x, start_y, fin_x, fin_y, a_x, a_y, b_x, b_y, 0, 0, r);
        if (num > 0) {
            if (pointOnSegment(start_x, start_y, fin_x, fin_y, a_x, a_y)) {
                intersection = true;
            }
            if (num == 2 && pointOnSegment(start_x, start_y, fin_x, fin_y, b_x, b_y)) {
                intersection = true;
            }
        }
        if (num <= 1 || !intersection) {
            double dis = Math.sqrt((fin_x - start_x) * (fin_x - start_x) + (fin_y - start_y) * (fin_y - start_y));
            return dis < v * t + 1e-9;
        }
        double dis = calc(start_x, start_y, fin_x, fin_y, r);
        return dis < v * t + 1e-9;
    }

    public static int circleLineIntersection(double x1, double y1, double x2, double y2, double cx, double cy, double r) {
        double dx = x2 - x1;
        double dy = y2 - y1;
        double A = dx * dx + dy * dy;
        double B = 2 * (dx * (x1 - cx) + dy * (y1 - cy));
        double C = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) - r * r;
        double det = B * B - 4 * A * C;
        if (Math.abs(det) < 1e-9) {
            det = 0;
        }
        if (det < 0) {
            return 0;
        } else if (det == 0) {
            return 1;
        } else {
            return 2;
        }
    }

    public static boolean pointOnSegment(double x1, double y1, double x2, double y2, double px, double py) {
        double crossproduct = (py - y1) * (x2 - x1) - (px - x1) * (y2 - y1);
        if (Math.abs(crossproduct) > 1e-9) {
            return false;
        }
        double dotproduct = (px - x1) * (x2 - x1) + (py - y1) * (y2 - y1);
        if (dotproduct < 0) {
            return false;
        }
        double squaredlengthba = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        if (dotproduct > squaredlengthba) {
            return false;
        }
        return true;
    }

    public static double calc(double start_x, double start_y, double fin_x, double fin_y, double r) {
        double a_x = 0;
        double a_y = 0;
        double b_x = 0;
        double b_y = 0;
        circleLineIntersection(start_x, start_y, fin_x, fin_y, 0, 0, r, a_x, a_y, b_x, b_y);
        double arc = calcArc(a_x, a_y, b_x, b_y, r);
        double res = arc + Math.abs(Math.sqrt((a_x - start_x) * (a_x - start_x) + (a_y - start_y) * (a_y - start_y))) + Math.abs(Math.sqrt((b_x - fin_x) * (b_x - fin_x) + (b_y - fin_y) * (b_y - fin_y)));
        return res;
    }

    public static double calcArc(double a_x, double a_y, double b_x, double b_y, double r) {
        double theta = Math.abs(Math.atan2(b_y, b_x) - Math.atan2(a_y, a_x));
        if (theta > Math.PI) {
            theta = 2 * Math.PI - theta;
        }
        double res = theta * r;
        return res;
    }

    public static void circleLineIntersection(double x1, double y1, double x2, double y2, double cx, double cy, double r, double a_x, double a_y, double b_x, double b_y) {
        double dx = x2 - x1;
        double dy = y2 - y1;
        double A = dx * dx + dy * dy;
        double B = 2 * (dx * (x1 - cx) + dy * (y1 - cy));
        double C = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) - r * r;
        double det = B * B - 4 * A * C;
        det = Math.sqrt(det);
        double t1 = (-B + det) / (2 * A);
        double t2 = (-B - det) / (2 * A);
        a_x = x1 + t1 * (x2 - x1);
        a_y = y1 + t1 * (y2 - y1);
        b_x = x1 + t2 * (x2 - x1);
        b_y = y1 + t2 * (y2 - y1);
    }
}
