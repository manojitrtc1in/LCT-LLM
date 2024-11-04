import java.util.*;
import java.util.stream.Collectors;

class Disjunction {
    static boolean value(boolean... bools) {
        for (boolean b : bools) {
            if (b) return true;
        }
        return false;
    }
}

class ContainerUtils {
    static <T> boolean hasBegin(T container) {
        return container instanceof Iterable;
    }

    static <T> boolean isContainer(T container) {
        return hasBegin(container);
    }
}

class TypeUtils {
    static <T> boolean isOneOf(T value, T... types) {
        for (T type : types) {
            if (value.equals(type)) return true;
        }
        return false;
    }

    static <T> boolean isSaneInteger(T value) {
        return value instanceof Integer && !isOneOf(value, (Object) new Character[]{'a', 'b', 'c', true});
    }
}

class StringUtils {
    static String toString(String s) {
        return "\"" + s + "\"";
    }

    static String toString(char ch) {
        return "'" + ch + "'";
    }

    static String toString(boolean b) {
        return b ? "true" : "false";
    }

    static <T> String toString(T value) {
        return value.toString();
    }

    static <A, B> String toString(Pair<A, B> pair) {
        return "(" + toString(pair.first) + ", " + toString(pair.second) + ")";
    }

    static <T> String toString(Collection<T> container) {
        StringBuilder res = new StringBuilder("{");
        boolean isFirst = true;
        for (T x : container) {
            if (!isFirst) {
                res.append(", ");
            }
            isFirst = false;
            res.append(toString(x));
        }
        res.append("}");
        return res.toString();
    }
}

class Pair<A, B> {
    A first;
    B second;

    Pair(A first, B second) {
        this.first = first;
        this.second = second;
    }
}

class DebugUtils {
    static void debugOut(List<String> args, int idx, int lineNum, Object... values) {
        System.err.println();
    }

    static void debugOut(List<String> args, int idx, int lineNum, Object head, Object... tail) {
        String value = StringUtils.toString(head);
        if (idx > 0) {
            System.err.print(", ");
        } else {
            System.err.print("Line(" + lineNum + ") ");
        }
        String arg = args.get(idx);
        if (arg.equals(value)) {
            System.err.print(arg);
        } else {
            System.err.print(arg + " = " + value);
        }
        debugOut(args, idx + 1, lineNum, tail);
    }
}

class RandomUtils {
    static long currentTimestamp() {
        return System.currentTimeMillis();
    }

    static long id1() {
        return currentTimestamp();
    }

    static long id21() {
        return id1();
    }

    static Random randomEngine() {
        return new Random(id21());
    }

    static int get(int to) {
        return randomEngine().nextInt(to);
    }

    static int get(int from, int to) {
        return get(to - from) + from;
    }

    static int get() {
        return get(0, Integer.MAX_VALUE);
    }
}

class Graph<T> {
    private List<List<Integer>> edges;
    private List<Integer> from;
    private List<Integer> to;
    private List<T> weight;
    private int verticesCount;

    Graph(int verticesCount) {
        this.verticesCount = verticesCount;
        edges = new ArrayList<>(verticesCount);
        for (int i = 0; i < verticesCount; i++) {
            edges.add(new ArrayList<>());
        }
        from = new ArrayList<>();
        to = new ArrayList<>();
        weight = new ArrayList<>();
    }

    void pushEdge(int from, int to) {
        int edgeId = this.from.size();
        this.from.add(from);
        this.to.add(to);
        edges.get(from).add(edgeId);
    }

    void clear() {
        verticesCount = 0;
        edges.clear();
        from.clear();
        to.clear();
        weight.clear();
    }

    int verticesCount() {
        return verticesCount;
    }

    List<Integer> edges(int vertex) {
        return edges.get(vertex);
    }

    List<Integer> edges() {
        return IntStream.range(0, from.size()).boxed().collect(Collectors.toList());
    }
}

class DirectedGraph<T> extends Graph<T> {
    DirectedGraph(int verticesCount) {
        super(verticesCount);
    }

