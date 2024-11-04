import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.lang.reflect.Array;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
            id8.Input[] a = new id8.Input[n];
            for (int i = 0; i < n; i++) {
                a[i] = new id8.Input(in.nextInt());
            }
            int m = in.nextInt();
            String[] queries = new String[m];
            for (int i = 0; i < m; i++) {
                queries[i] = in.nextLine();
            }
            ArrayList<Long> ans = solveMe(a, queries);
            for (Long val : ans) {
                out.println(val);
            }
        }

        private ArrayList<Long> solveMe(id8.Input[] a, String[] queries) {
            int n = a.length;
            id8.id7 st = new id8.id7(a, true);
            int m = queries.length;
            ArrayList<Long> res = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                String[] parts = queries[i].split(" ");
                int left = Integer.parseInt(parts[0]);
                int right = Integer.parseInt(parts[1]);
                if (parts.length == 2) {
                    long ans = left <= right ? st.getMe(left, right).val : Math.min(st.getMe(0, right).val, st.getMe(left, n - 1).val);
                    res.add(ans);
                } else {
                    int val = Integer.parseInt(parts[2]);
                    if (left <= right) {
                        st.id17(left, right, new id8.Input(val));
                    } else {
                        st.id17(0, right, new id8.Input(val));
                        st.id17(left, n - 1, new id8.Input(val));
                    }
                }
            }
            return res;
        }

        private static int id12(long n) {
            return n == 0 ? 0 : 64 - Long.numberOfLeadingZeros(n - 1);
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

        public static <T> String stringMe(T[] a, String separator) {
            int n = a.length;
            StringBuilder res = new StringBuilder();
            for (int i = 0; i < n; i++) {
                if (i > 0)
                    res.append(separator);
                res.append(a[i]);
            }
            return res.toString();
        }

        public static <T> String stringMe(T[] a) {
            return stringMe(a, " ");
        }

        public static <T> String id0(T[][] a) {
            return id0(a, null, null);
        }

        public static <T> String id0(T[][] a, Integer maxI, Integer maxJ) {
            StringBuilder sb = new StringBuilder();
            sb.append("\n");
            id10(a, maxI, maxJ, sb, (int[]) null);
            return sb.toString();
        }

        public static <T> void id10(T[][] a, Integer maxI, Integer maxJ, StringBuilder sb, int[] minLength) {
            if (maxI == null)
                maxI = 100;
            int firstPart = maxI * 9 / 10;
            if (a.length > maxI) {
                id10(a, maxJ, sb, 0, firstPart, minLength);
                sb.append("...\n");
                id10(a, maxJ, sb, a.length - maxI + firstPart, a.length - 1, minLength);
            } else {
                id10(a, maxJ, sb, 0, a.length - 1, minLength);
            }
        }

        public static <T> void id10(T[][] a, Integer maxJ, StringBuilder sb, int start, int end, int[] minLength) {
            end = Math.min(a.length - 1, end);

            if (minLength == null) {
                int id2 = 0;
                for (int i = start; i <= end; i++)
                    id2 = Math.max(id2, a[i].length);
                minLength = new int[id2];

                for (int i = start; i <= end; i++) {
                    for (int j = 0; j < a[i].length; j++) {
                        minLength[j] = Math.max(minLength[j], ("" + a[i][j]).length());
                    }
                }
            }

            int id2 = minLength.length;
            int id11 = ("[" + end + "] ").length();
            repeatSb(sb, " ", id11);
            String[] header = new String[id2];
            for (int i = 0; i < id2; i++) {
                header[i] = "[" + i + "] ";
                minLength[i] = Math.max(minLength[i], header[i].length());
            }

            id10(header, maxJ, sb, minLength);
            sb.append("\n");
            for (int i = start; i <= end; i++) {
                sb.append(rightPad("[" + i + "] ", ' ', id11));
                id10(a[i], maxJ, sb, minLength);
                sb.append("\n");
            }
        }

        public static <T> void id10(T[] a, Integer maxI, StringBuilder sb, int[] minLength) {
            int nbColumns = minLength != null ? minLength.length : a.length;

            if (maxI == null)
                maxI = 100;
            int firstPart = maxI * 9 / 10;
            if (a.length >= maxI) {
                id10(a, sb, 0, firstPart, minLength);
                sb.append(" ... ");
                id10(a, sb, nbColumns - maxI + firstPart, nbColumns - 1, minLength);
            } else {
                id10(a, sb, 0, a.length - 1, minLength);
            }
        }

        public static <T> void id10(T[] a, StringBuilder sb, int start, int end, int[] minLength) {
            end = Math.min(a.length - 1, end);

            sb.append("|");
            for (int i = start; i <= end; i++) {
                if (minLength == null)
                    sb.append(a[i]).append("|");
                else
                    sb.append(rightPad("" + a[i], ' ', minLength[i])).append("|");
                

            }
        }

        public static <T> String[][] id18(T[][][] a) {
            String[][] b = new String[a.length][];
            for (int i = 0; i < a.length; i++) {
                b[i] = new String[a[i].length];
                for (int j = 0; j < a[i].length; j++) {
                    b[i][j] = stringMe(a[i][j]);
                }
            }
            return b;
        }

        public static <T> T[][][] id13(T[][][] a) {
            Class<?> componentType = a.getClass().getComponentType();
            Class<?> id1 = a[0].getClass().getComponentType();
            Class<?> id6 = a[0][0].getClass().getComponentType();

            for (int i = 1; i < a.length; i++) {
                assertEquals(a[0].length, a[i].length, "Array must be of same size for i = " + i);
                for (int j = 1; j < a.length; j++) {
                    assertEquals(a[0][j].length, a[i][j].length, "Sub-Array must be of same size for i = " + i + " and j = " + j);
                }
            }

            T[][][] b = (T[][][]) Array.newInstance(componentType, a[0].length);
            for (int i = 0; i < a[0].length; i++) {
                b[i] = (T[][]) Array.newInstance(id1, a[0][i].length);
                for (int j = 0; j < a[0][i].length; j++) {
                    b[i][j] = (T[]) Array.newInstance(id6, a.length);
                    for (int k = 0; k < a.length; k++) {
                        b[i][j][k] = a[k][i][j];
                    }
                }
            }
            return b;
        }

        public static <T> String[][] id15(Object[][]... a) {
            return id18(id13(id4(a)));
        }

        public static <T> Object[] id4(T[] a) {
            Object[] res = new Object[a.length];
            for (int i = 0; i < a.length; i++)
                res[i] = a[i];
            return res;
        }

        public static <T> Object[][] id4(T[][] a) {
            Object[][] res = new Object[a.length][];
            for (int i = 0; i < a.length; i++)
                res[i] = id4(a[i]);
            return res;
        }

        public static <T> Object[][][] id4(T[][][] a) {
            Object[][][] res = new Object[a.length][][];
            for (int i = 0; i < a.length; i++)
                res[i] = id4(a[i]);
            return res;
        }

        public static void assertTrue(boolean id5, String message) {
            if (!id5)
                throw new RuntimeException(message);
        }

        public static String getExpected(Object expected, Object actual) {
            return "expected = " + expected + "; actual = " + actual + " ; ";
        }

        public static void assertEquals(int val1, int val2, String message) {
            assertTrue(val1 == val2, getExpected(val1, val2) + message);
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

        private static class id7 {
            int n;
            boolean id3;
            id8.Segment[][] segmentTree;
            id8.Input[][] lazy;
            int depth;

            public id8.Segment id9(id8.Segment inout, id8.Input val) {
                inout.val = val.val;
                return inout;
            }

            public id8.Segment id14(id8.Segment inout, id8.Segment left, id8.Segment right) {
                if (left == null && right == null)
                    return null;
                if (inout == null) {
                    inout = new id8.Segment();
                }
                inout.val = Math.min(left == null ? Long.MAX_VALUE : left.val, right == null ? Long.MAX_VALUE : right.val);
                return inout;
            }

            private id8.Input incLazy(id8.Input inout, id8.Input incLazy) {
                if (inout == null)
                    return null;
                inout.val += incLazy.val;
                return inout;
            }

            private id8.Segment incSegment(id8.Segment inout, id8.Input incLazy) {
                if (inout == null)
                    return null;
                inout.val += incLazy.val;
                return inout;
            }

            private id8.Input resetLazy(id8.Input inout) {
                if (inout == null)
                    return null;
                inout.val = 0;
                return inout;
            }

            public id7(id8.Input[] a, boolean id3) {
                this(a, null, id3);
            }

            public id7(id8.Input[] a, id8.Input[][] lazy, boolean id3) {
                this.n = a.length;
                this.id3 = id3;
                depth = id12(n);
                segmentTree = new id8.Segment[depth + 1][];
                for (int i = 0; i <= depth; i++) {
                    segmentTree[i] = new id8.Segment[1 << i];
                    for (int j = 0; j < 1 << i && j * (1 << (depth - i)) < n; j++)
                        segmentTree[i][j] = new id8.Segment();
                }

                for (int i = 0; i < n; i++) {
                    segmentTree[depth][i] = id9(segmentTree[depth][i], a[i]);
                }

                if (id3 && lazy == null) {
                    lazy = new id8.Input[depth + 1][];
                    for (int i = 0; i <= depth; i++) {
                        lazy[i] = new id8.Input[1 << i];
                        for (int j = 0; j < 1 << i && j * (1 << (depth - i)) < n; j++)
                            lazy[i][j] = new id8.Input();
                    }
                }

                this.lazy = lazy;
                build();
            }

            void build() {
                for (int level = depth - 1; level >= 0; level--) {
                    for (int tindex = 0; tindex < 1 << level; tindex++) {
                        updateSegment(level, tindex);
                    }
                }
            }

            id8.Segment getMe(int start, int end) {
                if (id3) {
                    id16(start);
                    id16(end);
                }

                id8.Segment resL = null;
                id8.Segment resR = null;
                int level = depth;
                end++;
                while (start < end) {
                    if (start % 2 == 1) {
                        

                        if (resL == null)
                            resL = new id8.Segment(segmentTree[level][start]);
                        else
                            resL = id14(resL, resL, segmentTree[level][start]);
                        start++;
                    }
                    if (end % 2 == 1) {
                        end--;
                        

                        if (resR == null)
                            resR = new id8.Segment(segmentTree[level][end]);
                        else
                            resR = id14(resR, segmentTree[level][end], resR);
                    }

                    level--;
                    start /= 2;
                    end /= 2;
                }

                

                if (resL == null)
                    return resR;
                if (resR == null)
                    return resL;
                return id14(resL, resL, resR);
            }

            public void id17(int start0, int end0, id8.Input inc) {
                int start = start0, end = end0 + 1;
                int level = depth;

                while (start < end) {
                    if (start % 2 == 1) {
                        inc(level, start, inc);
                        start++;
                    }
                    if (end % 2 == 1) {
                        end--;
                        inc(level, end, inc);
                    }
                    level--;
                    start /= 2;
                    end /= 2;
                }

                

                pushUp(start0);
                pushUp(end0);
            }

            void pushUp(int tindex) {
                pushUp(depth, tindex);
            }

            void pushUp(int level, int tindex) {
                while (level > 0) {
                    --level;
                    tindex /= 2;
                    updateSegment(level, tindex);
                }
            }

            private void id16(int tindex) {
                for (int level = 0; level < depth; level++) {
                    int indexFather = tindex >> (depth - level);
                    inc(level + 1, indexFather * 2, lazy[level][indexFather]);
                    inc(level + 1, indexFather * 2 + 1, lazy[level][indexFather]);
                    segmentTree[level][indexFather] = id14(segmentTree[level][indexFather], segmentTree[level + 1][indexFather * 2], segmentTree[level + 1][indexFather * 2 + 1]);
                    lazy[level][indexFather] = resetLazy(lazy[level][indexFather]);
                }
            }

            void updateSegment(int level, int index) {
                id8.Segment s1, s2;
                s1 = getSegment(level + 1, 2 * index);
                s2 = getSegment(level + 1, 2 * index + 1);
                segmentTree[level][index] = id14(segmentTree[level][index], s1, s2);
            }

            private id8.Segment getSegment(int level, int tindex) {
                if (segmentTree[level][tindex] == null)
                    return null;
                id8.Segment segment = new id8.Segment(segmentTree[level][tindex]);
                if (id3) {
                    segment = incSegment(segment, lazy[level - 1][tindex / 2]);
                }
                return segment;
            }

            public void inc(int level, int tindex, id8.Input incLazy) {
                segmentTree[level][tindex] = incSegment(segmentTree[level][tindex], incLazy);
                lazy[level][tindex] = incLazy(lazy[level][tindex], incLazy);
            }

            public String toString() {
                if (id3) {
                    return id0(id15(segmentTree, lazy));
                } else {
                    return id0(segmentTree);
                }

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

        public String nextLine() {
            String str = "";
            try {
                if (context != null) {
                    System.err.println("[" + context + "] Wait for input ...");
                }
                str = br.readLine();
                if (context != null) {
                    System.err.println("[" + context + "] ... received " + str);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}

