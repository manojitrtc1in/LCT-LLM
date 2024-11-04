import java.util.*;
import java.util.function.*;
import java.io.*;



public class Round761D {	
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
	
	public static void main(String[] args){


		
		Round761D sol = new Round761D();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean isFileIO = false;
		boolean hasMultipleTests = true;
		
		initIO(isFileIO);
	
		int t = hasMultipleTests? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}

	    	getInput();

	    	solve();
	    }
	    
	    in.close();
	    out.close();
	}
	
	

	int n;
	void getInput() {
		n = in.nextInt(); 
	}
	
	void idleQuery() {
		out.print("? ");
		out.print(1);
		out.print(" ");
		out.print(2);
		out.print(" ");
		out.println(3);
		out.flush();
	}
	
	

	boolean makeQuery(int a, int b, int c) {
		a++; b++; c++;
		out.print("? ");
		out.print(a);
		out.print(" ");
		out.print(b);
		out.print(" ");
		out.println(c);
		out.flush();
		int res = in.nextInt();
		return res==1;
	}
	
	void giveAnswer(int[] impostors) {
		out.print("! ");
		out.print(impostors.length);
		out.print(" ");
		out.printlnAns(impostors, 1);
		out.flush();
	}
	
	void solve(){
		

		

		
		

		
		

		

		

		

		

		

		
		

		

		

		
		

		

		

		

		

		

		
		

		

		

		
		
		

		

		

		

		

		
		

		

		
		

		
		

		

		

		

		

		
		

		

		

		

		
		

		
		ArrayDeque<Integer> indexTrue = new ArrayDeque<>();
		ArrayDeque<Integer> indexFalse = new ArrayDeque<>();
		
		indexCrew = new ArrayList<>();
		indexImpostor = new ArrayList<>();
		
		for(int i=0; i<n; i+=3) {
			if(makeQuery(i, i+1, i+2))
				indexTrue.add(i);
			else
				indexFalse.add(i);
		}
		
		{
			
			

			

			

			int i = indexTrue.pollFirst();
			int j = indexFalse.pollFirst();

			boolean res001, res002, res012, res101, res102, res112;
			
			res001 = makeQuery(i, j, j+1);
			res002 = makeQuery(i, j, j+2);
			res012 = makeQuery(i, j+1, j+2);
			res101 = makeQuery(i+1, j, j+1);
			res102 = makeQuery(i+1, j, j+2);
			res112 = makeQuery(i+1, j+1, j+2);
			
			

			

			

			

			

			

			
			

			

			

			
			if(!res001 && !res002 && !res012 && !res101 && !res102 && !res112) {
				

				

				

				

				

				

				

				indexImpostor.add(j);
				indexImpostor.add(j+1);
				indexImpostor.add(j+2);
				boolean res013, res023, res123;
				res013 = makeQuery(i, i+1, j);
				res023 = makeQuery(i, i+2, j);
				res123 = makeQuery(i+1, i+2, j);
				if(res013 && res023 && res123) {
					indexCrew.add(i);
					indexCrew.add(i+1);
					indexCrew.add(i+2);
				}
				else if(res013) {
					indexCrew.add(i);
					indexCrew.add(i+1);
					indexImpostor.add(i+2);
				}
				else if(res023) {
					indexCrew.add(i);
					indexCrew.add(i+2);
					indexImpostor.add(i+1);
				}
				else {
					indexCrew.add(i+1);
					indexCrew.add(i+2);
					indexImpostor.add(i);
				}
			}
			
			else {
				if(res001 || res002 || res012) {
					if(res001 && res002) {
						indexCrew.add(i);
						indexCrew.add(j);
						indexImpostor.add(j+1);
						indexImpostor.add(j+2);
					}
					else if(res001 && res012) {
						indexCrew.add(i);
						indexCrew.add(j+1);
						indexImpostor.add(j);
						indexImpostor.add(j+2);
					}
					else {
						if(!(res002 && res012)) {
							idleQuery();
							return;
						}
						indexCrew.add(i);
						indexCrew.add(j+2);
						indexImpostor.add(j);
						indexImpostor.add(j+1);
					}
					determine(i+1);
					determine(i+2);
				}
				else {
					if(res101 && res102) {
						indexCrew.add(i+1);
						indexCrew.add(j);
						indexImpostor.add(j+1);
						indexImpostor.add(j+2);
					}
					else if(res101 && res112) {
						indexCrew.add(i+1);
						indexCrew.add(j+1);
						indexImpostor.add(j);
						indexImpostor.add(j+2);
					}
					else {
						if(!(res102 && res112)) {
							idleQuery();
							return;
						}
						indexCrew.add(i+1);
						indexCrew.add(j+2);
						indexImpostor.add(j);
						indexImpostor.add(j+1);
					}
					determine(i);
					determine(i+2);
				}
				
			}
		}
		
		

		
		

		

		

		

		

		
		

		

		

		

		
		while(!indexTrue.isEmpty()) {
			int i = indexTrue.pollFirst();
			boolean res01 = makeQuery(i, i+1, indexImpostor.get(0));
			if(res01) {
				indexCrew.add(i);
				indexCrew.add(i+1);
				determine(i+2);
			}
			else {
				boolean res02 = makeQuery(i, i+2, indexImpostor.get(0));
				if(res02) {
					indexCrew.add(i);
					indexImpostor.add(i+1);
					indexCrew.add(i+2);
				}
				else {
					indexImpostor.add(i);
					indexCrew.add(i+1);
					indexCrew.add(i+2);
				}
			}
		}
		
		while(!indexFalse.isEmpty()) {
			int i = indexFalse.pollFirst();
			boolean res01 = makeQuery(i, i+1, indexCrew.get(0));
			if(!res01) {
				indexImpostor.add(i);
				indexImpostor.add(i+1);
				determine(i+2);
			}
			else {
				boolean res02 = makeQuery(i, i+2, indexCrew.get(0));
				if(!res02) {
					indexImpostor.add(i);
					indexCrew.add(i+1);
					indexImpostor.add(i+2);
				}
				else {
					indexCrew.add(i);
					indexImpostor.add(i+1);
					indexImpostor.add(i+2);
				}
			}
		}
		
		giveAnswer(indexImpostor.stream().mapToInt(x->x).toArray());
	}
	
	void determine(int index) {
		if(makeQuery(index, indexCrew.get(0), indexImpostor.get(0)))
			indexCrew.add(index);
		else
			indexImpostor.add(index);
	}
	
	ArrayList<Integer> indexCrew, indexImpostor;
	
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
