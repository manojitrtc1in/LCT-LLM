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

        private int numberOfTowns, numberOfRoads, numberOfGoodTypes, necessaryNumberOfGoodTypesForFair;
        private BidirectedNonWeightedGraph villageGraph;
        private int[] goodTypeByTownIdArray;
        private int[] fromRoadNodeIds;
        private int[] toRoadNodeIds;
        private int[][] minCostByTownIdAndGoodTypeArray;

        private void solve(InputReader reader, OutputWriter writer) {
            numberOfTowns = reader.nextInt();
            numberOfRoads = reader.nextInt();
            numberOfGoodTypes = reader.nextInt();
            necessaryNumberOfGoodTypesForFair = reader.nextInt();

            goodTypeByTownIdArray = new int[numberOfTowns];
            for (int i = 0; i < numberOfTowns; i++) {
                int goodType = reader.nextInt() - 1;
                goodTypeByTownIdArray[i] = goodType;
            }

            fromRoadNodeIds = new int[numberOfRoads];
            toRoadNodeIds = new int[numberOfRoads];
            for (int i = 0; i < numberOfRoads; i++) {
                fromRoadNodeIds[i] = reader.nextInt() - 1;
                toRoadNodeIds[i] = reader.nextInt() - 1;
            }

            villageGraph = new BidirectedNonWeightedGraph(numberOfTowns, numberOfRoads, fromRoadNodeIds, toRoadNodeIds);

            minCostByTownIdAndGoodTypeArray = new int[numberOfTowns][numberOfGoodTypes];
            for (int i = 0; i < numberOfGoodTypes; i++) {
                Arrays.fill(minCostByTownIdAndGoodTypeArray[i], -1);
            }
            for (int i = 0; i < numberOfGoodTypes; i++) {
                calculateMinCostByTownIdsAndGoodTypes(i);
            }

            for (int i = 0; i < numberOfTowns; i++) {
                int minFairCost = 0;
                Arrays.sort(minCostByTownIdAndGoodTypeArray[i]);
                for (int j = 0; j < necessaryNumberOfGoodTypesForFair; j++) {
                    minFairCost += minCostByTownIdAndGoodTypeArray[i][j];
                }
                if (i != 0) {
                    writer.print(" ");
                }
                writer.print(minFairCost);
            }
        }

        private void calculateMinCostByTownIdsAndGoodTypes(int goodType) {
            BFS.Traversal villageBFSTraversalByGivenTownIdsAsRoot = performBFS(goodType);
            BFS.TraversalEdge[] traversedEdges = villageBFSTraversalByGivenTownIdsAsRoot.getEdgesTraversedInOrder();
            for (BFS.TraversalEdge traversedEdge : traversedEdges) {
                BFS.NonWeightedTraversalEdge nonWeightedTraversalEdge = (BFS.NonWeightedTraversalEdge) traversedEdge;
                if (!BFS.isFromNodeOfRootTraversalEdge(nonWeightedTraversalEdge.getFromNodeId())) {
                    minCostByTownIdAndGoodTypeArray[nonWeightedTraversalEdge.getToNodeId()][goodType] =
                            minCostByTownIdAndGoodTypeArray[nonWeightedTraversalEdge.getFromNodeId()][goodType] + 1;
                } else {
                    minCostByTownIdAndGoodTypeArray[nonWeightedTraversalEdge.getToNodeId()][goodType] = 0;
                }
            }
        }

        private BFS.Traversal performBFS(int goodType) {
            int[] townIds = new int[numberOfTowns];
            int townIdsSize = 0;
            for (int i = 0; i < numberOfTowns; i++) {
                if (goodTypeByTownIdArray[i] == goodType) {
                    townIds[townIdsSize++] = i;
                }
            }
            BFS villageBFS = new BFS(villageGraph);
            return villageBFS.traverse(townIds, townIdsSize);
        }

        private static class BFS {
            private Graph graph;

            private static final int ROOT_TRAVERSAL_EDGE_FROM_NODE_ID = -1;

            public BFS(Graph graph) {
                this.graph = graph;
            }

            public Traversal traverse(int rootNodeId) {
                int[] rootNodeIds = new int[1];
                rootNodeIds[0] = rootNodeId;
                return traverse(rootNodeIds, 1);
            }

            public Traversal traverse(int[] rootNodeIds, int rootNodeIdsSize) {
                if (graph instanceof NonWeightedGraph) {
                    int nodeCount = graph.getNodeCount();
                    int[] visitedNodeMap = new int[nodeCount];
                    TraversalEdge[] edgesTraversedInOrder = new TraversalEdge[nodeCount];
                    int edgesTraversedInOrderArraySize = 0;
                    Queue<Integer> bfsQueue = new LinkedList<>();
                    for (int i = 0; i < rootNodeIdsSize; i++) {
                        visitedNodeMap[rootNodeIds[i]] = 1;
                        edgesTraversedInOrder[edgesTraversedInOrderArraySize++] = createRootTraversalEdge(
                                rootNodeIds[i]);
                        bfsQueue.add(rootNodeIds[i]);
                    }
                    int[][] nodeIdToAdjacentNodeIds = ((NonWeightedGraph) graph).getNodeIdToAdjacentNodeIds();
                    while (!bfsQueue.isEmpty()) {
                        int currentNodeId = bfsQueue.poll();
                        for (int nextNodeId : nodeIdToAdjacentNodeIds[currentNodeId]) {
                            if (visitedNodeMap[nextNodeId] == 0) {
                                visitedNodeMap[nextNodeId] = 1;
                                edgesTraversedInOrder[edgesTraversedInOrderArraySize++]
                                        = new NonWeightedTraversalEdge(currentNodeId, nextNodeId);
                                bfsQueue.add(nextNodeId);
                            }
                        }
                    }
                    return (new Traversal(visitedNodeMap, edgesTraversedInOrder, edgesTraversedInOrderArraySize));
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
                private int[] visitedNodeMap;
                private TraversalEdge[] edgesTraversedInOrder;
                private int edgesTraversedInOrderSize;

                public Traversal(int[] visitedNodeMap, TraversalEdge[] edgesTraversedInOrder,
                        int edgesTraversedInOrderSize) {
                    this.visitedNodeMap = visitedNodeMap;
                    this.edgesTraversedInOrder = edgesTraversedInOrder;
                    this.edgesTraversedInOrderSize = edgesTraversedInOrderSize;
                }

                public int[] getVisitedNodeMap() {
                    return visitedNodeMap;
                }

                public TraversalEdge[] getEdgesTraversedInOrder() {
                    return edgesTraversedInOrder;
                }

                public int getEdgesTraversedInOrderSize() {
                    return edgesTraversedInOrderSize;
                }
            }
        }

        private interface Graph {
            int getNodeCount();

            int getEdgeCount();
        }

        private interface NonWeightedGraph extends Graph {
            int[][] getNodeIdToAdjacentNodeIds();
        }

        private static abstract class AbstractNonWeightedGraph implements NonWeightedGraph {

            private int nodeCount;
            protected int edgeCount;

            protected int[][] nodeIdToAdjacentNodeIds;

            private int[] edgeFirstNodes;
            private int[] edgeSecondNodes;

            protected int[] inDegrees;
            protected int[] outDegrees;

            protected int[] nodeIdToAdjacentNodeIdsSize;

            public AbstractNonWeightedGraph(int nodeCount, int edgeCount, int[] edgeFirstNodes, int[] edgeSecondNodes) {
                this.nodeCount = nodeCount;
                this.edgeCount = edgeCount;
                this.edgeFirstNodes = edgeFirstNodes;
                this.edgeSecondNodes = edgeSecondNodes;
                buildNodeDegrees();
                buildNodeIdToAdjacentNodeIds();
            }

            private void buildNodeDegrees() {
                inDegrees = new int[nodeCount];
                outDegrees = new int[nodeCount];
                for (int i = 0; i < edgeCount; i++) {
                    processEdgeForNodeDegreesEvaluation(edgeFirstNodes[i], edgeSecondNodes[i]);
                }
            }

            protected abstract void processEdgeForNodeDegreesEvaluation(int nodeA, int nodeB);

            private void buildNodeIdToAdjacentNodeIds() {
                nodeIdToAdjacentNodeIds = new int[nodeCount][];
                nodeIdToAdjacentNodeIdsSize = new int[nodeCount];
                for (int i = 0; i < nodeCount; i++) {
                    nodeIdToAdjacentNodeIds[i] = new int[outDegrees[i]];
                }

                for (int i = 0; i < edgeCount; i++) {
                    processEdgeForNodeIdToAdjacentNodeIdsEvaluation(edgeFirstNodes[i], edgeSecondNodes[i]);
                }
            }

            protected abstract void processEdgeForNodeIdToAdjacentNodeIdsEvaluation(int nodeA, int nodeB);

            @Override
            public int getNodeCount() {
                return nodeCount;
            }

            @Override
            public int getEdgeCount() {
                return edgeCount;
            }

            public int[][] getNodeIdToAdjacentNodeIds() {
                return nodeIdToAdjacentNodeIds;
            }
        }

        private static class BidirectedNonWeightedGraph extends AbstractNonWeightedGraph {

            public BidirectedNonWeightedGraph(int nodeCount, int edgeCount, int[] edgeFirstNodes,
                    int[] edgeSecondNodes) {
                super(nodeCount, edgeCount, edgeFirstNodes, edgeSecondNodes);
            }

            @Override
            protected void processEdgeForNodeDegreesEvaluation(int nodeA, int nodeB) {
                inDegrees[nodeA]++;
                outDegrees[nodeA]++;
                inDegrees[nodeB]++;
                outDegrees[nodeB]++;
            }

            @Override
            protected void processEdgeForNodeIdToAdjacentNodeIdsEvaluation(int nodeA, int nodeB) {
                nodeIdToAdjacentNodeIds[nodeA][nodeIdToAdjacentNodeIdsSize[nodeA]++] = nodeB;
                nodeIdToAdjacentNodeIds[nodeB][nodeIdToAdjacentNodeIdsSize[nodeB]++] = nodeA;
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
