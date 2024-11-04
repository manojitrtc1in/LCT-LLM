import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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
        AKnightTournament solver = new AKnightTournament();
        solver.solve(1, in, out);
        out.close();
    }

    static class AKnightTournament {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            AKnightTournament.Input[] a = new AKnightTournament.Input[n];
            for (int i = 0; i < n; i++)
                a[i] = new AKnightTournament.Input(0, 0);
            AKnightTournament.SegmentTreeFast st = new AKnightTournament.SegmentTreeFast(a, true);
            for (int i = 0; i < m; i++) {
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                int x = in.nextInt() - 1;
                if (x - 1 >= l)
                    st.updateRangeLazy(l, x - 1, new AKnightTournament.Input(x + 1, m - i));
                if (x + 1 <= r)
                    st.updateRangeLazy(x + 1, r, new AKnightTournament.Input(x + 1, m - i));
                

            }
            for (int i = 0; i < n; i++) {
                out.println(st.getMe(i, i).val);
            }
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

        private static class Segment {
            long val;
            int step;

            public Segment() {
            }

            public Segment(long val, int step) {
                this.val = val;
                this.step = step;
            }

            public String toString() {
                return "" + val + ";" + step;
            }

        }

        private static class Input {
            long val;
            int step;

            public Input() {
            }

            public Input(long val, int step) {
                this.val = val;
                this.step = step;
            }

            public String toString() {
                return "" + val;
            }

        }

        private static class SegmentTreeFast {
            int n;
            boolean isWithLazy;
            AKnightTournament.Segment[] segmentTree;
            AKnightTournament.Input[] lazy;
            int depth;

            public AKnightTournament.Segment getLeafSegment(int tindex, AKnightTournament.Input val) {
                return new AKnightTournament.Segment(val.val, 0);
            }

            public AKnightTournament.Segment combineInternalLoop(AKnightTournament.Segment left, AKnightTournament.Segment right) {
                return new AKnightTournament.Segment(0, -1);
            }

            private void incLazy(int level, int tindex, AKnightTournament.Input lazyRes, AKnightTournament.Input inc) {
                if (lazyRes.step < inc.step) {
                    lazyRes.step = inc.step;
                    lazyRes.val = inc.val;
                }
            }

            private AKnightTournament.Segment incSegment(AKnightTournament.Segment res, AKnightTournament.Input incLazy) {
                if (res.step < incLazy.step) {
                    res.step = incLazy.step;
                    res.val = incLazy.val;
                }
                return res;
            }

            private void resetLazy(AKnightTournament.Input input) {
                input.val = 0;
            }

            public SegmentTreeFast(AKnightTournament.Input[] a, AKnightTournament.Input[] lazy, boolean isWithLazy) {
                this.n = a.length;
                this.isWithLazy = isWithLazy;
                segmentTree = new AKnightTournament.Segment[2 * n];
                this.depth = prevBaseOf2(n);

                for (int i = 0; i < n; i++) {
                    segmentTree[n + i] = getLeafSegment(i, a[i]);
                }

                if (isWithLazy && lazy == null) {
                    lazy = new AKnightTournament.Input[n];
                    for (int i = 0; i < n; i++) {
                        lazy[i] = new AKnightTournament.Input();
                    }
                }
                this.lazy = lazy;
                build();
            }

            public SegmentTreeFast(AKnightTournament.Input[] a, boolean isWithLazy) {
                this(a, null, isWithLazy);
            }

            private void build() {
                for (int i = n - 1; i > 0; i--) {
                    updateSegment(i);
                }
            }

            void updateSegment(int pos) {
                AKnightTournament.Segment s1, s2;
                s1 = getSegment(pos << 1);
                s2 = getSegment(pos << 1 | 1);
                segmentTree[pos] = combineInternalLoop(s1, s2);
            }

            private AKnightTournament.Segment getSegment(int pos) {
                AKnightTournament.Segment segment = segmentTree[pos];
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

            AKnightTournament.Segment getMe(int start0, int end0) {
                assertTrue(start0 <= end0 && start0 >= 0 && end0 < n, "start0 (" + start0 + ") or end0 (" + end0 + ") is not in range [0, " + n + "]");
                int start = start0 + n;
                int end = end0 + n;

                if (isWithLazy) {
                    pushDownLazy(start);
                    pushDownLazy(end);
                }

                end++;
                AKnightTournament.Segment resL = null;
                AKnightTournament.Segment resR = null;

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

            public void inc(int level, int tindex, AKnightTournament.Input inc) {
                segmentTree[tindex] = incSegment(segmentTree[tindex], inc);
                if (tindex < n)
                    incLazy(level, tindex, lazy[tindex], inc);
            }

            public void updateRangeLazy(int start0, int end0, AKnightTournament.Input inc) {
                assertTrue(start0 <= end0 && start0 >= 0 && end0 < n, "start0 (" + start0 + ") or end0 (" + end0 + ") is not in range [0, " + n + "]");
                int start = start0 + n;
                int end = end0 + n + 1;
                int level = depth;

                while (start < end) {
                    if ((start & 1) == 1) {
                        inc(level, start, inc);
                        start++;
                    }
                    if ((end & 1) == 1) {
                        end--;
                        inc(level, end, inc);
                    }
                    level--;
                    start >>= 1;
                    end >>= 1;
                }
                pushUp(start0);
                pushUp(end0);
            }

            public String toString() {
                return toForest().toString();
            }

            private AKnightTournament.Forest toForest() {
                return toForest(1, false);
            }

            private AKnightTournament.Forest toForest(int withNoneAdditionnalAllRanges, boolean withId) {
                AKnightTournament.Vertex[] vertices = new AKnightTournament.Vertex[2 * n];
                int[] start = new int[2 * n];
                int[] end = new int[2 * n];
                for (int i = 1; i < 2 * n; i++) {
                    vertices[i] = new AKnightTournament.Vertex();
                    vertices[i].label = (withId ? "(" + i + ") " : "") + segmentTree[i] + (isWithLazy && i < n ? " " + lazy[i] : "");
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

                

                List<AKnightTournament.Vertex> roots = new ArrayList<>();
                int iPos = n;
                while (iPos < 2 * n) {
                    int generation = 0;
                    int lastGeneration = generation;
                    AKnightTournament.Vertex lastVertex = vertices[iPos];
                    while (vertices[iPos >> generation] != null) {
                        lastGeneration = generation;
                        lastVertex = vertices[iPos >> generation];
                        generation++;
                    }

                    int nextIPos = iPos + (1 << lastGeneration);
                    

                    while (lastGeneration + 1 <= depth) {
                        AKnightTournament.Vertex vertex = new AKnightTournament.Vertex();
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
                        AKnightTournament.Vertex vertex = new AKnightTournament.Vertex();
                        vertex.label = "[" + (i - n) + "]";
                        vertices[i].children.add(vertex);
                    }
                }
                return new AKnightTournament.Forest(roots);
            }

        }

        private static class Forest {
            List<AKnightTournament.Vertex> roots;

            public Forest(List<AKnightTournament.Vertex> roots) {
                this.roots = roots;
            }

            public String toString() {
                for (AKnightTournament.Vertex root : roots) {
                    root.setCellMinLength();
                }

                List<List<AKnightTournament.Vertex>> vertices = new ArrayList<>();
                List<AKnightTournament.Vertex> currentRoots = roots;
                vertices.add(currentRoots);
                while (!currentRoots.isEmpty()) {
                    List<AKnightTournament.Vertex> newCurrentRoots = new ArrayList<>();
                    for (AKnightTournament.Vertex root : currentRoots) {
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
                    List<AKnightTournament.Vertex> vertexList = vertices.get(i);
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
            AKnightTournament.Vertex father;
            List<AKnightTournament.Vertex> children;
            public Integer cellMinLength;

            public String toString() {
                return label;
            }

            private void setCellMinLength() {
                setCellMinLength(this);
            }

            private void setCellMinLength(AKnightTournament.Vertex vertex) {
                int ans = 0;
                int cellLength = getCellMinLengthLeave(vertex);
                if (vertex.children != null) {
                    for (AKnightTournament.Vertex next : vertex.children) {
                        setCellMinLength(next);
                        ans += next.cellMinLength;
                    }
                    ans += vertex.children.size() - 1;

                    if (cellLength > ans) {
                        AKnightTournament.Vertex lastChild = vertex.children.get(vertex.children.size() - 1);
                        lastChild.cellMinLength += cellLength - ans;
                    }
                }
                vertex.cellMinLength = Math.max(cellLength, ans);
            }

            private int getCellMinLengthLeave(AKnightTournament.Vertex vertex) {
                return vertex.toString().length();
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

    }
}

