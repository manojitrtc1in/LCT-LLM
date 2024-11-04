
 
import java.io.*;

import java.math.*;
import java.util.*;
import javax.print.attribute.SetOfIntegerSyntax;
 
public class Solution {
	private static InputStream stream;
	private static byte[] buf = new byte[1024];
	private static int curChar;
	private static int numChars;
	private static SpaceCharFilter filter;
	private static PrintWriter pw;
	private static long count = 0,mod=1000000007;
	private static TreeSet<Integer>ts[]=new TreeSet[200000];
 
	public static void main(String args[]) throws Exception {
		InputReader(System.in);
		pw = new PrintWriter(System.out);
		soln();
		pw.close();
	}
	private static boolean visited[];
	private static int par[];
	private static LinkedList<Integer>[] adj;
	private static void dfs(int start,int root) {
		visited[start]=true;
		par[start]=root;
		for(int i:adj[start]) {
			if(!visited[i]) {
				dfs(i,start);
			}
		}
	}
	private static void soln(){
		int a=nextInt(),b=nextInt(),x=nextInt(),y=nextInt(),z=nextInt();
		long ans=0;
		if((long)a<2*(long)x) {
			ans+=2*(long)x-a;
			a=0;
			

		}else {
			a=a-2*x;
		}
		if((long)b<3*(long)z) {
			ans+=3*(long)z-b;
			b=0;
			

		}else {
			b=b-3*z;
		}
		if(a<b) {
			y=y-a>0?y-a:0;
			b=b-a;
			a=0;
		}else {
			y=y-b>0?y-b:0;
			b=a-b;
			a=0;
		}
		if(y>b) {
			ans+=b+2*(y-b);
			

		}else{
			ans+=y;
			

		}
		pw.println(ans);
	}
	
	public static int bfsPair(int[][] arr,boolean[][] visited,int x1,int y1,int x2,int y2) {
		Queue<Pair> q=new LinkedList<Pair>();
		visited[x1][y1]=true;
		int level = 1;
		int increamenter=0;
		if(x1-1>=0)
		if(arr[x1-1][y1]==1) increamenter++;
		if(y1-1>=0)
		if(arr[x1][y1-1]==1) increamenter++;
		if(y1+1<arr[1].length)
		if(arr[x1][y1+1]==1) increamenter++;
		if(x1+1<arr.length)
		if(arr[x1+1][y1]==1) increamenter++;
		
		q.add(new Pair(x1,y1));
		int i=0;
		while(!q.isEmpty()) {
			Pair p=q.poll();
			

			int x=p.idx,y=p.val;
			if(x-1>=0 && y>=0 && x-1<arr.length && y<arr[1].length) {
				if(!visited[x-1][y] && arr[x-1][y]==1)
				q.add(new Pair(x-1,y));
				visited[x-1][y]=true;
			}
			if(x>=0 && y-1>=0 && x<arr.length && y-1<arr[1].length) {
				if(!visited[x][y-1] && arr[x][y-1]==1)
				q.add(new Pair(x,y-1));
				visited[x][y-1]=true;
			}
			if(x>=0 && y+1>=0 && x<arr.length && y+1<arr[1].length) {
				if(!visited[x][y+1] && arr[x][y+1]==1)
				q.add(new Pair(x,y+1));
				visited[x][y+1]=true;
			}
			if(x+1>=0 && y>=0 && x+1<arr.length && y<arr[1].length) {
				if(!visited[x+1][y] && arr[x+1][y]==1)
				q.add(new Pair(x+1,y));
				visited[x+1][y]=true;
			}
			if(x==x2 && y==y2) return level;

			if(increamenter==0) {
				level++;
				increamenter=q.size();
				
			}
			increamenter--;
		}
		return -1;
	}
	
