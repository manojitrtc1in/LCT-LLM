import java.io.*;
import java.util.*;

class TaskD {
    static class Input {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        public Input(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        public int readInt() throws IOException {
            return Integer.parseInt(readString());
        }

        public long readLong() throws IOException {
            return Long.parseLong(readString());
        }

        public String readString() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        public int[] readIntArray(int size) throws IOException {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }

        public void close() throws IOException {
            reader.close();
        }
    }

    static class Output {
        private final PrintWriter writer;

        public Output(OutputStream stream) {
            writer = new PrintWriter(stream);
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

        public void flush() {
            writer.flush();
        }

        public void close() {
            writer.close();
        }
    }

    static class Pair<T, U> {
        public final T first;
        public final U second;

        public Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Edge {
        public final int from;
        public final int to;

        public Edge(int from, int to) {
            this.from = from;
            this.to = to;
        }
    }

    static class Graph {
        private final int vertexCount;
        private final List<List<Edge>> edges;

        public Graph(int vertexCount) {
            this.vertexCount = vertexCount;
            edges = new ArrayList<>(vertexCount);
            for (int i = 0; i < vertexCount; i++) {
                edges.add(new ArrayList<>());
            }
        }

        public void addEdge(Edge edge) {
            edges.get(edge.from).add(edge);
        }

        public List<Edge> getEdges(int vertex) {
            return edges.get(vertex);
        }
    }

    static class TaskSolver {
        private final int MAX_N = 3000;
        private final int MAX_M = 3002;
        private final Pair<Integer, Long>[][] answer = new Pair[MAX_N][MAX_M];

        public void solve(Input in, Output out) throws IOException {
            int n = in.readInt();
            int m = in.readInt();
            int[] b = in.readIntArray(n);
            int[] w = in.readIntArray(n);
            int[] x = new int[n - 1];
            int[] y = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                x[i] = in.readInt() - 1;
                y[i] = in.readInt() - 1;
            }

            Graph graph = new Graph(n);
            for (int i = 0; i < n - 1; i++) {
                graph.addEdge(new Edge(x[i], y[i]));
                graph.addEdge(new Edge(y[i], x[i]));
            }

            int[] q = new int[n];
            calcQ(graph, q, 0, -1);

            Pair<Integer, Long>[] temp = new Pair[MAX_N + 2];
            for (int i = 0; i < n + 2; i++) {
                temp[i] = new Pair<>(-1, 0L);
            }

            go(graph, b, w, q, temp, answer, 0, -1);

            out.println(answer[0][m].first);
        }

        private int calcQ(Graph graph, int[] q, int vertex, int last) {
            int res = 1;
            for (Edge edge : graph.getEdges(vertex)) {
                int next = edge.to;
                if (next == last) {
                    continue;
                }
                res += calcQ(graph, q, next, vertex);
            }
            q[vertex] = res;
            return res;
        }

        private void go(Graph graph, int[] b, int[] w, int[] q, Pair<Integer, Long>[] temp,
                        Pair<Integer, Long>[][] answer, int vertex, int last) {
            int id = -1;
            for (Edge edge : graph.getEdges(vertex)) {
                int next = edge.to;
                if (next == last) {
                    continue;
                }
                go(graph, b, w, q, temp, answer, next, vertex);
                if (id == -1 || q[next] > q[id]) {
                    id = next;
                }
            }

            Pair<Integer, Long>[] cur = answer[vertex];
            long delta = w[vertex] - b[vertex];
            if (id == -1) {
                cur[0] = new Pair<>(0, delta);
                cur[1] = new Pair<>(delta > 0 ? 1 : 0, 0L);
                return;
            }

            Pair<Integer, Long>[] aid = answer[id];
            int sz = q[id];
            for (int i = 0; i <= sz; i++) {
                cur[i] = new Pair<>(aid[i].first, aid[i].second + delta);
            }

            for (int i = sz + 1; i <= q[vertex]; i++) {
                cur[i] = new Pair<>(-1, 0L);
            }

            for (Edge edge : graph.getEdges(vertex)) {
                int next = edge.to;
                if (next == last || next == id) {
                    continue;
                }
                Pair<Integer, Long>[] anext = answer[next];
                for (int i = 0; i <= sz; i++) {
                    temp[i] = cur[i];
                    cur[i] = new Pair<>(-1, 0L);
                }

                int nsz = sz + q[next];
                for (int i = 0; i <= sz; i++) {
                    for (int j = 0; j <= q[next]; j++) {
                        if (cur[i + j].first == -1 || temp[i].first + anext[j].first > cur[i + j].first ||
                                (temp[i].first + anext[j].first == cur[i + j].first &&
                                        temp[i].second + anext[j].second > cur[i + j].second)) {
                            cur[i + j] = new Pair<>(temp[i].first + anext[j].first, temp[i].second + anext[j].second);
                        }
                    }
                }
                sz = nsz;
            }

            if (vertex == 0) {
                for (int i = n - 1; i >= 0; i--) {
                    cur[i + 1] = new Pair<>(cur[i].first + (cur[i].second > 0 ? 1 : 0), 0L);
                }
                return;
            }

            for (int i = n - 1; i >= sz + 1; i--) {
                cur[i + 1] = new Pair<>(cur[i].first + (cur[i].second > 0 ? 1 : 0), 0L);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Input in = new Input(System.in);
        Output out = new Output(System.out);
        TaskSolver solver = new TaskSolver();
        int n = in.readInt();
        for (int i = 0; i < n; i++) {
            solver.solve(in, out);
        }
        out.close();
    }
}
