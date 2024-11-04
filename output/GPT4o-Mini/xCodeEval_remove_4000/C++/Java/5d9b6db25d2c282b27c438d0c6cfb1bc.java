import java.util.*;
import java.util.function.Function;

class Disjunction {
    public static boolean id17(boolean... bools) {
        for (boolean b : bools) {
            if (b) return true;
        }
        return false;
    }

    public static boolean hasBegin(Object obj) {
        return obj instanceof Iterable;
    }

    public static <T> boolean isContainer(T obj) {
        return hasBegin(obj);
    }

    public static <T, U> boolean isOneOf(T t, U... types) {
        for (U type : types) {
            if (t.getClass() == type.getClass()) return true;
        }
        return false;
    }

    public static <T> boolean isSaneInteger(T t) {
        return t instanceof Integer && !isOneOf(t, (byte) 0, (short) 0, Boolean.class);
    }

    public static String toString(String s) {
        return "\"" + s + "\"";
    }

    public static String toString(char ch) {
        return "'" + ch + "'";
    }

    public static String toString(boolean b) {
        return b ? "true" : "false";
    }

    public static <T> String toString(T value) {
        if (value instanceof Number) {
            return value.toString();
        } else if (isContainer(value)) {
            StringBuilder res = new StringBuilder("{");
            boolean isFirst = true;
            for (Object x : (Iterable<?>) value) {
                if (!isFirst) res.append(", ");
                isFirst = false;
                res.append(toString(x));
            }
            res.append("}");
            return res.toString();
        }
        return value.toString();
    }

    public static List<String> id26(String s) {
        s += ',';
        List<String> res = new ArrayList<>();
        while (!s.isEmpty()) {
            int pos = s.indexOf(',');
            res.add(s.substring(0, pos));
            s = s.substring(pos + 1);
        }
        return res;
    }

    public static void debugOut(List<String> args, int idx, int lineNum) {
        System.err.println();
    }

    public static <Head, Tail> void debugOut(List<String> args, int idx, int lineNum, Head h, Tail... t) {
        String value = toString(h);
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
        debugOut(args, idx + 1, lineNum, t);
    }

    public static void main(String[] args) {
        // Example usage
        System.out.println(id17(true, false, false)); // true
        System.out.println(id17(false, false)); // false

        List<String> strings = Arrays.asList("Hello", "World");
        System.out.println(toString(strings)); // { "Hello", "World" }
    }
}

class IntegerIterator<T> implements Iterator<T> {
    private T value;

    public IntegerIterator(T value) {
        this.value = value;
    }

    @Override
    public boolean hasNext() {
        return true; // Simplified for demonstration
    }

    @Override
    public T next() {
        // Simplified for demonstration
        return value;
    }
}

class IntegerRange<T> implements Iterable<T> {
    private final T begin;
    private final T end;

    public IntegerRange(T begin, T end) {
        this.begin = begin;
        this.end = end;
    }

    @Override
    public Iterator<T> iterator() {
        return new IntegerIterator<>(begin); // Simplified for demonstration
    }
}

class Graph<T> {
    private List<List<Integer>> edges;
    private int verticesCount;

    public Graph(int verticesCount) {
        this.verticesCount = verticesCount;
        edges = new ArrayList<>(verticesCount);
        for (int i = 0; i < verticesCount; i++) {
            edges.add(new ArrayList<>());
        }
    }

    public void addEdge(int from, int to) {
        edges.get(from).add(to);
    }

    public List<Integer> getEdges(int vertex) {
        return edges.get(vertex);
    }

    public int getVerticesCount() {
        return verticesCount;
    }
}

class DirectedGraph<T> extends Graph<T> {
    public DirectedGraph(int verticesCount) {
        super(verticesCount);
    }

    public boolean isAcyclic() {
        // Implement topological sort or similar algorithm
        return true; // Simplified for demonstration
    }
}

class Permutation<T> extends ArrayList<T> {
    public Permutation(int size) {
        super(size);
        for (int i = 0; i < size; i++) {
            this.add((T) Integer.valueOf(i)); // Simplified for demonstration
        }
    }

    public Permutation multiply(Permutation<T> rhs) {
        Permutation<T> res = new Permutation<>(this.size());
        for (int i = 0; i < this.size(); i++) {
            res.set(i, this.get(rhs.get(i)));
        }
        return res;
    }
}

public class 5d9b6db25d2c282b27c438d0c6cfb1bcxcodeeval_processed_4000.json {
    public static void main(String[] args) {
        // Example usage
        DirectedGraph<Integer> graph = new DirectedGraph<>(5);
        graph.addEdge(0, 1);
        graph.addEdge(1, 2);
        System.out.println(graph.getVerticesCount()); // 5
    }
}
