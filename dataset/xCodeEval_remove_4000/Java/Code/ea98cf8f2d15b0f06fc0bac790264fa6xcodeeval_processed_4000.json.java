import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;


public class C implements Runnable{
	
	final static Random rnd = new Random();
	
	

	

	

	

	

	void solve() {
		int n = readInt();
		int k = readInt();
		
		int[] c = id1(n);
		
		int size = (n + 1) * (k + 1);
		
		List<Integer>[] graph = new List[size];
		
		for (int v = 0; v < size; ++v) {
			graph[v] = new ArrayList<Integer>();
		}
		
		int[] matchings = new int[size];
		int[] indexes = new int[size];
		
		for (int x = 0; x <= k; ++x) {
			for (int i = 0; i <= n; ++i) {
				int from = i * (k + 1) + x;
				matchings[from] = x;
				indexes[from] = i;
				
				if (i == n) continue;
				
				int to = (i + 1) * (k + 1) + x;
				graph[from].add(to);


				
				if (x + c[i] <= k) {
					to = (i + 1) * (k + 1) + x + c[i];
					graph[from].add(to);


				}
			}
		}
		
		int[] parents = new int[size];
		Arrays.fill(parents, -1);
		
		boolean[] used = new boolean[size];
		Queue<Integer> queue = new ArrayDeque<Integer>();
		
		int start = 0 * (k + 1) + 0;
		queue.add(start);
		used[start] = true;
		
		while (queue.size() > 0) {
			int from = queue.poll();
			for (int to : graph[from]) {
				if (used[to]) continue;
				
				used[to] = true;
				parents[to] = from;
				queue.add(to);
			}
		}
	
		boolean[] can = new boolean[k + 1];
		boolean[] processed = new boolean[k + 1];
		
		int[] banned = new int[n + 1];
		Arrays.fill(banned, -1);
		
		int[] processingColors = new int[size];
		Arrays.fill(processingColors, -1);
		
		Queue<Integer> processingQueue = new ArrayDeque<Integer>();
		
		for (int v = size - 1; v >= 0; --v) {
			if (used[v]) {
				int x = matchings[v];
				if (processed[x]) continue;
				
				processed[x] = true;
				for (int cur = v; cur > 0; cur = parents[cur]) {
					int curX = matchings[cur];
					
					int parent = parents[cur];
					int parentX = matchings[parent];
					
					if (curX != parentX) {
						int parentI = indexes[parent];
						banned[parentI] = v;
					}
				}
				
				processingColors[start] = v;
				processingQueue.add(start);
				
				while (processingQueue.size() > 0) {
					int from = processingQueue.poll();
					
					int fromX = matchings[from];
					if (fromX == k - x) {
						can[x] = true;
						can[k - x] = true;
						
						while (processingQueue.size() > 0) {
							processingQueue.poll();
						}
						break;
					}
					
					int fromI = indexes[from];
					for (int to : graph[from]) {
						int toX = matchings[to];
						if (banned[fromI] == v && toX != fromX) {
							continue;
						}
						
						if (processingColors[to] == v) continue;
						
						processingColors[to] = v;
						processingQueue.add(to);
					}
				}
			}
		}
		
















































































































		
		List<Integer> answer = new ArrayList<Integer>();
		for (int x = 0; x <= k; ++x) {
			if (can[x]) {
				answer.add(x);
			}
		}
		
		out.println(answer.size());
		for (int x : answer) {
			out.print(x + " ");
		}
		out.println();
	}
	
	

	
	final boolean id2 = false;
	final boolean id8 = System.getProperty("id8") != null;
	
