import java.util.*;
import java.io.*;

class E1SortirovkaSliyaniem {
    public static String check(ArrayList<Integer> a) {
        int n = a.size();
        ArrayList<Integer> b = new ArrayList<>(n);
        StringBuilder log = new StringBuilder();

        merge(a, b, log, 0, n);
        return log.toString();
    }

    public static void merge(ArrayList<Integer> a, ArrayList<Integer> b, StringBuilder log, int l, int r) {
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

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        s = sb.toString();

        for (int len = 2; len <= 1111; len++) {
            ArrayList<Integer> p = new ArrayList<>(len);
            for (int i = 0; i < len; i++) {
                p.add(i);
            }
            String tmp = s;
            if (tryRecover(tmp, p) && tmp.isEmpty()) {
                ArrayList<Integer> ans = new ArrayList<>(len);
                for (int i = 0; i < len; i++) {
                    ans.add(0);
                }
                for (int i = 0; i < len; i++) {
                    ans.set(p.get(i), i);
                }
                System.out.println(len);
                for (int x : ans) {
                    System.out.print((x + 1) + " ");
                }
                System.out.println();
                return;
            }
        }
    }

    public static boolean tryRecover(String s, ArrayList<Integer> p) {
        if (p.size() == 1) {
            return true;
        }
        int mid = p.size() / 2;
        ArrayList<Integer> left = new ArrayList<>();
        for (int i = mid - 1; i >= 0; i--) {
            left.add(p.get(i));
        }
        ArrayList<Integer> right = new ArrayList<>();
        for (int i = p.size() - 1; i >= mid; i--) {
            right.add(p.get(i));
        }
        int pos = 0;
        while (!left.isEmpty() && !right.isEmpty()) {
            if (s.isEmpty()) {
                return false;
            }
            char ch = s.charAt(s.length() - 1);
            s = s.substring(0, s.length() - 1);

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
        return tryRecover(s, p);
    }
}
