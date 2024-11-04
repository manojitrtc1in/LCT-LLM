import java.util.*;

class id13 {
    private HashMap<Integer, Integer> foo;

    public id13() {
        foo = new HashMap<>();
    }

    public void clear() {
        foo.clear();
    }

    public void put(int key, int val) {
        if (val == 0) return;
        if (foo.containsKey(key)) {
            foo.put(key, foo.get(key) + val);
        } else {
            foo.put(key, val);
        }
    }

    public int pop(int key, int val) {
        int res = 0;
        if (foo.containsKey(key)) {
            int count = foo.get(key);
            if (count > val) {
                res = val;
                foo.put(key, count - val);
            } else {
                res = count;
                foo.remove(key);
            }
        }
        return res;
    }
}

public class 4f45f4de99b2569b8fca95007ead4753xcodeeval_processed_4000.json {
    private static id13 open, close;
    private static int n;
    private static long[] a;
    private static int[] _seq, _sup, seq, sup;

    private static int process(int from) {
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
        if (sup[45] != 0) return 1;
        return 0;
    }

    private static int find(int lef, int rig) {
        while (lef <= rig) {
            int mid = (lef + rig) >> 1;
            if (!process(mid)) {
                if (mid == lef || process(mid - 1)) {
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
            a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextLong();
            }
            _seq = new int[50];
            _sup = new int[50];
            for (int i = 0; i < 50; i++) {
                _seq[i] = 0;
                _sup[i] = 0;
            }
            int cur = 0;
            for (int i = 0; i < n; i++) {
                while (a[i] >= (1L << (cur + 1))) cur++;
                if (a[i] == (1L << cur)) {
                    _seq[cur]++;
                } else {
                    _sup[cur]++;
                }
            }
            if (process(_seq[0])) {
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
    }
}
