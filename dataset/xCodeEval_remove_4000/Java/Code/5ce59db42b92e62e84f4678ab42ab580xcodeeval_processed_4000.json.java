import java.io.BufferedWriter;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class Fair {

    public static void main(String[] args) {
        new ProblemSolver().solve();
    }

    private static class ProblemSolver {

        public void solve() {
            String inputString = "";
            InputReader reader = new InputReader(
                    inputString.isEmpty() ? System.in : new ByteArrayInputStream(inputString.getBytes()));
            OutputWriter writer = new OutputWriter(System.out);

            solve(reader, writer);

            writer.flush();
            writer.close();
        }

        private int id45, id6, id37, id53;

        private int[][] id39; 

        private int[] id17;
        private int[][] id36;
        private int[] id3; 


        private int[] id19;
        private int[] id15;

        private void solve(InputReader reader, OutputWriter writer) {
            

            id45 = reader.nextInt();
            id6 = reader.nextInt();
            id37 = reader.nextInt();
            id53 = reader.nextInt();

            id39 = new int[id45][];
            id36 = new int[id45][id37];
            id3 = new int[id45];

            for (int i = 0; i < id45; i++) {
                id3[i] = reader.nextInt() - 1;
                Arrays.fill(id36[i], -1);
            }

            id19 = new int[id6];
            id15 = new int[id6];
            for (int i = 0; i < id6; i++) {
                id19[i] = reader.nextInt() - 1;;
                id15[i] = reader.nextInt() - 1;
            }

            

            id58();

            for (int i = 0; i < id37; i++) {
                bfs(i);
            }

            for (int i = 0; i < id45; i++) {
                Arrays.sort(id36[i]);
                int sum = 0;
                for (int j = 0; j < id53; j++) {
                    sum += id36[i][j];
                }
                writer.print(sum);
                if (i != id45 - 1) {
                    writer.print(" ");
                }
            }
        }

        private void id58() {
            

            id17 = new int[id45];
            for (int i : id19) {
                id17[i]++;
            }
            for (int i : id15) {
                id17[i]++;
            }
            for (int i = 0; i < id45; i++) {
                id39[i] = new int[id17[i]];
            }
            for (int i = 0; i < id6; i++) {
                id39[id19[i]][--id17[id19[i]]] = id15[i];
                id39[id15[i]][--id17[id15[i]]] = id19[i];
            }
        }

        private void bfs(int goodType) { 

            int queueSize = 0;
            int[] nodes = new int[id45 + 1];
            for (int i = 0; i < id45; i++) {
                if (id3[i] == goodType) {
                    id36[i][goodType] = 0;
                    nodes[queueSize++] = i;
                }
            }
            for (int i = 0; i < queueSize; i++) {
                int current = nodes[i];
                for (int next : id39[current]) {
                    if (id36[next][goodType] == -1) {
                        id36[next][goodType] = id36[current][goodType] + 1;
                        nodes[queueSize++] = next;
                    }
                }
            }
        }

        private void id29(int goodType, List<Integer> id49,
                int[][] id36, id22 id39) {
            
            id23(goodType, id49, id39,
                    id36);
        }

        

        private void id23(int goodType, List<Integer> townIds,
                Graph id39, int[][] id36) {
            Map<Integer, Boolean> id27 = new HashMap<>();

            Queue<Integer> id34 = new LinkedList<>();
            for (int nodeId : townIds) {
                id27.put(nodeId, true);
                id34.add(nodeId);
            }

            while (!id34.isEmpty()) {
                int id57 = id34.poll();
                for (int id28 : ((id18) id39).id38()
                        .get(id57)) {
                    if (!id27.containsKey(id28)) {
                        id27.put(id28, true);
                        id36[id28][goodType] =
                                id36[id57][goodType] + 1;
                        id34.add(id28);
                    }
                }
            }
        }

        private void id55(id22 id39, Road[] roads) {
            for (Road road : roads) {
                id39.addEdge(road.id26(), road.id40());
            }
        }

        private static class Road {
            private int id59;
            private int id25;

            public Road(int id59, int id25) {
                this.id59 = id59;
                this.id25 = id25;
            }

            public int id26() {
                return id59;
            }

            public int id40() {
                return id25;
            }
        }

        private static class BFS {
            private Graph graph;

            private static final int id31 = -1;

            public BFS(Graph graph) {
                this.graph = graph;
            }

            public Traversal traverse(int id41) {
                List<Integer> id12 = new ArrayList<>();
                id12.add(id41);
                return traverse(id12);
            }

            public Traversal traverse(List<Integer> id12) {
                if (graph instanceof id18) {
                    Map<Integer, Boolean> id27 = new HashMap<>();
                    List<TraversalEdge> id50 = new ArrayList<>();
                    Queue<Integer> id34 = new LinkedList<>();
                    for (int nodeId : id12) {
                        id27.put(nodeId, true);
                        id50.add(id14(nodeId));
                        id34.add(nodeId);
                    }

                    while (!id34.isEmpty()) {
                        int id57 = id34.poll();
                        for (int id28 : ((id18) graph).id38()
                                .get(id57)) {
                            if (!id27.containsKey(id28)) {
                                id27.put(id28, true);
                                id50.add(new id0(id57, id28));
                                id34.add(id28);
                            }
                        }
                    }
                    return (new Traversal(id27, id50));
                } else {
                    throw new UnsupportedOperationException("BFS for weighted graph is un-implemented...");
                }
            }

            private TraversalEdge id14(int id41) {
                if (id43(graph)) {
                    return new id0(id31, id41);
                } else {
                    throw new UnsupportedOperationException("BFS for weighted graph is un-implemented...");
                }
            }

            public static boolean id24(int nodeId) {
                return (nodeId == id31);
            }

            private boolean id43(Graph graph) {
                return (graph instanceof id18);
            }

            public interface TraversalEdge {
            }

            public static class id0 implements TraversalEdge {
                private int id16;
                private int id35;

                public id0(int id16, int id35) {
                    this.id16 = id16;
                    this.id35 = id35;
                }

                public int id4() {
                    return id16;
                }

                public int id48() {
                    return id35;
                }
            }

            public static class Traversal {
                private Map<Integer, Boolean> id27;
                private List<TraversalEdge> id50;

                public Traversal(Map<Integer, Boolean> id27,
                        List<TraversalEdge> id50) {
                    this.id27 = id27;
                    this.id50 = id50;
                }

                public Map<Integer, Boolean> id7() {
                    return id27;
                }

                public List<TraversalEdge> id8() {
                    return id50;
                }
            }
        }

        private interface Graph {
            void addNode(int nodeId);

            Set<Integer> id54();

            Set<Edge> getEdges();

            interface Edge {
                int id30();

                int id44();
            }

            interface id33 extends Edge {

            }

            interface DirectedEdge extends Edge {
                int id46();

                int id20();
            }

            interface id1 extends Edge {
            }

            class id51 implements id33, id1 {
                private int firstNode;
                private int secondNode;

                public id51(int firstNode, int secondNode) {
                    if (firstNode > secondNode) {
                        int tmp = firstNode;
                        firstNode = secondNode;
                        secondNode = tmp;
                    }
                    this.firstNode = firstNode;
                    this.secondNode = secondNode;
                }

                @Override
                public int id30() {
                    return firstNode;
                }

                @Override
                public int id44() {
                    return secondNode;
                }

                @Override
                public boolean equals(Object o) {
                    if (this == o)
                        return true;
                    if (o == null || getClass() != o.getClass())
                        return false;

                    id51 that = (id51) o;

                    if (firstNode != that.firstNode)
                        return false;
                    return secondNode == that.secondNode;
                }

                @Override
                public int hashCode() {
                    int result = firstNode;
                    result = 31 * result + secondNode;
                    return result;
                }
            }

            class id32 implements DirectedEdge, id1 {
                private int firstNode;
                private int secondNode;

                public id32(int firstNode, int secondNode) {
                    this.firstNode = firstNode;
                    this.secondNode = secondNode;
                }

                @Override
                public int id30() {
                    return firstNode;
                }

                @Override
                public int id44() {
                    return secondNode;
                }

                @Override
                public int id46() {
                    return firstNode;
                }

                @Override
                public int id20() {
                    return secondNode;
                }

                @Override
                public boolean equals(Object o) {
                    if (this == o)
                        return true;
                    if (o == null || getClass() != o.getClass())
                        return false;

                    id32 that = (id32) o;

                    if (firstNode != that.firstNode)
                        return false;
                    return secondNode == that.secondNode;
                }

                @Override
                public int hashCode() {
                    int result = firstNode;
                    result = 31 * result + secondNode;
                    return result;
                }
            }
        }

        private interface id18 extends Graph {
            void addEdge(int id42, int id52);

            Map<Integer, List<Integer>> id38();
        }

        private static abstract class id5 implements id18 {
            private Set<Integer> nodeIds = new HashSet<>();
            private Set<Edge> edges = new HashSet<>();

            protected Map<Integer, List<Integer>> id21 = new HashMap<>();

            public id5() {
            }

            public id5(int size) {
                for (int i = 0; i < size; i++) {
                    addNode(i);
                }
            }

            @Override
            public void addNode(int nodeId) {
                nodeIds.add(nodeId);
                id21.put(nodeId, new ArrayList<>());
            }

            @Override
            public Map<Integer, List<Integer>> id38() {
                return id21;
            }

            @Override
            public Set<Integer> id54() {
                return nodeIds;
            }

            @Override
            public Set<Edge> getEdges() {
                return edges;
            }
        }

        private static class id22 extends id5 {
            public id22() {
                super();
            }

            public id22(int size) {
                super(size);
            }

            @Override
            public void addEdge(int id42, int id52) {
                id51 edge = new id51(id42, id52);
                if (!getEdges().contains(edge)) {
                    getEdges().add(edge);
                    id21.get(id42).add(id52);
                    id21.get(id52).add(id42);
                }
            }
        }

        private static class InputReader {

            private static final int id56 = 1024;

            private InputStream stream;
            private byte[] buffer = new byte[id56];
            private int id47;
            private int id11;

            public InputReader(InputStream stream) {
                this.stream = stream;
            }

            public int read() {
                if (id11 == -1) {
                    throw new InputMismatchException();
                }
                if (id47 >= id11) {
                    fillBuffer();
                    if (id11 <= 0) {
                        return -1;
                    }
                }
                return buffer[id47++];
            }

            public int peek() {
                if (id11 == -1) {
                    return -1;
                }
                if (id47 >= id11) {
                    try {
                        fillBuffer();
                    } catch (InputMismatchException e) {
                        return -1;
                    }
                    if (id11 <= 0) {
                        return -1;
                    }
                }
                return buffer[id47];
            }

            private int fillBuffer() {
                id47 = 0;
                try {
                    return (id11 = stream.read(buffer));
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }

            public char nextChar() {
                int c = read();
                while (id10(c)) {
                    c = read();
                }
                return (char) c;
            }

            public int nextInt() {
                int c = read();
                while (id10(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                int res = 0;
                do {
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    res *= 10;
                    res += c - '0';
                    c = read();
                } while (!id10(c));
                return res * sgn;
            }

            public long nextLong() {
                int c = read();
                while (id10(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                long res = 0;
                do {
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    res *= 10;
                    res += c - '0';
                    c = read();
                } while (!id10(c));
                return res * sgn;
            }

            public double nextDouble() {
                int c = read();
                while (id10(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                double res = 0;
                while (!id10(c) && c != '.') {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, nextInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    res *= 10;
                    res += c - '0';
                    c = read();
                }
                if (c == '.') {
                    c = read();
                    double m = 1;
                    while (!id10(c)) {
                        if (c == 'e' || c == 'E') {
                            return res * Math.pow(10, nextInt());
                        }
                        if (c < '0' || c > '9') {
                            throw new InputMismatchException();
                        }
                        m /= 10;
                        res += (c - '0') * m;
                        c = read();
                    }
                }
                return res * sgn;
            }

            public BigInteger id13() {
                try {
                    return new BigInteger(nextString());
                } catch (NumberFormatException e) {
                    throw new InputMismatchException();
                }
            }

            public String nextLine() {
                String s = id2();
                while (s.trim().length() == 0) {
                    s = id2();
                }
                return s;
            }

            private String id2() {
                StringBuilder buf = new StringBuilder();
                int c = read();
                while (c != '\n' && c != -1) {
                    if (c != '\r') {
                        buf.appendCodePoint(c);
                    }
                    c = read();
                }
                return buf.toString();
            }

            public String next() {
                return nextString();
            }

            private String nextString() {
                int c = read();
                while (id10(c)) {
                    c = read();
                }
                StringBuilder res = new StringBuilder();
                do {
                    if (Character.isValidCodePoint(c)) {
                        res.appendCodePoint(c);
                    }
                    c = read();
                } while (!id10(c));
                return res.toString();
            }

            public boolean id9() {
                int value;
                while (id10(value = peek()) && value != -1) {
                    read();
                }
                return value == -1;
            }

            private boolean id10(int c) {
                return isWhitespace(c);
            }

            private boolean isWhitespace(int c) {
                return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
            }

        }

        private static class OutputWriter {

            private final PrintWriter writer;

            public OutputWriter(OutputStream outputStream) {
                writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
            }

            public OutputWriter(Writer writer) {
                this.writer = new PrintWriter(writer);
            }

            public void print(char i) {
                writer.print(i);
            }

            public void println(char i) {
                writer.println(i);
            }

            public void print(int i) {
                writer.print(i);
            }

            public void println(int i) {
                writer.println(i);
            }

            public void print(long i) {
                writer.print(i);
            }

            public void println(long i) {
                writer.println(i);
            }

            public void print(char[] array) {
                writer.print(array);
            }

            public void print(int[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }

            public void print(long[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }

            public void print(double[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }

            public void println(char[] array) {
                writer.println(array);
            }

            public void println(int[] array) {
                print(array);
                writer.println();
            }

            public void println(long[] array) {
                print(array);
                writer.println();
            }

            public void println(double[] array) {
                print(array);
                writer.println();
            }

            public void println() {
                writer.println();
            }

            public void print(Object... objects) {
                for (int i = 0; i < objects.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(objects[i]);
                }
            }

            public void println(Object... objects) {
                print(objects);
                writer.println();
            }

            public void printf(String format, Object... objects) {
                writer.printf(format, objects);
            }

            public void close() {
                writer.close();
            }

            public void flush() {
                writer.flush();
            }

        }

    }

}
