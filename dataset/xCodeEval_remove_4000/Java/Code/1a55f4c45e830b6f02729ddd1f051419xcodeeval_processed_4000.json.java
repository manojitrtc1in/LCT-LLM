import java.io.*;
import java.util.*;

import static java.util.Collections.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class cf {

    private static final int MOD = (int) (1e9 + 7), id3 = 998244353;
    private static final Reader r = new Reader();
    private static final PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    private static final boolean thread = false;
    static final boolean id2 = true;
    static final int id0 = 1000002;

    static int n, a[], e[][];

    private static Vector<Integer> adj[], v = new Vector<>();
    private static Vector<pi> g;

    static void solve() throws Exception {
        int n = ni(), m = ni();
        g = new Vector<>();
        e = new int[n][m];
        for (int i = 0; i < e.length; i++) {
            char s[] = n().toCharArray();
            for (int j = 0; j < s.length; j++) {
                e[i][j] = s[j] - '0';
            }

        }
        

        

        

        

        

        for (int i = 0; i < e.length - 1; i += 2) {
            for (int j = 0; j < (e[0].length - 2); j += 1) {
                cc(i, j);
            }
            check(i, m - 2);
        }
        if (n % 2 == 1) {
            int i = n - 2;
            for (int j = 0; j < (e[0].length - 2); j += 1) {
                cc(i, j);
            }
            check(i, m - 2);
        }
        

        

        

        

        

        

        

        

        pn(g.size() / 3);
        for (int i = 0; i < g.size(); i += 3) {
            p((g.get(i).fir + 1) + " " + (g.get(i).snd + 1) + " ");
            p((g.get(i + 1).fir + 1) + " " + (g.get(i + 1).snd + 1) + " ");
            p((g.get(i + 2).fir + 1) + " " + (g.get(i + 2).snd + 1));
            pn();
        }
    }

    private static void cc(int i, int j) {
        if (e[i][j] == 0 && e[i + 1][j] == 0)
            return;
        if (e[i][j] == 0) {
            e[i + 1][j] = 0;
            g.add(new pi(i + 1, j));

            e[i + 1][j + 1] ^= 1;
            g.add(new pi(i + 1, j + 1));
            e[i][j + 1] ^= 1;
            g.add(new pi(i, j + 1));

        } else if (e[i + 1][j] == 0) {
            e[i][j] = 0;
            g.add(new pi(i, j));
            e[i + 1][j + 1] ^= 1;
            g.add(new pi(i + 1, j + 1));
            e[i][j + 1] ^= 1;
            g.add(new pi(i, j + 1));

        } else {
            e[i + 1][j] = 0;
            g.add(new pi(i + 1, j));
            e[i][j] = 0;
            g.add(new pi(i, j));
            e[i][j + 1] ^= 1;
            g.add(new pi(i, j + 1));
        }
    }

    private static void check(int i, int j) {
        int c = 0;
        if (e[i][j] == 1)
            c++;
        if (e[i + 1][j + 1] == 1)
            c++;
        if (e[i][j + 1] == 1)
            c++;
        if (e[i + 1][j] == 1)
            c++;
        if (c == 0)
            return;
        if (c == 3) {
            case3(i, j);
        } else if (c == 2) {
            case2(i, j);
            case3(i, j);
        } else if (c == 4) {
            if (e[i][j] == 1) {
                g.add(new pi(i, j));
                e[i][j] = 0;
            }
            if (e[i + 1][j] == 1) {
                g.add(new pi(i + 1, j));
                e[i + 1][j] = 0;
            }
            if (e[i][j + 1] == 1) {
                g.add(new pi(i, j + 1));
                e[i][j + 1] = 0;
            }
            case1(i, j);
        } else {
            case1(i, j);
        }
    }

    private static void case1(int i, int j) {
        if (e[i][j] == 1) {
            g.add(new pi(i, j));
            e[i][j] = 0;

            g.add(new pi(i + 1, j + 1));
            e[i + 1][j + 1] = 1;
            g.add(new pi(i + 1, j));
            e[i + 1][j] = 1;
        } else if (e[i + 1][j] == 1) {
            g.add(new pi(i + 1, j));
            e[i + 1][j] = 0;

            g.add(new pi(i + 1, j + 1));
            e[i + 1][j + 1] = 1;
            g.add(new pi(i, j));
            e[i][j] = 1;
        } else if (e[i][j + 1] == 1) {
            g.add(new pi(i, j + 1));
            e[i][j + 1] = 0;

            g.add(new pi(i + 1, j + 1));
            e[i + 1][j + 1] = 1;
            g.add(new pi(i + 1, j));
            e[i + 1][j] = 1;
        } else if (e[i + 1][j + 1] == 1) {
            g.add(new pi(i + 1, j + 1));
            e[i + 1][j + 1] = 0;

            g.add(new pi(i + 1, j));
            e[i + 1][j] = 1;
            g.add(new pi(i, j));
            e[i][j] = 1;
        }
        case2(i, j);
        case3(i, j);
    }

    private static void case2(int i, int j) {
        int i1 = -1, j1 = -1;
        int ii0 = -1, jj0 = -1, ii1 = -1, jj1 = -1;
        if (e[i][j] == 1) {
            i1 = i;
            j1 = j;
        }
        if (e[i + 1][j] == 1) {
            i1 = i + 1;
            j1 = j;
        }
        if (e[i][j + 1] == 1) {
            i1 = i;
            j1 = j + 1;
        }
        if (e[i + 1][j + 1] == 1) {
            i1 = i + 1;
            j1 = j + 1;
        }
        if (e[i][j] == 0) {
            if (ii0 != -1) {
                ii1 = i;
                jj1 = j;
            } else {
                ii0 = i;
                jj0 = j;
            }
        }
        if (e[i + 1][j] == 0) {
            if (ii0 != -1) {
                ii1 = i + 1;
                jj1 = j;
            } else {
                ii0 = i + 1;
                jj0 = j;
            }
        }
        if (e[i][j + 1] == 0) {
            if (ii0 != -1) {
                ii1 = i;
                jj1 = j + 1;
            } else {
                ii0 = i;
                jj0 = j + 1;
            }
        }
        if (e[i + 1][j + 1] == 0) {
            if (ii0 != -1) {
                ii1 = i + 1;
                jj1 = j + 1;
            } else {
                ii0 = i + 1;
                jj0 = j + 1;
            }
        }
        g.add(new pi(i1, j1));
        e[i1][j1] = 0;
        g.add(new pi(ii0, jj0));
        g.add(new pi(ii1, jj1));
        e[ii1][jj1] = 1;
        e[ii0][jj0] = 1;
    }

    private static void case3(int i, int j) {
        if (e[i][j] == 1) {
            g.add(new pi(i, j));
            e[i][j] = 0;
        }
        if (e[i + 1][j] == 1) {
            g.add(new pi(i + 1, j));
            e[i + 1][j] = 0;
        }
        if (e[i][j + 1] == 1) {
            g.add(new pi(i, j + 1));
            e[i][j + 1] = 0;
        }
        if (e[i + 1][j + 1] == 1) {
            g.add(new pi(i + 1, j + 1));
            e[i + 1][j + 1] = 0;
        }
    }

    public static void main(final String[] args) throws Exception {
        if (!thread) {
            final int testcases = id2 ? ni() : 1;
            for (int i = 1; i <= testcases; i++) {
                

                

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

    private static void swap(final int i, final int j) {
        final int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    private static boolean id4(final long A, final long B) {
        if (A == 0 || B == 0)
            return false;
        final long result = A * B;
        if (A == result / B)
            return true;
        return false;
    }

    private static int gcd(final int a, final int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

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
            return c != 0 ? c : ((Comparable<E>) snd).compareTo(o.snd);
        }

    }

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

    private static <T> void checkV(final Vector<T> adj[], final int i) {
        adj[i] = adj[i] == null ? new Vector<>() : adj[i];
    }

    private static int[] na(final int n) throws Exception {
        final int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = ni();
        }
        return a;
    }

    private static int[] na1(final int n) throws Exception {
        final int[] a = new int[n + 1];
        for (int i = 1; i < a.length; i++) {
            a[i] = ni();
        }
        return a;
    }

    private static String n() throws IOException {
        return r.readToken();
    }

    private static String nln() throws IOException {
        return r.readLine();
    }

    private static int ni() throws IOException {
        return r.nextInt();
    }

    private static long nl() throws IOException {
        return r.nextLong();
    }

    private static double nd() throws IOException {
        return r.nextDouble();
    }

    private static void p(final Object o) {
        out.print(o);
    }

    private static void pn(final Object o) {
        out.println(o);
    }

    private static void pn() {
        out.println("");
    }

    private static void pi(final Object o) {
        out.print(o);
        out.flush();
    }

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

    static {
        if (thread)
            new Thread(null, new Runnable() {
                @Override
                public void run() {
                    try {
                        final int testcases = id2 ? ni() : 1;
                        for (int i = 1; i <= testcases; i++) {
                            

                            try {
                                solve();
                            } catch (final ArrayIndexOutOfBoundsException e) {
                                e.printStackTrace(System.err);
                                System.exit(-1);
                            } catch (final Exception e) {
                                pni("idk Exception in solve");
                                e.printStackTrace(System.err);
                                System.exit(-1);
                            }
                        }
                        out.flush();
                    } catch (final Throwable t) {
                        t.printStackTrace(System.err);
                        System.exit(-1);
                    }
                }
            }, "rec", (1L << 28)).start();
    }

    @SuppressWarnings({ "unchecked", })
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