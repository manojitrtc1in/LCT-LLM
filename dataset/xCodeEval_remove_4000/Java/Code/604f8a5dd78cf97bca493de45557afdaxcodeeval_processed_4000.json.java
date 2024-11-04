import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;




public class B implements Runnable{
	
	final boolean id8 = System.getProperty("id8") != null;
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new B(), "", 128 * (1L << 20)).start();
	}
	
	

	
	void init() throws FileNotFoundException{
		Locale.setDefault(Locale.US);
		
		if (id8){
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
		if (!id8){
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
	
	

	
	final char id6 = '\0';
	
	char readChar() throws IOException{
		int intValue = in.read();
		
		if (intValue == -1){
			return id6;
		}
		
		return (char) intValue;
	}
	
	char[] id7() throws IOException{
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
	
	int[] id10(int size) throws IOException {
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
	
	int[] id11(int size) throws IOException {
		int[] array = id1(size);
		
		for (int i = 0; i < size; ++i) {
			array[i]--;
		}
		
		return array;
	}
	
	

	
	int[][] id15(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id1(columnsCount);
		}
		
		return matrix;
	}
	
	int[][] id28(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id11(columnsCount);
		}
		
		return matrix;
	}
	
	

	
	long readLong() throws IOException{
		return Long.parseLong(readString());
	}
	
	long[] id12(int size) throws IOException{
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
	
	

		
	BigInteger id21() throws IOException {
		return new BigInteger(readString());
	}
	
	BigDecimal id20() throws IOException {
		return new BigDecimal(readString());
	}
	
	

	
	Point readPoint() throws IOException{
		int x = readInt();
		int y = readInt();
		return new Point(x, y);
	}
	
	Point[] id31(int size) throws IOException{
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
	
	

	
	static class id27 {
		
		static Comparator<id27> increaseComparator = new Comparator<B.id27>() {
			
			@Override
			public int compare(id27 id18, id27 id13) {
				int value1 = id18.value;
				int value2 = id13.value;
				
				if (value1 != value2) return value1 - value2;
				
				int index1 = id18.index;
				int index2 = id13.index;
				
				return index1 - index2;
			}
		};
		
		static Comparator<id27> id0 = new Comparator<B.id27>() {
			
			@Override
			public int compare(id27 id18, id27 id13) {
				int value1 = id18.value;
				int value2 = id13.value;
				
				if (value1 != value2) return -(value1 - value2);
				
				int index1 = id18.index;
				int index2 = id13.index;
				
				return index1 - index2;
			}
		};
		
		int value, index;

		public id27(int value, int index) {
			super();
			this.value = value;
			this.index = index;
		}		
		
		public int id5() {
			return index + 1;
		}
	}
	
	id27[] id2(int size) throws IOException {
		id27[] array = new id27[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = new id27(readInt(), index);
		}
		
		return array;
	}
	
	

	
	static class OutputWriter extends PrintWriter {

		final int id33 = 12;
		
		protected int precision;
		protected String format, id32;
		
		{
			precision = id33;
			
			format = createFormat(precision);
			id32 = format + " ";
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
			id32 = format + " ";
		}
		
		private String createFormat(int precision){
			return "%." + precision + "f";
		}
		
		@Override
		public void print(double d){
			printf(format, d);
		}
		
		public void id29(double d){
			printf(id32, d);
		}

		public void printAll(double...d){
			for (int i = 0; i < d.length - 1; ++i){
				id29(d[i]);
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
	
	static final Point id14(int[] array) {
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
	
	

	
	class id30 {
		
		int size;
		int[] tree;
		
		id30(int size) {
			this.size = size;
			this.tree = new int[size << 2];
		}
		
		int id22(int index) {
			return get(1, 0, size - 1, 0, index);
		}
		
		int id23(int index) {
			return get(1, 0, size - 1, index, size - 1);
		}
		
		int get(int v, int l, int r, int left, int right) {
			if (right < l || r < left) return 0;
			
			if (l == left && r == right) {
				return tree[v];
			} else {
				int vLeft = (v << 1);
				int vRight = (vLeft + 1);
				
				int m = ((l + r) >> 1);
				
				int leftResult = get(vLeft, l, m, left, min(m, right));
				int rightResult = get(vRight, m + 1, r, max(left, m + 1), right);
				
				return max(leftResult, rightResult);
			}
		}
		
		void set(int index, int value) {
			set(1, 0, size - 1, index, value);
		}
		
		int set(int v, int l, int r, int index, int value) {
			if (l == r) {
				return tree[v] = value;
			} else {
				int vLeft = (v << 1);
				int vRight = (vLeft + 1);
				
				int m = ((l + r) >> 1);
				
				if (index <= m) {
					set(vLeft, l, m, index, value);
				} else {
					set(vRight, m + 1, r, index, value);
				}
				
				return tree[v] = max(tree[vLeft], tree[vRight]);
			}
		}
	}
	
	void solve() throws IOException {
		int n = readInt();
		
		int[] x = new int[n];
		int[] w = new int[n];
		
		for (int i = 0; i < n; ++i) {
			x[i] = readInt();
			w[i] = readInt();
		}
		
		id27[] decPairs = new id27[n];
		id27[] incPairs = new id27[n];
		
		for (int i = 0; i < n; ++i) {
			decPairs[i] = new id27(x[i] - w[i], i);
			incPairs[i] = new id27(x[i] + w[i], i);
		}
		
		Arrays.sort(decPairs, id27.increaseComparator);
		Arrays.sort(incPairs, id27.increaseComparator);
		
		int[] decIndexes = new int[n];
		int[] incIndexes = new int[n];
		
		for (int i = 0; i < n; ++i) {
			decIndexes[decPairs[i].index] = i;
			incIndexes[incPairs[i].index] = i;
		}
		
		TreeMap<Integer, Integer> decMap = new TreeMap<Integer, Integer>();
		TreeMap<Integer, Integer> incMap = new TreeMap<Integer, Integer>();
		
		for (int i = 0; i < n; ++i) {
			decMap.put(decPairs[i].value, i);
			incMap.put(incPairs[i].value, i);
		}
		
		id30 prefTree = new id30(n);
		int[] prefDp = new int[n];
		
		class Vertex implements Comparable<Vertex> {
			int x, w, index;
			
			Vertex(int x, int w, int index) {
				this.x = x;
				this.w = w;
				this.index = index;
			}
			
			@Override
			public int compareTo(Vertex other) {
				return this.x - other.x;
			}

			@Override
			public String toString() {
				return "Vertex [x=" + x + ", w=" + w + "]";
			}
			
			
		}
		
		Vertex[] v = new Vertex[n];
		for (int i = 0; i < n; ++i) {
			v[i] = new Vertex(x[i], w[i], i);
		}
		
		Arrays.sort(v);
		
		for (int i = 0; i < n; ++i) {
			int curDec = v[i].x - v[i].w;
			
			Integer id19 = incMap.floorKey(curDec);
			int id25 = (id19 == null ? -1 : incMap.get(id19));
			
			if (id25 >= 0) {
				prefDp[i] = prefTree.id22(id25) + 1;
			} else {
				prefDp[i] = 1;
			}
			
			prefTree.set(incIndexes[v[i].index], prefDp[i]);
		}
		
		id30 id9 = new id30(n);
		int[] id26 = new int[n];
		
		for (int i = n - 1; i >= 0; --i) {
			int curInc = v[i].x + v[i].w;
			
			Integer id17 = decMap.lowerKey(curInc);
			int id24 = (id17 == null ? 0 : decMap.get(id17) + 1);
			
			id26[i] = id9.id23(id24) + 1;
			id9.set(decIndexes[v[i].index], id26[i]);
		}
		
		int answer = 0;
		for (int i = 0; i < n; ++i) {
			answer = max(answer, prefDp[i] + id26[i] - 1);
		}
		
		out.println(answer);
	}
	
	void solveSquare() throws IOException {
		int n = readInt();
		
		int[] x = new int[n];
		int[] w = new int[n];
		
		for (int i = 0; i < n; ++i) {
			x[i] = readInt();
			w[i] = readInt();
		}
		
		class Vertex implements Comparable<Vertex> {
			int x, w;
			
			Vertex(int x, int w) {
				this.x = x;
				this.w = w;
			}
			
			@Override
			public int compareTo(Vertex other) {
				return this.x - other.x;
			}
		}
		
		Vertex[] v = new Vertex[n];
		for (int i = 0; i < n; ++i) {
			v[i] = new Vertex(x[i], w[i]);
		}
		
		Arrays.sort(v);
		
		int[] prefDp = new int[n];
		for (int i = 0; i < n; ++i) {
			int id4 = 0;
			for (int j = 0; j < i; ++j) {
				if (v[i].x - v[j].x >= v[j].w + v[i].w) {
					id4 = max(id4, prefDp[j]);
				}
			}
			
			prefDp[i] = id4 + 1;
		}
		
		int[] id26 = new int[n];
		
		for (int i = n - 1; i >= 0; --i) {
			int id16 = 0;
			for (int j = i + 1; j < n; ++j) {
				if (v[j].x - v[i].x >= v[j].w + v[i].w) {
					id16 = max(id16, id26[j]);
				}
			}
			
			id26[i] = id16 + 1;
		}
		
		int answer = 0;
		for (int i = 0; i < n; ++i) {
			answer = max(answer, prefDp[i] + id26[i] - 1);
		}
		
		for (int i = 0; i < n; ++i) {
			if (answer == prefDp[i] + id26[i] - 1) {
				debug(i);
			}
		}
		
		debug("Answer");
		out.println(answer);
	}
}

