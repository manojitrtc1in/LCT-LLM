


import java.io.*;
import java.util.*;


public class D {

    int MAXN = 200_000;
    int[] a = new int[MAXN + 1];

    private void solve_() {

        int n = reader.readInt();

        for (int i = 1; i <= n; i++) {
            a[i] = reader.readInt();
        }

        Set<Integer> id19 = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            id19.add(i);
        }

        Map<Integer, id4> id11 = new HashMap<>();

        for (int i = 1; i <= n; i++) {
            int wish = a[i];
            if (!id11.containsKey(wish)) {
                id11.put(wish, new id4());
            }
            id11.get(wish).add(i);
            id19.remove(wish);
        }

        int k = id11.size();

        int[] ans = new int[n + 1];
        for (int wish : id11.keySet()) {
            int size = id11.get(wish).size();
            if (size == 1) {
                int ind = id11.get(wish).getFirst();
                ans[ind] = wish;
            }
        }

        for (int i = 0, ansLength = ans.length; i < ansLength; i++) {
            int an = ans[i];
            if (an != 0) {
                id11.remove(an);
            }
        }

        ArrayDeque<Map.Entry<Integer, id4>> deque = new ArrayDeque<>();
        for(int wish : id11.keySet()) {
            id4 indexes = id11.get(wish);
            deque.addLast(new AbstractMap.SimpleEntry<>(wish, indexes));
        }




