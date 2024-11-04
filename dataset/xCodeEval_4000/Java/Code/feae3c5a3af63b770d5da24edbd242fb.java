import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class cf1374e2_3 {

    public static void main(String[] args) throws IOException {
        int n = rni(), m = ni(), k = ni(), t[] = new int[n + 1];
        List<int[]> a11 = new ArrayList<>(), a01 = new ArrayList<>(), a10 = new ArrayList<>(), a00 = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            int ti = rni(), ai = ni(), bi = ni(), entry[] = {ti, i + 1};
            t[i + 1] = ti;
            if(ai == 1 && bi == 1) {
                a11.add(entry);
            } else if(ai == 1) {
                a01.add(entry);
            } else if(bi == 1) {
                a10.add(entry);
            } else {
                a00.add(entry);
            }
        }
        int n11 = a11.size(), n01 = a01.size(), n10 = a10.size(), n00 = a00.size(), c = maxof(0, 2 * k - m, k - min(n01, n10), m - n01 - n10 - n00);
        if(n11 < c) {
            prln(-1);
        } else {
            int p11 = 0, p01 = 0, p10 = 0, p00 = 0;
            a11.sort((a, b) -> a[0] - b[0]);
            a01.sort((a, b) -> a[0] - b[0]);
            a10.sort((a, b) -> a[0] - b[0]);
            a00.sort((a, b) -> a[0] - b[0]);
            long cur = 0;
            Set<Integer> ans = new HashSet<>();
            PriorityQueue<Integer> free = new PriorityQueue<>((a, b) -> t[b] - t[a]), hadToUse01 = new PriorityQueue<>((a, b) -> t[b] - t[a]), hadToUse10 = new PriorityQueue<>((a, b) -> t[b] - t[a]);
            while(p11 < c) {
                cur += a11.get(p11)[0];
                ans.add(a11.get(p11++)[1]);
            }
            for(int i = c; i < k; ++i) {
                cur += a01.get(p01)[0];
                cur += a10.get(p10)[0];
                ans.add(a01.get(p01)[1]);
                ans.add(a10.get(p10)[1]);
                hadToUse01.offer(a01.get(p01++)[1]);
                hadToUse10.offer(a10.get(p10++)[1]);
            }
            
            while(ans.size() < m) {
                int min = IMAX, curmin = -1;
                if(p00 < n00) {
                    min = a00.get(p00)[0];
                    curmin = 0;
                }
                if(p01 < n01 && a01.get(p01)[0] < min) {
                    min = a01.get(p01)[0];
                    curmin = 1;
                }
                if(p10 < n10 && a10.get(p10)[0] < min) {
                    min = a10.get(p10)[0];
                    curmin = 2;
                }
                assert curmin >= 0;
                cur += min;
                if(curmin == 0) {
                    ans.add(a00.get(p00)[1]);
                    free.offer(a00.get(p00++)[1]);
                } else if(curmin == 1) {
                    ans.add(a01.get(p01)[1]);
                    free.offer(a01.get(p01++)[1]);
                } else {
                    ans.add(a10.get(p10)[1]);
                    free.offer(a10.get(p10++)[1]);
                }
            }
            long anss = cur;
            int ansp11 = c;
            while(p11 < n11 && (!free.isEmpty() || !hadToUse01.isEmpty() || !hadToUse10.isEmpty())) {
                int max = IMIN, curmax = -1;
                if(!free.isEmpty()) {
                    max = t[free.peek()];
                    curmax = 0;
                }
                if(!hadToUse01.isEmpty() && t[hadToUse01.peek()] > max) {
                    max = t[hadToUse01.peek()];
                    curmax = 1;
                }
                if(!hadToUse10.isEmpty() && t[hadToUse10.peek()] > max) {
                    max = t[hadToUse10.peek()];
                    curmax = 2;
                }
                assert curmax >= 0;
                cur += a11.get(p11)[0] - max;
                if(curmax == 0) {
                    ans.remove(free.poll());
                    if(!hadToUse01.isEmpty() && p00 < n00 && a00.get(p00)[0] < t[hadToUse01.peek()]) {
                        cur += a00.get(p00)[0] - t[hadToUse01.peek()];
                        ans.remove(hadToUse01.poll());
                        ans.add(a00.get(p00++)[1]);
                    }
                    if(!hadToUse10.isEmpty() && p00 < n00 && a00.get(p00)[0] < t[hadToUse10.peek()]) {
                        cur += a00.get(p00)[0] - t[hadToUse10.peek()];
                        ans.remove(hadToUse10.poll());
                        ans.add(a00.get(p00++)[1]);
                    }
                } else if(curmax == 1) {
                    ans.remove(hadToUse01.poll());
                    if(!hadToUse10.isEmpty() && p00 < n00 && a00.get(p00)[0] < t[hadToUse10.peek()]) {
                        cur += a00.get(p00)[0] - t[hadToUse10.peek()];
                        ans.remove(hadToUse10.poll());
                        ans.add(a00.get(p00++)[1]);
                    }
                } else {
                    ans.remove(hadToUse10.poll());
                    if(!hadToUse01.isEmpty() && p00 < n00 && a00.get(p00)[0] < t[hadToUse01.peek()]) {
                        cur += a00.get(p00)[0] - t[hadToUse01.peek()];
                        ans.remove(hadToUse01.poll());
                        ans.add(a00.get(p00++)[1]);
                    }
                }
                ans.add(a11.get(p11++)[1]);
                if(cur < anss) {
                    anss = cur;
                    ansp11 = p11;
                }
            }
            prln(anss);
            ans.clear();
            p00 = p01 = p10 = p11 = 0;
            while(p11 < c) {
                cur += a11.get(p11)[0];
                ans.add(a11.get(p11++)[1]);
            }
            for(int i = c; i < k; ++i) {
                cur += a01.get(p01)[0];
                cur += a10.get(p10)[0];
                ans.add(a01.get(p01)[1]);
                ans.add(a10.get(p10)[1]);
                hadToUse01.offer(a01.get(p01++)[1]);
                hadToUse10.offer(a10.get(p10++)[1]);
            }
            
            while(ans.size() < m) {
                int min = IMAX, curmin = -1;
                if(p00 < n00) {
                    min = a00.get(p00)[0];
                    curmin = 0;
                }
                if(p01 < n01 && a01.get(p01)[0] < min) {
                    min = a01.get(p01)[0];
                    curmin = 1;
                }
                if(p10 < n10 && a10.get(p10)[0] < min) {
                    min = a10.get(p10)[0];
                    curmin = 2;
                }
                assert curmin >= 0;
                cur += min;
                if(curmin == 0) {
                    ans.add(a00.get(p00)[1]);
                    free.offer(a00.get(p00++)[1]);
                } else if(curmin == 1) {
                    ans.add(a01.get(p01)[1]);
                    free.offer(a01.get(p01++)[1]);
                } else {
                    ans.add(a10.get(p10)[1]);
                    free.offer(a10.get(p10++)[1]);
                }
            }
            while(p11 < ansp11) {
                int max = IMIN, curmax = -1;
                if(!free.isEmpty()) {
                    max = t[free.peek()];
                    curmax = 0;
                }
                if(!hadToUse01.isEmpty() && t[hadToUse01.peek()] > max) {
                    max = t[hadToUse01.peek()];
                    curmax = 1;
                }
                if(!hadToUse10.isEmpty() && t[hadToUse10.peek()] > max) {
                    max = t[hadToUse10.peek()];
                    curmax = 2;
                }
                assert curmax >= 0;
                cur += a11.get(p11)[0] - max;
                if(curmax == 0) {
                    ans.remove(free.poll());
                    if(!hadToUse01.isEmpty() && p00 < n00 && a00.get(p00)[0] < t[hadToUse01.peek()]) {
                        cur += a00.get(p00)[0] - t[hadToUse01.peek()];
                        ans.remove(hadToUse01.poll());
                        ans.add(a00.get(p00++)[1]);
                    }
                    if(!hadToUse10.isEmpty() && p00 < n00 && a00.get(p00)[0] < t[hadToUse10.peek()]) {
                        cur += a00.get(p00)[0] - t[hadToUse10.peek()];
                        ans.remove(hadToUse10.poll());
                        ans.add(a00.get(p00++)[1]);
                    }
                } else if(curmax == 1) {
                    ans.remove(hadToUse01.poll());
                    if(!hadToUse10.isEmpty() && p00 < n00 && a00.get(p00)[0] < t[hadToUse10.peek()]) {
                        cur += a00.get(p00)[0] - t[hadToUse10.peek()];
                        ans.remove(hadToUse10.poll());
                        ans.add(a00.get(p00++)[1]);
                    }
                } else {
                    ans.remove(hadToUse10.poll());
                    if(!hadToUse01.isEmpty() && p00 < n00 && a00.get(p00)[0] < t[hadToUse01.peek()]) {
                        cur += a00.get(p00)[0] - t[hadToUse01.peek()];
                        ans.remove(hadToUse01.poll());
                        ans.add(a00.get(p00++)[1]);
                    }
                }
                ans.add(a11.get(p11++)[1]);
                if(cur < anss) {
                    anss = cur;
                    ansp11 = p11;
                }
            }
            prln(ans);
        }
        close();
    }

    static BufferedReader __in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter __out = new PrintWriter(new OutputStreamWriter(System.out));
    static StringTokenizer input;
    static Random rand = new Random();

    

    

    

    

    

    

    static final int IBIG = 1000000007;
    static final int IRAND = 327859546;
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
    static int floori(double d) {return (int)d;}
    static int ceili(double d) {return (int)ceil(d);}
    static long floorl(double d) {return (long)d;}
    static long ceill(double d) {return (long)ceil(d);}
    static void shuffle(int[] a) {int n = a.length - 1; for(int i = 0; i < n; ++i) {int ind = randInt(i, n); int swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(long[] a) {int n = a.length - 1; for(int i = 0; i < n; ++i) {int ind = randInt(i, n); long swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(double[] a) {int n = a.length - 1; for(int i = 0; i < n; ++i) {int ind = randInt(i, n); double swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static <T> void shuffle(T[] a) {int n = a.length - 1; for(int i = 0; i < n; ++i) {int ind = randInt(i, n); T swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void rsort(int[] a) {shuffle(a); sort(a);}
    static void rsort(long[] a) {shuffle(a); sort(a);}
    static void rsort(double[] a) {shuffle(a); sort(a);}
    static int randInt(int min, int max) {return rand.nextInt(max - min + 1) + min;}
    

    static void r() throws IOException {input = new StringTokenizer(__in.readLine());}
    static int ri() throws IOException {return Integer.parseInt(__in.readLine());}
    static long rl() throws IOException {return Long.parseLong(__in.readLine());}
    static int[] ria(int n) throws IOException {int[] a = new int[n]; input = new StringTokenizer(__in.readLine()); for(int i = 0; i < n; ++i) a[i] = Integer.parseInt(input.nextToken()); return a;}
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
    static void pryesno(boolean b) {__out.println(b ? "yes" : "no");};
    static void pryn(boolean b) {__out.println(b ? "Yes" : "No");}
    static void prYN(boolean b) {__out.println(b ? "YES" : "NO");}
    static void prln(int... a) {for(int i = 0, len = a.length - 1; i < len; __out.print(a[i]), __out.print(' '), ++i); __out.println(a[a.length - 1]);}
    static void prln(long... a) {for(int i = 0, len = a.length - 1; i < len; __out.print(a[i]), __out.print(' '), ++i); __out.println(a[a.length - 1]);}
    static <T> void prln(Collection<T> c) {int n = c.size() - 1; Iterator<T> iter = c.iterator(); for(int i = 0; i < n; __out.print(iter.next()), __out.print(' '), ++i); if(n >= 0) __out.println(iter.next());}
    static void h() {__out.println("hlfd");}
    static void flush() {__out.flush();}
    static void close() {__out.close();}
}