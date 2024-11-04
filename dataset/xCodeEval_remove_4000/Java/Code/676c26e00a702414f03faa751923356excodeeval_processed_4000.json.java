import java.io.*;
import java.util.*;
import java.util.ArrayList;
import java.util.Arrays.*;
import java.util.Map.Entry;
import java.util.stream.IntStream;
import java.util.stream.LongStream;

import static java.util.Collections.*;
import static java.lang.Integer.parseInt;
import static java.lang.Math.*;
import static java.lang.String.format;
import static java.util.Arrays.*;

public class CC {
    @SuppressWarnings("all")
    private static final int[][] id4 = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    @SuppressWarnings("all")
    private static final int[][] id3 = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 1 }, { -1, 1 },
            { 1, -1 }, { -1, -1 } };
    static final int id0 = 1_000_002;
    private static final boolean thread = false;
    @SuppressWarnings("all")
    static final boolean id8 = (1 == 1) ? true : false;

    @SuppressWarnings("all")
    private static ArrayList<Integer> adj[], v = new ArrayList<>();
    static long gcd = 1;
    static HashMap<Integer, Integer> pos;
    static int n, e[][], vis[], m, b[], a[];

    @SuppressWarnings("unchecked")
    static void solve() throws Exception {
        n = ni();
        a = na(n);
        if (n == 1) {
            pn("YES");
            pn(a[0]);
            return;
        }
        long[] ans = new long[n];
        long sum = 0;
        for (int i = 0; i < ans.length; i++) {
            sum += a[i];
        }
        if (sum % (n * (n + 1l) / 2) != 0) {
            pn("NO");
            return;
        }
        long s = sum / (n * (n + 1l) / 2);
        for (int i = 0; i < ans.length; i++) {
            ans[i] = -a[i] + a[(i + n - 1) % n] + s;
            if (ans[i] % n != 0 || ans[i] < 1) {
                pn("NO");
                return;
            }
            ans[i] /= n;

        }
        pn("YES");
        pn(ans);
    }

    public static void main(final String[] args) throws Exception {
        if (!thread) {
            final int id5 = id8 ? ni() : 1;
            for (int i = 1; i <= id5; i++) {
                

                

                try {
                    solve();
                } catch (final Exception e) {
                    

                    

                    

                    throw e;
                }
            }
            out.flush();
        }
        r.close();
        out.close();
    }

    @SuppressWarnings("all")
    private static final int MOD = (int) (1e9 + 7), id9 = 998244353;
    private static final Reader r = new Reader();

    private static final PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    private static int[] deepCopy;

    public static long[] id7(int a, final int n, final int mod) {
        a %= mod;
        final long[] pows = new long[n + 1];
        pows[0] = 1;
        for (int i = 1; i <= n; i++)
            pows[i] = pows[i - 1] * a % mod;
        return pows;
    }

    @SuppressWarnings("all")
    private static ArrayList<Integer> sieve(final int n) {
        final ArrayList<Integer> p = new ArrayList<>();
        final int[] f = new int[n + 1];
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
    private static void s(final int[] a) {
        final Integer[] t = new Integer[a.length];
        for (int i = 0; i < t.length; i++) {
            t[i] = a[i];
        }
        sort(t);
        for (int i = 0; i < t.length; i++) {
            a[i] = t[i];
        }
    }

    int pow(int a, int b, final int m) {
        int ans = 1;
        while (b != 0) {
            if ((b & 1) != 0)
                ans = (ans * a) % m;
            b /= 2;
            a = (a * a) % m;
        }
        return ans;
    }

    int modInverse(final int k) {
        return pow(k, MOD - 2, MOD);
    }

    @SuppressWarnings("all")
    private static void swap(final int i, final int j) {
        final int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    @SuppressWarnings("all")
    private static boolean id10(final long A, final long B) {
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
        public String toString() {
            return "Pair [fir = " + fir + ", snd = " + snd + "]";
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + ((fir == null) ? 0 : fir.hashCode());
            result = prime * result + ((snd == null) ? 0 : snd.hashCode());
            return result;
        }

        

        @Override
        public boolean equals(final Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            final Pair other = (Pair) obj;
            if (fir == null) {
                if (other.fir != null)
                    return false;
            } else if (!fir.equals(other.fir))
                return false;
            if (snd == null) {
                if (other.snd != null)
                    return false;
            } else if (!snd.equals(other.snd))
                return false;
            return true;
        }

        
        public T getFir() {
            return fir;
        }

        
        public void setFir(final T fir) {
            this.fir = fir;
        }

        
        public E id6() {
            return snd;
        }

        
        public void id2(final E snd) {
            this.snd = snd;
        }

        @Override
        @SuppressWarnings("unchecked")
        public int compareTo(final Pair<T, E> o) {
            final int c = ((Comparable<T>) fir).compareTo(o.fir);
            return c != 0 ? c : ((Comparable<E>) snd).compareTo(o.snd);
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
        public boolean equals(final Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            final pi other = (pi) obj;
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

    @SuppressWarnings("all")
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
    private static void pn(int[] arr) {
        for (int i = 0; i < arr.length - 1; ++i) {
            p(arr[i] + " ");
        }
        pn(arr[arr.length - 1]);
    }

    @SuppressWarnings("all")
    private static void pn(long[] arr) {
        for (int i = 0; i < arr.length - 1; ++i) {
            p(arr[i] + " ");
        }
        pn(arr[arr.length - 1]);
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
            pni("Exception while Object Cloning = " + e);
            throw (e);
        } finally {
            oos.close();
            ois.close();
        }
    }

}