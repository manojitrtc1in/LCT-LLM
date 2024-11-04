import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;




public class E implements Runnable{
	
	final boolean id7 = System.getProperty("id7") != null;
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new E(), "", 128 * (1L << 20)).start();
	}
	
	

	
	void init() throws FileNotFoundException{
		Locale.setDefault(Locale.US);
		
		if (id7){
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new OutputWriter(System.out);
		}else{
			in = new BufferedReader(new FileReader("input.txt"));
			out = new OutputWriter("output.txt");
		}
	}
	
	

	
	long timeBegin, timeEnd;

	void time(){
		timeEnd = System.currentTimeMillis();
		System.err.println("Time = " + (timeEnd - timeBegin));
	}
	
	void debug(Object... objects){
		if (id7){
			for (Object o: objects){
				System.err.println(o.toString());
			}
		}
	}
	
	

	
	public void run(){
		try{
			timeBegin = System.currentTimeMillis();
			Locale.setDefault(Locale.US);
			
			init();
			solve();
			
			out.close();
			time();
		}catch (Exception e){
			e.printStackTrace(System.err);
			System.exit(-1);
		}
	}
	
	

	
	String delim = " ";
	
	String readString() throws IOException{
		while(!tok.hasMoreTokens()){
			try{
				tok = new StringTokenizer(in.readLine());
			}catch (Exception e){
				return null;
			}
		}
		
		return tok.nextToken(delim);
	}
	
	String readLine() throws IOException{
		return in.readLine();
	}
	
	

	
	final char id5 = '\0';
	
	char readChar() throws IOException{
		int intValue = in.read();
		
		if (intValue == -1){
			return id5;
		}
		
		return (char) intValue;
	}
	
	char[] id6() throws IOException{
		return readLine().toCharArray();
	}
	
	

	
	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}
	
	int[] id1(int size) throws IOException {
		int[] array = new int[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readInt();
		}
		
		return array;
	}
	
	int[] id8(int size) throws IOException {
		Integer[] array = new Integer[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = readInt();
		}
		Arrays.sort(array);
		
		int[] sortedArray = new int[size];
		for (int index = 0; index < size; ++index) {
			sortedArray[index] = array[index];
		}
		
		return sortedArray;
	}
	
	int[] id9(int size) throws IOException {
		int[] array = id1(size);
		
		for (int i = 0; i < size; ++i) {
			array[i]--;
		}
		
		return array;
	}
	
	

	
	int[][] id13(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id1(columnsCount);
		}
		
		return matrix;
	}
	
	int[][] id19(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id9(columnsCount);
		}
		
		return matrix;
	}
	
	

	
	long readLong() throws IOException{
		return Long.parseLong(readString());
	}
	
	long[] id10(int size) throws IOException{
		long[] array = new long[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readLong();
		}
		
		return array;
	}
	
	

	
	double readDouble() throws IOException{
		return Double.parseDouble(readString());
	}
	
	double[] id3(int size) throws IOException{
		double[] array = new double[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readDouble();
		}
		
		return array;
	}
	
	

		
	BigInteger id16() throws IOException {
		return new BigInteger(readString());
	}
	
	BigDecimal id15() throws IOException {
		return new BigDecimal(readString());
	}
	
	

	
	Point readPoint() throws IOException{
		int x = readInt();
		int y = readInt();
		return new Point(x, y);
	}
	
	Point[] id21(int size) throws IOException{
		Point[] array = new Point[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readPoint();
		}
		
		return array;
	}
	
	

	
	List<Integer>[] readGraph(int vertexNumber, int edgeNumber)
	throws IOException{
		@SuppressWarnings("unchecked")
		List<Integer>[] graph = new List[vertexNumber];
		
		for (int index = 0; index < vertexNumber; ++index){
			graph[index] = new ArrayList<Integer>();
		}
		
		while (edgeNumber-- > 0){
			int from = readInt() - 1;
			int to = readInt() - 1;
			
			graph[from].add(to);
			graph[to].add(from);
		}
		
		return graph;
	}
	
	

	
	static class id18 {
		
		static Comparator<id18> increaseComparator = new Comparator<E.id18>() {
			
			@Override
			public int compare(id18 id14, id18 id11) {
				int value1 = id14.value;
				int value2 = id11.value;
				
				if (value1 != value2) return value1 - value2;
				
				int index1 = id14.index;
				int index2 = id11.index;
				
				return index1 - index2;
			}
		};
		
		static Comparator<id18> id0 = new Comparator<E.id18>() {
			
			@Override
			public int compare(id18 id14, id18 id11) {
				int value1 = id14.value;
				int value2 = id11.value;
				
				if (value1 != value2) return -(value1 - value2);
				
				int index1 = id14.index;
				int index2 = id11.index;
				
				return index1 - index2;
			}
		};
		
		int value, index;

		public id18(int value, int index) {
			super();
			this.value = value;
			this.index = index;
		}		
		
		public int id4() {
			return index + 1;
		}
	}
	
	id18[] id2(int size) throws IOException {
		id18[] array = new id18[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = new id18(readInt(), index);
		}
		
		return array;
	}
	
	

	
	static class OutputWriter extends PrintWriter {

		final int id23 = 12;
		
		protected int precision;
		protected String format, id22;
		
		{
			precision = id23;
			
			format = createFormat(precision);
			id22 = format + " ";
		}
		
		public OutputWriter(OutputStream out) {
			super(out);
		}

		public OutputWriter(String fileName) throws FileNotFoundException {
			super(fileName);
		}
		
		public int getPrecision() {
			return precision;
		}

		public void setPrecision(int precision) {
			precision = max(0, precision);
			this.precision = precision;
			
			format = createFormat(precision);
			id22 = format + " ";
		}
		
		private String createFormat(int precision){
			return "%." + precision + "f";
		}
		
		@Override
		public void print(double d){
			printf(format, d);
		}
		
		public void id20(double d){
			printf(id22, d);
		}

		public void printAll(double...d){
			for (int i = 0; i < d.length - 1; ++i){
				id20(d[i]);
			}
			
			print(d[d.length - 1]);
		}
		
		@Override
		public void println(double d){
			printlnAll(d);
		}
		
		public void printlnAll(double... d){
			printAll(d);
			println();
		}
	}
	
	

	
	static final int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
	static final int[][] steps8 = {
			{-1, 0}, {1, 0}, {0, -1}, {0, 1},
			{-1, -1}, {1, 1}, {1, -1}, {-1, 1}
	};
	
	static final boolean check(int index, int lim){
		return (0 <= index && index < lim);
	}
	
	

	
	static final boolean checkBit(int mask, int bit){
		return (mask & (1 << bit)) != 0;
	}
	
	

	
	static final long getSum(int[] array) {
		long sum = 0;
		for (int value: array) {
			sum += value;
		}
		
		return sum;
	}
	
	static final Point id12(int[] array) {
		int min = array[0];
		int max = array[0];
		
		for (int index = 0, size = array.length; index < size; ++index, ++index) {
			int value = array[index];
			
			if (index == size - 1) {
				min = min(min, value);
				max = max(max, value);
			} else {
				int otherValue = array[index + 1];
				
				if (value <= otherValue) {
					min = min(min, value);
					max = max(max, otherValue);
				} else {
					min = min(min, otherValue);
					max = max(max, value);
				}
			}
		}
		
		return new Point(min, max);
	}
	
	

	
	class Triple {
		int value;
		int index;
		


		
		public Triple(int value, int index, int left, int right) {
			super();
			this.value = value;
			this.index = index;






		}
	}
	
	
	class SegmentTree {
		int[][] values;
		int[][] indexes;




		
		int size;
		
		public SegmentTree(int[] array) {
			size = array.length;
			
			values = new int[size << 2][];
			indexes = new int[size << 2][];
			

			

			
			build(1, 0, size - 1, array);
		}
		
		void build(int v, int left, int right, int[] array) {
			if (left == right) {
				values[v] = new int[1];
				values[v][0] = array[left];
				
				indexes[v] = new int[1];
				indexes[v][0] = left;
				










			} else {
				int vLeft = (v << 1);
				int vRight = (vLeft + 1);
				
				int mid = ((left + right) >> 1);
				
				build(vLeft, left, mid, array);
				build(vRight, mid + 1, right, array);
				
				merge(v, vLeft, vRight);
			}
		}
		
		final int INF = 1000 * 1000;
		void merge(int v, int vLeft, int vRight) {
			int leftSize = values[vLeft].length;
			int rightSize = values[vRight].length;
			
			

			
			values[v] = new int[leftSize + rightSize];
			indexes[v] = new int[leftSize + rightSize];




			
			for (int i = 0, j = 0, k = 0; i < values[v].length; ++i) {
				int leftValue = (j == leftSize? INF: values[vLeft][j]);
				int rightValue = (k == rightSize? INF: values[vRight][k]);
				
				if (leftValue <= rightValue) {
					values[v][i] = leftValue;
					indexes[v][i] = indexes[vLeft][j];




					
					++j;
				} else {
					values[v][i] = rightValue;
					indexes[v][i] = indexes[vRight][k];





					++k;
				}
			}
		}
		
		Triple getMin(int left, int right, int limit) {
			if (left > right) {
				return null;
			}
			
			return get(1, 0, size - 1, left, right, limit);
		}
		
		Triple get(int v, int left, int right, int curL, int curR, int limit) {
			if (curR < left || right < curL) return null;
			


			
			if (curL == left && right == curR) {
				int l = 0, r = values[v].length - 1;
				int index = -1;
				
				

				
				while (l <= r) {
					int mid = ((l + r) >> 1);
					
					int cur = values[v][mid];
					
					if (cur < limit) {
						l = mid + 1;
					} else {
						index = mid;
						r = mid - 1;
					}
				}
				
				if (index == -1) {
					return null;
				} else {
					return new Triple(values[v][index], indexes[v][index], -1, -1);
				}
			} else {
				int vLeft = (v << 1);
				int vRight = (vLeft + 1);
				
				int mid = ((left + right) >> 1);
				




				Triple leftT = get(vLeft, left, mid, curL, min(mid, curR), limit);
				Triple rightT = get(vRight, mid + 1, right, max(curL, mid + 1), curR, limit);
				
				
				if (leftT == null) {
					return rightT;
				} else if (rightT == null) {
					return leftT;
				} else {
					return (leftT.value <= rightT.value? leftT: rightT);
				}
			}
		}
	}
	
	void solve() throws IOException {
		int n = readInt();
		int[] a = id1(n);
		
		Map<Integer, Integer> nextIndexes = new HashMap<Integer, Integer>();
		
		int[] next = new int[n];
		
		int[] nextNext = new int[n+1];
		nextNext[n] = -1;
		for (int i = n - 1; i >= 0; --i) {
			Integer nextIndex = nextIndexes.get(a[i]);
			
			if (nextIndex == null) {
				next[i] = -1;
				nextNext[i] = -1;
			} else {
				next[i] = nextIndex;
				nextNext[i] = next[nextIndex];
			}
			
			nextIndexes.put(a[i], i);
		}
		
		SegmentTree tree = new SegmentTree(next);
		
		int[] dp = new int[n+1];
		Point[] p = new Point[n+1];
		
		dp[n] = 0;
		p[n] = new Point(-1, -1);
		
		for (int i = n - 1; i >= 0; --i) {
			dp[i] = dp[i+1];
			p[i] = p[i+1];
			
			if (next[i] != -1) {
				Triple t = tree.getMin(i + 1, next[i] - 1, next[i] + 1);
				if (t != null) {
					int secondIndex = t.index;
					int id17 = (t.value == -1? n: t.value);
					
					int curDp = 4 + dp[id17 + 1]; 
					if (curDp > dp[i]) {
						dp[i] = curDp;
						p[i] = new Point(i, secondIndex);
					}
				}
				
				int possibleThird = nextNext[i];
				int possibleFourth = nextNext[next[i]];
				if (possibleThird != -1 && possibleFourth != -1) {
					int secondIndex = next[i];
					int id17 = possibleFourth;
					
					int curDp = 4 + dp[id17 + 1]; 
					if (curDp > dp[i]) {
						dp[i] = curDp;
						p[i] = new Point(i, secondIndex);
					}
				}
			}
		}
		
		int length = dp[0];
		out.println(length);
		
		for (int i = 0, size = 0; i < n && size < length; size += 4) {
			int first = p[i].x;
			int second = p[i].y;
			
			out.print(a[first] + " " + a[second] + " " + a[next[first]] + " " + a[next[second]] + " ");
			
			i = next[second] + 1;
		}
	}
}