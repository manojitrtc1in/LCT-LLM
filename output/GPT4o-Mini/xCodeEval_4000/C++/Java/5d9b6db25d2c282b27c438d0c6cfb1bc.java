import java.io.*;
import java.util.*;
import java.util.function.Function;

class E1SortirovkaSliyaniem {
    static final boolean kWriteCaseNumber = false;
    static final boolean kMultiTest = false;

    final int kMinLen = 2;
    final int kMaxLen = 1111;

    static String check(List<Integer> a) {
        int n = a.size();
        List<Integer> b = new ArrayList<>(Collections.nCopies(n, 0));
        StringBuilder log = new StringBuilder();

        Function<Integer, Function<Integer, Void>> merge = l -> r -> {
            if (r - l <= 1) {
                return null;
            }
            int m = (l + r) / 2;
            merge.apply(l).apply(m);
            merge.apply(m).apply(r);
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
            for (int p : range(l, r)) {
                a.set(p, b.get(p));
            }
            return null;
        };

        merge.apply(0).apply(n);
        return log.toString();
    }

    static boolean tryRecover(int l, int r, StringBuilder s, List<Integer> p) {
        if (r - l <= 1) {
            return true;
        }
        int mid = (l + r) / 2;
        if (!tryRecover(l, mid, s, p) || !tryRecover(mid, r, s, p)) {
            return false;
        }
        List<Integer> left = new ArrayList<>();
        for (int i : downrange(mid, l)) {
            left.add(p.get(i));
        }
        List<Integer> right = new ArrayList<>();
        for (int i : downrange(r, mid)) {
            right.add(p.get(i));
        }
        int pos = l;
        while (!left.isEmpty() && !right.isEmpty()) {
            if (s.length() == 0) {
                return false;
            }
            char ch = s.charAt(s.length() - 1);
            s.deleteCharAt(s.length() - 1);

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

    void solve(BufferedReader in, PrintWriter out) throws IOException {
        String s = in.readLine();
        StringBuilder reversedS = new StringBuilder(s).reverse();

        for (int len = kMinLen; len <= kMaxLen; len++) {
            Permutation<Integer> p = new Permutation<>(len);
            StringBuilder tmp = new StringBuilder(reversedS);
            if (tryRecover(0, len, tmp, p) && tmp.length() == 0) {
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
        }
    }

    static List<Integer> range(int start, int end) {
        List<Integer> result = new ArrayList<>();
        for (int i = start; i < end; i++) {
            result.add(i);
        }
        return result;
    }

    static List<Integer> downrange(int start, int end) {
        List<Integer> result = new ArrayList<>();
        for (int i = start - 1; i >= end; i--) {
            result.add(i);
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        E1SortirovkaSliyaniem solver = new E1SortirovkaSliyaniem();
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        if (kMultiTest) {
            int testsCount = Integer.parseInt(in.readLine());
            for (int testId = 1; testId <= testsCount; testId++) {
                if (kWriteCaseNumber) {
                    out.printf("Case #%d: ", testId);
                }
                solver.solve(in, out);
            }
        } else {
            solver.solve(in, out);
        }
        out.flush();
    }
}

class Permutation<T> extends ArrayList<T> {
    Permutation(int size) {
        super(size);
        init();
    }

    void init() {
        for (int i = 0; i < this.size(); i++) {
            this.set(i, (T) Integer.valueOf(i));
        }
    }
}
