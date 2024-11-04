import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;




public class D implements Runnable{
	
	final boolean id9 = System.getProperty("id9") != null;
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new D(), "", 128 * (1L << 20)).start();
	}
	
	

	
	void init() throws FileNotFoundException{
		Locale.setDefault(Locale.US);
		
		if (id9){
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
		if (id9){
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
	
	char[] id8() throws IOException{
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
	
	int[] id11(int size) throws IOException {
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
	
	int[] id13(int size) throws IOException {
		int[] array = id1(size);
		
		for (int i = 0; i < size; ++i) {
			array[i]--;
		}
		
		return array;
	}
	
	

	
	int[][] id17(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id1(columnsCount);
		}
		
		return matrix;
	}
	
	int[][] id25(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id13(columnsCount);
		}
		
		return matrix;
	}
	
	

	
	long readLong() throws IOException{
		return Long.parseLong(readString());
	}
	
	long[] id14(int size) throws IOException{
		long[] array = new long[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readLong();
		}
		
		return array;
	}
	
	

	
	double readDouble() throws IOException{
		return Double.parseDouble(readString());
	}
	
	double[] id4(int size) throws IOException{
		double[] array = new double[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readDouble();
		}
		
		return array;
	}
	
	

		
	BigInteger id22() throws IOException {
		return new BigInteger(readString());
	}
	
	BigDecimal id21() throws IOException {
		return new BigDecimal(readString());
	}
	
	

	
	Point readPoint() throws IOException{
		int x = readInt();
		int y = readInt();
		return new Point(x, y);
	}
	
	Point[] id28(int size) throws IOException{
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
	
	

	
	static class id24 {
		
		static Comparator<id24> increaseComparator = new Comparator<id24>() {
			
			@Override
			public int compare(id24 id20, id24 id15) {
				int value1 = id20.value;
				int value2 = id15.value;
				
				if (value1 != value2) return value1 - value2;
				
				int index1 = id20.index;
				int index2 = id15.index;
				
				return index1 - index2;
			}
		};
		
		static Comparator<id24> id0 = new Comparator<id24>() {
			
			@Override
			public int compare(id24 id20, id24 id15) {
				int value1 = id20.value;
				int value2 = id15.value;
				
				if (value1 != value2) return -(value1 - value2);
				
				int index1 = id20.index;
				int index2 = id15.index;
				
				return index1 - index2;
			}
		};
		
		int value, index;

		public id24(int value, int index) {
			super();
			this.value = value;
			this.index = index;
		}		
		
		public int id5() {
			return index + 1;
		}
	}
	
	id24[] id3(int size) throws IOException {
		id24[] array = new id24[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = new id24(readInt(), index);
		}
		
		return array;
	}
	
	

	
	static class OutputWriter extends PrintWriter {

		final int id31 = 12;
		
		protected int precision;
		protected String format, id30;
		
		{
			precision = id31;
			
			format = createFormat(precision);
			id30 = format + " ";
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
			id30 = format + " ";
		}
		
		private String createFormat(int precision){
			return "%." + precision + "f";
		}
		
		@Override
		public void print(double d){
			printf(format, d);
		}
		
		public void id26(double d){
			printf(id30, d);
		}

		public void printAll(double...d){
			for (int i = 0; i < d.length - 1; ++i){
				id26(d[i]);
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
	
	static final Point id16(int[] array) {
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
		id29 = '(', 
		NONE_SIGN = '?', 
		id32 = ')';
	
	final static String id12 = "" + id29 + NONE_SIGN + id32;
	
	final static int 
		OPENED = id12.indexOf(id29),
		NONE = id12.indexOf(NONE_SIGN),
		CLOSED = id12.indexOf(id32);
	
	final static int[] STATES = { OPENED, NONE, CLOSED };
	final static int id19 = STATES.length;
	
	final static int[] id23 = { 1, 0, -1 };
	
	final static long INF = 1000L * 1000 * 1000 * 1000;
	
	static class id2 extends AbstractMap.SimpleEntry<Long, Integer> {

		
		private static final long id27 = -4326518412082051685L;

		public id2(Long key, Integer value) {
			super(key, value);
		}
	}
	
	static class id7 extends TreeMap<Long, TreeSet<Integer>> {
		
		final static id2 EMPTY = new id2(INF, -1);
		
		
		private static final long id27 = 7671098813940210758L;

		protected int size;
		
		public id7() {
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
		
		public id2 pollFirst() {
			if (size() == 0) {
				return EMPTY;
			}
			
			Map.Entry<Long, TreeSet<Integer>> firstEntry = firstEntry();
			
			long firstValue = firstEntry.getKey();
			int firstIndex = firstEntry.getValue().first();
			
			remove(firstValue, firstIndex);
			
			return new id2(firstValue, firstIndex);
		}
	}
	
	void solve() throws IOException {
		char[] sequence = id8();
		int n = sequence.length;
		
		int[] states = new int[n];
		for (int i = 0; i < n; ++i) {
			states[i] = id12.indexOf(sequence[i]);
		}
		
		int id10 = 0;
		for (int state : states) {
			id10 += (state == NONE ? 1 : 0);
		}
		
		Point[] noneCosts = id28(id10);
		
		long[][] costs = new long[id19][n];
		for (int i = 0, noneIndex = 0; i < n; ++i) {
			costs[1][i] = INF;
			
			if (states[i] == 1) {
				costs[OPENED][i] = noneCosts[noneIndex].x;
				costs[CLOSED][i] = noneCosts[noneIndex].y;
				
				++noneIndex;
			} else {
				costs[states[i]][i] = 0;
				costs[id19 - 1 - states[i]][i] = INF;
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
				out.print(id12.charAt(states[i]));
			}
			out.println();
		}
	}
	
	void mirroring(int n, int[] states, long[] changeCosts) {
		int[] newStates = new int[n];
		long[] id18 = new long[n];
		
		for (int i = 0, j = n - 1; i < n; ++i, --j) {
			newStates[j] = id19 - 1 - states[i];
			id18[j] = changeCosts[i];
		}
		
		for (int i = 0; i < n; ++i) {
			states[i] = newStates[i];
			changeCosts[i] = id18[i];
		}
	}

	int balancing(int n, int[] states, long[] changeCosts) {
		id7 suffixOpened = new id7();
		id7 prefixClosed = new id7();
		
		for (int i = n - 1; i >= 0; --i) {
			if (states[i] == OPENED) {
				suffixOpened.add(changeCosts[i], i);
			}
		}
		
		int balance = 0;
		for (int i = 0; i < n; ++i) {
			balance += id23[states[i]];
			
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
				
				balance += id23[OPENED] - id23[CLOSED];
			}
		}
		
		return balance;
	}

	boolean balancing(id7 oldStates, int newState,
			int[] states, long[] changeCosts) {
		id2 first = oldStates.pollFirst();
		
		if (first.getKey().equals(INF)) {
			return false;
		}
		
		int index = first.getValue();
		
		states[index] = newState;
		changeCosts[index] = -changeCosts[index];
		
		return true;
	}

	boolean equalization(int n, int[] states, long[] changeCosts) {
		id7 opened = new id7();
		id7 closed = new id7();
		
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

	boolean equalization(id7 small, id7 large,
			int[] states, long[] changeCosts, int smallState) {
		while (small.size() < large.size()) {
			id2 firstLarge = large.pollFirst();
			
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

