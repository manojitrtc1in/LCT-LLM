


import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class G {
    static InputReader in;
    static PrintWriter out;

    public static void main(String[] args) {
        

        initReaderPrinter(false);
        solve(in.nextInt());
        

    }  
    
    
    
    

    static int mod = (int)1e9 + 7, n;
    static List<int[]> idx;
    static int[] rightMostSmallerNonOverlap, leftMostBiggerNonOverlap;
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
                rightMostSmallerNonOverlap = new int[n];
                leftMostBiggerNonOverlap = new int[n];




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
        int[][] minMovesDp = new int[cnt][cnt];
        for(int i = 0; i < minMovesDp.length; i++) {
            Arrays.fill(minMovesDp[i], -1);
        }
        for(int i = l; i <= r; i++) {
            rightMostSmallerNonOverlap[i] = bsOnLeft(l, r, i);
            leftMostBiggerNonOverlap[i] = bsOnRight(l, r, i);
        }
        computeMinMoves(l, r, l, minMovesDp);
        int minMoves = minMovesDp[0][r - l];
        long[][] minMoveSeqCnt = new long[cnt][cnt];
        for(int i = 0; i < minMoveSeqCnt.length; i++) {
            Arrays.fill(minMoveSeqCnt[i], -1);
        }
        long seqCnt = computeNumOfSeq(l, r, l, minMovesDp, minMoveSeqCnt);
        return new long[]{minMoves, seqCnt};
    }

    static long computeNumOfSeq(int l, int r, int offset, int[][] minMovesDp, long[][] minMoveSeqCnt) {
        if(l > r) return 1;
        if(minMoveSeqCnt[l - offset][r - offset] < 0) {
            long cnt = 0;






            int leftMostNonOverlap = leftMostBiggerNonOverlap[l];
            for (int i = l; i < leftMostNonOverlap; i++) {
                

                

                

                int j = leftMostBiggerNonOverlap[i];
                int remainMoves = j <= r ? minMovesDp[j - offset][r - offset] : 0;
                if (remainMoves + 1 == minMovesDp[l - offset][r - offset]) {
                    cnt = (cnt + computeNumOfSeq(j, r, offset, minMovesDp, minMoveSeqCnt)) % mod;
                }
            }
            minMoveSeqCnt[l - offset][r - offset] = cnt;
        }
        return minMoveSeqCnt[l - offset][r - offset];
    }

    static int bsOnRight(int l, int r, int i) {
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

    static int bsOnLeft(int l, int r, int i) {
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
    static int computeMinMoves(int l, int r, int offset, int[][] minMovesDp) {
        int i = l - offset, j = r - offset;
        if(i > j) return 0;
        if(minMovesDp[i][j] < 0) {
            minMovesDp[i][j] = idx.size() + 1;
            for(int k = l; k <= r; k++) {






                int j1 = rightMostSmallerNonOverlap[k];
                int leftMoves = computeMinMoves(l, j1, offset, minMovesDp);






                int j2 = leftMostBiggerNonOverlap[k];
                int rightMoves = computeMinMoves(j2, r, offset, minMovesDp);
                minMovesDp[i][j] = min(minMovesDp[i][j], 1 + leftMoves + rightMoves);
            }
        }
        return minMovesDp[i][j];
    }

    static void initReaderPrinter(boolean test) {
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

        Integer[] nextIntArray(int n) {
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        int[] nextIntArrayPrimitive(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        int[] nextIntArrayPrimitiveOneIndexed(int n) {
            int[] a = new int[n + 1];
            for (int i = 1; i <= n; i++) a[i] = nextInt();
            return a;
        }

        Long[] nextLongArray(int n) {
            Long[] a = new Long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }

        long[] nextLongArrayPrimitive(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }

        long[] nextLongArrayPrimitiveOneIndexed(int n) {
            long[] a = new long[n + 1];
            for (int i = 1; i <= n; i++) a[i] = nextLong();
            return a;
        }

        String[] nextStringArray(int n) {
            String[] g = new String[n];
            for (int i = 0; i < n; i++) g[i] = next();
            return g;
        }

        List<Integer>[] readGraphOneIndexed(int n, int m) {
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

        List<Integer>[] readGraphZeroIndexed(int n, int m) {
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

        
        int[][] buildUndirectedGraph(int nodeCnt, int edgeCnt) {
            int[] end1 = new int[edgeCnt], end2 = new int[edgeCnt];
            int[] edgeCntForEachNode = new int[nodeCnt + 1], idxForEachNode = new int[nodeCnt + 1];
            for (int i = 0; i < edgeCnt; i++) {
                int u = in.nextInt(), v = in.nextInt();
                edgeCntForEachNode[u]++;
                edgeCntForEachNode[v]++;
                end1[i] = u;
                end2[i] = v;
            }
            int[][] adj = new int[nodeCnt + 1][];
            for (int i = 1; i <= nodeCnt; i++) {
                adj[i] = new int[edgeCntForEachNode[i]];
            }
            for (int i = 0; i < edgeCnt; i++) {
                adj[end1[i]][idxForEachNode[end1[i]]] = end2[i];
                idxForEachNode[end1[i]]++;
                adj[end2[i]][idxForEachNode[end2[i]]] = end1[i];
                idxForEachNode[end2[i]]++;
            }
            return adj;
        }

        
        int[][][] buildUndirectedWeightedGraph(int nodeCnt, int edgeCnt) {
            int[] end1 = new int[edgeCnt], end2 = new int[edgeCnt], weight = new int[edgeCnt];
            int[] edgeCntForEachNode = new int[nodeCnt + 1], idxForEachNode = new int[nodeCnt + 1];
            for (int i = 0; i < edgeCnt; i++) {
                int u = in.nextInt(), v = in.nextInt(), w = in.nextInt();
                edgeCntForEachNode[u]++;
                edgeCntForEachNode[v]++;
                end1[i] = u;
                end2[i] = v;
                weight[i] = w;
            }
            int[][][] adj = new int[nodeCnt + 1][][];
            for (int i = 1; i <= nodeCnt; i++) {
                adj[i] = new int[edgeCntForEachNode[i]][2];
            }
            for (int i = 0; i < edgeCnt; i++) {
                adj[end1[i]][idxForEachNode[end1[i]]][0] = end2[i];
                adj[end1[i]][idxForEachNode[end1[i]]][1] = weight[i];
                idxForEachNode[end1[i]]++;
                adj[end2[i]][idxForEachNode[end2[i]]][0] = end1[i];
                adj[end2[i]][idxForEachNode[end2[i]]][1] = weight[i];
                idxForEachNode[end2[i]]++;
            }
            return adj;
        }

        
        int[][] buildDirectedGraph(int nodeCnt, int edgeCnt) {
            int[] from = new int[edgeCnt], to = new int[edgeCnt];
            int[] edgeCntForEachNode = new int[nodeCnt + 1], idxForEachNode = new int[nodeCnt + 1];
            

            for (int i = 0; i < edgeCnt; i++) {
                int u = in.nextInt(), v = in.nextInt();
                edgeCntForEachNode[u]++;
                from[i] = u;
                to[i] = v;
            }
            int[][] adj = new int[nodeCnt + 1][];
            for (int i = 1; i <= nodeCnt; i++) {
                adj[i] = new int[edgeCntForEachNode[i]];
            }
            for (int i = 0; i < edgeCnt; i++) {
                adj[from[i]][idxForEachNode[from[i]]] = to[i];
                idxForEachNode[from[i]]++;
            }
            return adj;
        }

        
        int[][][] buildDirectedWeightedGraph(int nodeCnt, int edgeCnt) {
            int[] from = new int[edgeCnt], to = new int[edgeCnt], weight = new int[edgeCnt];
            int[] edgeCntForEachNode = new int[nodeCnt + 1], idxForEachNode = new int[nodeCnt + 1];
            

            for (int i = 0; i < edgeCnt; i++) {
                int u = in.nextInt(), v = in.nextInt(), w = in.nextInt();
                edgeCntForEachNode[u]++;
                from[i] = u;
                to[i] = v;
                weight[i] = w;
            }
            int[][][] adj = new int[nodeCnt + 1][][];
            for (int i = 1; i <= nodeCnt; i++) {
                adj[i] = new int[edgeCntForEachNode[i]][2];
            }
            for (int i = 0; i < edgeCnt; i++) {
                adj[from[i]][idxForEachNode[from[i]]][0] = to[i];
                adj[from[i]][idxForEachNode[from[i]]][1] = weight[i];
                idxForEachNode[from[i]]++;
            }
            return adj;
        }
    }
}