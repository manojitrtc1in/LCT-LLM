import java.util.*;
import java.io.*;

public class 59eb46ea823a3a580d30425aa06f9a5c_nc {
    static class Pair {
        long x, y;

        Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        Pair add(Pair other) {
            return new Pair(this.x + other.x, this.y + other.y);
        }

        Pair subtract(Pair other) {
            return new Pair(this.x - other.x, this.y - other.y);
        }

        long cross(Pair other) {
            return this.x * other.y - this.y * other.x;
        }

        long dot(Pair other) {
            return this.x * other.x + this.y * other.y;
        }

        double length() {
            return Math.sqrt(this.dot(this));
        }

        double distance(Pair other) {
            return this.subtract(other).length();
        }
    }

    static class Point {
        Pair coordinates;
        int index;

        Point(Pair coordinates, int index) {
            this.coordinates = coordinates;
            this.index = index;
        }
    }

    static void take(int k, List<Point> perm, List<Point> points) {
        int n = points.size();
        for (int i = 0; i < n; i++) {
            if (points.get(i).index == k) {
                Collections.swap(points, i, n - 1);
                break;
            }
        }
        perm.add(points.remove(points.size() - 1));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        int n = Integer.parseInt(br.readLine());
        Point[] p = new Point[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            p[i] = new Point(new Pair(x, y), i);
        }
        String s = br.readLine();
        
        List<Point> perm = new ArrayList<>();
        int firstIdx = 0;
        for (int i = 1; i < n; i++) {
            if (p[i].coordinates.cross(p[firstIdx].coordinates) < 0) {
                firstIdx = i;
            }
        }
        take(firstIdx, perm, new ArrayList<>(Arrays.asList(p)));
        
        for (int i = 0; i < n - 2; i++) {
            Pair q = perm.get(perm.size() - 1).coordinates;
            int best = 0;
            for (int j = 1; j < p.length; j++) {
                if ((((p[best].coordinates.subtract(q)).cross(p[j].coordinates.subtract(q))) > 0) == (s.charAt(i) == 'R'))) {
                    best = j;
                }
            }
            take(p[best].index, perm, new ArrayList<>(Arrays.asList(p)));
        }
        take(p[0].index, perm, new ArrayList<>(Arrays.asList(p)));
        
        for (Point point : perm) {
            out.print((point.index + 1) + " ");
        }
        out.println();
        out.flush();
    }
}
