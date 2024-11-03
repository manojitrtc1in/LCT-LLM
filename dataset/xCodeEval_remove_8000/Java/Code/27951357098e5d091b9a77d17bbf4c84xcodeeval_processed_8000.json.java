import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.reflect.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		Task solver = new C();
		solver.solve(1, in, out);
		out.close();
	}
}

interface Task {
	public void solve(int testNumber, InputReader in, OutputWriter out);
}

class A implements Task {

	Map<String, Integer> mapa = new HashMap<String, Integer>(),
			aux = new HashMap<String, Integer>();
	String[] nomes;
	int[] pontos;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int n = in.readInt(), p, max = Integer.MIN_VALUE;
		nomes = new String[n];
		pontos = new int[n];
		for (int i = 0; i < n; i++) {
			nomes[i] = in.next();
			pontos[i] = in.readInt();
			if (!mapa.containsKey(nomes[i]))
				mapa.put(nomes[i], 0);
			mapa.put(nomes[i], mapa.get(nomes[i]) + pontos[i]);
		}
		for (int i : mapa.values())
			max = MiscUtils.max(max, i);
		for (int i = 0; i < n; i++) {
			if (!aux.containsKey(nomes[i]))
				aux.put(nomes[i], 0);
			aux.put(nomes[i], aux.get(nomes[i]) + pontos[i]);
			if (mapa.get(nomes[i]) == max && aux.get(nomes[i]) >= max) {
				out.printLine(nomes[i]);
				break;
			}
		}
	}
}

class B implements Task {

	int[][] arr2, arr5, c22, c25, c52, c55;
	boolean[][] p2, p5;
	StringBuilder str = new StringBuilder();

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int n = in.readInt(), a = -1;
		arr2 = new int[n][n];
		arr5 = new int[n][n];
		c22 = new int[n][n];
		c25 = new int[n][n];
		c52 = new int[n][n];
		c55 = new int[n][n];
		p2 = new boolean[n][n];
		p5 = new boolean[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int x = in.readInt();
				if (x == 0) {
					a = i;
					x = 10;
				}
				while (x % 2 == 0) {
					arr2[i][j]++;
					x /= 2;
				}
				while (x % 5 == 0) {
					arr5[i][j]++;
					x /= 5;
				}
				c22[i][j] = arr2[i][j];
				c25[i][j] = arr5[i][j];
				c52[i][j] = arr2[i][j];
				c55[i][j] = arr5[i][j];
				if (i == 0 && j == 0)
					p2[i][j] = p5[i][j] = false;
				else if (i == 0) {
					c22[i][j] += c22[i][j - 1];
					c25[i][j] += c25[i][j - 1];
					p2[i][j] = false;
					c52[i][j] += c52[i][j - 1];
					c55[i][j] += c55[i][j - 1];
					p5[i][j] = false;
				} else if (j == 0) {
					c22[i][j] += c22[i - 1][j];
					c25[i][j] += c25[i - 1][j];
					p2[i][j] = true;
					c52[i][j] += c52[i - 1][j];
					c55[i][j] += c55[i - 1][j];
					p5[i][j] = true;
				} else {
					if (c22[i][j - 1] < c22[i - 1][j]
							|| c22[i][j - 1] == c22[i - 1][j]
							&& c25[i][j - 1] <= c25[i - 1][j]) {
						c22[i][j] += c22[i][j - 1];
						c25[i][j] += c25[i][j - 1];
						p2[i][j] = false;
					} else {
						c22[i][j] += c22[i - 1][j];
						c25[i][j] += c25[i - 1][j];
						p2[i][j] = true;
					}
					if (c55[i][j - 1] < c55[i - 1][j]
							|| c55[i][j - 1] == c55[i - 1][j]
							&& c52[i][j - 1] <= c52[i - 1][j]) {
						c52[i][j] += c52[i][j - 1];
						c55[i][j] += c55[i][j - 1];
						p5[i][j] = false;
					} else {
						c52[i][j] += c52[i - 1][j];
						c55[i][j] += c55[i - 1][j];
						p5[i][j] = true;
					}
				}
			}
		

		

		

		if (a != -1
				&& MiscUtils.min(
						MiscUtils.min(c22[n - 1][n - 1], c25[n - 1][n - 1]),
						MiscUtils.min(c52[n - 1][n - 1], c55[n - 1][n - 1])) > 0) {
			for (int i = 0; i < a; i++)
				str.append('D');
			for (int i = 0; i < n-1; i++)
				str.append('R');
			for (int i = a; i < n-1; i++)
				str.append('D');
			out.printLine(1);
		} else if (MiscUtils.min(c22[n - 1][n - 1], c25[n - 1][n - 1]) <= MiscUtils
				.min(c52[n - 1][n - 1], c55[n - 1][n - 1])) {
			f(p2, n - 1, n - 1);
			out.printLine(MiscUtils.min(c22[n - 1][n - 1], c25[n - 1][n - 1]));
		} else {
			f(p5, n - 1, n - 1);
			out.printLine(MiscUtils.min(c52[n - 1][n - 1], c55[n - 1][n - 1]));
		}
		out.printLine(str);
	}

	void f(boolean[][] p, int x, int y) {
		if (x == 0 && y == 0)
			return;
		if (p[x][y]) {
			f(p, x - 1, y);
			str.append('D');
			return;
		}
		f(p, x, y - 1);
		str.append('R');
	}

}

class C implements Task {

