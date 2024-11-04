import java.util.*;
import java.util.function.Supplier;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;


public class id30 implements Runnable{
	
	final static Random rnd = new Random();
	
	

	

	

	

	

	
	void solve() {
		int n = readInt();
		int[] a = id1(n);
		int[] b = id1(n);
		
		long answer = getAnswer(n, a, b);
		out.println(answer);
		
		if (!id11) {
			out.println();
			out.println(id43(n, a, b));
		}
	}
	
	long getAnswer(int n, int[] a, int[] b) {
		NavigableMap<Integer, Queue<Integer>> aElements = new TreeMap<Integer, Queue<Integer>>();
		NavigableMap<Integer, NavigableSet<Integer>> bElements = new TreeMap<Integer, NavigableSet<Integer>>();
		
		for (int i = 0; i < n; ++i) {
			add(aElements, i, a[i], ArrayDeque<Integer>::new);
			add(bElements, i, b[i], TreeSet<Integer>::new);
		}
		
		int id13 = Integer.MIN_VALUE;
		NavigableSet<Integer> id3 = new TreeSet<Integer>();
		
		NavigableSet<Integer> id45 = new TreeSet<Integer>();
		for (int index = 0; index < n; ++index) {
			id45.add(index);
		}
		
		NavigableSet<Integer> id10 = new TreeSet<Integer>();
		
		long answer = 0;
		
		for (Map.Entry<Integer, Queue<Integer>> aValueEntry : aElements.entrySet()) {
			int aValue = aValueEntry.getKey();
			Queue<Integer> aIndexes = aValueEntry.getValue();
			
			for (Map.Entry<Integer, NavigableSet<Integer>> id25 = bElements.firstEntry();
					id25 != null && id25.getKey() < aValue;
					bElements.pollFirstEntry(), id25 = bElements.firstEntry()) {
				for (int bIndex : id25.getValue()) {
					id10.add(bIndex);
				}
			}
			
			Map.Entry<Integer, NavigableSet<Integer>> id25 = bElements.firstEntry();
			if (id25 != null) {
				id13 = id25.getKey();
				id3 = id25.getValue();
			} else {
				id13 = Integer.MAX_VALUE;
				id3 = null;
			}
			
			while (aIndexes.size() > 0) {
				int aIndex = aIndexes.poll();
				id45.remove(aIndex);
				
				Integer id31 = id45.floor(aIndex);
				Integer id34 = id45.ceiling(aIndex);
				
				if (id31 == null) id31 = -1;
				if (id34 == null) id34 = n;
				
				if (id13 != aValue) {
					continue;
				}
				
				if (b[aIndex] < aValue) continue;
				
				Integer id21 = id10.floor(aIndex);
				Integer id24 = id10.ceiling(aIndex);
				
				if (id21 == null) id21 = -1;
				if (id24 == null) id24 = n;
				
				id21 = Math.max(id21, id31);
				id24 = Math.min(id24, id34);
				
				long id16 = aIndex - id21;
				long id44 = id24 - aIndex;
				
				answer += id16 * id44;
				
				if (b[aIndex] > aValue) {
					Integer id33 = id3.floor(aIndex);
					Integer id2 = id3.ceiling(aIndex);
					
					if (id33 == null) id33 = id21;
					if (id2 == null) id2 = id24;
					
					id33 = Math.max(id33, id21);
					id2 = Math.min(id2, id24);
					
					id33 = Math.max(id33, id31);
					id2 = Math.min(id2, id34);
					
					long id12 = aIndex - id33;
					long id32 = id2 - aIndex;
					
					answer -= id12 * id32;
				}
			}
		}
		
		return answer;
	}
	
	<IntegerCollection extends Collection<Integer>> void add(
			NavigableMap<Integer, IntegerCollection> id46, 
			int index, int value, 
			Supplier<IntegerCollection> collectionConstructor) {
		IntegerCollection id40 = id46.get(value);
		if (id40 == null) {
			id46.put(value, id40 = collectionConstructor.get());
		}
		
		id40.add(index);
	}
	
	long id43(int n, int[] a, int[] b) {
		long count = 0;
		for (int left = 0; left < n; ++left) {
			int aMax = a[left];
			int bMin = b[left];
			
			for (int right = left; right < n; ++right) {
				aMax = max(aMax, a[right]);
				bMin = min(bMin, b[right]);
				
				if (aMax == bMin) {


					++count;
				}
			}
		}
		
		return count;
	}
	
	

	
	final boolean STRESS = false;
	
	final boolean id4 = false;
	final boolean id11 = System.getProperty("id11") != null;
	
