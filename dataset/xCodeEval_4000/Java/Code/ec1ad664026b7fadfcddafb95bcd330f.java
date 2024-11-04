import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;




public class D implements Runnable{
	
	final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new D(), "", 128 * (1L << 20)).start();
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
	
	

	
	final static char 
		OPENED_SIGN = '(', 
		NONE_SIGN = '?', 
		CLOSED_SIGN = ')';
	
	final static String STATE_SIGNS = "" + OPENED_SIGN + NONE_SIGN + CLOSED_SIGN;
	
	final static int 
		OPENED = STATE_SIGNS.indexOf(OPENED_SIGN),
		NONE = STATE_SIGNS.indexOf(NONE_SIGN),
		CLOSED = STATE_SIGNS.indexOf(CLOSED_SIGN);
	
	final static int[] STATES = { OPENED, NONE, CLOSED };
	final static int STATES_COUNT = STATES.length;
	
	final static int[] BALANCE_DELTAS = { 1, 0, -1 };
	
	final static long INF = 1000L * 1000 * 1000 * 1000;
	
	static class ValueIndexPair extends AbstractMap.SimpleEntry<Long, Integer> {

		
		private static final long serialVersionUID = -4326518412082051685L;

		public ValueIndexPair(Long key, Integer value) {
			super(key, value);
		}
	}
	
	static class MultiIndexedTreeSet extends TreeMap<Long, TreeSet<Integer>> {
		
		final static ValueIndexPair EMPTY = new ValueIndexPair(INF, -1);
		
		
		private static final long serialVersionUID = 7671098813940210758L;

		protected int size;
		
		public MultiIndexedTreeSet() {
			super();
			
			size = 0;
		}
		
		@Override
		public int size() {
			return size;
		}
		
		public void add(long value, int index) {
			TreeSet<Integer> indexes = get(value);
			if (indexes == null) {
				put(value, indexes = new TreeSet<Integer>());
			}
			
			indexes.add(index);
			++size;
		}
		
		public void remove(long value, int index) {
			TreeSet<Integer> indexes = get(value);
			indexes.remove(index);
			
			if (indexes.size() == 0) {
				remove(value);
			};
			
			--size;
		}
		
		public ValueIndexPair pollFirst() {
			if (size() == 0) {
				return EMPTY;
			}
			
			Map.Entry<Long, TreeSet<Integer>> firstEntry = firstEntry();
			
			long firstValue = firstEntry.getKey();
			int firstIndex = firstEntry.getValue().first();
			
			remove(firstValue, firstIndex);
			
			return new ValueIndexPair(firstValue, firstIndex);
		}
	}
	
	void solve() throws IOException {
		char[] sequence = readCharArray();
		int n = sequence.length;
		
		int[] states = new int[n];
		for (int i = 0; i < n; ++i) {
			states[i] = STATE_SIGNS.indexOf(sequence[i]);
		}
		
		int nonesCount = 0;
		for (int state : states) {
			nonesCount += (state == NONE ? 1 : 0);
		}
		
		Point[] noneCosts = readPointArray(nonesCount);
		
		long[][] costs = new long[STATES_COUNT][n];
		for (int i = 0, noneIndex = 0; i < n; ++i) {
			costs[1][i] = INF;
			
			if (states[i] == 1) {
				costs[OPENED][i] = noneCosts[noneIndex].x;
				costs[CLOSED][i] = noneCosts[noneIndex].y;
				
				++noneIndex;
			} else {
				costs[states[i]][i] = 0;
				costs[STATES_COUNT - 1 - states[i]][i] = INF;
			}
		}

		long[] changeCosts = new long[n];
		for (int i = 0; i < n; ++i) {
			int minState = NONE;
			for (int state : STATES) {
				if (costs[minState][i] > costs[state][i]) {
					minState = state;
				}
			}
			
			states[i] = minState;
			changeCosts[i] = abs(costs[OPENED][i] - costs[CLOSED][i]);
		}
		
		if (!equalization(n, states, changeCosts)) {
			out.println(-1);
			return;
		}
		
		int balance = balancing(n, states, changeCosts); 
		if (balance > 0) {
			mirroring(balance, states, changeCosts);
			
			balance = balancing(n, states, changeCosts);
			
			mirroring(balance, states, changeCosts);
		}
		
		if (balance < 0) {
			out.println(-1);
			return;
		}
		
		long totalCost = 0;
		for (int i = 0; i < n; ++i) {
			totalCost += costs[states[i]][i];
		}
		
		if (totalCost >= INF) {
			out.println(-1);
		} else {
			out.println(totalCost);
			for (int i = 0; i < n; ++i) {
				out.print(STATE_SIGNS.charAt(states[i]));
			}
			out.println();
		}
	}
	
	void mirroring(int n, int[] states, long[] changeCosts) {
		int[] newStates = new int[n];
		long[] newChangeCosts = new long[n];
		
		for (int i = 0, j = n - 1; i < n; ++i, --j) {
			newStates[j] = STATES_COUNT - 1 - states[i];
			newChangeCosts[j] = changeCosts[i];
		}
		
		for (int i = 0; i < n; ++i) {
			states[i] = newStates[i];
			changeCosts[i] = newChangeCosts[i];
		}
	}

	int balancing(int n, int[] states, long[] changeCosts) {
		MultiIndexedTreeSet suffixOpened = new MultiIndexedTreeSet();
		MultiIndexedTreeSet prefixClosed = new MultiIndexedTreeSet();
		
		for (int i = n - 1; i >= 0; --i) {
			if (states[i] == OPENED) {
				suffixOpened.add(changeCosts[i], i);
			}
		}
		
		int balance = 0;
		for (int i = 0; i < n; ++i) {
			balance += BALANCE_DELTAS[states[i]];
			
			if (states[i] == CLOSED) {
				prefixClosed.add(changeCosts[i], i);
			}
			
			if (states[i] == OPENED) {
				suffixOpened.remove(changeCosts[i], i);
			}
			
			while (balance < 0) {
				if (!balancing(prefixClosed, OPENED, states, changeCosts)
						||
					!balancing(suffixOpened, CLOSED, states, changeCosts)) {
					return -1;
				}
				
				balance += BALANCE_DELTAS[OPENED] - BALANCE_DELTAS[CLOSED];
			}
		}
		
		return balance;
	}

	boolean balancing(MultiIndexedTreeSet oldStates, int newState,
			int[] states, long[] changeCosts) {
		ValueIndexPair first = oldStates.pollFirst();
		
		if (first.getKey().equals(INF)) {
			return false;
		}
		
		int index = first.getValue();
		
		states[index] = newState;
		changeCosts[index] = -changeCosts[index];
		
		return true;
	}

	boolean equalization(int n, int[] states, long[] changeCosts) {
		MultiIndexedTreeSet opened = new MultiIndexedTreeSet();
		MultiIndexedTreeSet closed = new MultiIndexedTreeSet();
		
		for (int i = 0; i < n; ++i) {
			if (states[i] == OPENED) {
				opened.add(changeCosts[i], i);
			} else {
				closed.add(changeCosts[i], i);
			}
		}
		
		if (!equalization(opened, closed, states, changeCosts, OPENED)
				||
			!equalization(closed, opened, states, changeCosts, CLOSED)) {
			
			return false;
		}
		
		return true;
	}

	boolean equalization(MultiIndexedTreeSet small, MultiIndexedTreeSet large,
			int[] states, long[] changeCosts, int smallState) {
		while (small.size() < large.size()) {
			ValueIndexPair firstLarge = large.pollFirst();
			
			int index = firstLarge.getValue();
			if (changeCosts[index] == INF) {
				return false;
			}
			
			changeCosts[index] = -changeCosts[index];
			states[index] = smallState;
			
			small.add(changeCosts[index], index);
		}
		
		return true;
	}
}

