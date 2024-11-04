import java.util.*;
import java.io.*;



public class id16 {
	id2 out;
	MyScanner in;
	
	final static String id6 = "id6";
	final static String id8 = "id8";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void id15(boolean id5) {
        if (System.getProperty("ONLINE_JUDGE") == null && id5) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id2(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id2(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){


		
		id16 sol = new id16();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id5 = true;
		
		id15(id5);
		
	    int t = in.nextInt();
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt(); 

	    	String s = in.next();
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
		    	out.println(s);
	    	}
	    	
			int[] ans = solve3(s);
			out.println(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	int[] solve3(String s) {
		boolean id3 = false;
		boolean id10 = false;
		int n = s.length();
		char[] ss = s.toCharArray();
		
		int numOp = 0;
		int numPieces = 0;
		for(int i=0; i<n; i+= 2) {
			if(ss[i] == ss[i+1]) {
				if(ss[i] == '0' && !id3)
					numPieces++;
				else if(ss[i] == '1' && !id10)
					numPieces++;
				if(ss[i] == '0') {
					id3 = true;
					id10 = false;
				}
				else {
					id3 = false;
					id10 = true;
				}
			}
			else {
				numOp++; 

				

			}
		}
		if(numPieces == 0)
			numPieces++;
		return new int[] {numOp, numPieces};
	}
	
	

	int[] solve2(String s) {
		int n = s.length();
		char[] ss = s.toCharArray();
		
		int numOp = 0;
		int numPieces = 0;
		ArrayList<Integer> chain = new ArrayList<>();
		
		boolean isFirst = true;
		boolean id11 = false;
		for(int i=0; i<n; i++) {
			int len = 1;
			while(i+len<n && ss[i] == ss[i+len])
				len++;
			i=i+len-1;
			

			boolean isEven = (len&1) == 0;
			if( !isEven && chain.size() == 0)
				chain.add(len);
			else if( isEven && chain.size() == 0) {
				if(!id11)
					numPieces++;
				else
					id11 = false;
				isFirst = false;
			}
			else if( isEven)
				chain.add(len);
			else {
				chain.add(len);
				int left = 0;
				int right = chain.size()-1;
				boolean id12 = false;
				while(left < right) {
					if(right-left+1 > 3) {
						if(chain.get(right) == 1) {
							numOp++;
							chain.set(right, 0);
							chain.set(right-1, chain.get(right-1)+1);
							if(right == chain.size()-1)
								id12 = true;
							right--;
						}
						else if(chain.get(right-1) == 2) {
							numOp+=2;
							chain.set(right, chain.get(right)+1);
							chain.set(right-1, 0);
							chain.set(right-2, chain.get(right-2)+1);
							right -= 2;
						}
						else {
							numOp++;
							numPieces++;
							chain.set(right, chain.get(right)-1);
							chain.set(right-1, chain.get(right-1)+1);
							right--;
						}
					}
					else if(right-left+1 == 3) {
						if(id11) {
							if(chain.get(left+1) == 2) {
								numOp += 2;
								chain.set(left, chain.get(left)+1);
								chain.set(left+1, 0);
								chain.set(right, chain.get(right)+1);
							}
							else if(chain.get(right) == 1) {
								numOp += 2;
								numPieces++;
								chain.set(left, chain.get(left)-1);
								chain.set(left+1, chain.get(left+1)+2);
								chain.set(right, 0);
								if(right == chain.size()-1)
									id12 = true;
							}
							else {
								numOp += 2;
								numPieces += 2;
								chain.set(left, chain.get(left)-1);
								chain.set(left+1, chain.get(left+1)+2);
								chain.set(right, chain.get(right)-1);								
							}
						}
						else {
							if(chain.get(right) == 1) {
								numOp += 2;
								numPieces++;
								numPieces += chain.get(left) == 1? 0:1;
								chain.set(left, chain.get(left)-1);
								chain.set(left+1, chain.get(left+1)+2);
								chain.set(right, 0);
								if(right == chain.size()-1)
									id12 = true;
							}
							else if(chain.get(left+1) == 2) {
								numOp += 2;
								numPieces++;
								chain.set(left, chain.get(left)+1);
								chain.set(left+1, 0);
								chain.set(right, chain.get(right)+1);					
							}
							else {
								numOp += 2;
								numPieces += 2;
								numPieces += chain.get(left) == 1? 0:1;
								chain.set(left, chain.get(left)-1);
								chain.set(left+1, chain.get(left+1)+2);
								chain.set(right, chain.get(right)-1);

							}
						}
						break;
					}
					else {
						if(id11) {
							if(chain.get(right) == 1) {
								numOp++;
								chain.set(left, chain.get(left)+1);
								chain.set(right, 0);
								if(right == chain.size()-1)
									id12 = true;
							}
							else {
								numOp++;
								numPieces++;
								chain.set(left, chain.get(left)+1);
								chain.set(right, chain.get(right)-1);
							}
						}
						else {
							if(chain.get(left) == 1 && !isFirst) {
								numOp++;
								chain.set(left, 0);
								chain.set(right, chain.get(right)+1);							
							}
							else if(chain.get(right) == 1) {
								numOp++;
								numPieces++;
								chain.set(left, chain.get(left)+1);
								chain.set(right, 0);
								if(right == chain.size()-1)
									id12 = true;
							}
							else if(chain.get(left) == 1) { 

								numOp++;
								numPieces++;
								chain.set(left, 0);
								chain.set(right, chain.get(right)+1);								
							}
							else {
								numOp++;
								numPieces += 2;
								chain.set(left, chain.get(left)+1);
								chain.set(right, chain.get(right)-1);
							}
						}
						break;
					}
				}
				chain.clear();
				id11 = id12;
				isFirst = false;
				

				

				

				

				

				

				
				
				

				

				
			}
		}
		return new int[] {numOp, numPieces};
		
	}

	private int[] solve(String s) {
		

		

		

		

		
		

		

		
		

		
		

		

		

		
		

		

		
		

		

		

		
		

		

		
		int n = s.length();
		int numOp = 0;
		boolean id1 = true;
		char[] ss = s.toCharArray();
		ArrayList<Integer> chain = new ArrayList<>();
		for(int i=0; i<n; i++) {
			int left = i;
			while(i+1 < n && ss[i] == ss[i+1]) {
				i++;
			}
			int right = i;
			int len = right-left+1;
			boolean id13 = (len & 1) == 0;
			if(id1 && id13) {
				continue;
			}
			else if(id1 && !id13) {
				if(len == 1) {
					flip(ss, left);
					numOp++;
					i--;
				}
				else {
					id1 = false;
				}
				
			}
			else if(!id1 && id13) {
				if(len == 2) {
					flip(ss, left);
					flip(ss, right);
					numOp += 2;
					i = right-1;
					id1 = true;
				}
				else {
					flip(ss, left);
					numOp ++;
					id1 = false;
				}
			}
			else {
				if(len == 1) {
					flip(ss, left);
					numOp++;
					i-=2;
					id1 = true;
				}
				else {
					flip(ss, left);
					numOp++;
					id1 = true;
				}
				
				













































			}
		}
		


		int numPieces = 0;
		for(int i=0; i<n; i++) {
			numPieces++;
			while(i+1 < n && ss[i] == ss[i+1]) {
				i++;
			}
		}
		
		
		return new int[] {numOp, numPieces};
	}
	
	private void flip(char[] s, int i) {
		if(s[i] == '0')
			s[i] = '1';
		else
			s[i] = '0';
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
		
		int[][] id7(){
			return id7(0);
		}
		int[][] id7(int offset) {
			int m = nextInt();
			int[][] e = new int[m][2];
			for(int i=0; i<m; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;
		}
		
		int[] id4(int len) {
			return id4(len, 0);
		}
		int[] id4(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id14(int len) {
			return id14(len, 0);
		}
		long[] id14(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
	}
	
	public static class id2 extends PrintWriter{
		public id2(OutputStream os) {
			super(os);
		}
		
		public void print(long[] arr){
			if(arr != null && arr.length > 0){
				print(arr[0]);
				for(int i=1; i<arr.length; i++){
					print(" ");
					print(arr[i]);
				}
			}
		}
		public void println(long[] arr){
			print(arr);
			println();
		}

		public void print(int[] arr){
			if(arr != null && arr.length > 0){
				print(arr[0]);
				for(int i=1; i<arr.length; i++){
					print(" ");
					print(arr[i]);
				}
			}
		}
		public void println(int[] arr){
			print(arr);
			println();
		}
		
		public <T> void print(ArrayList<T> arr){
			if(arr != null && arr.size() > 0){
				print(arr.get(0));
				for(int i=1; i<arr.size(); i++){
					print(" ");
					print(arr.get(i));
				}
			}
		}
		public <T> void println(ArrayList<T> arr){
			print(arr);
			println();
		}
		
		public void println(int[] arr, int split){
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
		
		public <T> void println(ArrayList<T> arr, int split){
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
	
	static private void id9(int[][] e) {
		id2 out2 = null;
		 try {
			out2 = new id2(new FileOutputStream("graph.dot"));
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
	
	static private void id0(int[][] e) {
		id2 out2 = null;
		 try {
			out2 = new id2(new FileOutputStream("graph.dot"));
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
