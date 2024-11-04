import java.util.*;
import java.util.function.*;
import java.io.*;



public class id4 {	
	id5 out;
	MyScanner in;
	








	final static String id10 = "id10";
	final static String id12 = "id12";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id8) {
        if (System.getProperty("ONLINE_JUDGE") == null && id8) {
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



		

		

		

		

		
		id4 sol = new id4();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id8 = true;
		boolean id1 = true;
		
		initIO(id8);
		
		

	
		int t = id1? in.nextInt() : 1;
	    
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
	
	void test() {
		Random rand = new Random();
		n = 50;
		m = 10;
		final int MAX = 5;
		for(int t=0; t<1000; t++) {
			a = new int[n];
			b = new int[m];
			for(int i=0; i<n; i++)
				a[i] = rand.nextInt(MAX)+1;
			for(int i=0; i<m; i++)
				b[i] = rand.nextInt(MAX)+1;
			long expected = 0;
			for(int i=0; i<n; i++)
				for(int j=i+1; j<n; j++)
					if(a[i] > a[j])
						expected++;
			for(int i=0; i<m; i++) {
				int curr = 0;
				for(int j=0; j<n; j++)
					if(a[j] < b[i])
						curr++;
				int best = curr;
				for(int j=0; j<=n; j++) {
					if(curr < best)
						best = curr;
					if(j < n) {
						if(a[j] > b[i])
							curr++;
						if(a[j] < b[i])
							curr--;
					}
				}
				expected += best;
			}
			solve();
			if(expected != ans) {
				solve();
			}
		}
	}
	
	

	int n, m;
	int[] a, b;
	void getInput() {
		n = in.nextInt();
		m = in.nextInt();
		a = in.id7(n);
		b = in.id7(m);
		




















	}
	
	void printOutput() {
		out.printlnAns(ans);
	}

	long ans;
	void solve(){
		

		id17(b); 


		

		

		

		
		

		

		
		

		

		
		

		












		


		
		pos = new int[m];
		computePos(0, n, 0, m);
		






























		
		ans = 0;
		id18 tree = new id18();
		int currPos = 0;
		for(int j=0; j<m; j++) {
			while(currPos < pos[j]) {
				tree.insert(a[currPos]);
				ans += tree.id15(a[currPos]);
				currPos++;
			}
			tree.insert(b[j]);
			ans += tree.id15(b[j]);
		}
		while(currPos < n) {
			tree.insert(a[currPos]);
			ans += tree.id15(a[currPos]);
			currPos++;
		}
	}
	
	int[] pos;
	void computePos(int aStart, int aEnd, int bStart, int bEnd) {
		if(bEnd <= bStart)
			return;
		
		int mid = (bStart + bEnd)/2;
		int curr = 0;
		for(int i=aStart; i<aEnd; i++)
			if(a[i] < b[mid])
				curr++;
		
		int best = n+1;
		for(int i=aStart; i<=aEnd; i++) {
			if(curr < best) {
				best = curr;
				pos[mid] = i;
			}
			if(i < n) {
				if(a[i] > b[mid])
					curr++;
				if(a[i] < b[mid])
					curr--;
			}
		}
		computePos(aStart, pos[mid], bStart, mid);
		computePos(pos[mid], aEnd, mid+1, bEnd);
	}
	
	

	long rec(int aStart, int aEnd, int bStart, int bEnd) {
		if(bEnd <= bStart)
			return 0;
		if(aEnd <= aStart)
			return 0;
		
		id18 left = new id18();
		id18 right = new id18();
		for(int i=aStart; i<aEnd; i++)
			right.insert(a[i]);
		
		int bestPos = -1;
		int best = n;
		int mid = (bStart + bEnd)/2;
		
		for(int i=aStart; i<=aEnd; i++) {
			int curr = left.id15(b[mid]);
			curr += right.id3(b[mid]);
			if(curr < best) {
				best = curr;
				bestPos = i;
			}
			if(i < n) {
				left.insert(a[i]);
				right.remove(a[i]);
			}
		}
		long res = best;
		left = new id18();
		right = new id18();
		for(int i=aStart; i<bestPos; i++)
			left.insert(a[i]);
		for(int i=bestPos; i<aEnd; i++)
			right.insert(a[i]);
		for(int j=bStart; j<mid; j++)
			res += right.id3(b[j]);
		for(int j=mid+1; j<bEnd; j++)
			res += left.id15(b[j]);
		res += rec(aStart, bestPos, bStart, mid);
		res += rec(bestPos, aEnd, mid+1, bEnd);
		return res;
	}
	
	static class id18{
		class Node{
			int key;
			int multitude;
			int id9;
			Node left, right;
			public Node(int key) {
				this.key = key;
				this.id9 = 1;
				this.multitude = 1;
				left = null;
				right = null;
			}
			public Node(int key, Node left, Node right) {
				this.key = key;
				this.id9 = 1 + getSize(left) + getSize(right);
				this.multitude = 1;
				this.left = left;
				this.right = right;
			}
			public void assignRight(Node right) {
				id9 -= getSize(this.right);
				this.right = right;
				id9 += getSize(right);
			}
			public void assignLeft(Node left) {
				id9 -= getSize(this.left);
				this.left = left;
				id9 += getSize(left);
			}
		}
		private int getSize(Node curr){
			if(curr == null)
				return 0;
			else
				return curr.id9;
		}

		public id18() {
			root = null;
			dummy = new Node(0);
		}
	    Node find(int key) {
	    	if(root == null)
	    		return null;
	        root = splay(root, key);
	        if (root.key == key)
	            return root;
	        else
	            return null;
	    }

		public int id15(int key) {
			if(root == null)
				return 0;
			root = splay(root, key);
			if(root.key > key)
				return getSize(root) - getSize(root.left);
			else
				

				return getSize(root.right);
		}
		public int id3(int key) {
			if(root == null)
				return 0;
			root = splay(root, key);
			if(root.key < key)
				return getSize(root) - getSize(root.right);
			else
				

				return getSize(root.left);
		}
	    
	    void insert(int key) {
	        if (root == null) {
	            root = new Node(key);
	        }
	        else {
	            root = splay(root, key);
	            if (root.key == key) {
	            	root.multitude++;
	            	root.id9++;
	            }
	            else {
		            NodePair temp = split(root, key);
		            root = new Node(key, temp.first, temp.second);
	            }
	        }
	    }
	    void remove(int key) {
	    	if(root == null)
	    		return;
	        root = splay(root, key);
	        if (root.key != key)
	        	return;
	        if(root.multitude > 1) {
	        	root.multitude--;
	        	root.id9--;
	        }




	        else {
	        	Node left = root.left;
	        	Node right = root.right;
	        	if(right == null)
	        		root = left;
	        	else {
	        		root = root.right;
	        		root.id9 += getSize(left);
	        		Node next = root;
	        		while(next.left != null) {
		    			next = next.left;
		    			next.id9 += getSize(left);
	        		}
	        		next.left = left;
	        	}
	        }
	    }
		
		class NodePair{
			Node first, second;
			public NodePair(Node first, Node second) {
				this.first = first;
				this.second = second;
			}
		}
		Node root, dummy;
		Node splay(Node curr, int key) {
			Node l = dummy;
			Node r = dummy;
			dummy.left = null;
			dummy.right = null;
			int lSize = 0;
			int rSize = 0;
			
			while(true) {
	            if (key < curr.key) {
	                if (curr.left == null)
	                    break;
	                if (key < curr.left.key) {
	                	

	                	Node next = curr.left;
	                	curr.assignLeft(next.right);
	                	next.assignRight(curr);
	                	curr = next;
	                    if (curr.left == null)
	                        break;
	                }
	                

	                r.left = curr;
	                r = curr;
	                curr = curr.left;
	                rSize += r.multitude + getSize(r.right);
	            }
	            else if(key > curr.key) {
	            	if(curr.right == null)
	            		break;
	            	if(key > curr.right.key) {
	            		

	            		Node next = curr.right;
	            		curr.assignRight(next.left);
	            		next.assignLeft(curr);
	            		curr = next;
	            		if(curr.right == null)
	            			break;
	            	}
	            	

	                l.right = curr;
	                l = curr;
	                curr = curr.right;
	                lSize += l.multitude + getSize(l.left);
	            }
	            else
	                break;
	        }
			curr.id9 += lSize + rSize;
			lSize += getSize(curr.left);
			rSize += getSize(curr.right);
			
			l.right = null;
			r.left = null;
			
			for(Node next = dummy.right; next != null; next = next.right) {
				next.id9 = lSize;
				lSize -= next.multitude + getSize(next.left);
			}
			
			for(Node next = dummy.left; next != null; next = next.left) {
				next.id9 = rSize;
				rSize -= next.multitude + getSize(next.right);
			}
			
			

			l.right = curr.left;
			r.left = curr.right;
			curr.left = dummy.right;
			curr.right = dummy.left;
			return curr;
		}














































































































































































































































		
	    

	    

	    NodePair split(Node root, int key) {
	        

	        

	        if (root.key <= key) {
	        	NodePair ret = new NodePair(root, root.right);
	        	

	        	root.assignRight(null);
	            return ret;
	        }
	        else {
	        	NodePair ret = new NodePair(root.left, root);
	            

	        	root.assignLeft(null);
	            return ret;
	        }
	    }
	}
	 




	
	static class Pair implements Comparable<Pair>{
		final static long id6 = System.currentTimeMillis();
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
			x += id6;
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
		
		int[] id7(int len) {
			return id7(len, 0);
		}
		int[] id7(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id19(int len) {
			return id19(len, 0);
		}
		long[] id19(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
		
		String[] id16(int len) {
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
	
	static private void id17(long[] a) {
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
	
	static private void id17(int[] a) {
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
	
	static private void id2(int[][] e) {
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