	public static void bfs(ArrayList<Integer>[] gp, int s,boolean[] visited,int[] dist){
		Queue<Integer> qu=new LinkedList<Integer>();
		int level = 1;
		int increamenter;
		if(gp[s]!=null)
		increamenter=gp[s].size()+1;
		else return;
		visited[s]=true;
		qu.add(s);
		while(!qu.isEmpty()){
			int temp=qu.poll();
			

			increamenter--;
			dist[temp]=level*6;
			for(int i=0;i<gp[temp].size();i++){
				if(!visited[gp[temp].get(i)]){
					

					

					visited[gp[temp].get(i)]=true;
					qu.add(gp[temp].get(i));
					

				}
			}
			if(increamenter==0){
				level++;
				increamenter=qu.size();
				

			}
			
		}
	}
	static int maxSubArraySum(int a[])
    {
        int size = a.length;
        int max_so_far = Integer.MIN_VALUE, max_ending_here = 0;
 
        for (int i = 0; i < size; i++)
        {
            max_ending_here = max_ending_here + a[i];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }
	public static ArrayList<Integer> allprime(int n){
		ArrayList<Integer> arr=new ArrayList<Integer>();
		arr.add(2);
		for(int i=3;i<n;i=i+2){
			int flag=0;
			for(int j=0;j<arr.size();j++){
				if(i%arr.get(j)==0) {flag=1;break;}
			}
			if(flag==0) arr.add(i);
		}
		return arr;
	}
	public static int fact(int n){
		int ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%1000000007;
		return ans;
	}
	static class Pair implements Comparable<Pair>{
		 
		int idx,val;
		Pair(int idx,int val){
			this.idx=idx;
			this.val=val;
		}
		@Override
		public int compareTo(Pair o) {
			

		

 
		
			if(o.val<val){
				return 1;
			}
			if(o.val==val){
				return 0;
			}
			else{
				return -1;
			}
		}		
		@Override
		public String toString(){
			return "idx: "+Integer.toString(idx)+" val: "+Integer.toString(val);
		}
	}
	public static long gcd(long x, long y) {
		if (x % y == 0)
			return y;
		else
			return gcd(y, x % y);
	}
	private static int BinarySearch(int a[], int low, int high, int target) {
		if (low > high)
			return -1;
		int mid = low + (high - low) / 2;
		if (a[mid] == target)
			return mid;
		if (a[mid] > target)
			high = mid - 1;
		if (a[mid] < target)
			low = mid + 1;
		return BinarySearch(a, low, high, target);
	}
	
	public static String reverseString(String s) {
		StringBuilder sb = new StringBuilder(s);
		sb.reverse();
		return (sb.toString());
	}
	public static long pow(long n, long p, long m) {
		long result = 1;
		if (p == 0)
			return 1;
		if (p == 1)
			return n;
		while (p != 0) {
			if (p % 2 == 1)
				result *= n;
			if (result >= m)
				result %= m;
			p >>= 1;
			n *= n;
			if (n >= m)
				n %= m;
		}
		return result;
	}
	public static long pow(long n, long p) {
		long result = 1;
		if (p == 0)
			return 1;
		if (p == 1)
			return n;
		while (p != 0) {
			if (p % 2 == 1)
				result *= n;
			p >>= 1;
			n *= n;
		}
		return result;
	}
	public static int[] radixSort(int[] f) {
		int[] to = new int[f.length];
		{
			int[] b = new int[65537];
			for (int i = 0; i < f.length; i++)
				b[1 + (f[i] & 0xffff)]++;
			for (int i = 1; i <= 65536; i++)
				b[i] += b[i - 1];
			for (int i = 0; i < f.length; i++)
				to[b[f[i] & 0xffff]++] = f[i];
			int[] d = f;
			f = to;
			to = d;
		}
		{
			int[] b = new int[65537];
			for (int i = 0; i < f.length; i++)
				b[1 + (f[i] >>> 16)]++;
			for (int i = 1; i <= 65536; i++)
				b[i] += b[i - 1];
			for (int i = 0; i < f.length; i++)
				to[b[f[i] >>> 16]++] = f[i];
			int[] d = f;
			f = to;
			to = d;
		}
		return f;
	}
	public static int nextPowerOf2(final int a) {
		int b = 1;
		while (b < a) {
			b = b << 1;
		}
		return b;
	}
	public static boolean PointInTriangle(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
		int s = p2 * p5 - p1 * p6 + (p6 - p2) * p7 + (p1 - p5) * p8;
		int t = p1 * p4 - p2 * p3 + (p2 - p4) * p7 + (p3 - p1) * p8;
 
		if ((s < 0) != (t < 0))
			return false;
 
		int A = -p4 * p5 + p2 * (p5 - p3) + p1 * (p4 - p6) + p3 * p6;
		if (A < 0.0) {
			s = -s;
			t = -t;
			A = -A;
		}
		return s > 0 && t > 0 && (s + t) <= A;
	}
	public static float area(int x1, int y1, int x2, int y2, int x3, int y3) {
		return (float) Math.abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
	}
 
	public static boolean isPrime(int n) {
		

		if (n <= 1)
			return false;
		if (n <= 3)
			return true;
 
		

		

		if (n % 2 == 0 || n % 3 == 0)
			return false;
 
		for (int i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;
 
		return true;
	}
 
	

 
	static long sort(int a[])
	{  int n=a.length;
		int b[]=new int[n];	
		return mergeSort(a,b,0,n-1);}
	static long mergeSort(int a[],int b[],long left,long right)
	{ long c=0;if(left<right)
	 {   long mid=left+(right-left)/2;
		 c= mergeSort(a,b,left,mid);
		 c+=mergeSort(a,b,mid+1,right);
		 c+=merge(a,b,left,mid+1,right); }	
		return c;	 }
	static long merge(int a[],int  b[],long left,long mid,long right)
	{long c=0;int i=(int)left;int j=(int)mid; int k=(int)left;
	while(i<=(int)mid-1&&j<=(int)right)
	{ if(a[i]>a[j]) {b[k++]=a[i++]; }
	else	{ b[k++]=a[j++];c+=mid-i;}}
	while (i <= (int)mid - 1)   b[k++] = a[i++]; 
	while (j <= (int)right) b[k++] = a[j++];
	for (i=(int)left; i <= (int)right; i++) 
		a[i] = b[i];  return c;  }

	

	

 
	public static void InputReader(InputStream stream1) {
		stream = stream1;
	}
 
	private static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
 
	private static boolean isEndOfLine(int c) {
		return c == '\n' || c == '\r' || c == -1;
	}
 
	private static int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}
 
	private static int nextInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}
 
	private static long nextLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}
 
	private static String nextToken() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}
 
	private static String nextLine() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isEndOfLine(c));
		return res.toString();
	}
 
	private static int[] nextIntArray(int n) {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}
		return arr;
	}
 
	private static int[][] next2dArray(int n, int m) {
		int[][] arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = nextInt();
			}
		}
		return arr;
	}
 
	private static long[] nextLongArray(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextLong();
		}
		return arr;
	}
 
	private static void pArray(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			pw.print(arr[i] + " ");
		}
		pw.println();
		return;
	}
 
	private static void pArray(long[] arr) {
		for (int i = 0; i < arr.length; i++) {
			pw.print(arr[i] + " ");
		}
		pw.println();
		return;
	}
 
	private static void pArray(boolean[] arr) {
		for (int i = 0; i < arr.length; i++) {
			pw.print(arr[i] + " ");
		}
		pw.println();
		return;
	}
 
	private static boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}
 
	private interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}