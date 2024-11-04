


import java.util.*;

public class Main implements Runnable {
    static ContestScanner in = new ContestScanner();
    static ContestPrinter out = new ContestPrinter();

    public static void main(String[] args) {
        new Thread(null, new Main(), "main", 1<<28).start();
    }

    public void run() {
        int tests = 1;
        for (int t = 0; t < tests; t++) {
            int n = in.nextInt();
            int[] a= in.id4(n);

            int queries = in.nextInt();
            int[] p = new int[queries];
            int[] x = new int[queries];
            for (int q = 0; q < queries; q++) {
                p[q] = in.nextInt() - 1;
                x[q] = in.nextInt();
            }

            long[] answers = getAnswers(n, a, queries, p, x);
            out.printArray(answers, "\n");
        }
        
        out.close();
    }

    private static long[] getAnswers(int n, int[] a, int queries, int[] p, int[] x) {
        int[] minDiff = new int[n];
        for (int i = 0; i < n; i++) {
            minDiff[i] = a[i] - (i + 1);
        }

        SparseTable st = new SparseTable(minDiff);
        List<List<Pair<Integer, Long>>> additionalPossible = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            additionalPossible.add(new ArrayList<>());
        }
        long[] id7 = new long[n + 1];
        long originalAnswer = 0;
        for (int i = 0; i < n; i++) {
            int left = i;
            int right = n - 1;

            int curr = i - 1;
            while (left <= right) {
                int mid = (left + right) >> 1;
                int min = st.getMin(i, mid);
                if (min >= -i) {
                    curr = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            int rangeSize = curr - i + 1;
            originalAnswer += rangeSize;
            id7[i+1] = id7[i] + rangeSize;

            if (curr == n - 2) {
                additionalPossible.get(n - 1).add(new Pair<Integer, Long>(curr + 2 - i, 1L));
            } else if (curr < n - 2) {
                left = curr + 2;
                right = n - 1;
                int next = curr + 1;
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    int min = st.getMin(curr + 2, mid);
                    if (min >= -i) {
                        next = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                int addition = 1 + next - (curr + 2) + 1;
                

                additionalPossible.get(curr + 1).add(new Pair<Integer, Long>(curr + 2 - i, (long) addition));
            }
        }
        

        

        

        

        

        

        for (int i = 0; i < n; i++) {
            long sum = 0;
            for (int j = additionalPossible.get(i).size() - 1; j >= 0; j--) {
                Pair<Integer, Long> pair = additionalPossible.get(i).get(j);
                sum += pair.getSecond();
                pair.setSecond(sum);
            }
        }

        

        

        

        

        

        


        

        

        

        long[] answers = new long[queries];
        for (int q = 0; q < queries; q++) {
            int idx = p[q];
            int val = x[q];
            if (val == a[idx]) {
                answers[q] = originalAnswer;
            } else if (a[idx] < val) {
                List<Pair<Integer, Long>> thisPossible = additionalPossible.get(idx);
                long addition = 0;
                int left = 0;
                int right = thisPossible.size() - 1;

                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (val >= thisPossible.get(mid).getFirst()) {
                        addition = thisPossible.get(mid).getSecond();
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                answers[q] = originalAnswer + addition;
            } else {
                

                int start = -1;
                int left = 0;
                int right = idx;
                

                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (st.getMin(mid, idx) >= -mid) {
                        start = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                

                if (start != -1) {
                    int newStart = Math.max(idx - val + 1, start);
                    

                    if (newStart > idx) {
                        long posDelta = getSum(1, idx - start);
                        long negDelta = id7[idx + 1] - id7[start];
                        answers[q] = originalAnswer + posDelta - negDelta;
                    } else {
                        long posDelta = getSum(idx - (newStart - 1), idx - start);
                        long negDelta = id7[newStart] - id7[start];
                        

                        answers[q] = originalAnswer + posDelta - negDelta;
                    }


                    

                    

                    

                    

                    

                    

                    

                } else {
                    answers[q] = originalAnswer;
                }
            }
        }

        return answers;
    }

    private static long getSum(int start, int end) {
        long add = (long) end * (end + 1) / 2;
        long sub = (long) (start - 1) * (start) / 2;
        return add - sub;
    }
}



class ContestScanner {
    private final java.io.InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private static final long id6 = 922337203685477580L;
    private static final int id2 = 7;
    private static final int id1 = 8;

    public ContestScanner(java.io.InputStream in){
        this.in = in;
    }
    public ContestScanner(java.io.File file) throws java.io.FileNotFoundException {
        this(new java.io.BufferedInputStream(new java.io.FileInputStream(file)));
    }
    public ContestScanner(){
        this(System.in);
    }

    private boolean id10() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (java.io.IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { 
        if (id10()) return buffer[ptr++]; else return -1;
    }
    private static boolean id12(int c) {
        return 33 <= c && c <= 126;
    }
    public boolean hasNext() {
        while(id10() && !id12(buffer[ptr])) ptr++;
        return id10();
    }
    public String next() {
        if (!hasNext()) throw new java.util.NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(id12(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
        if (!hasNext()) throw new java.util.NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                int digit = b - '0';
                if (n >= id6) {
                    if (n == id6) {
                        if (minus) {
                            if (digit <= id1) {
                                n = -n * 10 - digit;
                                b = readByte();
                                if (!id12(b)) {
                                    return n;
                                } else if (b < '0' || '9' < b) {
                                    throw new NumberFormatException(
                                        String.format("%d%s... is not number", n, Character.toString((char) b))
                                    );
                                }
                            }
                        } else {
                            if (digit <= id2) {
                                n = n * 10 + digit;
                                b = readByte();
                                if (!id12(b)) {
                                    return n;
                                } else if (b < '0' || '9' < b) {
                                    throw new NumberFormatException(
                                        String.format("%d%s... is not number", n, Character.toString((char) b))
                                    );
                                }
                            }
                        }
                    }
                    throw new ArithmeticException(
                        String.format("%s%d%d... overflows long.", minus ? "-" : "", n, digit)
                    );
                }
                n = n * 10 + digit;
            }else if(b == -1 || !id12(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long[] id11(int length){
        long[] array = new long[length];
        for(int i=0; i<length; i++) array[i] = this.nextLong();
        return array;
    }
    public long[] id11(int length, java.util.function.LongUnaryOperator map){
        long[] array = new long[length];
        for(int i=0; i<length; i++) array[i] = map.applyAsLong(this.nextLong());
        return array;
    }
    public int[] id4(int length){
        int[] array = new int[length];
        for(int i=0; i<length; i++) array[i] = this.nextInt();
        return array;
    }
    public int[] id4(int length, java.util.function.IntUnaryOperator map){
        int[] array = new int[length];
        for(int i=0; i<length; i++) array[i] = map.applyAsInt(this.nextInt());
        return array;
    }
    public double[] id9(int length){
        double[] array = new double[length];
        for(int i=0; i<length; i++) array[i] = this.nextDouble();
        return array;
    }
    public double[] id9(int length, java.util.function.DoubleUnaryOperator map){
        double[] array = new double[length];
        for(int i=0; i<length; i++) array[i] = map.applyAsDouble(this.nextDouble());
        return array;
    }

    public long[][] id3(int height, int width){
        long[][] mat = new long[height][width];
        for(int h=0; h<height; h++) for(int w=0; w<width; w++){
            mat[h][w] = this.nextLong();
        }
        return mat;
    }
    public int[][] id0(int height, int width){
        int[][] mat = new int[height][width];
        for(int h=0; h<height; h++) for(int w=0; w<width; w++){
            mat[h][w] = this.nextInt();
        }
        return mat;
    }
    public double[][] id8(int height, int width){
        double[][] mat = new double[height][width];
        for(int h=0; h<height; h++) for(int w=0; w<width; w++){
            mat[h][w] = this.nextDouble();
        }
        return mat;
    }

    public char[][] id5(int height, int width){
        char[][] mat = new char[height][width];
        for(int h=0; h<height; h++){
            String s = this.next();
            for(int w=0; w<width; w++){
                mat[h][w] = s.charAt(w);
            }
        }
        return mat;
    }
}



class ContestPrinter extends java.io.PrintWriter{
    public ContestPrinter(java.io.PrintStream stream){
        super(stream);
    }
    public ContestPrinter(java.io.File file) throws java.io.FileNotFoundException{
        super(new java.io.PrintStream(file));
    }
    public ContestPrinter(){
        super(System.out);
    }
    
    private static String dtos(double x, int n) {
        StringBuilder sb = new StringBuilder();
        if(x < 0){
            sb.append('-');
            x = -x;
        }
        x += Math.pow(10, -n)/2;
        sb.append((long)x);
        sb.append(".");
        x -= (long)x;
        for(int i = 0;i < n;i++){
            x *= 10;
            sb.append((int)x);
            x -= (int)x;
        }
        return sb.toString();
    }

    @Override
    public void print(float f){
        super.print(dtos(f, 20));
    }
    @Override
    public void println(float f){
        super.println(dtos(f, 20));
    }
    @Override
    public void print(double d){
        super.print(dtos(d, 20));
    }
    @Override
    public void println(double d){
        super.println(dtos(d, 20));
    }
    
    

    public void printArray(int[] array, String separator){
        int n = array.length;
        if(n==0){
            super.println();
            return;
        }
        for(int i=0; i<n-1; i++){
            super.print(array[i]);
            super.print(separator);
        }
        super.println(array[n-1]);
    }
    public void printArray(int[] array){
        this.printArray(array, " ");
    }
    public void printArray(int[] array, String separator, java.util.function.IntUnaryOperator map){
        int n = array.length;
        if(n==0){
            super.println();
            return;
        }
        for(int i=0; i<n-1; i++){
            super.print(map.applyAsInt(array[i]));
            super.print(separator);
        }
        super.println(map.applyAsInt(array[n-1]));
    }
    public void printArray(int[] array, java.util.function.IntUnaryOperator map){
        this.printArray(array, " ", map);
    }

    public void printArray(long[] array, String separator){
        int n = array.length;
        if(n==0){
            super.println();
            return;
        }
        for(int i=0; i<n-1; i++){
            super.print(array[i]);
            super.print(separator);
        }
        super.println(array[n-1]);
    }
    public void printArray(long[] array){
        this.printArray(array, " ");
    }
    public void printArray(long[] array, String separator, java.util.function.LongUnaryOperator map){
        int n = array.length;
        if(n==0){
            super.println();
            return;
        }
        for(int i=0; i<n-1; i++){
            super.print(map.applyAsLong(array[i]));
            super.print(separator);
        }
        super.println(map.applyAsLong(array[n-1]));
    }
    public void printArray(long[] array, java.util.function.LongUnaryOperator map){
        this.printArray(array, " ", map);
    }
    public <T> void printArray(T[] array, String separator){
        int n = array.length;
        if(n==0){
            super.println();
            return;
        }
        for(int i=0; i<n-1; i++){
            super.print(array[i]);
            super.print(separator);
        }
        super.println(array[n-1]);
    }
    public <T> void printArray(T[] array){
        this.printArray(array, " ");
    }
    public <T> void printArray(T[] array, String separator, java.util.function.UnaryOperator<T> map){
        int n = array.length;
        if(n==0){
            super.println();
            return;
        }
        for(int i=0; i<n-1; i++){
            super.print(map.apply(array[i]));
            super.print(separator);
        }
        super.println(map.apply(array[n-1]));
    }
    public <T> void printArray(T[] array, java.util.function.UnaryOperator<T> map){
        this.printArray(array, " ", map);
    }
}

class SparseTable {
    int[][] st;
    int[] lg;

    SparseTable(int[] arr) {
        int n = arr.length;
        lg = new int[n+1];
        lg[1] = 0;
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i >> 1] + 1;
        }
        int k = lg[n];

        st = new int[n][k + 1];
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = Math.min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int getMin(int left, int right) {
        int j = lg[right - left + 1];
        return Math.min(st[left][j], st[right - (1 << j) + 1][j]);
    }
}

class Pair<T1, T2> {
  private T1 first;
  private T2 second;
  public Pair(T1 first, T2 second) {
    setFirst(first);
    setSecond(second);
  }

  public T1 getFirst() {
    return first;
  }
  public T2 getSecond() {
    return second;
  }

  public void setFirst(T1 first) {
    this.first = first;
  }
  public void setSecond(T2 second) {
    this.second = second;
  }

  @Override
  public int hashCode() {
    final int prime = 7_243;
    int hash = first.hashCode() % prime;
    hash = (int) ((long) hash * second.hashCode() % prime);
    return hash;
  }

  @Override
  public boolean equals(Object obj) {
    if (obj instanceof Pair) {
      Pair<?, ?> other = (Pair<?, ?>) obj;
      return first.equals(other.getFirst()) && second.equals(other.getSecond());
    }
    return false;
  }
}

