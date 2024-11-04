import java.util.*;
import java.io.*;

class E1SortirovkaSliyaniem {
    static final boolean kWriteCaseNumber = false;
    static final boolean kMultiTest = false;

    static String check(ArrayList<Integer> a) {
        int n = a.size();
        ArrayList<Integer> b = new ArrayList<>(n);
        StringBuilder log = new StringBuilder();

        Comparator<Integer> comp = (x, y) -> Integer.compare(a.get(x), a.get(y));

        class Merge {
            void merge(int l, int r) {
                if (r - l <= 1) {
                    return;
                }
                int m = (l + r) / 2;
                merge(l, m);
                merge(m, r);
                int i = l;
                int j = m;
                int k = l;
                while (i < m && j < r) {
                    if (comp.compare(i, j) < 0) {
                        log.append('0');
                        b.set(k, a.get(i));
                        ++i;
                    } else {
                        log.append('1');
                        b.set(k, a.get(j));
                        ++j;
                    }
                    ++k;
                }
                while (i < m) {
                    b.set(k, a.get(i));
                    ++i;
                    ++k;
                }
                while (j < r) {
                    b.set(k, a.get(j));
                    ++j;
                    ++k;
                }
                for (int p = l; p < r; ++p) {
                    a.set(p, b.get(p));
                }
            }
        }

        Merge merge = new Merge();
        merge.merge(0, n);
        return log.toString();
    }

    static final int kMaxn = 100001;

    static boolean try_recover(int l, int r, StringBuilder s, ArrayList<Integer> p) {
        if (r - l <= 1) {
            return true;
        }
        int mid = (l + r) / 2;
        if (!try_recover(l, mid, s, p) || !try_recover(mid, r, s, p)) {
            return false;
        }
        ArrayList<Integer> left = new ArrayList<>();
        for (int i = mid - 1; i >= l; --i) {
            left.add(p.get(i));
        }
        ArrayList<Integer> right = new ArrayList<>();
        for (int i = r - 1; i >= mid; --i) {
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
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        s = sb.toString();

        int L = kMinLen;
        int R = kMaxLen;
        while (R - L > 1) {
            int len = (L + R) / 2;
            ArrayList<Integer> p = new ArrayList<>(len);
            for (int i = 0; i < len; ++i) {
                p.add(i);
            }
            StringBuilder tmp = new StringBuilder(s);
            boolean recovered = try_recover(0, len, tmp, p);
            if (recovered) {
                if (tmp.length() == 0) {
                    ArrayList<Integer> ans = new ArrayList<>(len);
                    for (int i = 0; i < len; ++i) {
                        ans.add(p.indexOf(i));
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
        assert false;
    }

    E1SortirovkaSliyaniem() {}

    static final boolean kUseCustomChecker = false;
    boolean check(Scanner in, Scanner jury, Scanner out) {
        return true;
    }

    static final int kGeneratedTestsCount = 0;
    static final boolean kStopAfterFirstFail = false;
    static void generate_test(PrintWriter test) {}

    public static void main(String[] args) throws IOException {
        E1SortirovkaSliyaniem solver = new E1SortirovkaSliyaniem();
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        if (E1SortirovkaSliyaniem.kMultiTest) {
            int tests_count = Integer.parseInt(in.readLine());
            for (int test_id = 1; test_id <= tests_count; ++test_id) {
                if (E1SortirovkaSliyaniem.kWriteCaseNumber) {
                    out.print("Case #" + test_id + ": ");
                }
                solver.solve(in, out);
            }
        } else {
            solver.solve(in, out);
        }
        out.flush();
    }
}
