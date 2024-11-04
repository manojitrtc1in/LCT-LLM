import java.io.*;
import java.util.*;
import java.util.function.Function;

class E1SortirovkaSliyaniem {
    static final boolean kWriteCaseNumber = false;
    static final boolean kMultiTest = false;

    static final int kMinLen = 1;
    static final int kMaxLen = 1111;

    static String check(List<Integer> a) {
        int n = a.size();
        List<Integer> b = new ArrayList<>(Collections.nCopies(n, 0));
        StringBuilder log = new StringBuilder();

        merge(a, b, log, 0, n);
        return log.toString();
    }

    static void merge(List<Integer> a, List<Integer> b, StringBuilder log, int l, int r) {
        if (r - l <= 1) {
            return;
        }
        int m = (l + r) / 2;
        merge(a, b, log, l, m);
        merge(a, b, log, m, r);
        int i = l, j = m, k = l;
        while (i < m && j < r) {
            if (a.get(i) < a.get(j)) {
                log.append('0');
                b.set(k++, a.get(i++));
            } else {
                log.append('1');
                b.set(k++, a.get(j++));
            }
        }
        while (i < m) {
            b.set(k++, a.get(i++));
        }
        while (j < r) {
            b.set(k++, a.get(j++));
        }
        for (int p = l; p < r; p++) {
            a.set(p, b.get(p));
        }
    }

    static final int kMaxn = 100001;

    static boolean tryRecover(int l, int r, StringBuilder s, List<Integer> p) {
        if (r - l <= 1) {
            return true;
        }
        int mid = (l + r) / 2;
        if (!tryRecover(l, mid, s, p) || !tryRecover(mid, r, s, p)) {
            return false;
        }
        List<Integer> left = new ArrayList<>();
        for (int i = mid - 1; i >= l; i--) {
            left.add(p.get(i));
        }
        List<Integer> right = new ArrayList<>();
        for (int i = r - 1; i >= mid; i--) {
            right.add(p.get(i));
        }
        int pos = l;
        while (!left.isEmpty() && !right.isEmpty()) {
            if (s.length() == 0) {
                return false;
            }
            char ch = s.charAt(s.length() - 1);
            s.setLength(s.length() - 1);

            if (ch == '1') {
                p.set(pos++, right.remove(right.size() - 1));
            } else {
                p.set(pos++, left.remove(left.size() - 1));
            }
        }
        while (!left.isEmpty()) {
            p.set(pos++, left.remove(left.size() - 1));
        }
        while (!right.isEmpty()) {
            p.set(pos++, right.remove(right.size() - 1));
        }
        return true;
    }

    void solve(InputStream in, PrintStream out) {
        Scanner scanner = new Scanner(in);
        StringBuilder s = new StringBuilder(scanner.next());
        s.reverse();

        int L = kMinLen;
        int R = kMaxLen;
        while (R - L > 1) {
            int len = (L + R) / 2;
            Permutation<Integer> p = new Permutation<>(len);
            StringBuilder tmp = new StringBuilder(s);
            boolean recovered = tryRecover(0, len, tmp, p);
            if (recovered) {
                if (tmp.length() == 0) {
                    List<Integer> ans = new ArrayList<>(Collections.nCopies(len, 0));
                    for (int i = 0; i < len; i++) {
                        ans.set(p.get(i), i);
                    }
                    out.println(len);
                    for (int x : ans) {
                        out.print((x + 1) + " ");
                    }
                    out.println();
                    return;
                }
                L = len;
            } else {
                R = len;
            }
        }
        throw new AssertionError();
    }

    public static void main(String[] args) {
        E1SortirovkaSliyaniem solver = new E1SortirovkaSliyaniem();
        InputStream in = System.in;
        PrintStream out = System.out;

        if (kMultiTest) {
            Scanner scanner = new Scanner(in);
            int testsCount = scanner.nextInt();
            for (int testId = 1; testId <= testsCount; testId++) {
                if (kWriteCaseNumber) {
                    out.print("Case #" + testId + ": ");
                }
                solver.solve(in, out);
            }
        } else {
            solver.solve(in, out);
        }
    }
}

class Permutation<T> extends ArrayList<T> {
    public Permutation(int size) {
        super(size);
        init();
    }

    public Permutation(Collection<? extends T> c) {
        super(c);
    }

    void init() {
        for (int i = 0; i < this.size(); i++) {
            this.set(i, (T) Integer.valueOf(i));
        }
    }

    public Permutation<T> multiply(Permutation<T> rhs) {
        Permutation<T> res = new Permutation<>(this.size());
        for (int i = 0; i < this.size(); i++) {
            res.set(i, this.get(rhs.get(i).intValue()));
        }
        return res;
    }

    public Permutation<T> pow(long deg) {
        Permutation<T> result = new Permutation<>(this.size());
        Permutation<T> a = new Permutation<>(this);
        while (deg > 0) {
            if ((deg & 1) > 0) {
                result = result.multiply(a);
            }
            a = a.multiply(a);
            deg >>= 1;
        }
        return result;
    }

    public boolean next() {
        return Collections.swap(this, 0, 1) != null; // Placeholder for next permutation logic
    }
}
