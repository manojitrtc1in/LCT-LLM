import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        int[][][] a = new int[n][m][3];
        for (int i = 0; i < n; i++) {
            String str = sc.next();
            for (int j = 0; j < m; j++) {
                a[i][j][0] = sc.nextInt();
                a[i][j][1] = sc.nextInt();
                a[i][j][2] = sc.nextInt();
            }
        }
        int val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    val = Math.max(val, refill(k, a[i], a[j]));
                }
            }
        }
        System.out.println(val);
    }

    public static int refill(int k, int[][] a, int[][] b) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((x, y) -> {
            return b[y][1] - a[x][0] - (b[x][0] - a[x][0]) - (b[y][1] - a[y][1]);
        });
        for (int i = 0; i < a.length; i++) {
            pq.offer(i);
        }
        int val = 0;
        while (!pq.isEmpty() && k > 0) {
            int i = pq.poll();
            if (a[i][0] < b[i][1]) {
                int w = Math.min(k, a[i][2]);
                k -= w;
                val += w * (b[i][1] - a[i][0]);
            }
        }
        return val;
    }
}
