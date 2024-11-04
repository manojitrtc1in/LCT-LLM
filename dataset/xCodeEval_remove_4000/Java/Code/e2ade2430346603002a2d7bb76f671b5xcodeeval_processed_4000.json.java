import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;


public class Main {
    public static void main(String[] args) throws Exception {
        id16 reader = new id16(System.in);
        int num = reader.nextInteger();

        if (num == 0) {
            return;
        }

        int[] cmds = new int[num];
        long[] leftBounds = new long[num];
        long[] rightBounds = new long[num];

        

        for (int i = 0; i < num; i++) {
            cmds[i] = reader.nextInteger();
            leftBounds[i] = reader.nextLong();
            rightBounds[i] = reader.nextLong();
        }

        

        long[] g = new long[num * 4 + 2];
        System.arraycopy(leftBounds, 0, g, 0, num);
        System.arraycopy(rightBounds, 0, g, num, num);
        for (int i = 0, base1 = num * 2, base2 = num * 3; i < num; i++) {

            g[base1 + i] = Math.max(rightBounds[i] - 1, 1);
            g[base2 + i] = rightBounds[i] + 1;
        }
        g[num * 4] = 1;
        g[num * 4 + 1] = Long.MAX_VALUE;
        Arrays.sort(g);
        

        int gLen = 0;
        for (int i = 1, bound = g.length; i < bound; i++) {
            if (g[i] != g[gLen]) {
                g[++gLen] = g[i];
            }
        }
        gLen++;

        

        SectionTree tree = new SectionTree(0, gLen);

        

        for (int i = 0; i < num; i++) {
            int cmd = cmds[i];
            int leftBound = Arrays.binarySearch(g, 0, gLen, leftBounds[i]);
            int rightBound = Arrays.binarySearch(g, 0, gLen, rightBounds[i] + 1) - 1;

            tree.update(leftBound, rightBound, cmd);

            














            System.out.println(g[tree.id7()]);
        }
    }

    
    private static class id16 implements AutoCloseable {
        private PushbackInputStream in;

        @Override
        public void close() throws IOException {
            in.close();
        }

