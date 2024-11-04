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
        CCircularRMQ solver = new CCircularRMQ();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCircularRMQ {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();
            CCircularRMQ.Input[] a = new CCircularRMQ.Input[n];
            for (int i = 0; i < n; i++) {
                a[i] = new CCircularRMQ.Input(in.nextInt());
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

        private ArrayList<Long> solveMe(CCircularRMQ.Input[] a, String[] queries) {
            int n = a.length;
            CCircularRMQ.SegmentTreeLevel st = new CCircularRMQ.SegmentTreeLevel(a, true);
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
                        st.updateRangeLazy(left, right, new CCircularRMQ.Input(val));
                    } else {
                        st.updateRangeLazy(0, right, new CCircularRMQ.Input(val));
                        st.updateRangeLazy(left, n - 1, new CCircularRMQ.Input(val));
                    }
                }
            }
            return res;
        }

        private static int nextBaseOf2(long n) {
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

        public static <T> String stringMeDeb(T[][] a) {
            return stringMeDeb(a, null, null);
        }

        public static <T> String stringMeDeb(T[][] a, Integer maxI, Integer maxJ) {
            StringBuilder sb = new StringBuilder();
            sb.append("\n");
            stringMeDebAppend(a, maxI, maxJ, sb, (int[]) null);
            return sb.toString();
        }

        public static <T> void stringMeDebAppend(T[][] a, Integer maxI, Integer maxJ, StringBuilder sb, int[] minLength) {
            if (maxI == null)
                maxI = 100;
            int firstPart = maxI * 9 / 10;
            if (a.length > maxI) {
                stringMeDebAppend(a, maxJ, sb, 0, firstPart, minLength);
                sb.append("...\n");
                stringMeDebAppend(a, maxJ, sb, a.length - maxI + firstPart, a.length - 1, minLength);
            } else {
                stringMeDebAppend(a, maxJ, sb, 0, a.length - 1, minLength);
            }
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

        public static <T> String[][] joinLastArray(T[][][] a) {
            String[][] b = new String[a.length][];
            for (int i = 0; i < a.length; i++) {
                b[i] = new String[a[i].length];
                for (int j = 0; j < a[i].length; j++) {
                    b[i][j] = stringMe(a[i][j]);
                }
            }
            return b;
        }

        public static <T> T[][][] arrayMoveFirstToLastArray(T[][][] a) {
            Class<?> componentType = a.getClass().getComponentType();
            Class<?> componentType2 = a[0].getClass().getComponentType();
            Class<?> componentType3 = a[0][0].getClass().getComponentType();

            for (int i = 1; i < a.length; i++) {
                assertEquals(a[0].length, a[i].length, "Array must be of same size for i = " + i);
                for (int j = 1; j < a.length; j++) {
                    assertEquals(a[0][j].length, a[i][j].length, "Sub-Array must be of same size for i = " + i + " and j = " + j);
                }
            }

            T[][][] b = (T[][][]) Array.newInstance(componentType, a[0].length);
            for (int i = 0; i < a[0].length; i++) {
                b[i] = (T[][]) Array.newInstance(componentType2, a[0][i].length);
                for (int j = 0; j < a[0][i].length; j++) {
                    b[i][j] = (T[]) Array.newInstance(componentType3, a.length);
                    for (int k = 0; k < a.length; k++) {
                        b[i][j][k] = a[k][i][j];
                    }
                }
            }
            return b;
        }

        public static <T> String[][] moveFirstToLastAndJoinLastArray(Object[][]... a) {
            return joinLastArray(arrayMoveFirstToLastArray(toArrayObject(a)));
        }

        public static <T> Object[] toArrayObject(T[] a) {
            Object[] res = new Object[a.length];
            for (int i = 0; i < a.length; i++)
                res[i] = a[i];
            return res;
        }

        public static <T> Object[][] toArrayObject(T[][] a) {
            Object[][] res = new Object[a.length][];
            for (int i = 0; i < a.length; i++)
                res[i] = toArrayObject(a[i]);
            return res;
        }

        public static <T> Object[][][] toArrayObject(T[][][] a) {
            Object[][][] res = new Object[a.length][][];
            for (int i = 0; i < a.length; i++)
                res[i] = toArrayObject(a[i]);
            return res;
        }

        public static void assertTrue(boolean shouldBeTrue, String message) {
            if (!shouldBeTrue)
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

            public Segment(CCircularRMQ.Segment segment) {
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

        private static class SegmentTreeLevel {
            int n;
            boolean isWithLazy;
            CCircularRMQ.Segment[][] segmentTree;
            CCircularRMQ.Input[][] lazy;
            int depth;

            public CCircularRMQ.Segment getLeafSegment(CCircularRMQ.Segment inout, CCircularRMQ.Input val) {
                inout.val = val.val;
                return inout;
            }

            public CCircularRMQ.Segment combineInternalLoop(CCircularRMQ.Segment inout, CCircularRMQ.Segment left, CCircularRMQ.Segment right) {
                if (left == null && right == null)
                    return null;
                if (inout == null) {
                    inout = new CCircularRMQ.Segment();
                }
                inout.val = Math.min(left == null ? Long.MAX_VALUE : left.val, right == null ? Long.MAX_VALUE : right.val);
                return inout;
            }

            private CCircularRMQ.Input incLazy(CCircularRMQ.Input inout, CCircularRMQ.Input incLazy) {
                if (inout == null)
                    return null;
                inout.val += incLazy.val;
                return inout;
            }

            private CCircularRMQ.Segment incSegment(CCircularRMQ.Segment inout, CCircularRMQ.Input incLazy) {
                if (inout == null)
                    return null;
                inout.val += incLazy.val;
                return inout;
            }

            private CCircularRMQ.Input resetLazy(CCircularRMQ.Input inout) {
                if (inout == null)
                    return null;
                inout.val = 0;
                return inout;
            }

            public SegmentTreeLevel(CCircularRMQ.Input[] a, boolean isWithLazy) {
                this(a, null, isWithLazy);
            }

            public SegmentTreeLevel(CCircularRMQ.Input[] a, CCircularRMQ.Input[][] lazy, boolean isWithLazy) {
                this.n = a.length;
                this.isWithLazy = isWithLazy;
                depth = nextBaseOf2(n);
                segmentTree = new CCircularRMQ.Segment[depth + 1][];
                for (int i = 0; i <= depth; i++) {
                    segmentTree[i] = new CCircularRMQ.Segment[1 << i];
                    for (int j = 0; j < 1 << i && j * (1 << (depth - i)) < n; j++)
                        segmentTree[i][j] = new CCircularRMQ.Segment();
                }

                for (int i = 0; i < n; i++) {
                    segmentTree[depth][i] = getLeafSegment(segmentTree[depth][i], a[i]);
                }

                if (isWithLazy && lazy == null) {
                    lazy = new CCircularRMQ.Input[depth + 1][];
                    for (int i = 0; i <= depth; i++) {
                        lazy[i] = new CCircularRMQ.Input[1 << i];
                        for (int j = 0; j < 1 << i && j * (1 << (depth - i)) < n; j++)
                            lazy[i][j] = new CCircularRMQ.Input();
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

            CCircularRMQ.Segment getMe(int start, int end) {
                if (isWithLazy) {
                    pushDownLazy(start);
                    pushDownLazy(end);
                }

                CCircularRMQ.Segment resL = null;
                CCircularRMQ.Segment resR = null;
                int level = depth;
                end++;
                while (start < end) {
                    if (start % 2 == 1) {
                        

                        if (resL == null)
                            resL = new CCircularRMQ.Segment(segmentTree[level][start]);
                        else
                            resL = combineInternalLoop(resL, resL, segmentTree[level][start]);
                        start++;
                    }
                    if (end % 2 == 1) {
                        end--;
                        

                        if (resR == null)
                            resR = new CCircularRMQ.Segment(segmentTree[level][end]);
                        else
                            resR = combineInternalLoop(resR, segmentTree[level][end], resR);
                    }

                    level--;
                    start /= 2;
                    end /= 2;
                }

                

                if (resL == null)
                    return resR;
                if (resR == null)
                    return resL;
                return combineInternalLoop(resL, resL, resR);
            }

            public void updateRangeLazy(int start0, int end0, CCircularRMQ.Input inc) {
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

            private void pushDownLazy(int tindex) {
                for (int level = 0; level < depth; level++) {
                    int indexFather = tindex >> (depth - level);
                    inc(level + 1, indexFather * 2, lazy[level][indexFather]);
                    inc(level + 1, indexFather * 2 + 1, lazy[level][indexFather]);
                    segmentTree[level][indexFather] = combineInternalLoop(segmentTree[level][indexFather], segmentTree[level + 1][indexFather * 2], segmentTree[level + 1][indexFather * 2 + 1]);
                    lazy[level][indexFather] = resetLazy(lazy[level][indexFather]);
                }
            }

            void updateSegment(int level, int index) {
                CCircularRMQ.Segment s1, s2;
                s1 = getSegment(level + 1, 2 * index);
                s2 = getSegment(level + 1, 2 * index + 1);
                segmentTree[level][index] = combineInternalLoop(segmentTree[level][index], s1, s2);
            }

            private CCircularRMQ.Segment getSegment(int level, int tindex) {
                if (segmentTree[level][tindex] == null)
                    return null;
                CCircularRMQ.Segment segment = new CCircularRMQ.Segment(segmentTree[level][tindex]);
                if (isWithLazy) {
                    segment = incSegment(segment, lazy[level - 1][tindex / 2]);
                }
                return segment;
            }

            public void inc(int level, int tindex, CCircularRMQ.Input incLazy) {
                segmentTree[level][tindex] = incSegment(segmentTree[level][tindex], incLazy);
                lazy[level][tindex] = incLazy(lazy[level][tindex], incLazy);
            }

            public String toString() {
                if (isWithLazy) {
                    return stringMeDeb(moveFirstToLastAndJoinLastArray(segmentTree, lazy));
                } else {
                    return stringMeDeb(segmentTree);
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

