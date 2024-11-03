import java.util.*;
import java.io.*;

class Main {
    static class Permutation<T> extends ArrayList<T> {
        public Permutation() {
            super();
        }

        public Permutation(int size) {
            super(size);
            init();
        }

        public Permutation(Collection<? extends T> c) {
            super(c);
        }

        public void init() {
            for (int i = 0; i < size(); i++) {
                set(i, (T) Integer.valueOf(i));
            }
        }

        public Permutation<T> multiply(Permutation<T> rhs) {
            Permutation<T> res = new Permutation<>(size());
            for (int i = 0; i < size(); i++) {
                res.set(i, get(rhs.get(i)));
            }
            return res;
        }

        public Permutation<T> pow(long deg) {
            Permutation<T> result = new Permutation<>(size());
            Permutation<T> a = this;
            long b = deg;
            while (b > 0) {
                if ((b & 1) > 0) {
                    result = result.multiply(a);
                }
                a = a.multiply(a);
                b >>= 1;
            }
            return result;
        }
    }

    static String check(ArrayList<Integer> a) {
        int n = a.size();
        ArrayList<Integer> b = new ArrayList<>(n);
        StringBuilder log = new StringBuilder();

        merge(a, b, log);

        return log.toString();
    }

    static void merge(ArrayList<Integer> a, ArrayList<Integer> b, StringBuilder log) {
        merge(a, b, log, 0, a.size());
    }

    static void merge(ArrayList<Integer> a, ArrayList<Integer> b, StringBuilder log, int l, int r) {
        if (r - l <= 1) {
            return;
        }
        int m = (l + r) / 2;
        merge(a, b, log, l, m);
        merge(a, b, log, m, r);
        int i = l;
        int j = m;
        int k = l;
        while (i < m && j < r) {
            if (a.get(i) < a.get(j)) {
                log.append('0');
                b.set(k, a.get(i));
                i++;
            } else {
                log.append('1');
                b.set(k, a.get(j));
                j++;
            }
            k++;
        }
        while (i < m) {
            b.set(k, a.get(i));
            i++;
            k++;
        }
        while (j < r) {
            b.set(k, a.get(j));
            j++;
            k++;
        }
        for (int p = l; p < r; p++) {
            a.set(p, b.get(p));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        String s = in.readLine();
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        s = sb.toString();

        for (int len = 2; len <= 1111; len++) {
            Permutation<Integer> p = new Permutation<>(len);
            String tmp = s;
            if (tryRecover(0, len, tmp, p) && tmp.isEmpty()) {
                ArrayList<Integer> ans = new ArrayList<>(len);
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

    static boolean tryRecover(int l, int r, StringBuilder s, ArrayList<Integer> p) {
        if (r - l <= 1) {
            return true;
        }
        int mid = (l + r) / 2;
        if (!tryRecover(l, mid, s, p) || !tryRecover(mid, r, s, p)) {
            return false;
        }
        ArrayList<Integer> left = new ArrayList<>();
        for (int i = mid - 1; i >= l; i--) {
            left.add(p.get(i));
        }
        ArrayList<Integer> right = new ArrayList<>();
        for (int i = r - 1; i >= mid; i--) {
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
}
