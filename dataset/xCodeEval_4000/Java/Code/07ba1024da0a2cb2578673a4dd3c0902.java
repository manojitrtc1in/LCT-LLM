import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;




public class C implements Runnable{
	
	final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new C(), "", 128 * (1L << 20)).start();
	}
	
	

	
	void init() throws FileNotFoundException{
		Locale.setDefault(Locale.US);
		
		if (ONLINE_JUDGE){
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
		if (ONLINE_JUDGE){
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
	
	

	
	final char NOT_A_SYMBOL = '\0';
	
	char readChar() throws IOException{
		int intValue = in.read();
		
		if (intValue == -1){
			return NOT_A_SYMBOL;
		}
		
		return (char) intValue;
	}
	
	char[] readCharArray() throws IOException{
		return readLine().toCharArray();
	}
	
	

	
	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}
	
	int[] readIntArray(int size) throws IOException {
		int[] array = new int[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readInt();
		}
		
		return array;
	}
	
	int[] readSortedIntArray(int size) throws IOException {
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
	
	int[] readIntArrayWithDecrease(int size) throws IOException {
		int[] array = readIntArray(size);
		
		for (int i = 0; i < size; ++i) {
			array[i]--;
		}
		
		return array;
	}
	
	

	
	int[][] readIntMatrix(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = readIntArray(columnsCount);
		}
		
		return matrix;
	}
	
	int[][] readIntMatrixWithDecrease(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = readIntArrayWithDecrease(columnsCount);
		}
		
		return matrix;
	}
	
	

	
	long readLong() throws IOException{
		return Long.parseLong(readString());
	}
	
	long[] readLongArray(int size) throws IOException{
		long[] array = new long[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readLong();
		}
		
		return array;
	}
	
	

	
	double readDouble() throws IOException{
		return Double.parseDouble(readString());
	}
	
	double[] readDoubleArray(int size) throws IOException{
		double[] array = new double[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readDouble();
		}
		
		return array;
	}
	
	

		
	BigInteger readBigInteger() throws IOException {
		return new BigInteger(readString());
	}
	
	BigDecimal readBigDecimal() throws IOException {
		return new BigDecimal(readString());
	}
	
	

	
	Point readPoint() throws IOException{
		int x = readInt();
		int y = readInt();
		return new Point(x, y);
	}
	
	Point[] readPointArray(int size) throws IOException{
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
	
	

	
	static class IntIndexPair {
		
		static Comparator<IntIndexPair> increaseComparator = new Comparator<IntIndexPair>() {
			
			@Override
			public int compare(IntIndexPair indexPair1, IntIndexPair indexPair2) {
				int value1 = indexPair1.value;
				int value2 = indexPair2.value;
				
				if (value1 != value2) return value1 - value2;
				
				int index1 = indexPair1.index;
				int index2 = indexPair2.index;
				
				return index1 - index2;
			}
		};
		
		static Comparator<IntIndexPair> decreaseComparator = new Comparator<IntIndexPair>() {
			
			@Override
			public int compare(IntIndexPair indexPair1, IntIndexPair indexPair2) {
				int value1 = indexPair1.value;
				int value2 = indexPair2.value;
				
				if (value1 != value2) return -(value1 - value2);
				
				int index1 = indexPair1.index;
				int index2 = indexPair2.index;
				
				return index1 - index2;
			}
		};
		
		int value, index;

		public IntIndexPair(int value, int index) {
			super();
			this.value = value;
			this.index = index;
		}		
		
		public int getRealIndex() {
			return index + 1;
		}
	}
	
	IntIndexPair[] readIntIndexArray(int size) throws IOException {
		IntIndexPair[] array = new IntIndexPair[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = new IntIndexPair(readInt(), index);
		}
		
		return array;
	}
	
	

	
	static class OutputWriter extends PrintWriter {

		final int DEFAULT_PRECISION = 12;
		
		protected int precision;
		protected String format, formatWithSpace;
		
		{
			precision = DEFAULT_PRECISION;
			
			format = createFormat(precision);
			formatWithSpace = format + " ";
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
			formatWithSpace = format + " ";
		}
		
		private String createFormat(int precision){
			return "%." + precision + "f";
		}
		
		@Override
		public void print(double d){
			printf(format, d);
		}
		
		public void printWithSpace(double d){
			printf(formatWithSpace, d);
		}

		public void printAll(double...d){
			for (int i = 0; i < d.length - 1; ++i){
				printWithSpace(d[i]);
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
	
	static final Point getMinMax(int[] array) {
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
	
	

	
	List<Integer>[] tree;
	
	int[] types;
	
	int[] distances;
	int[] parents;
	
	int[] twoColors;
	
	void solve() throws IOException {
		int n = readInt();
		tree = readGraph(n, n - 1);
		
		int[] degrees = new int[n];
		for (int i = 0; i < n; ++i) {
			degrees[i] = tree[i].size();
		}
		
		this.types = new int[n];
		for (int i = 0; i < n; ++i) {
			if (degrees[i] == 1 || degrees[i] == 2) {
				types[i] = 1;
			} else if (degrees[i] == 3) {
				types[i] = 2;
			} else {
				types[i] = 3;
			}
		}
		
		for (int i = 0; i < n; ++i) {
			if (types[i] == 2) {
				if (isType3(i)) {
					types[i] = 3;
				}
			}
		}
		
		int root = -1;
		int nextRoot = -1;
		for (int i = 0; i < n; ++i) {
			if (types[i] == 3) {
				root = i;
			}
		}
		
		this.distances = new int[n];
		this.parents = new int[n];
		
		if (root != -1) {
			bfs(root);
			
			nextRoot = root;
			for (int i = 0; i < n; ++i) {
				if (types[i] == 3 && distances[i] > distances[nextRoot]) {
					nextRoot = i;
				}
			}
			
			root = nextRoot;
			bfs(root);
			
			nextRoot = root;
			for (int i = 0; i < n; ++i) {
				if (types[i] == 3 && distances[i] > distances[nextRoot]) {
					nextRoot = i;
				}
			}
			
			boolean[] used = new boolean[n];
			for (int cur = nextRoot; cur != -1; cur = parents[cur]) {
				used[cur] = true;
			}
			
			for (int i = 0; i < n; ++i) {
				if (types[i] == 3 && !used[i]) {
					out.println("No");
					return;
				}
			}
		}
		
		
























































































































































































































		
		
		
		
		out.println("Yes");
	}
	
	int dfs(int from, int parent, int color) {
		twoColors[from] = color;
		
		if (tree[from].size() > 2) {
			return from;
		}
		
		for (int to : tree[from]) {
			if (to != parent && twoColors[to] != color) {
				return dfs(to, from, color);
			}
		}
		
		return 1;
	}
	
	int dfs(int from, int parent) {
		if (tree[from].size() > 2) {
			return from;
		}
		
		for (int to : tree[from]) {
			if (to != parent) {
				return dfs(to, from);
			}
		}
		
		return -1;
	}
	
	boolean isType3(int two) {
		int count = 0;
		int maxDegreeChild = -1;
		for (int to : tree[two]) {
			int child = dfs(to, two);
			if (child != -1) {
				maxDegreeChild = child;
			} else {
				++count;
			}
		}
		
		if (count == 2 && !tree[two].contains(maxDegreeChild)) {
			return true;
		}
		
		return count != 2;
	}
	
	int getParent(int two, int color) {
		twoColors[two] = color;
		for (int to : tree[two]) {
			int maxDegree = dfs(to, two, color);
			if (maxDegree > 1) return to;
		}
		
		return two;
	}
	
	void bfs(int root) {
		Arrays.fill(distances, distances.length * 10);
		Arrays.fill(parents, -1);
		
		boolean[] used = new boolean[distances.length];
		
		Queue<Integer> queue = new ArrayDeque<Integer>();
		
		distances[root] = 0;
		used[root] = true;
		queue.add(root);
		
		while (queue.size() > 0) {
			int from = queue.poll();
			
			for (int to : tree[from]) {
				if (used[to]) continue;
				
				distances[to] = distances[from] + 1;
				parents[to] = from;
				used[to] = true;
				queue.add(to);
			}
		}
	}
	
	List<Integer> twoBfs(int twoRoot, int color, boolean needList) {
		List<Integer> queue = new ArrayList<Integer>();
		
		distances[twoRoot] = 0;
		twoColors[twoRoot] = color;
		parents[twoRoot] = -1;
		queue.add(twoRoot);
		
		List<Integer> twos = new ArrayList<Integer>();
		
		for (int index = 0; index < queue.size(); ++index) {
			int from = queue.get(index);
			if (needList && types[from] == 2) {
				twos.add(from);
			}
			
			for (int to : tree[from]) {
				if (twoColors[to] == color) continue;
				if (types[to] == 3) continue;
				
				distances[to] = distances[from] + 1;
				parents[to] = from;
				twoColors[to] = color;
				queue.add(to);
			}
		}
		
		return (needList ? twos : queue);
	}
}