        private static class id17 {
            public static final byte id10 = 1;
            public static final byte SIGN_MARK = 1 << 1;
            public static final byte id2 = 1 << 2;
            public static final byte id15 = 1 << 3;
            public static final byte id11 = 1 << 4;
            public static final byte LETTER_MARK = id15 | id11;
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
                    asciiMarks[i] = id15;
                }
                asciiMarks[0xff] = EOF;
            }
        }

        
        public id16(InputStream input) {
            in = new PushbackInputStream(new BufferedInputStream(input));
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
            while (id17.asciiMarks[c = nextByte()] != id17.id10) {
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
            if (id17.asciiMarks[c] == id17.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = '0' - c;
            }
            c = nextByte();
            while (id17.asciiMarks[c] == id17.id2) {
                value = (value << 3) + (value << 1) + '0' - c;
                c = nextByte();
            }

            in.unread(c);
            return positive ? -value : value;
        }

        
        public boolean id1() throws IOException {
            int c = nextByte();
            if (id17.asciiMarks[c] == id17.EOF) {
                return true;
            }
            in.unread(c);
            return false;
        }

        
        public boolean id25() throws IOException {
            skipBlank();
            int c = nextByte();
            if (id17.asciiMarks[c] == id17.EOF) {
                return true;
            }
            in.unread(c);
            return false;
        }

        
        public String nextWord() throws IOException {
            StringBuilder sb = new StringBuilder(16);
            skipBlank();
            int c;
            while ((id17.asciiMarks[(c = nextByte())] & id17.LETTER_MARK) != 0) {
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
            if (id17.asciiMarks[c] == id17.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = '0' - c;
            }
            c = nextByte();
            while (id17.asciiMarks[c] == id17.id2) {
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
            if (id17.asciiMarks[c] == id17.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = c - '0';
            }
            c = nextByte();
            while (id17.asciiMarks[c] == id17.id2) {
                value = value * 10.0 + c - '0';
                c = nextByte();
            }

            if (c == '.') {
                double littlePart = 0;
                double base = 1;
                c = nextByte();
                while (id17.asciiMarks[c] == id17.id2) {
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
            while (id17.asciiMarks[c] == id17.id2) {
                sb.append((char) c);
                c = nextByte();
            }
            if (c == '.') {
                sb.append('.');
                c = nextByte();
                while (id17.asciiMarks[c] == id17.id2) {
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
            while (id17.asciiMarks[c] == id17.id2) {
                sb.append((char) c);
                c = nextByte();
            }
            in.unread(c);
            return new BigInteger(sb.toString());
        }
    }

    private static 
    class SectionTree {
        
        private id18 root;

        
        public static class ValuePair {
            public static final ValuePair id22 = new ValuePair(Integer.MAX_VALUE, Integer.MIN_VALUE);
            public final int minValue;
            public final int maxValue;

            public ValuePair(int minValue, int maxValue) {
                this.minValue = minValue;
                this.maxValue = maxValue;
            }

            @Override
            public String toString() {
                return String.format("max:%d, min:%d", maxValue, minValue);
            }

            public static ValuePair combine(ValuePair a, ValuePair b) {
                return new ValuePair(Math.min(a.minValue, b.minValue),
                        Math.max(a.maxValue, b.maxValue));
            }
        }

        
        private static class Section {
            
            public static enum SectionRelation {
                INCLUDED, INTERSECT, NONE
            }

            private int leftBound, rightBound;

            public int id9() {
                return leftBound;
            }

            public int id20() {
                return rightBound;
            }

            public Section(int leftBound, int rightBound) {
                if (rightBound < leftBound) {
                    throw new IllegalArgumentException(String.format("A section should obey leftBound<=rightBound, but current state is %d > %d", leftBound, rightBound));
                }
                this.leftBound = leftBound;
                this.rightBound = rightBound;
            }

            
            public SectionRelation relationWith(Section other) {
                if (rightBound < other.leftBound || leftBound > other.rightBound) {
                    return SectionRelation.NONE;
                }
                if (rightBound <= other.rightBound && leftBound >= other.leftBound) {
                    return SectionRelation.INCLUDED;
                }
                return SectionRelation.INTERSECT;
            }

            
            public Section id4() {
                return new Section(leftBound, (leftBound + rightBound) / 2);
            }

            
            public Section id13() {
                return new Section((leftBound + rightBound) / 2 + 1, rightBound);
            }

            @Override
            public String toString() {
                return String.format("[%d, %d]", leftBound, rightBound);
            }

            
            public int size() {
                return rightBound - leftBound + 1;
            }

            
            public boolean id24() {
                return rightBound == leftBound;
            }
        }

        
        private static class id18 {
            public id18 leftChild, rightChild;
            private Section section;
            private int id14, id23;
            private int dirtyMark;

            
            public Section getSection() {
                return section;
            }

            
            public void id6(int dirtyMark) {
                this.dirtyMark += dirtyMark;
            }

            
            public id18(Section section) {
                this.section = section;
            }

            
            public int id3() {
                switch (dirtyMark) {
                    case 0:
                        return id14;
                    case 1:
                        return 1;
                    case 2:
                        return 0;
                    default:
                        return (id23 + 1) % 2;
                }
            }

            
            public int id0() {
                switch (dirtyMark) {
                    case 0:
                        return id23;
                    case 1:
                        return 1;
                    case 2:
                        return 0;
                    default:
                        return (id14 + 1) % 2;
                }
            }

            
            public void id8() {
                id14 = Math.min(leftChild.id3(), rightChild.id3());
                id23 = Math.max(leftChild.id0(), rightChild.id0());
            }

            @Override
            public String toString() {
                StringBuilder sb = new StringBuilder(String.format("{lrBound:%s,minMaxValue:[%d,%d],dirtyMark:%d(",
                        section.toString(), id14, id23, dirtyMark));
                if (leftChild != null) {
                    sb.append(leftChild.toString());
                }
                sb.append(", ");
                if (rightChild != null) {
                    sb.append(rightChild.toString());
                }
                sb.append(")}");
                return sb.toString();
            }
        }

        
        public SectionTree(int[] data) {
            this(data, 0, data.length);
        }

        
        public SectionTree(int[] data, int from, int to) {
            if (from >= to) {
                throw new IllegalArgumentException("You can't build a section tree with empty array");
            }
            this.root = id19(data, new Section(from, to - 1));
        }

        @Override
        public String toString() {
            return root.toString();
        }

        
        public void update(int leftBound, int rightBound, int val) {
            update(root, new Section(leftBound, rightBound), val);
        }

        
        public ValuePair queryValue(int leftBound, int rightBound) {
            return queryValue(root, new Section(leftBound, rightBound));
        }

        public static ValuePair queryValue(id18 node, Section section) {
            switch (node.getSection().relationWith(section)) {
                case INCLUDED:
                    return new ValuePair(node.id3(), node.id0());
                case INTERSECT:
                    ValuePair vp = ValuePair.combine(queryValue(node.leftChild, section),
                            queryValue(node.rightChild, section));
                    int min = vp.minValue;
                    int max = vp.maxValue;
                    switch (node.dirtyMark) {
                        case 0:
                            return vp;
                        case 1:
                            return new ValuePair(1, 1);
                        case 2:
                            return new ValuePair(0, 0);
                        case 3:
                            return new ValuePair((max + 1) % 2, (min + 1) % 2);
                    }
            }
            return ValuePair.id22;
        }

        public static void update(id18 node, Section section, int val) {
            switch (node.getSection().relationWith(section)) {
                case INCLUDED:
                    if (val != 3) {
                        node.dirtyMark = val;
                    } else {
                        node.dirtyMark = 3 - node.dirtyMark;
                    }
                    return;
                case INTERSECT:
                    if (node.dirtyMark != 0) {
                        update(node.leftChild, node.section, node.dirtyMark);
                        update(node.rightChild, node.section, node.dirtyMark);
                        node.dirtyMark = 0;
                    }
                    update(node.leftChild, section, val);
                    update(node.rightChild, section, val);
                    node.id8();
                    return;
                case NONE:
                    return;
            }
        }

        private static id18 id19(int[] data, Section section) {
            id18 current = new id18(section);
            if (section.id24()) {
                current.id14 = current.id23 = data[section.id9()];
                return current;
            }
            current.leftChild = id19(data, section.id4());
            current.rightChild = id19(data, section.id13());
            current.id8();
            return current;
        }

        public SectionTree(int from, int to) {
            if (to <= from) {
                throw new IllegalArgumentException("You can't build a section tree with empty array");
            }
            this.root = id21(new Section(from, to - 1));
        }

        private static id18 id21(Section section) {
            id18 current = new id18(section);
            if (section.id24()) {
                return current;
            }
            current.leftChild = id21(section.id4());
            current.rightChild = id21(section.id13());
            return current;
        }

        public int id7() {
            return id7(root, 0);
        }

        private static int id7(id18 node, int reverse) {
            if (node.getSection().id24()) {
                return node.getSection().leftBound;
            }
            reverse = reverse ^ (node.dirtyMark == 3 ? 1 : 0);
            if (reverse == 0) {
                if (node.dirtyMark == 2) {
                    return node.section.leftBound;
                }
                if (node.leftChild.id3() == 0) {
                    return id7(node.leftChild, reverse);
                }
                return id7(node.rightChild, reverse);
            } else {
                if (node.dirtyMark == 1) {
                    return node.section.leftBound;
                }
                if (node.leftChild.id0() == 1) {
                    return id7(node.leftChild, reverse);
                }
                return id7(node.rightChild, reverse);
            }
        }
    }
}


