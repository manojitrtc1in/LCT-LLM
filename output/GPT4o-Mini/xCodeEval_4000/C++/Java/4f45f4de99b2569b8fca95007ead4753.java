import java.util.*;

public class 4f45f4de99b2569b8fca95007ead4753_nc {
    static final int MOD = 1000000007;
    static final long MODL = 1000000000000000003L;
    static final double eps = 1e-8;

    static class Chest {
        Map<Integer, Integer> foo;

        Chest() {
            foo = new HashMap<>();
        }

        void clear() {
            foo.clear();
        }

        void put(int key, int val) {
            if (val == 0) return;
            foo.put(key, foo.getOrDefault(key, 0) + val);
        }

        int pop(int key, int val) {
            int res = 0;
            if (foo.containsKey(key)) {
                if (foo.get(key) > val) {
                    res = val;
                    foo.put(key, foo.get(key) - val);
                } else {
                    res = foo.get(key);
                    foo.remove(key);
                }
            }
            return res;
        }
    }

    static int n;
    static long[] a = new long[110000];
    static int[] _seq = new int[50], _sup = new int[50];
    static int[] seq = new int[50], sup = new int[50];
    static Chest open = new Chest(), close = new Chest();

    static int process(int from) {
        System.arraycopy(_seq, 0, seq, 0, 50);
        System.arraycopy(_sup, 0, sup, 0, 50);
        if (from + from < seq[0]) return 1;
        open.clear();
        close.clear();
        open.put(0, from - (seq[0] - from));
        close.put(0, seq[0] - from);
        for (int i = 1; i < 45; i++) {
            int ext = open.pop(i - 1, seq[i]);
            seq[i] -= ext;
            open.put(i, ext);
            ext = close.pop(i - 1, seq[i]);
            sup[i] += seq[i] - ext;
            close.put(i, ext);
            int cls = open.pop(i, sup[i]);
            sup[i + 1] += sup[i] - cls;
            close.put(i, cls);
        }
        return sup[45] != 0 ? 1 : 0;
    }

    static int find(int lef, int rig) {
        while (lef <= rig) {
            int mid = (lef + rig) >> 1;
            if (process(mid) == 0) {
                if (mid == lef || process(mid - 1) != 0) {
                    return mid;
                }
                rig = mid - 1;
            } else {
                lef = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextLong();
            }
            Arrays.fill(_seq, 0);
            Arrays.fill(_sup, 0);
            int cur = 0;
            for (int i = 0; i < n; i++) {
                while (a[i] >= (1L << (cur + 1))) cur++;
                if (a[i] == (1L << cur)) {
                    _seq[cur]++;
                } else {
                    _sup[cur]++;
                }
            }
            if (process(_seq[0]) != 0) {
                System.out.println("-1");
            } else {
                int hig = _seq[0];
                int low = find(1, hig);
                for (int i = low; i <= hig; i++) {
                    if (i != low) System.out.print(" ");
                    System.out.print(i);
                }
                System.out.println();
            }
        }
        scanner.close();
    }
}
