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
import java.util.Random;
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

        private int n, m, k, s;

        private int[][] graph; 

        private int[][] minDist;
        private int[] goodTypes; 


        private int[] from;
        private int[] to;

        private void solve(InputReader reader, OutputWriter writer) {
            

            n = reader.nextInt();
            m = reader.nextInt();
            k = reader.nextInt();
            s = reader.nextInt();

            graph = new int[n][];
            minDist = new int[n][k];
            goodTypes = new int[n];

            for(int i = 0; i < n; i++) {
                goodTypes[i] = reader.nextInt() - 1;
                Arrays.fill(minDist[i], -1);
            }

            int f, t;
            from = new int[m]; to = new int[m];
            for(int i = 0; i < m; i++) {
                f = reader.nextInt() - 1;
                t = reader.nextInt() - 1;
                from[i] = f; to[i] = t;
            }

            

            int[] sizes = new int[n];
            for(int i: from) sizes[i]++;
            for(int i: to) sizes[i]++;
            for(int i = 0; i < n; i++) graph[i] = new int[sizes[i]];
            for(int i = 0; i < m; i++) {
                graph[from[i]][--sizes[from[i]]] = to[i];
                graph[to[i]][--sizes[to[i]]] = from[i];
            }

            for(int i = 0; i < k; i++) {
                bfs(i);
            }

            for(int i = 0; i < n; i++) {
                Arrays.sort(minDist[i]);
                int sum = 0;
                for(int j = 0; j < s; j++) {
                    sum += minDist[i][j];
                }
                writer.print(sum);
                if(i != n-1) {
                    writer.print(" ");
                }
            }
        }

        private void bfs(int goodType) { 

            int queueSize = 0;
            int[] nodes = new int[n + 1];
            for(int i = 0; i < n; i++) {
                if(goodTypes[i] == goodType) {
                    minDist[i][goodType] = 0;
                    nodes[queueSize++] = i;
                }
            }
            for(int i = 0; i < queueSize; i++) {
                int current = nodes[i];
                for(int next: graph[current]) {
                    if(minDist[next][goodType] == -1) {
                        minDist[next][goodType] = minDist[current][goodType] + 1;
                        nodes[queueSize++] = next;
                    }
                }
            }
        }

        private void id24(int goodType, List<Integer> id42,
                int[][] id31, id17 id33) {
            
            id18(goodType, id42, id33, id31);
        }

        

        private void id18(int goodType, List<Integer> townIds, Graph id33, int[][] id31) {
            Map<Integer, Boolean> id22 = new HashMap<>();

            Queue<Integer> id29 = new LinkedList<>();
            for (int nodeId : townIds) {
                id22.put(nodeId, true);
                id29.add(nodeId);
            }

            while (!id29.isEmpty()) {
                int id49 = id29.poll();
                for (int id23 : ((id14) id33).id32()
                        .get(id49)) {
                    if (!id22.containsKey(id23)) {
                        id22.put(id23, true);
                        id31[id23][goodType] = id31[id49][goodType] + 1;
                        id29.add(id23);
                    }
                }
            }
        }

        private void id47(id17 id33, Road[] roads) {
            for (Road road : roads) {
                id33.addEdge(road.id21(), road.id34());
            }
        }

        private static class Road {
            private int id50;
            private int id20;

            public Road(int id50, int id20) {
                this.id50 = id50;
                this.id20 = id20;
            }

            public int id21() {
                return id50;
            }

            public int id34() {
                return id20;
            }
        }

        private static class BFS {
            private Graph graph;

            private static final int id26 = -1;

            public BFS(Graph graph) {
                this.graph = graph;
            }

            public Traversal traverse(int id35) {
                List<Integer> id10 = new ArrayList<>();
                id10.add(id35);
                return traverse(id10);
            }

            public Traversal traverse(List<Integer> id10) {
                if (graph instanceof id14) {
                    Map<Integer, Boolean> id22 = new HashMap<>();
                    List<TraversalEdge> id43 = new ArrayList<>();
                    Queue<Integer> id29 = new LinkedList<>();
                    for (int nodeId : id10) {
                        id22.put(nodeId, true);
                        id43.add(id12(nodeId));
                        id29.add(nodeId);
                    }

                    while (!id29.isEmpty()) {
                        int id49 = id29.poll();
                        for (int id23 : ((id14) graph).id32()
                                .get(id49)) {
                            if (!id22.containsKey(id23)) {
                                id22.put(id23, true);
                                id43.add(new id0(id49, id23));
                                id29.add(id23);
                            }
                        }
                    }
                    return (new Traversal(id22, id43));
                } else {
                    throw new UnsupportedOperationException("BFS for weighted graph is un-implemented...");
                }
            }

            private TraversalEdge id12(int id35) {
                if (id37(graph)) {
                    return new id0(id26, id35);
                } else {
                    throw new UnsupportedOperationException("BFS for weighted graph is un-implemented...");
                }
            }

            public static boolean id19(int nodeId) {
                return (nodeId == id26);
            }

            private boolean id37(Graph graph) {
                return (graph instanceof id14);
            }

            public interface TraversalEdge {
            }

            public static class id0 implements TraversalEdge {
                private int id13;
                private int id30;

                public id0(int id13, int id30) {
                    this.id13 = id13;
                    this.id30 = id30;
                }

                public int id3() {
                    return id13;
                }

                public int id41() {
                    return id30;
                }
            }

            public static class Traversal {
                private Map<Integer, Boolean> id22;
                private List<TraversalEdge> id43;

                public Traversal(Map<Integer, Boolean> id22,
                        List<TraversalEdge> id43) {
                    this.id22 = id22;
                    this.id43 = id43;
                }

                public Map<Integer, Boolean> id5() {
                    return id22;
                }

                public List<TraversalEdge> id6() {
                    return id43;
                }
            }
        }

        private interface Graph {
            void addNode(int nodeId);
            Set<Integer> id46();
            Set<Edge> getEdges();

            interface Edge {
                int id25();
                int id38();
            }

            interface id28 extends Edge {

            }

            interface DirectedEdge extends Edge {
                int id39();
                int id15();
            }

            interface id1 extends Edge {
            }

            class id44 implements id28, id1 {
                private int firstNode;
                private int secondNode;

                public id44(int firstNode, int secondNode) {
                    if(firstNode > secondNode) {
                        int tmp = firstNode;
                        firstNode = secondNode;
                        secondNode = tmp;
                    }
                    this.firstNode = firstNode;
                    this.secondNode = secondNode;
                }

                @Override
                public int id25() {
                    return firstNode;
                }

                @Override
                public int id38() {
                    return secondNode;
                }

                @Override
                public boolean equals(Object o) {
                    if (this == o)
                        return true;
                    if (o == null || getClass() != o.getClass())
                        return false;

                    id44 that = (id44) o;

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

            class id27 implements DirectedEdge, id1 {
                private int firstNode;
                private int secondNode;

                public id27(int firstNode, int secondNode) {
                    this.firstNode = firstNode;
                    this.secondNode = secondNode;
                }

                @Override
                public int id25() {
                    return firstNode;
                }

                @Override
                public int id38() {
                    return secondNode;
                }

                @Override
                public int id39() {
                    return firstNode;
                }

                @Override
                public int id15() {
                    return secondNode;
                }

                @Override
                public boolean equals(Object o) {
                    if (this == o)
                        return true;
                    if (o == null || getClass() != o.getClass())
                        return false;

                    id27 that = (id27) o;

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

        private interface id14 extends Graph {
            void addEdge(int id36, int id45);

            Map<Integer, List<Integer>> id32();
        }

        private static abstract class id4 implements id14 {
            private Set<Integer> nodeIds = new HashSet<>();
            private Set<Edge> edges = new HashSet<>();

            protected Map<Integer, List<Integer>> id16 = new HashMap<>();

            public id4(){
            }

            public id4(int size){
                for(int i = 0; i < size; i++) {
                    addNode(i);
                }
            }

            @Override
            public void addNode(int nodeId) {
                nodeIds.add(nodeId);
                id16.put(nodeId, new ArrayList<>());
            }

            @Override
            public Map<Integer, List<Integer>> id32() {
                return id16;
            }

            @Override
            public Set<Integer> id46() {
                return nodeIds;
            }

            @Override
            public Set<Edge> getEdges() {
                return edges;
            }
        }

        private static class id17 extends id4{
            public id17(){
                super();
            }

            public id17(int size){
                super(size);
            }

            @Override
            public void addEdge(int id36, int id45) {
                id44 edge = new id44(id36, id45);
                if(!getEdges().contains(edge)) {
                    getEdges().add(edge);
                    id16.get(id36).add(id45);
                    id16.get(id45).add(id36);
                }
            }
        }


        private static class InputReader {

            private static final int id48 = 1024;

            private InputStream stream;
            private byte[] buffer = new byte[id48];
            private int id40;
            private int id9;

            public InputReader(InputStream stream) {
                this.stream = stream;
            }

            public int read() {
                if (id9 == -1) {
                    throw new InputMismatchException();
                }
                if (id40 >= id9) {
                    fillBuffer();
                    if (id9 <= 0) {
                        return -1;
                    }
                }
                return buffer[id40++];
            }

            public int peek() {
                if (id9 == -1) {
                    return -1;
                }
                if (id40 >= id9) {
                    try {
                        fillBuffer();
                    } catch (InputMismatchException e) {
                        return -1;
                    }
                    if (id9 <= 0) {
                        return -1;
                    }
                }
                return buffer[id40];
            }

            private int fillBuffer() {
                id40 = 0;
                try {
                    return (id9 = stream.read(buffer));
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }

            public char nextChar() {
                int c = read();
                while (id8(c)) {
                    c = read();
                }
                return (char) c;
            }

            public int nextInt() {
                int c = read();
                while (id8(c)) {
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
                } while (!id8(c));
                return res * sgn;
            }

            public long nextLong() {
                int c = read();
                while (id8(c)) {
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
                } while (!id8(c));
                return res * sgn;
            }

            public double nextDouble() {
                int c = read();
                while (id8(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                double res = 0;
                while (!id8(c) && c != '.') {
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
                    while (!id8(c)) {
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

            public BigInteger id11() {
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
                while (id8(c)) {
                    c = read();
                }
                StringBuilder res = new StringBuilder();
                do {
                    if (Character.isValidCodePoint(c)) {
                        res.appendCodePoint(c);
                    }
                    c = read();
                } while (!id8(c));
                return res.toString();
            }

            public boolean id7() {
                int value;
                while (id8(value = peek()) && value != -1) {
                    read();
                }
                return value == -1;
            }

            private boolean id8(int c) {
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