	final static int id20 = 128;
	
	

	
	public void run(){
		try{
			timeBegin = System.currentTimeMillis();
			Locale.setDefault(Locale.US);
			
			init();
			
			if (id11) {
				solve();
			} else if (STRESS) {
				for (int iteration = 0; iteration < 100; ++iteration) {
					int n = 1000;
					
					final int MIN_VALUE = -1000 * 1000 * 1000, MAX_VALUE = -MIN_VALUE;
					
					int[] a = new int[n];
					int[] b = new int[n];
					
					for (int i = 0; i < n; ++i) {
						a[i] = rnd.nextInt(MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
						b[i] = rnd.nextInt(MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
					}
					
					long fastAnswer = getAnswer(n, a, b);
					long id17 = id43(n, a, b);
					
					if (fastAnswer != id17) {
						out.println(n);
						for (int value : a) {
							out.print(value + " ");
						}
						
						for (int value : b) {
							out.print(value + " ");
						}
						
						out.println(fastAnswer + " " + id17);
						break;
					}
				}
				
				out.println("The end");
			} else {
				while (true) {
					try {
						solve();
						out.println();
					} catch (NumberFormatException e) {
						break;
					} catch (NullPointerException e) {
						if (id4) break;
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
		new Thread(null, new id30(), "", id20 * (1L << 20)).start();
	}
	
	

	
	void init() throws FileNotFoundException{
		Locale.setDefault(Locale.US);
		
		if (id11){
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
		if (id11){
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
	
	

	
	final char id8 = '\0';
	
	char readChar() {
		try {
			int intValue = in.read();
			
			if (intValue == -1){
				return id8;
			}
			
			return (char) intValue;
		} catch (IOException e) {
			throw new RuntimeIOException(e);
		}
	}
	
	char[] id9() {
		return readLine().toCharArray();
	}
	
	char[][] id27(int rowsCount) {
		char[][] field = new char[rowsCount][];
		for (int row = 0; row < rowsCount; ++row) {
			field[row] = id9();
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
	
	int[] id14(int size) {
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
	
	int[] id15(int size) {
		int[] array = id1(size);
		
		for (int i = 0; i < size; ++i) {
			array[i]--;
		}
		
		return array;
	}
	
	

	
	int[][] id23(int rowsCount, int columnsCount) {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id1(columnsCount);
		}
		
		return matrix;
	}
	
	int[][] id36(int rowsCount, int columnsCount) {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id15(columnsCount);
		}
		
		return matrix;
	}
	
	

	
	long readLong() {
		return Long.parseLong(readString());
	}
	
	long[] id18(int size) {
		long[] array = new long[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readLong();
		}
		
		return array;
	}
	
	

	
	double readDouble() {
		return Double.parseDouble(readString());
	}
	
	double[] id6(int size) {
		double[] array = new double[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readDouble();
		}
		
		return array;
	}
	
	

		
	BigInteger id29() {
		return new BigInteger(readString());
	}
	
	BigDecimal id28() {
		return new BigDecimal(readString());
	}
	
	

	
	Point readPoint() {
		int x = readInt();
		int y = readInt();
		return new Point(x, y);
	}
	
	Point[] id39(int size) {
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
	
	

	
	static class id35 {
		
		static Comparator<id35> increaseComparator = new Comparator<id35>() {
			
			@Override
			public int compare(id35 id26, id35 id19) {
				int value1 = id26.value;
				int value2 = id19.value;
				
				if (value1 != value2) return value1 - value2;
				
				int index1 = id26.index;
				int index2 = id19.index;
				
				return index1 - index2;
			}
		};
		
		static Comparator<id35> id0 = new Comparator<id35>() {
			
			@Override
			public int compare(id35 id26, id35 id19) {
				int value1 = id26.value;
				int value2 = id19.value;
				
				if (value1 != value2) return -(value1 - value2);
				
				int index1 = id26.index;
				int index2 = id19.index;
				
				return index1 - index2;
			}
		};
		
		int value, index;

		public id35(int value, int index) {
			super();
			this.value = value;
			this.index = index;
		}		
		
		public int id7() {
			return index + 1;
		}
	}
	
	id35[] id5(int size) {
		id35[] array = new id35[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = new id35(readInt(), index);
		}
		
		return array;
	}
	
	

	
	static class OutputWriter extends PrintWriter {

		final int id42 = 12;
		
		protected int precision;
		protected String format, id41;
		
		{
			precision = id42;
			
			format = createFormat(precision);
			id41 = format + " ";
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
			id41 = format + " ";
		}
		
		private String createFormat(int precision){
			return "%." + precision + "f";
		}
		
		@Override
		public void print(double d){
			printf(format, d);
		}
		
		public void id37(double d){
			printf(id41, d);
		}

		public void printAll(double...d){
			for (int i = 0; i < d.length - 1; ++i){
				id37(d[i]);
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

		
		private static final long id38 = -6463830523020118289L;

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
	
	static final Point id22(int[] array) {
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

		
		private static final long id38 = -3793737771950984481L;

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

