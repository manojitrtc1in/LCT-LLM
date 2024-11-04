


import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class G {
    static InputReader in;
    static PrintWriter out;

    public static void main(String[] args) {
        

        id10(false);
        solve(in.nextInt());
        

    }  
    
    
    
    

    static int mod = (int)1e9 + 7, n;
    static List<int[]> idx;
    static int[] id16, id12;
    static void solve(int testCnt) {
        for (int testNumber = 0; testNumber < testCnt; testNumber++) {
            String s = in.next(), t = in.next();
            if(s.length() < t.length()) {
                out.println(0 + " " + 1);
            }
            else {
                n = s.length();
                idx = new ArrayList<>();
                int i = 0;
                while(i <= s.length() - t.length()) {
                    int j = s.indexOf(t, i);
                    if(j < 0) break;
                    idx.add(new int[]{j, j + t.length() - 1});
                    i = j + 1;
                }
                id16 = new int[n];
                id12 = new int[n];




                long minMoves = 0, numMoves = 1;
                int prev = 0;
                for(int k = 0; k < idx.size() - 1; k++) {
                    if(idx.get(k)[1] < idx.get(k + 1)[0]) {
                        long[] ans = compute(prev, k);
                        minMoves += ans[0];
                        numMoves = numMoves * ans[1] % mod;
                        prev = k + 1;
                    }
                }
                if(prev <= idx.size() - 1) {
                    long[] ans = compute(prev, idx.size() - 1);
                    minMoves += ans[0];
                    numMoves = numMoves * ans[1] % mod;
                }
                out.println(minMoves + " " + numMoves);
            }
        }
        out.close();
    }

    static long[] compute(int l, int r) {
        

        int cnt = r - l + 1;
        int[][] id14 = new int[cnt][cnt];
        for(int i = 0; i < id14.length; i++) {
            Arrays.fill(id14[i], -1);
        }
        for(int i = l; i <= r; i++) {
            id16[i] = id8(l, r, i);
            id12[i] = id1(l, r, i);
        }
        id2(l, r, l, id14);
        int minMoves = id14[0][r - l];
        long[][] id21 = new long[cnt][cnt];
        for(int i = 0; i < id21.length; i++) {
            Arrays.fill(id21[i], -1);
        }
        long seqCnt = id19(l, r, l, id14, id21);
        return new long[]{minMoves, seqCnt};
    }

    static long id19(int l, int r, int offset, int[][] id14, long[][] id21) {
        if(l > r) return 1;
        if(id21[l - offset][r - offset] < 0) {
            long cnt = 0;






            int id5 = id12[l];
            for (int i = l; i < id5; i++) {
                

                

                

                int j = id12[i];
                int remainMoves = j <= r ? id14[j - offset][r - offset] : 0;
                if (remainMoves + 1 == id14[l - offset][r - offset]) {
                    cnt = (cnt + id19(j, r, offset, id14, id21)) % mod;
                }
            }
            id21[l - offset][r - offset] = cnt;
        }
        return id21[l - offset][r - offset];
    }

    static int id1(int l, int r, int i) {
        while(l < r - 1) {
            int mid = l + (r - l) / 2;
            if(idx.get(mid)[0] > idx.get(i)[1]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        if(idx.get(l)[0] > idx.get(i)[1]) {
            return l;
        }
        else if(idx.get(r)[0] > idx.get(i)[1]) {
            return r;
        }
        return r + 1;
    }

    static int id8(int l, int r, int i) {
        while(l < r - 1) {
            int mid = l + (r - l) / 2;
            if(idx.get(mid)[1] < idx.get(i)[0]) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        if(idx.get(r)[1] < idx.get(i)[0]) {
            return r;
        }
        else if(idx.get(l)[1] < idx.get(i)[0]) {
            return l;
        }
        return l - 1;
    }
    static int id2(int l, int r, int offset, int[][] id14) {
        int i = l - offset, j = r - offset;
        if(i > j) return 0;
        if(id14[i][j] < 0) {
            id14[i][j] = idx.size() + 1;
            for(int k = l; k <= r; k++) {






                int j1 = id16[k];
                int leftMoves = id2(l, j1, offset, id14);






                int j2 = id12[k];
                int rightMoves = id2(j2, r, offset, id14);
                id14[i][j] = min(id14[i][j], 1 + leftMoves + rightMoves);
            }
        }
        return id14[i][j];
    }

    static void id10(boolean test) {
        if (test) {
            try {
                in = new InputReader(new FileInputStream("src/input.in"));
                out = new PrintWriter(new FileOutputStream("src/output.out"));
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            in = new InputReader(System.in);
            out = new PrintWriter(System.out);
        }
    }

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        InputReader(InputStream stream) {
            try {
                br = new BufferedReader(new InputStreamReader(stream), 32768);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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

        Integer[] id9(int n) {
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        int[] id20(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        int[] id17(int n) {
            int[] a = new int[n + 1];
            for (int i = 1; i <= n; i++) a[i] = nextInt();
            return a;
        }

        Long[] id24(int n) {
            Long[] a = new Long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }

        long[] id7(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }

        long[] id18(int n) {
            long[] a = new long[n + 1];
            for (int i = 1; i <= n; i++) a[i] = nextLong();
            return a;
        }

        String[] id23(int n) {
            String[] g = new String[n];
            for (int i = 0; i < n; i++) g[i] = next();
            return g;
        }

        List<Integer>[] id4(int n, int m) {
            List<Integer>[] adj = new List[n + 1];
            for (int i = 0; i <= n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < m; i++) {
                int u = nextInt();
                int v = nextInt();
                adj[u].add(v);
                adj[v].add(u);
            }
            return adj;
        }

        List<Integer>[] id11(int n, int m) {
            List<Integer>[] adj = new List[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < m; i++) {
                int u = nextInt() - 1;
                int v = nextInt() - 1;
                adj[u].add(v);
                adj[v].add(u);
            }
            return adj;
        }

        
        int[][] id22(int nodeCnt, int edgeCnt) {
            int[] end1 = new int[edgeCnt], end2 = new int[edgeCnt];
            int[] id3 = new int[nodeCnt + 1], id15 = new int[nodeCnt + 1];
            for (int i = 0; i < edgeCnt; i++) {
                int u = in.nextInt(), v = in.nextInt();
                id3[u]++;
                id3[v]++;
                end1[i] = u;
                end2[i] = v;
            }
            int[][] adj = new int[nodeCnt + 1][];
            for (int i = 1; i <= nodeCnt; i++) {
                adj[i] = new int[id3[i]];
            }
            for (int i = 0; i < edgeCnt; i++) {
                adj[end1[i]][id15[end1[i]]] = end2[i];
                id15[end1[i]]++;
                adj[end2[i]][id15[end2[i]]] = end1[i];
                id15[end2[i]]++;
            }
            return adj;
        }

        
        int[][][] id0(int nodeCnt, int edgeCnt) {
            int[] end1 = new int[edgeCnt], end2 = new int[edgeCnt], weight = new int[edgeCnt];
            int[] id3 = new int[nodeCnt + 1], id15 = new int[nodeCnt + 1];
            for (int i = 0; i < edgeCnt; i++) {
                int u = in.nextInt(), v = in.nextInt(), w = in.nextInt();
                id3[u]++;
                id3[v]++;
                end1[i] = u;
                end2[i] = v;
                weight[i] = w;
            }
            int[][][] adj = new int[nodeCnt + 1][][];
            for (int i = 1; i <= nodeCnt; i++) {
                adj[i] = new int[id3[i]][2];
            }
            for (int i = 0; i < edgeCnt; i++) {
                adj[end1[i]][id15[end1[i]]][0] = end2[i];
                adj[end1[i]][id15[end1[i]]][1] = weight[i];
                id15[end1[i]]++;
                adj[end2[i]][id15[end2[i]]][0] = end1[i];
                adj[end2[i]][id15[end2[i]]][1] = weight[i];
                id15[end2[i]]++;
            }
            return adj;
        }

        
        int[][] id13(int nodeCnt, int edgeCnt) {
            int[] from = new int[edgeCnt], to = new int[edgeCnt];
            int[] id3 = new int[nodeCnt + 1], id15 = new int[nodeCnt + 1];
            

            for (int i = 0; i < edgeCnt; i++) {
                int u = in.nextInt(), v = in.nextInt();
                id3[u]++;
                from[i] = u;
                to[i] = v;
            }
            int[][] adj = new int[nodeCnt + 1][];
            for (int i = 1; i <= nodeCnt; i++) {
                adj[i] = new int[id3[i]];
            }
            for (int i = 0; i < edgeCnt; i++) {
                adj[from[i]][id15[from[i]]] = to[i];
                id15[from[i]]++;
            }
            return adj;
        }

        
        int[][][] id6(int nodeCnt, int edgeCnt) {
            int[] from = new int[edgeCnt], to = new int[edgeCnt], weight = new int[edgeCnt];
            int[] id3 = new int[nodeCnt + 1], id15 = new int[nodeCnt + 1];
            

            for (int i = 0; i < edgeCnt; i++) {
                int u = in.nextInt(), v = in.nextInt(), w = in.nextInt();
                id3[u]++;
                from[i] = u;
                to[i] = v;
                weight[i] = w;
            }
            int[][][] adj = new int[nodeCnt + 1][][];
            for (int i = 1; i <= nodeCnt; i++) {
                adj[i] = new int[id3[i]][2];
            }
            for (int i = 0; i < edgeCnt; i++) {
                adj[from[i]][id15[from[i]]][0] = to[i];
                adj[from[i]][id15[from[i]]][1] = weight[i];
                id15[from[i]]++;
            }
            return adj;
        }
    }
}