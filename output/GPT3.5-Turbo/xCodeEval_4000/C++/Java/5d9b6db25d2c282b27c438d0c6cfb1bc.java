import java.util.*;
import java.io.*;

class E1SortirovkaSliyaniem {
    static final boolean kWriteCaseNumber = false;
    static final boolean kMultiTest = false;

    static final int kMinLen = 2;
    static final int kMaxLen = 1111;

    static String check(ArrayList<Integer> a) {
        int n = a.size();
        ArrayList<Integer> b = new ArrayList<>(n);
        StringBuilder log = new StringBuilder();

        Comparator<Integer> comparator = (x, y) -> {
            if (a.get(x) < a.get(y)) {
                log.append('0');
                return -1;
            } else {
                log.append('1');
                return 1;
            }
        };

        class MergeSort {
            void merge(int l, int m, int r) {
                int i, j, k;
                int n1 = m - l + 1;
                int n2 = r - m;

                ArrayList<Integer> L = new ArrayList<>(n1);
                ArrayList<Integer> R = new ArrayList<>(n2);

                for (i = 0; i < n1; ++i)
                    L.add(a.get(l + i));
                for (j = 0; j < n2; ++j)
                    R.add(a.get(m + 1 + j));

                i = 0;
                j = 0;
                k = l;
                while (i < n1 && j < n2) {
                    if (comparator.compare(L.get(i), R.get(j)) <= 0) {
                        a.set(k, L.get(i));
                        i++;
                    } else {
                        a.set(k, R.get(j));
                        j++;
                    }
                    k++;
                }

                while (i < n1) {
                    a.set(k, L.get(i));
                    i++;
                    k++;
                }

                while (j < n2) {
                    a.set(k, R.get(j));
                    j++;
                    k++;
                }
            }

            void sort(int l, int r) {
                if (l < r) {
                    int m = (l + r) / 2;
                    sort(l, m);
                    sort(m + 1, r);
                    merge(l, m, r);
                }
            }
        }

        MergeSort mergeSort = new MergeSort();
        mergeSort.sort(0, n - 1);

        return log.toString();
    }

    static final int kMaxn = 100001;

    static boolean tryRecover(int l, int r, StringBuilder s, ArrayList<Integer> p) {
        if (r - l <= 1) {
            return true;
        }
        int mid = (l + r) / 2;
        if (!tryRecover(l, mid, s, p) || !tryRecover(mid, r, s, p)) {
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
                p.set(pos, right.get(right.size() - 1));
                right.remove(right.size() - 1);
            } else {
                p.set(pos, left.get(left.size() - 1));
                left.remove(left.size() - 1);
            }
            pos++;
        }
        while (!left.isEmpty()) {
            p.set(pos, left.get(left.size() - 1));
            left.remove(left.size() - 1);
            pos++;
        }
        while (!right.isEmpty()) {
            p.set(pos, right.get(right.size() - 1));
            right.remove(right.size() - 1);
            pos++;
        }
        return true;
    }

    void solve(BufferedReader in, PrintWriter out) throws IOException {
        String s = in.readLine();
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        s = sb.toString();

        for (int len = kMinLen; len <= kMaxLen; len++) {
            ArrayList<Integer> p = new ArrayList<>(len);
            for (int i = 0; i < len; i++) {
                p.add(i);
            }
            StringBuilder tmp = new StringBuilder(s);
            if (tryRecover(0, len, tmp, p) && tmp.length() == 0) {
                ArrayList<Integer> ans = new ArrayList<>(len);
                for (int i = 0; i < len; i++) {
                    ans.add(p.indexOf(i));
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

    E1SortirovkaSliyaniem() {}

    static final boolean kUseCustomChecker = false;
    boolean check(Scanner in, Scanner jury, Scanner out) {
        return true;
    }

    static final int kGeneratedTestsCount = 0;
    static final boolean kStopAfterFirstFail = false;
    static void generateTest(PrintWriter test) {}

    public static void main(String[] args) throws IOException {
        E1SortirovkaSliyaniem solver = new E1SortirovkaSliyaniem();
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        if (E1SortirovkaSliyaniem.kMultiTest) {
            int testsCount = Integer.parseInt(in.readLine());
            for (int testId = 1; testId <= testsCount; testId++) {
                if (E1SortirovkaSliyaniem.kWriteCaseNumber) {
                    out.print("Case #" + testId + ": ");
                }
                solver.solve(in, out);
            }
        } else {
            solver.solve(in, out);
        }
        out.close();
    }
}
