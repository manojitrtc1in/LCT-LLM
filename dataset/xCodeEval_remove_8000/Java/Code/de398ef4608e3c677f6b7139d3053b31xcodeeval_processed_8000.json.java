import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;
import java.util.Queue;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class D implements Runnable{

    

    

    

    

    


    private final static Random rnd = new Random();
    private final static String fileName = "";

    private final static long MODULO = 1000 * 1000 * 1000 + 7;

    private void solve() {
    	int days = readInt();
    	int id58 = readInt();
    	int id60 = readInt();
    	int id0 = readInt();
    	
    	int[][] exchangePrices = id14(2, days);
    	
    	class Gadget implements Comparable<Gadget> {
    		
    		int index;
    		int price;
			public Gadget(int index, int cost) {
				super();
				this.index = index;
				this.price = cost;
			}
			
			@Override
			public int compareTo(Gadget other) {
				if (this.price != other.price) {
					return this.price - other.price;
				}
				
				return this.index - other.index;
			}
    	}
    	
    	List<Gadget>[] id31 = new List[2];
    	for (int type = 0; type < 2; ++type) id31[type] = new ArrayList<Gadget>();
    	
    	for (int i = 0; i < id58; ++i) {
    		int type = readInt() - 1;
    		int price = readInt();
    		
    		id31[type].add(new Gadget(i, price));
    	}
    	
    	Gadget[][] gadgets = new Gadget[2][];
    	for (int type = 0; type < 2; ++type) gadgets[type] = id31[type].toArray(new Gadget[0]);
    	
    	for (Gadget[] id57 : gadgets) {
    		Arrays.sort(id57);
    	}
    	
    	long[][] id68 = new long[2][];
    	for (int type = 0; type < 2; ++type) {
    		int size = gadgets[type].length;
    		id68[type] = new long[size + 1];
    		
    		for (int index = 0; index < size; ++index) {
    			id68[type][index + 1] = id68[type][index] + gadgets[type][index].price;
    		}
    	}
    	
    	int answerDay = days;
    	
    	int[] id8 = new int[2];
    	Arrays.fill(id8, -1);
    	
    	int[] answerLimits = new int[2];
    	Arrays.fill(answerLimits, -1);
    	
    	int[][] id16 = new int[2][days];
    	for (int day = 0; day < days; ++day) {
    		for (int type = 0; type < 2; ++type) {
    			int id42 = (day > 0 ? id16[type][day - 1] : day);
    			if (id42 == -1 || exchangePrices[type][id42] > exchangePrices[type][day]) id42 = day;
    			id16[type][day] = id42;
    		}
    	}
    	
    	int[] id80 = new int[2];
    	
    	for (int dayLeft = 0, dayRight = days - 1; dayLeft <= dayRight; ) {
    		int day = (dayLeft + dayRight) >> 1;
    	
    		int limitType = -1;
    		int limitIndex = -1;
    		
    		for (int type = 0; type < 2; ++type) id80[type] = id16[type][day];
    		
    		for (int type = 0; type < 2; ++type) {
    			int otherType = 1 - type;
    			
    			Gadget[] id81 = gadgets[type], id38 = gadgets[otherType];
    			
    			long id19 = exchangePrices[type][id80[type]];
    			long id10 = exchangePrices[otherType][id80[otherType]];
    			
    			for (int left = 0, right = id81.length - 1; left <= right; ) {
    				int mid = (left + right) >> 1;
    			
    				int curIndex = id81[mid].index;
    				long curPrice = id81[mid].price * id19;
    				
    				int otherLast = -1;
    				for (int otherLeft = 0, otherRight = id38.length - 1; otherLeft <= otherRight; ) {
    					int otherMid = (otherLeft + otherRight) >> 1;
    				
    					int otherIndex = id38[otherMid].index;
    					long otherPrice = id38[otherMid].price * id10;
    					
    					if (curPrice > otherPrice || curPrice == otherPrice && curIndex > otherIndex) {
    						otherLast = otherMid;
    						otherLeft = otherMid + 1;
    					} else {
    						otherRight = otherMid - 1;
    					}
    				}
    				
    				int curCount = mid + 1;
    				int otherCount = otherLast + 1;
    				
    				int cmp = (curCount + otherCount) - id60; 
    				if (cmp == 0) {
    					limitType = type;
    					limitIndex = mid;
    					break;
    				} else if (cmp < 0) {
    					left = mid + 1;
    				} else {
    					right = mid - 1;
    				}
    			}
    		}
    		
    		if (limitIndex == -1) continue;
    		
    		int id59 = 1 - limitType;
    		int limitCount = limitIndex + 1, id43 = id60 - limitCount;
    		long totalCost = id68[limitType][limitCount] * exchangePrices[limitType][id80[limitType]];
		    totalCost += id68[id59][id43] * exchangePrices[id59][id80[id59]];
		    
    		if (totalCost <= id0) {
    			answerDay = day;
    			
    			id8[0] = id80[0];
    			id8[1] = id80[1];
    			
    			answerLimits[limitType] = limitCount;
    			answerLimits[id59] = id43;
    			
    			dayRight = day - 1;
    		} else {
    			dayLeft = day + 1;
    		}
    	}
    	
    	if (answerDay == days) {
    		out.println(-1);
    	} else {
    		out.println(answerDay + 1);
    		
    		for (int type = 0; type < 2; ++type) {
    			for (int index = 0; index < answerLimits[type]; ++index) {
    				out.println((gadgets[type][index].index + 1) + " " + (id8[type] + 1));
    			}
    		}
    	}
    }

    


    private static long add(long a, long b) { return (a + b) % MODULO; }
    private static long subtract(long a, long b) { return add(a, MODULO - b) % MODULO; }
    private static long mult(long a, long b) { return (a * b) % MODULO; }

    


    private final static boolean id44 = false;
    private final static boolean id4 = true;
    private final boolean id34 = !new File("input.txt").exists();



    private final static int id71 = 128;

    private final static boolean id18 = false;

    


    public void run(){
        try{
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (id34) {
                solve();
            } else {
                do {
                    try {
                        timeInit();
                        solve();
                        time();

                        out.println();
                    } catch (NumberFormatException e) {
                        break;
                    } catch (NullPointerException e) {
                        if (id44) break;
                        else throw e;
                    }
                } while (id4);
            }

            out.close();
            time();
        }catch (Exception e){
            e.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    


    private BufferedReader in;
    private OutputWriter out;
    private StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args){
        new Thread(null, new D(), "", id71 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id34){
            if (fileName.isEmpty()) {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new OutputWriter(System.out);
            } else {
                in = new BufferedReader(new FileReader(fileName + ".in"));
                out = new OutputWriter(fileName + ".out");
            }
        }else{
            in = new BufferedReader(new FileReader("input.txt"));
            out = new OutputWriter("output.txt");
        }
    }

    


    private long timeBegin;

    private void timeInit() {
        this.timeBegin = System.currentTimeMillis();
    }

    private void time(){
        long timeEnd = System.currentTimeMillis();
        System.err.println("Time = " + (timeEnd - timeBegin));
    }

    private void debug(Object... objects){
        if (id34){
            for (Object o: objects){
                System.err.println(o.toString());
            }
        }
    }

    


    private String delim = " ";

    private String readLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private String readString() {
        try {
            while(!tok.hasMoreTokens()){
                tok = new StringTokenizer(readLine(), delim);
            }

            return tok.nextToken(delim);
        } catch (NullPointerException e) {
            return null;
        }
    }

    


    private final char id66 = '\0';

    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1){
                return id66;
            }

            return (char) intValue;
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private char[] id6() {
        return readLine().toCharArray();
    }

    private char[][] id76(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id6();
        }

        return field;
    }

    


    private long id15() {
        int sign = 1;
        long result = 0;
        boolean started = false;
        while (true) {
            try {
                int j = in.read();
                if (-1 == j) {
                    if (started) return sign * result;
                    throw new NumberFormatException();
                }

                if (j == '-') {
                    if (started) throw new NumberFormatException();
                    sign = -sign;
                }

                if ('0' <= j && j <= '9') {
                    result = result * 10 + j - '0';
                    started = true;
                } else if (started) {
                    return sign * result;
                }
            } catch (IOException e) {
                throw new RuntimeIOException(e);
            }
        }
    }

    private int readInt() {

        if (!id18) {
            return Integer.parseInt(readString());
        } else {
            return (int) id15();
        }
    }

    private int[] id2(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    private int[] id9(int size) {
        Integer[] array = new Integer[size];

        for (int index = 0; index < size; ++index) {
            array[index] = readInt();
        }
        Arrays.sort(array);

        int[] sortedArray = new int[size];
        for (int index = 0; index < size; ++index) {
            sortedArray[index] = array[index];
        }

        return sortedArray;
    }

    private int[] id49(int size) {
        int[] array = id2(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    private int[][] id14(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id2(columnsCount);
        }

        return matrix;
    }

    private int[][] id61(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id49(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id18) {
            return Long.parseLong(readString());
        } else {
            return id15();
        }
    }

    private long[] id12(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index){
            array[index] = readLong();
        }

        return array;
    }

    


    private double readDouble() {
        return Double.parseDouble(readString());
    }

    private double[] id45(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger id17() {
        return new BigInteger(readString());
    }

    private BigDecimal id55() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    private Point[] id63(int size) {
        Point[] array = new Point[size];

        for (int index = 0; index < size; ++index){
            array[index] = readPoint();
        }

        return array;
    }

    


    @Deprecated
    private List<Integer>[] readGraph(int vertexNumber, int edgeNumber) {
        @SuppressWarnings("unchecked")
        List<Integer>[] graph = new List[vertexNumber];

        for (int index = 0; index < vertexNumber; ++index){
            graph[index] = new ArrayList<Integer>();
        }

        while (edgeNumber-- > 0){
            int from = readInt() - 1;
            int to = readInt() - 1;

            graph[from].add(to);
            graph[to].add(from);
        }

        return graph;
    }

    private static class GraphBuilder {

        final int size;
        final List<Integer>[] edges;

        static GraphBuilder createInstance(int size) {
            List<Integer>[] edges = new List[size];
            for (int v = 0; v < size; ++v) {
                edges[v] = new ArrayList<Integer>();
            }

            return new GraphBuilder(edges);
        }

        private GraphBuilder(List<Integer>[] edges) {
            this.size = edges.length;
            this.edges = edges;
        }

        public void addEdge(int from, int to) {
            id56(from, to);
            id56(to, from);
        }

        public void id56(int from, int to) {
            edges[from].add(to);
        }

        public int[][] build() {
            int[][] graph = new int[size][];
            for (int v = 0; v < size; ++v) {
                List<Integer> vEdges = edges[v];
                graph[v] = castInt(vEdges);
            }

            return graph;
        }
    }

    private final static int id39 = 0, id69 = 1;

    private int[][] id11(int vertexNumber, int edgesNumber) {
        return id11(vertexNumber, edgesNumber, id69, false);
    }

    private int[][] id11(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.id56(from, to);
            else graphBuilder.addEdge(from, to);
        }

        return graphBuilder.build();
    }

    private static class Edge {
        int to;
        int w;

        Edge(int to, int w) {
            this.to = to;
            this.w = w;
        }
    }

    private Edge[][] id20(int vertexNumber, int edgesNumber) {
        return id20(vertexNumber, edgesNumber, id69, false);
    }

    private Edge[][] id20(int vertexNumber, int edgesNumber,
                                       int indexation, boolean directed) {
        @SuppressWarnings("unchecked")
        List<Edge>[] graph = new List[vertexNumber];
        for (int v = 0; v < vertexNumber; ++v) {
            graph[v] = new ArrayList<Edge>();
        }

        while (edgesNumber --> 0) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;
            int w = readInt();

            graph[from].add(new Edge(to, w));
            if (!directed) graph[to].add(new Edge(from, w));
        }

        Edge[][] graphArrays = new Edge[vertexNumber][];
        for (int v = 0; v < vertexNumber; ++v) {
            graphArrays[v] = graph[v].toArray(new Edge[0]);
        }

        return graphArrays;
    }

    


    private static class id40 {

        static Comparator<id40> increaseComparator = new Comparator<id40>() {

            @Override
            public int compare(id40 id52, id40 id70) {
                int value1 = id52.value;
                int value2 = id70.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id52.index;
                int index2 = id70.index;

                return index1 - index2;
            }
        };

        static Comparator<id40> id29 = new Comparator<id40>() {

            @Override
            public int compare(id40 id52, id40 id70) {
                int value1 = id52.value;
                int value2 = id70.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id52.index;
                int index2 = id70.index;

                return index1 - index2;
            }
        };

        static id40[] from(int[] array) {
            id40[] iip = new id40[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id40(array[i], i);
            }

            return iip;
        }

        int value, index;

        id40(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int id46() {
            return index + 1;
        }
    }

    private id40[] id32(int size) {
        id40[] array = new id40[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id40(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id84 = 12;

        private int precision;
        private String format, id83;

        {
            precision = id84;

            format = createFormat(precision);
            id83 = format + " ";
        }

        OutputWriter(OutputStream out) {
            super(out);
        }

        OutputWriter(String fileName) throws FileNotFoundException {
            super(fileName);
        }

        int getPrecision() {
            return precision;
        }

        void setPrecision(int precision) {
            precision = max(0, precision);
            this.precision = precision;

            format = createFormat(precision);
            id83 = format + " ";
        }

        String createFormat(int precision){
            return "%." + precision + "f";
        }

        @Override
        public void print(double d){
            printf(format, d);
        }
        
        @Override
        public void println(double d){
            print(d);
            println();
        }

        void id78(double d){
            printf(id83, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id78(d[i]);
            }

            print(d[d.length - 1]);
        }

        void printlnAll(double... d){
            printAll(d);
            println();
        }
        
        void printAll(int... array) {
        	for (int value : array) {
        		print(value + " ");
        	}
        }
        
        void printlnAll(int... array) {
        	printAll(array);
        	println();
        }
        
        void printAll(long... array) {
        	for (long value : array) {
        		print(value + " ");
        	}
        }
        
        void printlnAll(long... array) {
        	printAll(array);
        	println();
        }
    }

    


    private static class RuntimeIOException extends RuntimeException {

        
        private static final long id62 = -6463830523020118289L;

        RuntimeIOException(Throwable cause) {
            super(cause);
        }
    }

    

    

    


    private static final int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private static final int[][] steps8 = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
    };

    private static boolean checkCell(int row, int rowsCount, int column, int columnsCount) {
        return checkIndex(row, rowsCount) && checkIndex(column, columnsCount);
    }

    private static boolean checkIndex(int index, int lim){
        return (0 <= index && index < lim);
    }

    


    private static int getBit(long mask, int bit) { return (int)((mask >> bit) & 1); }
    private static boolean checkBit(long mask, int bit){
        return getBit(mask, bit) != 0;
    }

    


    private static long getSum(int[] array) {
        long sum = 0;
        for (int value: array) {
            sum += value;
        }

        return sum;
    }

    private static Point id72(int[] array) {
        int min = array[0];
        int max = array[0];

        for (int index = 0, size = array.length; index < size; ++index, ++index) {
            int value = array[index];

            if (index == size - 1) {
                min = min(min, value);
                max = max(max, value);
            } else {
                int otherValue = array[index + 1];

                if (value <= otherValue) {
                    min = min(min, value);
                    max = max(max, otherValue);
                } else {
                    min = min(min, otherValue);
                    max = max(max, value);
                }
            }
        }

        return new Point(min, max);
    }

    


    private static int[] id51(int n) {
        boolean[] used = new boolean[n];
        used[0] = used[1] = true;

        int size = 0;
        for (int i = 2; i < n; ++i) {
            if (!used[i]) {
                ++size;
                for (int j = 2 * i; j < n; j += i) {
                    used[j] = true;
                }
            }
        }

        int[] primes = new int[size];
        for (int i = 0, cur = 0; i < n; ++i) {
            if (!used[i]) {
                primes[cur++] = i;
            }
        }

        return primes;
    }

    


    int[] id23(int value) {
        List<Integer> id1 = new ArrayList<Integer>();
        for (int divisor = 1; divisor * divisor <= value; ++divisor) {
            if (value % divisor == 0) {
                id1.add(divisor);
                if (divisor * divisor != value) {
                    id1.add(value / divisor);
                }
            }
        }

        return castInt(id1);
    }

    


    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private static long gcd(long a, long b) {
        return (a == 0 ? b : gcd(b % a, a));
    }




    private interface MultiSet<ValueType> {

        int size();

        void inc(ValueType value);
        boolean dec(ValueType value);

        int count(ValueType value);
    }

    private static abstract class id36
            <ValueType, MapType extends Map<ValueType, Integer>>
            implements MultiSet<ValueType> {

        protected final MapType map;
        protected int size;

        protected id36(MapType map) {
            this.map = map;
            this.size = 0;
        }

        public int size() {
            return size;
        }

        public void inc(ValueType value) {
            int count = count(value);
            map.put(value, count + 1);

            ++size;
        }

        public boolean dec(ValueType value) {
            int count = count(value);
            if (count == 0) return false;

            if (count == 1) map.remove(value);
            else map.put(value, count - 1);

            --size;
            return true;
        }

        public int count(ValueType value) {
            Integer count = map.get(value);
            return (count == null ? 0 : count);
        }
    }

    private static class id22<ValueType>
            extends id36<ValueType, Map<ValueType, Integer>> {

        public static <ValueType> MultiSet<ValueType> id24() {
            Map<ValueType, Integer> map = new HashMap<ValueType, Integer>();
            return new id22<ValueType>(map);
        }

        id22(Map<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private interface id37<ValueType> extends MultiSet<ValueType> {

        ValueType min();
        ValueType max();

        ValueType pollMin();
        ValueType pollMax();

        ValueType lower(ValueType value);
        ValueType floor(ValueType value);

        ValueType ceiling(ValueType value);
        ValueType higher(ValueType value);
    }

    private static abstract class id67<ValueType>
            extends id36<ValueType, NavigableMap<ValueType, Integer>>
            implements id37<ValueType> {

        id67(NavigableMap<ValueType, Integer> map) {
            super(map);
        }

        @Override
        public ValueType min() {
            return (size == 0 ? null : map.firstKey());
        }

        @Override
        public ValueType max() {
            return (size == 0 ? null : map.lastKey());
        }

        @Override
        public ValueType pollMin() {
            ValueType first = min();
            if (first != null) dec(first);
            return first;
        }

        @Override
        public ValueType pollMax() {
            ValueType last = max();
            dec(last);
            return last;
        }

        @Override
        public ValueType lower(ValueType value) {
            return map.lowerKey(value);
        }

        @Override
        public ValueType floor(ValueType value) {
            return map.floorKey(value);
        }

        @Override
        public ValueType ceiling(ValueType value) {
            return map.ceilingKey(value);
        }

        @Override
        public ValueType higher(ValueType value) {
            return map.higherKey(value);
        }
    }

    private static class id26<ValueType>
            extends id67<ValueType> {

        public static <ValueType> id37<ValueType> id24() {
            NavigableMap<ValueType, Integer> map = new TreeMap<ValueType, Integer>();
            return new id26<ValueType>(map);
        }

        id26(NavigableMap<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

        
        private static final long id62 = -3793737771950984481L;

        public IdMap() {
            super();
        }

        int register(KeyType key) {
            Integer id = super.get(key);
            if (id == null) {
                super.put(key, id = size());
            }

            return id;
        }

        int getId(KeyType key) {
            return get(key);
        }
    }

    


    private static class id74<ValueType extends Comparable<ValueType>> {

        private final List<ValueType> values;

        public id74() {
            this.values = new ArrayList<ValueType>();
        }

        void addValue(ValueType value) {
            values.add(value);
        }

        IdMap<ValueType> build() {
            Collections.sort(values);

            IdMap<ValueType> ids = new IdMap<ValueType>();

            for (int index = 0; index < values.size(); ++index) {
                ValueType value = values.get(index);
                if (index == 0 || values.get(index - 1).compareTo(value) != 0) {
                    ids.register(value);
                }
            }

            return ids;
        }
    }

    


    private static int[] castInt(List<Integer> list) {
        int[] array = new int[list.size()];
        for (int i = 0; i < array.length; ++i) {
            array[i] = list.get(i);
        }

        return array;
    }

    private static long[] castLong(List<Long> list) {
        long[] array = new long[list.size()];
        for (int i = 0; i < array.length; ++i) {
            array[i] = list.get(i);
        }

        return array;
    }

    


    
    private static List<Integer> order(int n) {
        List<Integer> sequence = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i) {
            sequence.add(i);
        }

        return sequence;
    }

    


    interface Rmq {
        int getMin(int left, int right);
        int id7(int left, int right);
    }

    private static class SparseTable implements Rmq {

        private static final int MAX_BIT = 20;

        int n;
        int[] array;

        SparseTable(int[] array) {
            this.n = array.length;
            this.array = array;
        }

        int[] id73;
        int[][] table;

        int id48(int leftIndex, int rightIndex) {
            return (array[leftIndex] <= array[rightIndex])
                    ? leftIndex
                    : rightIndex;
        }

        SparseTable build() {
            this.id73 = new int[n + 1];
            id73[0] = 0;
            for (int i = 1; i <= n; ++i) {
                id73[i] = id73[i - 1];
                int length = (1 << id73[i]);
                if (length + length <= i) ++id73[i];
            }

            this.table = new int[MAX_BIT][n];
            table[0] = castInt(order(n));

            for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
                for (int i = 0, j = (1 << bit); j < n; ++i, ++j) {
                    table[bit + 1][i] = id48(
                            table[bit][i], table[bit][j]
                    );
                }
            }

            return this;
        }

        @Override
        public int id7(int left, int right) {
            int length = (right - left + 1);

            int bit = id73[length];
            int segmentLength = (1 << bit);

            return id48(
                    table[bit][left], table[bit][right - segmentLength + 1]
            );
        }

        @Override
        public int getMin(int left, int right) {
            return array[id7(left, right)];
        }
    }

    private static Rmq id79(int[] array) {
        return new SparseTable(array).build();
    }

    


    interface Lca {
        Lca build(int root);
        int lca(int a, int b);

        int height(int v);
    }

    private static class id13 implements Lca {

        int n;
        int[][] graph;

        id13(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;

        int[] order;
        int[] heights;
        int[] first;

        Rmq rmq;

        @Override
        public id13 build(int root) {
            this.order = new int[n + n];
            this.heights = new int[n];

            this.first = new int[n];
            Arrays.fill(first, -1);

            this.time = 0;
            dfs(root, 0);

            int[] id25 = new int[n + n];
            for (int i = 0; i < order.length; ++i) {
                id25[i] = heights[order[i]];
            }

            this.rmq = id79(id25);
            return this;
        }

        void dfs(int from, int height) {
            first[from] = time;
            order[time] = from;
            heights[from] = height;
            ++time;

            for (int to : graph[from]) {
                if (first[to] == -1) {
                    dfs(to, height + 1);

                    order[time] = from;
                    ++time;
                }
            }
        }

        @Override
        public int lca(int a, int b) {
            int aFirst = first[a], bFirst = first[b];
            int left = min(aFirst, bFirst), right = max(aFirst, bFirst);

            int orderIndex = rmq.id7(left, right);
            return order[orderIndex];
        }

        @Override
        public int height(int v) {
            return heights[v];
        }
    }

    private static class id53 implements Lca {

        private static final int MAX_BIT = 20;

        int n;
        int[][] graph;

        int[] h;
        int[][] parents;

        id53(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        @Override
        public Lca build(int root) {
            this.h = new int[n];

            this.parents = new int[MAX_BIT][n];
            Arrays.fill(parents[0], -1);

            Queue<Integer> queue = new ArrayDeque<Integer>();

            queue.add(root);
            add(root, root);

            while (queue.size() > 0) {
                int from = queue.poll();
                for (int to : graph[from]) {
                    if (parents[0][to] == -1) {
                        add(from, to);
                        queue.add(to);
                    }
                }
            }

            return this;
        }

        void add(int parent, int v) {
            h[v] = h[parent] + 1;
            parents[0][v] = parent;
            for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
                parents[bit + 1][v] = parents[bit][parents[bit][v]];
            }
        }

        @Override
        public int lca(int a, int b) {
            if (h[a] < h[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }

            int delta = h[a] - h[b];
            for (int bit = MAX_BIT - 1; bit >= 0; --bit) {
                if (delta >= (1 << bit)) {
                    delta -= (1 << bit);
                    a = parents[bit][a];
                }
            }

            if (a == b) return a;

            for (int bit = MAX_BIT - 1; bit >= 0; --bit) {
                int nextA = parents[bit][a], nextB = parents[bit][b];
                if (nextA != nextB) {
                    a = nextA;
                    b = nextB;
                }
            }

            return parents[0][a];
        }

        @Override
        public int height(int v) {
            return h[v];
        }
    }

    private static Lca id21(int[][] graph, int root) {
        return new id13(graph).build(root);
    }

    


    private static class id64 {

        int n;
        int[][] graph;

        id64(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;
        int[] tin, up;

        boolean[] used;

        id64 build() {
            calculateTimes();
            id75();

            return this;
        }

        void calculateTimes() {
            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            this.used = new boolean[n];
            id65(0, -1);
        }

        void id65(int from, int parent) {
            used[from] = true;

            up[from] = tin[from] = time;
            ++time;

            for (int to : graph[from]) {
                if (to == parent) continue;

                if (used[to]) {
                    up[from] = min(up[from], tin[to]);
                } else {
                    id65(to, from);
                    up[from] = min(up[from], up[to]);
                }
            }
        }

        int[] components;
        int[][] componentsGraph;

        int component(int v) { return components[v]; }

        int[][] toGraph() {
            return componentsGraph;
        }

        void id75() {
            this.components = new int[n];
            Arrays.fill(components, -1);

            for (int v = 0; v < n; ++v) {
                if (components[v] == -1) {
                    id41(v, v);
                }
            }

            GraphBuilder graphBuilder = GraphBuilder.createInstance(n);

            Set<Point> edges = new HashSet<Point>();
            for (int from = 0; from < n; ++from) {
                int fromComponent = components[from];

                for (int to : graph[from]) {
                    int toComponent = components[to];
                    if (fromComponent == toComponent) continue;

                    Point edge = new Point(fromComponent, toComponent);
                    if (edges.add(edge)) graphBuilder.id56(fromComponent, toComponent);
                }
            }

            this.componentsGraph = graphBuilder.build();
        }

        void id41(int from, int color) {
            components[from] = color;
            for (int to : graph[from]) {
                if (components[to] != -1) continue;

                if (tin[from] >= up[to] && tin[to] >= up[from]) {
                    id41(to, color);
                }
            }
        }
    }

    


    private static class id35 {

        static class Edge {
            int to;
            int index;

            Edge(int to, int index) {
                this.to = to;
                this.index = index;
            }
        }

        int n, m;
        List<Edge>[] graph;
        List<Edge> edges;

        id35(int n) {
            this.n = n;
            this.m = 0;

            this.graph = new List[n];
            for (int v = 0; v < n; ++v) {
                graph[v] = new ArrayList<Edge>();
            }

            this.edges = new ArrayList<Edge>();
        }

        void addEdge(int from, int to) {
            Edge id28 = new Edge(to, m);
            Edge id54 = new Edge(from, m + 1);

            edges.add(id28);
            edges.add(id54);

            graph[from].add(id28);
            graph[to].add(id54);

            m += 2;
        }

        int time;

        boolean[] used;
        int[] tin, up;
        int[] parents;

        boolean[] id33;

        boolean[] id30() {
            this.id33 = new boolean[n];

            this.used = new boolean[n];
            this.parents = new int[n];
            Arrays.fill(parents, -1);

            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    id47(v, -1);
                }
            }

            return id33;
        }

        void id47(int from, int parent) {
            used[from] = true;
            parents[from] = parent;

            ++time;
            up[from] = tin[from] = time;

            int childrenCount = 0;

            for (Edge e : graph[from]) {
                int to = e.to;

                if (to == parent) continue;

                if (used[to]) {
                    up[from] = min(up[from], tin[to]);
                } else {
                    ++childrenCount;

                    id47(to, from);
                    up[from] = min(up[from], up[to]);
                    if (up[to] >= tin[from] && parent != -1) {
                        id33[from] = true;
                    }
                }
            }

            if (parent == -1 && childrenCount > 1) {
                id33[from] = true;
            }
        }

        int[] edgeColors;
        int id77;

        int[] paintEdges() {
            this.edgeColors = new int[m];
            Arrays.fill(edgeColors, -1);

            this.id77 = -1;

            this.used = new boolean[n];

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    ++id77;
                    id27(v, id77, -1);
                }
            }

            return edgeColors;
        }

        void paintEdge(int edgeIndex, int color) {
            if (edgeColors[edgeIndex] != -1) return;

            edgeColors[edgeIndex] = edgeColors[edgeIndex ^ 1] = color;
        }

        void id27(int from, int color, int parent) {
            used[from] = true;

            for (Edge e : graph[from]) {
                int to = e.to;
                if (to == parent) continue;

                if (!used[to]) {
                    if (up[to] >= tin[from]) {
                        int newColor = ++id77;
                        paintEdge(e.index, newColor);
                        id27(to, newColor, from);
                    } else {
                        paintEdge(e.index, color);
                        id27(to, color, from);
                    }
                } else if (up[to] <= tin[from]){
                    paintEdge(e.index, color);
                }
            }
        }

        Set<Integer>[] id50() {
            Set<Integer>[] id82 = new Set[n];
            for (int v = 0; v < n; ++v) {
                id82[v] = new HashSet<Integer>();
                for (Edge e : graph[v]) {
                    id82[v].add(edgeColors[e.index]);
                }
            }

            return id82;
        }

        id35 build() {
            id30();
            paintEdges();
            id3();

            return this;
        }

        int[][] componentsGraph;

        void id3() {
            Set<Integer>[] id82 = id50();

            int id5 = id82.length;
            int size = id82.length + id77 + 1;

            GraphBuilder graphBuilder = GraphBuilder.createInstance(size);
            for (int v = 0; v < id82.length; ++v) {
                for (int edgeColor : id82[v]) {
                    graphBuilder.addEdge(v, edgeColor + id5);
                }
            }

            this.componentsGraph = graphBuilder.build();
        }

        int[][] toGraph() {
            return componentsGraph;
        }
    }

    


    private static class DSU {

        int[] sizes;

        int[] ranks;
        int[] parents;

        static DSU createInstance(int size) {
            int[] sizes = new int[size];
            Arrays.fill(sizes, 1);

            return new DSU(sizes);
        }

        DSU(int[] sizes) {
            this.sizes = sizes;

            int size = sizes.length;

            this.ranks = new int[size];
            Arrays.fill(ranks, 1);

            this.parents = castInt(order(size));
        }

        int get(int v) {
            if (v == parents[v]) return v;
            return parents[v] = get(parents[v]);
        }

        boolean union(int a, int b) {
            a = get(a);
            b = get(b);

            if (a == b) return false;

            if (ranks[a] < ranks[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }

            parents[b] = a;
            sizes[a] += sizes[b];

            if (ranks[a] == ranks[b]) ++ranks[a];

            return true;
        }
    }

    

}