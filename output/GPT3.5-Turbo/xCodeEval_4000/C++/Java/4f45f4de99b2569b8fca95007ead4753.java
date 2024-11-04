import java.util.*;

class Chest {
    private Map<Integer, Integer> map;

    public Chest() {
        map = new HashMap<>();
    }

    public void put(int key, int val) {
        if (val == 0) return;
        if (map.containsKey(key)) {
            map.put(key, map.get(key) + val);
        } else {
            map.put(key, val);
        }
    }

    public int pop(int key, int val) {
        int res = 0;
        if (map.containsKey(key)) {
            int count = map.get(key);
            if (count > val) {
                res = val;
                map.put(key, count - val);
            } else {
                res = count;
                map.remove(key);
            }
        }
        return res;
    }

    public void clear() {
        map.clear();
    }
}

public class 4f45f4de99b2569b8fca95007ead4753_nc {
    private static Chest open;
    private static Chest close;
    private static long[] a;
    private static int[] seq;
    private static int[] sup;

    private static int process(int from) {
        for (int i = 0; i < 50; i++) {
            seq[i] = seq[i];
        }
        for (int i = 0; i < 50; i++) {
            sup[i] = sup[i];
        }
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
            if (process(mid) == 0) {
                if (mid == lef || process(mid - 1) == 1) {
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
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
            }
            seq = new int[50];
            sup = new int[50];
            for (int i = 0; i < 50; i++) {
                seq[i] = 0;
                sup[i] = 0;
            }
            int cur = 0;
            for (int i = 0; i < n; i++) {
                while (a[i] >= (1L << (cur + 1))) cur++;
                if (a[i] == (1L << cur)) {
                    seq[cur]++;
                } else {
                    sup[cur]++;
                }
            }
            open = new Chest();
            close = new Chest();
            if (process(seq[0]) == 1) {
                System.out.println("-1");
            } else {
                int hig = seq[0];
                int low = find(1, hig);
                for (int i = low; i <= hig; i++) {
                    if (i != low) System.out.print(" ");
                    System.out.print(i);
                }
                System.out.println();
            }
        }
        sc.close();
    }
}
