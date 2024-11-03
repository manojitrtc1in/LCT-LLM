import java.util.*;

public class a08055377482990fdb900d1f46aa4fc8_nc {
    static final int MAGIC = 20000000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int[] p = new int[1000005];
        int[] to = new int[1000005];
        Pair[] pp = new Pair[1000005];
        Set<List<Integer>> s = new HashSet<>();
        List<List<Integer>> vv = new ArrayList<>();
        Queue<Pair<List<Integer>, Pair<Integer, Integer>>> q = new LinkedList<>();

        for (int i = 2; i < 1000005; i++) {
            if (p[i] == 0) {
                p[i] = i;
                if (i <= 1000005 / i) {
                    for (int j = i * i; j < 1000005; j += i) {
                        if (p[j] == 0) {
                            p[j] = i;
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= 1000000; i++) {
            pp[i] = new Pair<>();
            pp[i].second = i;
            int la = -1;
            int ta = i;
            while (ta != 1) {
                if (p[ta] == la) {
                    pp[i].first.set(pp[i].first.size() - 1, pp[i].first.get(pp[i].first.size() - 1) + 1);
                } else {
                    pp[i].first.add(2);
                }
                la = p[ta];
                ta /= p[ta];
            }
            Collections.sort(pp[i].first, Collections.reverseOrder());
        }

        Arrays.sort(pp, 1, 1000001, new Comparator<Pair<List<Integer>, Integer>>() {
            @Override
            public int compare(Pair<List<Integer>, Integer> o1, Pair<List<Integer>, Integer> o2) {
                return o1.first.equals(o2.first) ? Integer.compare(o1.second, o2.second) : o1.first.compareTo(o2.first);
            }
        });

        for (int i = 1; i <= 1000000; i++) {
            if (i == 1 || !pp[i].first.equals(pp[i - 1].first)) {
                vv.add(pp[i].first);
            }
            to[pp[i].second] = vv.size() - 1;
        }

        for (int i = 0; i < vv.size(); i++) {
            for (int j = 0; j < i; j++) {
                x[i][j] = x[j][i] = xx[i][j] >= 'a' ? xx[i][j] - 'a' + 10 : xx[i][j] - '0';
            }
        }

        while (t-- > 0) {
            int ta = sc.nextInt();
            int tb = sc.nextInt();

            System.out.println(x[to[ta]][to[tb]]);
        }
    }
}

class Pair<T extends Comparable<T>, U extends Comparable<U>> implements Comparable<Pair<T, U>> {
    T first;
    U second;

    public Pair() {
    }

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(Pair<T, U> o) {
        return first.equals(o.first) ? second.compareTo(o.second) : first.compareTo(o.first);
    }
}
