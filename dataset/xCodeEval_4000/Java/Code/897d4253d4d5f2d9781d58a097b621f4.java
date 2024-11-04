
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Graph {

	
	static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException {
			byte[] buf = new byte[64]; 

			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}

		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}

		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}

			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
	public static void main(String[] args) throws IOException {
		
		
		Scanner scan=new Scanner(System.in);
		int t=scan.nextInt();
		
		while(t-->0) {
			int n=scan.nextInt();
			int arr[]=new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=scan.nextInt();
			}
			
			D1328(arr, n);
			System.out.println(); 
			
		}
		

	}
	
	public static void D1334(long n, long l, long r, long seg, long cur) {
		
		if(cur>r) return;
		
		if(seg==n) {
			System.out.print(1);
			return;
		}
		
		long t= 2*(n-seg);
		
		long hi= cur+t-1;
		
		
		if(hi<l) {
			D1334(n, l, r, seg+1, hi+1);
			return;
		}
		
		
		long i= l-cur+1;
		
		if(i%2==0) {
			System.out.print((seg+i/2)+" ");
			i++;
		}
		
		
		
		for(;i+cur-1<=Math.min(r,  hi);i++) {
			
			if(i%2!=0) System.out.print(seg+" ");
			else System.out.print((seg+i/2)+" ");
			
		}
		
		if(i==r+1) return;
		
		D1334(n, hi+1, r, seg+1, hi+1);
		
		
	}
	
	public static void C1334() throws IOException {
		
		Reader scan=new Reader();
		int n=scan.nextInt();
		int m=scan.nextInt();
		
		List<Integer> adj[]=new ArrayList[n+1];
		List<Integer> rev[]=new ArrayList[n+1];
		for(int i=0;i<m;i++) {
			
			int u=scan.nextInt();
			int v=scan.nextInt();
			
			if(adj[v]==null) adj[v]=new ArrayList<>();
			if(rev[u]==null) rev[u]=new ArrayList<>();
			adj[v].add(u);
			rev[u].add(v);
		}
		
		boolean visited[]=new boolean[n+1];
		
		for(int i=1;i<=n;i++) {
			
			if(!visited[i]) {
				Set<Integer> cur=new HashSet<>();
				boolean ans= dfs(i, adj, visited, cur);
				if(ans) {
					System.out.println(-1);
					return;
				}
			}
		}
		




















		
		
		int min1[]=new int[n+1];
		int min2[]=new int[n+1];
		visited=new boolean[n+1];
		for(int i=1;i<=n;i++) {
			
			if(!visited[i]) {
				getMin(min1, i, adj, visited);
			}
		}
		
		visited=new boolean[n+1];
		for(int i=1;i<=n;i++) {
			
			if(!visited[i]) {
				getMin(min2, i, rev, visited);
			}
		}
		
		int count=0;
		StringBuilder ans=new StringBuilder("");
		for(int i=1;i<=n;i++) {
			
			if(min1[i]==i&&min2[i]==i) {
				count++;
				ans.append("A");
			}else {
				ans.append("E");
			}
		}
		System.out.println(count);
		System.out.println(ans.toString());
		
		
	}
	
	public static int getMin(int min[], int start, List<Integer> adj[], boolean visited[]) {
		
		if(visited[start]) {
			return min[start];
		}
		
		min[start]=start;
		visited[start]=true;
		if(adj[start]==null) return min[start];
		for(Integer x: adj[start]) {
			min[start]=Math.min(min[start], getMin(min, x, adj, visited));
		}
		
		return min[start];
		
	}
	
	public static boolean dfs(int start, List<Integer> adj[], boolean visited[], Set<Integer> cur) {
		
		
		if(cur.contains(start)) {
			return true;
		}
		
		if(visited[start]) return false;
		
		visited[start]=true;
		cur.add(start);
		
		if(adj[start]==null) {
			cur.remove(start);
			return false;
		}
		
		for(int newStart: adj[start]) {
			if(dfs(newStart, adj, visited, cur)) {
				return true;
			}
		}
		
		cur.remove(start);
		return false;
	}
	
	public static void D1340() throws IOException {
		
		Reader scan=new Reader();
		int n=scan.nextInt();
		
		List<Integer> adj[]=new ArrayList[n+1];
		
		for(int i=0;i<n-1;i++) {
			int u=scan.nextInt();
			int v=scan.nextInt();
			
			if(adj[u]==null) adj[u]=new ArrayList<>();
			if(adj[v]==null) adj[v]=new ArrayList<>();
			
			adj[u].add(v);
			adj[v].add(u);
		}
		
		if(adj[1]==null) {
			System.out.println(1);
			System.out.println("1 0");
			return;
		}
		
		StringBuilder ans=new StringBuilder("");
		System.out.println(dfs(1, adj, 0, 0, ans));
		
		System.out.println(ans.toString());
		
	}
	
	public static int dfs(int start, List<Integer> adj[], int parent, int curTime, StringBuilder ans){
		
		
		int count=0;
		count++;
		ans.append(start+" "+curTime+"\n");
		
		int copy=curTime;
		
		if(curTime-adj[start].size()>=0) {
			copy=curTime-adj[start].size();
			count++;
			ans.append(start+" "+copy+"\n");
		}
		
		
		int i=copy+1;
		for(Integer x: adj[start]) {
			if(x==parent) continue;
			
			count+=dfs(x, adj, start, i, ans);
			count++;
			ans.append(start+" "+i+"\n");
			i++;
			
		}
		if(i!=curTime&&start!=1) {
			count++;
			ans.append(start+" "+(curTime-1)+"\n");
		}
		
		return count;
		
		
	}
	
	public static void C1340() throws IOException {
		
		Reader scan=new Reader();
		int n=scan.nextInt();
		int m=scan.nextInt();
		
		int arr[]=new int[m+1];
		for(int i=0;i<m;i++) {
			arr[i]=scan.nextInt();
		}
		
		arr[arr.length-1]=n;
		
		
		int g=scan.nextInt();
		int r=scan.nextInt();
		
		long dp[][]=new long[m+1][g+1];
		
		for(long x[]: dp) {
			Arrays.fill(x, -1);
		}
		long ans= C1340helper(0, arr, n, dp, g-arr[0], g, r);
		ans= (ans==Long.MAX_VALUE)?-1: ans;
		System.out.println(ans);
		
	}
	
	public static long C1340helper(int i, int arr[], int n, long dp[][], int rem, int g, int r) {
		
		

		
		if(i<0) return Long.MAX_VALUE;
		if(i>=arr.length) return Long.MAX_VALUE;
		
		if(rem<0) return Long.MAX_VALUE;
		
		if(arr[i]==n) {
			return (long)0;
		}
		
		if(dp[i][rem]==-2) {
			return Long.MAX_VALUE;
		}
		
		if(rem==0&&dp[i][g]==-2) {
			return Long.MAX_VALUE;
		}
		
		if(dp[i][rem]!=-1) {
			return dp[i][rem];
		}
		
		dp[i][rem]=-2;
		
		long curTime= (rem==0)? (long)r: (long)0;
		int time= (rem==0)?g:rem;
		
		long ans1=Long.MAX_VALUE;
		if(i!=0) {
			ans1= C1340helper(i-1, arr, n, dp, time-(arr[i]-arr[i-1]), g, r);
			if(ans1!=Long.MAX_VALUE) {
				ans1+= arr[i]-arr[i-1];
			}
		}
		
		long ans2= C1340helper(i+1, arr, n, dp, time-(arr[i+1]-arr[i]), g, r);
		
		if(ans2!=Long.MAX_VALUE) {
			ans2+= arr[i+1]-arr[i];
		}
		long ans= Math.min(ans1, ans2);
		if(ans==Long.MAX_VALUE) {
			dp[i][rem]=Long.MAX_VALUE;
			
		}else {
			dp[i][rem]= ans+curTime;
		}
		
		return dp[i][rem];
		
		
		
	}
	
	public static void B1340() throws IOException {
		
		String str[]= {"0001000", "1101101", "0100010", "0100100", "1000101", "0010100", "0010000", "0101101", "0000000", "0000100"};
		int masks[]=new int[10];
		int ind=0;
		for(String s: str) {
			
			int val=0;
			int pow=1;
			for(int i=s.length()-1;i>=0;i--) {
				if(s.charAt(i)=='1') {
					val+= pow;
				}
				
				pow*=2;
			}
			
			masks[ind++]=val;
		}
		
		

		
		int vals[]=new int[10];
		
		for(int i=0;i<vals.length;i++) {
			vals[i]= 127- masks[i];
		}
		
		

		Scanner scan=new Scanner(System.in);
		
		int n=scan.nextInt();
		int k=scan.nextInt();
		
		int arr[]=new int[n];
		for(int i=0;i<n;i++) {
			String s=scan.next();
			int val=0;
			int pow=1;
			for(int j=s.length()-1;j>=0;j--) {
				if(s.charAt(j)=='1') {
					val+= pow;
				}
				
				pow*=2;
			}
			
			arr[i]=val;
		}
		String dp[][]=new String[n][k+1];
		
		for(String x[]: dp) {
			Arrays.fill(x, "");
		}
		
		String ans= B1340helper(0, arr, dp, k, masks, vals);
		if(ans==null) {
			System.out.println(-1);
		}else {
			System.out.println(ans);
		}
	}
	
	public static String B1340helper(int i, int arr[], String dp[][], int k, int masks[], int vals[]) {
		
		if(k<0) return null;
		
		if(i>=arr.length) {
			
			if(k==0) return"";
			
			return null;
		}
		
		if(dp[i][k]!="") {
			return dp[i][k];
		}
		
		for(int j=9;j>=0;j--) {
			
			
			
			if((arr[i]&masks[j])!=0) {
				
				continue;
			}
			
			int required= Integer.bitCount(vals[j]^arr[i]);
			String recAns= B1340helper(i+1, arr, dp, k-required, masks, vals);
			
			if(recAns!=null) {
				dp[i][k]= j+recAns;
				return dp[i][k];
			}
			
		}
		dp[i][k]=null;
		return null;
		
		
	}
	
	public static void F1335(int n, int m, int col[][], char adj[][]) {
		
		int x= Math.max(n, m);
		
		int l= (int)(Math.log(n*m)/Math.log(2));
		

		int dp[][]=new int[n*m][l+1];
		
		for(int i=0;i<n*m;i++) {
			dp[i][0]=getIndex(n, m, ((x==m)? i/x: i%x), ((x==m)? i%x: i/x), adj);
		}
		
		for(int j=1;j<dp[0].length;j++) {
			
			for(int i=0;i<n*m;i++) {
				
				dp[i][j]= dp[dp[i][j-1]][j-1];
			}
			
		}
		
		int finPositions[]=new int[n*m];
		Set<Integer> set=new HashSet<>();
		
		for(int i=0;i<n*m;i++) {
			
			int rem= n*m- (int)Math.pow(2, l);
			
			finPositions[i]=dp[i][dp[0].length-1];
			while(rem!=0) {
				int ln= (int)(Math.log(rem)/Math.log(2));
				finPositions[i]= dp[finPositions[i]][ln];
				
				rem-=(int)Math.pow(2, ln);
			}
			
			set.add(finPositions[i]);
					
		}
		
		int ans= set.size();
		
		int count=0;
		for(int i=0;i<n*m;i++) {
			
			if(col[((x==m)? i/x: i%x)][((x==m)? i%x: i/x)]==0&&set.contains(finPositions[i])) {
				count++;
				set.remove(finPositions[i]);
			}
		}
		
		System.out.println(ans+" "+count);
		
	}
	
	public static int getIndex(int n, int m, int i, int j, char adj[][]) {
		
		int val=Math.max(n, m);
		if(adj[i][j]=='L') {
			return (val==m)?i*(val)+j-1: i+(val)*(j-1);
		}
		
		if(adj[i][j]=='R') {
			return (val==m)?i*(val)+j+1: i+(val)*(j+1);
		}
		
		if(adj[i][j]=='U') return (val==m)?(i-1)*(val)+j: i-1+(val)*(j);
		
		return (val==m)?(i+1)*(val)+j: i+1+(val)*(j);
		
	}

	public static void D1328(int arr[], int n) {
		
		int x= arr[0];
		boolean allSame=true;
		for(int i: arr) {
			if(i!=x) {
				allSame=false;
				break;
			}
		}
		
		if(allSame) {
			System.out.println(1);
			for(int i=0;i<n;i++) {
				System.out.print(1+" ");
			}
			
			return;
		}
		
		if(n%2==0) {
			System.out.println(2);
			for(int i=0;i<n/2;i++) {
				System.out.print(1+" "+2+" ");
			}
			
			return;
			
		}
		
		
		boolean grp=false;
		int index=-1;
		for(int i=0;i<n;i++) {
			if(arr[i]==arr[(i+1)%n]) {
				grp=true;
				index=i;
			}
		}
		
		if(!grp) {
			
			System.out.println(3);
			
			System.out.print(1+" ");
			for(int i=0;i<n/2;i++) {
				System.out.print(2+" "+3+" ");
			}
			
			return;
		}
		
			
		System.out.println(2);
		int k=1;
		
		for(int i=0;i<n;i++) {
			System.out.print(k+" ");
			if(i==index&&i!=n-1) {
				System.out.print(k+" ");
				i++;
			}
			
			k=3-k;
		}
			
		
		
	}
}
