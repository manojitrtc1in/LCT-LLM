import java.util.*;
import java.io.*;

public class 6d42941032a084c3b28df326724fbec5_nc {
    static final int M = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] a = new int[n];
        int[] w = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(st.nextToken());
        }
        int W1 = 0, W2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                W1 += w[i];
            } else {
                W2 += w[i];
            }
        }
        int[] probs = new int[m + 1];
        probs[0] = 1;
        for (int i = 0; i < m; i++) {
            int[] newProbs = new int[m + 1];
            for (int d1 = 0; d1 <= i; d1++) {
                int d2 = d1 - i;
                int w1 = W1 + d1;
                int w2 = W2 + d2;
                int w0 = w1 + w2;
                if (probs[d1] != 0 && w2 >= 0) {
                    int inv_w0 = inverse(w0, M);
                    if (w2 > 0) {
                        newProbs[d1] = sum(newProbs[d1], prod(probs[d1], prod(w2, inv_w0, M), M), M);
                    }
                    newProbs[d1 + 1] = sum(newProbs[d1 + 1], prod(probs[d1], prod(w1, inv_w0, M), M), M);
                }
            }
            probs = newProbs;
        }
        int[] after_ops_1 = new int[m + 1];
        int[] after_ops_2 = new int[m + 1];
        after_ops_1[0] = 1;
        after_ops_2[0] = 1;
        for (int i = 1; i <= m; i++) {
            after_ops_1[i] = prod(after_ops_1[i - 1], sum(1, inverse(W1 + i - 1, M), M), M);
        }
        for (int i = 1; i <= m; i++) {
            after_ops_2[i] = prod(after_ops_2[i - 1], raz(1, inverse(W2 - i + 1, M), M), M);
        }
        int coef1 = 0, coef2 = 0;
        for (int i = 0; i <= m; i++) {
            coef1 = sum(coef1, prod(after_ops_1[i], probs[i], M), M);
        }
        for (int i = 0; i <= m; i++) {
            coef2 = sum(coef2, prod(after_ops_2[i], probs[m - i], M), M);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                sb.append(prod(w[i], coef1, M)).append("\n");
            } else {
                sb.append(prod(w[i], coef2, M)).append("\n");
            }
        }
        System.out.print(sb);
    }

    static int inverse(int a, int n) {
        int c = cool_gcd(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static int cool_gcd(int a, int b) {
        if (b == 0) {
            return a >= 0 ? 1 : -1;
        }
        int t = a / b;
        int ans1 = cool_gcd(b, a - b * t);
        return new Pair<>(ans1.Y, ans1.X - ans1.Y * t);
    }

    static int prod(int a, int b, int M) {
        return (int) ((long) a * b % M);
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static Pair<Integer, Integer> cool_gcd(int a, int b) {
        if (b == 0) {
            return new Pair<>(1, 0);
        }
        int t = a / b;
        Pair<Integer, Integer> ans1 = cool_gcd(b, a - b * t);
        return new Pair<>(ans1.Y, ans1.X - ans1.Y * t);
    }

    static Pair<Long, Long> cool_gcdll(long a, long b) {
        if (b == 0) {
            return new Pair<>(1L, 0L);
        }
        long t = a / b;
        Pair<Long, Long> ans1 = cool_gcdll(b, a - b * t);
        return new Pair<>(ans1.Y, ans1.X - ans1.Y * t);
    }

    static int pow_mod(int a, int b, int p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        int temp = pow_mod(a, b >> 1, p);
        temp = prod(temp, temp, p);
        if ((b & 1) == 1) {
            return prod(temp, a, p);
        } else {
            return temp;
        }
    }

    static int inverse(int a, int n) {
        int c = cool_gcd(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static long inversell(long a, long n) {
        long c = cool_gcdll(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            a %= b;
            int temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static long gcdll(long a, long b) {
        while (b != 0) {
            a %= b;
            long temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static int pr_p(int a, int b, int p) {
        if (b < 1000000) {
            return (int) ((long) a * b % p);
        }
        int temp = pr_p(a, b >> 1, p);
        temp = sum(temp, temp, p);
        if ((b & 1) == 1) {
            return sum(temp, a, p);
        } else {
            return temp;
        }
    }

    static int po_p(int a, int b, int p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        int temp = po_p(a, b >> 1, p);
        temp = pr_p(temp, temp, p);
        if ((b & 1) == 1) {
            return pr_p(temp, a, p);
        } else {
            return temp;
        }
    }

    static int pow_mod(int a, int b, int p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        int temp = pow_mod(a, b >> 1, p);
        temp = prod(temp, temp, p);
        if ((b & 1) == 1) {
            return prod(temp, a, p);
        } else {
            return temp;
        }
    }

    static long pow_modll(long a, long b, long p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        long temp = pow_modll(a, b >> 1, p);
        temp = prodll(temp, temp, p);
        if ((b & 1) == 1) {
            return prodll(temp, a, p);
        } else {
            return temp;
        }
    }

    static int inverse(int a, int n) {
        int c = cool_gcd(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static long inversell(long a, long n) {
        long c = cool_gcdll(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static Pair<Integer, Integer> equal_elements(List<Integer> u, List<Integer> v) {
        Pair<Integer, Integer> ans = new Pair<>(Integer.MAX_VALUE, Integer.MAX_VALUE);
        int m = u.size();
        int n = v.size();
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (u.get(i) < v.get(j)) {
                i++;
            } else if (u.get(i) > v.get(j)) {
                j++;
            } else {
                ans = new Pair<>(v.get(j), u.get(i));
                j++;
            }
        }
        if (ans.X == Integer.MAX_VALUE) {
            return new Pair<>(-1, -1);
        } else {
            return new Pair<>(ans.Y, ans.X);
        }
    }

    static List<Pair<Integer, Integer>> factorize(int n) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    cnt++;
                    n /= i;
                }
                ans.add(new Pair<>(i, cnt));
            }
        }
        if (n > 1) {
            ans.add(new Pair<>(n, 1));
        }
        return ans;
    }

    static List<Pair<Integer, Integer>> merge(List<Pair<Integer, Integer>> p1, List<Pair<Integer, Integer>> p2) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        int m = p1.size();
        int n = p2.size();
        int i = 0;
        int j = 0;
        while (i < m || j < n) {
            if (i < m) {
                if (j < n) {
                    if (p1.get(i).X < p2.get(j).X) {
                        ans.add(p1.get(i++));
                    } else if (p1.get(i).X > p2.get(j).X) {
                        ans.add(p2.get(j++));
                    } else {
                        ans.add(new Pair<>(p1.get(i).X, p1.get(i).Y + p2.get(j).Y));
                        i++;
                        j++;
                    }
                } else {
                    ans.add(p1.get(i++));
                }
            } else {
                ans.add(p2.get(j++));
            }
        }
        return ans;
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            a %= b;
            int temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static long gcdll(long a, long b) {
        while (b != 0) {
            a %= b;
            long temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static int pr_p(int a, int b, int p) {
        if (b < 1000000) {
            return (int) ((long) a * b % p);
        }
        int temp = pr_p(a, b >> 1, p);
        temp = sum(temp, temp, p);
        if ((b & 1) == 1) {
            return sum(temp, a, p);
        } else {
            return temp;
        }
    }

    static int po_p(int a, int b, int p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        int temp = po_p(a, b >> 1, p);
        temp = pr_p(temp, temp, p);
        if ((b & 1) == 1) {
            return pr_p(temp, a, p);
        } else {
            return temp;
        }
    }

    static int pow_mod(int a, int b, int p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        int temp = pow_mod(a, b >> 1, p);
        temp = prod(temp, temp, p);
        if ((b & 1) == 1) {
            return prod(temp, a, p);
        } else {
            return temp;
        }
    }

    static long pow_modll(long a, long b, long p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        long temp = pow_modll(a, b >> 1, p);
        temp = prodll(temp, temp, p);
        if ((b & 1) == 1) {
            return prodll(temp, a, p);
        } else {
            return temp;
        }
    }

    static int inverse(int a, int n) {
        int c = cool_gcd(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static long inversell(long a, long n) {
        long c = cool_gcdll(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static Pair<Integer, Integer> cool_gcd(int a, int b) {
        if (b == 0) {
            return new Pair<>(1, 0);
        }
        int t = a / b;
        Pair<Integer, Integer> ans1 = cool_gcd(b, a - b * t);
        return new Pair<>(ans1.Y, ans1.X - ans1.Y * t);
    }

    static Pair<Long, Long> cool_gcdll(long a, long b) {
        if (b == 0) {
            return new Pair<>(1L, 0L);
        }
        long t = a / b;
        Pair<Long, Long> ans1 = cool_gcdll(b, a - b * t);
        return new Pair<>(ans1.Y, ans1.X - ans1.Y * t);
    }

    static int prod(int a, int b, int M) {
        return (int) ((long) a * b % M);
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static long prodll(long a, long b, long M) {
        return a * b % M;
    }

    static long sumll(long a, long b, long M) {
        long c = a + b;
        return c >= M ? c - M : c;
    }

    static long razll(long a, long b, long M) {
        long c = a - b;
        return c < 0 ? c + M : c;
    }

    static Pair<Integer, Integer> equal_elements(List<Integer> u, List<Integer> v) {
        Pair<Integer, Integer> ans = new Pair<>(Integer.MAX_VALUE, Integer.MAX_VALUE);
        int m = u.size();
        int n = v.size();
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (u.get(i) < v.get(j)) {
                i++;
            } else if (u.get(i) > v.get(j)) {
                j++;
            } else {
                ans = new Pair<>(v.get(j), u.get(i));
                j++;
            }
        }
        if (ans.X == Integer.MAX_VALUE) {
            return new Pair<>(-1, -1);
        } else {
            return new Pair<>(ans.Y, ans.X);
        }
    }

    static List<Pair<Integer, Integer>> factorize(int n) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    cnt++;
                    n /= i;
                }
                ans.add(new Pair<>(i, cnt));
            }
        }
        if (n > 1) {
            ans.add(new Pair<>(n, 1));
        }
        return ans;
    }

    static List<Pair<Integer, Integer>> merge(List<Pair<Integer, Integer>> p1, List<Pair<Integer, Integer>> p2) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        int m = p1.size();
        int n = p2.size();
        int i = 0;
        int j = 0;
        while (i < m || j < n) {
            if (i < m) {
                if (j < n) {
                    if (p1.get(i).X < p2.get(j).X) {
                        ans.add(p1.get(i++));
                    } else if (p1.get(i).X > p2.get(j).X) {
                        ans.add(p2.get(j++));
                    } else {
                        ans.add(new Pair<>(p1.get(i).X, p1.get(i).Y + p2.get(j).Y));
                        i++;
                        j++;
                    }
                } else {
                    ans.add(p1.get(i++));
                }
            } else {
                ans.add(p2.get(j++));
            }
        }
        return ans;
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            a %= b;
            int temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static long gcdll(long a, long b) {
        while (b != 0) {
            a %= b;
            long temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static int pr_p(int a, int b, int p) {
        if (b < 1000000) {
            return (int) ((long) a * b % p);
        }
        int temp = pr_p(a, b >> 1, p);
        temp = sum(temp, temp, p);
        if ((b & 1) == 1) {
            return sum(temp, a, p);
        } else {
            return temp;
        }
    }

    static int po_p(int a, int b, int p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        int temp = po_p(a, b >> 1, p);
        temp = pr_p(temp, temp, p);
        if ((b & 1) == 1) {
            return pr_p(temp, a, p);
        } else {
            return temp;
        }
    }

    static int pow_mod(int a, int b, int p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        int temp = pow_mod(a, b >> 1, p);
        temp = prod(temp, temp, p);
        if ((b & 1) == 1) {
            return prod(temp, a, p);
        } else {
            return temp;
        }
    }

    static long pow_modll(long a, long b, long p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        long temp = pow_modll(a, b >> 1, p);
        temp = prodll(temp, temp, p);
        if ((b & 1) == 1) {
            return prodll(temp, a, p);
        } else {
            return temp;
        }
    }

    static int inverse(int a, int n) {
        int c = cool_gcd(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static long inversell(long a, long n) {
        long c = cool_gcdll(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static Pair<Integer, Integer> cool_gcd(int a, int b) {
        if (b == 0) {
            return new Pair<>(1, 0);
        }
        int t = a / b;
        Pair<Integer, Integer> ans1 = cool_gcd(b, a - b * t);
        return new Pair<>(ans1.Y, ans1.X - ans1.Y * t);
    }

    static Pair<Long, Long> cool_gcdll(long a, long b) {
        if (b == 0) {
            return new Pair<>(1L, 0L);
        }
        long t = a / b;
        Pair<Long, Long> ans1 = cool_gcdll(b, a - b * t);
        return new Pair<>(ans1.Y, ans1.X - ans1.Y * t);
    }

    static int prod(int a, int b, int M) {
        return (int) ((long) a * b % M);
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static long prodll(long a, long b, long M) {
        return a * b % M;
    }

    static long sumll(long a, long b, long M) {
        long c = a + b;
        return c >= M ? c - M : c;
    }

    static long razll(long a, long b, long M) {
        long c = a - b;
        return c < 0 ? c + M : c;
    }

    static Pair<Integer, Integer> equal_elements(List<Integer> u, List<Integer> v) {
        Pair<Integer, Integer> ans = new Pair<>(Integer.MAX_VALUE, Integer.MAX_VALUE);
        int m = u.size();
        int n = v.size();
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (u.get(i) < v.get(j)) {
                i++;
            } else if (u.get(i) > v.get(j)) {
                j++;
            } else {
                ans = new Pair<>(v.get(j), u.get(i));
                j++;
            }
        }
        if (ans.X == Integer.MAX_VALUE) {
            return new Pair<>(-1, -1);
        } else {
            return new Pair<>(ans.Y, ans.X);
        }
    }

    static List<Pair<Integer, Integer>> factorize(int n) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    cnt++;
                    n /= i;
                }
                ans.add(new Pair<>(i, cnt));
            }
        }
        if (n > 1) {
            ans.add(new Pair<>(n, 1));
        }
        return ans;
    }

    static List<Pair<Integer, Integer>> merge(List<Pair<Integer, Integer>> p1, List<Pair<Integer, Integer>> p2) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        int m = p1.size();
        int n = p2.size();
        int i = 0;
        int j = 0;
        while (i < m || j < n) {
            if (i < m) {
                if (j < n) {
                    if (p1.get(i).X < p2.get(j).X) {
                        ans.add(p1.get(i++));
                    } else if (p1.get(i).X > p2.get(j).X) {
                        ans.add(p2.get(j++));
                    } else {
                        ans.add(new Pair<>(p1.get(i).X, p1.get(i).Y + p2.get(j).Y));
                        i++;
                        j++;
                    }
                } else {
                    ans.add(p1.get(i++));
                }
            } else {
                ans.add(p2.get(j++));
            }
        }
        return ans;
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            a %= b;
            int temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static long gcdll(long a, long b) {
        while (b != 0) {
            a %= b;
            long temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static int pr_p(int a, int b, int p) {
        if (b < 1000000) {
            return (int) ((long) a * b % p);
        }
        int temp = pr_p(a, b >> 1, p);
        temp = sum(temp, temp, p);
        if ((b & 1) == 1) {
            return sum(temp, a, p);
        } else {
            return temp;
        }
    }

    static int po_p(int a, int b, int p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        int temp = po_p(a, b >> 1, p);
        temp = pr_p(temp, temp, p);
        if ((b & 1) == 1) {
            return pr_p(temp, a, p);
        } else {
            return temp;
        }
    }

    static int pow_mod(int a, int b, int p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        int temp = pow_mod(a, b >> 1, p);
        temp = prod(temp, temp, p);
        if ((b & 1) == 1) {
            return prod(temp, a, p);
        } else {
            return temp;
        }
    }

    static long pow_modll(long a, long b, long p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        long temp = pow_modll(a, b >> 1, p);
        temp = prodll(temp, temp, p);
        if ((b & 1) == 1) {
            return prodll(temp, a, p);
        } else {
            return temp;
        }
    }

    static int inverse(int a, int n) {
        int c = cool_gcd(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static long inversell(long a, long n) {
        long c = cool_gcdll(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static Pair<Integer, Integer> cool_gcd(int a, int b) {
        if (b == 0) {
            return new Pair<>(1, 0);
        }
        int t = a / b;
        Pair<Integer, Integer> ans1 = cool_gcd(b, a - b * t);
        return new Pair<>(ans1.Y, ans1.X - ans1.Y * t);
    }

    static Pair<Long, Long> cool_gcdll(long a, long b) {
        if (b == 0) {
            return new Pair<>(1L, 0L);
        }
        long t = a / b;
        Pair<Long, Long> ans1 = cool_gcdll(b, a - b * t);
        return new Pair<>(ans1.Y, ans1.X - ans1.Y * t);
    }

    static int prod(int a, int b, int M) {
        return (int) ((long) a * b % M);
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static long prodll(long a, long b, long M) {
        return a * b % M;
    }

    static long sumll(long a, long b, long M) {
        long c = a + b;
        return c >= M ? c - M : c;
    }

    static long razll(long a, long b, long M) {
        long c = a - b;
        return c < 0 ? c + M : c;
    }

    static Pair<Integer, Integer> equal_elements(List<Integer> u, List<Integer> v) {
        Pair<Integer, Integer> ans = new Pair<>(Integer.MAX_VALUE, Integer.MAX_VALUE);
        int m = u.size();
        int n = v.size();
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (u.get(i) < v.get(j)) {
                i++;
            } else if (u.get(i) > v.get(j)) {
                j++;
            } else {
                ans = new Pair<>(v.get(j), u.get(i));
                j++;
            }
        }
        if (ans.X == Integer.MAX_VALUE) {
            return new Pair<>(-1, -1);
        } else {
            return new Pair<>(ans.Y, ans.X);
        }
    }

    static List<Pair<Integer, Integer>> factorize(int n) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    cnt++;
                    n /= i;
                }
                ans.add(new Pair<>(i, cnt));
            }
        }
        if (n > 1) {
            ans.add(new Pair<>(n, 1));
        }
        return ans;
    }

    static List<Pair<Integer, Integer>> merge(List<Pair<Integer, Integer>> p1, List<Pair<Integer, Integer>> p2) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        int m = p1.size();
        int n = p2.size();
        int i = 0;
        int j = 0;
        while (i < m || j < n) {
            if (i < m) {
                if (j < n) {
                    if (p1.get(i).X < p2.get(j).X) {
                        ans.add(p1.get(i++));
                    } else if (p1.get(i).X > p2.get(j).X) {
                        ans.add(p2.get(j++));
                    } else {
                        ans.add(new Pair<>(p1.get(i).X, p1.get(i).Y + p2.get(j).Y));
                        i++;
                        j++;
                    }
                } else {
                    ans.add(p1.get(i++));
                }
            } else {
                ans.add(p2.get(j++));
            }
        }
        return ans;
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            a %= b;
            int temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static long gcdll(long a, long b) {
        while (b != 0) {
            a %= b;
            long temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static int pr_p(int a, int b, int p) {
        if (b < 1000000) {
            return (int) ((long) a * b % p);
        }
        int temp = pr_p(a, b >> 1, p);
        temp = sum(temp, temp, p);
        if ((b & 1) == 1) {
            return sum(temp, a, p);
        } else {
            return temp;
        }
    }

    static int po_p(int a, int b, int p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        int temp = po_p(a, b >> 1, p);
        temp = pr_p(temp, temp, p);
        if ((b & 1) == 1) {
            return pr_p(temp, a, p);
        } else {
            return temp;
        }
    }

    static int pow_mod(int a, int b, int p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        int temp = pow_mod(a, b >> 1, p);
        temp = prod(temp, temp, p);
        if ((b & 1) == 1) {
            return prod(temp, a, p);
        } else {
            return temp;
        }
    }

    static long pow_modll(long a, long b, long p) {
