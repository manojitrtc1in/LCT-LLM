import java.io.*;
import java.util.*;




import static java.lang.Math.*;
import static java.util.Arrays.*;

public class cf1304f1 {

    public static void main(String[] args) throws IOException {
        int n = rni(), m = ni(), k = ni(), animals[][] = new int[n][m];
        for (int i = 0; i < n; ++i) {
            r();
            for (int j = 0; j < m; ++j) {
                animals[i][j] = ni();
            }
        }
        long sum[][] = new long[n][m + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                sum[i][j + 1] = sum[i][j] + animals[i][j];
            }
        }
        sgt dp = new sgt(m - k + 1, Math::max, LMIN);
        for (int i = 0; i < n; ++i) {
            sgt ndp = new sgt(m - k + 1, Math::max, LMIN);
            long[] point_qry = new long[m - k + 1];
            for (int j = 0; j <= m - k; ++j) {
                point_qry[j] = dp.qry(j, j + 1);
            }
            for (int j = 0; j <= m - k; ++j) {
                long cnt = sum[i][j + k] - sum[i][j];
                if (i < n - 1){
                    cnt += sum[i + 1][j + k] - sum[i + 1][j];
                }
                if (i == 0) {
                    ndp.upd(j, dp.qry(0, m - k + 1) + cnt);
                } else {
                    ndp.upd(j, dp.qry(0, j - k) + cnt);
                    ndp.upd(j, dp.qry(j + k, m - k + 1) + cnt);
                    long upd = 0;
                    for (int l = max(0, j - k); l < min(j + k, m - k + 1); ++l) {
                        upd = max(upd, point_qry[l] - max(0, min(sum[i][l + k] - sum[i][j], sum[i][j + k] - sum[i][l])) + cnt);
                    }
                    ndp.upd(j, upd);
                }
            }
            dp = ndp;
        }
        prln(dp.qry(0, m - k + 1));
        close();
    }

    @FunctionalInterface
    interface LongOperator {
        long merge(long a, long b);
    }

    static class sgt {
        LongOperator upd_op, qry_op;
        int n;
        long sgt[], id;

        sgt(int sz, LongOperator operator, long identity) {
            n = sz;
            sgt = new long[4 * n + 5];
            upd_op = qry_op = operator;
            id = identity;
        }

        sgt(int sz, LongOperator update_operator, LongOperator query_operator, long identity) {
            n = sz;
            sgt = new long[4 * n + 5];
            upd_op = update_operator;
            qry_op = query_operator;
            id = identity;
        }

        sgt(long[] a, LongOperator operator, long identity) {
            n = a.length;
            sgt = new long[4 * n + 5];
            upd_op = qry_op = operator;
            id = identity;
            build(1, a, 0, n - 1);
        }

        sgt(long[] a, LongOperator update_operator, LongOperator query_operator, long identity) {
            n = a.length;
            sgt = new long[4 * n + 5];
            upd_op = update_operator;
            qry_op = query_operator;
            id = identity;
            build(1, a, 0, n - 1);
        }

        void set(int i, long x) {
            set(1, i, x, 0, n - 1);
        }

        void upd(int i, long x) {
            upd(1, i, x, 0, n - 1);
        }

        long qry(int l, int r) {
            return qry(1, l, r - 1, 0, n - 1);
        }

        void set(int node, int i, long x, int l, int r) {
            if (l == r) {
                sgt[node] = x;
            } else {
                int m = l + (r - l) / 2;
                if (i <= m) {
                    set(node << 1, i, x, l, m);
                } else {
                    set(node << 1 | 1, i, x, m + 1, r);
                }
                pull(node);
            }
        }

        void upd(int node, int i, long x, int l, int r) {
            if (l == r) {
                sgt[node] = upd_op.merge(sgt[node], x);
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

        long qry(int node, int i, int j, int l, int r) {
            if (r < i || j < l) {
                return id;
            } else if (i <= l && r <= j) {
                return sgt[node];
            } else {
                int m = l + (r - l) / 2;
                return qry_op.merge(qry(node << 1, i, j, l, m), qry(node << 1 | 1, i, j, m + 1, r));
            }
        }

        void build(int node, long[] a, int l, int r) {
            if (l == r) {
                sgt[node] = a[l];
            } else {
                int m = l + (r - l) / 2;
                build(node << 1, a, l, m);
                build(node << 1 | 1, a, m + 1, r);
                pull(node);
            }
        }

        void pull(int node) {
            sgt[node] = qry_op.merge(sgt[node << 1], sgt[node << 1 | 1]);
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
    

    static List<List<Integer>> g(int n) {List<List<Integer>> g = new ArrayList<>(); for (int i = 0; i < n; ++i) g.add(new ArrayList<>()); return g;}
    static List<Set<Integer>> sg(int n) {List<Set<Integer>> g = new ArrayList<>(); for (int i = 0; i < n; ++i) g.add(new HashSet<>()); return g;}
    static void c(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).add(v); g.get(v).add(u);}
    static void cto(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).add(v);}
    static void dc(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).remove(v); g.get(v).remove(u);}
    static void dcto(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).remove(v);}
    

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
    static List<List<Integer>> rg(int n, int m) throws IOException {List<List<Integer>> g = g(n); for (int i = 0; i < m; ++i) c(g, rni() - 1, ni() - 1); return g;}
    static void rg(List<List<Integer>> g, int m) throws IOException {for (int i = 0; i < m; ++i) c(g, rni() - 1, ni() - 1);}
    static List<List<Integer>> rdg(int n, int m) throws IOException {List<List<Integer>> g = g(n); for (int i = 0; i < m; ++i) cto(g, rni() - 1, ni() - 1); return g;}
    static void rdg(List<List<Integer>> g, int m) throws IOException {for (int i = 0; i < m; ++i) cto(g, rni() - 1, ni() - 1);}
    static List<Set<Integer>> rsg(int n, int m) throws IOException {List<Set<Integer>> g = sg(n); for (int i = 0; i < m; ++i) c(g, rni() - 1, ni() - 1); return g;}
    static void rsg(List<Set<Integer>> g, int m) throws IOException {for (int i = 0; i < m; ++i) c(g, rni() - 1, ni() - 1);}
    static List<Set<Integer>> rdsg(int n, int m) throws IOException {List<Set<Integer>> g = sg(n); for (int i = 0; i < m; ++i) cto(g, rni() - 1, ni() - 1); return g;}
    static void rdsg(List<Set<Integer>> g, int m) throws IOException {for (int i = 0; i < m; ++i) cto(g, rni() - 1, ni() - 1);}
    

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
    static void pryesno(boolean b) {prln(b ? "yes" : "no");};
    static void pryn(boolean b) {prln(b ? "Yes" : "No");}
    static void prYN(boolean b) {prln(b ? "YES" : "NO");}
    static void prln(int... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static void prln(long... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static void prln(double... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static <T> void prln(Collection<T> c) {int n = c.size() - 1; Iterator<T> iter = c.iterator(); for (int i = 0; i < n; pr(iter.next()), pr(' '), ++i); if (n >= 0) prln(iter.next()); else prln();}
    static void h() {prln("hlfd"); flush();}
    static void flush() {__out.flush();}
    static void close() {__out.close();}
}