import java.util.*;
import java.util.function.*;
import java.io.*;



public class id18 {	
	id10 out;
	MyScanner in;
	








	final static String id14 = "id14";
	final static String id16 = "id16";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id13) {
        if (System.getProperty("ONLINE_JUDGE") == null && id13) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id10(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id10(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){



		

		

		

		

		
		id18 sol = new id18();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id13 = true;
		boolean id5 = true;
		
		initIO(id13);
		


	
		int t = id5? in.nextInt() : 1;
	    
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
	
	

	int n;
	int[] a;
	void getInput() {
		n = in.nextInt();
		a = in.id12(n);
	}
	
	void printOutput() {
		out.printlnAns(ans);
	}
	
	static class id28 implements Iterable<Integer>{
		int[] data;
		int capacity;
		int size;
		public id28() {
			capacity = 3;
			data = new int[capacity];
			size = 0;
		}
		public void add(int val) {
			if(size == capacity) {
				capacity *= 2;
				data = Arrays.copyOf(data, capacity);
			}
			data[size++] = val;
		}
		public int pop() {
			return data[--size];
		}
		public int size() {
			return size;
		}
		public int get(int index) {
			return data[index];
		}
		public int front() {
			return data[0];
		}
		public int back() {
			return data[size-1];
		}
		public int binarySearch(int val) {
			return Arrays.binarySearch(data, 0, size, val);
		}
		public String toString() {
			return Arrays.toString(Arrays.copyOf(data, size));
		}
		@Override
		public Iterator<Integer> iterator() {
			return new id0();
		}
		
		class id0 implements Iterator<Integer> {
			private int index = 0;
	        public boolean hasNext() {
	            return index < size;
	        }
	        public Integer next() {
	        	return data[index++];
	        }
	        public void remove() {
	        	throw new UnsupportedOperationException();
	        }
		}
	}

	long ans;
	final int MAX = 1_000_000;
	id28[] id25 = new id28[MAX+1];
	id28[] id26 = new id28[MAX+1];
	


















	void solve(){
		

		

		

		
		

		

		

		

		

		

		

		
		

		

		

		

		
		for(int i=0; i<n; i++){
			int val = a[i];
			if(id25[val] == null)
				id25[val] = new id28();
			id25[val].add(i);
		}
		
		for(int val=1; val<=MAX; val++) {
			if(id25[val] != null)
				id26[val] = new id28();
		}
		for(int val=1; val<=MAX; val++) {
			if(id25[val] != null) {
				for(int multiple=val*2; multiple<=MAX; multiple+=val) {
					if(id25[multiple] != null)
						id26[multiple].add(val);
				}
			}
		}
		
		int[] id4 = new int[n];
		for(int i=n-1; i>=0; i--) {
			int next = i+1;
			while(next < n && a[next] >= a[i])
				next = id4[next];
			id4[i] = next;
		}
		
		int[] id6 = new int[n];
		for(int i=0; i<n; i++) {
			int prev = i-1;
			while(prev >= 0 && a[prev] >= a[i])
				prev = id6[prev];
			id6[i] = prev;
		}
		
		int[] id24 = new int[n];
		for(int i=n-1; i>=0; i--) {
			int next = i+1;
			while(next < n && a[next] <= a[i])
				next = id24[next];
			id24[i] = next;
		}
		
		int[] id22 = new int[n];
		for(int i=0; i<n; i++) {
			int prev = i-1;
			while(prev >=0 && a[prev] <= a[i])
				prev = id22[prev];
			id22[i] = prev;
		}

		ans = 0;
		int[] pos = new int[MAX+1];
		boolean[] visited = new boolean[n];
		for(int i=0; i<n; i++) {
			int max = a[i];
			if(!visited[i]) {
				long len = 0;
				for(int j=i; j<n && a[i] == a[j]; j++, len++)
					visited[j] = true;
				ans += len*(len+1)/2;	
			}


			for(int j=0; j<id26[max].size; j++) {
				int min = id26[max].data[j];




				int curr = i;
				int lFrom = id22[curr]+1;
				int lTo = curr;
				int rFrom = curr;
				int rTo = id24[curr]-1;
				{
					while(pos[max] < id25[max].size() && id25[max].get(pos[max]) < curr)
						pos[max]++;
					

					int index = pos[max];
					if(index > 0)
						lFrom = Math.max(lFrom, id25[max].get(index-1)+1);
				}
				while(pos[min] < id25[min].size() && id25[min].get(pos[min]) <= curr)
					pos[min]++;
				

				

				int find = pos[min];
				int prevMin, nextMin;
				if(find == 0)
					prevMin = -1;
				else
					prevMin = id25[min].get(find-1);
				if(find == id25[min].size())
					nextMin = n;
				else
					nextMin = id25[min].get(find);
				if(prevMin == -1){
					rFrom = nextMin;
					rTo = Math.min(rTo, id4[nextMin]-1);
					lFrom = Math.max(lFrom, id6[nextMin]+1);
					if(lFrom <= lTo && rFrom <= rTo)
						ans += (long)(lTo-lFrom+1)*(rTo-rFrom+1);
				}
				else if(nextMin == n) {
					lTo = prevMin;
					lFrom = Math.max(lFrom, id6[prevMin]+1);
					rTo = Math.min(rTo, id4[prevMin]-1);
					if(lFrom <= lTo && rFrom <= rTo)
						ans += (long)(lTo-lFrom+1)*(rTo-rFrom+1);
				}
				else {
					

					
					

					int id20 = nextMin;
					int id3 = Math.min(rTo, id4[nextMin]-1);
					int id1 = Math.max(lFrom, id6[nextMin]+1);
					id1 = Math.max(id1, prevMin+1);
					int id27 = lTo;
					if(id1 <= id27 && id20 <= id3)
						ans += (long)(id27-id1+1)*(id3-id20+1);
					
					

					int id8 = prevMin;
					int id17 = Math.max(lFrom, id6[prevMin]+1);
					int id23 = Math.min(rTo, id4[prevMin]-1);
					id23 = Math.min(id23, nextMin-1);
					int id9 = rFrom;
					if(id17 <= id8 && id9 <= id23)
						ans += (long)(id8-id17+1)*(id23-id9+1);
					
					

					if(id4[prevMin] > curr && id6[nextMin] < curr) {
						lFrom = Math.max(lFrom, id6[prevMin]+1);
						lTo = Math.min(lTo, prevMin);
						rTo = Math.min(rTo, id4[nextMin]-1);
						rFrom = Math.max(rFrom, nextMin);
						if(lFrom <= lTo && rFrom <= rTo)
							ans += (long)(lTo-lFrom+1)*(rTo-rFrom+1);
					}
				}
			}
		}










































































































































































		
		for(int i=0; i<n; i++)
			id25[a[i]] = null;
		
	}
	 




	
	static class Pair implements Comparable<Pair>{
		final static long id11 = System.currentTimeMillis();
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
			x += id11;
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
		
		int[][] id15(int n, int m){
			return id15(n, m, 0);
		}
		
		int[][] id15(int n, int m, int offset){
			int[][] mat = new int[m][n];
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					mat[j][i] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[] id12(int len) {
			return id12(len, 0);
		}
		int[] id12(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id31(int len) {
			return id31(len, 0);
		}
		long[] id31(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
		
		String[] id29(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
		}
	}
	
	public static class id10 extends PrintWriter{
		public id10(OutputStream os) {
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
		
		public void printlnAns(boolean[] ans) {
			for(boolean b: ans)
				printlnAns(b);
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
		
		public void id2(long[] arr, int split){
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
		
		public void id2(int[] arr, int split){
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
		
		public <T> void id2(ArrayList<T> arr, int split){
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
	
	static private void id30(long[] a) {
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
	
	static private void id30(int[] a) {
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
	
	static private int[][][] id21(int n, int[][] e){
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
		id19(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id19(int[][] e) {
		id10 out2 = null;
		 try {
			out2 = new id10(new FileOutputStream("graph.dot"));
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
	
	static private void id7(int[][] e) {
		id10 out2 = null;
		 try {
			out2 = new id10(new FileOutputStream("graph.dot"));
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
