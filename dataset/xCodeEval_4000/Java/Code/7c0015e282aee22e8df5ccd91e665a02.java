import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;




public class C implements Runnable{
	
	final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new C(), "", 128 * (1L << 20)).start();
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
		
		static Comparator<IntIndexPair> increaseComparator = new Comparator<C.IntIndexPair>() {
			
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
		
		static Comparator<IntIndexPair> decreaseComparator = new Comparator<C.IntIndexPair>() {
			
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
	
	

	
	static class Point {
		double x, y;

		public Point(double x, double y) {
			super();
			this.x = x;
			this.y = y;
		}
		
		public double getDistance(Point other) {
			return getDistance(other.x, other.y);
		}
		
		public double getDistance(double otherX, double otherY) {
			double dx = this.x - otherX;
			double dy = this.y - otherY;
			
			return sqrt(dx * dx + dy * dy);
		}

		@Override
		public String toString() {
			return String.format(Locale.US, "%.5f %.5f", x, y);
		}
		
		
	}
	
	static class Vector extends Point {
		
		public Vector(Point start, Point end) {
			this(end.x - start.x, end.y - start.y);
		}
		
		public Vector(double x, double y) {
			super(x, y);
		}
		
		public Vector normalize() {
			double length = getDistance(0, 0);
			this.x /= length;
			this.y /= length;
			
			return this;
		}
		
		public Vector multiply(double k) {
			return new Vector(x * k, y * k);
		}
		
		public Point add(Point p) {
			return new Point(p.x + x, p.y + y);
		}
	}
	
	static interface Area {
		Point[] intersect(Area other);
	}
	
	static class Line implements Area {
		
		double a, b, c;
		
		public Line(Point first, Point second) {
			this.a = second.y - first.y;
			this.b = first.x - second.x;
			this.c = -(first.x * a + first.y * b);
			
			normalize();
		}
		
		public Line(double a, double b, double c) {
			this.a = a;
			this.b = b;
			this.c = c;
			
			normalize();
		}
		
		public void normalize() {
			double denominator = sqrt(a * a + b * b);
			
			this.a /= denominator;
			this.b /= denominator;
			this.c /= denominator;
		}
		
		public Line getPerpendicularLine(Point p) {
			double resultA = -b;
			double resultB = a;
			double resultC = -(resultA * p.x + resultB * p.y);
			
			return new Line(resultA, resultB, resultC);
		}
		
		private static double det(double a11, double a12, double a21, double a22) {
			return a11 * a22 - a12 * a21;
		}
		
		@Override
		public Point[] intersect(Area otherArea) {
			if (otherArea instanceof Circle) {
				return otherArea.intersect(this);
			} else {
				return this.intersect((Line) otherArea);
			}
		}
		
		public Point[] intersect(Line other) {
			double det = det(this.a, this.b, other.a, other.b);
			
			double detX = det(-this.c, this.b, -other.c, other.b);
			double detY = det(this.a, -this.c, other.a, -other.c);
			
			Point[] result = new Point[2];
			result[0] = result[1] = new Point(detX / det, detY / det);
			
			return result;
		}
		
		public double getDistance(Point p) {
			return a * p.x + b * p.y + c;
		}
	}
	
	static class Circle implements Area {
		Point center;
		double r;
		
		public Circle(Point center, double r) {
			this.center = center;
			this.r = r;
		}
		
		@Override
		public Point[] intersect(Area otherArea) {
			if (otherArea instanceof Circle) {
				return this.intersect((Circle) otherArea);
			} else {
				return this.intersect((Line) otherArea);
			}
		}
		
		public Point[] intersect(Line line) {
			double distance = line.getDistance(center);
			if (distance > r) {
				return null;
			}
			
			Point mid = new Vector(-line.a, -line.b).normalize().multiply(distance).add(center);

			double delta = sqrt(r * r - distance * distance);
			
			Point[] result = new Point[2];
			result[0] = new Vector(-line.b, line.a).normalize().multiply(delta).add(mid);
			result[1] = new Vector(line.b, -line.a).normalize().multiply(delta).add(mid);
			
			return result;
		}
		
		public Point[] intersect(Circle other) {
			double distance = this.center.getDistance(other.center);
			if (distance > this.r + other.r) return null;
			
			if (this.r > other.r && this.r == distance + other.r) {
				return other.intersect(this);
			}
			
			if (other.r - this.r > distance + EPS) return null;
			if (abs(other.r - this.r - distance) < EPS) {
				
			} else {
				
			}
			
			double delta = (this.r * this.r - other.r * other.r) / (2 * distance) + distance / 2;
			double h = sqrt(this.r * this.r - delta * delta);
			
			Vector vector = new Vector(this.center, other.center).normalize();
			Point mid = vector.multiply(delta).add(this.center);
			
			Point[] result = new Point[2];
			result[0] = new Vector(vector.y, -vector.x).normalize().multiply(h).add(mid);
			result[1] = new Vector(-vector.y, vector.x).normalize().multiply(h).add(mid);
			
			return result;
		}
	}
	
	final static double EPS = 1e-6;
	
	void solve() throws IOException {
		int n = 3;
		
		Point[] centers = new Point[n];
		int[] r = new int[n];
		
		for (int i = 0; i < n; ++i) {
			centers[i] = readPoint();
			r[i] = readInt();
		}
		
		Point bestPoint = null;
		double bestRatio = 0;
		
		for (int i = 0, j = 1, k = 2; i < n; ++i, j = (j + 1) % n, k = (k + 1) % n) {
			Area ijArea = getArea(i, j, centers, r);
			Area jkArea = getArea(j, k, centers, r);
			
			Point[] intersectPoints = ijArea.intersect(jkArea);
			if (intersectPoints == null) continue;
				
			for (Point point : intersectPoints) {
				double[] distances = new double[n];
				for (int index = 0; index < n; ++index) {
					distances[index] = centers[index].getDistance(point);
				}
				
				boolean correct = true;
				double ratio = r[0] / distances[0];
				
				for (int index = 0; index < n; ++index) {
					double curRatio = r[index] / distances[index];
					correct &= (abs(curRatio - ratio) < EPS);
				}
				
				if (correct && ratio >= bestRatio) {
					bestPoint = point;
					bestRatio = ratio;
				}
			}
		}
		
		if (bestPoint != null) {
			out.println(bestPoint);
		}
	}
	
	Area getArea(int i, int j, Point[] centers, int[] r) {
		Vector vector = new Vector(centers[i], centers[j]).normalize();
		double distance = centers[i].getDistance(centers[j]);
		
		if (r[i] == r[j]) {
			Line line = new Line(centers[i], centers[j]);
			
			Point mid = vector.multiply(distance / 2).add(centers[i]);
			
			return line.getPerpendicularLine(mid);
		} else {
			double innerDistance = 1.0 * r[i] / (r[i] + r[j]);
			double outerDistance = innerDistance / (2 * innerDistance - 1);
			
			innerDistance *= distance;
			outerDistance *= distance;
			
			Point innerPoint = vector.multiply(innerDistance).add(centers[i]);
			Point outerPoint = vector.multiply(outerDistance).add(centers[i]);
			
			Vector diameterVector = new Vector(innerPoint, outerPoint).normalize();
			double radius = innerPoint.getDistance(outerPoint) / 2;
			
			Point center = diameterVector.multiply(radius).add(innerPoint);
			
			return new Circle(center, radius);
		}
	}
}

