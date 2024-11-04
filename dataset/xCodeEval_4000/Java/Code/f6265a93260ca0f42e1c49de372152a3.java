import java.util.*;
import java.util.function.Supplier;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;


public class __AAAAA implements Runnable{
	
	final static Random rnd = new Random();
	
	

	

	

	

	

	
	void solve() {
		int n = readInt();
		int[] a = readIntArray(n);
		int[] b = readIntArray(n);
		
		long answer = getAnswer(n, a, b);
		out.println(answer);
		
		if (!ONLINE_JUDGE) {
			out.println();
			out.println(getBruteAnswer(n, a, b));
		}
	}
	
	long getAnswer(int n, int[] a, int[] b) {
		NavigableMap<Integer, Queue<Integer>> aElements = new TreeMap<Integer, Queue<Integer>>();
		NavigableMap<Integer, NavigableSet<Integer>> bElements = new TreeMap<Integer, NavigableSet<Integer>>();
		
		for (int i = 0; i < n; ++i) {
			add(aElements, i, a[i], ArrayDeque<Integer>::new);
			add(bElements, i, b[i], TreeSet<Integer>::new);
		}
		
		int currentBValue = Integer.MIN_VALUE;
		NavigableSet<Integer> currentBIndexes = new TreeSet<Integer>();
		
		NavigableSet<Integer> aRemovedIndexes = new TreeSet<Integer>();
		for (int index = 0; index < n; ++index) {
			aRemovedIndexes.add(index);
		}
		
		NavigableSet<Integer> bAddedIndexes = new TreeSet<Integer>();
		
		long answer = 0;
		
		for (Map.Entry<Integer, Queue<Integer>> aValueEntry : aElements.entrySet()) {
			int aValue = aValueEntry.getKey();
			Queue<Integer> aIndexes = aValueEntry.getValue();
			
			for (Map.Entry<Integer, NavigableSet<Integer>> bValueEntry = bElements.firstEntry();
					bValueEntry != null && bValueEntry.getKey() < aValue;
					bElements.pollFirstEntry(), bValueEntry = bElements.firstEntry()) {
				for (int bIndex : bValueEntry.getValue()) {
					bAddedIndexes.add(bIndex);
				}
			}
			
			Map.Entry<Integer, NavigableSet<Integer>> bValueEntry = bElements.firstEntry();
			if (bValueEntry != null) {
				currentBValue = bValueEntry.getKey();
				currentBIndexes = bValueEntry.getValue();
			} else {
				currentBValue = Integer.MAX_VALUE;
				currentBIndexes = null;
			}
			
			while (aIndexes.size() > 0) {
				int aIndex = aIndexes.poll();
				aRemovedIndexes.remove(aIndex);
				
				Integer aLeftBadIndex = aRemovedIndexes.floor(aIndex);
				Integer aRightBadIndex = aRemovedIndexes.ceiling(aIndex);
				
				if (aLeftBadIndex == null) aLeftBadIndex = -1;
				if (aRightBadIndex == null) aRightBadIndex = n;
				
				if (currentBValue != aValue) {
					continue;
				}
				
				if (b[aIndex] < aValue) continue;
				
				Integer bLeftBadIndex = bAddedIndexes.floor(aIndex);
				Integer bRightBadIndex = bAddedIndexes.ceiling(aIndex);
				
				if (bLeftBadIndex == null) bLeftBadIndex = -1;
				if (bRightBadIndex == null) bRightBadIndex = n;
				
				bLeftBadIndex = Math.max(bLeftBadIndex, aLeftBadIndex);
				bRightBadIndex = Math.min(bRightBadIndex, aRightBadIndex);
				
				long bLeftLength = aIndex - bLeftBadIndex;
				long bRightLength = bRightBadIndex - aIndex;
				
				answer += bLeftLength * bRightLength;
				
				if (b[aIndex] > aValue) {
					Integer bLeftGoodStart = currentBIndexes.floor(aIndex);
					Integer bRightGoodStart = currentBIndexes.ceiling(aIndex);
					
					if (bLeftGoodStart == null) bLeftGoodStart = bLeftBadIndex;
					if (bRightGoodStart == null) bRightGoodStart = bRightBadIndex;
					
					bLeftGoodStart = Math.max(bLeftGoodStart, bLeftBadIndex);
					bRightGoodStart = Math.min(bRightGoodStart, bRightBadIndex);
					
					bLeftGoodStart = Math.max(bLeftGoodStart, aLeftBadIndex);
					bRightGoodStart = Math.min(bRightGoodStart, aRightBadIndex);
					
					long bLeftBadLength = aIndex - bLeftGoodStart;
					long bRightBadLength = bRightGoodStart - aIndex;
					
					answer -= bLeftBadLength * bRightBadLength;
				}
			}
		}
		
		return answer;
	}
	
