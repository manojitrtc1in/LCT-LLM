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
    
    static class Pair<A, B> {
        A first;
        B second;
        
        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
        
        public String toString() {
            return "(" + first + ", " + second + ")";
        }
    }
    
    static int INF = (int)1e9;
    static long INF64 = (long)1e18;
    static int MOD = INF + 7;
    static double EPS = 1e-9;
    static double PI = Math.acos(-1.0);
    
    static int N = 2000 + 7;
    
    static Point[] a = new Point[N];
    static String s;
    
    static boolean read() {
        FastScanner sc = new FastScanner();
        if (!sc.hasNext()) return false;
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = new Point(sc.nextInt(), sc.nextInt(), i + 1);
        }
        s = sc.next();
        return true;
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
        return (long)(a.x - b.x) * (a.x - b.x) + (long)(a.y - b.y) * (a.y - b.y);
    }
    
    static long dotProduct(Point a, Point b) {
        return (long)a.x * b.x + (long)a.y * b.y;
    }
    
    static long crossProduct(Point a, Point b) {
        return (long)a.x * b.y - (long)a.y * b.x;
    }
    
    static ArrayList<Point> build() {
        int n = a.length;
        if (n <= 1) {
            ArrayList<Point> res = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                res.add(a[i]);
            }
            return res;
        }
        
        ArrayList<Point> up = new ArrayList<>();
        ArrayList<Point> dw = new ArrayList<>();
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
        
        ArrayList<Point> res = new ArrayList<>(up);
        for (int i = dw.size() - 2; i >= 1; i--) {
            res.add(dw.get(i));
        }
        
        return res;
    }
    
    static ArrayList<Point>[] chs = new ArrayList[N];
    
    static void solve() {
        Arrays.sort(a, 0, a.length);
        HashSet<Point> cur = new HashSet<>(Arrays.asList(a).subList(0, a.length));
        ArrayList<Point> ans = new ArrayList<>();
        
        ArrayList<Point> ch = build();
        ans.add(ch.get(0));
        if (s.charAt(0) == 'L') {
            ans.add(ch.get(ch.size() - 1));
        } else {
            ans.add(ch.get(1));
        }
        cur.remove(ch.get(0));
        
        for (int i = 0; i < s.length(); i++) {
            int n = 0;
            for (Point it : cur) {
                a[n++] = it;
            }
            ArrayList<Point> ch = build();
            int pos = ch.indexOf(ans.get(ans.size() - 1));
            if (s.charAt(i + 1) == 'L') {
                ans.add(ch.get((pos - 1 + ch.size()) % ch.size()));
            } else {
                ans.add(ch.get((pos + 1) % ch.size()));
            }
            cur.remove(ans.get(ans.size() - 2));
        }
        
        for (Point it : ans) {
            System.out.print(it.i + " ");
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        while (read()) {
            solve();
        }
    }
    
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
        
        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        
        int nextInt() {
            return Integer.parseInt(next());
        }
        
        long nextLong() {
            return Long.parseLong(next());
        }
        
        double nextDouble() {
            return Double.parseDouble(next());
        }
        
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
        
        boolean hasNext() {
            try {
                return br.ready();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return false;
        }
    }
}
