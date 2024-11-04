import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;




public class E implements Runnable{
	
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
		
		static Comparator<IntIndexPair> increaseComparator = new Comparator<E.IntIndexPair>() {
			
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
		
		static Comparator<IntIndexPair> decreaseComparator = new Comparator<E.IntIndexPair>() {
			
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
	
	

	
	class Edge {
		int from, to;
		int flow, capacity;
		int cost;
		
		Edge reverseEdge;

		public Edge(int from, int to, int capacity, int cost) {
			super();
			this.from = from;
			this.to = to;
			
			this.flow = 0;
			this.capacity = capacity;
			
			this.cost = cost;
		}
		
		public Edge setReverseEdge(Edge reverseEdge) {
			this.reverseEdge = reverseEdge;
			
			return this;
		}
	}
	
	List<Edge>[] graph;
	List<Edge> edges;
	
	@SuppressWarnings("unchecked")
	void solve() throws IOException {
		int arraySize = readInt();
		int variablesCount = readInt();
		
		int graphSize = variablesCount + 2 * (arraySize) + 2;
		
		int start = graphSize - 2;
		int end = start + 1;
		
		graph = new List[graphSize];
		for (int v = 0; v < graphSize; ++v) {
			graph[v] = new ArrayList<E.Edge>();
		}
		
		edges = new ArrayList<E.Edge>();
		
		int[] array = readIntArray(arraySize);
		
		int[] bitCounts = new int[arraySize];
		for (int index = 0; index < arraySize; ++index) {
			bitCounts[index] = Integer.bitCount(array[index]);
		}
		
		int variableStart = 0, variableEnd = variableStart + variablesCount - 1;
		int reAssignElementStart = variableEnd + 1, reAssignElementEnd = reAssignElementStart + arraySize - 1;
		int assignElementStart = reAssignElementEnd + 1, assignElementEnd = assignElementStart + arraySize - 1;
		
		for (int variable = variableStart; variable <= variableEnd; ++variable) {
			addEdge(start, variable, 0);
			
			for (int index = 0, assignElement = assignElementStart; index < arraySize && assignElement <= assignElementEnd; ++index, ++assignElement) {
				addEdge(variable, assignElement, bitCounts[index]);
			}
		}
		
		for (int index = 0, reAssignElement = reAssignElementStart; index < arraySize && reAssignElement <= reAssignElementEnd; ++index, ++reAssignElement) {
			addEdge(start, reAssignElement, 0);
			
			int value = array[index];
			for (int otherIndex = index + 1, assignElement = assignElementStart + index + 1; otherIndex < arraySize && assignElement <= assignElementEnd; ++otherIndex, ++assignElement) {
				int cost = (value == array[otherIndex] ? 0 : bitCounts[otherIndex]);
				addEdge(reAssignElement, assignElement, cost);
			}
		}
		
		for (int assignElement = assignElementStart; assignElement <= assignElementEnd; ++assignElement) {
			addEdge(assignElement, end, 0);
		}
		
		Collections.sort(
				edges,
				new Comparator<Edge>() {

					@Override
					public int compare(Edge first, Edge second) {
						return first.cost - second.cost;
					}
					
				}
		);
		
		int totalCost = minCostMaxFlow(start, end);
		
		int[] usedVariables = new int[arraySize];
		
		List<Point> answer = new ArrayList<Point>();
		for (int index = 0, assignElement = assignElementStart; index < arraySize && assignElement <= assignElementEnd; ++index, ++assignElement) {
			for (Edge edge : graph[assignElement]) {
				if (edge.flow == 0 || edge.capacity > 0) continue;
				

				
				int to = edge.to;
				if (variableStart <= to && to <= variableEnd) {
					int variable = to - variableStart;
					usedVariables[index] = variable;
					
					answer.add(new Point(usedVariables[index], index));
				}
				
				if (reAssignElementStart <= to && to <= reAssignElementEnd) {
					int prev = to - reAssignElementStart;
					usedVariables[index] = usedVariables[prev];
					
					if (array[prev] != array[index]) {
						answer.add(new Point(usedVariables[index], index));
					}
				}
				
				answer.add(new Point(usedVariables[index], -1));
			}
		}
		
		out.println(answer.size() + " " + totalCost);
		for (Point operation : answer) {
			char variable = (char) (operation.x + 'a');
			int index = operation.y;
			
			if (index == -1) {
				out.println("print(" + variable + ")");
			} else {
				out.println(variable + "=" + array[index]);
			}
		}
	}
	
	int minCostMaxFlow(int start, int end) {
		int totalCost = 0;
		
		int[] phi = new int[graph.length];
		fordBellman(start, phi);
		
		for (int curCost = dijkstra(start, end, phi); curCost != INF; curCost = dijkstra(start, end, phi)) {
			totalCost += curCost;
		}
		
		return totalCost;
	}
	
	
	
	final int INF = 1000000;

	
	void fordBellman(int start, int[] distances) {
		int graphSize = graph.length;
		
		Arrays.fill(distances, INF);
		distances[start] = 0;
		
		for (int it = 0; it < graphSize; ++it) {
			boolean changed = false;
			
			for (Edge edge : edges) {
				if (edge.flow == edge.capacity) continue;
				
				int from = edge.from;
				int to = edge.to;
				
				if (distances[from] == INF) continue;
				
				if (distances[to] > distances[from] + edge.cost) {
					distances[to] = distances[from] + edge.cost;
				
					changed = true;
				}
			}
			
			if (!changed) break;
		}
	}
	
	int dijkstra(int start, int end, int[] phi) {
		int graphSize = graph.length;
		
		int[] distances = new int[graphSize];
		Arrays.fill(distances, INF);
		
		Edge[] parentEdges = new Edge[graphSize];
		
		int[] maxFlows = new int[graphSize];
		Arrays.fill(maxFlows, INF);
		
		boolean[] used = new boolean[graphSize];
		
		distances[start] = 0;
		for (int iteration = 0; iteration < graphSize; ++iteration) {
			int from = -1;
			
			for (int v = 0; v < graphSize; ++v) {
				if (!used[v] && distances[v] < INF && (from == -1 || distances[from] > distances[v])) {
					from = v;
				}
			}
			
			if (from == -1) break;
			used[from] = true;
			
			for (Edge edge : graph[from]) {
				if (edge.flow < edge.capacity) {
					int to = edge.to;
					
					if (!used[to] && distances[to] > distances[from] + phi[from] - phi[to] + edge.cost) {
						distances[to] = distances[from] + phi[from] - phi[to] + edge.cost;
						parentEdges[to] = edge;
						maxFlows[to] = min(maxFlows[from], edge.capacity - edge.flow);
					}
				}
			}
		}
		
		if (distances[end] == INF) return INF;
		
		for (int v = 0; v < graphSize; ++v) {
			phi[v] += used[v] ? distances[v] : distances[end];
		}
		
		int endFlow = maxFlows[end];
		int curCost = 0;
		
		for (int cur = end; parentEdges[cur] != null; cur = parentEdges[cur].from) {
			Edge parentEdge = parentEdges[cur];
			parentEdge.flow += endFlow;
			
			curCost += parentEdge.cost * endFlow;
			
			Edge reverseEdge = parentEdge.reverseEdge;
			reverseEdge.flow -= endFlow;
		}
		
		return curCost;
	}
	
	void addEdge(int from, int to, int cost) {
		Edge fromToEdge = new Edge(from, to, 1, cost);
		Edge toFromEdge = new Edge(to, from, 0, -cost);
		
		graph[from].add(fromToEdge.setReverseEdge(toFromEdge));
		graph[to].add(toFromEdge.setReverseEdge(fromToEdge));
		
		edges.add(fromToEdge);
		edges.add(toFromEdge);
	}
}

