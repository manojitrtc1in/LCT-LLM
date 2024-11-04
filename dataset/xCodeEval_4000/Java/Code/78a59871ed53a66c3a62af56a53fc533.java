import java.util.*;
import java.io.*;





public class Round791E {
	public static MyPrintWriter out;
	public static MyScanner in;
	
	final static String IMPOSSIBLE = "IMPOSSIBLE";
	final static String POSSIBLE = "POSSIBLE";
	final static String YES = "YES";
	final static String NO = "NO";
	final static int MOD = 998244353;
	final static int M = 17;
	final static int EXTRACT = (1 << M) -1;
	
    private static void preferFileIO(boolean isFileIO) {
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


		
		boolean isDebug = false;
		boolean isFileIO = true;
		
		preferFileIO(isFileIO);
		








		
		
		Round791E sol = new Round791E();
		
		int n = in.nextInt();
    	String s = in.next();
    	
    	sol.preprocess(s);
    	
    	int q = in.nextInt();
    	
    	for(int i=0; i<q; i++){
    		String t = in.next();
    		
    		if(isDebug)
		    	out.println(t);
    		
			long ans = sol.solve(t);
	    	
			out.println(ans);
			
			if(isDebug)
				out.flush();
	    }
	    in.close();
	    out.close();
    }
	
	long solve(String t){
		int mask = pack(t);
		return map[mask];
	}
	
	long[][] precomputed;
	long[][] dp;
	long[] map;

	void preprocess(String s) {
		

		

		

		

		

		

			

			

			

		
		computeSubsets_more_optimized(s);
		
		computeMap_more_optimized();
		
		

		

	}

	long[][] dp_value;
	int[][] dp_mask;
	boolean[][] visited;
	
	void computeSubsets_more_optimized(String s) {
		int n = s.length();
		char[] str = s.toCharArray();
		
		precomputed = new long[M+1][1<<M];
		
		

		int[] numQ = new int[n+1];
		numQ[0] = 0;
		for(int i=1; i<= n; i++)
			numQ[i] = s.charAt(i-1)=='?'? numQ[i-1]+1: numQ[i-1];
		
		dp_mask = new int[n][n];
		dp_value = new long[n][n];
		for(int m=1; m<=M; m++){
			

			
			visited = new boolean[n][n];
			
			

			long[] pow = new long[n+1];
			pow[0] = 1;
			for(int i=1; i<=n; i++) 

				pow[i] = (pow[i-1]*m) % MOD;
			
			for(int i=0; i<s.length(); i++){
				for(int j=i; j<s.length(); j++){
					preprocess_more_optimized(str, i, j, m);
					long value = dp_value[i][j];
					int mask = dp_mask[i][j];
					

					precomputed[m][mask] += value*pow[numQ[n]-numQ[j+1]+numQ[i]];
					precomputed[m][mask] %= MOD;
				}
			}
		}		
	}

	void computeSubsets(String s) {
		int n = s.length();
		char[] str = s.toCharArray();
		
		precomputed = new long[M+1][1<<M];
		
		

		int[] numQ = new int[n+1];
		numQ[0] = 0;
		for(int i=1; i<= n; i++)
			numQ[i] = s.charAt(i-1)=='?'? numQ[i-1]+1: numQ[i-1];
		
		for(int m=1; m<=M; m++){
			

			dp = new long[n][n];
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					dp[i][j]=-1;
			
			

			long[] pow = new long[n+1];
			pow[0] = 1;
			for(int i=1; i<=n; i++) 

				pow[i] = (pow[i-1]*m) % MOD;
			
			for(int i=0; i<s.length(); i++){
				for(int j=i; j<s.length(); j++){
					long p = preprocess(str, i, j, m);
					int mask = (int)(p & EXTRACT);
					

					precomputed[m][mask] += (p >> M)*pow[numQ[n]-numQ[j+1]+numQ[i]];
					precomputed[m][mask] %= MOD;
				}
			}
		}
	}
	
