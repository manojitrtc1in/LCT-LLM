import java.io.BufferedInputStream;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.NoSuchElementException;


public class Main implements Runnable{
    public static void main(String[] args) {
        new Thread(null, new Main(), "", 1<<28).start();
    }

    public void run() {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        JoltyScanner in = new JoltyScanner(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int n;
        int[][] g;
        int[][] gr;
        int[] order;
        int orderSize;
        boolean[] visited;
        int[] gToComp;
        long[] compCost;
        long[] dp;
        int m;
        int[] eFrom;
        int[] eTo;
        int[] eWeight;
        long[] eTotalWeight;

        public void solve(int testNumber, JoltyScanner in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            int[] inDegree = new int[n];
            int[] outDegree = new int[n];
            eFrom = new int[m];
            eTo = new int[m];
            eWeight = new int[m];
            eTotalWeight = new long[m];
            for (int e = 0; e < m; e++) {
                int from = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                int weight = in.nextInt();
                eFrom[e] = from;
                eTo[e] = to;
                eWeight[e] = weight;
                outDegree[from]++;
                inDegree[to]++;
            }
            prepareCosts();

            g = new int[n][];
            gr = new int[n][];
            for (int i = 0; i < n; i++) {
                g[i] = new int[outDegree[i]];
                gr[i] = new int[inDegree[i]];
            }
            for (int e = 0; e < m; e++) {
                g[eFrom[e]][--outDegree[eFrom[e]]] = e;
                gr[eTo[e]][--inDegree[eTo[e]]] = e;
            }

            int s = in.nextInt() - 1;

            buildNewGraph();
            dp = new long[n];
            Arrays.fill(dp, -1);
            long res = go(gToComp[s]);
            out.print(res);
        }

        void dfs1(int v) {
            visited[v] = true;
            for (int e : g[v]) {
                if (!visited[eTo[e]]) {
                    dfs1(eTo[e]);
                }
            }
            order[orderSize++] = v;
        }

        void dfs2(int v, int c) {
            visited[v] = true;
            gToComp[v] = c;
            for (int e : gr[v]) {
                if (!visited[eFrom[e]]) {
                    dfs2(eFrom[e], c);
                }
            }
        }

        void buildNewGraph() {
            order = new int[n];
            orderSize = 0;
            visited = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    dfs1(i);
                }
            }

            Arrays.fill(visited, false);
            gToComp = new int[n];
            int compCount = 0;
            for (int i = 0; i < n; i++) {
                int v = order[n - 1 - i];
                if (!visited[v]) {
                    dfs2(v, compCount++);
                }
            }

            compCost = new long[compCount];
            int[] degree = new int[compCount];
            for (int e = 0; e < m; e++) {
                int fromComp = gToComp[eFrom[e]];
                int toComp = gToComp[eTo[e]];
                if (fromComp == toComp) {
                    compCost[fromComp] += eTotalWeight[e];
                } else {
                    degree[fromComp]++;
                }
            }

            int[][] newG = new int[compCount][];
            for (int i = 0; i < compCount; i++) {
                newG[i] = new int[degree[i]];
            }
            for (int e = 0; e < m; e++) {
                int fromComp = gToComp[eFrom[e]];
                int toComp = gToComp[eTo[e]];
                eFrom[e] = fromComp;
                eTo[e] = toComp;
                if (fromComp != toComp) {
                    newG[fromComp][--degree[fromComp]] = e;
                }
            }

            n = compCount;
            g = newG;
        }

        long go(int v) {
            if (dp[v] != -1) {
                return dp[v];
            }
            dp[v] = compCost[v];
            for (int e : g[v]) {
                dp[v] = Math.max(dp[v], compCost[v] + eWeight[e] + go(eTo[e]));
            }
            return dp[v];
        }

