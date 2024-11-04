
import java.util.*;

public class a08055377482990fdb900d1f46aa4fc8xcodeeval_processed_4000.json {
    static int t, la, ma, at;
    static int[] to = new int[1000005];
    static int[] p = new int[1000005];
    static Pair<List<Integer>, Integer>[] pp = new Pair[1000005];
    static Set<List<Integer>> s = new HashSet<>();
    static Map<Integer, Integer>[] m = new HashMap[300];
    static int[][] x = new int[289][289];
    static char[][] xx = {
        {},
        {'1'},
        {'2', '1'},
        {'3', '2', '1'},
        {'4', '3', '2', '1'},
        {'5', '4', '3', '2', '1'},
        {'6', '5', '4', '3', '2', '1'},
        {'7', '6', '5', '4', '3', '2', '1'},
        {'2', '1', '1', '2', '3', '4', '5', '6'},
        {'3', '2', '1', '1', '2', '3', '4', '5', '6'},
        {'4', '3', '2', '1', '1', '2', '3', '4', '5', '6'},
        {'5', '4', '3', '2', '1', '1', '2', '3', '4', '5', '6'},
        {'6', '5', '4', '3', '2', '1', '1', '2', '3', '4', '5', '6'},
        {'7', '6', '5', '4', '3', '2', '1', '1', '2', '3', '4', '5', '6'},
        ...
    };
    static List<List<Integer>> vv = new ArrayList<>();
    static Queue<Pair<List<Integer>, Pair<Integer, Integer>>> q = new LinkedList<>();
    static int ta, tb;

    static void go(List<Integer> aa, int bb, int cc) {
        q.add(new Pair<>(aa, new Pair<>(bb, cc)));
        s.add(aa);
        while (!q.isEmpty()) {
            List<Integer> a = q.peek().getKey();
            int b = q.peek().getValue().getKey();
            int c = q.peek().getValue().getValue();
            q.poll();
            Map<Integer, Integer> it = m[at];
            if (!it.containsKey(b)) {
                it.put(b, Integer.MAX_VALUE);
            }
            it.put(b, Math.min(it.get(b), c));
            if (c >= 10) {
                continue;
            }
            c++;
            for (int i = 0; i + 1 < a.size(); i++) {
                if (a.get(i) != a.get(i + 1)) {
                    a.set(i, a.get(i) - 1);
                    if (s.add(a)) {
                        q.add(new Pair<>(new ArrayList<>(a), new Pair<>(b / (a.get(i) + 1) * a.get(i), c)));
                    }
                    a.set(i, a.get(i) + 1);
                }
            }
            if (!a.isEmpty()) {
                if (a.get(a.size() - 1) == 2) {
                    a.remove(a.size() - 1);
                    if (s.add(a)) {
                        q.add(new Pair<>(new ArrayList<>(a), new Pair<>(b / 2, c)));
                    }
                    a.add(2);
                } else {
