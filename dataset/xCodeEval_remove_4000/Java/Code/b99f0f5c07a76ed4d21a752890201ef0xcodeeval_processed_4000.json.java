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
        id12 solver = new id12();
        solver.solve(1, in, out);
        out.close();
    }

    static class id12 {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            id12.Input[] a = new id12.Input[n];
            for (int i = 0; i < n; i++)
                a[i] = new id12.Input(0, 0);
            id12.id19 st = new id12.id19(a, true);
            for (int i = 0; i < m; i++) {
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                int x = in.nextInt() - 1;
                if (x - 1 >= l)
                    st.id18(l, x - 1, new id12.Input(x + 1, m - i));
                if (x + 1 <= r)
                    st.id18(x + 1, r, new id12.Input(x + 1, m - i));
                

            }
            for (int i = 0; i < n; i++) {
                out.println(st.getMe(i, i).val);
            }
        }

        private static int id0(long n) {
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

        public static <T> String id1(T[][] a, int[][] id14) {
            return id1(a, null, null, id14);
        }

        public static <T> String id1(T[][] a, Integer maxI, Integer maxJ, int[][] id14) {
            StringBuilder sb = new StringBuilder();
            sb.append("\n");
            id11(a, maxI, maxJ, sb, id14);
            return sb.toString();
        }

        public static <T> void id11(T[][] a, Integer maxJ, StringBuilder sb, int start, int end, int[] minLength) {
            end = Math.min(a.length - 1, end);

            if (minLength == null) {
                int id3 = 0;
                for (int i = start; i <= end; i++)
                    id3 = Math.max(id3, a[i].length);
                minLength = new int[id3];

                for (int i = start; i <= end; i++) {
                    for (int j = 0; j < a[i].length; j++) {
                        minLength[j] = Math.max(minLength[j], ("" + a[i][j]).length());
                    }
                }
            }

            int id3 = minLength.length;
            int id13 = ("[" + end + "] ").length();
            repeatSb(sb, " ", id13);
            String[] header = new String[id3];
            for (int i = 0; i < id3; i++) {
                header[i] = "[" + i + "] ";
                minLength[i] = Math.max(minLength[i], header[i].length());
            }

            id11(header, maxJ, sb, minLength);
            sb.append("\n");
            for (int i = start; i <= end; i++) {
                sb.append(rightPad("[" + i + "] ", ' ', id13));
                id11(a[i], maxJ, sb, minLength);
                sb.append("\n");
            }
        }

        public static <T> void id11(T[][] a, Integer maxI, Integer maxJ, StringBuilder sb, int[][] id9) {
            if (maxI == null)
                maxI = 100;
            int firstPart = maxI * 9 / 10;
            if (a.length > maxI) {
                id11(a, maxJ, sb, 0, firstPart, id9);
                sb.append("...\n");
                id11(a, maxJ, sb, a.length - maxI + firstPart, a.length - 1, id9);
            } else {
                id11(a, maxJ, sb, 0, a.length - 1, id9);
            }
        }

        public static <T> void id11(T[][] a, Integer maxJ, StringBuilder sb, int start, int end, int[][] id9) {
            if (id9 == null) {
                id11(a, maxJ, sb, start, end, (int[]) null);
                return;
            }

            end = Math.min(a.length - 1, end);

            for (int i = start; i <= end; i++) {
                id11(a[i], maxJ, sb, id9[i]);
                sb.append("\n");
            }
        }

        public static <T> void id11(T[] a, Integer maxI, StringBuilder sb, int[] minLength) {
            int nbColumns = minLength != null ? minLength.length : a.length;

            if (maxI == null)
                maxI = 100;
            int firstPart = maxI * 9 / 10;
            if (a.length >= maxI) {
                id11(a, sb, 0, firstPart, minLength);
                sb.append(" ... ");
                id11(a, sb, nbColumns - maxI + firstPart, nbColumns - 1, minLength);
            } else {
                id11(a, sb, 0, a.length - 1, minLength);
            }
        }

        public static <T> void id11(T[] a, StringBuilder sb, int start, int end, int[] minLength) {
            end = Math.min(a.length - 1, end);

            sb.append("|");
            for (int i = start; i <= end; i++) {
                if (minLength == null)
                    sb.append(a[i]).append("|");
                else
                    sb.append(rightPad("" + a[i], ' ', minLength[i])).append("|");
                

            }
        }

        public static void assertTrue(boolean id5, String message) {
            if (!id5)
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

        private static class id19 {
            int n;
            boolean id4;
            id12.Segment[] segmentTree;
            id12.Input[] lazy;
            int depth;

            public id12.Segment id8(int tindex, id12.Input val) {
                return new id12.Segment(val.val, 0);
            }

            public id12.Segment id15(id12.Segment left, id12.Segment right) {
                return new id12.Segment(0, -1);
            }

            private void incLazy(int level, int tindex, id12.Input lazyRes, id12.Input inc) {
                if (lazyRes.step < inc.step) {
                    lazyRes.step = inc.step;
                    lazyRes.val = inc.val;
                }
            }

            private id12.Segment incSegment(id12.Segment res, id12.Input incLazy) {
                if (res.step < incLazy.step) {
                    res.step = incLazy.step;
                    res.val = incLazy.val;
                }
                return res;
            }

            private void resetLazy(id12.Input input) {
                input.val = 0;
            }

            public id19(id12.Input[] a, id12.Input[] lazy, boolean id4) {
                this.n = a.length;
                this.id4 = id4;
                segmentTree = new id12.Segment[2 * n];
                this.depth = id0(n);

                for (int i = 0; i < n; i++) {
                    segmentTree[n + i] = id8(i, a[i]);
                }

                if (id4 && lazy == null) {
                    lazy = new id12.Input[n];
                    for (int i = 0; i < n; i++) {
                        lazy[i] = new id12.Input();
                    }
                }
                this.lazy = lazy;
                build();
            }

            public id19(id12.Input[] a, boolean id4) {
                this(a, null, id4);
            }

            private void build() {
                for (int i = n - 1; i > 0; i--) {
                    updateSegment(i);
                }
            }

            void updateSegment(int pos) {
                id12.Segment s1, s2;
                s1 = getSegment(pos << 1);
                s2 = getSegment(pos << 1 | 1);
                segmentTree[pos] = id15(s1, s2);
            }

            private id12.Segment getSegment(int pos) {
                id12.Segment segment = segmentTree[pos];
                if (id4) {
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

            id12.Segment getMe(int start0, int end0) {
                assertTrue(start0 <= end0 && start0 >= 0 && end0 < n, "start0 (" + start0 + ") or end0 (" + end0 + ") is not in range [0, " + n + "]");
                int start = start0 + n;
                int end = end0 + n;

                if (id4) {
                    id17(start);
                    id17(end);
                }

                end++;
                id12.Segment resL = null;
                id12.Segment resR = null;

                while (start < end) {
                    if ((start & 1) == 1) {
                        

                        if (resL == null)
                            resL = segmentTree[start];
                        else
                            resL = id15(resL, segmentTree[start]);
                        start++;
                    }
                    if ((end & 1) == 1) {
                        end--;
                        

                        if (resR == null)
                            resR = segmentTree[end];
                        else
                            resR = id15(segmentTree[end], resR);
                    }

                    start >>= 1;
                    end >>= 1;
                }

                

                if (resL == null)
                    return resR;
                if (resR == null)
                    return resL;
                return id15(resL, resR);
            }

            private void id17(int tindex) {
                for (int level = 0; level < depth; level++) {
                    int indexFather = tindex >> (depth - level);
                    inc(level + 1, indexFather << 1, lazy[indexFather]);
                    inc(level + 1, indexFather << 1 | 1, lazy[indexFather]);
                    

                    resetLazy(lazy[indexFather]);
                }
            }

            public void inc(int level, int tindex, id12.Input inc) {
                segmentTree[tindex] = incSegment(segmentTree[tindex], inc);
                if (tindex < n)
                    incLazy(level, tindex, lazy[tindex], inc);
            }

            public void id18(int start0, int end0, id12.Input inc) {
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

            private id12.Forest toForest() {
                return toForest(1, false);
            }

            private id12.Forest toForest(int id6, boolean withId) {
                id12.Vertex[] vertices = new id12.Vertex[2 * n];
                int[] start = new int[2 * n];
                int[] end = new int[2 * n];
                for (int i = 1; i < 2 * n; i++) {
                    vertices[i] = new id12.Vertex();
                    vertices[i].label = (withId ? "(" + i + ") " : "") + segmentTree[i] + (id4 && i < n ? " " + lazy[i] : "");
                }

                if (id6 == 2) {
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

                

                List<id12.Vertex> roots = new ArrayList<>();
                int iPos = n;
                while (iPos < 2 * n) {
                    int generation = 0;
                    int lastGeneration = generation;
                    id12.Vertex lastVertex = vertices[iPos];
                    while (vertices[iPos >> generation] != null) {
                        lastGeneration = generation;
                        lastVertex = vertices[iPos >> generation];
                        generation++;
                    }

                    int id7 = iPos + (1 << lastGeneration);
                    

                    while (lastGeneration + 1 <= depth) {
                        id12.Vertex vertex = new id12.Vertex();
                        vertex.label = "-";
                        lastVertex.father = vertex;
                        vertex.children = new ArrayList<>();
                        vertex.children.add(lastVertex);
                        lastVertex = vertex;
                        lastGeneration++;
                    }
                    roots.add(lastVertex);
                    iPos = id7;
                }

                if (id6 == 1) {
                    for (int i = n; i < 2 * n; i++) {
                        vertices[i].children = new ArrayList<>();
                        id12.Vertex vertex = new id12.Vertex();
                        vertex.label = "[" + (i - n) + "]";
                        vertices[i].children.add(vertex);
                    }
                }
                return new id12.Forest(roots);
            }

        }

        private static class Forest {
            List<id12.Vertex> roots;

            public Forest(List<id12.Vertex> roots) {
                this.roots = roots;
            }

            public String toString() {
                for (id12.Vertex root : roots) {
                    root.id2();
                }

                List<List<id12.Vertex>> vertices = new ArrayList<>();
                List<id12.Vertex> currentRoots = roots;
                vertices.add(currentRoots);
                while (!currentRoots.isEmpty()) {
                    List<id12.Vertex> id10 = new ArrayList<>();
                    for (id12.Vertex root : currentRoots) {
                        if (root.children != null)
                            id10.addAll(root.children);
                    }
                    currentRoots = id10;
                    if (currentRoots.isEmpty())
                        break;
                    vertices.add(currentRoots);
                }

                String[][] cells = new String[vertices.size()][];
                int[][] id14 = new int[vertices.size()][];
                for (int i = 0; i < vertices.size(); i++) {
                    List<id12.Vertex> vertexList = vertices.get(i);
                    cells[i] = new String[vertexList.size()];
                    id14[i] = new int[vertexList.size()];
                    for (int j = 0; j < cells[i].length; j++) {
                        cells[i][j] = "" + vertexList.get(j);
                        id14[i][j] = vertexList.get(j).id14;
                    }
                }
                return id1(cells, id14);
            }

        }

        private static class Vertex {
            String label;
            id12.Vertex father;
            List<id12.Vertex> children;
            public Integer id14;

            public String toString() {
                return label;
            }

            private void id2() {
                id2(this);
            }

            private void id2(id12.Vertex vertex) {
                int ans = 0;
                int cellLength = id16(vertex);
                if (vertex.children != null) {
                    for (id12.Vertex next : vertex.children) {
                        id2(next);
                        ans += next.id14;
                    }
                    ans += vertex.children.size() - 1;

                    if (cellLength > ans) {
                        id12.Vertex lastChild = vertex.children.get(vertex.children.size() - 1);
                        lastChild.id14 += cellLength - ans;
                    }
                }
                vertex.id14 = Math.max(cellLength, ans);
            }

            private int id16(id12.Vertex vertex) {
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

