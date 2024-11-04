import java.util.*;

class Main {
    static class Point implements Comparable<Point> {
        int x, y;
        
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        public int compareTo(Point other) {
            return Integer.compare(this.x * other.y, this.y * other.x);
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Point[] p = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            p[i] = new Point(x, y);
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].x < p[cur].x || (p[i].x == p[cur].x && p[i].y < p[cur].y)) {
                cur = i;
            }
        }
        String s = scanner.next();
        s += "R";
        List<Integer> ans = new ArrayList<>();
        ans.add(cur);
        boolean[] used = new boolean[n];
        Point[] a = new Point[n];
        for (int i = 0; i + 1 < n; i++) {
            used[cur] = true;
            Point zero = p[cur];
            for (int j = 0; j < n; j++) {
                a[j] = new Point(p[j].x - zero.x, p[j].y - zero.y);
            }
            int idx = -1;
            for (int j = 0; j < n; j++) {
                if (!used[j]) {
                    if (idx == -1) {
                        idx = j;
                    } else {
                        if (s.charAt(i) == 'R' && a[j].compareTo(a[idx]) < 0) {
                            idx = j;
                        }
                        if (s.charAt(i) == 'L' && a[idx].compareTo(a[j]) < 0) {
                            idx = j;
                        }
                    }
                }
            }
            cur = idx;
            ans.add(cur);
        }
        for (int x : ans) {
            System.out.print((x + 1) + " ");
        }
        System.out.println();
    }
}
