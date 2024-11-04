import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class cf1422d {

    public static void main(String[] args) throws IOException {
        int n = rni(), m = ni();
        int sx = rni(), sy = ni(), fx = ni(), fy = ni();
        p ps[] = new p[m + 1];
        ps[0] = new p(sx, sy);
        TreeSet<p> by_x = new TreeSet<>((a, b) -> a.a == b.a ? a.b - b.b : a.a - b.a), by_y = new TreeSet<>((a, b) -> a.b == b.b ? a.a - b.a : a.b - b.b);
        Map<p, Integer> ind = new HashMap<>();
        ind.put(ps[0], 0);
        for (int i = 0; i < m; ++i) {
            p p = new p(rni(), ni());
            by_x.add(p);
            by_y.add(p);
            ps[i + 1] = p;
            ind.put(p, i + 1);
        }
        long dist[] = new long[m + 1];
        fill(dist, LMAX >> 1);
        dist[0] = 0;
        PriorityQueue<pil> q = new PriorityQueue<>((a, b) -> Long.compare(a.b, b.b));
        q.offer(new pil(0, 0));
        while (!q.isEmpty()) {
            pil p = q.poll();
            int i = p.a;
            long d = p.b;
            if (d > dist[i]) {
                continue;
            }
            if (i > 0) {
                by_x.remove(ps[i]);
                by_y.remove(ps[i]);
            }
            p left = by_x.floor(ps[i]), right = by_x.ceiling(ps[i]);
            p down = by_y.floor(ps[i]), up = by_y.ceiling(ps[i]);
            

            

            if (left != null) {
                long nd = d + abs(left.a - ps[i].a);
                int j = ind.get(left);
                if (nd < dist[j]) {
                    dist[j] = nd;
                    q.offer(new pil(j, nd));
                }
            }
            if (right != null) {
                long nd = d + abs(right.a - ps[i].a);
                int j = ind.get(right);
                if (nd < dist[j]) {
                    dist[j] = nd;
                    q.offer(new pil(j, nd));
                }
            }
            if (down != null) {
                long nd = d + abs(down.b - ps[i].b);
                int j = ind.get(down);
                if (nd < dist[j]) {
                    dist[j] = nd;
                    q.offer(new pil(j, nd));
                }
            }
            if (up != null) {
                long nd = d + abs(up.b - ps[i].b);
                int j = ind.get(up);
                if (nd < dist[j]) {
                    dist[j] = nd;
                    q.offer(new pil(j, nd));
                }
            }
        }
        

        long ans = LMAX >> 1;
        for (int i = 0; i <= m; ++i) {
            ans = min(ans, dist[i] + abs(fx - ps[i].a) + abs(fy - ps[i].b));
        }
        prln(ans);
        close();
    }

    static class pil {
        int a;
        long b;

        pil(int a_, long b_) {
            a = a_;
            b = b_;
        }

        @Override
        public String toString() {
            return "Pair{" + "a = " + a + ", b = " + b + '}';
        }

        public boolean asymmetricEquals(Object o) {
            pil p = (pil) o;
            return a == p.a && b == p.b;
        }

        public boolean symmetricEquals(Object o) {
            pil p = (pil) o;
            return a == p.a && b == p.b || a == p.b && b == p.a;
        }

        @Override
        public boolean equals(Object o) {
            return asymmetricEquals(o);
        }

        public int asymmetricHashCode() {
            return Objects.hash(a, b);
        }

        public int symmetricHashCode() {
            return Objects.hash(a, b) + Objects.hash(b, a);
        }

        @Override
        public int hashCode() {
            return asymmetricHashCode();
        }
    }

    static class p {
        int a, b;

        p(int a_, int b_) {
            a = a_;
            b = b_;
        }

        @Override
        public String toString() {
            return "Pair{" + "a = " + a + ", b = " + b + '}';
        }


        public boolean asymmetricEquals(Object o) {
            p p = (p) o;
            return a == p.a && b == p.b;
        }

        public boolean symmetricEquals(Object o) {
            p p = (p) o;
            return a == p.a && b == p.b || a == p.b && b == p.a;
        }

        @Override
        public boolean equals(Object o) {
            return asymmetricEquals(o);
        }

        public int asymmetricHashCode() {
            return Objects.hash(a, b);
        }

        public int symmetricHashCode() {
            return Objects.hash(a, b) + Objects.hash(b, a);
        }

        @Override
        public int hashCode() {
            return asymmetricHashCode();
        }
    }

    

    

    static int[][] dijk(int src, List<List<dijk_P>> adjList) {
        return dijk(src, adjList, IBIG);
    }

    static int[][] dijk(int src, List<List<dijk_P>> adjList, int inf) {
        int n = adjList.size(), dist[] = new int[n], par[] = new int[n];
        fill(dist, inf);
        fill(par, -1);
        dist[src] = 0;
        PriorityQueue<dijk_P> q = new PriorityQueue<>((a, b) -> a.b == b.b ? a.a - b.a : b.b - a.b);
        q.offer(new dijk_P(src, 0));
        while (!q.isEmpty()) {
            dijk_P i = q.poll();
            if (i.b > dist[i.a]) {
                continue;
            }
            for (dijk_P nei : adjList.get(i.a)) {
                int d = i.b + nei.b;
                if (d < dist[nei.a]) {
                    dist[nei.a] = d;
                    par[nei.a] = i.a;
                    q.offer(new dijk_P(nei.a, dist[nei.a]));
                }
            }
        }
        return new int[][]{dist, par};
    }

    static class dijk_P {
        int a, b;

        dijk_P(int a_, int b_) {
            a = a_;
            b = b_;
        }

        @Override
        public String toString() {
            return "Pair{" + "a = " + a + ", b = " + b + '}';
        }

        public boolean equalsSafe(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            dijk_P p = (dijk_P) o;
            return a == p.a && b == p.b;
        }

        public boolean equalsUnchecked(Object o) {
            dijk_P p = (dijk_P) o;
            return a == p.a && b == p.b;
        }

        @Override
        public boolean equals(Object o) {
            return equalsUnchecked(o);
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b);
        }
    }

    static BufferedReader __in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter __out = new PrintWriter(new OutputStreamWriter(System.out));
    static StringTokenizer input;
    static Random __rand = new Random();

    

    

    

    


    

    static final int IBIG = 1000000007;
    static final int IMAX = 2147483647;
    static final int IMIN = -2147483648;
    static final long LMAX = 9223372036854775807L;
    static final long LMIN = -9223372036854775808L;
    

    static int minof(int a, int b, int c) {return min(a, min(b, c));}
    static int minof(int... x) {if (x.length == 1) return x[0]; if (x.length == 2) return min(x[0], x[1]); if (x.length == 3) return min(x[0], min(x[1], x[2])); int min = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] < min) min = x[i]; return min;}
    static long minof(long a, long b, long c) {return min(a, min(b, c));}
    static long minof(long... x) {if (x.length == 1) return x[0]; if (x.length == 2) return min(x[0], x[1]); if (x.length == 3) return min(x[0], min(x[1], x[2])); long min = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] < min) min = x[i]; return min;}
    static int maxof(int a, int b, int c) {return max(a, max(b, c));}
    static int maxof(int... x) {if (x.length == 1) return x[0]; if (x.length == 2) return max(x[0], x[1]); if (x.length == 3) return max(x[0], max(x[1], x[2])); int max = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] > max) max = x[i]; return max;}
    static long maxof(long a, long b, long c) {return max(a, max(b, c));}
    static long maxof(long... x) {if (x.length == 1) return x[0]; if (x.length == 2) return max(x[0], x[1]); if (x.length == 3) return max(x[0], max(x[1], x[2])); long max = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] > max) max = x[i]; return max;}
    static int powi(int a, int b) {if (a == 0) return 0; int ans = 1; while (b > 0) {if ((b & 1) > 0) ans *= a; a *= a; b >>= 1;} return ans;}
    static long powl(long a, int b) {if (a == 0) return 0; long ans = 1; while (b > 0) {if ((b & 1) > 0) ans *= a; a *= a; b >>= 1;} return ans;}
    static int fli(double d) {return (int) d;}
    static int cei(double d) {return (int) ceil(d);}
    static long fll(double d) {return (long) d;}
    static long cel(double d) {return (long) ceil(d);}
    static int gcf(int a, int b) {return b == 0 ? a : gcf(b, a % b);}
    static long gcf(long a, long b) {return b == 0 ? a : gcf(b, a % b);}
    static int lcm(int a, int b) {return a * b / gcf(a, b);}
    static long lcm(long a, long b) {return a * b / gcf(a, b);}
    static int randInt(int min, int max) {return __rand.nextInt(max - min + 1) + min;}
    static long mix(long x) {x += 0x9e3779b97f4a7c15L; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9L; x = (x ^ (x >> 27)) * 0x94d049bb133111ebL; return x ^ (x >> 31);}
    

    static void reverse(int[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {int swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(long[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {long swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(double[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {double swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(char[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {char swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void shuffle(int[] a) {int n = a.length - 1; for (int i = 0; i < n; ++i) {int ind = randInt(i, n); int swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(long[] a) {int n = a.length - 1; for (int i = 0; i < n; ++i) {int ind = randInt(i, n); long swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(double[] a) {int n = a.length - 1; for (int i = 0; i < n; ++i) {int ind = randInt(i, n); double swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void rsort(int[] a) {shuffle(a); sort(a);}
    static void rsort(long[] a) {shuffle(a); sort(a);}
    static void rsort(double[] a) {shuffle(a); sort(a);}
    static int[] copy(int[] a) {int[] ans = new int[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static long[] copy(long[] a) {long[] ans = new long[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static double[] copy(double[] a) {double[] ans = new double[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static char[] copy(char[] a) {char[] ans = new char[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    

    static void r() throws IOException {input = new StringTokenizer(rline());}
    static int ri() throws IOException {return Integer.parseInt(rline());}
    static long rl() throws IOException {return Long.parseLong(rline());}
    static double rd() throws IOException {return Double.parseDouble(rline());}
    static int[] ria(int n) throws IOException {int[] a = new int[n]; r(); for (int i = 0; i < n; ++i) a[i] = ni(); return a;}
    static int[] riam1(int n) throws IOException {int[] a = new int[n]; r(); for (int i = 0; i < n; ++i) a[i] = ni() - 1; return a;}
    static long[] rla(int n) throws IOException {long[] a = new long[n]; r(); for (int i = 0; i < n; ++i) a[i] = nl(); return a;}
    static double[] rda(int n) throws IOException {double[] a = new double[n]; r(); for (int i = 0; i < n; ++i) a[i] = nd(); return a;}
    static char[] rcha() throws IOException {return rline().toCharArray();}
    static String rline() throws IOException {return __in.readLine();}
    static String n() {return input.nextToken();}
    static int rni() throws IOException {r(); return ni();}
    static int ni() {return Integer.parseInt(n());}
    static long rnl() throws IOException {r(); return nl();}
    static long nl() {return Long.parseLong(n());}
    static double rnd() throws IOException {r(); return nd();}
    static double nd() {return Double.parseDouble(n());}
    

    static void pr(int i) {__out.print(i);}
    static void prln(int i) {__out.println(i);}
    static void pr(long l) {__out.print(l);}
    static void prln(long l) {__out.println(l);}
    static void pr(double d) {__out.print(d);}
    static void prln(double d) {__out.println(d);}
    static void pr(char c) {__out.print(c);}
    static void prln(char c) {__out.println(c);}
    static void pr(char[] s) {__out.print(new String(s));}
    static void prln(char[] s) {__out.println(new String(s));}
    static void pr(String s) {__out.print(s);}
    static void prln(String s) {__out.println(s);}
    static void pr(Object o) {__out.print(o);}
    static void prln(Object o) {__out.println(o);}
    static void prln() {__out.println();}
    static void pryes() {prln("yes");}
    static void pry() {prln("Yes");}
    static void prY() {prln("YES");}
    static void prno() {prln("no");}
    static void prn() {prln("No");}
    static void prN() {prln("NO");}
    static boolean pryesno(boolean b) {prln(b ? "yes" : "no"); return b;};
    static boolean pryn(boolean b) {prln(b ? "Yes" : "No"); return b;}
    static boolean prYN(boolean b) {prln(b ? "YES" : "NO"); return b;}
    static void prln(int... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static void prln(long... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static void prln(double... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static <T> void prln(Collection<T> c) {int n = c.size() - 1; Iterator<T> iter = c.iterator(); for (int i = 0; i < n; pr(iter.next()), pr(' '), ++i); if (n >= 0) prln(iter.next()); else prln();}
    static void h() {prln("hlfd"); flush();}
    static void flush() {__out.flush();}
    static void close() {__out.close();}
}