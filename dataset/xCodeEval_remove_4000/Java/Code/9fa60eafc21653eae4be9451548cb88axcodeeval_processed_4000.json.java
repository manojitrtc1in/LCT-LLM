import java.io.*;
import java.util.*;
import java.util.ArrayList;
import java.util.Arrays.*;
import java.util.Map.Entry;

import static java.util.Collections.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Solution {
    static final int id0 = 1_000_002;
    private static final boolean thread = true;
    @SuppressWarnings("all")
    static final boolean id7 = (1 == 1) ? true : false;

    static int n, a[], e[][], vis[], rot, b[];
    @SuppressWarnings("all")
    private static ArrayList<Integer> adj[], v = new ArrayList<>();
    static long gcd = 1;
    static HashMap<Integer, Integer> pos;

    @SuppressWarnings("unchecked")
    static void solve() throws Exception {
        

        int n = ni();
        int m = ni();
        char[][] s = new char[n][m];
        int[][][][] t = new int[10][10][11][];
        for (int i = 0; i < s.length; i++) {
            s[i] = ns();
            for (int j = 0; j < s[i].length; j++) {
                if (j + 1 < s[i].length) {
                    t[s[i][j] - '0'][s[i][j + 1] - '0'][10] = new int[] { j, j + 1, i };
                }
                if (j + 2 < s[i].length) {
                    t[s[i][j] - '0'][s[i][j + 1] - '0'][s[i][j + 2] - '0'] = new int[] { j, j + 2, i };
                }
            }
        }
        char[] a = ns();
        ArrayList<int[]>[][] dp = new ArrayList[a.length][2];
        ArrayList<int[]> ans = rec(a, 0, 2, t, dp);
        if ((ans.size() > 0 && ans.get(ans.size() - 1).length == 0))
            ans = rec(a, 0, 3, t, dp);
        if (ans.size() > 0 && ans.get(ans.size() - 1).length == 0) {
            pn(-1);
        } else {
            Collections.reverse(ans);
            

            

            

            

            

            

            

            

            pn(ans.size());
            for (int[] i : ans) {
                for (int j : i) {
                    p((j + 1) + " ");
                }
                pn();
            }
        }
    }

    private static ArrayList<int[]> rec(char[] a, int i, int j, int[][][][] t, ArrayList<int[]>[][] dp) {
        ArrayList<int[]> arrayList = new ArrayList<>();
        if (i == a.length) {
            return arrayList;
        }
        if (i + j > a.length) {
            arrayList.add(new int[] {});
            return arrayList;
        }
        if (dp[i][j % 2] != null) {
            return dp[i][j % 2];
        }
        if (j == 2) {
            if (t[a[i] - '0'][a[i + 1] - '0'][10] != null) {
                ArrayList<int[]> ans = rec(a, i + j, 2, t, dp);
                if (!(ans.size() > 0 && ans.get(0).length == 0)) {
                    ans.add(t[a[i] - '0'][a[i + 1] - '0'][10]);
                    return dp[i][j % 2] = ans;
                }
                ans = rec(a, i + j, 3, t, dp);
                if (!(ans.size() > 0 && ans.get(0).length == 0)) {
                    ans.add(t[a[i] - '0'][a[i + 1] - '0'][10]);
                    return dp[i][j % 2] = ans;
                }
                return dp[i][j % 2] = ans;
            }
        } else {
            if (t[a[i] - '0'][a[i + 1] - '0'][a[i + 2] - '0'] != null) {
                ArrayList<int[]> ans = rec(a, i + j, 2, t, dp);
                if (!(ans.size() > 0 && ans.get(0).length == 0)) {
                    ans.add(t[a[i] - '0'][a[i + 1] - '0'][a[i + 2] - '0']);
                    return dp[i][j % 2] = ans;
                }
                ans = rec(a, i + j, 3, t, dp);
                if (!(ans.size() > 0 && ans.get(0).length == 0)) {
                    ans.add(t[a[i] - '0'][a[i + 1] - '0'][a[i + 2] - '0']);
                    return dp[i][j % 2] = ans;
                }
                return dp[i][j % 2] = ans;
            }
        }
        arrayList.add(new int[] {});
        return dp[i][j % 2] = arrayList;
    }

    static int power(int x, int y, int m) {
        if (y == 0)
            return 1;
        int p = power(x, y / 2, m) % m;
        p = (int) ((p * (long) p) % m);
        if (y % 2 == 0)
            return p;
        else
            return (int) ((x * (long) p) % m);
    }

    static int N = 1000001;

    

    static long[] id3 = new long[N + 1];

    

    static long[] id4 = new long[N + 1];

    

    static long[] fact = new long[N + 1];

    

    public static void id2(int p) {
        id4[0] = id4[1] = 1;

        for (int i = 2; i <= N; i++)
            id4[i] = id4[p % i] * (long) (p - p / i) % p;
    }

    

    public static void id5(int p) {
        id3[0] = id3[1] = 1;

        

        for (int i = 2; i <= N; i++)
            id3[i] = (id4[i] * id3[i - 1]) % p;
    }

    

    public static void factorial(int p) {
        fact[0] = 1;

        

        for (int i = 1; i <= N; i++) {
            fact[i] = (fact[i - 1] * (long) i) % p;
        }
    }

    

    public static long nPr(int N, int R, int p) {

        

        long ans = ((fact[N]) % p * id3[N - R]) % p;

        return ans;
    }

    public static void main(final String[] args) throws Exception {
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        new Thread(null, () -> {
            try {
                final int testcases = id7 ? ni() : 1;
                for (int i = 1; i <= testcases; i++) {
                    

                    solve();
                }
                out.flush();
                r.close();
                out.close();
            } catch (final Exception t) {
                t.printStackTrace(System.err);
                

            }
        }, "rec", (1L << 25)).start();
        

        

        

    }

    @SuppressWarnings("all")
    private static final int MOD = (int) (1e9 + 7), id8 = 998244353;
    private static Reader r = new Reader();
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    static {
        int p = id8;
        id2(p);
        id5(p);
        factorial(p);
    }

    public static long[] id6(int a, int n, int mod) {
        a %= mod;
        long[] pows = new long[n + 1];
        pows[0] = 1;
        for (int i = 1; i <= n; i++)
            pows[i] = pows[i - 1] * a % mod;
        return pows;
    }

    @SuppressWarnings("all")
    private static boolean eq(long a, long b) {
        return Long.compare(a, b) == 0;
    }

    @SuppressWarnings("all")
    private static ArrayList<Integer> seive(int n) {
        ArrayList<Integer> p = new ArrayList<>();
        int[] f = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            if (f[i] == 1)
                continue;
            for (int j = i * i; j <= n && j < f.length; j += i) {
                f[j] = 1;
            }
        }
        for (int i = 2; i < f.length; i++) {
            if (f[i] == 0)
                p.add(i);
        }
        return p;
    }

    @SuppressWarnings("all")
    private static void s(int[] a) {
        Integer[] t = new Integer[a.length];
        for (int i = 0; i < t.length; i++) {
            t[i] = a[i];
        }
        sort(t);
        for (int i = 0; i < t.length; i++) {
            a[i] = t[i];
        }
    }

    int pow(int a, int b, int m) {
        int ans = 1;
        while (b != 0) {
            if ((b & 1) != 0)
                ans = (ans * a) % m;
            b /= 2;
            a = (a * a) % m;
        }
        return ans;
    }

    int modinv(int k) {
        return pow(k, MOD - 2, MOD);
    }

    @SuppressWarnings("all")
    private static void swap(final int i, final int j) {
        final int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    @SuppressWarnings("all")
    private static boolean id9(final long A, final long B) {
        if (A == 0 || B == 0)
            return false;
        final long result = A * B;
        if (A == result / B)
            return true;
        return false;
    }

    @SuppressWarnings("all")
    private static int gcd(final int a, final int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    @SuppressWarnings("all")
    private static long gcd(final long a, final long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    @SuppressWarnings("all")
    private static class Pair<T, E> implements Comparable<Pair<T, E>> {
        T fir;
        E snd;

        Pair() {
        }

        Pair(final T x, final E y) {
            this.fir = x;
            this.snd = y;
        }

        

        

        

        

        

        

        @Override
        @SuppressWarnings("unchecked")
        public int compareTo(final Pair<T, E> o) {
            final int c = ((Comparable<T>) fir).compareTo(o.fir);
            return c;
        }

    }

    @SuppressWarnings("all")
    private static class pi implements Comparable<pi> {
        int fir, snd;

        pi() {
        }

        pi(final int a, final int b) {
            fir = a;
            snd = b;
        }

        public int compareTo(final pi o) {
            return fir == o.fir ? snd - o.snd : fir - o.fir;
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + fir;
            result = prime * result + snd;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            pi other = (pi) obj;
            if (fir != other.fir)
                return false;
            if (snd != other.snd)
                return false;
            return true;
        }

    }

    @SuppressWarnings("all")
    private static <T> void checkV(final Vector<T> adj[], final int i) {
        adj[i] = adj[i] == null ? new Vector<>() : adj[i];
    }

    private static <T> void checkV(final ArrayList<T> adj[], final int i) {
        adj[i] = adj[i] == null ? new ArrayList<>() : adj[i];
    }

    @SuppressWarnings("all")
    private static int[] na(final int n) throws Exception {
        final int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = ni();
        }
        return a;
    }

    @SuppressWarnings("all")
    private static Float[] nf(final int n) throws Exception {
        final Float[] a = new Float[n];
        for (int i = 0; i < n; i++) {
            a[i] = nf();
        }
        return a;
    }

    @SuppressWarnings("all")
    private static int[] na1(final int n) throws Exception {
        final int[] a = new int[n + 1];
        for (int i = 1; i < a.length; i++) {
            a[i] = ni();
        }
        return a;
    }

    @SuppressWarnings("all")
    private static String n() throws IOException {
        return r.readToken();
    }

    @SuppressWarnings("all")
    private static char[] ns() throws IOException {
        return r.readToken().toCharArray();
    }

    @SuppressWarnings("all")
    private static String nln() throws IOException {
        return r.readLine();
    }

    private static int ni() throws IOException {
        return r.nextInt();
    }

    @SuppressWarnings("all")
    private static long nl() throws IOException {
        return r.nextLong();
    }

    @SuppressWarnings("all")
    private static double nd() throws IOException {
        return r.nextDouble();
    }

    @SuppressWarnings("all")
    private static float nf() throws IOException {
        return (float) r.nextDouble();
    }

    @SuppressWarnings("all")
    private static void p(final Object o) {
        out.print(o);
    }

    @SuppressWarnings("all")
    private static void pn(final Object o) {
        out.println(o);
    }

    @SuppressWarnings("all")
    private static void pn() {
        out.println("");
    }

    @SuppressWarnings("all")
    private static void pi(final Object o) {
        out.print(o);
        out.flush();
    }

    @SuppressWarnings("all")
    private static void pni() {
        out.println("");
        out.flush();
    }

    private static void pni(final Object o) {
        out.println(o);
        out.flush();
    }

    private static class Reader {
        private final int BUFFER_SIZE = 1 << 17;
        private final DataInputStream din;
        private final byte[] buffer;
        private int bufferPointer, bytesRead;
        


        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        @SuppressWarnings("all")
        public Reader(final String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        final byte[] buf = new byte[id0];

        public String readLine() throws IOException {
            int cnt = 0;
            int c;
            o: while ((c = read()) != -1) {
                if (c == '\n')
                    if (cnt == 0)
                        continue o;
                    else
                        break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public String readToken() throws IOException {
            int cnt = 0;
            int c;
            o: while ((c = read()) != -1) {
                if (!(c >= 33 && c <= 126))
                    if (cnt == 0)
                        continue o;
                    else
                        break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            final boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            final boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            final boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    @SuppressWarnings({ "all", })
    private static <T> T deepCopy(final T old) {
        try {
            return (T) id1(old);
        } catch (final IOException | ClassNotFoundException e) {
            e.printStackTrace(System.err);
            System.exit(-1);
        }
        return null;
    }

    private static Object id1(final Object oldObj) throws IOException, ClassNotFoundException {
        ObjectOutputStream oos = null;
        ObjectInputStream ois = null;
        try {
            final ByteArrayOutputStream bos = new ByteArrayOutputStream(); 

            oos = new ObjectOutputStream(bos); 

            

            oos.writeObject(oldObj); 

            oos.flush(); 

            final ByteArrayInputStream bin = new ByteArrayInputStream(bos.toByteArray()); 

            ois = new ObjectInputStream(bin); 

            

            return ois.readObject(); 

        } catch (final ClassNotFoundException e) {
            pni("Exception in ObjectCloner = " + e);
            throw (e);
        } finally {
            oos.close();
            ois.close();
        }
    }

}