	void addQueue(
			NavigableMap<Integer, Queue<Integer>> indexesByValues, 
			int index, int value) {
		Queue<Integer> indexesForValue = indexesByValues.get(value);
		if (indexesForValue == null) {
			indexesByValues.put(value, indexesForValue = new ArrayDeque<Integer>());
		}
		
		indexesForValue.add(index);
	}
	
	void addSet(
			NavigableMap<Integer, Set<Integer>> indexesByValues, 
			int index, int value) {
		Set<Integer> indexesForValue = indexesByValues.get(value);
		if (indexesForValue == null) {
			indexesByValues.put(value, indexesForValue = new TreeSet<Integer>());
		}
		
		indexesForValue.add(index);
	}
	
	<IntegerCollection extends Collection<Integer>> void add(
			NavigableMap<Integer, IntegerCollection> indexesByValues, 
			int index, int value, 
			Supplier<IntegerCollection> collectionConstructor) {
		IntegerCollection indexesForValue = indexesByValues.get(value);
		if (indexesForValue == null) {
			indexesByValues.put(value, indexesForValue = collectionConstructor.get());
		}
		
		indexesForValue.add(index);
	}
	
	long getBruteAnswer(int n, int[] a, int[] b) {
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
	
	final boolean FIRST_INPUT_STRING = false;
	final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
	
	final static int MAX_STACK_SIZE = 128;
	
	

	
	public void run(){
		try{
			timeBegin = System.currentTimeMillis();
			Locale.setDefault(Locale.US);
			
			init();
			
			if (ONLINE_JUDGE) {
				solve();
			} else if (STRESS) {
				for (int iteration = 0; iteration < 100; ++iteration) {
					

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
						if (FIRST_INPUT_STRING) break;
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
		new Thread(null, new __AAAAA(), "", MAX_STACK_SIZE * (1L << 20)).start();
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
	
	

	
	final char NOT_A_SYMBOL = '\0';
	
	char readChar() {
		try {
			int intValue = in.read();
			
			if (intValue == -1){
				return NOT_A_SYMBOL;
			}
			
			return (char) intValue;
		} catch (IOException e) {
			throw new RuntimeIOException(e);
		}
	}
	
	char[] readCharArray() {
		return readLine().toCharArray();
	}
	
	char[][] readCharField(int rowsCount) {
		char[][] field = new char[rowsCount][];
		for (int row = 0; row < rowsCount; ++row) {
			field[row] = readCharArray();
		}
		
		return field;
	}
	
	

	
	int readInt() {
		return Integer.parseInt(readString());
	}
	
	int[] readIntArray(int size) {
		int[] array = new int[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readInt();
		}
		
		return array;
	}
	
	int[] readSortedIntArray(int size) {
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
	
	int[] readIntArrayWithDecrease(int size) {
		int[] array = readIntArray(size);
		
		for (int i = 0; i < size; ++i) {
			array[i]--;
		}
		
		return array;
	}
	
	

	
	int[][] readIntMatrix(int rowsCount, int columnsCount) {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = readIntArray(columnsCount);
		}
		
		return matrix;
	}
	
	int[][] readIntMatrixWithDecrease(int rowsCount, int columnsCount) {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = readIntArrayWithDecrease(columnsCount);
		}
		
		return matrix;
	}
	
	

	
	long readLong() {
		return Long.parseLong(readString());
	}
	
	long[] readLongArray(int size) {
		long[] array = new long[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readLong();
		}
		
		return array;
	}
	
	

	
	double readDouble() {
		return Double.parseDouble(readString());
	}
	
	double[] readDoubleArray(int size) {
		double[] array = new double[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readDouble();
		}
		
		return array;
	}
	
	

		
	BigInteger readBigInteger() {
		return new BigInteger(readString());
	}
	
	BigDecimal readBigDecimal() {
		return new BigDecimal(readString());
	}
	
	

	
	Point readPoint() {
		int x = readInt();
		int y = readInt();
		return new Point(x, y);
	}
	
	Point[] readPointArray(int size) {
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
	
	IntIndexPair[] readIntIndexArray(int size) {
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
	
	

	
	static class RuntimeIOException extends RuntimeException {

		
		private static final long serialVersionUID = -6463830523020118289L;

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
	
	

	
	static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

		
		private static final long serialVersionUID = -3793737771950984481L;

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

