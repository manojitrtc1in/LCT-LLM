import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class cf1147b {

    public static void main(String[] args) throws IOException {
        int n = rni(), m = ni(), segs[][] = new int[m][2];
        Set<p> segset = new HashSet<>();
        for (int i = 0; i < m; ++i) {
            int u = rni() - 1, v = ni() - 1;
            segs[i][0] = u;
            segs[i][1] = v;
            segset.add(new p(u, v));
        }
        boolean ye = true;
        for (int i = 0; i < m; ++i) {
            int u = (segs[i][0] + 1) % n, v = (segs[i][1] + 1) % n;
            if (!segset.contains(new p(u, v))) {
                ye = false;
                break;
            }
        }
        if (ye) {
            

            pry();
            close();
            return;
        }
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                boolean yes = true;
                for (int j = 0; j < m; ++j) {
                    int u = (segs[j][0] + i) % n, v = (segs[j][1] + i) % n;
                    if (!segset.contains(new p(u, v))) {
                        yes = false;
                        break;
                    }
                }
                if (yes) {
                    

                    pry();
                    close();
                    return;
                }
                if (i * i < n) {
                    int j = n / i;
                    yes = true;
                    for (int k = 0; k < m; ++k) {
                        int u = (segs[k][0] + j) % n, v = (segs[k][1] + j) % n;
                        if (!segset.contains(new p(u, v))) {
                            yes = false;
                            break;
                        }
                    }
                    if (yes) {
                        

                        pry();
                        close();
                        return;
                    }
                }
            }
        }
        prn();
        close();
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

        public boolean equalsChecked(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            p p = (p) o;
            return a == p.a && b == p.b;
        }

        public boolean equalsUnchecked(Object o) {
            p p = (p) o;
            return a == p.a && b == p.b || a == p.b && b == p.a;
        }

        @Override
        public boolean equals(Object o) {
            return equalsUnchecked(o);
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b) + Objects.hash(b, a);
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
    static void close() {__out.close();}}