        void prepareCosts() {
            int[] order = Range.range(m).sort((x, y) -> Integer.compare(eWeight[x], eWeight[y])).toArray();
            long sum = 0;
            for (int i = 0, l = 0; i < m; i++) {
                int e = order[i];
                while ((l + 1L) * (l + 2L) / 2 <= eWeight[e]) {
                    l++;
                    sum += l * (l + 1L) / 2;
                }
                eTotalWeight[e] = (l + 1L) * eWeight[e] - sum;
            }
        }

    }

    static abstract class IntAbstractStream implements IntStream {

        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                if (first) {
                    first = false;
                } else {
                    builder.append(' ');
                }
                builder.append(it.value());
            }
            return builder.toString();
        }


        public boolean equals(Object o) {
            if (!(o instanceof IntStream)) {
                return false;
            }
            IntStream c = (IntStream) o;
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                if (it.value() != jt.value()) {
                    return false;
                }
                it.advance();
                jt.advance();
            }
            return !it.isValid() && !jt.isValid();
        }


        public int hashCode() {
            int result = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
        }

    }

    static interface IntComparator {
        public int compare(int first, int second);

    }

    static class IntArray extends IntAbstractStream implements IntList {
        private int[] data;

        public IntArray(int[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public int get(int at) {
            return data[at];
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

        public void set(int index, int value) {
            data[index] = value;
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface IntReversableCollection extends IntCollection {
    }

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        public IntIterator intIterator();

        default public Iterator<Integer> iterator() {
            return new Iterator<Integer>() {
                private IntIterator it = intIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Integer next() {
                    int result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(IntStream c) {
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                int i = it.value();
                int j = jt.value();
                if (i < j) {
                    return -1;
                } else if (i > j) {
                    return 1;
                }
                it.advance();
                jt.advance();
            }
            if (it.isValid()) {
                return 1;
            }
            if (jt.isValid()) {
                return -1;
            }
            return 0;
        }

    }

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void set(int index, int value);

        public abstract void removeAt(int index);

        default public void swap(int first, int second) {
            if (first == second) {
                return;
            }
            int temp = get(first);
            set(first, get(second));
            set(second, temp);
        }

        default public IntIterator intIterator() {
            return new IntIterator() {
                private int at;
                private boolean removed;

                public int value() {
                    if (removed) {
                        throw new IllegalStateException();
                    }
                    return get(at);
                }

                public boolean advance() {
                    at++;
                    removed = false;
                    return isValid();
                }

                public boolean isValid() {
                    return !removed && at < size();
                }

                public void remove() {
                    removeAt(at);
                    at--;
                    removed = true;
                }
            };
        }

        default public IntList sort(IntComparator comparator) {
            Sorter.sort(this, comparator);
            return this;
        }

    }

    static interface IntCollection extends IntStream {
        public int size();

        default public int[] toArray() {
            int size = size();
            int[] array = new int[size];
            int i = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                array[i++] = it.value();
            }
            return array;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void print(long i) {
            writer.print(i);
        }

    }

	static class JoltyScanner 
	{
		public static final int BUFFER_SIZE = 1 << 16;
		public static final char NULL_CHAR = (char) -1;
		byte[] buffer = new byte[BUFFER_SIZE];
		boolean EOF_FLAG = false;
		int bufferIdx = 0, size = 0;
		char c = NULL_CHAR;
		BufferedInputStream in;
		public JoltyScanner(InputStream in) 
		{
			this.in = new BufferedInputStream(in, BUFFER_SIZE);
		}
		public int nextInt() 
		{
			long x = nextLong();
			if (x > Integer.MAX_VALUE || x < Integer.MIN_VALUE) 
			{
				throw new ArithmeticException("Scanned value overflows integer");
			}
			return (int) x;
		}
		public long nextLong() 
		{
			boolean negative = false;
			if (c == NULL_CHAR) 
			{
				c = nextChar();
			}
			for (; !EOF_FLAG && (c < '0' || c > '9'); c = nextChar()) 
			{
				if (c == '-') 
				{
					negative = true;
				}				
			}
			checkEOF();
			long res = 0;
			for (; c >= '0' && c <= '9'; c = nextChar()) 
			{
				res = (res << 3) + (res << 1) + c - '0';
			}
			return negative ? -res : res;
		}
		public char nextChar() 
		{
			if (EOF_FLAG) 
			{
				return NULL_CHAR;
			}
			while (bufferIdx == size) 
			{
				try 
				{
					size = in.read(buffer);
					if (size == -1) 
					{
						throw new Exception();
					}
				} 
				catch (Exception e) 
				{
					EOF_FLAG = true;
					return NULL_CHAR;
				}
				if (size == -1) 
				{
					size = BUFFER_SIZE;
				}
				bufferIdx = 0;
			}
			return (char) buffer[bufferIdx++];
		}
		public void checkEOF() 
		{
			if (EOF_FLAG) 
			{
				throw new EndOfFileException();
			}
		}
		public class EndOfFileException extends RuntimeException 
		{
		}
	}

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
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

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class Sorter {
        private static final int INSERTION_THRESHOLD = 16;

        private Sorter() {
        }

        public static void sort(IntList list, IntComparator comparator) {
            quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                    comparator);
        }

        private static void quickSort(IntList list, int from, int to, int remaining, IntComparator comparator) {
            if (to - from < INSERTION_THRESHOLD) {
                insertionSort(list, from, to, comparator);
                return;
            }
            if (remaining == 0) {
                heapSort(list, from, to, comparator);
                return;
            }
            remaining--;
            int pivotIndex = (from + to) >> 1;
            int pivot = list.get(pivotIndex);
            list.swap(pivotIndex, to);
            int storeIndex = from;
            int equalIndex = to;
            for (int i = from; i < equalIndex; i++) {
                int value = comparator.compare(list.get(i), pivot);
                if (value < 0) {
                    list.swap(storeIndex++, i);
                } else if (value == 0) {
                    list.swap(--equalIndex, i--);
                }
            }
            quickSort(list, from, storeIndex - 1, remaining, comparator);
            for (int i = equalIndex; i <= to; i++) {
                list.swap(storeIndex++, i);
            }
            quickSort(list, storeIndex, to, remaining, comparator);
        }

        private static void heapSort(IntList list, int from, int to, IntComparator comparator) {
            for (int i = (to + from - 1) >> 1; i >= from; i--) {
                siftDown(list, i, to, comparator, from);
            }
            for (int i = to; i > from; i--) {
                list.swap(from, i);
                siftDown(list, from, i - 1, comparator, from);
            }
        }

        private static void siftDown(IntList list, int start, int end, IntComparator comparator, int delta) {
            int value = list.get(start);
            while (true) {
                int child = ((start - delta) << 1) + 1 + delta;
                if (child > end) {
                    return;
                }
                int childValue = list.get(child);
                if (child + 1 <= end) {
                    int otherValue = list.get(child + 1);
                    if (comparator.compare(otherValue, childValue) > 0) {
                        child++;
                        childValue = otherValue;
                    }
                }
                if (comparator.compare(value, childValue) >= 0) {
                    return;
                }
                list.swap(start, child);
                start = child;
            }
        }

        private static void insertionSort(IntList list, int from, int to, IntComparator comparator) {
            for (int i = from + 1; i <= to; i++) {
                int value = list.get(i);
                for (int j = i - 1; j >= from; j--) {
                    if (comparator.compare(list.get(j), value) <= 0) {
                        break;
                    }
                    list.swap(j, j + 1);
                }
            }
        }

    }

    static class Range {
        public static IntList range(int from, int to) {
            int[] result = new int[Math.abs(from - to)];
            int current = from;
            if (from <= to) {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current++;
                }
            } else {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current--;
                }
            }
            return new IntArray(result);
        }

        public static IntList range(int n) {
            return range(0, n);
        }

    }
}