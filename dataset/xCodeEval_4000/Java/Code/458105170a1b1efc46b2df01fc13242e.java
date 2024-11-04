import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class ExpensiveStrings2 {

	static int N,nlen,inpLen;
	static int totalLen;
	static char c[];
	static int goBack[];
	static long cost[];
	static long stringCost[];
	
	static int[] sa,lcp;
	static long prefixCostSums[];
	static RMQ lcprmq;
	

	static long res;
	static final boolean debug = false;
	
	static int curTrieNode = 1;
	static int trie[][];
	static long len[];
	static long cst[];
	
	public static void main(String[] args) {
		FS in = new FS();
		N = in.nextInt();
		nlen = String.valueOf(""+N).length();
		
		char inp[][] = new char[N][];
		inpLen = 0;
		for(int i = 0; i < N; i++) {
			inp[i] = in.next().toCharArray();
			inpLen += inp[i].length;
		}
		stringCost = new long[N];
		for(int i = 0; i < N; i++)stringCost[i] = in.nextLong();
		
		totalLen = N*nlen+inpLen;
		c = new char[totalLen];
		goBack = new int[totalLen];
		cost = new long[totalLen];
		res = 0;
		int cid = 0;
		
		trie = new int[26][inpLen+1];
		cst = new long[inpLen+1];
		len = new long[inpLen+1];
		
		for(int i = 0; i < N; i++) {
			

			int curNode = 0;
			for(int j = 0; j < inp[i].length; j++) {
				int ch = inp[i][j]-'a';
				if(trie[ch][curNode] == 0) trie[ch][curNode] = curTrieNode++;
				curNode = trie[ch][curNode];
			}
			cst[curNode]+=stringCost[i];
			len[curNode] = inp[i].length;
			
			for(int j = 0; j < inp[i].length; j++) {
				cost[cid] = stringCost[i];
				c[cid++] = inp[i][j];
			}
			

			String s = String.valueOf(""+i);
			while(s.length() < nlen) s = "0"+s;
			for(int j = 0; j < nlen; j++) {
				goBack[cid] = j+1;
				cost[cid] = 0;
				c[cid++] = (char)(s.charAt(j));
			}
		}
		
		for(int i = 0; i < inpLen+1; i++) {
			

			boolean good = true;
			for(int ch = 0; ch < 26; ch++) if(trie[ch][i] != 0) good = false;
			
			if(good) res = Math.max(res, cst[i]*len[i]);
		}
		
		if(debug)System.out.println(res);
		
		sa = suffixArray(c);
		lcp = lcp(sa,c);
		

		for(int i = 0; i < sa.length-1; i++) {
			int id = sa[i];
			if(goBack[id] > 0 || lcp[i] == 0) {
				if(goBack[id] > 0) lcp[i] = 0;
				continue;
			}
			int endMatch = id+lcp[i]-1;
			

			lcp[i] -= goBack[endMatch];
		}
		lcprmq = new RMQ(lcp);
		prefixCostSums = new long[sa.length];
		
		
		prefixCostSums[0] = cost[sa[0]];
		for(int i = 1; i < totalLen; i++) {
			prefixCostSums[i] = prefixCostSums[i-1]+cost[sa[i]];
		}
		

		
		if(debug) {
		System.out.println(new String(c));
		System.out.println("Lens: "+sa.length+" "+lcp.length);
		System.out.println("SA: "+Arrays.toString(sa));
		System.out.println("LCP: "+Arrays.toString(lcp));
		System.out.println("PRE: "+Arrays.toString(prefixCostSums));
		}
		
		for(int i = 0; i < totalLen-1; i++) { 

			int id = sa[i];
			if(goBack[id] > 0) continue; 

			
			

			

			int h = lcp[i];
			if(h == 0) continue; 

			
			int l = bsL(0, i, i, h);
			int r = bs(i,totalLen-2, i, h);
			
			if(debug)System.out.println("Sufid: "+i+"  "+h+" l/r:  "+l+" "+r);

			
			

			long curAns = (long)(h) * getSum(l, r+1);
			

			
			res = Math.max(res, curAns);
			
		}




























































































		
		System.out.println(res);
		
	}
	
	static int[] reverse(int a[]) {
		int b[] = new int[a.length];
		int id = 0;
		for(int i = a.length-1; i >= 0; i--) {
			b[id++] = a[i];
		}
		return b;
	}
	static long getSum(int l, int r) {


		long max = prefixCostSums[r];
		return max - (l == 0 ? 0 : prefixCostSums[l-1]);
	}
	
	static int bsL(int lo, int hi, int right, int target) {
		if(lo == hi) return lo;
		if(lo+1 == hi) {
			if(lcprmq.query(lo, right) >= target) return lo;
			return hi;
		}
		int mid = (lo+hi)/2;
		if(lcprmq.query(mid, right) >= target) return bsL(lo, mid, right, target);
		return bsL(mid, hi, right, target);
	}
	static int bs(int lo, int hi, int left, int target) {
		if(lo == hi) return lo;
		if(lo+1 == hi) {
			if(lcprmq.query(left, hi) >= target) return hi;
			return lo;
		}
		int mid = (lo+hi)/2;
		if(lcprmq.query(left, mid) >= target) return bs(mid, hi, left, target);
		return bs(lo, mid, left, target);
	}
	

	

	static class RMQ {
		int[] vs;
		int[][] lift;
	
		public RMQ(int[] vs) {
			this.vs = vs;
			int n = vs.length;
			int maxlog = Integer.numberOfTrailingZeros(Integer.highestOneBit(n)) + 2;
			lift = new int[maxlog][n];
			for (int i = 0; i < n; i++)
				lift[0][i] = vs[i];
			int lastRange = 1;
			for (int lg = 1; lg < maxlog; lg++) {
				for (int i = 0; i < n; i++) {
					lift[lg][i] = Math.min(lift[lg - 1][i], lift[lg - 1][Math.min(i + lastRange, n - 1)]);
				}
				lastRange *= 2;
			}
		}
	
		public int query(int low, int hi) {
			int range = hi - low + 1;
			int exp = Integer.highestOneBit(range);
			int lg = Integer.numberOfTrailingZeros(exp);
			return Math.min(lift[lg][low], lift[lg][hi - exp + 1]);
		}
	}
	























































	
	  

	  static int[] suffixArray(char[] S) {
	    int n = S.length;
	    Integer[] order = new Integer[n];
	    for (int i = 0; i < n; i++)
	      order[i] = n - 1 - i;

	    

	    Arrays.sort(order, (a, b) -> Character.compare(S[a], S[b]));

	    int[] sa = new int[n];
	    int[] classes = new int[n];
	    for (int i = 0; i < n; i++) {
	      sa[i] = order[i];
	      classes[i] = S[i];
	    }
	    

	    


	    for (int len = 1; len < n; len *= 2) {
	      int[] c = classes.clone();
	      for (int i = 0; i < n; i++) {
	        

	        

	        classes[sa[i]] = i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < n && c[sa[i - 1] + len / 2] == c[sa[i] + len / 2] ? classes[sa[i - 1]] : i;
	      }
	      

	      

	      int[] cnt = new int[n];
	      for (int i = 0; i < n; i++)
	        cnt[i] = i;
	      int[] s = sa.clone();
	      for (int i = 0; i < n; i++) {
	        

	        

	        int s1 = s[i] - len;
	        

	        if (s1 >= 0)
	          sa[cnt[classes[s1]]++] = s1;
	      }
	    }
	    return sa;
	  }

	  

	  static int[] rotationArray(char[] S) {
	    int n = S.length;
	    Integer[] order = new Integer[n];
	    for (int i = 0; i < n; i++)
	      order[i] = i;
	    Arrays.sort(order, (a, b) -> Character.compare(S[a], S[b]));
	    int[] sa = new int[n];
	    int[] classes = new int[n];
	    for (int i = 0; i < n; i++) {
	      sa[i] = order[i];
	      classes[i] = S[i];
	    }
	    for (int len = 1; len < n; len *= 2) {
	      int[] c = classes.clone();
	      for (int i = 0; i < n; i++)
	        classes[sa[i]] = i > 0 && c[sa[i - 1]] == c[sa[i]] && c[(sa[i - 1] + len / 2) % n] == c[(sa[i] + len / 2) % n] ? classes[sa[i - 1]] : i;
	      int[] cnt = new int[n];
	      for (int i = 0; i < n; i++)
	        cnt[i] = i;
	      int[] s = sa.clone();
	      for (int i = 0; i < n; i++) {
	        int s1 = (s[i] - len + n) % n;
	        sa[cnt[classes[s1]]++] = s1;
	      }
	    }
	    return sa;
	  }

	  

	  static int[] lcp(int[] sa, char[] s) {
	    int n = sa.length;
	    int[] rank = new int[n];
	    for (int i = 0; i < n; i++)
	      rank[sa[i]] = i;
	    int[] lcp = new int[n - 1];
	    for (int i = 0, h = 0; i < n; i++) {
	      if (rank[i] < n - 1) {
	        for (int j = sa[rank[i] + 1]; Math.max(i, j) + h < s.length && s[i + h] == s[j + h]; ++h)
	          ;
	        lcp[rank[i]] = h;
	        if (h > 0)
	          --h;
	      }
	    }
	    return lcp;
	  }
	
	
	

	static class FS{
		BufferedReader br;
		StringTokenizer st;
		public FS(String s) throws Exception {
			try{ br = new BufferedReader(new FileReader(s)); }
			catch(Exception e) { throw new Exception(); }
		}
		public FS(){
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String nextToken()	{
			while(st == null ||!st.hasMoreElements()){
				try { st = new StringTokenizer(br.readLine());}
				catch(IOException e) { e.printStackTrace(); }			
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(nextToken());
		}
		long nextLong() {
			return Long.parseLong(nextToken());
		}
		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
		String next() {
			return nextToken();
		}

	}
	
}