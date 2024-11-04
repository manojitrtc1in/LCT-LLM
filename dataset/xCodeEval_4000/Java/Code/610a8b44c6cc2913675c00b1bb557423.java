


import java.io.*;
import java.util.*;

public class CF1111C {
    static FastReader s;
    static PrintWriter out;
    static String INPUT = "3 2 5 1\n" +
            "8 7\n";


    public static void main(String[] args) {
        long time = System.currentTimeMillis();
        boolean oj = System.getProperty("ONLINE_JUDGE") != null;
        out = new PrintWriter(System.out);
        s = new FastReader(oj);

        int n = s.nextInt();
        int k = s.nextInt();
        long a = s.nextLong();
        long b = s.nextLong();
        long[] arr = s.nextLongArray(k);
        arrays.sort(arr);







        out.println(func(a, b, 1, (long)(1 << (long)n), arr));

        if (!oj) {
            System.out.println(Arrays.deepToString(new Object[]{System.currentTimeMillis() - time + " ms"}));
        }
        out.flush();
    }

    private static long func(long a, long b, long start, long end, long[] arr) {
        if (start == end) {
            if (Arrays.binarySearch(arr, end) >= 0) {
                long pos1 = (long)BS.binarySearchFirstOccurence(arr, end);
                long pos2 = (long)BS.binarySearchLastOccurence(arr, end);
                return b * (pos2 - pos1 + 1L);
            } else {
                return a;
            }
        }

        long pos = Arrays.binarySearch(arr, start);
        long pos2 = Arrays.binarySearch(arr, end);

        boolean bool1 = false;
        boolean bool2 = false;
        if (pos < 0) {
            pos = (-1L) * (pos + 1L);
            bool1 = true;
        }

        if (pos2 < 0) {
            pos2 = (-1L) * (pos2 + 1L);
            bool2 = true;
        }

        if(!bool2) {
            pos2 = (long)BS.binarySearchLastOccurence(arr, end);
        }

        if(!bool1) {
            pos = (long)BS.binarySearchFirstOccurence(arr, start);
        }

        if (pos2 == pos && bool1 && bool2) {
            return a;
        }

        long a1 = func(a, b, start, (start + end) / 2, arr);
        long a2 = func(a, b, ((start + end) / 2) + 1, end, arr);
        long min1;
        if(!bool1 && !bool2) {
            min1 = (end - start + 1L) * b * (pos2 - pos + 1L);
        } else {
            if(bool2) {
                min1 = (end - start + 1L) * b * (pos2 - pos);
            } else {
                min1 = (end - start + 1L) * b * (pos2 - pos + 1L);
            }
        }
        return Math.min(min1, a1 + a2);
    }




    private static class Maths {
        static ArrayList<Long> printDivisors(long n) {
            

            ArrayList<Long> list = new ArrayList<>();
            for (long i = 1; i <= Math.sqrt(n); i++) {
                if (n % i == 0) {
                    if (n / i == i) {
                        list.add(i);
                    } else {
                        list.add(i);
                        list.add(n / i);
                    }
                }
            }
            return list;
        }




        

        private static long gcd(long a, long b) {
            if (b == 0) {
                return a;
            }

            return gcd(b, a % b);
        }

        





        static long[] extendedEuclidean(long p, long q) {
            if (q == 0)
                return new long[]{p, 1, 0};

            long[] vals = extendedEuclidean(q, p % q);
            long d = vals[0];
            long a = vals[2];
            long b = vals[1] - (p / q) * vals[2];
            return new long[]{d, a, b};
        }

        

        static long power(long x, long y, long p) {
            long res = 1;
            x = x % p;

            while (y > 0) {
                if ((y & 1) == 1)
                    res = (res * x) % p;
                y = y >> 1;
                x = (x * x) % p;
            }
            return res;
        }

        

        

        

        

        static long inv(long a, long m) {
            long m0 = m, t, q;
            long x0 = 0, x1 = 1;

            if (m == 1)
                return 0;

            

            while (a > 1) {
                q = a / m;
                t = m;
                m = a % m;
                a = t;
                t = x0;
                x0 = x1 - q * x0;
                x1 = t;
            }

            

            if (x1 < 0)
                x1 += m0;

            return x1;
        }

        

        

        

        

        

        

        

        

        

        static long findMinX(long num[], long rem[], long k) {
            int prod = 1;
            for (int i = 0; i < k; i++)
                prod *= num[i];

            int result = 0;
            for (int i = 0; i < k; i++) {
                long pp = prod / num[i];
                result += rem[i] * inv(pp, num[i]) * pp;
            }

            return result % prod;
        }
    }

    private static class BS {
        

