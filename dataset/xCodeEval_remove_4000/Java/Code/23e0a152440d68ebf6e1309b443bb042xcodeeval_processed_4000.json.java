import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PushbackInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;



public class id3 {
    private static final long id0 = (long) (-1e14);
    int n;
    Node[] allNodes;
    LinkedList<Node> loop = new LinkedList<>();
    LinkedList<Long> id13 = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        id3 instance = new id3();
        instance.init(new id15(System.in));
        long result = instance.solve();
        System.out.println(result);
    }

    void init(id15 input) throws Exception {
        n = input.nextInteger();
        allNodes = new Node[n];
        for (int i = 0; i < n; i++) {
            allNodes[i] = new Node();
            allNodes[i].id = i + 1;
        }
        for (int i = 0; i < n; i++) {
            int ui = input.nextInteger() - 1;
            int vi = input.nextInteger() - 1;
            int li = input.nextInteger();
            allNodes[ui].id19(allNodes[vi], li);
            allNodes[vi].id19(allNodes[ui], li);
        }
    }

    boolean searchLoop(Node node, Node from)
    {
        if (node.flag == Node.id6) {
            

            

            long distance = node.id23(from);
            from.id23(node);
            id17(node, from, null);
            loop.add(node);
            id13.add(distance);
            node.flag = Node.id9;
            return true;
        }
        node.flag = Node.id6;
        for (Node next : node.nearNodes) {
            if (next == from) {
                continue;
            }
            if(searchLoop(next, node))
            {
                return true;
            }
        }
        return false;
    }

    boolean id17(Node node, Node target, Node from) {
        if (node == target) {
            return true;
        }
        Iterator<Long> distanceIterator = node.distanceTo.iterator();
        for (Node next : node.nearNodes) {
            Long distanceTo = distanceIterator.next();
            if (next == from) {
                continue;
            }
            if (id17(next, target, node)) {
                loop.add(next);
                id13.add(distanceTo);
                next.flag = Node.id9;
                return true;
            }
        }
        return false;
    }

    void id4(Node node, Node from) {
        Iterator<Long> distanceIterator = node.distanceTo.iterator();
        SimpleHeap heap = new SimpleHeap();
        long maxMid = 0;
        for (Node next : node.nearNodes) {
            Long distanceTo = distanceIterator.next();
            if (next.flag == Node.id9) {
                continue;
            }
            if (next == from) {
                continue;
            }
            id4(next, node);
            heap.update(distanceTo + next.end);
            maxMid = Math.max(maxMid, next.mid);
        }

        node.end = heap.max;
        node.mid = Math.max(heap.max + heap.secondaryMax, maxMid);
    }

    void id21() {
        for (Node node : loop) {
            id4(node, null);
        }
    }

    long solve() {
        searchLoop(allNodes[0], null);
        id21();
        long possibleResult = 0;
        for (Node node : loop) {
            possibleResult = possibleResult > node.mid ? possibleResult : node.mid;
        }

        

        int loopSize = loop.size();
        long[] cross = new long[loopSize];
        long[] left = new long[loopSize];
        long[] right = new long[loopSize];
        {
            long[] w = new long[loopSize];
            long[] m = new long[loopSize];
            long[] lw = new long[loopSize];
            long[] lm = new long[loopSize];
            long[] rw = new long[loopSize];
            long[] rm = new long[loopSize];
            long id8 = 0;
            {
                int i = 0;
                Iterator<Long> distanceIterator = id13.iterator();
                for (Node node : loop) {
                    w[i] = node.end + id8;
                    m[i] = node.end - id8;
                    id8 += distanceIterator.next();
                    i++;
                }
            }
            lw[0] = id0;
            lm[0] = id0;
            left[0] = id0;
            for (int i = 1; i < loopSize; i++) {
                lw[i] = Math.max(lw[i - 1], w[i - 1]);
                lm[i] = Math.max(lm[i - 1], m[i - 1]);
                left[i] = Math.max(left[i - 1], lm[i] + w[i]);
            }
            rw[loopSize - 1] = id0;
            rm[loopSize - 1] = id0;
            right[loopSize - 1] = id0;
            for (int i = loopSize - 2; i >= 0; i--) {
                rw[i] = Math.max(rw[i + 1], w[i + 1]);
                rm[i] = Math.max(rm[i + 1], m[i + 1]);
                right[i] = Math.max(right[i + 1], rw[i + 1] + m[i + 1]);
            }

            for (int i = 0, bound = loopSize - 1; i < bound; i++) {
                cross[i] = rm[i] + lw[i + 1] + id8;
            }
        }

        

        long id18 = left[loopSize - 1];
        for (int i = 0, bound = loopSize - 1; i < bound; i++) {
            long id20 = 0;
            id20 = Math.max(left[i], id20);
            id20 = Math.max(right[i], id20);
            id20 = Math.max(cross[i], id20);
            id18 = Math.min(id18, id20);
        }
        return Math.max(id18, possibleResult);
    }

    private static class SimpleHeap {
        long max = 0;
        long secondaryMax = 0;

        void update(long value) {
            if (value > max) {
                secondaryMax = max;
                max = value;
            } else if (value > secondaryMax) {
                secondaryMax = value;
            }
        }
    }

    private static class Node {
        public static final int id6 = 1;
        public static final int id9 = 2;
        List<Node> nearNodes = new LinkedList<>();
        List<Long> distanceTo = new LinkedList<>();
        long end;
        long mid;
        int flag;
        int id;

        @Override
        public String toString() {
            return "" + id;
        }

        void id19(Node node, long distance) {
            nearNodes.add(node);
            distanceTo.add(distance);
        }

        long distanceTo(Node node) {
            Iterator<Node> nodeIterator = nearNodes.iterator();
            Iterator<Long> id7 = distanceTo.iterator();
            while (nodeIterator.next() != node) {
                id7.next();
            }
            return id7.next();
        }

        long id23(Node node) {
            Iterator<Node> nodeIterator = nearNodes.iterator();
            Iterator<Long> id7 = distanceTo.iterator();

            while (nodeIterator.next() != node) {
                id7.next();
            }
            nodeIterator.remove();
            long result =  id7.next();
            id7.remove();
            return result;
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

        
        public void id12(int b, int times) throws IOException {
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
            while (id16.asciiMarks[c = nextByte()] != id16.id10) {
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

        
        public boolean id22() throws IOException {
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

        
        public BigInteger id5() throws IOException {
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
            public static final byte id10 = 1;
            public static final byte SIGN_MARK = 1 << 1;
            public static final byte id2 = 1 << 2;
            public static final byte id14 = 1 << 3;
            public static final byte id11 = 1 << 4;
            public static final byte LETTER_MARK = id14 | id11;
            public static final byte EOF = 1 << 5;
            public static byte[] asciiMarks = new byte[256];

            static {
                for (int i = 0; i <= 32; i++) {
                    asciiMarks[i] = id10;
                }
                asciiMarks['+'] = SIGN_MARK;
                asciiMarks['-'] = SIGN_MARK;
                for (int i = '0'; i <= '9'; i++) {
                    asciiMarks[i] = id2;
                }
                for (int i = 'a'; i <= 'z'; i++) {
                    asciiMarks[i] = id11;
                }
                for (int i = 'A'; i <= 'Z'; i++) {
                    asciiMarks[i] = id14;
                }
                asciiMarks[0xff] = EOF;
            }
        }
    }
}