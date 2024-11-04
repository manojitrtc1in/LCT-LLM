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
		
		char[] digitCharacters = id8();
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
		int[] powers, id5;
		int[] id18;
		
		int[] sizes;
		int[] lefts, rights, mids;
		int[] id2, vRights;
		
		int[] id10;
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
			
			this.id5 = new int[powers.length + 1];
			id5[0] = 0;
			
			for (int power = 1; power <= powers.length; ++power) {
				id5[power] = (id5[power - 1] + powers[power - 1]) % MODULO;
			}
			
			this.id18 = new int[treeSize];
			
			this.sizes = new int[treeSize];
			
			this.id10 = new int[treeSize];
			
			this.lazyColors = new int[treeSize];
			Arrays.fill(lazyColors, -1);
			
			this.lefts = new int[treeSize];
			this.rights = new int[treeSize];
			this.mids = new int[treeSize];
			
			this.id2 = new int[treeSize];
			this.vRights = new int[treeSize];
			
			Arrays.fill(mids, treeSize);
			Arrays.fill(id2, treeSize);
			Arrays.fill(vRights, treeSize);
			
			init(1, 0, size - 1, array);
		}
		
		protected void init(int v, int left, int right, int[] array) {
			lefts[v] = left;
			rights[v] = right;
			
			id18[v] = (id5[rights[v] + 1] - id5[lefts[v]] + MODULO) % MODULO;
			
			if (left == right) {
				id10[v] = (int)((1L * array[left] * powers[left]) % MODULO);  
			} else {
				int mid = mids[v] = (left + right) >> 1;
			
				int vLeft = id2[v] = (v << 1);
				int vRight = vRights[v] = (vLeft + 1);
				
				init(vLeft, left, mid, array);
				init(vRight, mid + 1, right, array);
				
				id10[v] = (id10[vLeft] + id10[vRight]) % MODULO;
			}
		}
		
		protected void push(int v) {
			int color = lazyColors[v];
			if (color != -1) {
				
				id10[v] = (int)((1L * color * id18[v]) % MODULO);
				
				int vLeft = id2[v];
				int vRight = vRights[v];
				
				if (vRight < treeSize) {
					lazyColors[vLeft] = color;


					
					lazyColors[vRight] = color;


				}
				
				lazyColors[v] = -1;
			}
		}
		
		protected void update(int v) {
			int vLeft = id2[v];
			int vRight = vRights[v];
			
			push(vLeft);
			push(vRight);
			
			id10[v] = (id10[vLeft] + id10[vRight]) % MODULO;
		}
		
		public boolean isPeriod(int left, int right, int delta) {
			int size = (right - left + 1);
			
			boolean leftResult = id29(left, right - size % delta - delta, left + delta, right - size % delta);
			boolean rightResult = id29(left + size % delta, right - delta, left + size % delta + delta, right);
			
			boolean isPeriod = (leftResult & rightResult);
			if (size % delta != 0) {
				isPeriod &= id29(left, left + size % delta - 1, right - size % delta + 1, right);
			}
			
			return isPeriod;
		}
		
		protected boolean id29(int l1, int r1, int l2, int r2) {
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
			
			push(v);
			
			if (left == qLeft && right == qRight) {
				return id10[v];
			} else {


				
				int mid = mids[v];
				
				int vLeft = id2[v];
				int vRight = vRights[v];
				
				int id28 = (qLeft <= mid ? get(vLeft, qLeft, min(mid, qRight)) : 0);
				int id21 = (qRight > mid ? get(vRight, max(qLeft, mid + 1), qRight) : 0);
				
				int hashSum = (id28 + id21) % MODULO;
				
				update(v);
				
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


				push(v);
			} else {
				push(v);
				
				int mid = mids[v];
				
				int vLeft = id2[v];
				int vRight = vRights[v];
				
				if (qLeft <= mid) set(vLeft, qLeft, min(mid, qRight), color);
				if (qRight > mid) set(vRight, max(qLeft, mid + 1), qRight, color);
				
				update(v);
			}
		}
	}
	
	

	
	final boolean id9 = System.getProperty("id9") != null;
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new E(), "", 128 * (1L << 20)).start();
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
			
			if (id9) {
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
	
	

	
	final char id7 = '\0';
	
	char readChar() throws IOException{
		int intValue = in.read();
		
		if (intValue == -1){
			return id7;
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
	
	int[] id12(int size) throws IOException {
		int[] array = id1(size);
		
		for (int i = 0; i < size; ++i) {
			array[i]--;
		}
		
		return array;
	}
	
	

	
	int[][] id16(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id1(columnsCount);
		}
		
		return matrix;
	}
	
	int[][] id23(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id12(columnsCount);
		}
		
		return matrix;
	}
	
	

	
	long readLong() throws IOException{
		return Long.parseLong(readString());
	}
	
	long[] id13(int size) throws IOException{
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
	
	

		
	BigInteger id20() throws IOException {
		return new BigInteger(readString());
	}
	
	BigDecimal id19() throws IOException {
		return new BigDecimal(readString());
	}
	
	

	
	Point readPoint() throws IOException{
		int x = readInt();
		int y = readInt();
		return new Point(x, y);
	}
	
	Point[] id25(int size) throws IOException{
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
	
	

	
	static class id22 {
		
		static Comparator<id22> increaseComparator = new Comparator<id22>() {
			
			@Override
			public int compare(id22 id17, id22 id14) {
				int value1 = id17.value;
				int value2 = id14.value;
				
				if (value1 != value2) return value1 - value2;
				
				int index1 = id17.index;
				int index2 = id14.index;
				
				return index1 - index2;
			}
		};
		
		static Comparator<id22> id0 = new Comparator<id22>() {
			
			@Override
			public int compare(id22 id17, id22 id14) {
				int value1 = id17.value;
				int value2 = id14.value;
				
				if (value1 != value2) return -(value1 - value2);
				
				int index1 = id17.index;
				int index2 = id14.index;
				
				return index1 - index2;
			}
		};
		
		int value, index;

		public id22(int value, int index) {
			super();
			this.value = value;
			this.index = index;
		}		
		
		public int id6() {
			return index + 1;
		}
	}
	
	id22[] id3(int size) throws IOException {
		id22[] array = new id22[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = new id22(readInt(), index);
		}
		
		return array;
	}
	
	

	
	static class OutputWriter extends PrintWriter {

		final int id27 = 12;
		
		protected int precision;
		protected String format, id26;
		
		{
			precision = id27;
			
			format = createFormat(precision);
			id26 = format + " ";
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
			id26 = format + " ";
		}
		
		private String createFormat(int precision){
			return "%." + precision + "f";
		}
		
		@Override
		public void print(double d){
			printf(format, d);
		}
		
		public void id24(double d){
			printf(id26, d);
		}

		public void printAll(double...d){
			for (int i = 0; i < d.length - 1; ++i){
				id24(d[i]);
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
	
	static final Point id15(int[] array) {
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

