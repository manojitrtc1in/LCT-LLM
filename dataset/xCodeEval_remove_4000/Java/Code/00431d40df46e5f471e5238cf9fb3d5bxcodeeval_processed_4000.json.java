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
        id5 solver = new id5();
        solver.solve(1, in, out);
        out.close();
    }

    static class id5 {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            id5.Input[] a = new id5.Input[1 << n];
            for (int i = 0; i < (1 << n); i++)
                a[i] = new id5.Input(in.nextInt());

            id5.id18 st = new id5.id18(a, false);
            

            for (int i = 0; i < m; i++) {
                st.updateMe(in.nextInt() - 1, new id5.Input(in.nextInt()));
                out.println(st.getMe(0, (1 << n) - 1));
                

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
            id12(a, maxI, maxJ, sb, id14);
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

        public static <T> void id12(T[][] a, Integer maxI, Integer maxJ, StringBuilder sb, int[][] id10) {
            if (maxI == null)
                maxI = 100;
            int firstPart = maxI * 9 / 10;
            if (a.length > maxI) {
                id12(a, maxJ, sb, 0, firstPart, id10);
                sb.append("...\n");
                id12(a, maxJ, sb, a.length - maxI + firstPart, a.length - 1, id10);
            } else {
                id12(a, maxJ, sb, 0, a.length - 1, id10);
            }
        }

        public static <T> void id12(T[][] a, Integer maxJ, StringBuilder sb, int start, int end, int[][] id10) {
            if (id10 == null) {
                id12(a, maxJ, sb, start, end, (int[]) null);
                return;
            }

            end = Math.min(a.length - 1, end);

            for (int i = start; i <= end; i++) {
                id12(a[i], maxJ, sb, id10[i]);
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

        public static void assertTrue(boolean id6, String message) {
            if (!id6)
                throw new RuntimeException(message);
        }

        private static class Segment {
            long val;
            int level;

            public Segment() {
            }

            public Segment(long val, int level) {
                this.val = val;
                this.level = level;
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

        private static class id18 {
            int n;
            boolean id4;
            id5.Segment[] segmentTree;
            id5.Input[] lazy;
            int depth;

            public id5.Segment id9(int tindex, id5.Input val) {
                return new id5.Segment(val.val, depth);
            }

            public id5.Segment id15(id5.Segment left, id5.Segment right) {
                if (left.level % 2 == depth % 2) {
                    return new id5.Segment(left.val | right.val, left.level - 1);
                } else {
                    return new id5.Segment(left.val ^ right.val, left.level - 1);
                }
            }

            private void incLazy(int level, int tindex, id5.Input lazyRes, id5.Input inc) {
                

            }

            private id5.Segment incSegment(id5.Segment res, id5.Input incLazy) {
                return new id5.Segment(res.val + incLazy.val, 0);
            }

            private void resetLazy(id5.Input input) {
                input.val = 0;
            }

            public id18(id5.Input[] a, id5.Input[] lazy, boolean id4) {
                this.n = a.length;
                this.id4 = id4;
                segmentTree = new id5.Segment[2 * n];
                this.depth = id0(n);

                for (int i = 0; i < n; i++) {
                    segmentTree[n + i] = id9(i, a[i]);
                }

                if (id4 && lazy == null) {
                    lazy = new id5.Input[n];
                    for (int i = 0; i < n; i++) {
                        lazy[i] = new id5.Input();
                    }
                }
                this.lazy = lazy;
                build();
            }

            public id18(id5.Input[] a, boolean id4) {
                this(a, null, id4);
            }

            private void build() {
                for (int i = n - 1; i > 0; i--) {
                    updateSegment(i);
                }
            }

            void updateSegment(int pos) {
                id5.Segment s1, s2;
                s1 = getSegment(pos << 1);
                s2 = getSegment(pos << 1 | 1);
                segmentTree[pos] = id15(s1, s2);
            }

            private id5.Segment getSegment(int pos) {
                id5.Segment segment = segmentTree[pos];
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

            void updateMe(int tindex, id5.Input value) {
                assertTrue(tindex >= 0 && tindex < n, "tindex (" + tindex + ") is not in range [0, " + n + "]");
                segmentTree[tindex + n] = id9(tindex, value);
                pushUp(tindex);
            }

            id5.Segment getMe(int start0, int end0) {
                assertTrue(start0 <= end0 && start0 >= 0 && end0 < n, "start0 (" + start0 + ") or end0 (" + end0 + ") is not in range [0, " + n + "]");
                int start = start0 + n;
                int end = end0 + n;

                if (id4) {
                    id17(start);
                    id17(end);
                }

                end++;
                id5.Segment resL = null;
                id5.Segment resR = null;

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

            public void inc(int level, int tindex, id5.Input inc) {
                segmentTree[tindex] = incSegment(segmentTree[tindex], inc);
                if (tindex < n)
                    incLazy(level, tindex, lazy[tindex], inc);
            }

            public String toString() {
                return toForest().toString();
            }

            private id5.Forest toForest() {
                return toForest(1);
            }

            private id5.Forest toForest(int id7) {
                id5.Vertex[] vertices = new id5.Vertex[2 * n];
                int[] start = new int[2 * n];
                int[] end = new int[2 * n];
                for (int i = 1; i < 2 * n; i++) {
                    vertices[i] = new id5.Vertex();
                    vertices[i].label = segmentTree[i].toString();
                }

                if (id7 == 2) {
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

                

                List<id5.Vertex> roots = new ArrayList<>();
                int iPos = n;
                while (iPos < 2 * n) {
                    int generation = 0;
                    int lastGeneration = generation;
                    id5.Vertex lastVertex = vertices[iPos];
                    while (vertices[iPos >> generation] != null) {
                        lastGeneration = generation;
                        lastVertex = vertices[iPos >> generation];
                        generation++;
                    }

                    int id8 = iPos + (1 << lastGeneration);
                    

                    while (lastGeneration + 1 <= depth) {
                        id5.Vertex vertex = new id5.Vertex();
                        vertex.label = "-";
                        lastVertex.father = vertex;
                        vertex.children = new ArrayList<>();
                        vertex.children.add(lastVertex);
                        lastVertex = vertex;
                        lastGeneration++;
                    }
                    roots.add(lastVertex);
                    iPos = id8;
                }

                if (id7 == 1) {
                    for (int i = n; i < 2 * n; i++) {
                        vertices[i].children = new ArrayList<>();
                        id5.Vertex vertex = new id5.Vertex();
                        vertex.label = "[" + (i - n) + "]";
                        vertices[i].children.add(vertex);
                    }
                }
                return new id5.Forest(roots);
            }

        }

        private static class Forest {
            List<id5.Vertex> roots;

            public Forest(List<id5.Vertex> roots) {
                this.roots = roots;
            }

            public String toString() {
                for (id5.Vertex root : roots) {
                    root.id2();
                }

                List<List<id5.Vertex>> vertices = new ArrayList<>();
                List<id5.Vertex> currentRoots = roots;
                vertices.add(currentRoots);
                while (!currentRoots.isEmpty()) {
                    List<id5.Vertex> id11 = new ArrayList<>();
                    for (id5.Vertex root : currentRoots) {
                        if (root.children != null)
                            id11.addAll(root.children);
                    }
                    currentRoots = id11;
                    if (currentRoots.isEmpty())
                        break;
                    vertices.add(currentRoots);
                }

                String[][] cells = new String[vertices.size()][];
                int[][] id14 = new int[vertices.size()][];
                for (int i = 0; i < vertices.size(); i++) {
                    List<id5.Vertex> vertexList = vertices.get(i);
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
            id5.Vertex father;
            List<id5.Vertex> children;
            public Integer id14;

            public String toString() {
                return label;
            }

            private void id2() {
                id2(this);
            }

            private void id2(id5.Vertex vertex) {
                int ans = 0;
                int cellLength = id16(vertex);
                if (vertex.children != null) {
                    for (id5.Vertex next : vertex.children) {
                        id2(next);
                        ans += next.id14;
                    }
                    ans += vertex.children.size() - 1;

                    if (cellLength > ans) {
                        id5.Vertex lastChild = vertex.children.get(children.size() - 1);
                        lastChild.id14 += cellLength - ans;
                    }
                }
                vertex.id14 = Math.max(cellLength, ans);
            }

            private int id16(id5.Vertex vertex) {
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

