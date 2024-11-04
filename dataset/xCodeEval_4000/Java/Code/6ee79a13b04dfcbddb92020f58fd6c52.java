import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;




public class cf1527d {

    public static void main(String[] args) throws IOException {
        int t = ri();
        while (t --> 0) {
            int n = ri();
            long ans[] = new long[n + 1], sz[] = new long[n], sz1[] = new long[n];
            dep = new int[n];
            anc = new int[n][20];
            for (int[] row : anc) {
                fill(row, -1);
            }
            Graph g = tree(n);
            binary_lifting_dfs(g, 0, -1);
            dfs(g, 0, sz);
            dfs1(g, 0, sz1);
            for (int i : g.get(0)) {
                ans[0] += sz[i] * (sz[i] - 1) / 2;
                ans[1] += sz1[i] * (sz1[0] - 1 - sz1[i] + 2);
            }
            ans[1] /= 2;
            int a = 0, b = 1;
            Set<Integer> in_path = new HashSet<>();
            in_path.add(1);
            int c = 1;
            while (c != 0) {
                in_path.add(c = anc[c][0]);
            }
            for (int i = 2; i < n; ++i) {
                if (in_path.contains(i)) {
                    continue;
                }
                c = -1;
                long sz_a = sz[a], sz_b = sz[b];
                

                if (lca(i, b) == b) {
                    c = b;
                    if (a == 0) {
                        sz_a -= sz[get_anc_that_is_child_of_root(i)];
                    }
                    sz_b -= sz[i];
                } else if (lca(i, a) == a) {
                    c = a;
                    if (a == 0) {
                        if (lca(i, b) != 0) {
                            c = -1;
                            sz_a -= sz[get_anc_that_is_child_of_root(i)];
                        } else {
                            sz_a -= sz[get_anc_that_is_child_of_root(b)];
                        }
                    }
                    if (c != -1) {
                        sz_a -= sz[i];
                    }
                }
                

                ans[i] = sz_a * sz_b;
                int cur = i;
                if (c == a) {
                    while (cur != a) {
                        in_path.add(cur);
                        cur = anc[cur][0];
                    }
                    a = i;
                } else if (c == b) {
                    while (cur != b) {
                        in_path.add(cur);
                        cur = anc[cur][0];
                    }
                    b = i;
                } else {
                    break;
                }
            }
            ans[n] = in_path.size() == n ? 1 : 0;
            
            prln(ans);
        }
        close();
    }

    static int get_anc_that_is_child_of_root(int i) {
        for (int j = anc[i].length - 1; j >= 0; --j) {
            if (dep[i] - (1 << j) > 0) {
                i = anc[i][j];
            }
        }
        return i;
    }

    static void dfs1(Graph g, int i, long sz1[]) {
        sz1[i] = 1;
        for (int j : g.get(i)) {
            if (j != 1 && sz1[j] == 0) {
                dfs1(g, j, sz1);
                sz1[i] += sz1[j];
            }
        }
    }

    static void dfs(Graph g, int i, long sz[]) {
        sz[i] = 1;
        for (int j : g.get(i)) {
            if (sz[j] == 0) {
                dfs(g, j, sz);
                sz[i] += sz[j];
            }
        }
    }

    

    static int dep[], anc[][];

    static int dist(int a, int b) {
        int lca = lca(a, b);
        return (dep[a] - dep[lca]) + (dep[b] - dep[lca]);
    }

    static int lca(int a, int b) {
        if (dep[a] < dep[b]) {
            int __swap = a;
            a = b;
            b = __swap;
        }
        for (int i = anc[a].length - 1; i >= 0; --i) {
            if (dep[a] - (1 << i) >= dep[b]) {
                a = anc[a][i];
            }
        }
        if (a == b) {
            return a;
        } else {
            for (int i = anc[a].length - 1; i >= 0; --i) {
                if (anc[a][i] != anc[b][i]) {
                    a = anc[a][i];
                    b = anc[b][i];
                }
            }
            return anc[a][0];
        }
    }

    static void binary_lifting_dfs(List<? extends Collection<Integer>> g, int i, int p) {
        if (p == -1) {
            dep[i] = 0;
        } else {
            dep[i] = dep[p] + 1;
        }
        anc[i][0] = p;
        for (int j = 1; j < anc[i].length && anc[i][j - 1] >= 0; ++j) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
        for (int n : g.get(i)) {
            if (n != p) {
                binary_lifting_dfs(g, n, i);
            }
        }
    }

    static Graph graph(int n) {
        Graph g = new Graph();
        for (int i = 0; i < n; ++i) {
            g.add(new ArrayList<>());
        }
        return g;
    }

    static Graph graph(int n, int m) throws IOException {
        Graph g = graph(n);
        for (int i = 0; i < m; ++i) {
            g.c(rni(), ni());
        }
        return g;
    }

    static Graph digraph(int n, int m) throws IOException {
        Graph g = graph(n);
        for (int i = 0; i < m; ++i) {
            g.cto(rni() - 1, ni() - 1);
        }
        return g;
    }

    static Graph tree(int n) throws IOException {
        return graph(n, n - 1);
    }

    static Graph graph(List<? extends Collection<Integer>> g) {
        int n = g.size();
        Graph h = graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j : g.get(i)) {
                h.cto(i, j);
            }
        }
        return h;
    }

    static class Graph extends ArrayList<List<Integer>> {
        void cto(int u, int v) {
            get(u).add(v);
        }

        void c(int u, int v) {
            cto(u, v);
            cto(v, u);
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
    static void h() {prln("hlfd"); flush();}
    static void flush() {__o.flush();}
    static void close() {__o.close();}
}