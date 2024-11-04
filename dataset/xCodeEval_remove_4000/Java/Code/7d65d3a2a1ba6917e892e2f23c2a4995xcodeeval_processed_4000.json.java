import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;
import java.util.Queue;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class C implements Runnable{

    

    

    

    

    


    private final static Random rnd = new Random();
    private final static String fileName = "";

    private final static long MODULO = 1000 * 1000 * 1000 + 7;

    class Query {
    	int index;
    	
    	int type;
    	int first, second;
    	
		public Query(int index, int type, int first, int second) {
			super();
			this.index = index;
			this.type = type;
			this.first = first;
			this.second = second;
		}
    	
    	
    }
    
    private void solve() {
    	int n = readInt();
    	int q = readInt();
    	
    	int[] a = id45(n);
    	
    	Query[] queries = new Query[q];
    	for (int i = 0; i < q; ++i) {
    		int index = i;
    		
    		int type = readInt();
    		int first = readInt() - 1;
    		int second = readInt() - 1;
    		
    		queries[i] = new Query(index, type, first, second);
    	}
    
    	CSolver solver = createSolver();
    	
    	long[] answers = solver.getAnswers(n, a, q, queries);
    	for (Query query : queries) {
    		if (query.type == 2) {
    			out.println(answers[query.index]);
    		}
    	}
    }
    
    interface CSolver {
    	
    	long[] getAnswers(int n, int[] a, int q, Query[] queries);
    }
    
    static CSolver createSolver() {
    	return new id13();
    }
    
    static abstract class id48 implements CSolver {
    	
    	int[] a;
    	NavigableSet<Integer>[] indexSets;
    	
    	void id74(int[] a) {
    		this.a = a;
    		
    		int n = a.length;
    		
    		indexSets = new NavigableSet[n];
    		for (int i = 0; i < n; ++i) {
        		indexSets[i] = new TreeSet<Integer>();
        	}
        	
        	for (int i = 0; i < n; ++i) {
        		indexSets[a[i]].add(i);
        	}
    	}
    	    
    	void set(int index, int value) {
    		indexSets[a[index]].remove(index);
    		
    		a[index] = value;
    		indexSets[value].add(index);
    	}
    	
    	@Override
    	public long[] getAnswers(int n, int[] a, int q, Query[] queries) {
    		long[] answers = new long[q];
    		for (int i = 0; i < q; ++i) {
    			answers[i] = queries[i].type - 2;
    		}
    		
    		fillAnswers(n, a, q, queries, answers);
    		
    		return answers;
    	}
    	
    	abstract void fillAnswers(int n, int[] a, int q, Query[] queries, long[] answers);
    }
    
    static class id13 extends id48 {

		@Override
		void fillAnswers(int n, int[] a, int q, Query[] queries, long[] answers) {
			int[] aInit = a.clone();
			
			id74(a);
			
			List<Integer>[] rightLists = new List[n];
			for (int i = 0; i < n; ++i) {
				rightLists[i] = new ArrayList<Integer>();
			}
			
			for (int i = 0; i < n; ++i) {
				Integer right = indexSets[a[i]].higher(i);
				if (right != null) {
					rightLists[i].add(right);
				}
			}
			
			for (Query query : queries) {
				if (query.type == 2) continue;
				
				int index = query.first;
				int oldValue = a[index], newValue = query.second;
				
				Integer prev = indexSets[oldValue].lower(index);
				Integer next = indexSets[oldValue].higher(index);
				
				if (prev != null && next != null) {
					rightLists[prev].add(next);
				}
				
				set(index, newValue);
				
				prev = indexSets[newValue].lower(index);
				next = indexSets[newValue].higher(index);
				
				if (prev != null) {
					rightLists[prev].add(index);
				}
				
				if (next != null) {
					rightLists[index].add(next);
				}
			}
			
			for (List<Integer> rights : rightLists) {
				Collections.sort(rights);
			}
			
			id39 tree = new id39(n, rightLists);
			
			a = aInit;
			id74(a);
			
			for (int i = 0; i < n; ++i) {
				Integer next = indexSets[a[i]].higher(i);
				if (next != null) {
					tree.updatePoint(i, next, next - i);
				}
			}
			
			for (Query query : queries) {
				int type = query.type;
				if (type == 1) {
					int index = query.first;
					int oldValue = a[index], newValue = query.second;
					
					Integer prev = indexSets[oldValue].lower(index);
					Integer next = indexSets[oldValue].higher(index);
					
					if (prev != null) {
						tree.updatePoint(prev, index, prev - index);
					}
					
					if (next != null) {
						tree.updatePoint(index, next, index - next);
					}
					
					if (prev != null && next != null) {
						tree.updatePoint(prev, next, next - prev);
					}
					
					set(index, newValue);
					
					prev = indexSets[newValue].lower(index);
					next = indexSets[newValue].higher(index);
					
					if (prev != null && next != null) {
						tree.updatePoint(prev, next, prev - next);
					}
					
					if (prev != null) {
						tree.updatePoint(prev, index, index - prev);
					}
					
					if (next != null) {
						tree.updatePoint(index, next, next - index);
					}
				} else {
					int index = query.index;
					int left = query.first, right = query.second;
					
					answers[index] = tree.id49(left, right, left, right);
				}
			}
		}
    }
    
    static class id32 extends id48 {
    	
    	@Override
    	void fillAnswers(int n, int[] a, int q, Query[] queries, long[] answers) {
        	int blockSize = 700;
        	
        	Query[] blockUpdates = new Query[blockSize];
        	Query[] blockQueries = new Query[blockSize];
        	
        	Deque<Query>[] id62 = new Deque[n];
        	Deque<Query>[] id61 = new Deque[n];
        	
        	for (int i = 0; i < n; ++i) {
        		id62[i] = new ArrayDeque<Query>();
        		id61[i] = new ArrayDeque<Query>();
        	}
        	
        	id38 endTree = new id38(n);
        	id38 startTree = new id38(n);
        	
        	id74(a);
        	
        	int[] prevIndexes = new int[n], nextIndexes = new int[n];
        	int[] interesting = new int[n];
        	Arrays.fill(interesting, -1);
        	
        	for (int queryStart = 0; queryStart < q; queryStart += blockSize) {
        		blockSize = Math.min(blockSize, q - queryStart);
        		
        		Arrays.fill(blockUpdates, null);
        		Arrays.fill(blockQueries, null);
        		
        		int updatesCount = 0;
        		int queriesCount = 0;
        		
        		for (int i = 0; i < blockSize; ++i) {
        			int index = queryStart + i;
        			Query query = queries[index];
        			
        			if (query.type == 1) {
        				blockUpdates[updatesCount++] = query;
        			} else {
        				blockQueries[queriesCount++] = query;
        			}
        		}
        		
        		Set<Integer> id56 = new TreeSet<Integer>();
        		
        		for (int i = 0; i < updatesCount; ++i) {
        			Query update = blockUpdates[i];
        			int fromValue = a[update.first];
        			int toValue = update.second;
        			
        			id56.add(fromValue);
        			id56.add(toValue);
        		}
        		
        		int[] interestingValues = castInt(new ArrayList<Integer>(id56));
        		
        		for (int value : interestingValues) {
        			interesting[value] = queryStart;
        		}
        		
        		for (int i = 0; i < queriesCount; ++i) {
        			Query query = blockQueries[i];
        			
        			id62[query.first].add(query);
        			id61[query.second].add(query);
        		}
        		
        		endTree.clear();
        		Arrays.fill(prevIndexes, -1);
        		

        		for (int i = 0; i < n; ++i) {
        			int value = a[i];
        			
        			if (interesting[value] != queryStart) {
            			int prevIndex = prevIndexes[value];
            			if (prevIndex != -1) {
            				endTree.update(prevIndex, -prevIndex);
            			}
            			
            			endTree.update(i, i);
            			prevIndexes[value] = i;	
        			}
        			
        			for (Query query : id61[i]) {
        				int left = query.first, right = i;
        				long sum = endTree.get(left, right);
        				
        				answers[query.index] += sum; 
        			}
        		}
        		
        		

        		startTree.clear();
        		Arrays.fill(nextIndexes, -1);
        		
        		for (int i = n - 1; i >= 0; --i) {
        			int value = a[i];
        			if (interesting[value] != queryStart) {
        				Integer nextIndex = nextIndexes[value];
            			if (nextIndex != -1) {
            				startTree.update(nextIndex, -nextIndex);
            			}
            			
            			startTree.update(i, i);
            			nextIndexes[value] = i;	
        			}
        			
        			for (Query query : id62[i]) {
        				int left = i, right = query.second;
        				long sum = startTree.get(left, right);
        				
        				answers[query.index] -= sum; 
        			}
        		}
        		
        		int j = 0;
        		for (int i = 0; i < queriesCount; ++i) {
        			Query query = blockQueries[i];
        			
        			for (; j < updatesCount; ++j) {
        				Query update = blockUpdates[j];
        				
        				if (update.index > query.index) {
        					break;
        				}
        				
        				set(update.first, update.second);
        			}
        			
        			int left = query.first, right = query.second;
        			for (int interestingValue : interestingValues) {
        				NavigableSet<Integer> indexes = indexSets[interestingValue];
        				
        				Integer start = indexes.ceiling(left);
        				if (start == null || start > right) continue;
        				
        				Integer end = indexes.floor(right);
        				if (end == null || end < left) continue;
        				
        				answers[query.index] += end - start; 
        			}	
        			
        		}
        		
        		for (; j < updatesCount; ++j) {
    				Query update = blockUpdates[j];
    				
    				set(update.first, update.second);
    			}
        		
        		

        		for (int i = 0; i < queriesCount; ++i) {
        			Query query = blockQueries[i];
        			
        			id62[query.first].clear();
        			id61[query.second].clear();
        		}
        	}
        }
    }
    
    

    static class id38 {
    	
    	int size;
    	long[] tree;
    	
    	id38(int size){ 
    		this.size = size + 1;
    		this.tree = new long[this.size];
    	}
    	
    	void clear() {
    		Arrays.fill(tree, 0);
    	}
    	
    	long get(int left, int right) {
    		return get(right + 1) - get(left);
    	}
    	
    	long get(int index) {
    		long sum = 0;
    		for (; index >= 0; index &= (index + 1), --index) {
    			sum += tree[index];
    		}
    		
    		return sum;
    	}
    	
    	void update(int index, long delta) {
    		++index;
    		for (; index < size; index |= (index + 1)) {
    			tree[index] += delta;
    		}
    	}
    }
    
    static class id9 extends id38 {
    	
    	int[] values;
    	
    	id9(List<Integer> valuesList) {
    		super(valuesList.size());
    		this.values = castInt(valuesList);
    	}
    	
    	@Override
    	void update(int realIndex, long delta) {
    		int index = Arrays.binarySearch(values, realIndex);
    		super.update(index, delta);
    	}
    	
    	@Override
    	long get(int realLeft, int realRight) {
    		int left = Arrays.binarySearch(values, realLeft);
    		if (left < 0) left = ~left;
    		
    		int right = Arrays.binarySearch(values, realRight);
    		if (right < 0) right = (~right) - 1;
    		
    		if (left > right) return 0;
    		
    		return super.get(left, right);
    	}
    }
    
    static class id39 {
    	
    	int size;
    	id9[] trees;
    	
    	id39(int size, List<Integer>[] values) {
    		this.size = size;
    		this.trees = new id9[size << 2];
    		build(1, 0, size - 1, values);
    	}
    	
    	static List<Integer> merge(int[] left, int[] right) {
    		List<Integer> values = new ArrayList<Integer>();
    		
    		for (int i = 0, j = 0, last = -1; i < left.length || j < right.length; ) {
    			int value = -1;
    			if (i == left.length) {
    				value = right[j++];
    			} else if (j == right.length) {
    				value = left[i++];
    			} else if (left[i] <= right[j]) {
    				value = left[i++];
    			} else {
    				value = right[j++];
    			}
    			
    			if (last != value) {
    				values.add(last = value);
    			}
    		}
    		
    		return values;
    	}
    	
    	int[] build(int v, int left, int right, List<Integer>[] values) {
    		List<Integer> valuesList = null;
    		
    		if (left == right) {
    			valuesList = values[left];
    		} else {
    			int mid = (left + right) >> 1;
    			
    			int vLeft = (v << 1), vRight = (vLeft + 1);
    			
    			int[] leftValues = build(vLeft, left, mid, values);
    			int[] rightValues = build(vRight, mid + 1, right, values);
    			
    			valuesList = merge(leftValues, rightValues);
    		}
    		
    		trees[v] = new id9(valuesList);
    		return trees[v].values;
    	}
    	
    	int startX, endX;
    	int startY, endY;
    	
    	long id49(int startX, int endX, int startY, int endY) {
    		this.startX = startX;
    		this.endX = endX;
    		
    		this.startY = startY;
    		this.endY = endY;
    		
    		return get(1, 0, size - 1);
    	}
    	
    	long get(int v, int left, int right) {
    		if (startX <= left && right <= endX) {
    			return trees[v].get(startY, endY);
    		}
    		
    		int mid = (left + right) >> 1;
    		int vLeft = (v << 1), vRight = (vLeft + 1);
    		
    		long result = 0;
    		if (startX <= mid) result += get(vLeft, left, mid);
    		if (mid < endX) result += get(vRight, mid + 1, right);
    			
    		return result;
    	}
    	
    	int xIndex, yIndex;
    	long delta;
    	
    	void updatePoint(int xIndex, int yIndex, long delta) {
    		this.xIndex = xIndex;
    		this.yIndex = yIndex;
    		this.delta = delta;
    		
    		update(1, 0, size - 1);
    	}
    	
    	void update(int v, int left, int right) {
    		while (left <= right) {
    			trees[v].update(yIndex, delta);
    			
    			if (left != right) {
    	    		int mid = (left + right) >> 1;
    	    		int vLeft = (v << 1), vRight = (vLeft + 1);
    	    		
    	    		if (xIndex <= mid) {
    	    			v = vLeft;
    	    			right = mid;
    	    		} else {
    	    			v = vRight;
    	    			left = mid + 1;
    	    		}
    			} else {
    				break;
    			}
    		}
    	}
    }
    


    


    private static long add(long a, long b) { return (a + b) % MODULO; }
    private static long subtract(long a, long b) { return add(a, MODULO - b) % MODULO; }
    private static long mult(long a, long b) { return (a * b) % MODULO; }

    


    private final static boolean id40 = false;
    private final static boolean id3 = true;
    private final boolean id30 = !new File("input.txt").exists();

    private final static int id67 = 128;

    private final static boolean id16 = true;

    


    public void run(){
        try{
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (id30) {
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
                        if (id40) break;
                        else throw e;
                    }
                } while (id3);
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
        new Thread(null, new C(), "", id67 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id30){
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
        if (id30){
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

    


    private final char id63 = '\0';

    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1){
                return id63;
            }

            return (char) intValue;
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private char[] id5() {
        return readLine().toCharArray();
    }

    private char[][] id72(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id5();
        }

        return field;
    }

    


    private long id14() {
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

        if (!id16) {
            return Integer.parseInt(readString());
        } else {
            return (int) id14();
        }
    }

    private int[] id1(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    private int[] id7(int size) {
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

    private int[] id45(int size) {
        int[] array = id1(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    private int[][] id12(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id1(columnsCount);
        }

        return matrix;
    }

    private int[][] id55(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id45(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id16) {
            return Long.parseLong(readString());
        } else {
            return id14();
        }
    }

    private long[] id10(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index){
            array[index] = readLong();
        }

        return array;
    }

    


    private double readDouble() {
        return Double.parseDouble(readString());
    }

    private double[] id41(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger id15() {
        return new BigInteger(readString());
    }

    private BigDecimal id53() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    private Point[] id58(int size) {
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
            id54(from, to);
            id54(to, from);
        }

        public void id54(int from, int to) {
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

    private final static int id35 = 0, id65 = 1;

    private int[][] id8(int vertexNumber, int edgesNumber) {
        return id8(vertexNumber, edgesNumber, id65, false);
    }

    private int[][] id8(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.id54(from, to);
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

    private Edge[][] id17(int vertexNumber, int edgesNumber) {
        return id17(vertexNumber, edgesNumber, id65, false);
    }

    private Edge[][] id17(int vertexNumber, int edgesNumber,
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

    


    private static class id36 {

        static Comparator<id36> increaseComparator = new Comparator<id36>() {

            @Override
            public int compare(id36 id50, id36 id66) {
                int value1 = id50.value;
                int value2 = id66.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id50.index;
                int index2 = id66.index;

                return index1 - index2;
            }
        };

        static Comparator<id36> id26 = new Comparator<id36>() {

            @Override
            public int compare(id36 id50, id36 id66) {
                int value1 = id50.value;
                int value2 = id66.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id50.index;
                int index2 = id66.index;

                return index1 - index2;
            }
        };

        static id36[] from(int[] array) {
            id36[] iip = new id36[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id36(array[i], i);
            }

            return iip;
        }

        int value, index;

        id36(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int id42() {
            return index + 1;
        }
    }

    private id36[] id28(int size) {
        id36[] array = new id36[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id36(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id79 = 12;

        private int precision;
        private String format, id78;

        {
            precision = id79;

            format = createFormat(precision);
            id78 = format + " ";
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
            id78 = format + " ";
        }

        String createFormat(int precision){
            return "%." + precision + "f";
        }

        @Override
        public void print(double d){
            printf(format, d);
        }

        void id75(double d){
            printf(id78, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id75(d[i]);
            }

            print(d[d.length - 1]);
        }

        @Override
        public void println(double d){
            printlnAll(d);
        }

        void printlnAll(double... d){
            printAll(d);
            println();
        }
    }

    


    private static class RuntimeIOException extends RuntimeException {

        
        private static final long id57 = -6463830523020118289L;

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

    private static Point id68(int[] array) {
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

    


    private static int[] id47(int n) {
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

    


    int[] id20(int value) {
        List<Integer> id0 = new ArrayList<Integer>();
        for (int divisor = 1; divisor * divisor <= value; ++divisor) {
            if (value % divisor == 0) {
                id0.add(divisor);
                if (divisor * divisor != value) {
                    id0.add(value / divisor);
                }
            }
        }

        return castInt(id0);
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

    private static abstract class id33
            <ValueType, MapType extends Map<ValueType, Integer>>
            implements MultiSet<ValueType> {

        protected final MapType map;
        protected int size;

        protected id33(MapType map) {
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

    private static class id19<ValueType>
            extends id33<ValueType, Map<ValueType, Integer>> {

        public static <ValueType> MultiSet<ValueType> id21() {
            Map<ValueType, Integer> map = new HashMap<ValueType, Integer>();
            return new id19<ValueType>(map);
        }

        id19(Map<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private interface id34<ValueType> extends MultiSet<ValueType> {

        ValueType min();
        ValueType max();

        ValueType pollMin();
        ValueType pollMax();

        ValueType lower(ValueType value);
        ValueType floor(ValueType value);

        ValueType ceiling(ValueType value);
        ValueType higher(ValueType value);
    }

    private static abstract class id64<ValueType>
            extends id33<ValueType, NavigableMap<ValueType, Integer>>
            implements id34<ValueType> {

        id64(NavigableMap<ValueType, Integer> map) {
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

    private static class id23<ValueType>
            extends id64<ValueType> {

        public static <ValueType> id34<ValueType> id21() {
            NavigableMap<ValueType, Integer> map = new TreeMap<ValueType, Integer>();
            return new id23<ValueType>(map);
        }

        id23(NavigableMap<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

        
        private static final long id57 = -3793737771950984481L;

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

    


    private static class id70<ValueType extends Comparable<ValueType>> {

        private final List<ValueType> values;

        public id70() {
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
        int id6(int left, int right);
    }

    private static class SparseTable implements Rmq {

        private static final int MAX_BIT = 20;

        int n;
        int[] array;

        SparseTable(int[] array) {
            this.n = array.length;
            this.array = array;
        }

        int[] id69;
        int[][] table;

        int id44(int leftIndex, int rightIndex) {
            return (array[leftIndex] <= array[rightIndex])
                    ? leftIndex
                    : rightIndex;
        }

        SparseTable build() {
            this.id69 = new int[n + 1];
            id69[0] = 0;
            for (int i = 1; i <= n; ++i) {
                id69[i] = id69[i - 1];
                int length = (1 << id69[i]);
                if (length + length <= i) ++id69[i];
            }

            this.table = new int[MAX_BIT][n];
            table[0] = castInt(order(n));

            for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
                for (int i = 0, j = (1 << bit); j < n; ++i, ++j) {
                    table[bit + 1][i] = id44(
                            table[bit][i], table[bit][j]
                    );
                }
            }

            return this;
        }

        @Override
        public int id6(int left, int right) {
            int length = (right - left + 1);

            int bit = id69[length];
            int segmentLength = (1 << bit);

            return id44(
                    table[bit][left], table[bit][right - segmentLength + 1]
            );
        }

        @Override
        public int getMin(int left, int right) {
            return array[id6(left, right)];
        }
    }

    private static Rmq id76(int[] array) {
        return new SparseTable(array).build();
    }

    


    interface Lca {
        Lca build(int root);
        int lca(int a, int b);

        int height(int v);
    }

    private static class id11 implements Lca {

        int n;
        int[][] graph;

        id11(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;

        int[] order;
        int[] heights;
        int[] first;

        Rmq rmq;

        @Override
        public id11 build(int root) {
            this.order = new int[n + n];
            this.heights = new int[n];

            this.first = new int[n];
            Arrays.fill(first, -1);

            this.time = 0;
            dfs(root, 0);

            int[] id22 = new int[n + n];
            for (int i = 0; i < order.length; ++i) {
                id22[i] = heights[order[i]];
            }

            this.rmq = id76(id22);
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

            int orderIndex = rmq.id6(left, right);
            return order[orderIndex];
        }

        @Override
        public int height(int v) {
            return heights[v];
        }
    }

    private static class id51 implements Lca {

        private static final int MAX_BIT = 20;

        int n;
        int[][] graph;

        int[] h;
        int[][] parents;

        id51(int[][] graph) {
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

    private static Lca id18(int[][] graph, int root) {
        return new id11(graph).build(root);
    }

    


    private static class id59 {

        int n;
        int[][] graph;

        id59(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;
        int[] tin, up;

        boolean[] used;

        id59 build() {
            calculateTimes();
            id71();

            return this;
        }

        void calculateTimes() {
            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            this.used = new boolean[n];
            id60(0, -1);
        }

        void id60(int from, int parent) {
            used[from] = true;

            up[from] = tin[from] = time;
            ++time;

            for (int to : graph[from]) {
                if (to == parent) continue;

                if (used[to]) {
                    up[from] = min(up[from], tin[to]);
                } else {
                    id60(to, from);
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

        void id71() {
            this.components = new int[n];
            Arrays.fill(components, -1);

            for (int v = 0; v < n; ++v) {
                if (components[v] == -1) {
                    id37(v, v);
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
                    if (edges.add(edge)) graphBuilder.id54(fromComponent, toComponent);
                }
            }

            this.componentsGraph = graphBuilder.build();
        }

        void id37(int from, int color) {
            components[from] = color;
            for (int to : graph[from]) {
                if (components[to] != -1) continue;

                if (tin[from] >= up[to] && tin[to] >= up[from]) {
                    id37(to, color);
                }
            }
        }
    }

    


    private static class id31 {

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

        id31(int n) {
            this.n = n;
            this.m = 0;

            this.graph = new List[n];
            for (int v = 0; v < n; ++v) {
                graph[v] = new ArrayList<Edge>();
            }

            this.edges = new ArrayList<Edge>();
        }

        void addEdge(int from, int to) {
            Edge id25 = new Edge(to, m);
            Edge id52 = new Edge(from, m + 1);

            edges.add(id25);
            edges.add(id52);

            graph[from].add(id25);
            graph[to].add(id52);

            m += 2;
        }

        int time;

        boolean[] used;
        int[] tin, up;
        int[] parents;

        boolean[] id29;

        boolean[] id27() {
            this.id29 = new boolean[n];

            this.used = new boolean[n];
            this.parents = new int[n];
            Arrays.fill(parents, -1);

            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    id43(v, -1);
                }
            }

            return id29;
        }

        void id43(int from, int parent) {
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

                    id43(to, from);
                    up[from] = min(up[from], up[to]);
                    if (up[to] >= tin[from] && parent != -1) {
                        id29[from] = true;
                    }
                }
            }

            if (parent == -1 && childrenCount > 1) {
                id29[from] = true;
            }
        }

        int[] edgeColors;
        int id73;

        int[] paintEdges() {
            this.edgeColors = new int[m];
            Arrays.fill(edgeColors, -1);

            this.id73 = -1;

            this.used = new boolean[n];

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    ++id73;
                    id24(v, id73, -1);
                }
            }

            return edgeColors;
        }

        void paintEdge(int edgeIndex, int color) {
            if (edgeColors[edgeIndex] != -1) return;

            edgeColors[edgeIndex] = edgeColors[edgeIndex ^ 1] = color;
        }

        void id24(int from, int color, int parent) {
            used[from] = true;

            for (Edge e : graph[from]) {
                int to = e.to;
                if (to == parent) continue;

                if (!used[to]) {
                    if (up[to] >= tin[from]) {
                        int newColor = ++id73;
                        paintEdge(e.index, newColor);
                        id24(to, newColor, from);
                    } else {
                        paintEdge(e.index, color);
                        id24(to, color, from);
                    }
                } else if (up[to] <= tin[from]){
                    paintEdge(e.index, color);
                }
            }
        }

        Set<Integer>[] id46() {
            Set<Integer>[] id77 = new Set[n];
            for (int v = 0; v < n; ++v) {
                id77[v] = new HashSet<Integer>();
                for (Edge e : graph[v]) {
                    id77[v].add(edgeColors[e.index]);
                }
            }

            return id77;
        }

        id31 build() {
            id27();
            paintEdges();
            id2();

            return this;
        }

        int[][] componentsGraph;

        void id2() {
            Set<Integer>[] id77 = id46();

            int id4 = id77.length;
            int size = id77.length + id73 + 1;

            GraphBuilder graphBuilder = GraphBuilder.createInstance(size);
            for (int v = 0; v < id77.length; ++v) {
                for (int edgeColor : id77[v]) {
                    graphBuilder.addEdge(v, edgeColor + id4);
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