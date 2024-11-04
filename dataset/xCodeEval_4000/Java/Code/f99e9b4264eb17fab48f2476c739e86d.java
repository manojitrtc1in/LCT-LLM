import java.util.*;
import java.util.function.*;
import java.io.*;



public class RoundEdu130F implements Runnable {	
	MyPrintWriter out;
	MyScanner in;
	








	final static String IMPOSSIBLE = "IMPOSSIBLE";
	final static String POSSIBLE = "POSSIBLE";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean isFileIO) {
        if (System.getProperty("ONLINE_JUDGE") == null && isFileIO) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new MyPrintWriter(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new MyPrintWriter(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args) throws InterruptedException{


		Thread t = new Thread(null, new RoundEdu130F(), "RoundEdu130F", 1<<28);
		t.start();
		t.join();




    }
	
	public void run() {
		boolean isDebug = false;
		boolean isFileIO = true;
		boolean hasMultipleTests = true;
		
		initIO(isFileIO);
		
		

	
		int t = hasMultipleTests? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}

	    	getInput();

	    	solve();
	    	
	    	printOutput();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private void test() {
		Random rand = new Random();
		for(int t=0; t<1000; t++) {
			n = 2_0000;
			m = 2_0000;
			k = 10;
			int[] changeIndex = new int[k];
			for(int i=0; i<k-1; i++)
				changeIndex[i] = rand.nextInt(n);
			changeIndex[k-1] = 0;
			Arrays.sort(changeIndex);
			int[] a = new int[n];
			for(int i=0; i<k-1; i++)
				for(int j=changeIndex[i]; j<n; j++)
					a[j]++;
			constraints = new Constraint[m];
			for(int q=0; q<m; q++)
				constraints[q] = new Constraint(rand, n, k, a);
			
			solve();
			if(!Arrays.equals(ans, a)) {
				solve();
			}
		}
	}

	

	int n, m, k;
	Constraint[] constraints;
	void getInput() {
		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		constraints = new Constraint[m];
		for(int i=0; i<m; i++)
			constraints[i] = new Constraint(in);
	}
	
	static enum Ctype{
		NEQ, LEQ, GEQ; 
	}
	
	static class Constraint{
		Ctype t;
		int i, j, x;
		public Constraint(MyScanner in) {
			int tt = in.nextInt();
			if(tt == 1) {
				this.t = Ctype.NEQ;
				this.i = in.nextInt()-1;
				this.x = in.nextInt();
			}
			else{
				this.t = tt == 2? Ctype.LEQ: Ctype.GEQ;
				this.i = in.nextInt()-1;
				this.j = in.nextInt()-1;
				this.x = in.nextInt();
			}
		}
		public Constraint(Random rand, int n, int k, int[] a) {
			int tt = rand.nextInt(3);
			if(tt == 1) {
				this.t = Ctype.NEQ;
				this.i = rand.nextInt(n);
				do {
					this.x = rand.nextInt(k)+1;
				}while(this.x == a[i]);
			}
			else{
				this.t = tt == 2? Ctype.LEQ: Ctype.GEQ;
				this.i = rand.nextInt(n);
				do {
					this.j = rand.nextInt(n);
				}while(this.j == this.i);
				do {
					this.x = rand.nextInt(k*2-1)+2;
					if(tt == 2) {
						if(a[i] + a[j] <= x)
							break;
					}
					else {
						if(a[i] + a[j] >= x)
							break;				
					}
				}while(true);
			}
		}
	}
	
	void printOutput() {
		if(ans == null)
			out.printlnAns(-1);
		else
			out.printlnAns(ans);
	}

	int[] ans;
	void solve(){
		

		
		

		

		
		

		

		

		
		

		
		

		

		
		
		

		

		

		

		
		
		

		

		
		

		

		
		

		

		

		
		

		

		

		

		
		

		

		

		
		

		

		

		
		
		TwoSatSolver solver = new TwoSatSolver(n*k*2);
		
		solver.addTrueClause(solver.getPositiveLiteral(0, 1));
		
		

		for(int i=0; i<n; i++) {
			for(int x=1; x<k; x++) {
				solver.addIfThenClause(solver.getPositiveLiteral(i, x+1), solver.getPositiveLiteral(i, x));
			}
		}
		
		

		

		for(int i=0; i<n-1; i++) {
			for(int x=1; x<=k; x++) {
				solver.addIfThenClause(solver.getPositiveLiteral(i, x), solver.getPositiveLiteral(i+1, x));
			}
		}
		
		for(int q=0; q<m; q++) {
			int i = constraints[q].i;
			int j = constraints[q].j;
			int x = constraints[q].x;
			switch(constraints[q].t) {
			case NEQ:
				

				

				

				if(x == 1)
					solver.addTrueClause(solver.getPositiveLiteral(i, 2));
				else if(x == k)
					solver.addTrueClause(solver.getNegativeLiteral(i, k));
				else
					solver.addOrClause(solver.getNegativeLiteral(i, x), solver.getPositiveLiteral(i, x+1));
				break;
			case GEQ:
				

				

				

				

				for(int y=2; y<=x; y++) {
					if(y > k || x+1-y < 2)
						continue;
					if(x+1-y > k) {
						solver.addFalseClause(solver.getNegativeLiteral(i, y));
						solver.addFalseClause(solver.getNegativeLiteral(j, y));
					}
					else {
						solver.addIfThenClause(solver.getNegativeLiteral(i, y), solver.getPositiveLiteral(j, x+1-y));
						solver.addIfThenClause(solver.getNegativeLiteral(j, y), solver.getPositiveLiteral(i, x+1-y));
					}
				}
				break;
			case LEQ:
				

				

				

				

				for(int y=1; y<=x; y++) {
					if(y > k || x+1-y > k)
						continue;
					if(x+1-y < 1){
						solver.addFalseClause(solver.getPositiveLiteral(i, y));
						solver.addFalseClause(solver.getPositiveLiteral(j, y));
					}
					else {
						solver.addIfThenClause(solver.getPositiveLiteral(i, y), solver.getNegativeLiteral(j, x+1-y));
						solver.addIfThenClause(solver.getPositiveLiteral(j, y), solver.getNegativeLiteral(i, x+1-y));
					}
				}
				break;
			}
		}
		
		if(!solver.solve()) {
			ans = null;
			return;
		}
		
		ans = new int[n];
		for(int i=0; i<n; i++) {
			for(int x=k; x>=1; x--)
				if(solver.assignment[solver.getPositiveLiteral(i, x)] == Assignment.ASSIGNED) {
					ans[i] = x;
					break;
				}
		}
	}
	
	enum Assignment{
		ASSIGNED, NOT_ASSIGNED;
	}

	class TwoSatSolver{
		final int N;
		ArrayList<Integer>[] neighbors;
		
		public TwoSatSolver(int N) {
			this.N = N;
			neighbors = new ArrayList[N];
			for(int i=0; i<N; i++)
				neighbors[i] = new ArrayList<Integer>();
		}
		
		Assignment[] assignment;
		boolean solve() {
			var scc = new SCC().tarjan();
			int[] indexToComponent = new int[N];
			for(int i=0; i<scc.size(); i++) {
				for(int index: scc.get(i))
					indexToComponent[index] = i;
			}
			for(int i=0; i<N; i+=2)
				if(indexToComponent[i] == indexToComponent[not(i)])
					return false;
			
			assignment = new Assignment[N];
			for(int i=0; i<scc.size(); i++) {
				for(int index: scc.get(i)) {
					if(assignment[index] == null) {
						assignment[index] = Assignment.ASSIGNED;
						assignment[not(index)] = Assignment.NOT_ASSIGNED;
					}
				}
			}
			return true;
		}
		
		void addTrueClause(int literal) {
			neighbors[not(literal)].add(literal);
		}
		
		void addFalseClause(int literal) {
			neighbors[literal].add(not(literal));
		}
		
		void addOrClause(int literal1, int literal2) {
			neighbors[not(literal1)].add(literal2);
			neighbors[not(literal2)].add(literal1);
		}
		
		void addIfThenClause(int literal1, int literal2) {
			neighbors[literal1].add(literal2);
			neighbors[not(literal2)].add(not(literal1));
		}
		
		int not(int literal) {
			return literal^1;
		}
		
		int getPositiveLiteral(int index, int val) {
			val--;
			return index*k*2 + val*2;
		}
		
		int getNegativeLiteral(int index, int val) {
			val--;
			return index*k*2 + val*2 + 1;
		}
		
		class SCC{
			int[] tin;
			int[] low;
			boolean[] onStack;
			ArrayDeque<Integer> stack;
			ArrayList<ArrayList<Integer>> scc;
			int time;
			
			public SCC() {
				
			}
			
			

			public ArrayList<ArrayList<Integer>> tarjan() {
				time = 1;
				tin = new int[N];
				low = new int[N];
				onStack = new boolean[N];
				stack = new ArrayDeque<>();
				scc = new ArrayList<>();
				for(int i=0; i<N; i++)
					if(tin[i] == 0)
						dfs(i);
				return scc;
			}
			
			public void dfs(int v) {
				tin[v] = time;
				low[v] = time;
				time++;
				onStack[v] = true;
				stack.add(v);
				
				

				for(int u: neighbors[v]) {
					if(tin[u] == 0) {
						dfs(u);
						low[v] = Math.min(low[v], low[u]);
					}
					else if(onStack[u]) {
						low[v] = Math.min(low[v], tin[u]);
					}
				}
				
				if(low[v] == tin[v]) {
					ArrayList<Integer> component = new ArrayList<>();
					while(!stack.isEmpty()) {
						int u = stack.pollLast();
						onStack[u] = false;
						component.add(u);
						if(u == v)
							break;
					}
					scc.add(component);
				}
			}
		}
	}
	




	
	static class Pair implements Comparable<Pair>{
		final static long FIXED_RANDOM = System.currentTimeMillis();
		int first, second;
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
		

		@Override
		public int hashCode() {
			

			long x = first;
			x <<= 32;
			x += second;
			x += FIXED_RANDOM;
			x += 0x9e3779b97f4a7c15l;
			x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9l;
			x = (x ^ (x >> 27)) * 0x94d049bb133111ebl;
			return (int)(x ^ (x >> 31));
		}
		@Override
		public boolean equals(Object obj) {












			Pair other = (Pair) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}


		@Override
		public int compareTo(Pair o) {
			int cmp = Integer.compare(first, o.first);
			return cmp != 0? cmp: Integer.compare(second, o.second);
		}
	}
	
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		

		public MyScanner(InputStream is, int bufferSize) {
			br = new BufferedReader(new InputStreamReader(is), bufferSize);
		}
		
		public MyScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
			

			

		}

		public void close() {
			try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}

		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine(){
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		
		int[][] nextMatrix(int n, int m) {
			return nextMatrix(n, m, 0);
		}
		
		int[][] nextMatrix(int n, int m, int offset) {
			int[][] mat = new int[n][m];
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					mat[i][j] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[][] nextTransposedMatrix(int n, int m){
			return nextTransposedMatrix(n, m, 0);
		}
		
		int[][] nextTransposedMatrix(int n, int m, int offset){
			int[][] mat = new int[m][n];
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					mat[j][i] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[] nextIntArray(int len) {
			return nextIntArray(len, 0);
		}
		int[] nextIntArray(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] nextLongArray(int len) {
			return nextLongArray(len, 0);
		}
		long[] nextLongArray(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
		
		String[] nextStringArray(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
		}
	}
	
	public static class MyPrintWriter extends PrintWriter{
		public MyPrintWriter(OutputStream os) {
			super(os);
		}
		












		
		public void printlnAns(OptionalInt ans) {
			println(ans.orElse(-1));
		}
		
		public void printlnAns(long ans) {
			println(ans);
		}
		
		public void printlnAns(int ans) {
			println(ans);
		}
		
		public void printlnAns(boolean ans) {
			if(ans)
				println(YES);
			else
				println(NO);
		}
		
		public void printAns(long[] arr){
			if(arr != null && arr.length > 0){
				print(arr[0]);
				for(int i=1; i<arr.length; i++){
					print(" ");
					print(arr[i]);
				}
			}
		}
		public void printlnAns(long[] arr){
			printAns(arr);
			println();
		}

		public void printAns(int[] arr){
			if(arr != null && arr.length > 0){
				print(arr[0]);
				for(int i=1; i<arr.length; i++){
					print(" ");
					print(arr[i]);
				}
			}
		}
		public void printlnAns(int[] arr){
			printAns(arr);
			println();
		}
		
		public <T> void printAns(ArrayList<T> arr){
			if(arr != null && arr.size() > 0){
				print(arr.get(0));
				for(int i=1; i<arr.size(); i++){
					print(" ");
					print(arr.get(i));
				}
			}
		}
		public <T> void printlnAns(ArrayList<T> arr){
			printAns(arr);
			println();
		}
		
		public void printAns(int[] arr, int add){
			if(arr != null && arr.length > 0){
				print(arr[0]+add);
				for(int i=1; i<arr.length; i++){
					print(" ");
					print(arr[i]+add);
				}
			}
		}
		public void printlnAns(int[] arr, int add){
			printAns(arr, add);
			println();
		}
		
		public void printAns(ArrayList<Integer> arr, int add) {
			if(arr != null && arr.size() > 0){
				print(arr.get(0)+add);
				for(int i=1; i<arr.size(); i++){
					print(" ");
					print(arr.get(i)+add);
				}
			}			
		}
		
		public void printlnAns(ArrayList<Integer> arr, int add){
			printAns(arr, add);
			println();
		}
		
		public void printlnAnsSplit(long[] arr, int split){
			if(arr != null){
				for(int i=0; i<arr.length; i+=split){
					print(arr[i]);
					for(int j=i+1; j<i+split; j++){
						print(" ");
						print(arr[j]);
					}
					println();
				}
			}
		}
		
		public void printlnAnsSplit(int[] arr, int split){
			if(arr != null){
				for(int i=0; i<arr.length; i+=split){
					print(arr[i]);
					for(int j=i+1; j<i+split; j++){
						print(" ");
						print(arr[j]);
					}
					println();
				}
			}
		}
		
		public <T> void printlnAnsSplit(ArrayList<T> arr, int split){
			if(arr != null && !arr.isEmpty()){
				for(int i=0; i<arr.size(); i+=split){
					print(arr.get(i));
					for(int j=i+1; j<i+split; j++){
						print(" ");
						print(arr.get(j));
					}
					println();
				}
			}
		}
	}
	
	static private void permutateAndSort(long[] a) {
		int n = a.length;
		Random R = new Random(System.currentTimeMillis());
		for(int i=0; i<n; i++) {
			int t = R.nextInt(n-i);
			long temp = a[n-1-i];
			a[n-1-i] = a[t];
			a[t] = temp;
		}
		Arrays.sort(a);		
	}
	
	static private void permutateAndSort(int[] a) {
		int n = a.length;
		Random R = new Random(System.currentTimeMillis());
		for(int i=0; i<n; i++) {
			int t = R.nextInt(n-i);
			int temp = a[n-1-i];
			a[n-1-i] = a[t];
			a[t] = temp;
		}
		Arrays.sort(a);
	}
	
	static private int[][] constructChildren(int n, int[] parent, int parentRoot){
		int[][] childrens = new int[n][];
		
		int[] numChildren = new int[n];
		for(int i=0; i<parent.length; i++) {
			if(parent[i] != parentRoot)
				numChildren[parent[i]]++;
		}
		
		for(int i=0; i<n; i++) {
			childrens[i] = new int[numChildren[i]];
		}
		

		int[] idx = new int[n];
		for(int i=0; i<parent.length; i++) {
			if(parent[i] != parentRoot)
				childrens[parent[i]][idx[parent[i]]++] = i;
		}

		return childrens;
	}
	
	static private int[][][] constructDirectedNeighborhood(int n, int[][] e){
		int[] inDegree = new int[n];
		int[] outDegree = new int[n];
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			outDegree[u]++;
			inDegree[v]++;
		}
		
		int[][] inNeighbors = new int[n][];
		int[][] outNeighbors = new int[n][];
		for(int i=0; i<n; i++) {
			inNeighbors[i] = new int[inDegree[i]];
			outNeighbors[i] = new int[outDegree[i]];
		}
		
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			outNeighbors[u][--outDegree[u]] = v;
			inNeighbors[v][--inDegree[v]] = u;
		}
		
		return new int[][][] {inNeighbors, outNeighbors};
	}
	
	static private int[][] constructNeighborhood(int n, int[][] e) {
		int[] degree = new int[n];
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			degree[u]++;
			degree[v]++;
		}
		
		int[][] neighbors = new int[n][];
		for(int i=0; i<n; i++)
			neighbors[i] = new int[degree[i]];
		
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			neighbors[u][--degree[u]] = v;
			neighbors[v][--degree[v]] = u;
		}
		
		return neighbors;
	}
	
	static private void drawGraph(int[][] e) {
		makeDotUndirected(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void makeDotUndirected(int[][] e) {
		MyPrintWriter out2 = null;
		 try {
			out2 = new MyPrintWriter(new FileOutputStream("graph.dot"));
		} catch (FileNotFoundException e1) {
			

			e1.printStackTrace();
		}
		out2.println("strict graph {");
		for(int i=0; i<e.length; i++){
			out2.println(e[i][0] + "--" + e[i][1] + ";");
		}
		out2.println("}");
		out2.close();
	}
	
	static private void makeDotDirected(int[][] e) {
		MyPrintWriter out2 = null;
		 try {
			out2 = new MyPrintWriter(new FileOutputStream("graph.dot"));
		} catch (FileNotFoundException e1) {
			

			e1.printStackTrace();
		}
		out2.println("strict digraph {");
		for(int i=0; i<e.length; i++){
			out2.println(e[i][0] + "->" + e[i][1] + ";");
		}
		out2.println("}");
		out2.close();
	}
	
}