	void computeMap_more_optimized(){
		


		

		

		

		

		
		

		

		

		
		map = new long[1<<M];
		
		long[][] dp = new long[M+1][1<<M];
		for(int m=1; m<=M; m++){
			for(int mask=0; mask<1<<M; mask++){
				dp[m][mask] = precomputed[m][mask];
			}
		}
		
		for(int pos=M-1; pos>=0; pos--){
			

			for(int m=1; m<=M; m++){
				for(int mask=0; mask < 1<<M; mask++){
					if( (mask & 1<<pos) > 0){
						long val = dp[m][mask] + dp[m][mask^(1<<pos)];
						dp[m][mask] = val>MOD? val-MOD : val;
					}
				}
			}
		}
		
		for(int mask=0; mask < 1<<M; mask++)
			map[mask] = dp[Integer.bitCount(mask)][mask];
	}
	
	void computeMap(){
		


		

		

		

		

		
		

		

		

		
		map = new long[1<<M];
		
		long[][] prev = new long[M+1][1<<M];
		for(int m=1; m<=M; m++){
			for(int mask=0; mask<1<<M; mask++){
				prev[m][mask] = precomputed[m][mask];
			}
		}
		
		for(int pos=M-1; pos>=0; pos--){
			long[][] curr = new long[M+1][1<<M];
			
			

			for(int m=1; m<=M; m++){
				for(int mask=0; mask < 1<<M; mask++){
					long val;
					if( (mask & 1<<pos) > 0){
						val = prev[m][mask] + prev[m][mask-(1<<pos)];
						val = val>MOD? val-MOD : val;
					}
					else{
						val = prev[m][mask];
					}
					curr[m][mask] = val;	
				}
			}
			prev = curr;
		}
		
		for(int mask=0; mask < 1<<M; mask++)
			map[mask] = prev[Integer.bitCount(mask)][mask];
	}


	

	void computeMapNaiveBetter(){
		map = new long[1<<M];

		for(int mask = 0; mask < (1<<M); mask++){
			for(int subset = mask; subset > 0; subset = (subset-1)&mask){
				map[mask] += precomputed[Integer.bitCount(mask)][subset];
				map[mask] = map[mask]>MOD? map[mask]-MOD : map[mask];
			}
			map[mask] += precomputed[Integer.bitCount(mask)][0];
			map[mask] = map[mask]>MOD? map[mask]-MOD : map[mask];
		}
	}

	

	

	void computeMapNaive() {
		map = new long[1<<M];
		
		for(int subset=0; subset<map.length; subset++){
			

			int numZeros = M-Integer.bitCount(subset);
			int[] zeroPos = new int[numZeros];
			int idx = 0;
			for(int i=0; i<M; i++){
				if((subset & (1<<i)) == 0)
					zeroPos[idx++] = i;
			}
			assert(idx == numZeros);
			
			

			for(int restSet=0; restSet < (1<<numZeros); restSet++){
				int mask = subset;
				for(int i=0; i<numZeros; i++){
					if ((restSet & 1<<i) > 0)
						mask += 1<<zeroPos[i];
				}
				map[mask] += precomputed[Integer.bitCount(mask)][subset];
				map[mask] = map[mask]>MOD? map[mask]-MOD : map[mask];
			}
		}
	}
	
