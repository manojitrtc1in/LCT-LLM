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
import java.util.InputMismatchException;
import java.util.Optional;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class CodeD {
  private static final boolean id6 = true;

  static final SuperWriter sw = new SuperWriter(System.out);

  static final SuperScanner sc = new SuperScanner();

  static class id8<E>
  {
      private Entry<E>[] table;
 
      private int count;
 
      private int threshold;
 
      private final float loadFactor;
 
      private static class Entry<E> {
          final int key;
          E value;
          Entry<E> next;
 
          private Entry(int key, E value, Entry<E> next) {
              this.key = key;
              this.value = value;
              this.next = next;
          }
      }
       
      public id8() {
          this(20, 0.75f);
      }
 
      @SuppressWarnings("unchecked")
      public id8(int initialCapacity, float loadFactor) 
      {
          this.loadFactor = loadFactor;
          table = new Entry[initialCapacity];
          threshold = (int) (initialCapacity * loadFactor);
      }
 
      public E get(int key) {
          Entry<E> tab[] = table;
          int hash = getHash(key);
          int index = (hash & 0x7FFFFFFF) % tab.length;
          for (Entry<E> e = tab[index]; e != null; e = e.next) {
              if (e.key == key) {
                  return e.value;
              }
          }
          return null;
      }
 
      protected void rehash() {
          int oldCapacity = table.length;
          Entry<E> oldMap[] = table;
 
          int newCapacity = oldCapacity * 2 + 1;
          @SuppressWarnings("unchecked")
          Entry<E> newMap[] = new Entry[newCapacity];
 
          threshold = (int) (newCapacity * loadFactor);
          table = newMap;
 
          for (int i = oldCapacity; i-- > 0;) {
              for (Entry<E> old = oldMap[i]; old != null;) {
                  Entry<E> e = old;
                  old = old.next;
                  int index = (getHash(e.key) & 0x7FFFFFFF) % newCapacity;
                  e.next = newMap[index];
                  newMap[index] = e;
              }
          }
      }
       
      public void put(int key, E newVal) 
      {
          Entry<E> tab[] = table;
          int hash = getHash(key);
          int index = (hash & 0x7FFFFFFF) % tab.length;
          for (Entry<E> e = tab[index]; e != null; e = e.next) {
              if (e.key == key) {
                  Object old = e.value;
                  e.value = newVal;
                  return;
              }
          }
 
          if (count >= threshold) {
              

              rehash();
 
              tab = table;
              index = (hash & 0x7FFFFFFF) % tab.length;
          }
 
          

          Entry<E> e = new Entry<E>(key, newVal, tab[index]);
          tab[index] = e;
          count++;
          return;
      }

      int getHash(int x) {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        return x;
      }
  }

  static class Node {
    final int number;
    boolean rooted = false;

    Node(int number) {
      this.number = number;
    }

    TreeSet<Integer> getBest() {
      Optional<Node> a = id9(2 * number);
      Optional<Node> b = id9(2 * number + 1);
      TreeSet<Integer> setA = a.isPresent() ? a.get().getBest() : new TreeSet<Integer>();
      TreeSet<Integer> setB = b.isPresent() ? b.get().getBest() : new TreeSet<Integer>();
      if (setA.size() > setB.size()) {
        for (int i : setB) {
          setA.add(i);
        }
      } else {
        for (int i : setA) {
          setB.add(i);
        }
        setA = setB;
      }
      if (rooted) {
        setA.add(number);
      } else {
        if (setA.size() > 0) {
          setA.pollLast();
          setA.add(number);
        }
      }
      return setA;
    }
  }

  static id8<Node> nodes = new id8<>();

  static Node getNode(int number) {
    if (nodes.get(number) == null) {
      nodes.put(number, new Node(number));
    }
    return nodes.get(number);
  }

  static Optional<Node> id9(int number) {
    if (nodes.get(number) == null) {
      return Optional.empty();
    }
    return Optional.of(nodes.get(number));
  }

  public static void main() {
    int n = sc.nextInt();
    int[] ys = sc.id10(n);
    for (int number : ys) {
      Node initial = getNode(number);
      initial.rooted = true;
      if (number == 1) {
        continue;
      }
      do {
        number >>= 1;
        getNode(number);
      } while (number != 1);
    }
    sw.printLine(getNode(1).getBest());
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

    public long[] id13() {
      fillTemp();
      long[] answer = new long[temp.size()];
      for (int i = 0; i < answer.length; i++) {
        answer[i] = Long.parseLong((String) temp.get(i));
      }
      temp.clear();
      return answer;
    }

    public double[] id16() {
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

    public LineScanner id14() {
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

    public int[] id10(int n) {
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

    public void id12(long[] array) {
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
        ans[i] = id10(m);
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

    public <T> T[] id15(Class<T> clazz, int size) {
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

    public boolean id11(Number... values) {
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