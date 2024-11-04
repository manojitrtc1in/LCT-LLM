import java.io.*;
import java.util.*;

public class 6d42941032a084c3b28df326724fbec5xcodeeval_processed_4000.json {
    static final int M = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] a = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int[] w = new int[n];
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
                    int id16 = inverse(w0, M);
                    if (w2 > 0) {
                        newProbs[d1] = sum(newProbs[d1], prod(probs[d1], prod(w2, id16, M), M), M);
                    }
                    newProbs[d1 + 1] = sum(newProbs[d1 + 1], prod(probs[d1], prod(w1, id16, M), M), M);
                }
            }
            probs = newProbs;
        }

        int[] id4 = new int[m + 1];
        int[] id29 = new int[m + 1];
        id4[0] = 1;
        id29[0] = 1;
        for (int i = 1; i <= m; i++) {
            id4[i] = prod(id4[i - 1], sum(1, inverse(W1 + i - 1, M), M), M);
        }
        for (int i = 1; i <= m; i++) {
            id29[i] = prod(id29[i - 1], raz(1, inverse(W2 - i + 1, M), M), M);
        }

        int coef1 = 0, coef2 = 0;
        for (int i = 0; i <= m; i++) {
            coef1 = sum(coef1, prod(id4[i], probs[i], M), M);
        }
        for (int i = 0; i <= m; i++) {
            coef2 = sum(coef2, prod(id29[i], probs[m - i], M), M);
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                pw.println(prod(w[i], coef1, M));
            } else {
                pw.println(prod(w[i], coef2, M));
            }
        }

        pw.close();
        br.close();
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

    static int inverse(int a, int n) {
        int c = id20(a, n).x;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static long id39(long a, long n) {
        long c = id11(a, n).x;
        if (c < 0) {
            c += n;
        }
        return c;
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

    static long id5(long a, long b, long p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        long temp = id5(a, b >> 1, p);
        temp = prodll(temp, temp, p);
        if ((b & 1) == 1) {
            return prodll(temp, a, p);
        } else {
            return temp;
        }
    }

    static int id20(int a, int b) {
        if (b == 0) {
            return a >= 0 ? 1 : -1;
        }
        int t = a / b;
        int ans1 = id20(b, a - b * t).x;
        return new Pair<>(ans1.y, ans1.x - ans1.y * t);
    }

    static Pair<Long, Long> id11(long a, long b) {
        if (b == 0) {
            return new Pair<>(1L, 0L);
        }
        long t = a / b;
        Pair<Long, Long> ans1 = id11(b, a - b * t);
        return new Pair<>(ans1.y, ans1.x - ans1.y * t);
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

    static long id32(long a, long b) {
        while (b != 0) {
            a %= b;
            long temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static int id35(int a, int p, int b, int q) {
        Pair<Integer, Integer> c = id20(p, q);
        int pr = p * q;
        int ans = ((a * c.y * q + b * c.x * p) % pr + pr) % pr;
        return ans;
    }

    static long id1(long a, long p, long b, long q) {
        Pair<Long, Long> c = id11(p, q);
        long pr = p * q;
        long ans = ((a * c.y * q + b * c.x * p) % pr + pr) % pr;
        return ans;
    }

    static Pair<Integer, Integer> power_v(int n, int p) {
        int ans = 0;
        while (n % p == 0) {
            n /= p;
            ans++;
        }
        return new Pair<>(ans, n);
    }

    static int id13(int c, int n, int pr, int k) {
        c %= n;
        if (c != 0) {
            Pair<Integer, Integer> kek = power_v(c, pr);
            int l = kek.x;
            if ((l & 1) == 1) {
                return -1;
            }
            if (l > 0) {
                int pwl = 1;
                for (int i = 0; i < l; i++) {
                    pwl *= pr;
                }
                n /= pwl;
                c /= pwl;
                int ans1 = id13(c, n, pr, k - l);
                if (ans1 == -1) {
                    return -1;
                }
                for (int i = 0; i < (l >> 1); i++) {
                    ans1 *= pr;
                }
                return ans1;
            } else {
                int primitive;
                if ((n & 1) == 1) {
                    primitive = primitive_root(n);
                } else {
                    primitive = 5;
                }
                int u = ((int) id19(primitive, c, n));
                if (u == -1) {
                    return -1;
                }
                if ((u & 1) == 1) {
                    return -1;
                }
                return pow_mod(primitive, u >> 1, n);
            }
        } else {
            return 0;
        }
    }

    static int id9(int c, int n) {
        List<Pair<Integer, Integer>> f = factorize(n);
        int a = 0, p = 1;
        for (Pair<Integer, Integer> pair : f) {
            int q = 1;
            for (int j = 0; j < pair.y; j++) {
                q *= pair.x;
            }
            int b = id13(c, q, pair.x, pair.y);
            if (b == -1) {
                return -1;
            }
            a = id35(a, p, b, q);
            p *= q;
        }
        return a;
    }

    static List<Pair<Integer, Integer>> factorize(int n) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }
                ans.add(new Pair<>(i, cnt));
            }
        }
        if (n > 1) {
            ans.add(new Pair<>(n, 1));
        }
        return ans;
    }

    static int phi(List<Pair<Integer, Integer>> v) {
        int ans = 1;
        for (Pair<Integer, Integer> pair : v) {
            ans *= pair.x - 1;
            for (int j = 1; j < pair.y; j++) {
                ans *= pair.x;
            }
        }
        return ans;
    }

    static int phi(int n) {
        return phi(factorize(n));
    }

    static boolean id0(int ph, List<Integer> toCheck, int r, int n) {
        for (int i = 0; i < toCheck.size(); i++) {
            if (pow_mod(r, toCheck.get(i), n) == 1) {
                return false;
            }
        }
        return pow_mod(r, ph, n) == 1;
    }

    static int primitive_root(int n) {
        if (n < 3) {
            return n - 1;
        }
        int p = phi(n);
        List<Pair<Integer, Integer>> f = factorize(p);
        List<Integer> toCheck = new ArrayList<>();
        for (Pair<Integer, Integer> pair : f) {
            toCheck.add(p / pair.x);
        }
        for (int i = 2; i < n; i++) {
            if (id0(p, toCheck, i, n)) {
                return i;
            }
        }
        return -1;
    }

    static int inverse(int a, int n) {
        Pair<Integer, Integer> c = id20(a, n);
        if (c.x < 0) {
            c.x += n;
        }
        return c.x;
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

    static int inverse(int a, int n) {
        int c = id20(a, n).x;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static long id39(long a, long n) {
        long c = id11(a, n).x;
        if (c < 0) {
            c += n;
        }
        return c;
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

    static long id5(long a, long b, long p) {
        if (b < 2) {
            if (b == 0) {
                return 1;
            } else {
                return a;
            }
        }
        long temp = id5(a, b >> 1, p);
        temp = prodll(temp, temp, p);
        if ((b & 1) == 1) {
            return prodll(temp, a, p);
        } else {
            return temp;
        }
    }

    static Pair<Integer, Integer> id20(int a, int b) {
        if (b == 0) {
            return new Pair<>(a >= 0 ? 1 : -1, 0);
        }
        int t = a / b;
        Pair<Integer, Integer> ans1 = id20(b, a - b * t);
        return new Pair<>(ans1.y, ans1.x - ans1.y * t);
    }

    static Pair<Long, Long> id11(long a, long b) {
        if (b == 0) {
            return new Pair<>(1L, 0L);
        }
        long t = a / b;
        Pair<Long, Long> ans1 = id11(b, a - b * t);
        return new Pair<>(ans1.y, ans1.x - ans1.y * t);
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

    static long id32(long a, long b) {
        while (b != 0) {
            a %= b;
            long temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static int id35(int a, int p, int b, int q) {
        Pair<Integer, Integer> c = id20(p, q);
        int pr = p * q;
        int ans = ((a * c.y * q + b * c.x * p) % pr + pr) % pr;
        return ans;
    }

    static long id1(long a, long p, long b, long q) {
        Pair<Long, Long> c = id11(p, q);
        long pr = p * q;
        long ans = ((a * c.y * q + b * c.x * p) % pr + pr) % pr;
        return ans;
    }

    static Pair<Integer, Integer> power_v(int n, int p) {
        int ans = 0;
        while (n % p == 0) {
            n /= p;
            ans++;
        }
        return new Pair<>(ans, n);
    }

    static int id13(int c, int n, int pr, int k) {
        c %= n;
        if (c != 0) {
            Pair<Integer, Integer> kek = power_v(c, pr);
            int l = kek.x;
            if ((l & 1) == 1) {
                return -1;
            }
            if (l > 0) {
                int pwl = 1;
                for (int i = 0; i < l; i++) {
                    pwl *= pr;
                }
                n /= pwl;
                c /= pwl;
                int ans1 = id13(c, n, pr, k - l);
                if (ans1 == -1) {
                    return -1;
                }
                for (int i = 0; i < (l >> 1); i++) {
                    ans1 *= pr;
                }
                return ans1;
            } else {
                int primitive;
                if ((n & 1) == 1) {
                    primitive = primitive_root(n);
                } else {
                    primitive = 5;
                }
                int u = ((int) id19(primitive, c, n));
                if (u == -1) {
                    return -1;
                }
                if ((u & 1) == 1) {
                    return -1;
                }
                return pow_mod(primitive, u >> 1, n);
            }
        } else {
            return 0;
        }
    }

    static int id9(int c, int n) {
        List<Pair<Integer, Integer>> f = factorize(n);
        int a = 0, p = 1;
        for (Pair<Integer, Integer> pair : f) {
            int q = 1;
            for (int j = 0; j < pair.y; j++) {
                q *= pair.x;
            }
            int b = id13(c, q, pair.x, pair.y);
            if (b == -1) {
                return -1;
            }
            a = id35(a, p, b, q);
            p *= q;
        }
        return a;
    }

    static List<Pair<Integer, Integer>> factorize(int n) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }
                ans.add(new Pair<>(i, cnt));
            }
        }
        if (n > 1) {
            ans.add(new Pair<>(n, 1));
        }
        return ans;
    }

    static int phi(List<Pair<Integer, Integer>> v) {
        int ans = 1;
        for (Pair<Integer, Integer> pair : v) {
            ans *= pair.x - 1;
            for (int j = 1; j < pair.y; j++) {
                ans *= pair.x;
            }
        }
        return ans;
    }

    static int phi(int n) {
        return phi(factorize(n));
    }

    static boolean id0(int ph, List<Integer> toCheck, int r, int n) {
        for (int i = 0; i < toCheck.size(); i++) {
            if (pow_mod(r, toCheck.get(i), n) == 1) {
                return false;
            }
        }
        return pow_mod(r, ph, n) == 1;
    }

    static int primitive_root(int n) {
        if (n < 3) {
            return n - 1;
        }
        int p = phi(n);
        List<Pair<Integer, Integer>> f = factorize(p);
        List<Integer> toCheck = new ArrayList<>();
        for (Pair<Integer, Integer> pair : f) {
            toCheck.add(p / pair.x);
        }
        for (int i = 2; i < n; i++) {
            if (id0(p, toCheck, i, n)) {
                return i;
            }
        }
        return -1;
    }

    static int id35(int a, int p, int b, int q) {
        Pair<Integer, Integer> c = id20(p, q);
        int pr = p * q;
        int ans = ((a * c.y * q + b * c.x * p) % pr + pr) % pr;
        return ans;
    }

    static long id1(long a, long p, long b, long q) {
        Pair<Long, Long> c = id11(p, q);
        long pr = p * q;
        long ans = ((a * c.y * q + b * c.x * p) % pr + pr) % pr;
        return ans;
    }

    static Pair<Integer, Integer> power_v(int n, int p) {
        int ans = 0;
        while (n % p == 0) {
            n /= p;
            ans++;
        }
        return new Pair<>(ans, n);
    }

    static int id13(int c, int n, int pr, int k) {
        c %= n;
        if (c != 0) {
            Pair<Integer, Integer> kek = power_v(c, pr);
            int l = kek.x;
            if ((l & 1) == 1) {
                return -1;
            }
            if (l > 0) {
                int pwl = 1;
                for (int i = 0; i < l; i++) {
                    pwl *= pr;
                }
                n /= pwl;
                c /= pwl;
                int ans1 = id13(c, n, pr, k - l);
                if (ans1 == -1) {
                    return -1;
                }
                for (int i = 0; i < (l >> 1); i++) {
                    ans1 *= pr;
                }
                return ans1;
            } else {
                int primitive;
                if ((n & 1) == 1) {
                    primitive = primitive_root(n);
                } else {
                    primitive = 5;
                }
                int u = ((int) id19(primitive, c, n));
                if (u == -1) {
                    return -1;
                }
                if ((u & 1) == 1) {
                    return -1;
                }
                return pow_mod(primitive, u >> 1, n);
            }
        } else {
            return 0;
        }
    }

    static int id9(int c, int n) {
        List<Pair<Integer, Integer>> f = factorize(n);
        int a = 0, p = 1;
        for (Pair<Integer, Integer> pair : f) {
            int q = 1;
            for (int j = 0; j < pair.y; j++) {
                q *= pair.x;
            }
            int b = id13(c, q, pair.x, pair.y);
            if (b == -1) {
                return -1;
            }
            a = id35(a, p, b, q);
            p *= q;
        }
        return a;
    }

    static List<Pair<Integer, Integer>> factorize(int n) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }
                ans.add(new Pair<>(i, cnt));
            }
        }
        if (n > 1) {
            ans.add(new Pair<>(n, 1));
        }
        return ans;
    }

    static int phi(List<Pair<Integer, Integer>> v) {
        int ans = 1;
        for (Pair<Integer, Integer> pair : v) {
            ans *= pair.x - 1;
            for (int j = 1; j < pair.y; j++) {
                ans *= pair.x;
            }
        }
        return ans;
    }

    static int phi(int n) {
        return phi(factorize(n));
    }

    static boolean id0(int ph, List<Integer> toCheck, int r, int n) {
        for (int i = 0; i < toCheck.size(); i++) {
            if (pow_mod(r, toCheck.get(i), n) == 1) {
                return false;
            }
        }
        return pow_mod(r, ph, n) == 1;
    }

    static int primitive_root(int n) {
        if (n < 3) {
            return n - 1;
        }
        int p = phi(n);
        List<Pair<Integer, Integer>> f = factorize(p);
        List<Integer> toCheck = new ArrayList<>();
        for (Pair<Integer, Integer> pair : f) {
            toCheck.add(p / pair.x);
        }
        for (int i = 2; i < n; i++) {
            if (id0(p, toCheck, i, n)) {
                return i;
            }
        }
        return -1;
    }

    static int id35(int a, int p, int b, int q) {
        Pair<Integer, Integer> c = id20(p, q);
        int pr = p * q;
        int ans = ((a * c.y * q + b * c.x * p) % pr + pr) % pr;
        return ans;
    }

    static long id1(long a, long p, long b, long q) {
        Pair<Long, Long> c = id11(p, q);
        long pr = p * q;
        long ans = ((a * c.y * q + b * c.x * p) % pr + pr) % pr;
        return ans;
    }

    static Pair<Integer, Integer> power_v(int n, int p) {
        int ans = 0;
        while (n % p == 0) {
            n /= p;
            ans++;
        }
        return new Pair<>(ans, n);
    }

    static int id13(int c, int n, int pr, int k) {
        c %= n;
        if (c != 0) {
            Pair<Integer, Integer> kek = power_v(c, pr);
            int l = kek.x;
            if ((l & 1) == 1) {
                return -1;
            }
            if (l > 0) {
                int pwl = 1;
                for (int i = 0; i < l; i++) {
                    pwl *= pr;
                }
                n /= pwl;
                c /= pwl;
                int ans1 = id13(c, n, pr, k - l);
                if (ans1 == -1) {
                    return -1;
                }
                for (int i = 0; i < (l >> 1); i++) {
                    ans1 *= pr;
                }
                return ans1;
            } else {
                int primitive;
                if ((n & 1) == 1) {
                    primitive = primitive_root(n);
                } else {
                    primitive = 5;
                }
                int u = ((int) id19(primitive, c, n));
                if (u == -1) {
                    return -1;
                }
                if ((u & 1) == 1) {
                    return -1;
                }
                return pow_mod(primitive, u >> 1, n);
            }
        } else {
            return 0;
        }
    }

    static int id9(int c, int n) {
        List<Pair<Integer, Integer>> f = factorize(n);
        int a = 0, p = 1;
        for (Pair<Integer, Integer> pair : f) {
            int q = 1;
            for (int j = 0; j < pair.y; j++) {
                q *= pair.x;
            }
            int b = id13(c, q, pair.x, pair.y);
            if (b == -1) {
                return -1;
            }
            a = id35(a, p, b, q);
            p *= q;
        }
        return a;
    }

    static List<Pair<Integer, Integer>> factorize(int n) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }
                ans.add(new Pair<>(i, cnt));
            }
        }
        if (n > 1) {
            ans.add(new Pair<>(n, 1));
        }
        return ans;
    }

    static int phi(List<Pair<Integer, Integer>> v) {
        int ans = 1;
        for (Pair<Integer, Integer> pair : v) {
            ans *= pair.x - 1;
            for (int j = 1; j < pair.y; j++) {
                ans *= pair.x;
            }
        }
        return ans;
    }

    static int phi(int n) {
        return phi(factorize(n));
    }

    static boolean id0(int ph, List<Integer> toCheck, int r, int n) {
        for (int i = 0; i < toCheck.size(); i++) {
            if (pow_mod(r, toCheck.get(i), n) == 1) {
                return false;
            }
        }
        return pow_mod(r, ph, n) == 1;
    }

    static int primitive_root(int n) {
        if (n < 3) {
            return n - 1;
        }
        int p = phi(n);
        List<Pair<Integer, Integer>> f = factorize(p);
        List<Integer> toCheck = new ArrayList<>();
        for (Pair<Integer, Integer> pair : f) {
            toCheck.add(p / pair.x);
        }
        for (int i = 2; i < n; i++) {
            if (id0(p, toCheck, i, n)) {
                return i;
            }
        }
        return -1;
    }

    static int id35(int a, int p, int b, int q) {
        Pair<Integer, Integer> c = id20(p, q);
        int pr = p * q;
        int ans = ((a * c.y * q + b * c.x * p) % pr + pr) % pr;
        return ans;
    }

    static long id1(long a, long p, long b, long q) {
        Pair<Long, Long> c = id11(p, q);
        long pr = p * q;
        long ans = ((a * c.y * q + b * c.x * p) % pr + pr) % pr;
        return ans;
    }

    static Pair<Integer, Integer> power_v(int n, int p) {
        int ans = 0;
        while (n % p == 0) {
            n /= p;
            ans++;
        }
        return new Pair<>(ans, n);
    }

    static int id13(int c, int n, int pr, int k) {
        c %= n;
        if (c != 0) {
            Pair<Integer, Integer> kek = power_v(c, pr);
            int l = kek.x;
            if ((l & 1) == 1) {
                return -1;
            }
            if (l > 0) {
                int pwl = 1;
                for (int i = 0; i < l; i++) {
                    pwl *= pr;
                }
                n /= pwl;
                c /= pwl;
                int ans1 = id13(c, n, pr, k - l);
                if (ans1 == -1) {
                    return -1;
                }
                for (int i = 0; i < (l >> 1); i++) {
                    ans1 *= pr;
                }
                return ans1;
            } else {
                int primitive;
                if ((n & 1) == 1) {
                    primitive = primitive_root(n);
                } else {
                    primitive = 5;
                }
                int u = ((int) id19(primitive, c, n));
                if (u == -1) {
                    return -1;
                }
                if ((u & 1) == 1) {
                    return -1;
                }
                return pow_mod(primitive, u >> 1, n);
            }
        } else {
            return 0;
        }
    }

    static int id9(int c, int n) {
        List<Pair<Integer, Integer>> f = factorize(n);
        int a = 0, p = 1;
        for (Pair<Integer, Integer> pair : f) {
            int q = 1;
            for (int j = 0; j < pair.y; j++) {
                q *= pair.x;
            }
            int b = id13(c, q, pair.x, pair.y);
            if (b == -1) {
                return -1;
            }
            a = id35(a, p, b, q);
            p *= q;
        }
        return a;
    }

    static List<Pair<Integer, Integer>> factorize(int n) {
        List<Pair<Integer, Integer>> ans = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }
                ans.add(new Pair<>(i, cnt));
            }
        }
        if (n > 1) {
            ans.add(new Pair<>(n, 1));
        }
        return ans;
    }

    static int phi(List<Pair<Integer, Integer>> v) {
        int ans = 1;
        for (Pair<Integer, Integer> pair : v) {
            ans *= pair.x - 1;
            for (int j = 1; j < pair.y; j++) {
                ans *= pair.x;
            }
        }
        return ans;
    }

    static int phi(int n) {
        return phi(factorize(n));
    }

    static boolean id0(int ph, List<Integer> toCheck, int r, int n) {
        for (int i = 0; i < toCheck.size(); i++) {
            if (pow_mod(r, toCheck.get(i), n) == 1) {
                return false;
            }
        }
        return pow_mod(r, ph, n) == 1;
    }

    static int primitive_root(int n) {
        if (n < 3) {
            return n - 1;
        }
        int p = phi(n);
        List<Pair<Integer, Integer>> f = factorize(p);
        List<Integer> toCheck = new ArrayList<>();
        for (Pair<Integer, Integer> pair : f) {
            toCheck.add(p / pair.x);
        }
        for (int i = 2; i < n; i++) {
            if (id0(p, toCheck, i, n)) {
                return i;
            }
        }
        return -1;
    }

    static int id35(int a, int p, int b, int q) {
        Pair<Integer, Integer> c = id20(p, q);
        int pr = p * q;
        int ans = ((a * c.y * q + b * c.x * p) % pr + pr) % pr;
        return ans;
    }

    static long id1(long a, long p, long b, long q) {
        Pair<Long, Long> c = id11(p, q);
        long pr = p * q;