	void preprocess_more_optimized(char[] s, int start, int end, int m) {
		if(start > end)
			return;
		
		if(visited[start][end])
			return;
		
		visited[start][end] = true;
		
		if(start == end){
			if(s[start] != '?'){
				dp_value[start][end] = 1;
				dp_mask[start][end] = 0;
			}
			else{
				dp_value[start][end] = m;
				dp_mask[start][end] = 0;
			}
		}
		else if(end == start+1){
			if(s[start] =='?' && s[end] == '?'){
				dp_value[start][end] = m;
				dp_mask[start][end] = 0;
			}
			else if(s[start] == '?'){
				dp_value[start][end] = 1;
				dp_mask[start][end] = pack(s[end]);
			}
			else if(s[end] == '?'){
				dp_value[start][end] = 1;
				dp_mask[start][end] = pack(s[start]);				
			}
			else if(s[start] == s[end]){
				dp_value[start][end] = 1;
				dp_mask[start][end] = 0;
			}
			else{
				dp_value[start][end] = 0;
				dp_mask[start][end] = 0;				
			}
		}
		else{
			if(s[start] == '?' && s[end] == '?'){
				preprocess_more_optimized(s, start+1, end-1, m);
				dp_value[start][end] =  (dp_value[start+1][end-1]*m) % MOD;
				dp_mask[start][end] = dp_mask[start+1][end-1];
				
			}
			else if(s[start] == '?'){
				preprocess_more_optimized(s, start+1, end-1, m);
				dp_value[start][end] = dp_value[start+1][end-1];
				dp_mask[start][end] = pack(dp_mask[start+1][end-1], s[end]);
			}
			else if(s[end] == '?'){
				preprocess_more_optimized(s, start+1, end-1, m);
				dp_value[start][end] = dp_value[start+1][end-1];
				dp_mask[start][end] = pack(dp_mask[start+1][end-1], s[start]);
			}
			else if(s[start] == s[end]){
				preprocess_more_optimized(s, start+1, end-1, m);
				dp_value[start][end] = dp_value[start+1][end-1];
				dp_mask[start][end] = dp_mask[start+1][end-1];
			}
			else{
				dp_value[start][end] = 0;
				dp_mask[start][end] = 0;	
			}			
		}
	}
	
	long preprocess(char[] s, int start, int end, int m) {
		if(start > end)
			return 1 << M;
		
		if(dp[start][end] != -1)
			return dp[start][end];
		
		if(start == end){
			if(s[start] != '?')
				return 1 << M;
			else
				return m << M;
		}
		
		long mask;
		long value;
		long p;
		
		if(s[start] == '?' && s[end] == '?'){
			p = preprocess(s, start+1, end-1, m);
			mask = p & EXTRACT;
			value =  ((p >> M)*m) % MOD;
		}
		else if(s[start] == '?'){
			p = preprocess(s, start+1, end-1, m);
			mask = pack(p & EXTRACT, s[end]);
			value = p >> M;
		}
		else if(s[end] == '?'){
			p = preprocess(s, start+1, end-1, m);
			mask = pack(p & EXTRACT, s[start]);
			value = p >> M;
		}
		else if(s[start] == s[end]){
			p = preprocess(s, start+1, end-1, m);
			mask = p & EXTRACT;
			value = p >> M;
		}
		else{
			mask = 0;
			value = 0;
		}

		p = (value << M) + mask;
		dp[start][end] = p;
		return p;
	}

	int pack(String t){
		int mask = 0;
		for(int i=0; i<t.length(); i++){
			int pos = t.charAt(i)-'a';
			mask += (1<<pos);
		}
		return mask;
	}
	
	int pack(char ch){
		int pos = ch-'a';
		return (1<<pos);
	}
	
	long pack(long mask, char ch){
		int pos = ch-'a';
		mask = mask | (1<<pos);
		return mask;		
	}
	
	int pack(int mask, char ch){
		int pos = ch-'a';
		mask = mask | (1<<pos);
		return mask;
	}
	
	char[] unpack(int mask){
		char[] t = new char[Integer.bitCount(mask)];
		for(int i=0; i<M; i++){
			if((mask & (1<<i)) > 0)
				t[i] = (char) ('a'+i);
		}
		return t;
	}
	
	private static int numPalinSubstr(String s){
		return numPalinSubstr(s, 0, s.length()-1);
	}
	

	private static int numPalinSubstr(String s, int i, int j) {
		if(j < i)
			return 0;
		if(j == i){
			if(s.charAt(i) == s.charAt(j))
				return 1;
			else
				return 0;
		}
		
		int palin = isPalin(s, i, j)? 1:0;
		
		return numPalinSubstr(s, i, j-1) + numPalinSubstr(s, i+1, j) - numPalinSubstr(s, i+1, j-1) + palin;
	}


	private static boolean isPalin(String s, int start, int end) {
		while(start < end)
			if(s.charAt(start++) != s.charAt(end--))
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

	}
	
	public static class MyPrintWriter extends PrintWriter{
		public MyPrintWriter(OutputStream os) {
			super(os);
		}
		
		public void print(long[] arr){
			if(arr != null){
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
			if(arr != null){
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
			if(arr != null){
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
}

