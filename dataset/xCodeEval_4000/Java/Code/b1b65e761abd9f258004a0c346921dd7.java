import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DPashmakAndParmidasProblem solver = new DPashmakAndParmidasProblem();
        solver.solve(1, in, out);
        out.close();
    }

    static class DPashmakAndParmidasProblem {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextArrInt(n);
            long ans = solveMe(n, a);
            out.println(ans);
            

        }

        private long solveMe(int n, int[] aRaw) {
            int[] nbIndices = new int[n];
            int[] b = new int[n + 1];
            HashMap<Integer, Integer> map = new HashMap<>();
            for (int i = n - 1; i >= 0; i--) {
                int nb = map.getOrDefault(aRaw[i], 0) + 1;
                map.put(aRaw[i], nb);
                nbIndices[i] = nb;
                b[nb]++;
            }

            DPashmakAndParmidasProblem.Input[] c = new DPashmakAndParmidasProblem.Input[n + 1];
            for (int i = 0; i <= n; i++) {
                c[i] = new DPashmakAndParmidasProblem.Input(b[i]);
            }

            DPashmakAndParmidasProblem.SegmentTreeFast st = new DPashmakAndParmidasProblem.SegmentTreeFast(c, false);
            long ans = 0;
            HashMap<Integer, Integer> map2 = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int nb = map2.getOrDefault(aRaw[i], 0) + 1;
                map2.put(aRaw[i], nb);
                st.updateMe(nbIndices[i], new DPashmakAndParmidasProblem.Input(-1));
                

                ans += st.getMe(0, nb - 1).val;
            }
            return ans;
        }

        private static int prevBaseOf2(long n) {
            return 63 - Long.numberOfLeadingZeros(n);
        }

        public static StringBuilder repeatSb(StringBuilder sb, String pattern, int n) {
            for (int i = 0; i < n; i++) {
                sb.append(pattern);
            }
            return sb;
        }

        public static String rightPad(String a, char padding, int n) {
            StringBuilder sb = new StringBuilder();
            sb.append(a);
            return repeatSb(sb, "" + padding, Math.max(0, n - a.length())).toString();
            

        }

        public static <T> String stringMeDeb(T[][] a, int[][] cellMinLength) {
            return stringMeDeb(a, null, null, cellMinLength);
        }

        public static <T> String stringMeDeb(T[][] a, Integer maxI, Integer maxJ, int[][] cellMinLength) {
            StringBuilder sb = new StringBuilder();
            sb.append("\n");
            stringMeDebAppend(a, maxI, maxJ, sb, cellMinLength);
            return sb.toString();
        }

        public static <T> void stringMeDebAppend(T[][] a, Integer maxJ, StringBuilder sb, int start, int end, int[] minLength) {
            end = Math.min(a.length - 1, end);

            if (minLength == null) {
                int totalNbColumns = 0;
                for (int i = start; i <= end; i++)
                    totalNbColumns = Math.max(totalNbColumns, a[i].length);
                minLength = new int[totalNbColumns];

                for (int i = start; i <= end; i++) {
                    for (int j = 0; j < a[i].length; j++) {
                        minLength[j] = Math.max(minLength[j], ("" + a[i][j]).length());
                    }
                }
            }

            int totalNbColumns = minLength.length;
            int minLengthLeft = ("[" + end + "] ").length();
            repeatSb(sb, " ", minLengthLeft);
            String[] header = new String[totalNbColumns];
            for (int i = 0; i < totalNbColumns; i++) {
                header[i] = "[" + i + "] ";
                minLength[i] = Math.max(minLength[i], header[i].length());
            }

            stringMeDebAppend(header, maxJ, sb, minLength);
            sb.append("\n");
            for (int i = start; i <= end; i++) {
                sb.append(rightPad("[" + i + "] ", ' ', minLengthLeft));
                stringMeDebAppend(a[i], maxJ, sb, minLength);
                sb.append("\n");
            }
        }

        public static <T> void stringMeDebAppend(T[][] a, Integer maxI, Integer maxJ, StringBuilder sb, int[][] minCellLength) {
            if (maxI == null)
                maxI = 100;
            int firstPart = maxI * 9 / 10;
            if (a.length > maxI) {
                stringMeDebAppend(a, maxJ, sb, 0, firstPart, minCellLength);
                sb.append("...\n");
                stringMeDebAppend(a, maxJ, sb, a.length - maxI + firstPart, a.length - 1, minCellLength);
            } else {
                stringMeDebAppend(a, maxJ, sb, 0, a.length - 1, minCellLength);
            }
        }

        public static <T> void stringMeDebAppend(T[][] a, Integer maxJ, StringBuilder sb, int start, int end, int[][] minCellLength) {
            if (minCellLength == null) {
                stringMeDebAppend(a, maxJ, sb, start, end, (int[]) null);
                return;
            }

            end = Math.min(a.length - 1, end);

            for (int i = start; i <= end; i++) {
                stringMeDebAppend(a[i], maxJ, sb, minCellLength[i]);
                sb.append("\n");
            }
        }

        public static <T> void stringMeDebAppend(T[] a, Integer maxI, StringBuilder sb, int[] minLength) {
            int nbColumns = minLength != null ? minLength.length : a.length;

            if (maxI == null)
                maxI = 100;
            int firstPart = maxI * 9 / 10;
            if (a.length >= maxI) {
                stringMeDebAppend(a, sb, 0, firstPart, minLength);
                sb.append(" ... ");
                stringMeDebAppend(a, sb, nbColumns - maxI + firstPart, nbColumns - 1, minLength);
            } else {
                stringMeDebAppend(a, sb, 0, a.length - 1, minLength);
            }
        }

        public static <T> void stringMeDebAppend(T[] a, StringBuilder sb, int start, int end, int[] minLength) {
            end = Math.min(a.length - 1, end);

            sb.append("|");
            for (int i = start; i <= end; i++) {
                if (minLength == null)
                    sb.append(a[i]).append("|");
                else
                    sb.append(rightPad("" + a[i], ' ', minLength[i])).append("|");
                

            }
        }

        public static void assertTrue(boolean shouldBeTrue, String message) {
            if (!shouldBeTrue)
                throw new RuntimeException(message);
        }

        private static class Forest {
            List<DPashmakAndParmidasProblem.Vertex> roots;

            public Forest(List<DPashmakAndParmidasProblem.Vertex> roots) {
                this.roots = roots;
            }

            public String toString() {
                for (DPashmakAndParmidasProblem.Vertex root : roots) {
                    root.setCellMinLength();
                }

                List<List<DPashmakAndParmidasProblem.Vertex>> vertices = new ArrayList<>();
                List<DPashmakAndParmidasProblem.Vertex> currentRoots = roots;
                vertices.add(currentRoots);
                while (!currentRoots.isEmpty()) {
                    List<DPashmakAndParmidasProblem.Vertex> newCurrentRoots = new ArrayList<>();
                    for (DPashmakAndParmidasProblem.Vertex root : currentRoots) {
                        if (root.children != null)
                            newCurrentRoots.addAll(root.children);
                    }
                    currentRoots = newCurrentRoots;
                    if (currentRoots.isEmpty())
                        break;
                    vertices.add(currentRoots);
                }

                String[][] cells = new String[vertices.size()][];
                int[][] cellMinLength = new int[vertices.size()][];
                for (int i = 0; i < vertices.size(); i++) {
                    List<DPashmakAndParmidasProblem.Vertex> vertexList = vertices.get(i);
                    cells[i] = new String[vertexList.size()];
                    cellMinLength[i] = new int[vertexList.size()];
                    for (int j = 0; j < cells[i].length; j++) {
                        cells[i][j] = "" + vertexList.get(j);
                        cellMinLength[i][j] = vertexList.get(j).cellMinLength;
                    }
                }
                return stringMeDeb(cells, cellMinLength);
            }

        }

        private static class Vertex {
            String label;
            DPashmakAndParmidasProblem.Vertex father;
            List<DPashmakAndParmidasProblem.Vertex> children;
            public Integer cellMinLength;

            public String toString() {
                return label;
            }

            private void setCellMinLength() {
                setCellMinLength(this);
            }

            private void setCellMinLength(DPashmakAndParmidasProblem.Vertex vertex) {
                int ans = 0;
                int cellLength = getCellMinLengthLeave(vertex);
                if (vertex.children != null) {
                    for (DPashmakAndParmidasProblem.Vertex next : vertex.children) {
                        setCellMinLength(next);
                        ans += next.cellMinLength;
                    }
                    ans += vertex.children.size() - 1;

                    if (cellLength > ans) {
                        DPashmakAndParmidasProblem.Vertex lastChild = vertex.children.get(vertex.children.size() - 1);
                        lastChild.cellMinLength += cellLength - ans;
                    }
                }
                vertex.cellMinLength = Math.max(cellLength, ans);
            }

            private int getCellMinLengthLeave(DPashmakAndParmidasProblem.Vertex vertex) {
                return vertex.toString().length();
            }

        }

        private static class Segment {
            long val;

            public Segment() {
            }

            public Segment(long val) {
                this.val = val;
            }

            public String toString() {
                return "" + val;
            }

        }

        private static class Input {
            long val;

            public Input() {
            }

            public Input(long val) {
                this.val = val;
            }

            public String toString() {
                return "" + val;
            }

        }

        private static class SegmentTreeFast {
            int n;
            boolean isWithLazy;
            DPashmakAndParmidasProblem.Segment[] segmentTree;
            DPashmakAndParmidasProblem.Input[] lazy;
            int depth;

            public DPashmakAndParmidasProblem.Segment getLeafSegment(int tindex, DPashmakAndParmidasProblem.Input val, DPashmakAndParmidasProblem.Segment segment) {
                segment.val += val.val;
                return segment;
            }

            public DPashmakAndParmidasProblem.Segment combineInternalLoop(DPashmakAndParmidasProblem.Segment left, DPashmakAndParmidasProblem.Segment right) {
                return new DPashmakAndParmidasProblem.Segment(left.val + right.val);
            }

            private void incLazy(int level, int tindex, DPashmakAndParmidasProblem.Input lazyRes, DPashmakAndParmidasProblem.Input inc) {
                lazyRes.val += inc.val;
            }

            private DPashmakAndParmidasProblem.Segment incSegment(DPashmakAndParmidasProblem.Segment res, DPashmakAndParmidasProblem.Input incLazy) {
                return new DPashmakAndParmidasProblem.Segment(res.val + incLazy.val);
            }

            private void resetLazy(DPashmakAndParmidasProblem.Input input) {
                input.val = 0;
            }

            public SegmentTreeFast(DPashmakAndParmidasProblem.Input[] a, DPashmakAndParmidasProblem.Input[] lazy, boolean isWithLazy) {
                this.n = a.length;
                this.isWithLazy = isWithLazy;
                segmentTree = new DPashmakAndParmidasProblem.Segment[2 * n];
                this.depth = prevBaseOf2(n);

                for (int i = 0; i < n; i++) {
                    segmentTree[n + i] = new DPashmakAndParmidasProblem.Segment();
                    segmentTree[n + i] = getLeafSegment(i, a[i], segmentTree[n + i]);
                }

                if (isWithLazy && lazy == null) {
                    lazy = new DPashmakAndParmidasProblem.Input[n];
                    for (int i = 0; i < n; i++) {
                        lazy[i] = new DPashmakAndParmidasProblem.Input();
                    }
                }
                this.lazy = lazy;
                build();
            }

            public SegmentTreeFast(DPashmakAndParmidasProblem.Input[] a, boolean isWithLazy) {
                this(a, null, isWithLazy);
            }

            private void build() {
                for (int i = n - 1; i > 0; i--) {
                    updateSegment(i);
                }
            }

            void updateSegment(int pos) {
                DPashmakAndParmidasProblem.Segment s1, s2;
                s1 = getSegment(pos << 1);
                s2 = getSegment(pos << 1 | 1);
                segmentTree[pos] = combineInternalLoop(s1, s2);
            }

            private DPashmakAndParmidasProblem.Segment getSegment(int pos) {
                DPashmakAndParmidasProblem.Segment segment = segmentTree[pos];
                if (isWithLazy) {
                    segment = incSegment(segment, lazy[pos >> 1]);
                }
                return segment;
            }

            void pushUp(int tindex) {
                int pos = tindex + n;
                while (pos > 1) {
                    pos >>= 1;
                    updateSegment(pos);
                }
            }

            void updateMe(int tindex, DPashmakAndParmidasProblem.Input value) {
                assertTrue(tindex >= 0 && tindex < n, "tindex (" + tindex + ") is not in range [0, " + n + "]");
                segmentTree[tindex + n] = getLeafSegment(tindex, value, segmentTree[tindex + n]);
                pushUp(tindex);
            }

            DPashmakAndParmidasProblem.Segment getMe(int start0, int end0) {
                assertTrue(start0 <= end0 && start0 >= 0 && end0 < n, "start0 (" + start0 + ") or end0 (" + end0 + ") is not in range [0, " + n + "]");
                int start = start0 + n;
                int end = end0 + n;

                if (isWithLazy) {
                    pushDownLazy(start);
                    pushDownLazy(end);
                }

                end++;
                DPashmakAndParmidasProblem.Segment resL = null;
                DPashmakAndParmidasProblem.Segment resR = null;

                while (start < end) {
                    if ((start & 1) == 1) {
                        

                        if (resL == null)
                            resL = segmentTree[start];
                        else
                            resL = combineInternalLoop(resL, segmentTree[start]);
                        start++;
                    }
                    if ((end & 1) == 1) {
                        end--;
                        

                        if (resR == null)
                            resR = segmentTree[end];
                        else
                            resR = combineInternalLoop(segmentTree[end], resR);
                    }

                    start >>= 1;
                    end >>= 1;
                }

                

                if (resL == null)
                    return resR;
                if (resR == null)
                    return resL;
                return combineInternalLoop(resL, resR);
            }

            private void pushDownLazy(int tindex) {
                for (int level = 0; level < depth; level++) {
                    int indexFather = tindex >> (depth - level);
                    inc(level + 1, indexFather << 1, lazy[indexFather]);
                    inc(level + 1, indexFather << 1 | 1, lazy[indexFather]);
                    

                    resetLazy(lazy[indexFather]);
                }
            }

            public void inc(int level, int tindex, DPashmakAndParmidasProblem.Input inc) {
                segmentTree[tindex] = incSegment(segmentTree[tindex], inc);
                if (tindex < n)
                    incLazy(level, tindex, lazy[tindex], inc);
            }

            public String toString() {
                return toForest().toString();
            }

            private DPashmakAndParmidasProblem.Forest toForest() {
                return toForest(1, false);
            }

            private DPashmakAndParmidasProblem.Forest toForest(int withNoneAdditionnalAllRanges, boolean withId) {
                DPashmakAndParmidasProblem.Vertex[] vertices = new DPashmakAndParmidasProblem.Vertex[2 * n];
                int[] start = new int[2 * n];
                int[] end = new int[2 * n];
                for (int i = 1; i < 2 * n; i++) {
                    vertices[i] = new DPashmakAndParmidasProblem.Vertex();
                    vertices[i].label = (withId ? "(" + i + ") " : "") + segmentTree[i].toString();
                }

                if (withNoneAdditionnalAllRanges == 2) {
                    for (int i = n; i < 2 * n; i++) {
                        start[i] = end[i] = i - n;
                        vertices[i].label = "[" + start[i] + "] " + vertices[i].label;
                    }

                    for (int i = n - 1; i > 0; i--) {
                        start[i] = start[2 * i];
                        end[i] = end[2 * i + 1];
                        vertices[i].label = "[" + start[i] + ", " + end[i] + "] " + vertices[i].label;
                    }
                }

                for (int i = n - 1; i > 0; i--) {
                    vertices[i].children = new ArrayList<>();
                    vertices[i].children.add(vertices[2 * i]);
                    vertices[i].children.add(vertices[2 * i + 1]);
                    vertices[2 * i].father = vertices[i];
                    vertices[2 * i + 1].father = vertices[i];
                }

                for (int i = Integer.numberOfTrailingZeros(n); i < depth; i++) {
                    vertices[n >> (i + 1)] = null;
                }

                

                List<DPashmakAndParmidasProblem.Vertex> roots = new ArrayList<>();
                int iPos = n;
                while (iPos < 2 * n) {
                    int generation = 0;
                    int lastGeneration = generation;
                    DPashmakAndParmidasProblem.Vertex lastVertex = vertices[iPos];
                    while (vertices[iPos >> generation] != null) {
                        lastGeneration = generation;
                        lastVertex = vertices[iPos >> generation];
                        generation++;
                    }

                    int nextIPos = iPos + (1 << lastGeneration);
                    

                    while (lastGeneration + 1 <= depth) {
                        DPashmakAndParmidasProblem.Vertex vertex = new DPashmakAndParmidasProblem.Vertex();
                        vertex.label = "-";
                        lastVertex.father = vertex;
                        vertex.children = new ArrayList<>();
                        vertex.children.add(lastVertex);
                        lastVertex = vertex;
                        lastGeneration++;
                    }
                    roots.add(lastVertex);
                    iPos = nextIPos;
                }

                if (withNoneAdditionnalAllRanges == 1) {
                    for (int i = n; i < 2 * n; i++) {
                        vertices[i].children = new ArrayList<>();
                        DPashmakAndParmidasProblem.Vertex vertex = new DPashmakAndParmidasProblem.Vertex();
                        vertex.label = "[" + (i - n) + "]";
                        vertices[i].children.add(vertex);
                    }
                }
                return new DPashmakAndParmidasProblem.Forest(roots);
            }

        }

    }

    static class FastReader {
        public BufferedReader br;
        public StringTokenizer st;
        String context = null;

        public FastReader(InputStream in) {
            this(new InputStreamReader(in));
        }

        public FastReader(InputStreamReader input) {
            br = new BufferedReader(input);
        }

        public String next() {
            if (context != null) {
                System.err.print("[" + context + "] Wait for input ...");
            }
            while (st == null || !st.hasMoreElements()) {
                try {
                    String s = br.readLine();
                    if (s == null)
                        return null;
                    st = new StringTokenizer(s);
                } catch (IOException e) {
                    e.printStackTrace();
                    throw new RuntimeException("Could not read");
                }
            }
            String res = st.nextToken();
            if (context != null) {
                System.err.println("[" + context + "] ... received : " + res);
            }
            return res;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] nextArrInt(int n) {
            int[] a = new int[n];
            for (int i = 0; i < a.length; i++)
                a[i] = nextInt();
            return a;
        }

    }
}

