import java.io.*;
import java.math.*;
import java.security.KeyStore.Entry;
import java.util.*;


 public class id0 {
	private InputStream is;
	private PrintWriter out;
	int time = 0, dp[][], DP[], start[], end[], red[], black[], MOD = (int)(1e9+7), arr[];
	int MAX = 200000, N, K;
	ArrayList<Integer>[] amp;
	boolean b[], boo[][];
	Pair prr[], parent[][];
	HashSet<Integer> hs = new HashSet<>();
	

	public static void main(String[] args) throws Exception {
		new Thread(null, new Runnable() {
		public void run() {
			try {

		

		} catch (Exception e) {
				System.out.println(e);
			}
		}
	}, "1", 1 << 26).start();
		new id0().soln();
	}
	char ch[][];
	void solve() {
		int n = ni(), m = ni();
		ch = new char[n][m];
		int x = 0, y = 0;
		for(int i = 0;i<n;i++) ch[i] = ns().toCharArray();
		for(int i = 0; i< n; i ++){
			for(int j = 0; j < m ; j++){
				

				if(ch[i][j]=='F'){ x = i;y = j;} 
			}
			

		}
		N = n; K = m;
		boo = new boolean[n][m];
		parent = new Pair[n][m];
		dfs(0,0);
		parent[0][0] = new Pair(-1,-1);
		Pair p = new Pair(-1,-1);
		int x1 = x, y1=  y;
		StringBuilder sb = new StringBuilder();
		while(true){
			int c = parent[x1][y1].u, d = parent[x1][y1].v;
			if(c==x1 && d==(y1+1)) sb.append('L');
			if(c==x1 && d==(y1-1)) sb.append('R');
			if(d==y1 && c==(x1+1)) sb.append('U');
			if(d==y1 && c==(x1-1)) sb.append('D');
			x1 = c; y1= d;
			if(x1==-1) break;
		}
		sb = sb.reverse();
		boolean t1 = false, t2 = false, a1 = false, a2 = false;
		int pos1 = 1, pos2 = 1;
		

		for(int i = 0; i<sb.length();i++){
			if((sb.charAt(i)=='R' || sb.charAt(i)=='L') && !t1){
				System.out.println(sb.charAt(i));
				System.out.flush();
				try{
					int k = ni(), l = ni();
					if(k==pos1 && l== pos2){
						a1 = true;
						i--;
					}
					else{
						pos1 = k; pos2 = l;
					}
				}
				catch(Exception e){
					return;
				}
				t1 = true;
			}
			else if(sb.charAt(i)=='R' || sb.charAt(i)=='L'){
				if(a1){
					if(sb.charAt(i)=='R')
					System.out.println('L');
					else System.out.println('R');
					System.out.flush();
					try{
						int k = ni(), l = ni();
						pos1 = k; pos2 = l;
					}
					catch(Exception e){
						return;
					}
				}
				else{
					System.out.println(sb.charAt(i));
					System.out.flush();
					try{
						int k = ni(), l = ni();
						pos1 = k; pos2 = l;
					}
					catch(Exception e){
						return;
					}
				}
			}
			else if((sb.charAt(i)=='U' || sb.charAt(i)=='D') && !t2){
				System.out.println(sb.charAt(i));
				System.out.flush();
				try{
					int k = ni(), l = ni();
					if(k==pos1 && l== pos2){
						a2 = true;
						i--;
					}
					else{ pos1 = k; pos2 = l;}
				}
				catch(Exception e){
					return;
				}
				t2 = true;
			}
			else{
				if(a2){
					if(sb.charAt(i)=='U')
						System.out.println('D');
						else System.out.println('U');
						System.out.flush();
						try{
							int k = ni(), l = ni();
							pos1 = k; pos2 = l;
						}
						catch(Exception e){
							return;
						}
				}
				else{
					System.out.println(sb.charAt(i));
					System.out.flush();
					try{
						int k = ni(), l = ni();
						pos1 = k; pos2 = l;
					}
					catch(Exception e){
						return;
					}
				}
			}
		}
	}
	void dfs(int i, int j){
		boo[i][j] = true;
		if(ch[i][j]=='F') return;
		Pair p = new Pair(i,j);
		if(i>0 && ch[i-1][j]!='*' && !boo[i-1][j]){
			parent[i-1][j] = p;
			dfs(i-1,j);
		}
		if(j>0 && ch[i][j-1]!='*' && !boo[i][j-1]){
			parent[i][j-1] = p;
			dfs(i,j-1);
		}
		if(i<N-1 && ch[i+1][j]!='*' && !boo[i+1][j]){
			parent[i+1][j] = p;
			dfs(i+1,j);
		}
		if(j<K-1 && ch[i][j+1]!='*' && !boo[i][j+1]){
			parent[i][j+1] = p;
			dfs(i,j+1);
		}
	}
	int recur(int n){
		

		if(n>=N) return 0;
		if(DP[n]!=-1) return DP[n];
		int ans = 0;
		DP[n] = 0;
		
		for(int i = n; i<N;i++){
			if(start[arr[i]]>n){
				DP[i] = Math.max((red[end[arr[i]]]^red[start[arr[i]]-1]+recur(end[arr[i]])),DP[i]);
			}
			
		}
		return DP[n];
	}
	void recur(int n, int k){
		if(k<0) return;
		hs.add(K-k);
		if(n>=0 && dp[n][k]!=-1) return;
		if(n>=0) dp[n][k] = 1;
		for(int i = n+1;i<N;i++){
			recur(i,k-arr[i]);
		}
	}
	long modInverse(long a, long id2){
        return  power(a, id2-2, id2);
	}
	long power(long x, long y, long m)
	{
		if (y == 0)
    return 1;
	long p = power(x, y/2, m) % m;
	p = (p * p) % m;

	return (y%2 == 0)? p : (x * p) % m;
	}
	boolean isPrime(int x){
		for(int i = 2;i*1L*i<=x;i++) if(x%i==0) return false;
		return true;
	}
	public String isPossible(int b[]){
		String ans = "Possible";
		int n = b.length;
		Arrays.sort(b);
		if(n==1) return "Possible";
		if(b[0]==1) return "Impossible";
		if(b[0]>=n) return ans;
		int lcm = 1;
		for(int i : b){
			long gcd = gcd(lcm,i);
			lcm *= (i/gcd);
		}
		int cnt = 0;
		for(int i : b) cnt+=lcm/i;
		if(cnt>lcm) return "Impossible";
		return ans;
	}
	public long gcd(long a, long b){
		if(b==0) return a;
		return gcd(b,a%b);
	}
	void failFn(String str, int arr[]){
		int len = 0;
		arr[0] = 0;
		int i = 1;
		while(i<arr.length){
			if(str.charAt(i)==str.charAt(len)){
				arr[i++] = ++len;
				continue;
			}
			if(len == 0){
				arr[i] = len;
				i++;
				continue;
			}
			if(str.charAt(i)!=str.charAt(len)){
				len = arr[len-1];
			}
		}
	}
	static class ST1{
		int arr[], st[], size;
		ST1(int a[]){
			arr = a.clone();
			size = 10*arr.length;
			st = new int[size];
			build(0,arr.length-1,1);
		}
		void build(int ss, int se, int si){
			if(ss==se){
				st[si] = arr[ss];
				return;
			}
			int mid = (ss+se)/2;
			int val = 2*si;
			build(ss,mid,val); build(mid+1,se,val+1);
			st[si] = Math.min(st[val], st[val+1]);
		}
		int get(int ss, int se, int l, int r, int si){
			if(l>se || r<ss || l>r) return Integer.MAX_VALUE;
			if(l<=ss && r>=se) return st[si];
			int mid = (ss+se)/2;
			int val = 2*si;
			return Math.min(get(ss,mid,l,r,val), get(mid+1,se,l,r,val+1));
		}
	}
	static class ST{
		int arr[],lazy[],n;
		ST(int a){
			n = a;
			arr = new int[10*n];
			lazy = new int[10*n];
		}
		void up(int l,int r,int val){
			update(0,n-1,0,l,r,val);
		}
		void update(int l,int r,int c,int x,int y,int val){
			if(lazy[c]!=0){
				lazy[2*c+1]+=lazy[c];
				lazy[2*c+2]+=lazy[c];
				if(l==r)
					arr[c]+=lazy[c];
				lazy[c] = 0;
			}
			if(l>r||x>y||l>y||x>r)
				return;
			if(x<=l&&y>=r){
				lazy[c]+=val;
				return ;
			}
			int mid = l+r>>1;
			update(l,mid,2*c+1,x,y,val);
			update(mid+1,r,2*c+2,x,y,val);
			arr[c] = Math.max(arr[2*c+1], arr[2*c+2]);
		}
		int an(int ind){
			return ans(0,n-1,0,ind);
		}
		int ans(int l,int r,int c,int ind){
			if(lazy[c]!=0){
				lazy[2*c+1]+=lazy[c];
				lazy[2*c+2]+=lazy[c];
				if(l==r)
					arr[c]+=lazy[c];
				lazy[c] = 0;
			}
			if(l==r)
				return arr[c];
			int mid = l+r>>1;
			if(mid>=ind)
				return ans(l,mid,2*c+1,ind);
			return ans(mid+1,r,2*c+2,ind);
		}
	}
	public static class id3 {
		
	    int[] array; 


	    public id3(int size) {
	        array = new int[size + 1];
	    }
	    public int rsq(int ind) {
	        assert ind > 0;
	        int sum = 0;
	        while (ind > 0) {
	            sum += array[ind];
	            

	            ind -= ind & (-ind);
	        }
	        return sum;
	    }
	    public int rsq(int a, int b) {
	        assert b >= a && a > 0 && b > 0;
	        return rsq(b) - rsq(a - 1);
	    }
	    public void update(int ind, int value) {
	        assert ind > 0;
	        while (ind < array.length) {
	            array[ind] += value;
	            

	            ind += ind & (-ind);
	        }
	    }
	    public int size() {
	        return array.length - 1;
	    }
	}
	public static int[] shuffle(int[] a, Random gen){
		for(int i = 0, n = a.length;i < n;i++)
		{ 
			int ind = gen.nextInt(n-i)+i; 
			int d = a[i]; 
			a[i] = a[ind];
			a[ind] = d; 
		} 
	return a; 
	}

	class Pair implements Comparable<Pair>{
		int u, v;
		Pair(int u, int v){
			this.u = u;
			this.v = v;
		}public int hashCode() {
			return Objects.hash();
		}
		public boolean equals(Object o) {
			Pair other = (Pair) o;
			return ((u == other.u && v == other.v) || (v == other.u && u == other.v));
		}
		public int compareTo(Pair other) {
			

			return Long.compare(u, other.u);

		}
	}
	long power(long x, long y, int mod){
		long ans = 1;
		while(y>0){
			if(y%2==0){
				x = (x*x)%mod;
				y/=2;
			}
			else{
				ans = (x*ans)%mod;
				y--;
			}
		}
		return ans;
	}
	void soln() {
		is = System.in;
		out = new PrintWriter(System.out);
		long s = System.currentTimeMillis();
		solve();
		

		out.flush();
		

	}


	

	

	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;

	private int readByte() {
		if (lenbuf == -1)
			throw new InputMismatchException();
		if (ptrbuf >= lenbuf) {
			ptrbuf = 0;
			try {
				lenbuf = is.read(inbuf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (lenbuf <= 0)
				return -1;
		}
		return inbuf[ptrbuf++];
	}

	private boolean id1(int c) {
		return !(c >= 33 && c <= 126);
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && id1(b))
			;
		return b;
	}

	private double nd() {
		return Double.parseDouble(ns());
	}

	private char nc() {
		return (char) skip();
	}
	private String ns() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!(id1(b))) { 

									

			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	private char[] ns(int n) {
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while (p < n && !(id1(b))) {
			buf[p++] = (char) b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}

	private char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for (int i = 0; i < n; i++)
			map[i] = ns(m);
		return map;
	}

	private int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}

	private int ni() {
		int num = 0, b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	private long nl() {
		long num = 0;
		int b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;

	private void tr(Object... o) {
		if (!oj)
			System.out.println(Arrays.deepToString(o));
	}
}