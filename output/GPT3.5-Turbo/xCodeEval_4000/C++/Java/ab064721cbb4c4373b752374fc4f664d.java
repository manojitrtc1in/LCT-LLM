import java.util.*;
import java.io.*;

class Main {
    static class Point {
        int x, y, i;

        Point() {}

        Point(int x, int y, int i) {
            this.x = x;
            this.y = y;
            this.i = i;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    static int n;
    static Point[] a;
    static String s;

    static boolean read() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            n = Integer.parseInt(br.readLine());
            a = new Point[n];
            for (int i = 0; i < n; i++) {
                String[] input = br.readLine().split(" ");
                int x = Integer.parseInt(input[0]);
                int y = Integer.parseInt(input[1]);
                a[i] = new Point(x, y, i + 1);
            }
            s = br.readLine();
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    static Point subtract(Point a, Point b) {
        return new Point(a.x - b.x, a.y - b.y, -1);
    }

    static Point add(Point a, Point b) {
        return new Point(a.x + b.x, a.y + b.y, -1);
    }

    static boolean isEqual(Point a, Point b) {
        return (a.x == b.x && a.y == b.y);
    }

    static long squaredDistance(Point a, Point b) {
        return (long) (Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2));
    }

    static long dotProduct(Point a, Point b) {
        return a.x * (long) b.x + a.y * (long) b.y;
    }

    static long crossProduct(Point a, Point b) {
        return a.x * (long) b.y - a.y * (long) b.x;
    }

    static List<Point> build() {
        if (n <= 1) {
            return new ArrayList<>(Arrays.asList(a).subList(0, n));
        }

        List<Point> up = new ArrayList<>();
        List<Point> dw = new ArrayList<>();
        up.add(a[0]);
        dw.add(a[0]);

        for (int i = 1; i < n; i++) {
            if (i == n - 1 || crossProduct(subtract(a[n - 1], a[0]), subtract(a[i], a[0])) >= 0) {
                while (up.size() > 1 && crossProduct(subtract(a[i], up.get(up.size() - 2)), subtract(up.get(up.size() - 1), up.get(up.size() - 2))) < 0) {
                    up.remove(up.size() - 1);
                }
                up.add(a[i]);
            }
            if (i == n - 1 || crossProduct(subtract(a[n - 1], a[0]), subtract(a[i], a[0])) < 0) {
                while (dw.size() > 1 && crossProduct(subtract(a[i], dw.get(dw.size() - 2)), subtract(dw.get(dw.size() - 1), dw.get(dw.size() - 2))) > 0) {
                    dw.remove(dw.size() - 1);
                }
                dw.add(a[i]);
            }
        }

        List<Point> res = new ArrayList<>(up);
        for (int i = dw.size() - 2; i >= 1; i--) {
            res.add(dw.get(i));
        }

        return res;
    }

    static void solve() {
        Arrays.sort(a, new Comparator<Point>() {
            public int compare(Point p1, Point p2) {
                if (p1.x != p2.x) {
                    return p1.x - p2.x;
                }
                return p1.y - p2.y;
            }
        });

        List<Point> ans = new ArrayList<>();
        List<Point> ch = build();
        ans.add(ch.get(0));
        if (s.charAt(0) == 'L') {
            ans.add(ch.get(ch.size() - 1));
        } else {
            ans.add(ch.get(1));
        }

        for (int i = 0; i < s.length(); i++) {
            int x = Arrays.asList(a).indexOf(ans.get(ans.size() - 2));
            for (int j = x + 1; j < n; j++) {
                a[j - 1] = a[j];
            }
            n--;
            ch = build();
            int pos = ch.indexOf(ans.get(ans.size() - 1));
            if (s.charAt(i + 1) == 'L') {
                ans.add(ch.get((pos - 1 + ch.size()) % ch.size()));
            } else {
                ans.add(ch.get((pos + 1) % ch.size()));
            }
        }

        for (Point point : ans) {
            System.out.print(point.i + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String line;
            while ((line = br.readLine()) != null) {
                if (line.equals("")) {
                    continue;
                }
                n = Integer.parseInt(line);
                a = new Point[n];
                for (int i = 0; i < n; i++) {
                    String[] input = br.readLine().split(" ");
                    int x = Integer.parseInt(input[0]);
                    int y = Integer.parseInt(input[1]);
                    a[i] = new Point(x, y, i + 1);
                }
                s = br.readLine();
                solve();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