        for (final int id13 : id19) {
            




            

            

            


            

            


            int wish = deque.getFirst().getKey();
            id4 indexes = deque.getFirst().getValue();


            int first = indexes.removeFirst();
            int second = indexes.removeFirst();

            if (id13 != first) {
                indexes.addLast(second);
                ans[first] = id13;
            } else if (id13 != second) {
                indexes.addLast(first);
                ans[second] = id13;
            }

            if (indexes.size() == 1) {
                int ind2 = indexes.getFirst();
                ans[ind2] = wish;
                deque.removeFirst();
            }

        }
        writer.writeln(k);
        for (int i = 1; i <= n; i++) {
            writer.write(ans[i]).write(' ');
        }
        writer.writeln();
    }


    public class id4 {

        int[] elements;

        int head;
        int tail;

        private final int id17 = 8;

        private int calculateSize(int numElements) {
            int initialCapacity = id17;
            

            

            if (numElements >= initialCapacity) {
                initialCapacity = numElements;
                initialCapacity |= (initialCapacity >>>  1);
                initialCapacity |= (initialCapacity >>>  2);
                initialCapacity |= (initialCapacity >>>  4);
                initialCapacity |= (initialCapacity >>>  8);
                initialCapacity |= (initialCapacity >>> 16);
                initialCapacity++;

                if (initialCapacity < 0)   

                    initialCapacity >>>= 1;

            }
            return initialCapacity;
        }

        private void allocateElements(int numElements) {
            elements = new int[calculateSize(numElements)];
        }

        private void doubleCapacity() {
            assert head == tail;
            int p = head;
            int n = elements.length;
            int r = n - p; 

            int newCapacity = n << 1;
            if (newCapacity < 0)
                throw new IllegalStateException("Sorry, deque too big");
            int[] a = new int[newCapacity];
            System.arraycopy(elements, p, a, 0, r);
            System.arraycopy(elements, 0, a, r, p);
            elements = a;
            head = 0;
            tail = n;
        }

        private  int[] copyElements(int[] a) {
            if (head < tail) {
                System.arraycopy(elements, head, a, 0, size());
            } else if (head > tail) {
                int id16 = elements.length - head;
                System.arraycopy(elements, head, a, 0, id16);
                System.arraycopy(elements, 0, a, id16, tail);
            }
            return a;
        }


        public id4() {






            elements = new int[16];
        }

        public id4(int numElements) {
            allocateElements(numElements);
        }

        public int size() {
            return (tail - head) & (elements.length - 1);
        }
        public boolean isEmpty() {
            return head == tail;
        }

        public void add(int a) {
            addLast(a);
        }

        private void ensure(int i) {
            if (elements.length == i || -1 == i) {
                int len = elements.length;
                int[] newArr = new int[3 * len];
                

                System.arraycopy(elements, 0, newArr, len, len);
                elements = newArr;
                head += len;
                tail += len;
            }
        }

        public void addLast(int e) {




            elements[tail] = e;
            if ( (tail = (tail + 1) & (elements.length - 1)) == head)
                doubleCapacity();
        }

        public void addFirst(int e) {




            elements[head = (head - 1) & (elements.length - 1)] = e;
            if (head == tail)
                doubleCapacity();
        }

        public int getFirst() {
            

            return elements[head];
        }

        public int getLast() {
            

            return elements[(tail - 1) & (elements.length - 1)];
        }

        public int removeFirst() {
            int h = head;


            int result =  elements[h];
            







            head = (h + 1) & (elements.length - 1);
            return result;
            

        }

        public int removeLast() {
            int t = (tail - 1) & (elements.length - 1);
            

            int result = elements[t];






            tail = t;
            return result;
            

        }


        @Override
        public String toString() {
            return "id4{ " + Arrays.toString(elements) + " }";
        }
    }



    private void solve() {
        int t = reader.readInt();
        for (int i = 0; i < t; i++) {
            solve_();
        }
    }

    public static void main(String[] args) {
        new D().run();
    }

    private InputReader reader;
    private FastWriter writer;

    private void run() {
        reader = new InputReader(System.in);
        writer = new FastWriter(System.out);
        solve();
        writer.flush();
    }

    private static class FastWriter {
        private static final int BUF_SIZE = 8192;

        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private FastWriter() {
            this(System.out);
        }

        public FastWriter(OutputStream os) {
            this.out = os;
        }

        public FastWriter(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public FastWriter write(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public FastWriter write(char c) {
            return write((byte) c);
        }

        public FastWriter write(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public FastWriter write(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }

        public FastWriter write0(char[] s) {
            if (ptr + s.length < BUF_SIZE) {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                }
            } else {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                    if (ptr == BUF_SIZE) innerflush();
                }
            }
            return this;
        }

        public FastWriter write0(String s) {
            if (ptr + s.length() < BUF_SIZE) {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                }
            } else {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                    if (ptr == BUF_SIZE) innerflush();
                }
            }
            return this;
        }

        private static int countDigits(int l) {
            if (l >= 1000000000) return 10;
            if (l >= 100000000) return 9;
            if (l >= 10000000) return 8;
            if (l >= 1000000) return 7;
            if (l >= 100000) return 6;
            if (l >= 10000) return 5;
            if (l >= 1000) return 4;
            if (l >= 100) return 3;
            if (l >= 10) return 2;
            return 1;
        }

        public FastWriter write(int x) {
            if (x == Integer.MIN_VALUE) {
                return write((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        private static int countDigits(long l) {
            if (l >= 1000000000000000000L) return 19;
            if (l >= 100000000000000000L) return 18;
            if (l >= 10000000000000000L) return 17;
            if (l >= 1000000000000000L) return 16;
            if (l >= 100000000000000L) return 15;
            if (l >= 10000000000000L) return 14;
            if (l >= 1000000000000L) return 13;
            if (l >= 100000000000L) return 12;
            if (l >= 10000000000L) return 11;
            if (l >= 1000000000L) return 10;
            if (l >= 100000000L) return 9;
            if (l >= 10000000L) return 8;
            if (l >= 1000000L) return 7;
            if (l >= 100000L) return 6;
            if (l >= 10000L) return 5;
            if (l >= 1000L) return 4;
            if (l >= 100L) return 3;
            if (l >= 10L) return 2;
            return 1;
        }

        public FastWriter write(long x) {
            if (x == Long.MIN_VALUE) {
                return write("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        public FastWriter write(double x, int precision) {
            if (x < 0) {
                write('-');
                x = -x;
            }
            x += Math.pow(10, -precision) / 2;
            

            write((long) x).write(".");
            x -= (long) x;
            for (int i = 0; i < precision; i++) {
                x *= 10;
                write((char) ('0' + (int) x));
                x -= (int) x;
            }
            return this;
        }

        public FastWriter writeln(char c) {
            return write(c).writeln();
        }

        public FastWriter writeln(int x) {
            return write(x).writeln();
        }

        public FastWriter writeln(long x) {
            return write(x).writeln();
        }

        public FastWriter writeln(String x) {
            return write(x).writeln();
        }

        public FastWriter writeln(double x, int precision) {
            return write(x, precision).writeln();
        }

        public FastWriter writeln() {
            return write((byte) '\n');
        }

        private void innerflush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerflush");
            }
        }

        public void flush() {
            innerflush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }
    }

    private static class InputReader {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id24 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public double[] id3(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id22(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] id6(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }
































        public void id12(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
        }

        public void id14(long[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readLong();
                }
            }
        }

        public void id18(double[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readDouble();
                }
            }
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id6(columnCount);
            }
            return table;
        }

        public int[][] id9(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id1(columnCount);
            }
            return table;
        }

        public double[][] id0(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id3(columnCount);
            }
            return table;
        }

        public long[][] id2(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id10(columnCount);
            }
            return table;
        }

        public String[][] id20(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id22(columnCount);
            }
            return table;
        }

        public String readText() {
            StringBuilder result = new StringBuilder();
            while (true) {
                int character = read();
                if (character == '\r') {
                    continue;
                }
                if (character == -1) {
                    break;
                }
                result.append((char) character);
            }
            return result.toString();
        }

        public void id15(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id10(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public int[] id1(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }
























        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int peek() {
            if (numChars == -1) {
                return -1;
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar];
        }

        public int id23() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id8(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id8(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id8(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id8(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id8(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id8(c));
            return res.toString();
        }

        public boolean id8(int c) {
            if (filter != null) {
                return filter.id8(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String id5() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r') {
                    buf.appendCodePoint(c);
                }
                c = read();
            }
            return buf.toString();
        }

        public String readLine() {
            String s = id5();
            while (s.trim().length() == 0) {
                s = id5();
            }
            return s;
        }

        public String readLine(boolean id21) {
            if (id21) {
                return readLine();
            } else {
                return id5();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id8(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id8(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id8(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, readInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!id8(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, readInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public boolean id7() {
            int value;
            while (id8(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id24 getFilter() {
            return filter;
        }

        public void setFilter(id24 filter) {
            this.filter = filter;
        }

        public interface id24 {
            public boolean id8(int ch);
        }
    }

}