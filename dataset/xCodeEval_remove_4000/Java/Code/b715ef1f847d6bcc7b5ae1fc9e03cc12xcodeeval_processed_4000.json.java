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
        id8 solver = new id8();
        solver.solve(1, in, out);
        out.close();
    }

    static class id8 {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.id14(n);
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

            id8.Input[] c = new id8.Input[n + 1];
            for (int i = 0; i <= n; i++) {
                c[i] = new id8.Input(b[i]);
            }

            id8.id20 st = new id8.id20(c, false);
            

            long ans = 0;
            HashMap<Integer, Integer> map2 = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int nb = map2.getOrDefault(aRaw[i], 0) + 1;
                map2.put(aRaw[i], nb);
                st.updateMe(nbIndices[i], new id8.Input(-1));
                

                ans += st.getMe(0, nb - 1).val;
            }
            return ans;
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

        public static String id1(id8.id20 st, int id6, boolean withId) {
            int n = st.n;
            id8.Vertex[] vertices = new id8.Vertex[2 * n];
            int[] start = new int[2 * n];
            int[] end = new int[2 * n];
            for (int i = 1; i < 2 * n; i++) {
                vertices[i] = new id8.Vertex();
                vertices[i].label = (withId ? "(" + i + ") " : "") + st.segmentTree[i] + (st.id4 && i < n ? " " + st.lazy[i] : "");
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

            for (int i = Integer.numberOfTrailingZeros(n); i < st.depth; i++) {
                vertices[n >> (i + 1)] = null;
            }

            

            List<id8.Vertex> roots = new ArrayList<>();
            int iPos = n;
            while (iPos < 2 * n) {
                int generation = 0;
                int lastGeneration = generation;
                id8.Vertex lastVertex = vertices[iPos];
                while (vertices[iPos >> generation] != null) {
                    lastGeneration = generation;
                    lastVertex = vertices[iPos >> generation];
                    generation++;
                }

                int id7 = iPos + (1 << lastGeneration);
                

                while (lastGeneration + 1 <= st.depth) {
                    id8.Vertex vertex = new id8.Vertex();
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
                    id8.Vertex vertex = new id8.Vertex();
                    vertex.label = "[" + (i - n) + "]";
                    vertices[i].children.add(vertex);
                }
            }
            return id1(new id8.Forest(roots));
        }

        public static String id1(id8.Forest f) {
            for (id8.Vertex root : f.roots) {
                root.id2();
            }

            List<List<id8.Vertex>> vertices = new ArrayList<>();
            List<id8.Vertex> currentRoots = f.roots;
            vertices.add(currentRoots);
            while (!currentRoots.isEmpty()) {
                List<id8.Vertex> id10 = new ArrayList<>();
                for (id8.Vertex root : currentRoots) {
                    if (root.children != null)
                        id10.addAll(root.children);
                }
                currentRoots = id10;
                if (currentRoots.isEmpty())
                    break;
                vertices.add(currentRoots);
            }

            String[][] cells = new String[vertices.size()][];
            int[][] id15 = new int[vertices.size()][];
            for (int i = 0; i < vertices.size(); i++) {
                List<id8.Vertex> vertexList = vertices.get(i);
                cells[i] = new String[vertexList.size()];
                id15[i] = new int[vertexList.size()];
                for (int j = 0; j < cells[i].length; j++) {
                    cells[i][j] = "" + vertexList.get(j);
                    id15[i][j] = vertexList.get(j).id15;
                }
            }
            return id1(cells, id15);
        }

        public static <T> String id1(T[][] a, int[][] id15) {
            return id1(a, null, null, id15);
        }

        public static <T> String id1(T[][] a, Integer maxI, Integer maxJ, int[][] id15) {
            StringBuilder sb = new StringBuilder();
            sb.append("\n");
            id12(a, maxI, maxJ, sb, id15);
            return sb.toString();
        }

        public static <T> void id12(T[][] a, Integer maxJ, StringBuilder sb, int start, int end, int[] minLength) {
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

            id12(header, maxJ, sb, minLength);
            sb.append("\n");
            for (int i = start; i <= end; i++) {
                sb.append(rightPad("[" + i + "] ", ' ', id13));
                id12(a[i], maxJ, sb, minLength);
                sb.append("\n");
            }
        }

        public static <T> void id12(T[][] a, Integer maxI, Integer maxJ, StringBuilder sb, int[][] id11) {
            if (maxI == null)
                maxI = 100;
            int firstPart = maxI * 9 / 10;
            if (a.length > maxI) {
                id12(a, maxJ, sb, 0, firstPart, id11);
                sb.append("...\n");
                id12(a, maxJ, sb, a.length - maxI + firstPart, a.length - 1, id11);
            } else {
                id12(a, maxJ, sb, 0, a.length - 1, id11);
            }
        }

        public static <T> void id12(T[][] a, Integer maxJ, StringBuilder sb, int start, int end, int[][] id11) {
            if (id11 == null) {
                id12(a, maxJ, sb, start, end, (int[]) null);
                return;
            }

            end = Math.min(a.length - 1, end);

            for (int i = start; i <= end; i++) {
                id12(a[i], maxJ, sb, id11[i]);
                sb.append("\n");
            }
        }

        public static <T> void id12(T[] a, Integer maxI, StringBuilder sb, int[] minLength) {
            int nbColumns = minLength != null ? minLength.length : a.length;

            if (maxI == null)
                maxI = 100;
            int firstPart = maxI * 9 / 10;
            if (a.length >= maxI) {
                id12(a, sb, 0, firstPart, minLength);
                sb.append(" ... ");
                id12(a, sb, nbColumns - maxI + firstPart, nbColumns - 1, minLength);
            } else {
                id12(a, sb, 0, a.length - 1, minLength);
            }
        }

        public static <T> void id12(T[] a, StringBuilder sb, int start, int end, int[] minLength) {
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

        private static class id20 {
            int n;
            boolean id4;
            id8.Segment[] segmentTree;
            id8.Input[] lazy;
            int depth;

            public id8.Segment id9(id8.Segment inout, id8.Input val) {
                inout.val += val.val;
                return inout;
            }

            public id8.Segment id16(id8.Segment inout, id8.Segment left, id8.Segment right) {
                inout.val = left.val + right.val;
                return inout;
            }

            private id8.Input incLazy(id8.Input inout, id8.Input incLazy) {
                inout.val += incLazy.val;
                return inout;
            }

            private id8.Segment incSegment(id8.Segment inout, id8.Input incLazy) {
                inout.val += incLazy.val;
                return inout;
            }

            private id8.Input resetLazy(id8.Input inout) {
                inout.val = 0;
                return inout;
            }

            public id20(id8.Input[] a, id8.Input[] lazy, boolean id4) {
                this.n = a.length;
                this.id4 = id4;
                segmentTree = new id8.Segment[2 * n];
                this.depth = id0(n);

                for (int i = 0; i < 2 * n; i++)
                    segmentTree[i] = new id8.Segment();

                for (int i = 0; i < n; i++) {
                    segmentTree[n + i] = id9(segmentTree[n + i], a[i]);
                }

                if (id4 && lazy == null) {
                    lazy = new id8.Input[n];
                    for (int i = 0; i < n; i++) {
                        lazy[i] = new id8.Input();
                    }
                }
                this.lazy = lazy;
                build();
            }

            public id20(id8.Input[] a, boolean id4) {
                this(a, null, id4);
            }

            private void build() {
                for (int i = n - 1; i > 0; i--) {
                    updateSegment(i);
                }
            }

            void updateMe(int tindex, id8.Input value) {
                assertTrue(tindex >= 0 && tindex < n, "tindex (" + tindex + ") is not in range [0, " + n + "]");
                segmentTree[tindex + n] = id9(segmentTree[tindex + n], value);
                pushUp(tindex);
            }

            id8.Segment getMe(int start0, int end0) {
                assertTrue(start0 <= end0 && start0 >= 0 && end0 < n, "start0 (" + start0 + ") or end0 (" + end0 + ") is not in range [0, " + n + "]");
                int start = start0 + n;
                int end = end0 + n;

                if (id4) {
                    id18(start);
                    id18(end);
                }

                end++;
                id8.Segment resL = null;
                id8.Segment resR = null;
                while (start < end) {
                    if ((start & 1) == 1) {
                        

                        if (resL == null)
                            resL = new id8.Segment(segmentTree[start]);
                        else
                            resL = id16(resL, resL, segmentTree[start]);
                        start++;
                    }
                    if ((end & 1) == 1) {
                        end--;
                        

                        if (resR == null)
                            resR = new id8.Segment(segmentTree[end]);
                        else
                            resR = id16(resR, segmentTree[end], resR);
                    }

                    start >>= 1;
                    end >>= 1;
                }

                

                if (resL == null)
                    return resR;
                if (resR == null)
                    return resL;
                return id16(resL, resL, resR);
            }

            void pushUp(int tindex) {
                int pos = tindex + n;
                while (pos > 1) {
                    pos >>= 1;
                    updateSegment(pos);
                }
            }

            private void id18(int tindex) {
                for (int level = 0; level < depth; level++) {
                    int indexFather = tindex >> (depth - level);
                    inc(indexFather << 1, lazy[indexFather]);
                    inc(indexFather << 1 | 1, lazy[indexFather]);
                    lazy[indexFather] = resetLazy(lazy[indexFather]);
                    

                }
            }

            void updateSegment(int tindex) {
                id8.Segment s1, s2;
                s1 = getSegment(tindex << 1);
                s2 = getSegment(tindex << 1 | 1);
                segmentTree[tindex] = id16(segmentTree[tindex], s1, s2);
            }

            private id8.Segment getSegment(int tindex) {
                id8.Segment segment = new id8.Segment(segmentTree[tindex]);
                if (id4) {
                    segment = incSegment(segment, lazy[tindex >> 1]);
                }
                return segment;
            }

            public void inc(int tindex, id8.Input incLazy) {
                segmentTree[tindex] = incSegment(segmentTree[tindex], incLazy);
                if (tindex < n)
                    lazy[tindex] = incLazy(lazy[tindex], incLazy);
            }

            public String toString() {
                return toString(1, false);
            }

            public String toString(int id19, boolean withId) {
                return id1(this, id19, withId);
            }

        }

        private static class Forest {
            List<id8.Vertex> roots;

            public Forest(List<id8.Vertex> roots) {
                this.roots = roots;
            }

            public String toString() {
                return id1(this);
            }

        }

        private static class Vertex {
            String label;
            id8.Vertex father;
            List<id8.Vertex> children;
            public Integer id15;

            public String toString() {
                return label;
            }

            private void id2() {
                id2(this);
            }

            private void id2(id8.Vertex vertex) {
                int ans = 0;
                int cellLength = id17(vertex);
                if (vertex.children != null) {
                    for (id8.Vertex next : vertex.children) {
                        id2(next);
                        ans += next.id15;
                    }
                    ans += vertex.children.size() - 1;

                    if (cellLength > ans) {
                        id8.Vertex lastChild = vertex.children.get(vertex.children.size() - 1);
                        lastChild.id15 += cellLength - ans;
                    }
                }
                vertex.id15 = Math.max(cellLength, ans);
            }

            private int id17(id8.Vertex vertex) {
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

            public Segment(id8.Segment segment) {
                this(segment.val);
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

        public int[] id14(int n) {
            int[] a = new int[n];
            for (int i = 0; i < a.length; i++)
                a[i] = nextInt();
            return a;
        }

    }
}