	double eps=1e-8;
	Circle[] arr=new Circle[3];
	List<Circle> circulos=new ArrayList<Circle>();
	List<Line>linhas=new ArrayList<Line>();
	Point[] pontos;
	Counter<Point> contador=new Counter<Point>();
	
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		for(int i=0; i<3;i++)arr[i]=new Circle(new Point(in.readDouble(),in.readDouble()),in.readDouble());
		Circle c1,c2;
		Point p,q;
		for (int i=0; i<3; i++)for (int j=i+1;j<3; j++) {
			if( arr[i].radius<arr[j].radius){
				c1=new Circle(arr[i].center,arr[i].radius);
				c2=new Circle(arr[j].center,arr[j].radius);
			}
			else {
				c1=new Circle(arr[j].center,arr[j].radius);
				c2=new Circle(arr[i].center, arr[i].radius);
			}
			double xa=c1.center.x, xb=c2.center.x, ya=c1.center.y,yb=c2.center.y, c=c1.radius/c2.radius;
			if(Math.abs(c1.radius-c2.radius)<eps)linhas.add(new Line(2.0*(xb-xa),2.0*(yb-ya),xa*xa+ya*ya-xb*xb-yb*yb));
			else circulos.add(new Circle(new Point((xa-c*c*xb)/(1.0-c*c), (ya-c*c*yb)/(1.0-c*c)),c*c1.center.distance(c2.center)/(1.0-c*c)));
		}
		for (int i=0; i<circulos.size();i++) for (int j=i+1;j<circulos.size();j++){
			pontos=circulos.get(i).intersect(circulos.get(j));
			for(int k=0; k<pontos.length; k++) contador.add(pontos[k]);
		}
		for(int i=0; i<linhas.size(); i++) for (int j=i+1;j<linhas.size();j++){
			p=linhas.get(i).intersect(linhas.get(j));
			if(p!=null)contador.add(p);
		}
		for( int i=0; i<linhas.size();i++)for(int j=0;j<circulos.size();j++){
			pontos=linhas.get(i).intersect(circulos.get(j));
			for(int k=0; k<pontos.length; k++)contador.add(pontos[k]);
		}
		p=null;
		q=null;
		for(Point r: contador.keySet()) {
			if(contador.get(r)==3) {
				if(p==null) p=r;
				else q=r;
			}


		}
		if (p!=null&&q==null) out.printFormat("%.5f %.5f\n", p.x, p.y);
		if(q!=null) {
			if(p.distance(arr[0].center)<q.distance(arr[0].center))out.printFormat("%.5f %.5f\n", p.x,p.y);
			else out.printFormat("%.5f %.5f\n", q.x, q.y);
		}
	}
	
	double hypot(double a,double b){
		return Math.sqrt(a*a+b*b);
	}
	
	public class Counter<K extends Comparable<K>> {
		
		Map<K, Integer>mapa;
		
		public Counter(){
			mapa=new TreeMap<K, Integer>();
		}
		
		public void add(K k) {
			mapa.put(k, get(k)+1);
		}
		
		public int get(K k) {
			return mapa.containsKey(k)?mapa.get(k):0;
		}
		
		public Set<K> keySet() {
			return mapa.keySet();
		}
		
	}
	
	public class Circle {
        public final Point center;
        public final double radius;

        public Circle(Point center, double radius) {
                this.center = center;
                this.radius = radius;
        }
	
	    public Point[] intersect(Circle other) {
	        double distance = center.distance(other.center);
	        if (distance > radius + other.radius + eps || Math.abs(radius - other.radius) > distance + eps)
	            return new Point[0];
	        double p = (radius + other.radius + distance) / 2;
	        double height = 2 * Math.sqrt(p * (p - radius) * (p - other.radius) * (p - distance)) / distance;
	        double l1 = Math.sqrt(radius * radius - height * height);
	        double l2 = Math.sqrt(other.radius * other.radius - height * height);
	        if (radius * radius + distance * distance < other.radius * other.radius)
	            l1 = -l1;
	        if (radius * radius > distance * distance + other.radius * other.radius)
	            l2 = -l2;
	        Point middle = new Point((center.x * l2 + other.center.x * l1) / (l1 + l2),
	            (center.y * l2 + other.center.y * l1) / (l1 + l2));
	        Line line = center.line(other.center).perpendicular(middle);
	        return line.intersect(this);
	    }
	}
	
	public class Line {
        public final double a;
        public final double b;
        public final double c;

        public Line(double a, double b, double c) {
                double h = hypot(a, b);
                this.a = a / h;
                this.b = b / h;
                this.c = c / h;
        }

        public Point intersect(Line other) {
                if (parallel(other))
                        return null;
                double id58 = b * other.a - a * other.b;
                double x = (c * other.b - b * other.c) / id58;
                double y = (a * other.c - c * other.a) / id58;
                return new Point(x, y);
        }

        public boolean parallel(Line other) {
                return Math.abs(a * other.b - b * other.a) < eps;
        }

        public Line perpendicular(Point point) {
                return new Line(-b, a, b * point.x - a * point.y);
        }

        public double value(Point point) {
                return a * point.x + b * point.y + c;
        }

        public Point[] intersect(Circle circle) {
                double distance = distance(circle.center);
                if (distance > circle.radius + eps)
                        return new Point[0];
                Point intersection = intersect(perpendicular(circle.center));
                if (Math.abs(distance - circle.radius) < eps)
                        return new Point[]{intersection};
                double shift = Math.sqrt(circle.radius * circle.radius - distance * distance);
                return new Point[]{new Point(intersection.x + shift * b, intersection.y - shift * a),
                        new Point(intersection.x - shift * b, intersection.y + shift * a)};
        }

        public double distance(Point center) {
                return Math.abs(value(center));
        }

	}
	
	public class Point implements Comparable <Point>{
        public final double x;
        public final double y;
        
        public int compareTo(Point other){
        	if (Math.abs(x-other.x)<eps) {
        		if (Math.abs(y-other.y)<eps) return 0;
        		return y<other.y?-1:1;
        	}
        	return x<other.x?-1:1;
        }

        public Point(double x, double y) {
                this.x = x;
                this.y = y;
        }

        public Line line(Point other) {
                if (equals(other))
                        return null;
                double a = other.y - y;
                double b = x - other.x;
                double c = -a * x - b * y;
                return new Line(a, b, c);
        }

        public double distance(Point other) {
                return hypot(x - other.x, y - other.y);
        }
        
        @Override
        public boolean equals(Object o) {
                if (this == o)
                        return true;
                if (o == null || getClass() != o.getClass())
                        return false;

                Point point = (Point) o;

                return Math.abs(x - point.x) <= eps && Math.abs(y - point.y) <= eps;
        }
        
        @Override
        public String toString() {
                return "(" + x + ", " + y + ")";
        }

	}

}

class D implements Task {

	public void solve(int testNumber, InputReader in, OutputWriter out) {

	}

}

class E implements Task {

	public void solve(int testNumber, InputReader in, OutputWriter out) {

	}

}

