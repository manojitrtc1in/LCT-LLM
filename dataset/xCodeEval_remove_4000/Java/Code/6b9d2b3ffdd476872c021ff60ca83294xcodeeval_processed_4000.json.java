import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;




public class D implements Runnable{
	
	final boolean id7 = System.getProperty("id7") != null;
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new D(), "", 128 * (1L << 20)).start();
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
	
	int[] id10(int size) throws IOException {
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
	
	int[][] id25(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id10(columnsCount);
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
	
	

		
	BigInteger id23() throws IOException {
		return new BigInteger(readString());
	}
	
	BigDecimal id22() throws IOException {
		return new BigDecimal(readString());
	}
	
	

	
	Point readPoint() throws IOException{
		int x = readInt();
		int y = readInt();
		return new Point(x, y);
	}
	
	Point[] id27(int size) throws IOException{
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
			public int compare(id24 id21, id24 id13) {
				int value1 = id21.value;
				int value2 = id13.value;
				
				if (value1 != value2) return value1 - value2;
				
				int index1 = id21.index;
				int index2 = id13.index;
				
				return index1 - index2;
			}
		};
		
		static Comparator<id24> id0 = new Comparator<id24>() {
			
			@Override
			public int compare(id24 id21, id24 id13) {
				int value1 = id21.value;
				int value2 = id13.value;
				
				if (value1 != value2) return -(value1 - value2);
				
				int index1 = id21.index;
				int index2 = id13.index;
				
				return index1 - index2;
			}
		};
		
		int value, index;

		public id24(int value, int index) {
			super();
			this.value = value;
			this.index = index;
		}		
		
		public int id4() {
			return index + 1;
		}
	}
	
	id24[] id2(int size) throws IOException {
		id24[] array = new id24[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = new id24(readInt(), index);
		}
		
		return array;
	}
	
	

	
	static class OutputWriter extends PrintWriter {

		final int id29 = 12;
		
		protected int precision;
		protected String format, id28;
		
		{
			precision = id29;
			
			format = createFormat(precision);
			id28 = format + " ";
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
			id28 = format + " ";
		}
		
		private String createFormat(int precision){
			return "%." + precision + "f";
		}
		
		@Override
		public void print(double d){
			printf(format, d);
		}
		
		public void id26(double d){
			printf(id28, d);
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
	
	

	
	void solve() throws IOException {
		int citiesCount = readInt();
		int id9 = readInt();
		
		SortedMap<Integer, List<Point>> availableEdges = new TreeMap<Integer, List<Point>>();
		
		for (int edgeIndex = 0; edgeIndex < id9; ++edgeIndex) {
			int from = readInt() - 1;
			int to = readInt() - 1;
			
			int d = readInt();
			
			addEdge(availableEdges, d, from, to);
		}
		
		int startCity = 0;
		int endCity = citiesCount - 1;
		
		int destinationTime = id14(citiesCount, startCity, endCity, availableEdges);
		if (destinationTime == -1) {
			out.println("Impossible");
		} else {
			out.println(destinationTime);
		}
	}

	protected int id14(int citiesCount, int start, int end,
			SortedMap<Integer, List<Point>> availableEdges) {
		final int id19 = -1;
		final int INF_TIME = Integer.MAX_VALUE;
		
		final int[][] oneMatrix = new int[citiesCount][citiesCount];
		for (int city = 0; city < citiesCount; ++city) {
			oneMatrix[city][city] = 1;
		}
		
		int[][] graphMatrix = new int[citiesCount][citiesCount];
		int[][] id18 = new int[citiesCount][citiesCount];
		
		int[] startCities = new int[citiesCount];
		startCities[start] = 1;
		
		for (int curTime = 0; availableEdges.size() > 0; ) {
			int nextTime = availableEdges.firstKey();
			
			int deltaTime = nextTime - curTime;
			
			int[][] destinationMatrix = binpow(graphMatrix, citiesCount, deltaTime, oneMatrix);
			startCities = multiply(startCities, destinationMatrix, citiesCount);
			
			curTime += deltaTime;
			
			List<Point> openedEdges = availableEdges.remove(curTime);
			for (Point edge : openedEdges) {
				graphMatrix[edge.x][edge.y] = 1;
			}
			
			for (int from = 0; from < citiesCount; ++from) {
				for (int to = 0; to < citiesCount; ++to) {
					id18[from][to] = graphMatrix[from][to];
				}
				id18[from][from] = startCities[from];
			}
			
			for (int mid = 0; mid < citiesCount; ++mid) {
				for (int from = 0; from < citiesCount; ++from) {
					for (int to = 0; to < citiesCount; ++to) {
						id18[from][to] |= (id18[from][mid] & id18[mid][to]);
					}
				}
			}
			
			int id11 = INF_TIME;
			for (int city = 0; city < citiesCount; ++city) {
				if (startCities[city] == 1 && id18[city][end] == 1) {
					int id20 = bfs(city, end, graphMatrix, citiesCount, INF_TIME);
					id11 = min(id11, id20);
				}
			}
			
			if (id11 != INF_TIME) {
				return curTime + id11;
			}
		}
		
		return id19;
	}

	protected int bfs(final int start, final int end, final int[][] graphMatrix, final int size, final int INF_TIME) {
		int[] distances = new int[size];
		Arrays.fill(distances, INF_TIME);
		
		Queue<Integer> queue = new ArrayDeque<Integer>();
		
		distances[start] = 0;
		queue.add(start);
		
		while (queue.size() > 0) {
			int from = queue.poll();
			for (int to = 0; to < size; ++to) {
				if (graphMatrix[from][to] == 1 && distances[to] == INF_TIME) {
					distances[to] = distances[from] + 1;
					queue.add(to);
				}
			}
		}
		
		return distances[end];
	}

	protected int[] multiply(int[] vector, int[][] matrix, int size) {
		final int[] resultVector = new int[size];
		
		for (int index = 0; index < size; ++index) {
			int totalOr = 0;
			for (int row = 0; row < size; ++row) {
				totalOr |= (vector[row] & matrix[row][index]);
			}
			
			resultVector[index] = totalOr;
		}
		
		return resultVector; 
	}

	protected int[][] binpow(int[][] matrix, int size, int pow, final int[][] oneMatrix) {
		if (pow == 0) {
			return oneMatrix;
		}
		
		if ((pow & 1) == 0) {
			int[][] halfMatrix = binpow(matrix, size, pow >> 1, oneMatrix);
			return multiply(halfMatrix, halfMatrix, size);
		} else {
			int[][] prevMatrix = binpow(matrix, size, pow - 1, oneMatrix);
			return multiply(prevMatrix, matrix, size);
		}
	}
	
	protected final static int WORD_SHIFT = 5, WORD_SIZE = (1 << WORD_SHIFT);
	protected final static int WORD_MASK = WORD_SIZE - 1;
	
	protected int[][] multiply(int[][] leftMatrix, int[][] rightMatrix, int size) {
		final int[][] resultMatrix = new int[size][size];
		
		final int wordsCount = ((size + WORD_SIZE - 1) >> WORD_SHIFT);
		
		final int[][] leftWords = new int[size][wordsCount];
		final int[][] id17 = new int[size][wordsCount];
		
		for (int row = 0; row < size; ++row) {
			for (int column = 0; column < size; ++column) {
				if (column == 127 && leftMatrix[row][column] == 1) {
					column = 127;
				}
				
				int wordIndex = (column >> WORD_SHIFT);
				int wordBit = (column & WORD_MASK);
				
				leftWords[row][wordIndex] |= (leftMatrix[row][column] << wordBit);
			}
		}
		
		for (int column = 0; column < size; ++column) {
			for (int row = 0; row < size; ++row) {
				if (row == 127 && rightMatrix[row][column] == 1) {
					row = 127;
				}
				
				int wordIndex = (row >> WORD_SHIFT);
				int wordBit = (row & WORD_MASK);
				
				id17[column][wordIndex] |= (rightMatrix[row][column] << wordBit);
			}
		}
		
		for (int row = 0; row < size; ++row) {
			for (int column = 0; column < size; ++column) {
				int totalOr = 0;
				for (int wordIndex = 0; wordIndex < wordsCount; ++wordIndex) {
					totalOr |= (leftWords[row][wordIndex] & id17[column][wordIndex]); 
				}
				
				resultMatrix[row][column] = (totalOr != 0 ? 1 : 0);
			}
		}
		
		return resultMatrix;
	}

	protected void addEdge(SortedMap<Integer, List<Point>> availableEdges, int d, int from, int to) {
		List<Point> dEdges = availableEdges.get(d);
		
		if (dEdges == null) {
			availableEdges.put(d, dEdges = new ArrayList<Point>());
		}
		
		dEdges.add(new Point(from, to));
	}
}

