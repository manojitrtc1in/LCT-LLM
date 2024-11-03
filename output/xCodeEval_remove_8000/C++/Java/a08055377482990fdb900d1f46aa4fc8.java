
import java.util.*;

public class a08055377482990fdb900d1f46aa4fc8xcodeeval_processed_8000.json {
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
        {'8', '7', '6', '5', '4', '3', '2', '1'},
        {'9', '8', '7', '6', '5', '4', '3', '2', '1'},
        {'a', '9', '8', '7', '6', '5', '4', '3', '2', '1'},
        // ...
    };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        for (int i = 0; i < 300; i++) {
            m[i] = new HashMap<>();
        }
        // ...
        while (t--) {
            ta = sc.nextInt();
            tb = sc.nextInt();
            // ...
            System.out.println(x[to[ta]][to[tb]]);
        }
    }
}