class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private id53 filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
	}

	public int readInt() {
		int c = read();
		while (id5(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!id5(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (id5(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!id5(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id5(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!id5(c));
		return res.toString();
	}

	public boolean id5(int c) {
		if (filter != null)
			return filter.id5(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id22() {
		StringBuilder buf = new StringBuilder();
		int c = read();
		while (c != '\n' && c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = read();
		}
		return buf.toString();
	}

	public String readLine() {
		String s = id22();
		while (s.trim().length() == 0)
			s = id22();
		return s;
	}

	public String readLine(boolean id69) {
		if (id69)
			return readLine();
		else
			return id22();
	}

	public BigInteger id14() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id5(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id5(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id5(c) && c != '.') {
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, readInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		if (c == '.') {
			c = read();
			double m = 1;
			while (!id5(c)) {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = read();
			}
		}
		return res * sgn;
	}

	public boolean id24() {
		int value;
		while (id5(value = peek()) && value != -1)
			read();
		return value == -1;
	}

	public String next() {
		return readString();
	}

	public id53 getFilter() {
		return filter;
	}

	public void setFilter(id53 filter) {
		this.filter = filter;
	}

	public interface id53 {
		public boolean id5(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(char[] array) {
		writer.print(array);
	}

	public void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void print(int[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(array[i]);
		}
	}

	public void print(long[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(array[i]);
		}
	}

	public void print(IntCollection collection) {
		boolean first = true;
		for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator
				.advance()) {
			if (first)
				first = false;
			else
				writer.print(' ');
			writer.print(iterator.value());
		}
	}

	public void printLine(int[] array) {
		print(array);
		writer.println();
	}

	public void printLine(long[] array) {
		print(array);
		writer.println();
	}

	public void printLine(IntCollection collection) {
		print(collection);
		writer.println();
	}

	public void printLine() {
		writer.println();
	}

	public void printLine(Object... objects) {
		print(objects);
		writer.println();
	}

	public void print(char i) {
		writer.print(i);
	}

	public void printLine(char i) {
		writer.println(i);
	}

	public void printLine(char[] array) {
		writer.println(array);
	}

	public void printFormat(String format, Object... objects) {
		writer.printf(format, objects);
	}

	public void close() {
		writer.close();
	}

	public void flush() {
		writer.flush();
	}

	public void print(long i) {
		writer.print(i);
	}

	public void printLine(long i) {
		writer.println(i);
	}

	public void print(int i) {
		writer.print(i);
	}

	public void printLine(int i) {
		writer.println(i);
	}
}

class IOUtils {
	public static Pair<Integer, Integer> id59(InputReader in) {
		int first = in.readInt();
		int second = in.readInt();
		return Pair.makePair(first, second);
	}

	public static Pair<Long, Long> id10(InputReader in) {
		long first = in.readLong();
		long second = in.readLong();
		return Pair.makePair(first, second);
	}

	public static int[] id1(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	public static long[] id7(InputReader in, int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readLong();
		return array;
	}

	public static double[] id36(InputReader in, int size) {
		double[] array = new double[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readDouble();
		return array;
	}

	public static String[] id33(InputReader in, int size) {
		String[] array = new String[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readString();
		return array;
	}

	public static char[] id4(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	public static Pair<Integer, Integer>[] id9(InputReader in,
			int size) {
		@SuppressWarnings({ "unchecked" })
		Pair<Integer, Integer>[] result = new Pair[size];
		for (int i = 0; i < size; i++)
			result[i] = id59(in);
		return result;
	}

	public static Pair<Long, Long>[] id56(InputReader in, int size) {
		@SuppressWarnings({ "unchecked" })
		Pair<Long, Long>[] result = new Pair[size];
		for (int i = 0; i < size; i++)
			result[i] = id10(in);
		return result;
	}

	public static void id11(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	public static void id47(InputReader in, long[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readLong();
		}
	}

	public static void id49(InputReader in, double[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readDouble();
		}
	}

	public static char[][] readTable(InputReader in, int rowCount,
			int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id4(in, columnCount);
		return table;
	}

	public static int[][] id37(InputReader in, int rowCount,
			int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id1(in, columnCount);
		return table;
	}

	public static double[][] id0(InputReader in, int rowCount,
			int columnCount) {
		double[][] table = new double[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id36(in, columnCount);
		return table;
	}

	public static long[][] id18(InputReader in, int rowCount,
			int columnCount) {
		long[][] table = new long[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id7(in, columnCount);
		return table;
	}

	public static String[][] id68(InputReader in, int rowCount,
			int columnCount) {
		String[][] table = new String[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = id33(in, columnCount);
		return table;
	}

	public static String readText(InputReader in) {
		StringBuilder result = new StringBuilder();
		while (true) {
			int character = in.read();
			if (character == '\r')
				continue;
			if (character == -1)
				break;
			result.append((char) character);
		}
		return result.toString();
	}

	public static void id29(InputReader in, String[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readString();
		}
	}

	public static void printTable(OutputWriter out, char[][] table) {
		for (char[] row : table)
			out.printLine(new String(row));
	}
}

interface IntComparator {
	public static final IntComparator DEFAULT = new IntComparator() {
		public int compare(int first, int second) {
			if (first < second)
				return -1;
			if (first > second)
				return 1;
			return 0;
		}
	};

	public static final IntComparator REVERSE = new IntComparator() {
		public int compare(int first, int second) {
			if (first < second)
				return 1;
			if (first > second)
				return -1;
			return 0;
		}
	};

	public int compare(int first, int second);
}

class id26 extends Graph {
	public int[] id21;

	public id26(int vertexCount) {
		this(vertexCount, vertexCount);
	}

	public id26(int vertexCount, int edgeCapacity) {
		super(vertexCount, 2 * edgeCapacity);
		id21 = new int[2 * edgeCapacity];
	}

	public static id26 createGraph(int vertexCount, int[] from,
			int[] to) {
		id26 graph = new id26(vertexCount,
				from.length);
		for (int i = 0; i < from.length; i++)
			graph.id13(from[i], to[i]);
		return graph;
	}

	public static id26 id20(int vertexCount,
			int[] from, int[] to, long[] weight) {
		id26 graph = new id26(vertexCount,
				from.length);
		for (int i = 0; i < from.length; i++)
			graph.id2(from[i], to[i], weight[i]);
		return graph;
	}

	public static id26 id48(int vertexCount,
			int[] from, int[] to, long[] capacity) {
		id26 graph = new id26(vertexCount,
				from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id27(from[i], to[i], capacity[i]);
		return graph;
	}

	public static id26 id41(int vertexCount,
			int[] from, int[] to, long[] weight, long[] capacity) {
		id26 graph = new id26(vertexCount,
				from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id42(from[i], to[i], weight[i], capacity[i]);
		return graph;
	}

	@Override
	public int addEdge(int fromID, int toID, long weight, long capacity,
			int reverseEdge) {
		int id63 = edgeCount;
		super.addEdge(fromID, toID, weight, capacity, reverseEdge);
		super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1
				: reverseEdge + 1);
		this.id21[id63] = id63 + 1;
		this.id21[id63 + 1] = id63;
		return id63;
	}

	@Override
	protected int id12() {
		return 2;
	}

	@Override
	public final int transposed(int id) {
		return id21[id];
	}

	@Override
	protected void id46(int size) {
		if (size > edgeCapacity()) {
			super.id46(size);
			id21 = resize(id21, edgeCapacity());
		}
	}
}

class Graph {
	public static final int id72 = 0;

	protected int vertexCount;
	protected int edgeCount;

	private int[] firstOutbound;
	private int[] firstInbound;

	private Edge[] edges;
	private int[] nextInbound;
	private int[] nextOutbound;
	private int[] from;
	private int[] to;
	private long[] weight;
	private long[] capacity;
	private int[] reverseEdge;
	private int[] flags;

	public Graph(int vertexCount) {
		this(vertexCount, vertexCount);
	}

	public Graph(int vertexCount, int edgeCapacity) {
		this.vertexCount = vertexCount;
		firstOutbound = new int[vertexCount];
		Arrays.fill(firstOutbound, -1);

		from = new int[edgeCapacity];
		to = new int[edgeCapacity];
		nextOutbound = new int[edgeCapacity];
		flags = new int[edgeCapacity];
	}

	public static Graph createGraph(int vertexCount, int[] from, int[] to) {
		Graph graph = new Graph(vertexCount, from.length);
		for (int i = 0; i < from.length; i++)
			graph.id13(from[i], to[i]);
		return graph;
	}

	public static Graph id20(int vertexCount, int[] from,
			int[] to, long[] weight) {
		Graph graph = new Graph(vertexCount, from.length);
		for (int i = 0; i < from.length; i++)
			graph.id2(from[i], to[i], weight[i]);
		return graph;
	}

	public static Graph id48(int vertexCount, int[] from, int[] to,
			long[] capacity) {
		Graph graph = new Graph(vertexCount, from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id27(from[i], to[i], capacity[i]);
		return graph;
	}

	public static Graph id41(int vertexCount, int[] from,
			int[] to, long[] weight, long[] capacity) {
		Graph graph = new Graph(vertexCount, from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id42(from[i], to[i], weight[i], capacity[i]);
		return graph;
	}

	public static Graph createTree(int[] parent) {
		Graph graph = new Graph(parent.length + 1, parent.length);
		for (int i = 0; i < parent.length; i++)
			graph.id13(parent[i], i + 1);
		return graph;
	}

	public int addEdge(int fromID, int toID, long weight, long capacity,
			int reverseEdge) {
		id46(edgeCount + 1);
		if (firstOutbound[fromID] != -1)
			nextOutbound[edgeCount] = firstOutbound[fromID];
		else
			nextOutbound[edgeCount] = -1;
		firstOutbound[fromID] = edgeCount;
		if (firstInbound != null) {
			if (firstInbound[toID] != -1)
				nextInbound[edgeCount] = firstInbound[toID];
			else
				nextInbound[edgeCount] = -1;
			firstInbound[toID] = edgeCount;
		}
		this.from[edgeCount] = fromID;
		this.to[edgeCount] = toID;
		if (capacity != 0) {
			if (this.capacity == null)
				this.capacity = new long[from.length];
			this.capacity[edgeCount] = capacity;
		}
		if (weight != 0) {
			if (this.weight == null)
				this.weight = new long[from.length];
			this.weight[edgeCount] = weight;
		}
		if (reverseEdge != -1) {
			if (this.reverseEdge == null) {
				this.reverseEdge = new int[from.length];
				Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
			}
			this.reverseEdge[edgeCount] = reverseEdge;
		}
		if (edges != null)
			edges[edgeCount] = createEdge(edgeCount);
		return edgeCount++;
	}

	protected final GraphEdge createEdge(int id) {
		return new GraphEdge(id);
	}

	public final int id42(int from, int to, long weight,
			long capacity) {
		if (capacity == 0) {
			return addEdge(from, to, weight, 0, -1);
		} else {
			int id63 = edgeCount;
			addEdge(to, from, -weight, 0, id63 + id12());
			return addEdge(from, to, weight, capacity, id63);
		}
	}

	protected int id12() {
		return 1;
	}

	public final int id27(int from, int to, long capacity) {
		return id42(from, to, 0, capacity);
	}

	public final int id2(int from, int to, long weight) {
		return id42(from, to, weight, 0);
	}

	public final int id13(int from, int to) {
		return id2(from, to, 0);
	}

	public final int vertexCount() {
		return vertexCount;
	}

	public final int edgeCount() {
		return edgeCount;
	}

	protected final int edgeCapacity() {
		return from.length;
	}

	public final Edge edge(int id) {
		initEdges();
		return edges[id];
	}

	public final int firstOutbound(int vertex) {
		int id = firstOutbound[vertex];
		while (id != -1 && isRemoved(id))
			id = nextOutbound[id];
		return id;
	}

	public final int nextOutbound(int id) {
		id = nextOutbound[id];
		while (id != -1 && isRemoved(id))
			id = nextOutbound[id];
		return id;
	}

	public final int firstInbound(int vertex) {
		initInbound();
		int id = firstInbound[vertex];
		while (id != -1 && isRemoved(id))
			id = nextInbound[id];
		return id;
	}

	public final int nextInbound(int id) {
		initInbound();
		id = nextInbound[id];
		while (id != -1 && isRemoved(id))
			id = nextInbound[id];
		return id;
	}

	public final int source(int id) {
		return from[id];
	}

	public final int destination(int id) {
		return to[id];
	}

	public final long weight(int id) {
		if (weight == null)
			return 0;
		return weight[id];
	}

	public final long capacity(int id) {
		if (capacity == null)
			return 0;
		return capacity[id];
	}

	public final long flow(int id) {
		if (reverseEdge == null)
			return 0;
		return capacity[reverseEdge[id]];
	}

	public final void pushFlow(int id, long flow) {
		if (flow == 0)
			return;
		if (flow > 0) {
			if (capacity(id) < flow)
				throw new IllegalArgumentException("Not enough capacity");
		} else {
			if (flow(id) < -flow)
				throw new IllegalArgumentException("Not enough capacity");
		}
		capacity[id] -= flow;
		capacity[reverseEdge[id]] += flow;
	}

	public int transposed(int id) {
		return -1;
	}

	public final int reverse(int id) {
		if (reverseEdge == null)
			return -1;
		return reverseEdge[id];
	}

	public final void addVertices(int count) {
		id44(vertexCount + count);
		Arrays.fill(firstOutbound, vertexCount, vertexCount + count, -1);
		if (firstInbound != null)
			Arrays.fill(firstInbound, vertexCount, vertexCount + count, -1);
		vertexCount += count;
	}

	protected final void initEdges() {
		if (edges == null) {
			edges = new Edge[from.length];
			for (int i = 0; i < edgeCount; i++)
				edges[i] = createEdge(i);
		}
	}

	public final void removeVertex(int vertex) {
		int id = firstOutbound[vertex];
		while (id != -1) {
			removeEdge(id);
			id = nextOutbound[id];
		}
		initInbound();
		id = firstInbound[vertex];
		while (id != -1) {
			removeEdge(id);
			id = nextInbound[id];
		}
	}

	private void initInbound() {
		if (firstInbound == null) {
			firstInbound = new int[firstOutbound.length];
			Arrays.fill(firstInbound, 0, vertexCount, -1);
			nextInbound = new int[from.length];
			for (int i = 0; i < edgeCount; i++) {
				nextInbound[i] = firstInbound[to[i]];
				firstInbound[to[i]] = i;
			}
		}
	}

	public final boolean flag(int id, int bit) {
		return (flags[id] >> bit & 1) != 0;
	}

	public final void setFlag(int id, int bit) {
		flags[id] |= 1 << bit;
	}

	public final void removeFlag(int id, int bit) {
		flags[id] &= -1 - (1 << bit);
	}

	public final void removeEdge(int id) {
		setFlag(id, id72);
	}

	public final void restoreEdge(int id) {
		removeFlag(id, id72);
	}

	public final boolean isRemoved(int id) {
		return flag(id, id72);
	}

	public final Iterable<Edge> outbound(final int id) {
		initEdges();
		return new Iterable<Edge>() {
			public Iterator<Edge> iterator() {
				return new EdgeIterator(id, firstOutbound, nextOutbound);
			}
		};
	}

	public final Iterable<Edge> inbound(final int id) {
		initEdges();
		initInbound();
		return new Iterable<Edge>() {
			public Iterator<Edge> iterator() {
				return new EdgeIterator(id, firstInbound, nextInbound);
			}
		};
	}

	protected void id46(int size) {
		if (from.length < size) {
			int newSize = Math.max(size, 2 * from.length);
			if (edges != null)
				edges = resize(edges, newSize);
			from = resize(from, newSize);
			to = resize(to, newSize);
			nextOutbound = resize(nextOutbound, newSize);
			if (nextInbound != null)
				nextInbound = resize(nextInbound, newSize);
			if (weight != null)
				weight = resize(weight, newSize);
			if (capacity != null)
				capacity = resize(capacity, newSize);
			if (reverseEdge != null)
				reverseEdge = resize(reverseEdge, newSize);
			flags = resize(flags, newSize);
		}
	}

	private void id44(int size) {
		if (firstOutbound.length < size) {
			int newSize = Math.max(size, 2 * from.length);
			firstOutbound = resize(firstOutbound, newSize);
			if (firstInbound != null)
				firstInbound = resize(firstInbound, newSize);
		}
	}

	protected final int[] resize(int[] array, int size) {
		int[] newArray = new int[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private long[] resize(long[] array, int size) {
		long[] newArray = new long[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private Edge[] resize(Edge[] array, int size) {
		Edge[] newArray = new Edge[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	public final boolean isSparse() {
		return vertexCount == 0 || edgeCount * 20 / vertexCount <= vertexCount;
	}

	protected class GraphEdge implements Edge {
		protected int id;

		protected GraphEdge(int id) {
			this.id = id;
		}

		public int getSource() {
			return source(id);
		}

		public int getDestination() {
			return destination(id);
		}

		public long getWeight() {
			return weight(id);
		}

		public long getCapacity() {
			return capacity(id);
		}

		public long getFlow() {
			return flow(id);
		}

		public void pushFlow(long flow) {
			Graph.this.pushFlow(id, flow);
		}

		public boolean getFlag(int bit) {
			return flag(id, bit);
		}

		public void setFlag(int bit) {
			Graph.this.setFlag(id, bit);
		}

		public void removeFlag(int bit) {
			Graph.this.removeFlag(id, bit);
		}

		public int id54() {
			return transposed(id);
		}

		public Edge id57() {
			int reverseID = id54();
			if (reverseID == -1)
				return null;
			initEdges();
			return edge(reverseID);
		}

		public int id16() {
			return reverse(id);
		}

		public Edge id50() {
			int reverseID = id16();
			if (reverseID == -1)
				return null;
			initEdges();
			return edge(reverseID);
		}

		public int getID() {
			return id;
		}

		public void remove() {
			removeEdge(id);
		}

		public void restore() {
			restoreEdge(id);
		}
	}

	public class EdgeIterator implements Iterator<Edge> {
		private int edgeID;
		private final int[] next;
		private int lastID = -1;

		public EdgeIterator(int id, int[] first, int[] next) {
			this.next = next;
			edgeID = nextEdge(first[id]);
		}

		private int nextEdge(int id) {
			while (id != -1 && isRemoved(id))
				id = next[id];
			return id;
		}

		public boolean hasNext() {
			return edgeID != -1;
		}

		public Edge next() {
			if (edgeID == -1)
				throw new NoSuchElementException();
			lastID = edgeID;
			edgeID = nextEdge(next[lastID]);
			return edges[lastID];
		}

		public void remove() {
			if (lastID == -1)
				throw new IllegalStateException();
			removeEdge(lastID);
			lastID = -1;
		}
	}
}

class MiscUtils {
	public static final int[] DX4 = { 1, 0, -1, 0 };
	public static final int[] DY4 = { 0, -1, 0, 1 };
	public static final int[] DX8 = { 1, 1, 1, 0, -1, -1, -1, 0 };
	public static final int[] DY8 = { -1, 0, 1, 1, 1, 0, -1, -1 };
	public static final int[] id32 = { 2, 1, -1, -2, -2, -1, 1, 2 };
	public static final int[] id25 = { 1, 2, 2, 1, -1, -2, -2, -1 };

	private static final String[] id39 = { "M", "CM", "D", "CD", "C",
			"XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	private static final int[] id70 = { 1000, 900, 500, 400, 100, 90,
			50, 40, 10, 9, 5, 4, 1 };

	public static long id23(long n, int k) {
		if (n == 1)
			return 0;
		if (k == 1)
			return n - 1;
		if (k > n)
			return (id23(n - 1, k) + k) % n;
		long count = n / k;
		long result = id23(n - count, k);
		result -= n % k;
		if (result < 0)
			result += n;
		else
			result += result / (k - 1);
		return result;
	}

	public static boolean id71(int row, int column, int rowCount,
			int columnCount) {
		return row >= 0 && row < rowCount && column >= 0
				&& column < columnCount;
	}

	public static IntList getPath(int[] last, int destination) {
		IntList path = new id67();
		while (destination != -1) {
			path.add(destination);
			destination = last[destination];
		}
		path.id61();
		return path;
	}

	public static IntList getPath(int[][] lastIndex, int[][] id8,
			int destination, int pathNumber) {
		IntList path = new id67();
		while (destination != -1 || pathNumber != 0) {
			path.add(destination);
			int nextDestination = lastIndex[destination][pathNumber];
			pathNumber = id8[destination][pathNumber];
			destination = nextDestination;
		}
		path.id61();
		return path;
	}

	public static long id52(long[][] array) {
		int n = array.length;
		int m = array[0].length;
		long[][] id60 = new long[n + 1][m + 1];
		for (int i = 0; i < n; i++) {
			long rowSum = 0;
			for (int j = 0; j < m; j++) {
				rowSum += array[i][j];
				id60[i + 1][j + 1] = id60[i][j + 1] + rowSum;
			}
		}
		long result = Long.MIN_VALUE;
		for (int i = 0; i < m; i++) {
			for (int j = i; j < m; j++) {
				long id45 = 0;
				for (int k = 1; k <= n; k++) {
					long current = id60[k][j + 1] - id60[k][i];
					result = Math.max(result, current - id45);
					id45 = Math.min(id45, current);
				}
			}
		}
		return result;
	}

	public static int parseIP(String ip) {
		String[] components = ip.split("[.]");
		int result = 0;
		for (int i = 0; i < 4; i++)
			result += (1 << (24 - 8 * i)) * Integer.parseInt(components[i]);
		return result;
	}

	public static String buildIP(int mask) {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < 4; i++) {
			if (i != 0)
				result.append('.');
			result.append(mask >> (24 - 8 * i) & 255);
		}
		return result.toString();
	}

	public static long binarySearch(long from, long to,
			Function<Long, Boolean> function) {
		while (from < to) {
			long argument = from + (to - from) / 2;
			if (function.value(argument))
				to = argument;
			else
				from = argument + 1;
		}
		return from;
	}

	public static <T> boolean equals(T first, T second) {
		return first == null && second == null || first != null
				&& first.equals(second);
	}

	public static boolean id43(char ch) {
		ch = Character.toUpperCase(ch);
		return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
				|| ch == 'Y';
	}

	public static boolean id3(char ch) {
		ch = Character.toUpperCase(ch);
		return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
	}

	public static String id30(int number) {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < id39.length; i++) {
			while (number >= id70[i]) {
				number -= id70[i];
				result.append(id39[i]);
			}
		}
		return result.toString();
	}

	public static int id28(String number) {
		int result = 0;
		for (int i = 0; i < id39.length; i++) {
			while (number.startsWith(id39[i])) {
				number = number.substring(id39[i].length());
				result += id70[i];
			}
		}
		return result;
	}

	public static int distance(int x1, int y1, int x2, int y2) {
		int dx = x1 - x2;
		int dy = y1 - y2;
		return dx * dx + dy * dy;
	}

	public static <T extends Comparable<T>> T min(T first, T second) {
		if (first.compareTo(second) <= 0)
			return first;
		return second;
	}

	public static <T extends Comparable<T>> T max(T first, T second) {
		if (first.compareTo(second) <= 0)
			return second;
		return first;
	}

	public static void id62(int[]... arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	public static int[] id15(String s) {
		String[] tokens = s.split(" ");
		int[] result = new int[tokens.length];
		for (int i = 0; i < result.length; i++)
			result[i] = Integer.parseInt(tokens[i]);
		return result;
	}
}

class id67 extends IntList {
	private int[] array;
	private int size;

	public id67() {
		this(10);
	}

	public id67(int capacity) {
		array = new int[capacity];
	}

	public id67(IntList list) {
		this(list.size());
		addAll(list);
	}

	@Override
	public int get(int index) {
		if (index >= size)
			throw new IndexOutOfBoundsException();
		return array[index];
	}

	@Override
	public void set(int index, int value) {
		if (index >= size)
			throw new IndexOutOfBoundsException();
		array[index] = value;
	}

	@Override
	public int size() {
		return size;
	}

	@Override
	public void add(int value) {
		ensureCapacity(size + 1);
		array[size++] = value;
	}

	public void ensureCapacity(int newCapacity) {
		if (newCapacity > array.length) {
			int[] newArray = new int[Math.max(newCapacity, array.length << 1)];
			System.arraycopy(array, 0, newArray, 0, size);
			array = newArray;
		}
	}

	@Override
	public int[] toArray() {
		int[] array = new int[size];
		System.arraycopy(this.array, 0, array, 0, size);
		return array;
	}

	@Override
	public int popBack() {
		return array[--size];
	}
}

abstract class IntList extends IntCollection implements Comparable<IntList> {
	private static final int id17 = 16;
	private static IntList EMPTY_LIST;

	public abstract int get(int index);

	public abstract void set(int index, int value);

	@Override
	public IntIterator iterator() {
		return new IntIterator() {
			private int size = size();
			private int index = 0;

			public int value() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				return get(index);
			}

			public void advance() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				index++;
			}

			public boolean isValid() {
				return index < size;
			}
		};
	}

	@Override
	public void remove(int value) {
		throw new UnsupportedOperationException();
	}

	public int find(int value) {
		int size = size();
		for (int i = 0; i < size; i++) {
			if (get(i) == value)
				return i;
		}
		return -1;
	}

	public int findLast(int value) {
		int size = size();
		for (int i = size - 1; i >= 0; i--) {
			if (get(i) == value)
				return i;
		}
		return -1;
	}

	public boolean nextPermutation() {
		return nextPermutation(IntComparator.DEFAULT);
	}

	private boolean nextPermutation(IntComparator comparator) {
		int size = size();
		int last = get(size - 1);
		for (int i = size - 2; i >= 0; i--) {
			int current = get(i);
			if (comparator.compare(last, current) > 0) {
				for (int j = size - 1; j > i; j--) {
					if (comparator.compare(get(j), current) > 0) {
						swap(i, j);
						subList(i + 1, size).id61();
						return true;
					}
				}
			}
			last = current;
		}
		return false;
	}

	public void id61() {
		for (int i = 0, j = size() - 1; i < j; i++, j--)
			swap(i, j);
	}

	public IntList subList(final int from, final int to) {
		return new SubList(from, to);
	}

	private void swap(int first, int second) {
		if (first == second)
			return;
		int temp = get(first);
		set(first, get(second));
		set(second, temp);
	}

	public id31 id66() {
		return id66(IntComparator.DEFAULT);
	}

	public id31 id66(IntComparator comparator) {
		quickSort(0, size() - 1,
				(Integer.bitCount(Integer.highestOneBit(size()) - 1) * 5) >> 1,
				comparator);
		return new id40(this, comparator);
	}

	private void quickSort(int from, int to, int remaining,
			IntComparator comparator) {
		if (to - from < id17) {
			id38(from, to, comparator);
			return;
		}
		if (remaining == 0) {
			heapSort(from, to, comparator);
			return;
		}
		remaining--;
		int pivotIndex = (from + to) >> 1;
		int pivot = get(pivotIndex);
		swap(pivotIndex, to);
		int storeIndex = from;
		int equalIndex = to;
		for (int i = from; i < equalIndex; i++) {
			int value = comparator.compare(get(i), pivot);
			if (value < 0)
				swap(storeIndex++, i);
			else if (value == 0)
				swap(--equalIndex, i--);
		}
		quickSort(from, storeIndex - 1, remaining, comparator);
		for (int i = equalIndex; i <= to; i++)
			swap(storeIndex++, i);
		quickSort(storeIndex, to, remaining, comparator);
	}

	private void heapSort(int from, int to, IntComparator comparator) {
		for (int i = (to + from - 1) >> 1; i >= from; i--)
			id19(i, to, comparator, from);
		for (int i = to; i > from; i--) {
			swap(from, i);
			id19(from, i - 1, comparator, from);
		}
	}

	private void id19(int start, int end, IntComparator comparator,
			int delta) {
		int value = get(start);
		while (true) {
			int child = ((start - delta) << 1) + 1 + delta;
			if (child > end)
				return;
			int childValue = get(child);
			if (child + 1 <= end) {
				int otherValue = get(child + 1);
				if (comparator.compare(otherValue, childValue) > 0) {
					child++;
					childValue = otherValue;
				}
			}
			if (comparator.compare(value, childValue) >= 0)
				return;
			swap(start, child);
			start = child;
		}
	}

	private void id38(int from, int to, IntComparator comparator) {
		for (int i = from + 1; i <= to; i++) {
			int value = get(i);
			for (int j = i - 1; j >= from; j--) {
				if (comparator.compare(get(j), value) <= 0)
					break;
				swap(j, j + 1);
			}
		}
	}

	public id31 sort() {
		return sort(IntComparator.DEFAULT);
	}

	public id31 sort(IntComparator comparator) {
		return new IntArray(this).id66(comparator);
	}

	public int back() {
		return get(size() - 1);
	}

	public int popBack() {
		throw new UnsupportedOperationException();
	}

	public int hashCode() {
		int hashCode = 1;
		for (IntIterator i = iterator(); i.isValid(); i.advance())
			hashCode = 31 * hashCode + i.value();
		return hashCode;
	}

	@Override
	public boolean equals(Object obj) {
		if (!(obj instanceof IntList))
			return false;
		IntList list = (IntList) obj;
		if (list.size() != size())
			return false;
		IntIterator i = iterator();
		IntIterator j = list.iterator();
		while (i.isValid()) {
			if (i.value() != j.value())
				return false;
			i.advance();
			j.advance();
		}
		return true;
	}

	public int compareTo(IntList o) {
		IntIterator i = iterator();
		IntIterator j = o.iterator();
		while (true) {
			if (i.isValid()) {
				if (j.isValid()) {
					if (i.value() != j.value()) {
						if (i.value() < j.value())
							return -1;
						else
							return 1;
					}
				} else
					return 1;
			} else {
				if (j.isValid())
					return -1;
				else
					return 0;
			}
			i.advance();
			j.advance();
		}
	}

	public static IntList emptyList() {
		if (EMPTY_LIST == null)
			EMPTY_LIST = new IntArray(new int[0]);
		return EMPTY_LIST;
	}

	private class SubList extends IntList {
		private final int to;
		private final int from;
		private int size;

		public SubList(int from, int to) {
			this.to = to;
			this.from = from;
			size = to - from;
		}

		@Override
		public int get(int index) {
			if (index < 0 || index >= size)
				throw new IndexOutOfBoundsException();
			return IntList.this.get(index + from);
		}

		@Override
		public void set(int index, int value) {
			if (index < 0 || index >= size)
				throw new IndexOutOfBoundsException();
			IntList.this.set(index + from, value);
		}

		@Override
		public int size() {
			return size;
		}

		@Override
		public void add(int value) {
			throw new UnsupportedOperationException();
		}
	}
}

class id64 {
	private final Graph graph;
	private final int source;
	private final int destination;
	private final long[] phi;
	private final long[] id55;
	private final int[] lastEdge;
	private final Heap heap;
	private final int vertexCount;
	private final int[] visited;
	private int visitIndex;

	public id64(Graph graph, int source, int destination,
			boolean id51) {
		this.graph = graph;
		this.source = source;
		this.destination = destination;
		vertexCount = graph.vertexCount();
		phi = new long[vertexCount];
		if (id51)
			id65();
		id55 = new long[vertexCount];
		lastEdge = new int[vertexCount];
		if (graph.isSparse()) {
			heap = new Heap(vertexCount, new IntComparator() {
				public int compare(int first, int second) {
					return IntegerUtils.longCompare(id55[first],
							id55[second]);
				}
			}, vertexCount);
			visited = null;
		} else {
			heap = null;
			visited = new int[vertexCount];
		}
	}

	private void id65() {
		Arrays.fill(phi, Long.MAX_VALUE);
		phi[source] = 0;
		boolean[] inQueue = new boolean[vertexCount];
		int[] queue = new int[vertexCount + 1];
		queue[0] = source;
		inQueue[source] = true;
		int stepCount = 0;
		int head = 0;
		int end = 1;
		int maxSteps = 2 * vertexCount * vertexCount;
		while (head != end) {
			int vertex = queue[head++];
			if (head == queue.length)
				head = 0;
			inQueue[vertex] = false;
			int edgeID = graph.firstOutbound(vertex);
			while (edgeID != -1) {
				long total = phi[vertex] + graph.weight(edgeID);
				int destination = graph.destination(edgeID);
				if (graph.capacity(edgeID) != 0 && phi[destination] > total) {
					phi[destination] = total;
					if (!inQueue[destination]) {
						queue[end++] = destination;
						inQueue[destination] = true;
						if (end == queue.length)
							end = 0;
					}
				}
				edgeID = graph.nextOutbound(edgeID);
			}
			if (++stepCount > maxSteps)
				throw new IllegalArgumentException(
						"Graph contains negative cycle");
		}
	}

	public static Pair<Long, Long> id6(Graph graph, int source,
			int destination, boolean id51) {
		return new id64(graph, source, destination, id51)
				.id6();
	}

	public static Pair<Long, Long> id6(Graph graph, int source,
			int destination, boolean id51, long maxFlow) {
		return new id64(graph, source, destination, id51)
				.id6(maxFlow);
	}

	public Pair<Long, Long> id6() {
		return id6(Long.MAX_VALUE);
	}

	public Pair<Long, Long> id6(long maxFlow) {
		long cost = 0;
		long flow = 0;
		while (maxFlow != 0) {
			if (graph.isSparse())
				id34();
			else
				id35();
			if (lastEdge[destination] == -1)
				return Pair.makePair(cost, flow);
			for (int i = 0; i < id55.length; i++) {
				if (id55[i] != Long.MAX_VALUE)
					phi[i] += id55[i];
			}
			int vertex = destination;
			long currentFlow = maxFlow;
			long currentCost = 0;
			while (vertex != source) {
				int edgeID = lastEdge[vertex];
				currentFlow = Math.min(currentFlow, graph.capacity(edgeID));
				currentCost += graph.weight(edgeID);
				vertex = graph.source(edgeID);
			}
			maxFlow -= currentFlow;
			cost += currentCost * currentFlow;
			flow += currentFlow;
			vertex = destination;
			while (vertex != source) {
				int edgeID = lastEdge[vertex];
				graph.pushFlow(edgeID, currentFlow);
				vertex = graph.source(edgeID);
			}
		}
		return Pair.makePair(cost, flow);
	}

	private void id34() {
		Arrays.fill(id55, Long.MAX_VALUE);
		Arrays.fill(lastEdge, -1);
		id55[source] = 0;
		heap.add(source);
		while (!heap.isEmpty()) {
			int current = heap.poll();
			int edgeID = graph.firstOutbound(current);
			while (edgeID != -1) {
				if (graph.capacity(edgeID) != 0) {
					int next = graph.destination(edgeID);
					long total = graph.weight(edgeID) - phi[next]
							+ phi[current] + id55[current];
					if (id55[next] > total) {
						id55[next] = total;
						if (heap.getIndex(next) == -1)
							heap.add(next);
						else
							heap.shiftUp(heap.getIndex(next));
						lastEdge[next] = edgeID;
					}
				}
				edgeID = graph.nextOutbound(edgeID);
			}
		}
	}

	private void id35() {
		visitIndex++;
		Arrays.fill(id55, Long.MAX_VALUE);
		lastEdge[destination] = -1;
		id55[source] = 0;
		for (int i = 0; i < vertexCount; i++) {
			int index = -1;
			long length = Long.MAX_VALUE;
			for (int j = 0; j < vertexCount; j++) {
				if (visited[j] != visitIndex && id55[j] < length) {
					length = id55[j];
					index = j;
				}
			}
			if (index == -1) {
				return;
			}
			visited[index] = visitIndex;
			int edgeID = graph.firstOutbound(index);
			while (edgeID != -1) {
				if (graph.capacity(edgeID) != 0) {
					int next = graph.destination(edgeID);
					if (visited[next] != visitIndex) {
						long total = graph.weight(edgeID) - phi[next]
								+ phi[index] + length;
						if (id55[next] > total) {
							id55[next] = total;
							lastEdge[next] = edgeID;
						}
					}
				}
				edgeID = graph.nextOutbound(edgeID);
			}
		}
	}
}

class IntPair implements Comparable<IntPair> {
	public final int first, second;

	public IntPair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public String toString() {
		return "(" + first + "," + second + ")";
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		IntPair intPair = (IntPair) o;

		return first == intPair.first && second == intPair.second;

	}

	@Override
	public int hashCode() {
		int result = first;
		result = 31 * result + second;
		return result;
	}

	public int compareTo(IntPair o) {
		if (first < o.first)
			return -1;
		if (first > o.first)
			return 1;
		if (second < o.second)
			return -1;
		if (second > o.second)
			return 1;
		return 0;
	}
}

class IntArray extends IntList {
	private final int[] array;

	public IntArray(int[] array) {
		this.array = array;
	}

	public IntArray(IntCollection collection) {
		array = new int[collection.size()];
		int i = 0;
		for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator
				.advance())
			array[i++] = iterator.value();
	}

	@Override
	public int get(int index) {
		return array[index];
	}

	@Override
	public void set(int index, int value) {
		array[index] = value;
	}

	@Override
	public int size() {
		return array.length;
	}

	@Override
	public void add(int value) {
		throw new UnsupportedOperationException();
	}

}

abstract class id31 extends IntList {
	protected final IntComparator comparator;

	protected id31(IntComparator comparator) {
		this.comparator = comparator;
	}

	@Override
	public void set(int index, int value) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void add(int value) {
		throw new UnsupportedOperationException();
	}

	protected void ensureSorted() {
		int size = size();
		if (size == 0)
			return;
		int last = get(0);
		for (int i = 1; i < size; i++) {
			int current = get(i);
			if (comparator.compare(last, current) > 0)
				throw new IllegalArgumentException();
			last = current;
		}
	}

}

interface Edge {

}

abstract class IntCollection {
	public abstract IntIterator iterator();

	public abstract int size();

	public abstract void add(int value);

	public abstract void remove(int value);

	public int[] toArray() {
		int size = size();
		int[] array = new int[size];
		int i = 0;
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator
				.advance())
			array[i++] = iterator.value();
		return array;
	}

	public void addAll(IntCollection values) {
		for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
			add(it.value());
		}
	}

}

interface IntIterator {
	public int value() throws NoSuchElementException;

	public void advance() throws NoSuchElementException;

	public boolean isValid();
}

class id40 extends id31 {
	private final int[] array;

	public id40(IntCollection collection, IntComparator comparator) {
		super(comparator);
		array = new int[collection.size()];
		int i = 0;
		for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator
				.advance())
			array[i++] = iterator.value();
		ensureSorted();
	}

	@Override
	public int get(int index) {
		return array[index];
	}

	@Override
	public int size() {
		return array.length;
	}
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static <U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	@SuppressWarnings({ "unchecked" })
	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>) first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>) second).compareTo(o.second);
	}
}

class Heap {
	private IntComparator comparator;
	private int size = 0;
	private int[] elements;
	private int[] at;

	public Heap(int capacity, IntComparator comparator, int maxElement) {
		this.comparator = comparator;
		elements = new int[capacity];
		at = new int[maxElement];
		Arrays.fill(at, -1);
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public int add(int element) {
		ensureCapacity(size + 1);
		elements[size] = element;
		at[element] = size;
		shiftUp(size++);
		return at[element];
	}

	public void shiftUp(int index) {
		int value = elements[index];
		while (index != 0) {
			int parent = (index - 1) >>> 1;
			int parentValue = elements[parent];
			if (comparator.compare(parentValue, value) <= 0) {
				elements[index] = value;
				at[value] = index;
				return;
			}
			elements[index] = parentValue;
			at[parentValue] = index;
			index = parent;
		}
		elements[0] = value;
		at[value] = 0;
	}

	public void shiftDown(int index) {
		if (index < 0 || index >= size)
			throw new IllegalArgumentException();
		while (true) {
			int child = (index << 1) + 1;
			if (child >= size)
				return;
			if (child + 1 < size
					&& comparator.compare(elements[child], elements[child + 1]) > 0)
				child++;
			if (comparator.compare(elements[index], elements[child]) <= 0)
				return;
			swap(index, child);
			index = child;
		}
	}

	public int getIndex(int element) {
		return at[element];
	}

	private void swap(int first, int second) {
		int temp = elements[first];
		elements[first] = elements[second];
		elements[second] = temp;
		at[elements[first]] = first;
		at[elements[second]] = second;
	}

	private void ensureCapacity(int size) {
		if (elements.length < size) {
			int[] oldElements = elements;
			elements = new int[Math.max(2 * elements.length, size)];
			System.arraycopy(oldElements, 0, elements, 0, this.size);
		}
	}

	public int poll() {
		if (isEmpty())
			throw new IndexOutOfBoundsException();
		int result = elements[0];
		at[result] = -1;
		if (size == 1) {
			size = 0;
			return result;
		}
		elements[0] = elements[--size];
		at[elements[0]] = 0;
		shiftDown(0);
		return result;
	}

}

class IntegerUtils {

	public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

}

interface Function<A, V> {
	public abstract V value(A argument);
}