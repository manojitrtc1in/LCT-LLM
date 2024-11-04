import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class cf1552e_2 {

    public static void main(String[] args) throws IOException {
        int n = rni(), k = ni(), c[] = riam1(n * k), last[] = new int[n], ans[][] = new int[n][2], left[] = new int[n * k];
        fill(last, -1);
        p ints[][] = new p[n][k - 1];
        int inds[] = new int[n];
        for (int i = 0; i < n * k; ++i) {
            if (last[c[i]] != -1) {
                ints[c[i]][inds[c[i]]++] = new p(last[c[i]], i);
                left[i] = last[c[i]];
            }
            last[c[i]] = i;
        }
        int layers = (n + k - 2) / (k - 1);
        for (int i = 0; i < layers; ++i) {
            List<p> nints = new ArrayList<>();
            for (int j = 0; j < n; ++j) {
                if (ans[j][0] == 0) {
                    for (int l = 0; l < k - 1; ++l) {
                        nints.add(ints[j][l]);
                    }
                }
            }
            nints.sort((a, b) -> a.b - b.b);
            boolean[] used = new boolean[n];
            int nlast = -1;
            for (p p : nints) {
                if (!used[c[p.a]] && p.a > nlast) {
                    ans[c[p.a]][0] = p.a + 1;
                    ans[c[p.b]][1] = p.b + 1;
                    nlast = p.b;
                    used[c[p.a]] = true;
                }
            }
        }
        for (int[] row : ans) {
            prln(row);
        }
        close();
    }

    static class sgt {
        int n, sgt[], ind[];

        sgt(int sz) {
            n = sz;
            sgt = new int[4 * n + 5];
            ind = new int[4 * n + 5];
            build(1, 0, n - 1);
        }

        void upd(int i, int x) {
            upd(1, i, x, 0, n - 1);
        }

        p qry(int l, int r) {
            return qry(1, l, r, 0, n - 1);
        }

        void upd(int node, int i, int x, int l, int r) {
            if (l == r) {
                sgt[node] = max(sgt[node], x);
            } else {
                int m = l + (r - l) / 2;
                if (i <= m) {
                    upd(node << 1, i, x, l, m);
                } else {
                    upd(node << 1 | 1, i, x, m + 1, r);
                }
                pull(node);
            }
        }

        p qry(int node, int i, int j, int l, int r) {
            if (r < i || j < l) {
                return new p(-1, 0);
            } else if (i <= l && r <= j) {
                return new p(ind[node], sgt[node]);
            } else {
                int m = l + (r - l) / 2;
                p left = qry(node << 1, i, j, l, m);
                p right = qry(node << 1 | 1, i, j, m + 1, r);
                return left.b > right.b ? left : right;
            }
        }

        void build(int node, int l, int r) {
            if (l == r) {
                ind[node] = l;
            } else {
                int m = l + (r - l) / 2;
                build(node << 1, l, m);
                build(node << 1 | 1, m + 1, r);
                pull(node);
            }
        }

        void traverse(p[] ans) {
            traverse(1, ans, 0, n - 1);
        }

        void traverse(int node, p[] ans, int l, int r) {
            if (l == r) {
                ans[l] = new p(ind[node], sgt[node]);
            } else {
                int m = l + (r - l) / 2;
                traverse(node << 1, ans, l, m);
                traverse(node << 1 | 1, ans, m + 1, r);
            }
        }

        void pull(int node) {
            sgt[node] = max(sgt[node << 1], sgt[node << 1 | 1]);
            ind[node] = sgt[node << 1] > sgt[node << 1 | 1] ? ind[node << 1] : ind[node << 1 | 1];
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

    static BufferedReader __i = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter __o = new PrintWriter(new OutputStreamWriter(System.out));
    static StringTokenizer input;
    static Random __r = new Random();

    

    

    

    


    

    static final int IBIG = 1000000007;
    static final int IMAX = 2147483647;
    static final long LMAX = 9223372036854775807L;
    

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
    static int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
    static long gcd(long a, long b) {return b == 0 ? a : gcd(b, a % b);}
    static int[] exgcd(int a, int b) {if (b == 0) return new int[] {1, 0}; int[] y = exgcd(b, a % b); return new int[] {y[1], y[0] - y[1] * (a / b)};}
    static long[] exgcd(long a, long b) {if (b == 0) return new long[] {1, 0}; long[] y = exgcd(b, a % b); return new long[] {y[1], y[0] - y[1] * (a / b)};}
    static int randInt(int min, int max) {return __r.nextInt(max - min + 1) + min;}
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
    static void ria(int[] a) throws IOException {int n = a.length; r(); for (int i = 0; i < n; ++i) a[i] = ni();}
    static int[] riam1(int n) throws IOException {int[] a = new int[n]; r(); for (int i = 0; i < n; ++i) a[i] = ni() - 1; return a;}
    static void riam1(int[] a) throws IOException {int n = a.length; r(); for (int i = 0; i < n; ++i) a[i] = ni() - 1;}
    static long[] rla(int n) throws IOException {long[] a = new long[n]; r(); for (int i = 0; i < n; ++i) a[i] = nl(); return a;}
    static void rla(long[] a) throws IOException {int n = a.length; r(); for (int i = 0; i < n; ++i) a[i] = nl();}
    static double[] rda(int n) throws IOException {double[] a = new double[n]; r(); for (int i = 0; i < n; ++i) a[i] = nd(); return a;}
    static void rda(double[] a) throws IOException {int n = a.length; r(); for (int i = 0; i < n; ++i) a[i] = nd();}
    static char[] rcha() throws IOException {return rline().toCharArray();}
    static void rcha(char[] a) throws IOException {int n = a.length, i = 0; for (char c : rline().toCharArray()) a[i++] = c;}
    static String rline() throws IOException {return __i.readLine();}
    static String n() {return input.nextToken();}
    static int rni() throws IOException {r(); return ni();}
    static int ni() {return Integer.parseInt(n());}
    static long rnl() throws IOException {r(); return nl();}
    static long nl() {return Long.parseLong(n());}
    static double rnd() throws IOException {r(); return nd();}
    static double nd() {return Double.parseDouble(n());}
    

    static void pr(int i) {__o.print(i);}
    static void prln(int i) {__o.println(i);}
    static void pr(long l) {__o.print(l);}
    static void prln(long l) {__o.println(l);}
    static void pr(double d) {__o.print(d);}
    static void prln(double d) {__o.println(d);}
    static void pr(char c) {__o.print(c);}
    static void prln(char c) {__o.println(c);}
    static void pr(char[] s) {__o.print(new String(s));}
    static void prln(char[] s) {__o.println(new String(s));}
    static void pr(String s) {__o.print(s);}
    static void prln(String s) {__o.println(s);}
    static void pr(Object o) {__o.print(o);}
    static void prln(Object o) {__o.println(o);}
    static void prln() {__o.println();}
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
    static <T> void prln(T[] a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static void h() {prln("hlfd"); flush();}
    static void flush() {__o.flush();}
    static void close() {__o.close();}
}