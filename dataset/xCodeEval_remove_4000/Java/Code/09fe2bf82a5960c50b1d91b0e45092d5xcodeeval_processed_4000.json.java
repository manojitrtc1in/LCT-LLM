import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.lang.reflect.Constructor;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class CodeD {
  private static final boolean id6 = false;

  static final SuperWriter sw = new SuperWriter(System.out);

  static final SuperScanner sc = new SuperScanner();


  static class Rational implements Comparable <Rational> 
  {
      static Rational zero = new Rational(0, 1);
      
      private long num;
      private long den;

      public Rational(long numerator, long denominator) {
          long g = gcd(numerator, denominator);
          num = numerator   / g;
          den = denominator / g;
          if (den < 0) { den = -den; num = -num; }
      }

      public long numerator()   { return num; }
      public long denominator() { return den; }

      public String toString() { 
          if (den == 1) return num + "";
          else          return num + "/" + den;
      }

      public int compareTo(Rational b) {
          Rational a = this;
          long lhs = a.num * b.den;
          long rhs = a.den * b.num;
          if (lhs < rhs) return -1;
          if (lhs > rhs) return +1;
          return 0;
      }

      public boolean equals(Object y) {
          Rational b = (Rational) y;
          return compareTo(b) == 0;
      }

      public int hashCode() {
          return this.toString().hashCode();
      }

      private long gcd(long m, long n) {
          if (m < 0) m = -m;
          if (n < 0) n = -n;
          if (0 == n) return m;
          else return gcd(n, m % n);
      }

      public long lcm(long m, long n) {
          if (m < 0) m = -m;
          if (n < 0) n = -n;
          return m * (n / gcd(m, n)); 
      }

      public Rational times(Rational b) {
          Rational a = this;
          Rational c = new Rational(a.num, b.den);
          Rational d = new Rational(b.num, a.den);
          return new Rational(c.num * d.num, c.den * d.den);
      }
      
      public Rational plus(Rational b) {
          Rational a = this;
          if (a.compareTo(zero) == 0) return b;
          if (b.compareTo(zero) == 0) return a;
          long f = gcd(a.num, b.num);
          long g = gcd(a.den, b.den);
          
          Rational s = 
          new Rational((a.num / f) * (b.den / g) + (b.num / f) * (a.den / g),
          lcm(a.den, b.den));
          
          s.num *= f;
          return s;
      }

      public Rational negate() {
          return new Rational(-num, den);
      }

      public Rational minus(Rational b) {
          Rational a = this;
          return a.plus(b.negate());
      }

      public Rational id16() { return new Rational(den, num);  }

      public Rational divides(Rational b) {
          Rational a = this;
          return a.times(b.id16());
      }
      
      public Rational abs() {
          if(num < 0)
              return negate();
          else
              return this;
      }
  }

  static class Line {
    Rational slope;
    long lengthSquare;
    boolean id8;
    Integer hash;

    Line(long x1, long y1, long x2, long y2) {
      lengthSquare = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
      if (x1 == x2) {
        id8 = true;
        slope = new Rational(0, 1);
      } else {
        id8 = false;
        slope = new Rational(y2 - y1, x2 - x1);
      }
    }

    @Override
    public int hashCode() {
      if (hash != null) {
        return hash;
      }
      final int prime = 31;
      int result = 1;
      result = prime * result + (id8 ? 1231 : 1237);
      result = prime * result + (int) (lengthSquare ^ (lengthSquare >>> 32));
      result = prime * result + slope.hashCode();
      return hash = result;
    }

    @Override
    public boolean equals(Object obj) {
      Line other = (Line) obj;
      if (lengthSquare != other.lengthSquare) return false;
      if (id8 != other.id8) return false;
      return slope.equals(other.slope);
    }
  }

  public static void main() {
    int n = sc.nextInt();
    int[][] points = sc.id0(n, 2);
    HashMap<Line, Long> lines = new HashMap<Line, Long>();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        long x1 = points[i][0];
        long y1 = points[i][1];
        long x2 = points[j][0];
        long y2 = points[j][1];

        Line line = new Line(x1, y1, x2, y2);
        if (!lines.containsKey(line)) {
          lines.put(line, 0L);
        }
        lines.put(line, lines.get(line) + 1L);
      }
    }
    long answer = 0;
    for (long value : lines.values()) {
      answer += value * (value - 1L);
    }
    sw.printLine(answer / 4L);
  }

  static class LineScanner extends Scanner {
    private StringTokenizer st;

    public LineScanner(String input) {
      st = new StringTokenizer(input);
    }

    @Override
    public String next() {
      return st.hasMoreTokens() ? st.nextToken() : null;
    }

    @Override
    public String nextLine() {
      throw new RuntimeException("not supported");
    }

    public boolean hasNext() {
      return st.hasMoreTokens();
    }

    private final ArrayList<Object> temp = new ArrayList<Object>();

    private void fillTemp() {
      while (st.hasMoreTokens()) {
        temp.add(st.nextToken());
      }
    }

    public String[] id1() {
      fillTemp();
      String[] answer = new String[temp.size()];
      for (int i = 0; i < answer.length; i++) {
        answer[i] = (String) temp.get(i);
      }
      temp.clear();
      return answer;
    }

    public int[] id17() {
      fillTemp();
      int[] answer = new int[temp.size()];
      for (int i = 0; i < answer.length; i++) {
        answer[i] = Integer.parseInt((String) temp.get(i));
      }
      temp.clear();
      return answer;
    }

    public long[] id12() {
      fillTemp();
      long[] answer = new long[temp.size()];
      for (int i = 0; i < answer.length; i++) {
        answer[i] = Long.parseLong((String) temp.get(i));
      }
      temp.clear();
      return answer;
    }

    public double[] id15() {
      fillTemp();
      double[] answer = new double[temp.size()];
      for (int i = 0; i < answer.length; i++) {
        answer[i] = Double.parseDouble((String) temp.get(i));
      }
      temp.clear();
      return answer;
    }
  }

  static class SuperScanner extends Scanner {
    private InputStream stream;
    private byte[] buf = new byte[8096];
    private int curChar;
    private int numChars;

    public SuperScanner() {
        this.stream = System.in;
    }

    public int read() {
        if (numChars == -1)
            return -1;
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
    
    public static boolean isWhitespace(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public static boolean id4(int c) {
      return c == '\n' || c == -1;
    }
    
    private final StringBuilder sb = new StringBuilder();
    
    @Override
    public String next() {
      int c = read();
      while (isWhitespace(c)) {
          if (c == -1) {
            return null;
          }
          c = read();
      }
      sb.setLength(0);
      do {
          sb.append((char) c);
          c = read();
      } while (!isWhitespace(c));
      return sb.toString();
    }

    @Override
    public String nextLine() {
      sb.setLength(0);
      int c;
      while (true) {
        c = read();
        if (!id4(c)) {
          sb.append((char) c);
        } else {
          break;
        }
      }
      if (c == -1 && sb.length() == 0) {
        return null;
      } else {
        if (sb.length() > 0 && sb.charAt(sb.length() - 1) == '\r') {
          return sb.substring(0, sb.length() - 1);
        } else {
          return sb.toString();
        }
      }
    }

    public LineScanner id13() {
      String line = nextLine();
      if (line == null) {
        return null;
      } else {
        return new LineScanner(line);
      }
    }

    public LineScanner id5() {
      while (true) {
        String line = nextLine();
        if (line == null) {
          return null;
        } else if (!line.isEmpty()) {
          return new LineScanner(line);
        }
      }
    }

    @Override
    public int nextInt() {
        int c = read();
        while (isWhitespace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res = (res << 3) + (res << 1);
            res += c - '0';
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    @Override
    public long nextLong() {
        int c = read();
        while (isWhitespace(c))
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
            res = (res << 3) + (res << 1);
            res += c - '0';
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }
  }
  
  static abstract class Scanner {

    public abstract String next();

    public abstract String nextLine();

    public int id7() {
      Integer n = nextInteger();
      if (n == null) {
        sw.close();
        System.exit(0);
      }
      return n.intValue();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }

    public int[] id9(int n) {
      int[] res = new int[n];
      for (int i = 0; i < res.length; i++)
        res[i] = nextInt();
      return res;
    }

    public long[] id20(int n) {
      long[] res = new long[n];
      for (int i = 0; i < res.length; i++)
        res[i] = nextLong();
      return res;
    }

    public double[] id18(int n) {
      double[] res = new double[n];
      for (int i = 0; i < res.length; i++)
        res[i] = nextDouble();
      return res;
    }

    public void id2(int[] array) {
      Integer[] vals = new Integer[array.length];
      for (int i = 0; i < array.length; i++)
        vals[i] = array[i];
      Arrays.sort(vals);
      for (int i = 0; i < array.length; i++)
        array[i] = vals[i];
    }

    public void id11(long[] array) {
      Long[] vals = new Long[array.length];
      for (int i = 0; i < array.length; i++)
        vals[i] = array[i];
      Arrays.sort(vals);
      for (int i = 0; i < array.length; i++)
        array[i] = vals[i];
    }

    public void id3(double[] array) {
      Double[] vals = new Double[array.length];
      for (int i = 0; i < array.length; i++)
        vals[i] = array[i];
      Arrays.sort(vals);
      for (int i = 0; i < array.length; i++)
        array[i] = vals[i];
    }

    public String[] id19(int n) {
      String[] vals = new String[n];
      for (int i = 0; i < n; i++)
        vals[i] = next();
      return vals;
    }

    public Integer nextInteger() {
      String s = next();
      if (s == null)
        return null;
      return Integer.parseInt(s);
    }

    public int[][] id0(int n, int m) {
      int[][] ans = new int[n][];
      for (int i = 0; i < n; i++)
        ans[i] = id9(m);
      return ans;
    }

    public char[][] nextGrid(int r) {
      char[][] grid = new char[r][];
      for (int i = 0; i < r; i++)
        grid[i] = next().toCharArray();
      return grid;
    }

    public static <T> T fill(T arreglo, int val) {
      if (arreglo instanceof Object[]) {
        Object[] a = (Object[]) arreglo;
        for (Object x : a)
          fill(x, val);
      } else if (arreglo instanceof int[])
        Arrays.fill((int[]) arreglo, val);
      else if (arreglo instanceof double[])
        Arrays.fill((double[]) arreglo, val);
      else if (arreglo instanceof long[])
        Arrays.fill((long[]) arreglo, val);
      return arreglo;
    }

    public <T> T[] id14(Class<T> clazz, int size) {
      @SuppressWarnings("unchecked")
      T[] result = (T[]) java.lang.reflect.Array.newInstance(clazz, size);
      for (int c = 0; c < 3; c++) {
        Constructor<T> constructor;
        try {
          if (c == 0)
            constructor = clazz.getDeclaredConstructor(Scanner.class,
                Integer.TYPE);
          else if (c == 1)
            constructor = clazz.getDeclaredConstructor(Scanner.class);
          else
            constructor = clazz.getDeclaredConstructor();
        } catch (Exception e) {
          continue;
        }
        try {
          for (int i = 0; i < result.length; i++) {
            if (c == 0)
              result[i] = constructor.newInstance(this, i);
            else if (c == 1)
              result[i] = constructor.newInstance(this);
            else
              result[i] = constructor.newInstance();
          }
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        return result;
      }
      throw new RuntimeException("Constructor not found");
    }

    public Collection<Integer> wrap(int[] as) {
      ArrayList<Integer> ans = new ArrayList<Integer>();
      for (int i : as)
        ans.add(i);
      return ans;
    }

    public int[] unwrap(Collection<Integer> collection) {
      int[] vals = new int[collection.size()];
      int index = 0;
      for (int i : collection)
        vals[index++] = i;
      return vals;
    }

    int testCases = Integer.MIN_VALUE;

    boolean testCases() {
      if (testCases == Integer.MIN_VALUE) {
        testCases = nextInt();
      }
      return --testCases >= 0;
    }
  }

  static class SuperWriter {

    private final PrintWriter writer;

    public SuperWriter(OutputStream outputStream) {
      writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public SuperWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void close() {
        writer.flush();
        writer.close();
    }

    public void printLine(String line) {
      writer.println(line);
      if (!id6) {
        writer.flush();
      }
    }

    public void printLine(int... vals) {
      if (vals.length == 0) {
        writer.println();
      } else {
        writer.print(vals[0]);
        for (int i = 1; i < vals.length; i++)
          writer.print(" ".concat(String.valueOf(vals[i])));
        writer.println();
      }
      if (!id6) {
        writer.flush();
      }
    }

    public void printLine(long... vals) {
      if (vals.length == 0) {
        writer.println();
      } else {
        writer.print(vals[0]);
        for (int i = 1; i < vals.length; i++)
          writer.print(" ".concat(String.valueOf(vals[i])));
        writer.println();
      }
      if (!id6) {
        writer.flush();
      }
    }

    public void printLine(double... vals) {
      if (vals.length == 0) {
        writer.println();
      } else {
        writer.print(vals[0]);
        for (int i = 1; i < vals.length; i++)
          writer.print(" ".concat(String.valueOf(vals[i])));
        writer.println();
      }
      if (!id6) {
        writer.flush();
      }
    }

    public void printLine(int prec, double... vals) {
      if (vals.length == 0) {
        writer.println();
      } else {
        String precision = "%." + prec + "f";
        writer.print(String.format(precision, vals[0]).replace(',', '.'));
        precision = " " + precision;
        for (int i = 1; i < vals.length; i++)
          writer.print(String.format(precision, vals[i]).replace(',', '.'));
        writer.println();
      }
      if (!id6) {
        writer.flush();
      }
    }

    public <E> void printLine(Collection<E> vals) {
      if (vals.size() == 0) {
        writer.println();
      } else {
        int i = 0;
        for (E val : vals) {
          if (i++ == 0) {
            writer.print(val.toString());
          } else {
            writer.print(" ".concat(val.toString()));
          }
        }
        writer.println();
      }
      if (!id6) {
        writer.flush();
      }
    }

    public void printSimple(String value) {
      writer.print(value);
      if (!id6) {
        writer.flush();
      }
    }

    public boolean id10(Number... values) {
    	for (Number number : values) {
    		if (number.doubleValue() != 0.0d || number.longValue() != 0) {
    			return false;
    		}
    	}
    	close();
    	System.exit(0);
    	return true;
    }
  }


  public static void main(String[] args) {
    main();
    sw.close();
  }
}
