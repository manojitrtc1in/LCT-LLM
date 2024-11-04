
import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PushbackInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.TreeMap;


public class Main {
    public static void main(String[] args) throws IOException {
        id15 reader = new id15(System.in);

        

        int T = reader.nextInteger();
        int n = reader.nextInteger();

        id0[] id12 = new id0[n];
        id12[0] = new id0(0);
        id12[0].startTime = 0;
        int id7 = reader.nextInteger();
        int L = 0;
        for (int i = 1; i < n; i++) {
            int wi = reader.nextInteger();
            L = (L + wi) % T;
            id12[i] = new id0(i);
            id12[i].startTime = L;
        }
        L = (L + id7) % T;

        

        int c = DiscreteMath.gcd(T, L);
        TreeMap<Integer, List<id0>> map = new TreeMap<Integer, List<id0>>();

        for (int i = 0; i < n; i++) {
            Integer cycleId = id12[i].startTime % c;
            List<id0> list = map.get(cycleId);
            if (list == null) {
                list = new ArrayList<>();
                map.put(cycleId, list);
            }
            list.add(id12[i]);
        }

        int[] coe = DiscreteMath.id18(L, T, c);
        int q = coe[0];
        int w = coe[1];
        coe = DiscreteMath.id3(L, T);
        coe = DiscreteMath.id4(coe[0], coe[1], q, w);
        int x = (int)coe[0];
        int y = (int)coe[1];

        for (List<id0> list : map.values()) {
            id0 base = list.get(0);
            base.loopCount = 0;
            for (int i = 1, bound = list.size(); i < bound; i++) {
                id0 node = list.get(i);
                int offset = node.startTime - base.startTime;
                if (offset < 0) {
                    offset += T;
                }
                int loopCount = offset / c;
                int[] minCoe = DiscreteMath.id4((long)x * loopCount, (long)y * loopCount, q, w);
                node.loopCount = minCoe[0];
            }

            Collections.sort(list);
            id0 lastNode = list.get(0);
            for(int i = 1, bound = list.size(); i < bound; i++)
            {
                id0 curNode = list.get(i);
                lastNode.id5 = curNode.loopCount - lastNode.loopCount;
                lastNode = curNode;
            }
            lastNode.id5 = q - lastNode.loopCount;
        }

        for(id0 node : id12)
        {
            System.out.print(node.id5);
            System.out.print(' ');
        }
    }

    private static class id0 implements Comparable<id0> {
        public int id;
        public int id5;
        public int loopCount;
        public int startTime;

        public id0(int id) {
            this.id = id;
        }

        @Override
        public int compareTo(id0 o) {
            int res = this.loopCount - o.loopCount;
            if (res == 0) {
                return o.id - this.id;
            }
            return res;
        }
    }

    
    private static final class DiscreteMath {
        private DiscreteMath() {
        }

        ;

        
        public static int gcd(int a, int b) {
            if (a < 0 || b < 0 || (a + b <= 0)) {
                throw new IllegalArgumentException();
            }
            if (a >= b) {
                return id13(a, b);
            }
            return id13(b, a);
        }

        private static int id13(int a, int b) {
            if (b == 0) {
                return a;
            }
            return id13(b, a % b);
        }

        
        public static int[] id3(int a, int b) {
            if (a < 0 || b < 0 || (a + b <= 0)) {
                throw new IllegalArgumentException();
            }
            if (a >= b) {
                return id8(a, b);
            }
            int[] r = id8(b, a);
            int rx = r[0];
            r[0] = r[1];
            r[1] = rx;
            return r;
        }


        private static int[] id8(int a, int b) {
            if (b == 0) {
                return new int[]{1, 0};
            }
            int[] r = id8(b, a % b);
            int rx = r[0];
            r[0] = r[1];
            r[1] = rx - r[1] * (a / b);
            return r;
        }

        
        public static int[] id18(int a, int b) {
            return id18(a, b, gcd(a, b));
        }

        
        public static int[] id18(int a, int b, int c) {
            return new int[]{b / c, a / c};
        }

        
        public static int[] id4(long x, long y, int i, int j) {
            if (x < 0) {
                return new int[]{(int)(x % i + i), (int)(y - (x / i + 1) * j)};
            }
            return new int[]{(int)(x % i), (int)(y - x / i * j)};
        }
    }


    
    private static class id15 implements AutoCloseable {
        private PushbackInputStream in;

        
        public id15(InputStream input) {
            in = new PushbackInputStream(new BufferedInputStream(input));
        }

        @Override
        public void close() throws IOException {
            in.close();
        }

