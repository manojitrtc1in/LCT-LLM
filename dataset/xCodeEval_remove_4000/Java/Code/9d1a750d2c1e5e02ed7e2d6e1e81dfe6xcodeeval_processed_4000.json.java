import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;




public class E implements Runnable{
	
	final boolean id7 = System.getProperty("id7") != null;
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new E(), "", 128 * (1L << 20)).start();
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
	
	int[] id11(int size) throws IOException {
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
	
	int[][] id26(int rowsCount, int columnsCount) throws IOException {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = id11(columnsCount);
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
	
	double[] id3(int size) throws IOException{
		double[] array = new double[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readDouble();
		}
		
		return array;
	}
	
	

		
	BigInteger id24() throws IOException {
		return new BigInteger(readString());
	}
	
	BigDecimal id23() throws IOException {
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
	
	

	
	static class id25 {
		
		static Comparator<id25> increaseComparator = new Comparator<E.id25>() {
			
			@Override
			public int compare(id25 id20, id25 id15) {
				int value1 = id20.value;
				int value2 = id15.value;
				
				if (value1 != value2) return value1 - value2;
				
				int index1 = id20.index;
				int index2 = id15.index;
				
				return index1 - index2;
			}
		};
		
		static Comparator<id25> id0 = new Comparator<E.id25>() {
			
			@Override
			public int compare(id25 id20, id25 id15) {
				int value1 = id20.value;
				int value2 = id15.value;
				
				if (value1 != value2) return -(value1 - value2);
				
				int index1 = id20.index;
				int index2 = id15.index;
				
				return index1 - index2;
			}
		};
		
		int value, index;

		public id25(int value, int index) {
			super();
			this.value = value;
			this.index = index;
		}		
		
		public int id4() {
			return index + 1;
		}
	}
	
	id25[] id2(int size) throws IOException {
		id25[] array = new id25[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = new id25(readInt(), index);
		}
		
		return array;
	}
	
	

	
	static class OutputWriter extends PrintWriter {

		final int id30 = 12;
		
		protected int precision;
		protected String format, id29;
		
		{
			precision = id30;
			
			format = createFormat(precision);
			id29 = format + " ";
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
			id29 = format + " ";
		}
		
		private String createFormat(int precision){
			return "%." + precision + "f";
		}
		
		@Override
		public void print(double d){
			printf(format, d);
		}
		
		public void id27(double d){
			printf(id29, d);
		}

		public void printAll(double...d){
			for (int i = 0; i < d.length - 1; ++i){
				id27(d[i]);
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
		
		public Edge id31(Edge reverseEdge) {
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
		
		int[] array = id1(arraySize);
		
		int[] bitCounts = new int[arraySize];
		for (int index = 0; index < arraySize; ++index) {
			bitCounts[index] = Integer.bitCount(array[index]);
		}
		
		int variableStart = 0, variableEnd = variableStart + variablesCount - 1;
		int id9 = variableEnd + 1, id19 = id9 + arraySize - 1;
		int id13 = id19 + 1, id12 = id13 + arraySize - 1;
		
		for (int variable = variableStart; variable <= variableEnd; ++variable) {
			addEdge(start, variable, 0);
			
			for (int index = 0, assignElement = id13; index < arraySize && assignElement <= id12; ++index, ++assignElement) {
				addEdge(variable, assignElement, bitCounts[index]);
			}
		}
		
		for (int index = 0, id18 = id9; index < arraySize && id18 <= id19; ++index, ++id18) {
			addEdge(start, id18, 0);
			
			int value = array[index];
			for (int otherIndex = index + 1, assignElement = id13 + index + 1; otherIndex < arraySize && assignElement <= id12; ++otherIndex, ++assignElement) {
				int cost = (value == array[otherIndex] ? 0 : bitCounts[otherIndex]);
				addEdge(id18, assignElement, cost);
			}
		}
		
		for (int assignElement = id13; assignElement <= id12; ++assignElement) {
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
		
		int totalCost = id10(start, end);
		
		int[] usedVariables = new int[arraySize];
		
		List<Point> answer = new ArrayList<Point>();
		for (int index = 0, assignElement = id13; index < arraySize && assignElement <= id12; ++index, ++assignElement) {
			for (Edge edge : graph[assignElement]) {
				if (edge.flow == 0 || edge.capacity > 0) continue;
				

				
				int to = edge.to;
				if (variableStart <= to && to <= variableEnd) {
					int variable = to - variableStart;
					usedVariables[index] = variable;
					
					answer.add(new Point(usedVariables[index], index));
				}
				
				if (id9 <= to && to <= id19) {
					int prev = to - id9;
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
	
	int[] distances;
	int[] maxFlows;
	Edge[] parentEdges;
	
	int id10(int start, int end) {
		int totalCost = 0;
		
		this.distances = new int[graph.length];
		this.parentEdges = new Edge[graph.length];
		this.maxFlows = new int[graph.length];
		
		for (int curCost = id21(start, end); curCost != INF; curCost = id21(start, end)) {
			totalCost += curCost;
		}
		
		return totalCost;
	}
	
	final int INF = Integer.MAX_VALUE / 3;
	
	class Trie {
		int[] parents;
		
		int[] first;
		
		int[] next;
		int[] prev;
		
		int[] last;
		
		public Trie(int n) {
			first = new int[n];
			
			next = new int[n];
			prev = new int[n];
			
			last = new int[n];
			
			parents = new int[n];
			
			Arrays.fill(first, -1);
			Arrays.fill(next, -1);
			Arrays.fill(last, -1);
			Arrays.fill(prev, -1);
			Arrays.fill(parents, -1);
		}
		
		public void updateDistances(int v) {
			for (int child = first[v]; child != -1; child = next[child]) {
				distances[child] = distances[v] + parentEdges[child].cost;
				
				updateDistances(child);
			}
		}
		
		public void setParent(int parent, int cur) {
			if (prev[cur] != -1) {
				next[prev[cur]] = next[cur];
			} else if (parents[cur] != -1 && cur == first[parents[cur]]) {
				first[parents[cur]] = next[cur];
			}
			
			if (next[cur] != -1) {
				prev[next[cur]] = prev[cur];
			} else if (parents[cur] != -1 && cur == last[parents[cur]]) {
				last[parents[cur]] = prev[cur];
			}
			
			prev[cur] = -1;
			next[cur] = -1;
			
			parents[cur] = parent;
			
			if (first[parent] == -1) {
				first[parent] = cur;
				last[parent] = cur;
			} else {
				prev[cur] = last[parent];
				next[last[parent]] = cur;
				
				last[parent] = cur;
			}
		}
	}
	
	int id21(int start, int end) {
		int graphSize = graph.length;
		
		Trie trie = new Trie(graphSize);
		
		Arrays.fill(distances, INF);
		Arrays.fill(parentEdges, null);
		Arrays.fill(maxFlows, INF);
		
		distances[start] = 0;
		for (int it = 0; it < graphSize; ++it) {
			boolean changed = false;
			
			for (Edge edge : edges) {
				if (edge.flow == edge.capacity) continue;
				
				int from = edge.from;
				int to = edge.to;
				
				if (distances[to] > distances[from] + edge.cost) {
					distances[to] = distances[from] + edge.cost;
					
					parentEdges[to] = edge;
					trie.setParent(from, to);
					
					maxFlows[to] = min(maxFlows[from], edge.capacity - edge.flow);
					
					trie.updateDistances(to);
				
					changed = true;
				}
			}
			
			if (!changed) break;
		}
		
		if (distances[end] == INF) return INF;
		
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
		Edge id32 = new Edge(from, to, 1, cost);
		Edge id22 = new Edge(to, from, 0, -cost);
		
		graph[from].add(id32.id31(id22));
		graph[to].add(id22.id31(id32));
		
		edges.add(id32);
		edges.add(id22);
	}
}

