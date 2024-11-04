import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;


public class E implements Runnable{
	
	

	

	

	

	

	void solve() throws IOException {
		int n = readInt();
		int queriesCount = readInt() + readInt();
		
		int[] digits = new int[n];
		
		char[] digitCharacters = readCharArray();
		for (int i = 0; i < n; ++i) {
			digits[i] = digitCharacters[i] - '0' + 1;
		}
		
		SegmentTree tree = new SegmentTree(digits);
		
		final int CHANGE = 1, CHECK = 2;
		
		while (queriesCount --> 0) {
			int type = readInt();
			int left = readInt() - 1; 
			int right = readInt() - 1;
			int value = readInt();
			
			if (type == CHANGE) {
				tree.set(left, right, value + 1);
			} else if (type == CHECK) {
				boolean result = tree.isPeriod(left, right, value);
				out.println(result ? "YES" : "NO");
			}
		}
	}
	
	static class SegmentTree {
		static final int PRIME = 13, MODULO = 59815783;
		
		int size, treeSize;
		int[] powers, prefixPowerSums;
		int[] hashSegmentSums;
		
		int[] sizes;
		int[] lefts, rights, mids;
		int[] vLefts, vRights;
		
		int[] hashSums;
		int[] periods;
		
		int[] lazyColors;
		
		SegmentTree(int[] array) {
			this.size = array.length;
			this.treeSize = (size << 2);
			
			this.powers = new int[size + 2];
			powers[0] = 1;
			
			for (int power = 1; power < powers.length; ++power) {
				powers[power] = (int)((1L * powers[power - 1] * PRIME) % MODULO);
			}
			
			this.prefixPowerSums = new int[powers.length + 1];
			prefixPowerSums[0] = 0;
			
			for (int power = 1; power <= powers.length; ++power) {
				prefixPowerSums[power] = (prefixPowerSums[power - 1] + powers[power - 1]) % MODULO;
			}
			
			this.hashSegmentSums = new int[treeSize];
			
			this.sizes = new int[treeSize];
			
			this.hashSums = new int[treeSize];
			
			this.lazyColors = new int[treeSize];
			Arrays.fill(lazyColors, -1);
			
			this.lefts = new int[treeSize];
			this.rights = new int[treeSize];
			this.mids = new int[treeSize];
			
			this.vLefts = new int[treeSize];
			this.vRights = new int[treeSize];
			
			Arrays.fill(mids, treeSize);
			Arrays.fill(vLefts, treeSize);
			Arrays.fill(vRights, treeSize);
			
			init(1, 0, size - 1, array);
		}
		
		protected void init(int v, int left, int right, int[] array) {
			lefts[v] = left;
			rights[v] = right;
			
			hashSegmentSums[v] = (prefixPowerSums[rights[v] + 1] - prefixPowerSums[lefts[v]] + MODULO) % MODULO;
			
			if (left == right) {
				hashSums[v] = (int)((1L * array[left] * powers[left]) % MODULO);  
			} else {
				int mid = mids[v] = (left + right) >> 1;
			
				int vLeft = vLefts[v] = (v << 1);
				int vRight = vRights[v] = (vLeft + 1);
				
				init(vLeft, left, mid, array);
				init(vRight, mid + 1, right, array);
				
				hashSums[v] = (hashSums[vLeft] + hashSums[vRight]) % MODULO;
			}
		}
		
		protected void push(int v) {
			int color = lazyColors[v];
			if (color != -1) {
				


				
				int vLeft = vLefts[v];
				int vRight = vRights[v];
				


					lazyColors[vLeft] = color;
					hashSums[vLeft] = (int)((1L * color * hashSegmentSums[vLeft]) % MODULO);
					
					lazyColors[vRight] = color;
					hashSums[vRight] = (int)((1L * color * hashSegmentSums[vRight]) % MODULO);


				
				lazyColors[v] = -1;
			}
		}
		


















		
		public boolean isPeriod(int left, int right, int delta) {
			int size = (right - left + 1);
			
			boolean leftResult = areEqualSubstrings(left, right - size % delta - delta, left + delta, right - size % delta);
			boolean rightResult = areEqualSubstrings(left + size % delta, right - delta, left + size % delta + delta, right);
			
			boolean isPeriod = (leftResult & rightResult);
			if (size % delta != 0) {
				isPeriod &= areEqualSubstrings(left, left + size % delta - 1, right - size % delta + 1, right);
			}
			
			return isPeriod;
		}
		
		protected boolean areEqualSubstrings(int l1, int r1, int l2, int r2) {
			long hash1 = getHash(l1, r1);
			long hash2 = getHash(l2, r2);
			
			hash1 = (hash1  % MODULO * powers[l2 - l1]) % MODULO;
			hash2 %= MODULO;
			
			return (hash1 == hash2);
		}
		
		protected int getHash(int left, int right) {
			return get(1, left, right);
		}
		
		protected int get(int v, int qLeft, int qRight) {
			int left = lefts[v];
			int right = rights[v];
			
			if (qRight < left || right < qLeft) {
				return 0;
			}
			


			
			if (left == qLeft && right == qRight) {
				return hashSums[v];
			} else {
				push(v);
				
				int mid = mids[v];
				
				int vLeft = vLefts[v];
				int vRight = vRights[v];
				
				int hashSum = -1;
				if (qRight <= mid) {
					hashSum = get(vLeft, qLeft, qRight);
				} else if (qLeft > mid) {
					hashSum = get(vRight, qLeft, qRight);
				} else {
					int leftHashSum = (qLeft <= mid ? get(vLeft, qLeft, mid) : 0);
					int rightHashSum = (qRight > mid ? get(vRight, mid + 1, qRight) : 0);
					
					hashSum = (leftHashSum + rightHashSum);

				}








				
				hashSums[v] = (hashSums[vLeft] + hashSums[vRight]) % MODULO;


				
				return hashSum;
			}
		}
		
		public void set(int left, int right, int color) {
			set(1, left, right, color);
		}
		
		protected void set(int v, int qLeft, int qRight, int color) {
			int left = lefts[v];
			int right = rights[v];
			
			if (qRight < left || right < qLeft) {
				return;
			}
			
			if (left == qLeft && right == qRight) {
				lazyColors[v] = color;
				hashSums[v] = (int)((1L * color * hashSegmentSums[v]) % MODULO);


			} else {
				push(v);
				
				int mid = mids[v];
				
				int vLeft = vLefts[v];
				int vRight = vRights[v];
				
				if (qLeft <= mid) set(vLeft, qLeft, min(mid, qRight), color);
				if (qRight > mid) set(vRight, max(qLeft, mid + 1), qRight, color);
				
				

				hashSums[v] = (hashSums[vLeft] + hashSums[vRight]) % MODULO;
			}
		}
	}
	
	

	
	final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new E(), "", 128 * (1L << 20)).start();
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
			
			if (ONLINE_JUDGE) {
				solve();
			} else {
				while (true) {
					try {
						solve();
					} catch (NumberFormatException e) {
						break;
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
}