        private int nextByte() throws IOException {
            return in.read() & 0xff;
        }

        
        public void skipByte(int b) throws IOException {
            int c;
            if ((c = nextByte()) != b) {
                in.unread(c);
            }
        }

        
        public void skipByte(int b, int times) throws IOException {
            int c;
            while ((c = nextByte()) == b && times > 0) {
                times--;
            }
            if (c != b) {
                in.unread(c);
            }
        }

        
        public void id11(int b, int times) throws IOException {
            int c;
            skipBlank();
            while ((c = nextByte()) == b && times > 0) {
                times--;
                skipBlank();
            }
            if (c != b) {
                in.unread(c);
            }
        }

        
        public String nextBlock() throws IOException {
            skipBlank();
            StringBuilder sb = new StringBuilder();
            int c = nextByte();
            while (id16.asciiMarks[c = nextByte()] != id16.id9) {
                sb.append((char) c);
            }
            in.unread(c);
            return sb.toString();
        }

        
        private void skipBlank() throws IOException {
            int c;
            while ((c = nextByte()) <= 32) ;
            in.unread(c);
        }

        
        public int nextInteger() throws IOException {
            skipBlank();
            int value = 0;
            boolean positive = true;
            int c = nextByte();
            if (id16.asciiMarks[c] == id16.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = '0' - c;
            }
            c = nextByte();
            while (id16.asciiMarks[c] == id16.id2) {
                value = (value << 3) + (value << 1) + '0' - c;
                c = nextByte();
            }

            in.unread(c);
            return positive ? -value : value;
        }

        
        public boolean id1() throws IOException {
            int c = nextByte();
            if (id16.asciiMarks[c] == id16.EOF) {
                return true;
            }
            in.unread(c);
            return false;
        }

        
        public boolean id17() throws IOException {
            skipBlank();
            int c = nextByte();
            if (id16.asciiMarks[c] == id16.EOF) {
                return true;
            }
            in.unread(c);
            return false;
        }

        
        public String nextWord() throws IOException {
            StringBuilder sb = new StringBuilder(16);
            skipBlank();
            int c;
            while ((id16.asciiMarks[(c = nextByte())] & id16.LETTER_MARK) != 0) {
                sb.append((char) c);
            }
            in.unread(c);
            return sb.toString();
        }

        
        public long nextLong() throws IOException {
            skipBlank();
            long value = 0;
            boolean positive = true;
            int c = nextByte();
            if (id16.asciiMarks[c] == id16.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = '0' - c;
            }
            c = nextByte();
            while (id16.asciiMarks[c] == id16.id2) {
                value = (value << 3) + (value << 1) + '0' - c;
                c = nextByte();
            }
            in.unread(c);
            return positive ? -value : value;
        }

        
        public float nextFloat() throws IOException {
            return (float) nextDouble();
        }

        
        public double nextDouble() throws IOException {
            skipBlank();
            double value = 0;
            boolean positive = true;
            int c = nextByte();
            if (id16.asciiMarks[c] == id16.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = c - '0';
            }
            c = nextByte();
            while (id16.asciiMarks[c] == id16.id2) {
                value = value * 10.0 + c - '0';
                c = nextByte();
            }

            if (c == '.') {
                double littlePart = 0;
                double base = 1;
                c = nextByte();
                while (id16.asciiMarks[c] == id16.id2) {
                    littlePart = littlePart * 10.0 + c - '0';
                    base *= 10.0;
                    c = nextByte();
                }
                value += littlePart / base;
            }
            in.unread(c);
            return positive ? value : -value;
        }

        
        public BigDecimal nextDecimal() throws IOException {
            skipBlank();
            StringBuilder sb = new StringBuilder();
            sb.append((char) nextByte());
            int c = nextByte();
            while (id16.asciiMarks[c] == id16.id2) {
                sb.append((char) c);
                c = nextByte();
            }
            if (c == '.') {
                sb.append('.');
                c = nextByte();
                while (id16.asciiMarks[c] == id16.id2) {
                    sb.append((char) c);
                    c = nextByte();
                }
            }
            in.unread(c);
            return new BigDecimal(sb.toString());
        }

        
        public BigInteger id6() throws IOException {
            skipBlank();
            StringBuilder sb = new StringBuilder();
            sb.append((char) nextByte());
            int c = nextByte();
            while (id16.asciiMarks[c] == id16.id2) {
                sb.append((char) c);
                c = nextByte();
            }
            in.unread(c);
            return new BigInteger(sb.toString());
        }

        private static class id16 {
            public static final byte id9 = 1;
            public static final byte SIGN_MARK = 1 << 1;
            public static final byte id2 = 1 << 2;
            public static final byte id14 = 1 << 3;
            public static final byte id10 = 1 << 4;
            public static final byte LETTER_MARK = id14 | id10;
            public static final byte EOF = 1 << 5;
            public static byte[] asciiMarks = new byte[256];

            static {
                for (int i = 0; i <= 32; i++) {
                    asciiMarks[i] = id9;
                }
                asciiMarks['+'] = SIGN_MARK;
                asciiMarks['-'] = SIGN_MARK;
                for (int i = '0'; i <= '9'; i++) {
                    asciiMarks[i] = id2;
                }
                for (int i = 'a'; i <= 'z'; i++) {
                    asciiMarks[i] = id10;
                }
                for (int i = 'A'; i <= 'Z'; i++) {
                    asciiMarks[i] = id14;
                }
                asciiMarks[0xff] = EOF;
            }
        }
    }
}