        private static int binarySearch(int[] arr, int ele) {
            int low = 0;
            int high = arr.length - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (arr[mid] == ele) {
                    return mid;
                } else if (ele < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return -1;
        }

        

        private static int binarySearchFirstOccurence(long[] arr, long ele) {
            int low = 0;
            int high = arr.length - 1;
            int ans = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (arr[mid] == ele) {
                    ans = mid;
                    high = mid - 1;
                } else if (ele < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return ans;
        }


        

        private static int binarySearchLastOccurence(long[] arr, long ele) {
            int low = 0;
            int high = arr.length - 1;
            int ans = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (arr[mid] == ele) {
                    ans = mid;
                    low = mid + 1;
                } else if (ele < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return ans;
        }
    }

    private static class arrays {
        

        static void merge(long arr[], int l, int m, int r) {
            int n1 = m - l + 1;
            int n2 = r - m;
            long L[] = new long[n1];
            long R[] = new long[n2];
            for (int i = 0; i < n1; ++i)
                L[i] = arr[l + i];
            for (int j = 0; j < n2; ++j)
                R[j] = arr[m + 1 + j];
            int i = 0, j = 0;
            int k = l;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }

            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        static void sort(long arr[], int l, int r) {
            if (l < r) {
                int m = (l + r) / 2;
                sort(arr, l, m);
                sort(arr, m + 1, r);
                merge(arr, l, m, r);
            }
        }

        static void sort(long[] arr) {
            sort(arr, 0, arr.length - 1);
        }
    }

    private static class UnionFindDisjointSet {
        int[] parent;
        int[] size;
        int n;
        int size1;

        public UnionFindDisjointSet(int n) {
            this.n = n;
            this.parent = new int[n];
            this.size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }

            for (int i = 0; i < n; i++) {
                size[i] = 1;
            }

            this.size1 = n;
        }

        private int numDisjointSets() {
            System.out.println(size1);
            return size1;
        }

        private boolean find(int a, int b) {
            int rootA = root(a);
            int rootB = root(b);
            if (rootA == rootB) {
                return true;
            }
            return false;
        }

        private int root(int b) {
            while (parent[b] != b) {
                parent[b] = parent[parent[b]];
                b = parent[b];
            }
            return b;
        }

        private void union(int a, int b) {
            int rootA = root(a);
            int rootB = root(b);
            if (rootA == rootB) {
                return;
            }

            if (size[rootA] < size[rootB]) {
                parent[rootA] = parent[rootB];
                size[rootB] += size[rootA];
            } else {
                parent[rootB] = parent[rootA];
                size[rootA] += size[rootB];
            }
            size1--;
            System.out.println(Arrays.toString(parent));
        }
    }

    private static class SegTree {
        int[] st;
        int[] arr;

        public SegTree(int[] arr) {
            this.arr = arr;
            int size = (int) Math.ceil(Math.log(arr.length) / Math.log(2));
            st = new int[(int) ((2 * Math.pow(2, size)) - 1)];
            buildSegmentTree(1, 0, arr.length - 1);
        }

        

        private void buildSegmentTree(int index, int L, int R) {
            if (L == R) {
                st[index] = arr[L];
                return;
            }

            buildSegmentTree(index * 2, L, (L + R) / 2);
            buildSegmentTree(index * 2 + 1, (L + R) / 2 + 1, R);


            st[index] = Math.min(st[index * 2], st[index * 2 + 1]);
        }

        

        private int Query(int queL, int queR) {
            return Query1(1, 0, arr.length - 1, queL, queR);
        }

        

        

        private int Query1(int index, int segL, int segR, int queL, int queR) {
            if (queL > segR || queR < segL) {
                return -1;
            }

            if (queL <= segL && queR >= segR) {
                return st[index];
            }

            int ans1 = Query1(index * 2, segL, (segL + segR) / 2, queL, queR);
            int ans2 = Query1(index * 2 + 1, (segL + segR) / 2 + 1, segR, queL, queR);
            if (ans1 == -1) {
                return ans2;
            }

            if (ans2 == -1) {
                return ans1;
            }


            return Math.min(ans1, ans2);
        }

        private void update(int idx, int val) {
            update1(1, 0, arr.length - 1, idx, val);
        }

        private void update1(int node, int queL, int queR, int idx, int val) {
            

            

            if (queL == queR) {
                

                arr[idx] += val;
                st[node] += val;
            } else {
                int mid = (queL + queR) / 2;
                if (queL <= idx && idx <= mid) {
                    

                    update1(2 * node, queL, mid, idx, val);
                } else {
                    

                    update1(2 * node + 1, mid + 1, queR, idx, val);
                }
                

                st[node] = Math.min(st[2 * node], st[2 * node + 1]);
            }
        }

    }

    private static class FastReader {
        InputStream is;

        public FastReader(boolean onlineJudge) {
            is = onlineJudge ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        }

        byte[] inbuf = new byte[1024];
        public int lenbuf = 0, ptrbuf = 0;

        int readByte() {
            if (lenbuf == -1)
                throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0)
                    return -1;
            }
            return inbuf[ptrbuf++];
        }

        boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b))
                ;
            return b;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        char nextChar() {
            return (char) skip();
        }

        String next() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) { 

                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        String nextLine() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while ((!isSpaceChar(b) || b == ' ')) { 

                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        char[] next(int n) {
            char[] buf = new char[n];
            int b = skip(), p = 0;
            while (p < n && !(isSpaceChar(b))) {
                buf[p++] = (char) b;
                b = readByte();
            }
            return n == p ? buf : Arrays.copyOf(buf, p);
        }

        int nextInt() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
                ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        long nextLong() {
            long num = 0;
            int b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
                ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        char[][] nextMatrix(int n, int m) {
            char[][] map = new char[n][];
            for (int i = 0; i < n; i++)
                map[i] = next(m);
            return map;
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        int[][] next2DInt(int n, int m) {
            int[][] arr = new int[n][];
            for (int i = 0; i < n; i++) {
                arr[i] = nextIntArray(m);
            }
            return arr;
        }

        long[][] next2DLong(int n, int m) {
            long[][] arr = new long[n][];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLongArray(m);
            }
            return arr;
        }

        int[] shuffle(int[] arr) {
            Random r = new Random();
            for (int i = 1, j; i < arr.length; i++) {
                j = r.nextInt(i);
                arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];
            }
            return arr;
        }

        int[] uniq(int[] arr) {
            Arrays.sort(arr);
            int[] rv = new int[arr.length];
            int pos = 0;
            rv[pos++] = arr[0];
            for (int i = 1; i < arr.length; i++) {
                if (arr[i] != arr[i - 1]) {
                    rv[pos++] = arr[i];
                }
            }
            return Arrays.copyOf(rv, pos);
        }
    }
}