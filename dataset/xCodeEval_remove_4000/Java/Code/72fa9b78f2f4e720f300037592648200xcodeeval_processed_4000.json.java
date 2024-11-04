import java.util.*;
import java.util.function.*;
import java.io.*;



public class id2 {	
	id5 out;
	MyScanner in;
	








	final static String id10 = "id10";
	final static String id12 = "id12";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id9) {
        if (System.getProperty("ONLINE_JUDGE") == null && id9) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id5(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id5(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){


		
		id2 sol = new id2();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id9 = false;
		boolean id1 = true;
		
		initIO(id9);
	
		int t = id1? in.nextInt() : 1;
	    
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
	
	void giveAnswer(int[] id6) {
		out.print("! ");
		out.print(id6.length);
		out.print(" ");
		out.printlnAns(id6, 1);
		out.flush();
	}
	
	void solve(){
		

		

		
		

		
		

		

		

		

		

		

		
		

		

		

		
		

		

		

		

		

		

		
		

		

		

		
		
		

		

		

		

		

		
		

		

		
		

		
		

		

		

		

		

		
		

		

		

		

		
		

		
		ArrayDeque<Integer> indexTrue = new ArrayDeque<>();
		ArrayDeque<Integer> indexFalse = new ArrayDeque<>();
		
		indexCrew = new ArrayList<>();
		id4 = new ArrayList<>();
		
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
				

				

				

				

				

				

				

				id4.add(j);
				id4.add(j+1);
				id4.add(j+2);
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
					id4.add(i+2);
				}
				else if(res023) {
					indexCrew.add(i);
					indexCrew.add(i+2);
					id4.add(i+1);
				}
				else {
					indexCrew.add(i+1);
					indexCrew.add(i+2);
					id4.add(i);
				}
			}
			
			else {
				if(res001 || res002 || res012) {
					if(res001 && res002) {
						indexCrew.add(i);
						indexCrew.add(j);
						id4.add(j+1);
						id4.add(j+2);
					}
					else if(res001 && res012) {
						indexCrew.add(i);
						indexCrew.add(j+1);
						id4.add(j);
						id4.add(j+2);
					}
					else {
						if(!(res002 && res012)) {
							idleQuery();
							return;
						}
						indexCrew.add(i);
						indexCrew.add(j+2);
						id4.add(j);
						id4.add(j+1);
					}
					determine(i+1);
					determine(i+2);
				}
				else {
					if(res101 && res102) {
						indexCrew.add(i+1);
						indexCrew.add(j);
						id4.add(j+1);
						id4.add(j+2);
					}
					else if(res101 && res112) {
						indexCrew.add(i+1);
						indexCrew.add(j+1);
						id4.add(j);
						id4.add(j+2);
					}
					else {
						if(!(res102 && res112)) {
							idleQuery();
							return;
						}
						indexCrew.add(i+1);
						indexCrew.add(j+2);
						id4.add(j);
						id4.add(j+1);
					}
					determine(i);
					determine(i+2);
				}
				
			}
		}
		
		

		
		

		

		

		

		

		
		

		

		

		

		
		while(!indexTrue.isEmpty()) {
			int i = indexTrue.pollFirst();
			boolean res01 = makeQuery(i, i+1, id4.get(0));
			if(res01) {
				indexCrew.add(i);
				indexCrew.add(i+1);
				determine(i+2);
			}
			else {
				boolean res02 = makeQuery(i, i+2, id4.get(0));
				if(res02) {
					indexCrew.add(i);
					id4.add(i+1);
					indexCrew.add(i+2);
				}
				else {
					id4.add(i);
					indexCrew.add(i+1);
					indexCrew.add(i+2);
				}
			}
		}
		
		while(!indexFalse.isEmpty()) {
			int i = indexFalse.pollFirst();
			boolean res01 = makeQuery(i, i+1, indexCrew.get(0));
			if(!res01) {
				id4.add(i);
				id4.add(i+1);
				determine(i+2);
			}
			else {
				boolean res02 = makeQuery(i, i+2, indexCrew.get(0));
				if(!res02) {
					id4.add(i);
					indexCrew.add(i+1);
					id4.add(i+2);
				}
				else {
					indexCrew.add(i);
					id4.add(i+1);
					id4.add(i+2);
				}
			}
		}
		
		giveAnswer(id4.stream().mapToInt(x->x).toArray());
	}
	
	void determine(int index) {
		if(makeQuery(index, indexCrew.get(0), id4.get(0)))
			indexCrew.add(index);
		else
			id4.add(index);
	}
	
	ArrayList<Integer> indexCrew, id4;
	
	static class Pair implements Comparable<Pair>{
		final static long id7 = System.currentTimeMillis();
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
			x += id7;
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
		
		int[][] id11(int n, int m){
			return id11(n, m, 0);
		}
		
		int[][] id11(int n, int m, int offset){
			int[][] mat = new int[m][n];
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					mat[j][i] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[] id8(int len) {
			return id8(len, 0);
		}
		int[] id8(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id17(int len) {
			return id17(len, 0);
		}
		long[] id17(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
		
		String[] id15(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
		}
	}
	
	public static class id5 extends PrintWriter{
		public id5(OutputStream os) {
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
		
		public void id0(long[] arr, int split){
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
		
		public void id0(int[] arr, int split){
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
		
		public <T> void id0(ArrayList<T> arr, int split){
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
	
	static private void id16(long[] a) {
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
	
	static private void id16(int[] a) {
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
	
	static private int[][][] id14(int n, int[][] e){
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
		id13(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id13(int[][] e) {
		id5 out2 = null;
		 try {
			out2 = new id5(new FileOutputStream("graph.dot"));
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
	
	static private void id3(int[][] e) {
		id5 out2 = null;
		 try {
			out2 = new id5(new FileOutputStream("graph.dot"));
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