	final static int id13 = 128;
	
	

	
	public void run(){
		try{
			timeBegin = System.currentTimeMillis();
			Locale.setDefault(Locale.US);
			
			init();
			
			if (id8) {
				solve();
			} else {
				while (true) {
					try {
						solve();
						out.println();
					} catch (NumberFormatException e) {
						break;
					} catch (NullPointerException e) {
						if (id2) break;
						else throw e;
					}
				}
			}
			
			out.close();
			time();
		}catch (Exception e){
			e.printStackTrace(System.err);
			System.exit(-1);
		}
	}
	
	

	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new C(), "", id13 * (1L << 20)).start();
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
		if (id8){
			for (Object o: objects){
				System.err.println(o.toString());
			}
		}
	}
	
	

	
	String delim = " ";
	
	String readLine() {
		try {
			return in.readLine();
		} catch (IOException e) {
			throw new RuntimeIOException(e);
		}
	}
	
	String readString() {
		try {
			while(!tok.hasMoreTokens()){
				tok = new StringTokenizer(readLine());
			}
			
			return tok.nextToken(delim);
		} catch (NullPointerException e) {
			return null;
		}
	}
	
	

	
	final char id6 = '\0';
	
	char readChar() {
		try {
			int intValue = in.read();
			
			if (intValue == -1){
				return id6;
			}
			
			return (char) intValue;
		} catch (IOException e) {
			throw new RuntimeIOException(e);
		}
	}
	
	char[] id7() {
		return readLine().toCharArray();
	}
	
	char[][] id17(int rowsCount) {
		char[][] field = new char[rowsCount][];
		for (int row = 0; row < rowsCount; ++row) {
			field[row] = id7();
		}
		
		return field;
	}
	
	

	
	int readInt() {
		return Integer.parseInt(readString());
	}
	
	int[] id1(int size) {
		int[] array = new int[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readInt();
		}
		
		return array;
	}
	
	int[] id9(int size) {
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
	
	int[] id10(int size) {
		int[] array = id1(size);
		
		for (int i = 0; i < size; ++i) {
			array[i]--;
		}
		
		return array;
	}
	
	

	
	int[][] id15(int rowsCount, int columnsCount) {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id1(columnsCount);
		}
		
		return matrix;
	}
	
	int[][] id21(int rowsCount, int columnsCount) {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id10(columnsCount);
		}
		
		return matrix;
	}
	
	

	
	long readLong() {
		return Long.parseLong(readString());
	}
	
	long[] id11(int size) {
		long[] array = new long[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readLong();
		}
		
		return array;
	}
	
	

	
	double readDouble() {
		return Double.parseDouble(readString());
	}
	
	double[] id4(int size) {
		double[] array = new double[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readDouble();
		}
		
		return array;
	}
	
	

		
	BigInteger id19() {
		return new BigInteger(readString());
	}
	
	BigDecimal id18() {
		return new BigDecimal(readString());
	}
	
	

	
	Point readPoint() {
		int x = readInt();
		int y = readInt();
		return new Point(x, y);
	}
	
	Point[] id24(int size) {
		Point[] array = new Point[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readPoint();
		}
		
		return array;
	}
	
	

	
	List<Integer>[] readGraph(int vertexNumber, int edgeNumber) {
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
	
	

	
	static class id20 {
		
		static Comparator<id20> increaseComparator = new Comparator<id20>() {
			
			@Override
			public int compare(id20 id16, id20 id12) {
				int value1 = id16.value;
				int value2 = id12.value;
				
				if (value1 != value2) return value1 - value2;
				
				int index1 = id16.index;
				int index2 = id12.index;
				
				return index1 - index2;
			}
		};
		
		static Comparator<id20> id0 = new Comparator<id20>() {
			
			@Override
			public int compare(id20 id16, id20 id12) {
				int value1 = id16.value;
				int value2 = id12.value;
				
				if (value1 != value2) return -(value1 - value2);
				
				int index1 = id16.index;
				int index2 = id12.index;
				
				return index1 - index2;
			}
		};
		
		int value, index;

		public id20(int value, int index) {
			super();
			this.value = value;
			this.index = index;
		}		
		
		public int id5() {
			return index + 1;
		}
	}
	
	id20[] id3(int size) {
		id20[] array = new id20[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = new id20(readInt(), index);
		}
		
		return array;
	}
	
	

	
	static class OutputWriter extends PrintWriter {

		final int id26 = 12;
		
		protected int precision;
		protected String format, id25;
		
		{
			precision = id26;
			
			format = createFormat(precision);
			id25 = format + " ";
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
			id25 = format + " ";
		}
		
		private String createFormat(int precision){
			return "%." + precision + "f";
		}
		
		@Override
		public void print(double d){
			printf(format, d);
		}
		
		public void id22(double d){
			printf(id25, d);
		}

		public void printAll(double...d){
			for (int i = 0; i < d.length - 1; ++i){
				id22(d[i]);
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
	
	

	
	static class RuntimeIOException extends RuntimeException {

		
		private static final long id23 = -6463830523020118289L;

		public RuntimeIOException(Throwable cause) {
			super(cause);
		}
	}
	
	

	

	

	
	static final int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
	static final int[][] steps8 = {
			{-1, 0}, {1, 0}, {0, -1}, {0, 1},
			{-1, -1}, {1, 1}, {1, -1}, {-1, 1}
	};
	
	static final boolean checkCell(int row, int rowsCount, int column, int columnsCount) {
		return checkIndex(row, rowsCount) && checkIndex(column, columnsCount);
	}
	
	static final boolean checkIndex(int index, int lim){
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
	
	

	
	static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

		
		private static final long id23 = -3793737771950984481L;

		public IdMap() {
			super();
		}
		
		int getId(KeyType key) {
			Integer id = super.get(key);
			if (id == null) {
				super.put(key, id = size());
			}
			
			return id;
		}
	}
}

