import java.io.BufferedWriter;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.Queue;

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

        private int id49, id10, id40, id56;
        private id23 id41;
        private int[] id4;
        private int[] id12;
        private int[] id36;
        private int[][] id38;

        long startTime = System.currentTimeMillis();

        private void solve(InputReader reader, OutputWriter writer) {
            id49 = reader.nextInt();
            id10 = reader.nextInt();
            id40 = reader.nextInt();
            id56 = reader.nextInt();

            id4 = new int[id49];
            for (int i = 0; i < id49; i++) {
                int goodType = reader.nextInt() - 1;
                id4[i] = goodType;
            }

            id12 = new int[id10];
            id36 = new int[id10];
            for (int i = 0; i < id10; i++) {
                id12[i] = reader.nextInt() - 1;
                id36[i] = reader.nextInt() - 1;
            }

            id47("Constructing id41... ");
            id41 = new id23(id49, id10, id12, id36);
            id47("Constructed id41... ");

            id38 = new int[id49][id40];
            for (int i = 0; i < id40; i++) {
                Arrays.fill(id38[i], -1);
            }
            for (int i = 0; i < id40; i++) {
                id32(i);
            }

            for (int i = 0; i < id49; i++) {
                int id39 = 0;
                Arrays.sort(id38[i]);
                for (int j = 0; j < id56; j++) {
                    id39 += id38[i][j];
                }
                writer.print(id39);
                if(i != id49 - 1) {
                    writer.print(" ");
                }
            }
        }

        private void id47(String string) {
            if (id49 == 100000) {
                long id59 = System.currentTimeMillis() - startTime;
                if (id59 > 1900)
                    System.out.println(string + " " + id59);
            }
        }

        private void id32(int goodType) {
            id47("id32 for goodType: " + goodType);
            BFS.Traversal id28 = id43(goodType);
            BFS.TraversalEdge[] id25 = id28.id13();
            for (BFS.TraversalEdge traversedEdge : id25) {
                BFS.id0 id9 = (BFS.id0) traversedEdge;
                if (!BFS.id27(id9.id5())) {
                    id38[id9.id51()][goodType] =
                            id38[id9.id5()][goodType] + 1;
                } else {
                    id38[id9.id51()][goodType] = 0;
                }
            }
            id47("calculated MinCostByTownIdsAndGoodTypes for goodType: " + goodType);
        }

        private BFS.Traversal id43(int goodType) {
            int[] townIds = new int[id49];
            int id24 = 0;
            for (int i = 0; i < id49; i++) {
                if (id4[i] == goodType) {
                    townIds[id24++] = i;
                }
            }
            BFS id58 = new BFS(id41);
            return id58.traverse(townIds, id24);
        }

        private static class BFS {
            private Graph graph;

            private static final int id34 = -1;

            public BFS(Graph graph) {
                this.graph = graph;
            }

            public Traversal traverse(int id46) {
                int[] id17 = new int[1];
                id17[0] = id46;
                return traverse(id17, 1);
            }

            public Traversal traverse(int[] id17, int id44) {
                if (graph instanceof id21) {
                    int nodeCount = graph.id3();
                    int[] id30 = new int[nodeCount];
                    TraversalEdge[] id53 = new TraversalEdge[nodeCount];
                    int id2 = 0;
                    Queue<Integer> id35 = new LinkedList<>();
                    for (int i = 0; i < id44; i++) {
                        id30[id17[i]] = 1;
                        id53[id2++] = id19(
                                id17[i]);
                        id35.add(id17[i]);
                    }
                    int[][] id52 = ((id21) graph).id55();
                    while (!id35.isEmpty()) {
                        int id60 = id35.poll();
                        for (int id31 : id52[id60]) {
                            if (id30[id31] == 0) {
                                id30[id31] = 1;
                                id53[id2++]
                                        = new id0(id60, id31);
                                id35.add(id31);
                            }
                        }
                    }
                    return (new Traversal(id30, id53, id2));
                } else {
                    throw new UnsupportedOperationException("BFS for weighted graph is un-implemented...");
                }
            }

            private TraversalEdge id19(int id46) {
                if (id48(graph)) {
                    return new id0(id34, id46);
                } else {
                    throw new UnsupportedOperationException("BFS for weighted graph is un-implemented...");
                }
            }

            public static boolean id27(int nodeId) {
                return (nodeId == id34);
            }

            private boolean id48(Graph graph) {
                return (graph instanceof id21);
            }

            public interface TraversalEdge {
            }

            public static class id0 implements TraversalEdge {
                private int id20;
                private int id37;

                public id0(int id20, int id37) {
                    this.id20 = id20;
                    this.id37 = id37;
                }

                public int id5() {
                    return id20;
                }

                public int id51() {
                    return id37;
                }
            }

            public static class Traversal {
                private int[] id30;
                private TraversalEdge[] id53;
                private int id45;

                public Traversal(int[] id30, TraversalEdge[] id53,
                        int id45) {
                    this.id30 = id30;
                    this.id53 = id53;
                    this.id45 = id45;
                }

                public int[] id11() {
                    return id30;
                }

                public TraversalEdge[] id13() {
                    return id53;
                }

                public int id6() {
                    return id45;
                }
            }
        }

        private interface Graph {
            int id3();

            int id61();
        }

        private interface id21 extends Graph {
            int[][] id55();
        }

        private static abstract class id7 implements id21 {

            private int nodeCount;
            protected int edgeCount;

            protected int[][] id52;

            private int[] id29;
            private int[] id22;

            protected int[] inDegrees;
            protected int[] outDegrees;

            protected int[] id33;

            public id7(int nodeCount, int edgeCount, int[] id29, int[] id22) {
                this.nodeCount = nodeCount;
                this.edgeCount = edgeCount;
                this.id29 = id29;
                this.id22 = id22;
                id54();
                id26();
            }

            private void id54() {
                inDegrees = new int[nodeCount];
                outDegrees = new int[nodeCount];
                for (int i = 0; i < edgeCount; i++) {
                    id42(id29[i], id22[i]);
                }
            }

            protected abstract void id42(int nodeA, int nodeB);

            private void id26() {
                id52 = new int[nodeCount][];
                id33 = new int[nodeCount];
                for (int i = 0; i < nodeCount; i++) {
                    id52[i] = new int[outDegrees[i]];
                }

                for (int i = 0; i < edgeCount; i++) {
                    id8(id29[i], id22[i]);
                }
            }

            protected abstract void id8(int nodeA, int nodeB);

            @Override
            public int id3() {
                return nodeCount;
            }

            @Override
            public int id61() {
                return edgeCount;
            }

            public int[][] id55() {
                return id52;
            }
        }

        private static class id23 extends id7 {

            public id23(int nodeCount, int edgeCount, int[] id29,
                    int[] id22) {
                super(nodeCount, edgeCount, id29, id22);
            }

            @Override
            protected void id42(int nodeA, int nodeB) {
                inDegrees[nodeA]++;
                outDegrees[nodeA]++;
                inDegrees[nodeB]++;
                outDegrees[nodeB]++;
            }

            @Override
            protected void id8(int nodeA, int nodeB) {
                id52[nodeA][id33[nodeA]++] = nodeB;
                id52[nodeB][id33[nodeB]++] = nodeA;
            }

        }

        private static class InputReader {

            private static final int id57 = 1024;

            private InputStream stream;
            private byte[] buffer = new byte[id57];
            private int id50;
            private int id16;

            public InputReader(InputStream stream) {
                this.stream = stream;
            }

            public int read() {
                if (id16 == -1) {
                    throw new InputMismatchException();
                }
                if (id50 >= id16) {
                    fillBuffer();
                    if (id16 <= 0) {
                        return -1;
                    }
                }
                return buffer[id50++];
            }

            public int peek() {
                if (id16 == -1) {
                    return -1;
                }
                if (id50 >= id16) {
                    try {
                        fillBuffer();
                    } catch (InputMismatchException e) {
                        return -1;
                    }
                    if (id16 <= 0) {
                        return -1;
                    }
                }
                return buffer[id50];
            }

            private int fillBuffer() {
                id50 = 0;
                try {
                    return (id16 = stream.read(buffer));
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }

            public char nextChar() {
                int c = read();
                while (id15(c)) {
                    c = read();
                }
                return (char) c;
            }

            public int nextInt() {
                int c = read();
                while (id15(c)) {
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
                } while (!id15(c));
                return res * sgn;
            }

            public long nextLong() {
                int c = read();
                while (id15(c)) {
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
                } while (!id15(c));
                return res * sgn;
            }

            public double nextDouble() {
                int c = read();
                while (id15(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                double res = 0;
                while (!id15(c) && c != '.') {
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
                    while (!id15(c)) {
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

            public BigInteger id18() {
                try {
                    return new BigInteger(nextString());
                } catch (NumberFormatException e) {
                    throw new InputMismatchException();
                }
            }

            public String nextLine() {
                String s = id1();
                while (s.trim().length() == 0) {
                    s = id1();
                }
                return s;
            }

            private String id1() {
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
                while (id15(c)) {
                    c = read();
                }
                StringBuilder res = new StringBuilder();
                do {
                    if (Character.isValidCodePoint(c)) {
                        res.appendCodePoint(c);
                    }
                    c = read();
                } while (!id15(c));
                return res.toString();
            }

            public boolean id14() {
                int value;
                while (id15(value = peek()) && value != -1) {
                    read();
                }
                return value == -1;
            }

            private boolean id15(int c) {
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
