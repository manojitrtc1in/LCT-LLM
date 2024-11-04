import java.util.*;
import java.io.*;
import java.math.*;

public class d {


    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        int n = in.nextInt();
        int m = in.nextInt();

        long startTime = System.currentTimeMillis();
        
        int[][] ids = new int[n][m];
        int[] mapR = new int[n * m];
        int[] mapC = new int[n * m];
        IntList reds = new IntList();
        IntList blacks = new IntList();
        int cid = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ids[i][j] = cid;
                mapR[cid] = i;
                mapC[cid] = j;
                if (((i + j) & 1) == 0)
                    reds.add(cid);
                else
                    blacks.add(cid);
                cid++;
            }
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(j);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(j);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(j);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(j);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(j);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(j);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(j);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(j);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }



        int[] map = new int[blacks.size()];
        for (int i = 0; i < map.length; i++) {
            map[i] = i;
        }
        for (int i = 0; i < map.length / 4; i++) {
            int j = (map.length / 2) - i - 1;
            if (j < 0 || j >= map.length) break;
            int tmp = map[i];
            map[i] = map[j];
            map[j] = tmp;
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }





        map = new int[blacks.size()];
        for (int i = 0; i < map.length; i++) {
            map[i] = i;
        }
        for (int i = 0; i * 4 < map.length; i++) {
            int j = (map.length / 2) - i - 1;
            if (j < 0 || j >= map.length) break;
            int tmp = map[i + (map.length / 2)];
            map[i + (map.length / 2)] = map[j + (map.length / 2)];
            map[j + (map.length / 2)] = tmp;
        }


        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < reds.size(); i++) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = blacks.size() - 1; j >= 0; j--) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            

            

            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        {
            int[][] ans = new int[n][m];
        
            int r = 0;
            int c = 0;
        
            for (int i = reds.size() - 1; i >= 0; i--) {
                int id = reds.get(i);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                int id = blacks.get(map[j]);
                ans[r][c] = id;
                c++;
                if (c == m) {
                    c = 0;
                    r++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }


        int[][] ans = new int[n][m];
        ArrayList<Integer> redss = new ArrayList<>(reds.size());
        ArrayList<Integer> blackss = new ArrayList<>(blacks.size());
            for (int i = 0; i < reds.size(); i++) {
                redss.add(reds.get(i));
            }
            
            for (int j = 0; j < blacks.size(); j++) {
                blackss.add(blacks.get(j));
            }
        while (true) {
			Collections.shuffle(redss);
			Collections.shuffle(blackss);
            long time = System.currentTimeMillis();
            if (time - startTime > 1600) break;
            int r = 0;
            int c = 0;
        
            for (int i = 0; i < redss.size(); i++) {
                int id = redss.get(i);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            for (int j = 0; j < blackss.size(); j++) {
                int id = blackss.get(j);
                ans[r][c] = id;
                r++;
                if (r == n) {
                    r = 0;
                    c++;
                }
            }
            
            if (verify(n, m, ids, mapR, mapC, ans)) {
                out.println("YES");
                print(n, m, ans, out);
                out.close();
                return;
            }
        
        }
        out.println("NO");
        out.close();
    }

    static int[] drs = new int[] {1, 0, -1, 0};
    static int[] dcs = new int[] {0, 1, 0, -1};
    static boolean verify(int n, int m, int[][] ids, int[] mapR, int[] mapC, int[][] ans) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r = mapR[ans[i][j]];
                int c = mapC[ans[i][j]];
                for (int d0 = 0; d0 < 4; d0++) {
                    int ni = i + drs[d0];
                    int nj = j + dcs[d0];
                    if (ni >= n || ni < 0 || nj >= m || nj < 0)
                        continue;
                    for (int d1 = 0; d1 < 4; d1++) {
                        
                        int nr = r + drs[d1];
                        int nc = c + dcs[d1];
                        if (nr >= n || nr < 0 || nc >= m || nc < 0)
                            continue;
                        if (ids[nr][nc] == ans[ni][nj]) {
                            

                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    static void print(int n, int m, int[][] ans, PrintWriter out) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j > 0) out.print(" ");
                out.print(ans[i][j] + 1);
            }
            out.println();
        }
    }

    static Random rand = new Random();
    static void sort(int[] a) {
        int n = a.length;
        for (int i = a.length - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1);
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        Arrays.sort(a);
    }
    static void sort(long[] a) {
        int n = a.length;
        for (int i = a.length - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1);
            long tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        Arrays.sort(a);
    }
    static void sort(double[] a) {
        int n = a.length;
        for (int i = a.length - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1);
            double tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        Arrays.sort(a);
    }
    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
    static long lcm(long a, long b) { return a / gcd(a, b) * b; }
    static long[] id5(long a, long b) {
        if (b == 0) return new long[] { a, 1, 0 };
        long[] ans = id5(b, a % b);
        long temp = ans[1] - ans[2] * (a / b);
        ans[1] = ans[2];  ans[2] = temp;
        return ans;
    }
    static long modInverse(long a, long m) {
        return ((id5(a, m)[1] % m) + m) % m;
    }
    static class IntList {
        static int[] EMPTY = {};
        int[] a = EMPTY;
        int n = 0;
        void add(int v) {
            if (n >= a.length)
                a = Arrays.copyOf(a, (n << 2) + 8);
            a[n++] = v;
        }
        int get(int idx) {
            return a[idx];
        }
        int size() {
            return n;
        }
    }
    static class id4 {
        int[] s, r;	
	public id4(int n) {
            s = new int[n]; r = new int[n];
            for (int i = 0; i < n; i++) s[i] = i;
        }	
        public int find(int i) { return s[i] == i ? i : (s[i] = find(s[i])); }
	public void union(int a, int b) {
            if(r[a = find(a)] == r[b = find(b)]) r[a]++;
            if(r[a] >= r[b]) s[b] = a; else s[a] = b;
        }
    }
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
        public FastScanner(InputStream i) {
            br = new BufferedReader(new InputStreamReader(i));
            st = new StringTokenizer("");
        }
        public String next() throws IOException {
            if(st.hasMoreTokens())
                return st.nextToken();
            else
                st = new StringTokenizer(br.readLine());
            return next();
        }
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        public int[] id0(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextInt() - 1;
            return arr;
        }
        public int[] id3(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextInt();
            return arr;
        }
        public int[][] id3(int n, int m) throws IOException {
            int[][] arr = new int[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    arr[i][j] = nextInt();
            return arr;
        }
        public long[] id6(int n) throws IOException {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextLong();
            return arr;
        }
        public long[][] id6(int n, int m) throws IOException {
            long[][] arr = new long[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    arr[i][j] = nextLong();
            return arr;
        }
        public double[] id2(int n) throws IOException {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextDouble();
            return arr;
        }
        public double[][] id2(int n, int m) throws IOException {
            double[][] arr = new double[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    arr[i][j] = nextDouble();
            return arr;
        }
        public char[][] id1(int n, int m) throws IOException {
            char[][] arr = new char[n][];
            for (int i = 0; i < n; i++)
                arr[i] = next().toCharArray();
            return arr;
        }
    }
}