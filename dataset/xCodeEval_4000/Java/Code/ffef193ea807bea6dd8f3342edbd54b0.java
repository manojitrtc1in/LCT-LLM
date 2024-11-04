import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.io.InputStream;


public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    QuickScanner in = new QuickScanner(inputStream);
    QuickWriter out = new QuickWriter(outputStream);
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskD {
    static final int HEAD = 17;
    static final int TAIL = 10007;
    int n;
    int m;
    Tree tree;
    DoubleHash[] hash;
    SmartMap cntMap;
    int res;
    int resIdx;
    List<DoubleHash> hashList;
    DoubleHash[] headHash;
    DoubleHash[] tailHash;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      n = in.nextInt();
      m = (n - 1) << 1;
      tree = new Tree(n);
      for (int i = 1; i < n; ++i) {
        tree.add(in.nextInt() - 1, in.nextInt() - 1);
      }
      hash = new DoubleHash[m];
      for (int i = 0; i < m; ++i) {
        hash[i] = DoubleHash.empty();
      }
      hashList = new ArrayList<>(n);
      cntMap = new SmartMap();
      dfs(0, -1, -1);
      headHash = new DoubleHash[n + 1];
      tailHash = new DoubleHash[n + 1];
      for (int i = 0; i <= n; ++i) {
        headHash[i] = DoubleHash.empty();
        tailHash[i] = DoubleHash.empty();
      }
      res = -1;
      dfsAgain(0, -1, null);
      out.println(resIdx + 1);


    }

    void dfs(int u, int parent, int parentEdgeIdx) {
      for (int edgeIdx = tree.lastOut(u); edgeIdx >= 0; edgeIdx = tree.nextOut(edgeIdx)) {
        int v = tree.toIdx(edgeIdx);
        if (v == parent) continue;
        dfs(v, u, edgeIdx);
      }
      if (parentEdgeIdx < 0) return;
      hashList.clear();
      for (int edgeIdx = tree.lastOut(u); edgeIdx >= 0; edgeIdx = tree.nextOut(edgeIdx)) {
        int v = tree.toIdx(edgeIdx);
        if (v == parent) continue;
        hashList.add(hash[edgeIdx]);
      }
      Collections.sort(hashList);
      DoubleHash hash = this.hash[parentEdgeIdx];
      hash.init(HEAD);
      for (DoubleHash value : hashList) {
        hash.addLast(value);
      }
      hash.addLast(TAIL);
      if (u > 0) cntMap.add(hash);
    }

    void dfsAgain(int u, int parent, DoubleHash parentHash) {


      if (res < cntMap.cnt) {
        res = cntMap.cnt;
        resIdx = u;
      }
      hashList.clear();
      if (u > 0) hashList.add(parentHash);
      for (int edgeIdx = tree.lastOut(u); edgeIdx >= 0; edgeIdx = tree.nextOut(edgeIdx)) {
        int v = tree.toIdx(edgeIdx);
        if (v == parent) continue;
        hashList.add(hash[edgeIdx]);
      }
      Collections.sort(hashList);
      headHash[0].init(HEAD);
      for (int i = 0; i < hashList.size(); ++i) {
        headHash[i + 1].init(headHash[i], hashList.get(i));
      }
      tailHash[hashList.size()].init(TAIL);
      for (int i = hashList.size() - 1; i >= 0; --i) {
        tailHash[i].init(hashList.get(i), tailHash[i + 1]);
      }
      for (int edgeIdx = tree.lastOut(u); edgeIdx >= 0; edgeIdx = tree.nextOut(edgeIdx)) {
        int v = tree.toIdx(edgeIdx);
        if (v == parent) continue;
        int idx = Collections.binarySearch(hashList, hash[edgeIdx]);
        if (idx < 0) throw new IllegalArgumentException();
        hash[edgeIdx ^ 1].init(headHash[idx], tailHash[idx + 1]);
      }
      for (int edgeIdx = tree.lastOut(u); edgeIdx >= 0; edgeIdx = tree.nextOut(edgeIdx)) {
        int v = tree.toIdx(edgeIdx);
        if (v == parent) continue;
        cntMap.remove(hash[edgeIdx]);
        cntMap.add(hash[edgeIdx ^ 1]);
        dfsAgain(v, u, hash[edgeIdx ^ 1]);
        cntMap.add(hash[edgeIdx]);
        cntMap.remove(hash[edgeIdx ^ 1]);
      }
    }

    class SmartMap {
      int cnt;
      Map<DoubleHash, Integer> cntMap;

      SmartMap() {
        cnt = 0;
        cntMap = new TreeMap<>();
      }

      void add(DoubleHash hash) {
        int oldCnt = cntMap.getOrDefault(hash, 0);
        cntMap.put(hash, oldCnt + 1);
        if (oldCnt == 0) ++cnt;
      }

      void remove(DoubleHash hash) {
        int oldCnt = cntMap.getOrDefault(hash, 0);
        if (oldCnt == 0) throw new IllegalArgumentException();
        cntMap.put(hash, oldCnt - 1);
        if (oldCnt == 1) --cnt;
      }

    }

  }

  static class IntArrayList implements IntCollection {
    private static final int[] EMPTY = {};
    public int[] values;
    public int size;

    public IntArrayList() {
      values = EMPTY;
      clear();
    }

    public IntArrayList(int capacity) {
      values = new int[IntUtils.nextPow2(capacity)];
      clear();
    }

    public IntArrayList(Collection<Integer> collection) {
      this(collection.size());
      addAll(collection);
    }


    public void clear() {
      size = 0;
    }


    public int size() {
      return size;
    }


    public void add(int value) {
      ensureCapacity(size + 1);
      addInternal(value);
    }


    public void addAll(Collection<Integer> values) {
      ensureCapacity(size + values.size());
      for (int value : values) {
        addInternal(value);
      }
    }

    public int peekLast() {
      return values[size - 1];
    }

    public int get(int idx) {
      if (idx >= size) throw new ArrayIndexOutOfBoundsException();
      return values[idx];
    }


    public String toString() {
      return IntArrayUtils.toString(values, 0, size);
    }

    public void ensureCapacity(int capacity) {
      if (capacity <= values.length) return;
      int[] newValues = new int[IntUtils.nextPow2(capacity)];
      for (int i = 0; i < size; ++i) {
        newValues[i] = values[i];
      }
      values = newValues;
    }

    private void addInternal(int value) {
      values[size++] = value;
    }

  }

  static abstract class AbstractTree extends AbstractBidirectionalGraph implements TreeInterface {
    public AbstractTree(int vertexCapacity) {
      super(vertexCapacity, vertexCapacity - 1);
    }

  }

  static interface BidirectionalGraphInterface extends DirectedGraphInterface {
  }

  static abstract class AbstractBidirectionalGraph extends AbstractDirectedGraph implements BidirectionalGraphInterface {
    public AbstractBidirectionalGraph(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity << 1);
    }

    public AbstractBidirectionalGraph(int vertexCapacity, int edgeCapacity, boolean initialize) {
      super(vertexCapacity, edgeCapacity << 1, initialize);
    }


    public void add(int u, int v) {
      super.add(u, v);
      super.add(v, u);
    }

  }

  static class IntUtils {
    public static boolean isPow2(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }

    public static int nextPow2(int n) {
      if (n < 1) return 1;
      return isPow2(n) ? n : Integer.highestOneBit(n) << 1;
    }

  }

  static class QuickScanner {
    private static final int BUFFER_SIZE = 1024;
    private InputStream stream;
    private byte[] buffer;
    private int currentPosition;
    private int numberOfChars;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.currentPosition = 0;
      this.numberOfChars = 0;
    }

    public int nextInt() {
      int c = nextNonSpaceChar();
      boolean positive = true;
      if (c == '-') {
        positive = false;
        c = nextChar();
      }
      int res = 0;
      do {
        if (c < '0' || '9' < c) throw new RuntimeException();
        res = res * 10 + c - '0';
        c = nextChar();
      } while (!isSpaceChar(c));
      return positive ? res : -res;
    }

    public int nextNonSpaceChar() {
      int res = nextChar();
      for (; isSpaceChar(res) || res < 0; res = nextChar()) ;
      return res;
    }

    public int nextChar() {
      if (numberOfChars == -1) {
        throw new RuntimeException();
      }
      if (currentPosition >= numberOfChars) {
        currentPosition = 0;
        try {
          numberOfChars = stream.read(buffer);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        if (numberOfChars <= 0) {
          return -1;
        }
      }
      return buffer[currentPosition++];
    }

    public boolean isSpaceChar(int c) {
      return c == ' ' || c == '\t' || isEndOfLineChar(c);
    }

    public boolean isEndOfLineChar(int c) {
      return c == '\n' || c == '\r' || c < 0;
    }

  }

  static class DoubleHash implements Comparable<DoubleHash> {
    private static final int BASE1 = 99999989;
    private static final int BASE2 = 99999971;
    private static final IntModular MOD1 = new IntModular(1000000007);
    private static final IntModular MOD2 = new IntModular(1000000009);
    private static final IntArrayList POW1 = new IntArrayList();
    private static final IntArrayList POW2 = new IntArrayList();
    private int length;
    private int hash1;
    private int hash2;

    public DoubleHash(int length, int hash1, int hash2) {
      this.length = length;
      this.hash1 = hash1;
      this.hash2 = hash2;
    }

    public static DoubleHash empty() {
      return new DoubleHash(0, 0, 0);
    }

    public void init(int value) {
      assign(1, MOD1.fix(value), MOD2.fix(value));
    }

    public void init(DoubleHash l, DoubleHash r) {
      ensurePowCapacity(r.length);
      assign(
          l.length + r.length,
          MOD1.add(MOD1.mul(l.hash1, POW1.get(r.length)), r.hash1),
          MOD2.add(MOD2.mul(l.hash2, POW2.get(r.length)), r.hash2));
    }

    public void addLast(int value) {
      hash1 = MOD1.add(MOD1.mul(hash1, BASE1), value);
      hash2 = MOD2.add(MOD2.mul(hash2, BASE2), value);
      ++length;
    }

    public void addLast(DoubleHash o) {
      ensurePowCapacity(o.length);
      length += o.length;
      hash1 = MOD1.add(MOD1.mul(hash1, POW1.get(o.length)), o.hash1);
      hash2 = MOD2.add(MOD2.mul(hash2, POW2.get(o.length)), o.hash2);
    }


    public int compareTo(DoubleHash o) {
      if (length != o.length) return length - o.length;
      if (hash1 != o.hash1) return hash1 - o.hash1;
      return hash2 - o.hash2;
    }


    public String toString() {
      return String.format("length:%d hash:(%d,%d)", length, hash1, hash2);
    }

    private void assign(int length, int hash1, int hash2) {
      this.length = length;
      this.hash1 = hash1;
      this.hash2 = hash2;
    }

    private void ensurePowCapacity(int length) {
      if (POW1.size > length) return;
      if (POW1.isEmpty()) {
        POW1.add(1);
        POW2.add(1);
      }
      for (int i = POW1.size; i <= length; ++i) {
        POW1.add(MOD1.mul(POW1.peekLast(), BASE1));
        POW2.add(MOD2.mul(POW2.peekLast(), BASE2));
      }
    }

  }

  static interface IntCollection {
    int size();

    default boolean isEmpty() {
      return size() == 0;
    }

  }

  static class IntModular {
    private static final int MOD = 1000000007;
    public final int mod;
    private final int[] x;

    public IntModular() {
      this(MOD);
    }

    public IntModular(int mod) {
      this.mod = mod;
      this.x = new int[2];
    }

    public int add(int a, int b) {
      return fix(a + b);
    }

    public int fix(int a) {
      a = slightFix(a);
      return 0 <= a && a < mod ? a : slightFix(a % mod);
    }

    public int mul(int a, int b) {
      return a > 0
          ? (b < mod / a ? a * b : (int) ((long) a * b % mod))
          : 0;
    }

    private int slightFix(int a) {
      return a >= mod
          ? a - mod
          : a < 0 ? a + mod : a;
    }

  }

  static abstract class AbstractDirectedGraph implements DirectedGraphInterface {
    protected int vertexCnt;
    protected int currentEdgeCnt;
    protected int[] fromIdx;
    protected int[] toIdx;
    protected int[] nextIn;
    protected int[] nextOut;
    protected int[] lastIn;
    protected int[] lastOut;
    protected int[] inDegree;
    protected int[] outDegree;

    public abstract void createSubclass(int vertexCapacity, int edgeCapacity);

    public abstract void initSubclass(int vertexCnt);

    public AbstractDirectedGraph(int vertexCapacity, int edgeCapacity) {
      this(vertexCapacity, edgeCapacity, true);
    }

    public AbstractDirectedGraph(int vertexCapacity, int edgeCapacity, boolean initialize) {
      fromIdx = new int[edgeCapacity];
      toIdx = new int[edgeCapacity];
      lastIn = new int[vertexCapacity];
      lastOut = new int[vertexCapacity];
      nextIn = new int[edgeCapacity];
      nextOut = new int[edgeCapacity];
      inDegree = new int[vertexCapacity];
      outDegree = new int[vertexCapacity];
      createSubclass(vertexCapacity, edgeCapacity);
      if (initialize) init(vertexCapacity);
    }


    public void init(int vertexCnt) {
      this.vertexCnt = vertexCnt;
      currentEdgeCnt = 0;
      Arrays.fill(inDegree, 0, vertexCnt, 0);
      Arrays.fill(outDegree, 0, vertexCnt, 0);
      Arrays.fill(lastIn, 0, vertexCnt, -1);
      Arrays.fill(lastOut, 0, vertexCnt, -1);
      initSubclass(vertexCnt);
    }


    public void add(int fromIdx, int toIdx) {
      this.fromIdx[currentEdgeCnt] = fromIdx;
      this.toIdx[currentEdgeCnt] = toIdx;
      ++outDegree[fromIdx];
      ++inDegree[toIdx];
      nextOut[currentEdgeCnt] = lastOut[fromIdx];
      lastOut[fromIdx] = currentEdgeCnt;
      nextIn[currentEdgeCnt] = lastIn[toIdx];
      lastIn[toIdx] = currentEdgeCnt;
      ++currentEdgeCnt;
    }


    public int toIdx(int edgeIdx) {
      return toIdx[edgeIdx];
    }


    public int lastOut(int nodeIdx) {
      return lastOut[nodeIdx];
    }


    public int nextOut(int edgeIdx) {
      return nextOut[edgeIdx];
    }

  }

  static interface TreeInterface extends BidirectionalGraphInterface {
  }

  static class IntArrayUtils {
    public static String toString(int[] values, int fromIdx, int toIdx) {
      StringBuilder sb = new StringBuilder("[");
      for (int i = fromIdx; i < toIdx; ++i) {
        if (i != fromIdx) sb.append(", ");
        sb.append(values[i]);
      }
      return sb.append("]").toString();
    }

  }

  static class Tree extends AbstractTree {
    public Tree(int vertexCapacity) {
      super(vertexCapacity);
    }


    public void createSubclass(int vertexCapacity, int edgeCapacity) {
    }


    public void initSubclass(int vertexCnt) {
    }

  }

  static interface DirectedGraphInterface {
  }

  static class QuickWriter {
    private final PrintWriter writer;

    public QuickWriter(OutputStream outputStream) {
      this.writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public QuickWriter(Writer writer) {
      this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
      for (int i = 0; i < objects.length; ++i) {
        if (i > 0) {
          writer.print(' ');
        }
        writer.print(objects[i]);
      }
    }

    public void println(Object... objects) {
      print(objects);
      writer.print('\n');
    }

    public void close() {
      writer.close();
    }

  }
}