    boolean isAcyclic() {
        return topSortAcyclic() != null;
    }

    List<Integer> topSortAcyclic() {
        List<Integer> order = new ArrayList<>();
        int[] inDegree = new int[verticesCount()];
        for (int to : to) {
            inDegree[to]++;
        }
        for (int v = 0; v < verticesCount(); v++) {
            if (inDegree[v] == 0) {
                order.add(v);
            }
        }
        int head = 0;
        while (head < order.size()) {
            int curVertex = order.get(head++);
            for (int edge : edges(curVertex)) {
                int to = this.to.get(edge);
                inDegree[to]--;
                if (inDegree[to] == 0) {
                    order.add(to);
                }
            }
        }
        return order.size() == verticesCount() ? order : null;
    }
}

class Permutation<T> extends ArrayList<T> {
    Permutation(int size) {
        super(size);
        init();
    }

    void init() {
        for (int i = 0; i < size(); i++) {
            this.set(i, (T) Integer.valueOf(i));
        }
    }

    Permutation<T> multiply(Permutation<T> rhs) {
        Permutation<T> res = new Permutation<>(size());
        for (int i = 0; i < size(); i++) {
            res.set(i, this.get(rhs.get(i)));
        }
        return res;
    }

    Permutation<T> pow(long deg) {
        Permutation<T> result = new Permutation<>(size());
        Permutation<T> a = this;
        while (deg > 0) {
            if ((deg & 1) > 0) {
                result = result.multiply(a);
            }
            a = a.multiply(a);
            deg >>= 1;
        }
        return result;
    }
}

class Id16 {
    static final int id7 = 1;
    static final int id19 = 1111;

    static String check(List<Integer> a) {
        int n = a.size();
        List<Integer> b = new ArrayList<>(n);
        StringBuilder log = new StringBuilder();

        merge(a, b, log, 0, n);
        return log.toString();
    }

    static void merge(List<Integer> a, List<Integer> b, StringBuilder log, int l, int r) {
        if (r - l <= 1) return;
        int m = (l + r) / 2;
        merge(a, b, log, l, m);
        merge(a, b, log, m, r);
        int i = l, j = m, k = l;
        while (i < m && j < r) {
            if (a.get(i) < a.get(j)) {
                log.append('0');
                b.set(k++, a.get(i++));
            } else {
                log.append('1');
                b.set(k++, a.get(j++));
            }
        }
        while (i < m) {
            b.set(k++, a.get(i++));
        }
        while (j < r) {
            b.set(k++, a.get(j++));
        }
        for (int p = l; p < r; p++) {
            a.set(p, b.get(p));
        }
    }

    static boolean tryRecover(int l, int r, StringBuilder s, List<Integer> p) {
        if (r - l <= 1) return true;
        int mid = (l + r) / 2;
        if (!tryRecover(l, mid, s, p) || !tryRecover(mid, r, s, p)) return false;

        List<Integer> left = new ArrayList<>();
        for (int i = mid - 1; i >= l; i--) {
            left.add(p.get(i));
        }
        List<Integer> right = new ArrayList<>();
        for (int i = r - 1; i >= mid; i--) {
            right.add(p.get(i));
        }
        int pos = l;
        while (!left.isEmpty() && !right.isEmpty()) {
            if (s.length() == 0) return false;
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

    void solve(Scanner in, PrintWriter out) {
        String s = in.next();
        StringBuilder reversedS = new StringBuilder(s).reverse();

        int L = id7;
        int R = id19;
        while (R - L > 1) {
            int len = (L + R) / 2;
            Permutation<Integer> p = new Permutation<>(len);
            StringBuilder tmp = new StringBuilder(reversedS);
            boolean recovered = tryRecover(0, len, tmp, p);
            if (recovered) {
                if (tmp.length() == 0) {
                    List<Integer> ans = new ArrayList<>(len);
                    for (int i = 0; i < len; i++) {
                        ans.add(p.get(i));
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
        throw new AssertionError();
    }

    public static void main(String[] args) {
        Id16 solver = new Id16();
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        solver.solve(in, out);
        out.flush();
    }
}
