import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PushbackInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class id16 {
    public static void main(String[] args) throws IOException {
        id13 reader = new id13(System.in);

        int n = reader.nextInteger();
        ResidualNet net = new ResidualNet(2 + n * 4);

        {
            List<Integer>[] id19 = new List[7];
            for (int i = 0; i < 7; i++) {
                id19[i] = new LinkedList<Integer>();
                id19[i].add(0);
            }
            Map<Integer, List<Integer>> id5 = new TreeMap<>();
            int inf = 100000000;
            for (int i = 0; i < n; i++) {
                int input = reader.nextInteger();

                int m7 = i * 4 + 2;
                int equal = m7 + 1;
                int id24 = m7 + 2;
                int id0 = m7 + 3;

                

                int id18 = input % 7;
                for (int src : id19[id18]) {
                    net.buildEdge(src, m7, inf, 0);
                }
                id19[id18].clear();

                List<Integer> registry = id5.get(input);
                if (registry == null) {
                    registry = new LinkedList<>();
                    id5.put(input, registry);
                }
                for (Integer src : registry) {
                    net.buildEdge(src, equal, inf, 0);
                }
                registry.clear();
                

                net.buildEdge(m7, id24, 1, 0);
                net.buildEdge(equal, id24, 1, 0);
                net.buildEdge(id24, id0, 1, -1);

                

                id19[id18].add(m7);
                id19[id18].add(id0);
                registry.add(equal);
                registry = id5.get(input - 1);
                if (registry == null) {
                    registry = new LinkedList<>();
                    id5.put(input - 1, registry);
                }
                registry.add(id0);
                registry = id5.get(input + 1);
                if (registry == null) {
                    registry = new LinkedList<>();
                    id5.put(input + 1, registry);
                }
                registry.add(id0);
            }

            

            for (int i = 0; i < 7; i++) {
                for (int src : id19[i]) {
                    if (src != 0) {
                        net.buildEdge(src, 1, inf, 0);
                    }
                }
            }
            for (List<Integer> list : id5.values()) {
                for (int src : list) {
                    net.buildEdge(src, 1, inf, 0);
                }
            }
        }

        

        

        prepare(net);
        for (int i = 0; i < 4; i++) {
            

            id11(net);
        }

        int totalPrice = net.totalPrice();
        System.out.println(-totalPrice);
    }

    public static void validate(ResidualNet net) {
        for (ResidualNet.id3 node : net.id6()) {
            for (ResidualNet.id25 edge : node.getEdges()) {
                if (edge.valid() && edge.weightedPrice() < 0) {
                    throw new AssertionError();
                }
            }
        }
    }

    public static void prepare(ResidualNet net) {
        ResidualNet.id3[] nodes = net.id6();
        nodes[0].setWeight(0);
        for (ResidualNet.id3 src : nodes) {
            int srcWeight = src.getWeight();
            for (ResidualNet.id25 edge : src.getEdges()) {
                if (!edge.valid()) {
                    continue;
                }
                ResidualNet.id3 target = edge.targetNode();
                int targetWeight = edge.targetNode().getWeight();
                int newWeight = srcWeight + edge.unitPrice();
                if (newWeight < targetWeight) {
                    target.setWeight(newWeight);
                }
            }
        }
    }

    public static void id11(ResidualNet net) {
        

        ResidualNet.id3[] nodes = net.id6();
        KeyHeap.Key[] keyOutput = new KeyHeap.Key[nodes.length];
        Pair<Integer, ResidualNet.id3>[] id23 = new Pair[nodes.length];
        int inf = 100000000;
        Integer infPack = Integer.valueOf(inf);
        id23[0] = new Pair<>(Integer.valueOf(0), nodes[0]);
        ResidualNet.id25[] parentEdges = new ResidualNet.id25[nodes.length];
        for (int i = 1, bound = nodes.length; i < bound; i++) {
            id23[i] = new Pair<>(infPack, nodes[i]);
        }
        KeyHeap heap = new KeyHeap(id23, keyOutput, new Comparator<Object>() {
            @Override
            public int compare(Object o1, Object o2) {
                return ((Pair<Integer, ResidualNet.id3>) o1).key.compareTo(((Pair<Integer, ResidualNet.id3>) o2).key);
            }
        });

        

        while (!heap.isEmpty()) {
            Pair<Integer, ResidualNet.id3> pair = (Pair<Integer, ResidualNet.id3>) heap.pop();
            if (pair.key.intValue() < inf) {
                id23[pair.value.getId()] = pair;
                

                for (ResidualNet.id25 edge : pair.value.getEdges()) {
                    if (!edge.valid()) {
                        continue;
                    }
                    int newDistance = edge.weightedPrice() + pair.key;
                    ResidualNet.id3 targetNode = edge.targetNode();
                    KeyHeap.Key targetKey = keyOutput[targetNode.getId()];
                    if (((Pair<Integer, ResidualNet.id3>) targetKey.getValue()).key > newDistance) {
                        targetKey.update(new Pair<Integer, ResidualNet.id3>(newDistance, edge.targetNode()));
                        parentEdges[targetNode.getId()] = edge;
                    }
                }
            } else {
                break;
            }
        }

        

        ResidualNet.id25 edge = parentEdges[1];
        while (edge != null) {
            edge.appendFlow(1);
            edge = parentEdges[edge.sourceNode().getId()];
        }

        

        for (int i = 0, bound = nodes.length; i < bound; i++) {
            int newWeight = nodes[i].getWeight() + id23[i].key;
            nodes[i].setWeight(Math.min(newWeight, inf));
        }
    }

    public static class Pair<K, V> {
        public final K key;
        public final V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    
    public static class KeyHeap {
        private Comparator<Object> comparator;
        private Key[] keys;
        private int remain;

        public KeyHeap(Object[] data, Key[] keyOutput, Comparator<Object> comparator) {
            remain = data.length;
            this.comparator = comparator;

            if (data == null) {
                throw new IllegalArgumentException();
            }
            if (comparator == null) {
                throw new IllegalArgumentException();
            }
            keys = new Key[data.length];
            for (int i = 0, bound = data.length; i < bound; i++) {
                keys[i] = new Key(data[i], i);
            }
            if (keyOutput != null) {
                System.arraycopy(keys, 0, keyOutput, 0, Math.min(keys.length, keyOutput.length));
            }
            Arrays.sort(keys, new Comparator<Key>() {
                @Override
                public int compare(Key o1, Key o2) {
                    return comparator.compare(o1.getValue(), o2.getValue());
                }
            });
        }

        public KeyHeap(int capacity, Comparator<Object> comparator) {
            if (capacity < 0) {
                throw new IllegalArgumentException();
            }
            if (comparator == null) {
                throw new IllegalArgumentException();
            }
            keys = new Key[capacity];
            this.comparator = comparator;
        }

        public Object peek() {
            if (remain <= 0) {
                throw new IllegalStateException();
            }
            return keys[0].value;
        }

        public int size() {
            return remain;
        }

        public Object pop() {
            if (remain <= 0) {
                throw new IllegalStateException();
            }
            Key result = keys[0];
            remain--;
            inject(keys[remain], 0);
            keys[remain] = null;
            downward(0);
            return result.value;
        }

        public Key push(Object value) {
            if (remain == keys.length) {
                throw new IllegalStateException();
            }
            Key newKey = new Key(value, remain);
            keys[remain] = newKey;
            remain++;
            upward(newKey.index);
            return newKey;
        }


        public void clear() {
            for (int i = 0; i < remain; i++) {
                keys[i].removed = true;
                keys[i] = null;
            }
            remain = 0;
        }

        private void downward(int target) {
            if(target < 0 || target >= remain)
            {
                return;
            }
            Key targetKey = keys[target];
            while (true) {
                int lindex = target << 1;
                int rindex = (target << 1) | 1;
                if (lindex >= remain) {
                    break;
                }
                if (rindex >= remain) {
                    rindex = lindex;
                }
                Key left = keys[lindex];
                Key right = keys[rindex];
                if (comparator.compare(left.value, right.value) < 0) {
                    if (comparator.compare(left.value, targetKey.value) < 0) {
                        inject(left, target);
                        target = lindex;
                    } else {
                        break;
                    }
                } else {
                    if (comparator.compare(right.value, targetKey.value) < 0) {
                        inject(right, target);
                        target = rindex;
                    } else {
                        break;
                    }
                }
            }
            inject(targetKey, target);
        }

        private void inject(Key key, int i) {
            keys[i] = key;
            key.index = i;
        }

        private void upward(int target) {
            if(target < 0 || target >= remain)
            {
                return;
            }

            Key targetKey = keys[target];
            while (target > 0) {
                int pindex = target >> 1;
                Key parent = keys[pindex];
                if (comparator.compare(targetKey.value, parent.value) < 0) {
                    inject(parent, target);
                    target = pindex;
                } else {
                    break;
                }
            }
            inject(targetKey, target);
        }

        public boolean isEmpty() {
            return remain == 0;
        }

        private void remove(int index) {
            keys[index].removed = true;
            keys[index] = keys[--remain];
            keys[remain] = null;
            downward(index);
        }

        public class Key {
            boolean removed = false;
            private int index;
            private Object value;

            public Key(Object value, int index) {
                this.value = value;
                this.index = index;
            }

            public Object getValue() {
                return value;
            }

            public void remove() {
                if (removed) {
                    throw new IllegalStateException();
                }
                KeyHeap.this.remove(index);
            }

            public void update(Object value) {
                if (removed) {
                    throw new IllegalStateException();
                }
                int cmp = comparator.compare(value, this.value);
                this.value = value;
                if (cmp < 0) {
                    upward(index);
                } else if (cmp > 0) {
                    downward(index);
                }
            }
        }
    }

    
    private static class id13 implements AutoCloseable {
        private PushbackInputStream in;

        
        public id13(InputStream input) {
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

        
        public void id10(int b, int times) throws IOException {
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
            while (id14.asciiMarks[c = nextByte()] != id14.id8) {
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
            if (id14.asciiMarks[c] == id14.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = '0' - c;
            }
            c = nextByte();
            while (id14.asciiMarks[c] == id14.id2) {
                value = (value << 3) + (value << 1) + '0' - c;
                c = nextByte();
            }

            in.unread(c);
            return positive ? -value : value;
        }

        
        public boolean id1() throws IOException {
            int c = nextByte();
            if (id14.asciiMarks[c] == id14.EOF) {
                return true;
            }
            in.unread(c);
            return false;
        }

        
        public boolean id20() throws IOException {
            skipBlank();
            int c = nextByte();
            if (id14.asciiMarks[c] == id14.EOF) {
                return true;
            }
            in.unread(c);
            return false;
        }

        
        public String nextWord() throws IOException {
            StringBuilder sb = new StringBuilder(16);
            skipBlank();
            int c;
            while ((id14.asciiMarks[(c = nextByte())] & id14.LETTER_MARK) != 0) {
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
            if (id14.asciiMarks[c] == id14.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = '0' - c;
            }
            c = nextByte();
            while (id14.asciiMarks[c] == id14.id2) {
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
            if (id14.asciiMarks[c] == id14.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = c - '0';
            }
            c = nextByte();
            while (id14.asciiMarks[c] == id14.id2) {
                value = value * 10.0 + c - '0';
                c = nextByte();
            }

            if (c == '.') {
                double littlePart = 0;
                double base = 1;
                c = nextByte();
                while (id14.asciiMarks[c] == id14.id2) {
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
            while (id14.asciiMarks[c] == id14.id2) {
                sb.append((char) c);
                c = nextByte();
            }
            if (c == '.') {
                sb.append('.');
                c = nextByte();
                while (id14.asciiMarks[c] == id14.id2) {
                    sb.append((char) c);
                    c = nextByte();
                }
            }
            in.unread(c);
            return new BigDecimal(sb.toString());
        }

        
        public BigInteger id4() throws IOException {
            skipBlank();
            StringBuilder sb = new StringBuilder();
            sb.append((char) nextByte());
            int c = nextByte();
            while (id14.asciiMarks[c] == id14.id2) {
                sb.append((char) c);
                c = nextByte();
            }
            in.unread(c);
            return new BigInteger(sb.toString());
        }

        private static class id14 {
            public static final byte id8 = 1;
            public static final byte SIGN_MARK = 1 << 1;
            public static final byte id2 = 1 << 2;
            public static final byte id12 = 1 << 3;
            public static final byte id9 = 1 << 4;
            public static final byte LETTER_MARK = id12 | id9;
            public static final byte EOF = 1 << 5;
            public static byte[] asciiMarks = new byte[256];

            static {
                for (int i = 0; i <= 32; i++) {
                    asciiMarks[i] = id8;
                }
                asciiMarks['+'] = SIGN_MARK;
                asciiMarks['-'] = SIGN_MARK;
                for (int i = '0'; i <= '9'; i++) {
                    asciiMarks[i] = id2;
                }
                for (int i = 'a'; i <= 'z'; i++) {
                    asciiMarks[i] = id9;
                }
                for (int i = 'A'; i <= 'Z'; i++) {
                    asciiMarks[i] = id12;
                }
                asciiMarks[0xff] = EOF;
            }
        }
    }

    private static class ResidualNet {

        private id22[] nodes;

        
        public ResidualNet(int nodeNum) {
            nodes = new id22[nodeNum];
            for (int i = 0; i < nodeNum; i++) {
                nodes[i] = new id22(i);
            }
        }

        public id3[] id6() {
            return nodes;
        }

        public void buildEdge(int from, int to, int capcity, int unitPrice) {
            if (from == 1 || to == 0) {
                throw new IllegalArgumentException("Illegal source node for " + from + " with target node for " + to + " to build a edge");
            }
            if (from == to) {
                throw new IllegalArgumentException("You can't build an edge between same node");
            }
            id25 edge = new id17(nodes[from], nodes[to], unitPrice, capcity);
            nodes[from].addEdge(edge);
            nodes[to].addEdge(edge.reverseEdge());
        }

        public int totalPrice() {
            int totalPrice = 0;
            for (id22 node : nodes) {
                for (id25 edge : node.getEdges()) {
                    totalPrice += edge.totalPrice();
                }
            }
            return totalPrice;
        }

        public static interface id25 {
            public id3 sourceNode();

            public id3 targetNode();

            public int unitPrice();

            public int totalPrice();

            public int weightedPrice();

            public id25 reverseEdge();

            public int capacity();

            public int flow();

            public void appendFlow(int inc);

            public int remain();

            public boolean valid();
        }

        public static interface id3 {
            public int getId();

            public Iterable<id25> getEdges();

            public int getWeight();

            public void setWeight(int weight);
        }

        public static abstract class id7 implements id25 {
            public int weightedPrice() {
                return unitPrice() + sourceNode().getWeight() - targetNode().getWeight();
            }

            @Override
            public boolean valid() {
                return remain() > 0;
            }

            public int flow() {
                return capacity() - remain();
            }

            @Override
            public int totalPrice() {
                return unitPrice() * flow();
            }

            @Override
            public String toString() {
                return String.format("to %d, price %d, flow %d, remain %d", targetNode().getId(), weightedPrice(), flow(), remain());
            }
        }

        public static class id17 extends id7 {
            private id3 source;
            private id3 target;
            private int price;
            private int capacity;
            private int remain;
            private id15 id21 = new id15(this);

            public id17(id3 source, id3 target, int price, int capacity) {
                this.source = source;
                this.target = target;
                this.price = price;
                this.capacity = capacity;
                this.remain = capacity;
            }

            @Override
            public void appendFlow(int inc) {
                this.remain -= inc;
            }

            @Override
            public id3 sourceNode() {
                return source;
            }

            @Override
            public id3 targetNode() {
                return target;
            }

            @Override
            public int unitPrice() {
                return price;
            }

            @Override
            public id25 reverseEdge() {
                return id21;
            }

            @Override
            public int capacity() {
                return capacity;
            }

            @Override
            public int remain() {
                return remain;
            }
        }

        public static class id15 extends id7 {
            private id17 edge;

            public id15(id17 edge) {
                this.edge = edge;
            }

            @Override
            public id3 sourceNode() {
                return edge.targetNode();
            }

            @Override
            public void appendFlow(int inc) {
                edge.appendFlow(-inc);
            }

            @Override
            public id3 targetNode() {
                return edge.sourceNode();
            }

            @Override
            public int unitPrice() {
                return -edge.unitPrice();
            }

            @Override
            public id25 reverseEdge() {
                return edge;
            }

            @Override
            public int capacity() {
                return edge.capacity();
            }

            @Override
            public int remain() {
                return edge.flow();
            }

            @Override
            public int flow() {
                return 0;
            }
        }

        public static class id22 implements id3 {
            private LinkedList<id25> edges;
            private int id;
            private int weight;

            public id22(int id) {
                this.id = id;
                edges = new LinkedList<id25>();
            }

            public void addEdge(id25 edge) {
                edges.add(edge);
            }

            @Override
            public Iterable<id25> getEdges() {
                return edges;
            }

            @Override
            public int getId() {
                return id;
            }

            @Override
            public int getWeight() {
                return weight;
            }

            @Override
            public void setWeight(int weight) {
                this.weight = weight;
            }

            @Override
            public String toString() {
                return Integer.toString(id);
            }
        }
    }
}
