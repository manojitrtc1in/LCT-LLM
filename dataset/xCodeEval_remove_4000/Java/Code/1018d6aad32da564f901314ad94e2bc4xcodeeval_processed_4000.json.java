import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;






public class id1 {

    static int n, m, p, mx = 262144;
    static long sgt[], lazy[];

    static void build(long[] a, int node, int l, int r) {
        if(l == r) {
            sgt[node] = l < a.length ? a[l] : LMIN >> 1;
        } else if(l < r) {
            int m = l + (r - l) / 2;
            build(a, node << 1, l, m);
            build(a, node << 1 | 1, m + 1, r);
            pull(node);
        }
    }

    static void push(int node, int l, int r) {
        if(lazy[node] != 0) {
            sgt[node] += lazy[node];
            if(l < r) {
                lazy[node << 1] += lazy[node];
                lazy[node << 1 | 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    static void pull(int node) {
        sgt[node] = max(sgt[node << 1], sgt[node << 1 | 1]);
    }

    static void upd(int i, int j, long x, int node, int l, int r) {
        push(node, l, r);
        if(j < l || r < i) {
            return;
        }
        if(i <= l && r <= j) {
            lazy[node] = x;
            push(node, l, r);
        } else {
            int m = l + (r - l) / 2;
            upd(i, j, x, node << 1, l, m);
            upd(i, j, x, node << 1 | 1, m + 1, r);
            pull(node);
        }
    }

    static long qry(int i, int j, int node, int l, int r) {
        push(node, l, r);
        if(j < l || r < i) {
            return 0;
        }
        if(i <= l && r <= j) {
            return sgt[node];
        } else {
            int m = l + (r - l) / 2;
            return qry(i, j, node << 1, l, m) + qry(i, j, node << 1 | 1, m + 1, r);
        }
    }

    public static void main(String[] args) throws IOException {
        n = rni();
        m = ni();
        p = ni();
        int a[][] = new int[n][2], b[][] = new int[m][2], mon[][] = new int[p][3];
        sgt = new long[mx << 1];
        lazy = new long[mx << 1];
        for(int i = 0; i < n; ++i) {
            a[i][0] = rni();
            a[i][1] = ni();
        }
        for(int i = 0; i < m; ++i) {
            b[i][0] = rni();
            b[i][1] = ni();
        }
        for(int i = 0; i < p; ++i) {
            mon[i][0] = rni();
            mon[i][1] = ni();
            mon[i][2] = ni();
        }
        Comparator<int[]> cmp = (x, y) -> x[0] - y[0];
        sort(a, cmp);
        sort(b, cmp);
        sort(mon, cmp);
        long[] id0 = new long[m];
        TreeMap<Integer, Integer> find = new TreeMap<>();
        for(int i = 0; i < m; ++i) {
            id0[i] = -b[i][1];
            if(!find.containsKey(b[i][0])) {
                find.put(b[i][0], i);
            }
        }
        build(id0, 1, 0, mx - 1);
        int curmon = 0;
        long ans = LMIN;
        for(int i = 0; i < n; ++i) {
            while(curmon < p && mon[curmon][0] < a[i][0]) {
                Integer ind = find.higherKey(mon[curmon][1]);
                if(ind != null) {
                    

                    upd(find.get(ind), mx - 1, mon[curmon][2], 1, 0, mx - 1);
                }
                ++curmon;
            }
            

            ans = max(ans, -a[i][1] + qry(0, mx - 1, 1, 0, mx - 1));
        }
        prln(ans);
        close();
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
    static int minof(int... x) {if(x.length == 1) return x[0]; if(x.length == 2) return min(x[0], x[1]); if(x.length == 3) return min(x[0], min(x[1], x[2])); int min = x[0]; for(int i = 1; i < x.length; ++i) if(x[i] < min) min = x[i]; return min;}
    static long minof(long a, long b, long c) {return min(a, min(b, c));}
    static long minof(long... x) {if(x.length == 1) return x[0]; if(x.length == 2) return min(x[0], x[1]); if(x.length == 3) return min(x[0], min(x[1], x[2])); long min = x[0]; for(int i = 1; i < x.length; ++i) if(x[i] < min) min = x[i]; return min;}
    static int maxof(int a, int b, int c) {return max(a, max(b, c));}
    static int maxof(int... x) {if(x.length == 1) return x[0]; if(x.length == 2) return max(x[0], x[1]); if(x.length == 3) return max(x[0], max(x[1], x[2])); int max = x[0]; for(int i = 1; i < x.length; ++i) if(x[i] > max) max = x[i]; return max;}
    static long maxof(long a, long b, long c) {return max(a, max(b, c));}
    static long maxof(long... x) {if(x.length == 1) return x[0]; if(x.length == 2) return max(x[0], x[1]); if(x.length == 3) return max(x[0], max(x[1], x[2])); long max = x[0]; for(int i = 1; i < x.length; ++i) if(x[i] > max) max = x[i]; return max;}
    static int powi(int a, int b) {if(a == 0) return 0; int ans = 1; while(b > 0) {if((b & 1) > 0) ans *= a; a *= a; b >>= 1;} return ans;}
    static long powl(long a, int b) {if(a == 0) return 0; long ans = 1; while(b > 0) {if((b & 1) > 0) ans *= a; a *= a; b >>= 1;} return ans;}
    static int fli(double d) {return (int)d;}
    static int cei(double d) {return (int)ceil(d);}
    static long fll(double d) {return (long)d;}
    static long cel(double d) {return (long)ceil(d);}
    static int gcf(int a, int b) {return b == 0 ? a : gcf(b, a % b);}
    static long gcf(long a, long b) {return b == 0 ? a : gcf(b, a % b);}
    static int randInt(int min, int max) {return __rand.nextInt(max - min + 1) + min;}
    static long hash(long x) {x += 0x9e3779b97f4a7c15L; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9L; x = (x ^ (x >> 27)) * 0x94d049bb133111ebL; return x ^ (x >> 31);}
    

    static void reverse(int[] a) {for(int i = 0, n = a.length, half = n / 2; i < half; ++i) {int swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(long[] a) {for(int i = 0, n = a.length, half = n / 2; i < half; ++i) {long swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(char[] a) {for(int i = 0, n = a.length, half = n / 2; i < half; ++i) {char swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void shuffle(int[] a) {int n = a.length - 1; for(int i = 0; i < n; ++i) {int ind = randInt(i, n); int swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(long[] a) {int n = a.length - 1; for(int i = 0; i < n; ++i) {int ind = randInt(i, n); long swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void rsort(int[] a) {shuffle(a); sort(a);}
    static void rsort(long[] a) {shuffle(a); sort(a);}
    static int[] copy(int[] a) {int[] ans = new int[a.length]; for(int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static long[] copy(long[] a) {long[] ans = new long[a.length]; for(int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static char[] copy(char[] a) {char[] ans = new char[a.length]; for(int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static int[] sorted(int[] a) {int[] ans = copy(a); sort(ans); return ans;}
    static long[] sorted(long[] a) {long[] ans = copy(a); sort(ans); return ans;}
    static int[] rsorted(int[] a) {int[] ans = copy(a); rsort(ans); return ans;}
    static long[] rsorted(long[] a) {long[] ans = copy(a); rsort(ans); return ans;}
    

    static List<List<Integer>> graph(int n) {List<List<Integer>> g = new ArrayList<>(); for(int i = 0; i < n; ++i) g.add(new ArrayList<>()); return g;}
    static List<List<Integer>> graph(List<List<Integer>> g, int m) throws IOException {for(int i = 0; i < m; ++i) connect(g, rni() - 1, ni() - 1); return g;}
    static List<List<Integer>> graph(int n, int m) throws IOException {return graph(graph(n), m);}
    static List<List<Integer>> dgraph(List<List<Integer>> g, int m) throws IOException {for(int i = 0; i < m; ++i) connecto(g, rni() - 1, ni() - 1); return g;}
    static List<List<Integer>> dgraph(List<List<Integer>> g, int n, int m) throws IOException {return dgraph(graph(n), m);}
    static List<Set<Integer>> sgraph(int n) {List<Set<Integer>> g = new ArrayList<>(); for(int i = 0; i < n; ++i) g.add(new HashSet<>()); return g;}
    static List<Set<Integer>> sgraph(List<Set<Integer>> g, int m) throws IOException {for(int i = 0; i < m; ++i) connect(g, rni() - 1, ni() - 1); return g;}
    static List<Set<Integer>> sgraph(int n, int m) throws IOException {return sgraph(sgraph(n), m);}
    static List<Set<Integer>> dsgraph(List<Set<Integer>> g, int m) throws IOException {for(int i = 0; i < m; ++i) connecto(g, rni() - 1, ni() - 1); return g;}
    static List<Set<Integer>> dsgraph(List<Set<Integer>> g, int n, int m) throws IOException {return dsgraph(sgraph(n), m);}
    static void connect(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).add(v); g.get(v).add(u);}
    static void connecto(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).add(v);}
    static void dconnect(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).remove(v); g.get(v).remove(u);}
    static void id2(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).remove(v);}
    

    static void r() throws IOException {input = new StringTokenizer(__in.readLine());}
    static int ri() throws IOException {return Integer.parseInt(__in.readLine());}
    static long rl() throws IOException {return Long.parseLong(__in.readLine());}
    static int[] ria(int n) throws IOException {int[] a = new int[n]; input = new StringTokenizer(__in.readLine()); for(int i = 0; i < n; ++i) a[i] = Integer.parseInt(input.nextToken()); return a;}
    static int[] id4(int n) throws IOException {int[] a = new int[n]; input = new StringTokenizer(__in.readLine()); for(int i = 0; i < n; ++i) a[i] = Integer.parseInt(input.nextToken()) - 1; return a;}
    static long[] rla(int n) throws IOException {long[] a = new long[n]; input = new StringTokenizer(__in.readLine()); for(int i = 0; i < n; ++i) a[i] = Long.parseLong(input.nextToken()); return a;}
    static char[] rcha() throws IOException {return __in.readLine().toCharArray();}
    static String rline() throws IOException {return __in.readLine();}
    static int rni() throws IOException {input = new StringTokenizer(__in.readLine()); return Integer.parseInt(input.nextToken());}
    static int ni() {return Integer.parseInt(input.nextToken());}
    static long rnl() throws IOException {input = new StringTokenizer(__in.readLine()); return Long.parseLong(input.nextToken());}
    static long nl() {return Long.parseLong(input.nextToken());}
    

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
    static void pryes() {__out.println("yes");}
    static void pry() {__out.println("Yes");}
    static void prY() {__out.println("YES");}
    static void prno() {__out.println("no");}
    static void prn() {__out.println("No");}
    static void prN() {__out.println("NO");}
    static void id3(boolean b) {__out.println(b ? "yes" : "no");};
    static void pryn(boolean b) {__out.println(b ? "Yes" : "No");}
    static void prYN(boolean b) {__out.println(b ? "YES" : "NO");}
    static void prln(int... a) {for(int i = 0, len = a.length - 1; i < len; __out.print(a[i]), __out.print(' '), ++i); __out.println(a[a.length - 1]);}
    static void prln(long... a) {for(int i = 0, len = a.length - 1; i < len; __out.print(a[i]), __out.print(' '), ++i); __out.println(a[a.length - 1]);}
    static <T> void prln(Collection<T> c) {int n = c.size() - 1; Iterator<T> iter = c.iterator(); for(int i = 0; i < n; __out.print(iter.next()), __out.print(' '), ++i); if(n >= 0) __out.println(iter.next()); else __out.println();}
    static void h() {__out.println("hlfd");}
    static void flush() {__out.flush();}
    static void close() {__out.close();}
}