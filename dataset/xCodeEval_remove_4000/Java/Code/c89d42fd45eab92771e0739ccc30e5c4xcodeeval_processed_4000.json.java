import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class id1 {

    public static void main(String[] args) throws IOException {
        int T = ri();
        next: while (T --> 0) {
            int n = rni(), m = ni(), a[] = ria(n), k[] = new int[m], b[][] = new int[m][], sk = 0;
            double avg[] = new double[m];
            for (int i = 0; i < m; ++i) {
                k[i] = ri();
                sk += k[i];
                b[i] = ria(k[i]);
                for (int j = 0; j < k[i]; ++j) {
                    avg[i] += b[i][j];
                }
                avg[i] /= k[i];
            }
            double sorted[][] = new double[n + m][3];
            for (int i = 0; i < n; ++i) {
                sorted[i][0] = a[i];
                sorted[i][1] = i;
                sorted[i][2] = 1;
            }
            for (int i = 0; i < m; ++i) {
                sorted[n + i][0] = avg[i];
                sorted[n + i][1] = n + i;
            }
            sort(sorted, (x, y) -> x[0] == y[0] ? Double.compare(y[2], x[2]) : Double.compare(y[0], x[0]));
            int pos[] = new int[m];
            for (int i = 0; i < n + m; ++i) {
                if (sorted[i][2] == 0) {
                    pos[(int) sorted[i][1] - n] = i + 1;
                }
            }
            int bal[] = new int[n + m + 1], id5 = n + m, id0 = -1;
            boolean bad = false;
            for (int i = 0; i < n + m; ++i) {
                bal[i + 1] = bal[i] + (int) sorted[i][2] * 2 - 1;
                if (bal[i + 1] == -1) {
                    id5 = min(id5, i + 1);
                    id0 = max(id0, i + 1);
                } else if (bal[i + 1] == -2) {
                    bad = true;
                }
            }














            sgt sgt = new sgt(bal, Integer::min, IBIG);
            StringBuilder ans = new StringBuilder();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < k[i]; ++j) {
                    if (bad) {
                        ans.append('0');
                        continue;
                    }
                    double navg = (avg[i] * k[i] - b[i][j]) / (k[i] - 1);


                    if (navg >= avg[i]) {


                        if (id5 != n + m) {


                            ans.append('0');
                            continue;
                        }
                        int ind = minst(1, pos[i] - 1, jnd -> sorted[jnd - 1][0] < navg);


                        if (sgt.qry(ind - 1, pos[i] - 1) <= 0) {
                            ans.append('0');
                        } else {
                            ans.append('1');
                        }
                    } else {


                        if (id5 == n + m) {


                            ans.append('1');
                            continue;
                        }
                        int ind = maxst(pos[i] + 1, n + m, jnd -> sorted[jnd - 1][0] >= navg);


                        if (pos[i] <= id5 && id0 < ind) {
                            ans.append('1');
                        } else {
                            ans.append('0');
                        }
                    }
                }
            }
            prln(ans);
        }
        close();
    }

    @FunctionalInterface
    interface IntCondition {
        boolean check(int x);
    }

    static int maxst(int min, int max, IntCondition condition) {
        int ans = min - 1;
        for (int l = min, r = max, m; l <= r; ) {
            if (condition.check(m = l + (r - l) / 2)) l = (ans = m) + 1;
            else r = m - 1;
        }
        return ans;
    }

    static int minst(int min, int max, IntCondition condition) {
        int ans = max + 1;
        for (int l = min, r = max, m; l <= r; ) {
            if (condition.check(m = l + (r - l) / 2)) r = (ans = m) - 1;
            else l = m + 1;
        }
        return ans;
    }

    @FunctionalInterface
    interface IntOperator {
        int merge(int a, int b);
    }

    @FunctionalInterface
    interface IntAction {
        void apply(int x);
    }

    static class sgt {
        IntOperator upd_op, qry_op;
        int n, sgt[], lazy[], id;

        sgt(int sz, IntOperator operator, int identity) {
            n = sz;
            sgt = new int[4 * n + 5];
            lazy = new int[4 * n + 5];
            upd_op = qry_op = operator;
            id = identity;
            int a[] = new int[n];
            fill(a, id);
            build(1, a, 0, n - 1);
        }

        sgt(int sz, IntOperator update_operator, IntOperator query_operator, int identity) {
            n = sz;
            sgt = new int[4 * n + 5];
            lazy = new int[4 * n + 5];
            upd_op = update_operator;
            qry_op = query_operator;
            id = identity;
            int a[] = new int[n];
            fill(a, id);
            build(1, a, 0, n - 1);
        }

        sgt(int[] a, IntOperator operator, int identity) {
            n = a.length;
            sgt = new int[4 * n + 5];
            lazy = new int[4 * n + 5];
            upd_op = qry_op = operator;
            id = identity;
            build(1, a, 0, n - 1);
        }

        sgt(int[] a, IntOperator update_operator, IntOperator query_operator, int identity) {
            n = a.length;
            sgt = new int[4 * n + 5];
            lazy = new int[4 * n + 5];
            upd_op = update_operator;
            qry_op = query_operator;
            id = identity;
            build(1, a, 0, n - 1);
        }

        void set(int i, int x) {
            set(1, i, x, 0, n - 1);
        }

        void upd(int i, int j, int x) {
            upd(1, i, j, x, 0, n - 1);
        }

        void upd(int i, int x) {
            upd(1, i, x, 0, n - 1);
        }

        int qry(int l, int r) {
            return qry(1, l, r, 0, n - 1);
        }

        int qry(int i) {
            return qry(1, i, i, 0, n - 1);
        }

        void set(int node, int i, int x, int l, int r) {
            push(node, l, r);
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

        void upd(int node, int i, int x, int l, int r) {
            push(node, l, r);
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

        void upd(int node, int i, int j, int x, int l, int r) {
            push(node, l, r);
            if (r < i || j < l) {
                return;
            } else if (i <= l && r <= j) {
                lazy[node] = x;
                push(node, l, r);
            } else {
                int m = l + (r - l) / 2;
                upd(node << 1, i, j, x, l, m);
                upd(node << 1 | 1, i, j, x, m + 1, r);
                pull(node);
            }
        }

        int qry(int node, int i, int j, int l, int r) {
            push(node, l, r);
            if (r < i || j < l) {
                return id;
            } else if (i <= l && r <= j) {
                return sgt[node];
            } else {
                int m = l + (r - l) / 2;
                return qry_op.merge(qry(node << 1, i, j, l, m), qry(node << 1 | 1, i, j, m + 1, r));
            }
        }

        void build(int node, int[] a, int l, int r) {
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

        void push(int node, int l, int r) {
            

            if (l != r) {
                

                

            }
            lazy[node] = 0;
        }

        void traverse(IntAction a) {
            traverse(a, 1, 0, n - 1);
        }

        void traverse(IntAction a, int node, int l, int r) {
            push(node, l, r);
            if (l == r) {
                a.apply(sgt[node]);
            } else {
                int m = l + (r - l) / 2;
                traverse(a, node << 1, l, m);
                traverse(a, node << 1 | 1, m + 1, r);
            }
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
    static int[] id2(int a, int b) {if (b == 0) return new int[] {1, 0, a}; int[] y = id2(b, a % b); return new int[] {y[1], y[0] - y[1] * (a / b), y[2]};}
    static long[] id2(long a, long b) {if (b == 0) return new long[] {1, 0, a}; long[] y = id2(b, a % b); return new long[] {y[1], y[0] - y[1] * (a / b), y[2]};}
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
    static int[] id4(int n) throws IOException {int[] a = new int[n]; r(); for (int i = 0; i < n; ++i) a[i] = ni() - 1; return a;}
    static void id4(int[] a) throws IOException {int n = a.length; r(); for (int i = 0; i < n; ++i) a[i] = ni() - 1;}
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
    static boolean id3(boolean b) {prln(b ? "yes" : "no"); return b;};
    static boolean pryn(boolean b) {prln(b ? "Yes" : "No"); return b;}
    static boolean prYN(boolean b) {prln(b ? "YES" : "NO"); return b;}
    static void prln(int... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static void prln(long... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static void prln(double... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static <T> void prln(Collection<T> c) {int n = c.size() - 1; Iterator<T> iter = c.iterator(); for (int i = 0; i < n; pr(iter.next()), pr(' '), ++i); if (n >= 0) prln(iter.next()); else prln();}
    static void h() {prln("hlfd"); flush();}
    static void flush() {__o.flush();}
    static void close() {__o.close();}
}