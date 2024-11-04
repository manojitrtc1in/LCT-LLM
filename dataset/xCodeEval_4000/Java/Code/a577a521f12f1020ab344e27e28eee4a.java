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

        private void calculateMinCostByTownIdsAndGoodTypes(int goodType, List<Integer> townIdListForGivenGoodType,
                int[][] minCostByTownIdAndGoodTypeArray, BidirectedNonWeightedGraph villageGraph) {
            
            performBFSAndEvaluateMinCostByTownIdAndGoodTypeArray(goodType, townIdListForGivenGoodType, villageGraph, minCostByTownIdAndGoodTypeArray);
        }

        

        private void performBFSAndEvaluateMinCostByTownIdAndGoodTypeArray(int goodType, List<Integer> townIds, Graph villageGraph, int[][] minCostByTownIdAndGoodTypeArray) {
            Map<Integer, Boolean> visitedNodeMap = new HashMap<>();

            Queue<Integer> bfsQueue = new LinkedList<>();
            for (int nodeId : townIds) {
                visitedNodeMap.put(nodeId, true);
                bfsQueue.add(nodeId);
            }

            while (!bfsQueue.isEmpty()) {
                int currentNodeId = bfsQueue.poll();
                for (int nextNodeId : ((NonWeightedGraph) villageGraph).getNodeIdToAdjacentNodeIdsMap()
                        .get(currentNodeId)) {
                    if (!visitedNodeMap.containsKey(nextNodeId)) {
                        visitedNodeMap.put(nextNodeId, true);
                        minCostByTownIdAndGoodTypeArray[nextNodeId][goodType] = minCostByTownIdAndGoodTypeArray[currentNodeId][goodType] + 1;
                        bfsQueue.add(nextNodeId);
                    }
                }
            }
        }

        private void addRoadsAsEdgesInVillageGraph(BidirectedNonWeightedGraph villageGraph, Road[] roads) {
            for (Road road : roads) {
                villageGraph.addEdge(road.getFromTownId(), road.getToTownId());
            }
        }

        private static class Road {
            private int fromTownId;
            private int toTownId;

            public Road(int fromTownId, int toTownId) {
                this.fromTownId = fromTownId;
                this.toTownId = toTownId;
            }

            public int getFromTownId() {
                return fromTownId;
            }

            public int getToTownId() {
                return toTownId;
            }
        }

        private static class BFS {
            private Graph graph;

            private static final int ROOT_TRAVERSAL_EDGE_FROM_NODE_ID = -1;

            public BFS(Graph graph) {
                this.graph = graph;
            }

            public Traversal traverse(int rootNodeId) {
                List<Integer> rootNodeIds = new ArrayList<>();
                rootNodeIds.add(rootNodeId);
                return traverse(rootNodeIds);
            }

            public Traversal traverse(List<Integer> rootNodeIds) {
                if (graph instanceof NonWeightedGraph) {
                    Map<Integer, Boolean> visitedNodeMap = new HashMap<>();
                    List<TraversalEdge> edgesTraversedInOrder = new ArrayList<>();
                    Queue<Integer> bfsQueue = new LinkedList<>();
                    for (int nodeId : rootNodeIds) {
                        visitedNodeMap.put(nodeId, true);
                        edgesTraversedInOrder.add(createRootTraversalEdge(nodeId));
                        bfsQueue.add(nodeId);
                    }

                    while (!bfsQueue.isEmpty()) {
                        int currentNodeId = bfsQueue.poll();
                        for (int nextNodeId : ((NonWeightedGraph) graph).getNodeIdToAdjacentNodeIdsMap()
                                .get(currentNodeId)) {
                            if (!visitedNodeMap.containsKey(nextNodeId)) {
                                visitedNodeMap.put(nextNodeId, true);
                                edgesTraversedInOrder.add(new NonWeightedTraversalEdge(currentNodeId, nextNodeId));
                                bfsQueue.add(nextNodeId);
                            }
                        }
                    }
                    return (new Traversal(visitedNodeMap, edgesTraversedInOrder));
                } else {
                    throw new UnsupportedOperationException("BFS for weighted graph is un-implemented...");
                }
            }

            private TraversalEdge createRootTraversalEdge(int rootNodeId) {
                if (isNonWeightedGraph(graph)) {
                    return new NonWeightedTraversalEdge(ROOT_TRAVERSAL_EDGE_FROM_NODE_ID, rootNodeId);
                } else {
                    throw new UnsupportedOperationException("BFS for weighted graph is un-implemented...");
                }
            }

            public static boolean isFromNodeOfRootTraversalEdge(int nodeId) {
                return (nodeId == ROOT_TRAVERSAL_EDGE_FROM_NODE_ID);
            }

            private boolean isNonWeightedGraph(Graph graph) {
                return (graph instanceof NonWeightedGraph);
            }

            public interface TraversalEdge {
            }

            public static class NonWeightedTraversalEdge implements TraversalEdge {
                private int fromNodeId;
                private int toNodeId;

                public NonWeightedTraversalEdge(int fromNodeId, int toNodeId) {
                    this.fromNodeId = fromNodeId;
                    this.toNodeId = toNodeId;
                }

                public int getFromNodeId() {
                    return fromNodeId;
                }

                public int getToNodeId() {
                    return toNodeId;
                }
            }

            public static class Traversal {
                private Map<Integer, Boolean> visitedNodeMap;
                private List<TraversalEdge> edgesTraversedInOrder;

                public Traversal(Map<Integer, Boolean> visitedNodeMap,
                        List<TraversalEdge> edgesTraversedInOrder) {
                    this.visitedNodeMap = visitedNodeMap;
                    this.edgesTraversedInOrder = edgesTraversedInOrder;
                }

                public Map<Integer, Boolean> getVisitedNodeMap() {
                    return visitedNodeMap;
                }

                public List<TraversalEdge> getEdgesTraversedInOrder() {
                    return edgesTraversedInOrder;
                }
            }
        }

        private interface Graph {
            void addNode(int nodeId);
            Set<Integer> getNodeIds();
            Set<Edge> getEdges();

            interface Edge {
                int getFirstNode();
                int getSecondNode();
            }

            interface BidirectedEdge extends Edge {

            }

            interface DirectedEdge extends Edge {
                int getFromNode();
                int getToNode();
            }

            interface NonWeightedEdge extends Edge {
            }

            class BidirectedNonWeightedEdge implements BidirectedEdge, NonWeightedEdge {
                private int firstNode;
                private int secondNode;

                public BidirectedNonWeightedEdge(int firstNode, int secondNode) {
                    if(firstNode > secondNode) {
                        int tmp = firstNode;
                        firstNode = secondNode;
                        secondNode = tmp;
                    }
                    this.firstNode = firstNode;
                    this.secondNode = secondNode;
                }

                @Override
                public int getFirstNode() {
                    return firstNode;
                }

                @Override
                public int getSecondNode() {
                    return secondNode;
                }

                @Override
                public boolean equals(Object o) {
                    if (this == o)
                        return true;
                    if (o == null || getClass() != o.getClass())
                        return false;

                    BidirectedNonWeightedEdge that = (BidirectedNonWeightedEdge) o;

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

            class DirectedNonWeightedEdge implements DirectedEdge, NonWeightedEdge {
                private int firstNode;
                private int secondNode;

                public DirectedNonWeightedEdge(int firstNode, int secondNode) {
                    this.firstNode = firstNode;
                    this.secondNode = secondNode;
                }

                @Override
                public int getFirstNode() {
                    return firstNode;
                }

                @Override
                public int getSecondNode() {
                    return secondNode;
                }

                @Override
                public int getFromNode() {
                    return firstNode;
                }

                @Override
                public int getToNode() {
                    return secondNode;
                }

                @Override
                public boolean equals(Object o) {
                    if (this == o)
                        return true;
                    if (o == null || getClass() != o.getClass())
                        return false;

                    DirectedNonWeightedEdge that = (DirectedNonWeightedEdge) o;

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

        private interface NonWeightedGraph extends Graph {
            void addEdge(int nodeAId, int nodeBId);

            Map<Integer, List<Integer>> getNodeIdToAdjacentNodeIdsMap();
        }

        private static abstract class AbstractNonWeightedGraph implements NonWeightedGraph {
            private Set<Integer> nodeIds = new HashSet<>();
            private Set<Edge> edges = new HashSet<>();

            protected Map<Integer, List<Integer>> nodeIdToAdjacentNodeIdsMap = new HashMap<>();

            public AbstractNonWeightedGraph(){
            }

            public AbstractNonWeightedGraph(int size){
                for(int i = 0; i < size; i++) {
                    addNode(i);
                }
            }

            @Override
            public void addNode(int nodeId) {
                nodeIds.add(nodeId);
                nodeIdToAdjacentNodeIdsMap.put(nodeId, new ArrayList<>());
            }

            @Override
            public Map<Integer, List<Integer>> getNodeIdToAdjacentNodeIdsMap() {
                return nodeIdToAdjacentNodeIdsMap;
            }

            @Override
            public Set<Integer> getNodeIds() {
                return nodeIds;
            }

            @Override
            public Set<Edge> getEdges() {
                return edges;
            }
        }

        private static class BidirectedNonWeightedGraph extends AbstractNonWeightedGraph{
            public BidirectedNonWeightedGraph(){
                super();
            }

            public BidirectedNonWeightedGraph(int size){
                super(size);
            }

            @Override
            public void addEdge(int nodeAId, int nodeBId) {
                BidirectedNonWeightedEdge edge = new BidirectedNonWeightedEdge(nodeAId, nodeBId);
                if(!getEdges().contains(edge)) {
                    getEdges().add(edge);
                    nodeIdToAdjacentNodeIdsMap.get(nodeAId).add(nodeBId);
                    nodeIdToAdjacentNodeIdsMap.get(nodeBId).add(nodeAId);
                }
            }
        }


        private static class InputReader {

            private static final int BUFFER_SIZE_IN_BYTES = 1024;

            private InputStream stream;
            private byte[] buffer = new byte[BUFFER_SIZE_IN_BYTES];
            private int nextPositionInBuffer;
            private int numberOfBytesInBuffer;

            public InputReader(InputStream stream) {
                this.stream = stream;
            }

            public int read() {
                if (numberOfBytesInBuffer == -1) {
                    throw new InputMismatchException();
                }
                if (nextPositionInBuffer >= numberOfBytesInBuffer) {
                    fillBuffer();
                    if (numberOfBytesInBuffer <= 0) {
                        return -1;
                    }
                }
                return buffer[nextPositionInBuffer++];
            }

            public int peek() {
                if (numberOfBytesInBuffer == -1) {
                    return -1;
                }
                if (nextPositionInBuffer >= numberOfBytesInBuffer) {
                    try {
                        fillBuffer();
                    } catch (InputMismatchException e) {
                        return -1;
                    }
                    if (numberOfBytesInBuffer <= 0) {
                        return -1;
                    }
                }
                return buffer[nextPositionInBuffer];
            }

            private int fillBuffer() {
                nextPositionInBuffer = 0;
                try {
                    return (numberOfBytesInBuffer = stream.read(buffer));
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }

            public char nextChar() {
                int c = read();
                while (isSpaceChar(c)) {
                    c = read();
                }
                return (char) c;
            }

            public int nextInt() {
                int c = read();
                while (isSpaceChar(c)) {
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
                } while (!isSpaceChar(c));
                return res * sgn;
            }

            public long nextLong() {
                int c = read();
                while (isSpaceChar(c)) {
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
                } while (!isSpaceChar(c));
                return res * sgn;
            }

            public double nextDouble() {
                int c = read();
                while (isSpaceChar(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                double res = 0;
                while (!isSpaceChar(c) && c != '.') {
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
                    while (!isSpaceChar(c)) {
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

            public BigInteger nextBigInteger() {
                try {
                    return new BigInteger(nextString());
                } catch (NumberFormatException e) {
                    throw new InputMismatchException();
                }
            }

            public String nextLine() {
                String s = readLineWithoutAnyTrimming();
                while (s.trim().length() == 0) {
                    s = readLineWithoutAnyTrimming();
                }
                return s;
            }

            private String readLineWithoutAnyTrimming() {
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
                while (isSpaceChar(c)) {
                    c = read();
                }
                StringBuilder res = new StringBuilder();
                do {
                    if (Character.isValidCodePoint(c)) {
                        res.appendCodePoint(c);
                    }
                    c = read();
                } while (!isSpaceChar(c));
                return res.toString();
            }

            public boolean isExhausted() {
                int value;
                while (isSpaceChar(value = peek()) && value != -1) {
                    read();
                }
                return value == -1;
            }

            private boolean isSpaceChar(int c) {
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
