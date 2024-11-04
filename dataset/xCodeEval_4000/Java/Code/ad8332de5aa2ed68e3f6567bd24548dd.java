import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class cf316g3_2 {

    public static void main(String[] args) throws IOException {
        char[] s_original = rcha(), s;
        int n = ri(), m = s_original.length, len = m;
        int suf_original[] = suffix(s_original), lcp_original[] = lcp(s_original, suf_original);
        char[][] rule = new char[n][];
        int rule_l[] = new int[n], rule_r[] = new int[n];
        for (int i = 0; i < n; ++i) {
            r();
            rule[i] = input.nextToken().toCharArray();
            rule_l[i] = ni();
            rule_r[i] = ni();
            len += rule[i].length + 1;
        }
        s = new char[len];
        int tag[] = new int[len];
        for (int i = 0; i < m; ++i) {
            s[i] = s_original[i];
        }
        for (int i = 0, ind = m; i < n; ++i) {
            s[ind++] = '#';
            for (int j = 0; j < rule[i].length; ++j) {
                tag[ind] = i + 1;
                s[ind++] = rule[i][j];
            }
        }
        int suf[] = suffix(s), invsuf[] = new int[m + 1], lcp[] = lcp(s, suf);
        for (int i = 1; i <= len; ++i) {
            if (suf[i] < m) {
                invsuf[suf[i]] = i;
            }
        }
        int cnt[][] = new int[len + 1][n];
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < n; ++j) {
                cnt[i + 1][j] = cnt[i][j] + (tag[suf[i + 1]] == j + 1 ? 1 : 0);
            }
        }
        SpTb rmq = new SpTb(lcp);
        long ans = 0;
        

        for (int i = 1; i <= m; ++i) {
            int lb = lcp_original[i - 1] + 1, ub = m - suf_original[i];
            if (lb <= ub) {
                for (int j = 0; j < n; ++j) {
                    int b = ub + 1;
                    for (int l = lb, r = m - suf_original[i]; l <= r; ) {
                        int mid = l + (r - l) / 2, llb = invsuf[suf_original[i]], uub = invsuf[suf_original[i]];
                        for (int ll = 1, rr = invsuf[suf_original[i]] - 1; ll <= rr; ) {
                            int mmid = ll + (rr - ll) / 2, cp = rmq.qry(invsuf[suf_original[i]], mmid);
                            if (cp >= mid) {
                                llb = mmid;
                                rr = mmid - 1;
                            } else {
                                ll = mmid + 1;
                            }
                        }
                        for (int ll = invsuf[suf_original[i]] + 1, rr = len; ll <= rr; ) {
                            int mmid = ll + (rr - ll) / 2, cp = rmq.qry(invsuf[suf_original[i]], mmid);
                            if (cp >= mid) {
                                uub = mmid;
                                ll = mmid + 1;
                            } else {
                                rr = mmid - 1;
                            }
                        }
                        

                        

                        

                        if (cnt[uub][j] - cnt[llb - 1][j] <= rule_r[j]) {
                            b = mid;
                            r = mid - 1;
                        } else {
                            l = mid + 1;
                        }
                    }
                    lb = max(lb, b);
                    b = lb - 1;
                    for (int l = 1, r = ub; l <= r; ) {
                        int mid = l + (r - l) / 2, llb = invsuf[suf_original[i]], uub = invsuf[suf_original[i]];
                        for (int ll = 1, rr = invsuf[suf_original[i]] - 1; ll <= rr; ) {
                            int mmid = ll + (rr - ll) / 2, cp = rmq.qry(invsuf[suf_original[i]], mmid);
                            if (cp >= mid) {
                                llb = mmid;
                                rr = mmid - 1;
                            } else {
                                ll = mmid + 1;
                            }
                        }
                        for (int ll = invsuf[suf_original[i]] + 1, rr = len; ll <= rr; ) {
                            int mmid = ll + (rr - ll) / 2, cp = rmq.qry(invsuf[suf_original[i]], mmid);
                            if (cp >= mid) {
                                uub = mmid;
                                ll = mmid + 1;
                            } else {
                                rr = mmid - 1;
                            }
                        }
                        if (cnt[uub][j] - cnt[llb - 1][j] >= rule_l[j]) {
                            b = mid;
                            l = mid + 1;
                        } else {
                            r = mid - 1;
                        }
                    }
                    ub = min(ub, b);
                    

                    if (lb > ub) {
                        break;
                    }
                }
                ans += max(0, ub - lb + 1);
                

            }
        }
        prln(ans);
        close();
    }

    

    

    static int[] lcp(char[] s) {
        return lcp(s, suffix(s));
    }

    static int[] lcp(char[] s, int[] suf) {
        int n = s.length, rank[] = new int[n + 1], ans[] = new int[n], k = 0;
        for (int i = 0; i <= n; ++i) rank[suf[i]] = i;
        for (int i = 0; i < n; ++i) {
            if (k > 0) --k;
            int p = suf[rank[i] - 1];
            while (i + k < n && p + k < n && s[i + k] == s[p + k]) ++k;
            ans[rank[i] - 1] = k;
        }
        return ans;
    }

    static int[] suffix(char[] s) {
        int n = s.length + 1, ans[] = new int[n], cls[] = new int[n], cnt[] = new int[128], ncls[] = new int[n];
        ans[0] = n - 1;
        for (char c : s) ++cnt[c];
        for (int i = 1; i < 128; ++i) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n - 1; ++i) ans[cnt[s[i]]--] = i;
        cls[ans[1]] = 1;
        for (int i = 2; i < n; ++i) cls[ans[i]] = cls[ans[i - 1]] + (s[ans[i]] > s[ans[i - 1]] ? 1 : 0);
        for (int offset = 1; offset <= n; offset <<= 1) {
            cntsort(ans, cls, n, offset);
            cntsort(ans, cls, n, 0);
            fill(ncls, 0);
            for (int i = 1; i < n; ++i)
                ncls[ans[i]] = ncls[ans[i - 1]] + (cls[ans[i]] > cls[ans[i - 1]] || cls[(ans[i] + offset) % n] > cls[(ans[i - 1] + offset) % n] ? 1 : 0);
            cls = copy(ncls);
        }
        return ans;
    }

    static void cntsort(int[] a, int[] by, int n, int offset) {
        int[] cnt = new int[n + 1], ans = new int[n];
        for (int b : by) ++cnt[b + 1];
        for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; ++i) ans[cnt[by[(a[i] + offset) % n]]++] = a[i];
        for (int i = 0; i < n; ++i) a[i] = ans[i];
    }

    

    static class SpTb {
        int n, lookup[][];
        static int lg[] = new int[500050], pow2[] = new int[20], ind = 1;
        static {
            for (int i = 0; i < 20; ++i) {
                pow2[i] = 1 << (i + 1);
            }
            for (int i = 2; i <= 500010; ++i) {
                if (pow2[ind] == i) {
                    ++ind;
                }
                lg[i] = ind;
            }
        }

        SpTb(int[] a) {
            n = a.length;
            lookup = new int[n][lg[n] + 1];
            for (int i = 0; i < n; ++i) {
                lookup[i][0] = a[i];
            }
            for (int j = 1; (1 << j) <= n; ++j) {
                for (int i = 0; (i + (1 << j)) <= n; ++i) {
                    lookup[i][j] = min(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
                }
            }
        }

        int qry(int l, int r) {
            if (r < l) {
                int __swap = l;
                l = r;
                r = __swap;
            }
            

            int j = lg[r - l];
            return min(lookup[l][j], lookup[r - (1 << j)][j]);
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
    static int lcm(int a, int b) {return a * b / gcf(a, b);}
    static long lcm(long a, long b) {return a * b / gcf(a, b);}
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
    

    static List<List<Integer>> g(int n) {List<List<Integer>> g = new ArrayList<>(); for(int i = 0; i < n; ++i) g.add(new ArrayList<>()); return g;}
    static List<Set<Integer>> sg(int n) {List<Set<Integer>> g = new ArrayList<>(); for(int i = 0; i < n; ++i) g.add(new HashSet<>()); return g;}
    static void c(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).add(v); g.get(v).add(u);}
    static void cto(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).add(v);}
    static void dc(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).remove(v); g.get(v).remove(u);}
    static void dcto(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).remove(v);}
    

    static void r() throws IOException {input = new StringTokenizer(__in.readLine());}
    static int ri() throws IOException {return Integer.parseInt(__in.readLine());}
    static long rl() throws IOException {return Long.parseLong(__in.readLine());}
    static int[] ria(int n) throws IOException {int[] a = new int[n]; input = new StringTokenizer(__in.readLine()); for(int i = 0; i < n; ++i) a[i] = Integer.parseInt(input.nextToken()); return a;}
    static int[] riam1(int n) throws IOException {int[] a = new int[n]; input = new StringTokenizer(__in.readLine()); for(int i = 0; i < n; ++i) a[i] = Integer.parseInt(input.nextToken()) - 1; return a;}
    static long[] rla(int n) throws IOException {long[] a = new long[n]; input = new StringTokenizer(__in.readLine()); for(int i = 0; i < n; ++i) a[i] = Long.parseLong(input.nextToken()); return a;}
    static char[] rcha() throws IOException {return __in.readLine().toCharArray();}
    static String rline() throws IOException {return __in.readLine();}
    static int rni() throws IOException {input = new StringTokenizer(__in.readLine()); return Integer.parseInt(input.nextToken());}
    static int ni() {return Integer.parseInt(input.nextToken());}
    static long rnl() throws IOException {input = new StringTokenizer(__in.readLine()); return Long.parseLong(input.nextToken());}
    static long nl() {return Long.parseLong(input.nextToken());}
    static List<List<Integer>> rg(int n, int m) throws IOException {List<List<Integer>> g = g(n); for(int i = 0; i < m; ++i) c(g, rni() - 1, ni() - 1); return g;}
    static void rg(List<List<Integer>> g, int m) throws IOException {for(int i = 0; i < m; ++i) c(g, rni() - 1, ni() - 1);}
    static List<List<Integer>> rdg(int n, int m) throws IOException {List<List<Integer>> g = g(n); for(int i = 0; i < m; ++i) cto(g, rni() - 1, ni() - 1); return g;}
    static void rdg(List<List<Integer>> g, int m) throws IOException {for(int i = 0; i < m; ++i) cto(g, rni() - 1, ni() - 1);}
    static List<Set<Integer>> rsg(int n, int m) throws IOException {List<Set<Integer>> g = sg(n); for(int i = 0; i < m; ++i) c(g, rni() - 1, ni() - 1); return g;}
    static void rsg(List<Set<Integer>> g, int m) throws IOException {for(int i = 0; i < m; ++i) c(g, rni() - 1, ni() - 1);}
    static List<Set<Integer>> rdsg(int n, int m) throws IOException {List<Set<Integer>> g = sg(n); for(int i = 0; i < m; ++i) cto(g, rni() - 1, ni() - 1); return g;}
    static void rdsg(List<Set<Integer>> g, int m) throws IOException {for(int i = 0; i < m; ++i) cto(g, rni() - 1, ni() - 1);}
    

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
    static void pryesno(boolean b) {__out.println(b ? "yes" : "no");};
    static void pryn(boolean b) {__out.println(b ? "Yes" : "No");}
    static void prYN(boolean b) {__out.println(b ? "YES" : "NO");}
    static void prln(int... a) {for(int i = 0, len = a.length - 1; i < len; __out.print(a[i]), __out.print(' '), ++i); __out.println(a[a.length - 1]);}
    static void prln(long... a) {for(int i = 0, len = a.length - 1; i < len; __out.print(a[i]), __out.print(' '), ++i); __out.println(a[a.length - 1]);}
    static <T> void prln(Collection<T> c) {int n = c.size() - 1; Iterator<T> iter = c.iterator(); for(int i = 0; i < n; __out.print(iter.next()), __out.print(' '), ++i); if(n >= 0) __out.println(iter.next()); else __out.println();}
    static void h() {__out.println("hlfd"); flush();}
    static void flush() {__out.flush();}
    static void close() {__out.close();}
}