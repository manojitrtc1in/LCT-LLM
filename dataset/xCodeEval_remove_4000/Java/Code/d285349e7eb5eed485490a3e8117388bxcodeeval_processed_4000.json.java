import java.util.*;
import java.util.function.*;
import java.io.*;



public class id18 {	
	id4 out;
	MyScanner in;
	








	final static String id9 = "id9";
	final static String id11 = "id11";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id8) {
        if (System.getProperty("ONLINE_JUDGE") == null && id8) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id4(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id4(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){


		
		id18 sol = new id18();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id8 = true;
		boolean id2 = true;
		
		initIO(id8);
		
		

	
		int t = id2? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	boolean[][][] d = new boolean[n][n][n];
	    	for(int j=0; j<n-1; j++)
	    		for(int k=0; k<n-j-1; k++) {
	    			String s = in.next();
	    			for(int l=0; l<n; l++) {
	    				if(s.charAt(l) == '1') {
			    			d[j+k+1][j][l] = true;
			    			d[j][j+k+1][l] = true;
	    				}
	    				else {
	    					d[j+k+1][j][l] = false;
	    					d[j][j+k+1][l] = false;
	    				}
	    			}
	    		}
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			int[][] ans = solve(d);
			if(ans == null)
				out.println(NO);
			else {
				out.println(YES);
				for(int[] e: ans)
					out.printlnAns(e, 1);
			}
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}

	private void test() {
		int n = 100;
		int[] parents = new int[n];
		int root = 0;
		parents[0] = -1;
		Random r = new Random();
		for(int i=1; i<n; i++)
			parents[i] = r.nextInt(i);
		
		boolean[][][] dd = computeDD(n, parents, root);
		
		int[][] ans = solve(dd);
		if(ans == null)
			out.println(NO);
		else {
			out.println(YES);
			for(int[] e: ans)
				out.printlnAns(e, 1);
		}
		
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				dd[i][j][0] = false;
			}
		}
		
		ans = solve(dd);
		if(ans == null)
			out.println(NO);
		else {
			out.println(YES);
			for(int[] e: ans)
				out.printlnAns(e, 1);
		}
		
		n = 15;
		parents = new int[n];
		root = 14;
		parents[root] = -1;
		for(int i=0; i<root; i++)
			parents[i] = root;
		
		dd = computeDD(n, parents, root);
		
		ans = solve(dd);
		if(ans == null)
			out.println(NO);
		else {
			out.println(YES);
			for(int[] e: ans)
				out.printlnAns(e, 1);
		}
		
		dd[0][2][3] ^= true;
		ans = solve(dd);
		if(ans == null)
			out.println(NO);
		else {
			out.println(YES);
			for(int[] e: ans)
				out.printlnAns(e, 1);
		}		
		
	}

	boolean[][][] computeDD(int n, int[] parents, int root) {
		int[] depths = new int[n];
		Arrays.fill(depths, -1);
		depths[root] = 0;
		for(int i=0; i<n; i++)
			id15(i, parents, depths);
		
		int[][] dists = new int[n][n];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				int x = i;
				int y = j;
				int dist = 0;
				while(depths[x] > depths[y]) {
					x = parents[x];
					dist++;
				}
				while(depths[y] > depths[x]) {
					y = parents[y];
					dist++;
				}
				while(x != y) {
					x = parents[x];
					y = parents[y];
					dist += 2;
				}
				dists[i][j] = dist;
			}
		}
		
		boolean[][][] dd = new boolean[n][n][n];
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				for(int k=0; k<n; k++) {
					dd[i][j][k] = (dists[i][k] == dists[j][k]);
				}
			}
		}
		return dd;
	}

	private int[][] solve(boolean[][][] d) {
		final int n = d.length;
		final int root = 0;
		
		this.d = d;
		id13 = new int[n];
		Arrays.fill(id13, -1);
		setNum = 0;
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(i != j && d[i][j][j])
					return null;
			}
		}
		
		for(int i=1; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(d[i][j][root])
					if(!id7(i, j))
						return null;
			}
			if(id13[i] == -1) {
				id13[i] = setNum++;
			}
		}
		
		

		
		

		

		

		
		

		

		

		
		

		

		

		
		sets = new HashSet[setNum];
		for(int i=0; i<setNum; i++)
			sets[i] = new HashSet<Integer>();
		
		for(int i=1; i<n; i++)
			sets[id13[i]].add(i);
		
		for(int i=0; i<setNum; i++) {
			int[][] ans = id1(root, i);
			if(ans != null)
				return ans;
		}
		
		return null;
	}
	
	boolean[][][] d;
	HashSet<Integer>[] sets;
	int[] id13;
	int setNum;
	
	private int[][] id1(int root, int childrenSet) {
		

		int n = id13.length;
		
		int[] parents = new int[n];
		Arrays.fill(parents, -1);
		parents[root] = -1;
		for(int i: sets[childrenSet])
			parents[i] = root;
		
		int curr = childrenSet;
		for(int done = 1; done < setNum; done++) {
			HashSet<Integer> currSet = sets[curr];
			int next = -1;
			for(int i: currSet) {
				for(int j=0; j<n; j++) {
					if(j == parents[i] || j==i)
						continue;
					if(d[parents[i]][j][i]) {
						if(next == -1)
							next = id13[j];
						else if(id13[j] != next)
							return null;
						

						else if(parents[j] != -1 && parents[j] != i)
							return null;
						parents[j] = i;
					}
				}
			}
			if(next == -1)
				return null;
			for(int i: sets[next])
				if(parents[i] == -1)
					return null;
			curr = next;
		}
		
		if(!isValid(root, parents))
			return null;
		
		int[][] e = new int[n-1][2];
		int idx = 0;
		for(int i=0; i<n; i++) {
			if(i == root)
				continue;
			e[idx++] = new int[] {i, parents[i]};
		}
		
		return e;
	}
	
	private boolean isValid(int root, int[] parents) {
		int n = parents.length;		
		int[] depths = new int[n];
		Arrays.fill(depths, -1);
		depths[root] = 0;
		for(int i=0; i<n; i++)
			id15(i, parents, depths);
		int[][] dists = new int[n][n];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				int x = i;
				int y = j;
				int dist = 0;
				while(depths[x] > depths[y]) {
					x = parents[x];
					dist++;
				}
				while(depths[y] > depths[x]) {
					y = parents[y];
					dist++;
				}
				while(x != y) {
					x = parents[x];
					y = parents[y];
					dist += 2;
				}
				dists[i][j] = dist;
			}
		}
		
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				for(int k=0; k<n; k++) {
					if(d[i][j][k] != (dists[i][k] == dists[j][k]))
						return false;
				}
			}
		}
		
		return true;
	}

	private int id15(int curr, int[] parents, int[] depths) {
		if(depths[curr] != -1)
			return depths[curr];
		depths[curr] = id15(parents[curr], parents, depths)+1;
		return depths[curr];
	}

	private boolean id7(int i, int j) {
		if(id13[j] == -1 && id13[i] == -1) {
			id13[i] = setNum++;
			id13[j] = id13[i];
		}
		else if(id13[j] == -1) {
			id13[j] = id13[i];
		}
		else if(id13[i] == -1) {
			id13[i] = id13[j];
		}
		else if(id13[i] != id13[j])
			return false;
		return true;
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
		
		int[][] id5(int n, int offset){
			int[][] e = new int[n-1][2];
			for(int i=0; i<n-1; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;			
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
		
		int[][] nextPairs(int n){
			return nextPairs(n, 0);
		}
		
		int[][] nextPairs(int n, int offset) {
			int[][] xy = new int[2][n];
			for(int i=0; i<n; i++) {
				xy[0][i] = nextInt() + offset;
				xy[1][i] = nextInt() + offset;
			}
			return xy;
		}

		int[][] id10(){
			return id10(0);
		}
		
		int[][] id10(int offset) {
			int m = nextInt();
			int[][] e = new int[m][2];
			for(int i=0; i<m; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;
		}
		
		int[] id6(int len) {
			return id6(len, 0);
		}
		int[] id6(int len, int offset){
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
	}
	
	public static class id4 extends PrintWriter{
		public id4(OutputStream os) {
			super(os);
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
		
		int[] inIdx = new int[n];
		int[] outIdx = new int[n];
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			outNeighbors[u][outIdx[u]++] = v;
			inNeighbors[v][inIdx[v]++] = u;
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
		
		int[] idx = new int[n];
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			neighbors[u][idx[u]++] = v;
			neighbors[v][idx[v]++] = u;
		}
		
		return neighbors;
	}
	
	static private void drawGraph(int[][] e) {
		id12(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id12(int[][] e) {
		id4 out2 = null;
		 try {
			out2 = new id4(new FileOutputStream("graph.dot"));
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
		id4 out2 = null;
		 try {
			out2 = new id4(new FileOutputStream("graph.dot"));
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
