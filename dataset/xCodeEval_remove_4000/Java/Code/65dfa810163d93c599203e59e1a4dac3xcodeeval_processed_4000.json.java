import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;




public class id13 {

    public static void main(String[] args) throws IOException {
        int t = ri();
        next: while (t --> 0) {
            int n = rni(), a = ni() - 1, b = ni() - 1, par[] = new int[n], maxdep[] = new int[n];
            int id14[] = new int[n], id11[] = new int[n];
            Graph g = tree(n);
            init(g, a, -1, par, b, id14, id11);
            par[b] = -1;
            for (int i = 0; i < n; ++i) {
                if (par[i] == -1) {
                    id2(g, i, par, maxdep);
                } else {
                    id14[i] = 0;
                }
            }
            

            


            int l = id14[b], anc[][] = new int[n][20], id12[] = new int[n];
            for (int i = 0; i < n; ++i) {
                anc[i][0] = par[i];
                id12[i] = i;
            }
            for (int j = 1; j < 20; ++j) {
                for (int i = 0; i < n; ++i) {
                    anc[i][j] = anc[i][j - 1] == -1 ? -1 : anc[anc[i][j - 1]][j - 1];
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 20; ++j) {
                    if (((l - 1) & (1 << j)) != 0) {
                        id12[i] = id12[i] == -1 ? -1 : anc[id12[i]][j];
                    }
                }
            }
            boolean[] id18 = new boolean[n];
            for (int i = 0; i < n; ++i) {
                if (id12[i] != -1) {
                    id18[id12[i]] = true;
                }
            }

            

            

            

            


            boolean id8[] = new boolean[n], id7[] = new boolean[n];
            int[] id17 = new int[l + 1], id5 = new int[l + 1];
            id3(g, a, id14, id17);
            id3(g, b, id11, id5);
            Queue<Integer> id6 = new LinkedList<>(), id0 = new LinkedList<>();
            id6.offer(a);
            id0.offer(b);
            int ind_a = 1, ind_b = 1;
            while (!id6.isEmpty() || !id0.isEmpty()) {
                int i;
                if (!id6.isEmpty()) {
                    i = id6.poll();
                    id8[i] = true;
                    while (ind_b <= min(l - 1, maxdep[i] - id14[i])) {
                        id0.offer(id5[ind_b++]);
                    }
                } else {
                    i = id0.poll();
                    id7[i] = true;
                    while (ind_a <= min(l - 1, maxdep[i] - id11[i])) {
                        id6.offer(id17[ind_a++]);
                    }
                }
            }
            

            

            for (int i = 0; i < n; ++i) {
                if (par[i] == -1 && id20(g, i, par, id18) && (id8[i] || id7[i])) {
                    

                    

                    prY();
                    continue next;
                }
            }

            

            int id1[] = new int[n], id10[] = new int[n];
            id4(g, a, id14, id1, id8, maxdep, 0);
            id4(g, b, id11, id10, id7, maxdep, 0);
            for (int i = 0; i < n; ++i) {
                if (par[i] == -1 && i != a && i != b && maxdep[i] >= l && id10[i] >= l && id1[i] >= l) {
                    

                    

                    prY();
                    continue next;
                }
            }

            prN();
        }
        close();
    }

    static void id4(Graph g, int i, int[] d_from, int[] id19, boolean[] good_from, int[] maxdep, int cur) {
        id19[i] = cur;
        for (int j : g.get(i)) {
            if (d_from[j] == d_from[i] + 1) {
                id4(g, j, d_from, id19, good_from, maxdep, max(cur, good_from[i] ? maxdep[i] : cur) + 1);
            }
        }
    }

    static void id3(Graph g, int i, int[] d_from, int[] snake) {
        snake[d_from[i]] = i;
        for (int j : g.get(i)) {
            if (d_from[j] == d_from[i] + 1) {
                id3(g, j, d_from, snake);
            }
        }
    }

    static void id9(Graph g, int i, int[] d_from, int[] maxdep, int cur, int l, boolean[] good) {
        if (++cur >= l) {
            good[i] = true;
            cur = max(cur, d_from[i] + l - maxdep[i]);
        }
        good[i] = cur >= l;
        for (int j : g.get(i)) {
            if (d_from[j] == d_from[i] + 1) {
                id9(g, j, d_from, maxdep, cur, l, good);
            }
        }
    }

    static void id2(Graph g, int i, int[] par, int[] maxdep) {
        if (par[i] != -1) {
            maxdep[i] = maxdep[par[i]] + 1;
        }
        for (int j : g.get(i)) {
            if (par[j] == i) {
                id2(g, j, par, maxdep);
            }
        }
        for (int j : g.get(i)) {
            if (par[j] == i) {
                maxdep[i] = max(maxdep[i], maxdep[j]);
            }
        }
    }

    static boolean id20(Graph g, int i, int[] par, boolean[] id18) {
        int cnt = 0;
        for (int j : g.get(i)) {
            if (par[j] == i) {
                if (id20(g, j, par, id18)) {
                    return true;
                }
                

                if (id18[j] && ++cnt == 2) {
                    return true;
                }
            }
        }
        return false;
    }

    static boolean init(Graph g, int i, int p, int par[], int b, int[] id14, int[] id11) {
        par[i] = p;
        if (p != -1) {
            id14[i] = id14[p] + 1;
        }
        boolean ret = i == b;
        for (int j : g.get(i)) {
            if (j != p) {
                if (init(g, j, i, par, b, id14, id11)) {
                    id11[i] = id11[j] + 1;
                    par[i] = -1;
                    ret = true;
                }
            }
        }
        return ret;
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
            g.c(rni() - 1, ni() - 1);
        }
        return g;
    }

    static Graph tree(int n) throws IOException {
        return graph(n, n - 1);
    }

    static class Graph extends ArrayList<List<Integer>> {
        void cto(int u, int v) {
            get(u).add(v);
        }

        void c(int u, int v) {
            cto(u, v);
            cto(v, u);
        }

        boolean is_leaf(int i) {
            return get(i).size() == 1;
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
    static int[] id16(int n) throws IOException {int[] a = new int[n]; r(); for (int i = 0; i < n; ++i) a[i] = ni() - 1; return a;}
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
    static boolean id15(boolean b) {prln(b ? "yes" : "no"); return b;};
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