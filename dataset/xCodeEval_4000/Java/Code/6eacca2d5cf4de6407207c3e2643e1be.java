import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class cfs {
	private static InputStream stream;
	private static byte[] buf = new byte[1024];
	private static int curChar;
	private static int numChars;
	private static SpaceCharFilter filter;
	private static PrintWriter pw;
	private static long mod = 1000000000 + 7;
	private static long mod1 = 1000000000 + 9;
	private static int MAX=1000001;
	private static int block;
	private static void soln(){
		boolean[] vis=new boolean[1001];
		vis[2]=true;
		for(int p=3;p<=1000;p++)
		{
			int x=p;
			boolean flag=false;
			for(int j=2;j<=Math.sqrt(x);j++)
			{
				if(x%j==0)
				{
					int a=j;
					int b=x/j;
					if((gcd(a,b)==1))
					{
						flag=true;
						break;
					}
				}
			}
			if(flag)
				continue;
			else
			{
				vis[p]=true;
			}
		}
		int n=nextInt();
		if(n==1)
			pw.println("0");
		else
		{
			int count=0;
			for(int i=2;i<=n;i++)
			{
				if(vis[i])count++;
			}
			pw.println(count);
			for(int i=2;i<=n;i++)
			{
				if(vis[i])pw.print(i+" ");
			}
		}
	}
	public static class sieve{
		public static ArrayList<Integer> sieves(int n)
		{
			ArrayList<Integer> arr=new ArrayList<>();
			boolean[] bol=new boolean[n+1];
			Arrays.fill(bol, true);
			

			for(int i=2;i<=n;i++)
			{
				if(bol[i])
				{
					arr.add(i);
					for(int j=2;j*i<=n;j++)
					{
						bol[i*j]=false;
					}
				}
			}
			return arr;
		}
	}
	public static class isprime{
		public static boolean check(int n)
		{
			if(n==2)
				return true;
			else if(n==3)
				return true;
			else if(n%2==0)
				return false;
			else if(n%3==0)
				return false;
			else
			{
				for(int i=6;;i+=6)
				{
					if(i>Math.sqrt(n))
						break;
					if(n%(i-1)==0)
					{
						return false;
					}
					else if(n%(i+1)==0)
						return false;
									}
				return true;
			}
		}
	}
	private static class arti{
		public static void artis(boolean[] ap,int[] parent,int[] disc,int[] low,ArrayList<Integer>[] gr,boolean[] vis,int ver,int times)
		{
			vis[ver]=true;
			ArrayList<Integer> arr=gr[ver];
			disc[ver]=low[ver]=times+1;
			for(int i=0;i<arr.size();i++)
			{
				if(!vis[arr.get(i)])
				{
					parent[arr.get(i)]=ver;
					artis(ap,parent,disc,low,gr,vis,arr.get(i),times+1);
					low[ver]=Math.min(low[ver], low[arr.get(i)]);
					if(parent[ver]!=0 && low[arr.get(i)]>=disc[ver])
						ap[ver]=true;
					if(parent[ver]==0 && arr.size()>1)
						ap[ver]=true;
				}
				else if(parent[ver]!=i)
					low[ver]=Math.min(low[ver], disc[arr.get(i)]);
			}
		}
	}
	private static class dijkstra{
		public static int[] dijkstras(ArrayList<Pair>[] gr)
		{
			int n=gr.length-1;
			int[] dist=new int[n+1];
			Arrays.fill(dist, Integer.MAX_VALUE);
			
			PriorityQueue<Integer> dis=new PriorityQueue<>(n+1,
					new Comparator<Integer>()
					{
						public int compare(Integer p,Integer q)
						{
						return dist[p]-dist[q];
						}
					}
					);
			boolean[] vis=new boolean[n+1];
			Arrays.fill(vis, false);
			
			int s=1;
			dist[s]=0;
			dis.add(s);
			vis[s]=true;
			while(!dis.isEmpty())
			{
				int p=dis.poll();
				for(int i=0;i<gr[p].size();i++)
				{
					int y=gr[p].get(i).v;
					int w=gr[p].get(i).i;
					if(!vis[y])
					{
						dist[y]=dist[p]+w;
						dis.add(y);
						vis[y]=true;
					}
					else
					{
						if(dist[p]+w<dist[y])
						{
							dist[y]=dist[p]+w;
						}
					}
				}
			}
			return dist;
		}
	}
	private static class MST{
		public static void MSTa(int n,int m,Pair[] arr)
		{
			int sum=0;
			Arrays.sort(arr);
			DSU x=new DSU(n+1);
			for(int c=0;(c<m);c++)
			{
				Pair p=arr[c];
				

				

				int a=p.j.v;
				int b=p.j.i;
				int w=p.v;
				if(x.find(a)!=x.find(b))
				{
					sum+=w;
					x.Union(a, b);
				}
			}
			pw.println(sum);
		}
	}
	private static class DSU{
		int[] parent;
		int[] rank;
		int cnt;
		public DSU(int n){
			parent=new int[n];
			rank=new int[n];
			for(int i=0;i<n;i++){
				parent[i]=i;
				rank[i]=1;
			}
			cnt=n;
		}
		int find(int i){
	        while(parent[i] !=i){
	        	parent[i]=parent[parent[i]];
	        	i=parent[i];
	        }
	        return i;
	    }
		int Union(int x, int y){
	        int xset = find(x);
	        int yset = find(y);
	        if(xset!=yset)
	        	cnt--;
	        if(rank[xset]<rank[yset]){
	        	parent[xset] = yset;
		        rank[yset]+=rank[xset];
		        rank[xset]=0;
		        return yset;
	        }else{
	        	parent[yset]=xset;
	        	rank[xset]+=rank[yset];
	        	rank[yset]=0;
	        	return xset;
	        }
	    }
	}
	private static class Pair implements Comparable<Pair>{
		int v,i;Pair j;
		public Pair(int a,int b){
			v=a;
			i=b;
		}
		public Pair(int a,Pair b)
		{
			v=a;
			j=b;
		}
		@Override
		public int compareTo(Pair arg0) {
			return this.v-arg0.v;
		}
	}
private static int[] buildSuffix(String s,int n){
	Integer[] order=new Integer[n];
	for(int i=0;i<n;i++) order[i]=n-i-1;
	Arrays.sort(order,(a,b) -> Character.compare(s.charAt(a),s.charAt(b)));
	int[] sa=new int[n];
	int[] m_tmp=new int[n];
	for(int i=0;i<n;i++){
		sa[i]=order[i];
		m_tmp[i]=s.charAt(i);
	}
	for(int len=1;len<n;len<<=1){
		int[] tmp=m_tmp.clone();
		m_tmp[sa[0]]=0;
		for(int i=1;i<n;i++){
			m_tmp[sa[i]] = (tmp[sa[i-1]]==tmp[sa[i]] && sa[i-1] + len < n && 
							tmp[(sa[i-1]+(len>>1))]==tmp[(sa[i]+(len>>1))]) ? m_tmp[sa[i-1]]:i;
		}
		int[] cnt=new int[n];
		for(int i=0;i<n;i++) cnt[i]=i;
		int[] sa_tmp=sa.clone();
		for(int i=0;i<n;i++){
			int s1=sa_tmp[i]-len;
			if(s1>=0)
				sa[cnt[m_tmp[s1]]++]=s1;
		}
	}
	return sa;
}
private static int[] buildLCP(int[] sa,String s,int n){
	int[] ind=new int[n];
	for(int i=0;i<n;i++)
		ind[sa[i]]=i;
	int[] lcp=new int[n];
	for(int i=0, k=0; i<n; i++)
		if(ind[i] < n-1){
			for(int j=sa[ind[i]+1]; Math.max(i,j)+k < n && s.charAt(i+k)==s.charAt(j+k);) k++;
			lcp[ind[i]]=k;
			if(k>0) k--;
		}
	return lcp;
}
private static class Edge{
	int u,v;
	public Edge(int a,int b) {
		u=a;v=b;
	}
}
private static void shortestPath(LinkedList<Edge>[] l,int n,int k,int[] masks) {
	int tot=(int) Math.pow(2,k);
	int[][] dist=new int[n][tot];
	int[][] from=new int[n][tot];
	for(int i=0;i<n;i++)
		Arrays.fill(dist[i], Integer.MAX_VALUE);
	dist[0][masks[0]]=0;
	from[0][masks[0]]=-1;
	PriorityQueue<Long> q=new PriorityQueue<>();
	q.add((long) masks[0]);
	

	while(!q.isEmpty()) {
		long cur=q.poll();
		

		int u = ((int) cur)>>>10;
		int mask=(int) (cur&(tot-1));
		

		if((cur>>>32) != dist[u][mask])
			continue;
		

		Iterator<Edge> it=l[u].listIterator();
		while(it.hasNext()) {
			Edge e=it.next();
			int len=dist[u][mask]+e.v;
			if(dist[e.u][mask|masks[e.u]]>len) {
				

				dist[e.u][mask|masks[e.u]]=len;
				from[e.u][mask|masks[e.u]]=u;
				q.add(((long)len << 32)+(e.u<<10)+(mask|masks[e.u]));
			}
		}
	}
	int ans=Integer.MAX_VALUE;
	

	for(int i=0;i<tot;i++) {
		for(int j=0;j<tot;j++) {
			

			if((i|j) != (tot-1))
				continue;
			

			ans=Math.min(ans,Math.max(dist[n-1][i],dist[n-1][j]));
		}
	}
	pw.println(ans);
}
	
	public static class Merge {
	int cnt=0;
	public void sort(int inputArr[]) {
        int length = inputArr.length;
        doMergeSort(inputArr,0, length - 1);
    }
    private void doMergeSort(int[] arr,int lowerIndex, int higherIndex) {         
        if (lowerIndex < higherIndex) {
            int middle = lowerIndex + (higherIndex - lowerIndex) / 2;
            doMergeSort(arr,lowerIndex, middle);
            doMergeSort(arr,middle + 1, higherIndex);
            mergeParts(arr,lowerIndex, middle, higherIndex);
        }
    }
    private void mergeParts(int[]array,int lowerIndex, int middle, int higherIndex) {
    	int[] temp=new int[higherIndex-lowerIndex+1];
        for (int i = lowerIndex; i <= higherIndex; i++) {
            temp[i-lowerIndex] = array[i];
        }
        int i = lowerIndex;
        int j = middle + 1;
        int k = lowerIndex;
        while (i <= middle && j <= higherIndex) {
            if (temp[i-lowerIndex] > temp[j-lowerIndex]) {
                array[k] = temp[i-lowerIndex];
                i++;
            } else {
                array[k] = temp[j-lowerIndex];
                j++;
                

            }
            k++;
        }
        while (i <= middle) {
            array[k] = temp[i-lowerIndex];
            k++;
            i++;
        }
        while(j<=higherIndex){
        	array[k]=temp[j-lowerIndex];
        	k++;
        	j++;
        }
        
    }
}
	
	static void multiply(long[][] a, long[][] b,long m){
		int n=a.length;
	    long[][] mul=new long[n][n];
	    for (int i = 0; i < n; i++){
	        for (int j = 0; j < n; j++){
	            mul[i][j] = 0;
	            for (int k = 0; k < n; k++)
	                mul[i][j] = (mul[i][j]+(a[i][k]*b[k][j])%m)%m;
	        }
	    }
	    for (int i=0; i<n; i++)
	        for (int j=0; j<n; j++)
	            a[i][j] =mul[i][j];
	}
	private static long pow(long a, long b, long c) {
		if (b == 0)
			return 1;
		long p = pow(a, b / 2, c);
		p = (p * p) % c;
		return (b % 2 == 0) ? p : (a * p) % c;
	}
	
	private static class Mo implements Comparable<Mo>{
		int l;
		int r;
		int i;
		public Mo(int a,int b,int ind) {
			l=a;r=b;i=ind;
		}
		@Override
		public int compareTo(Mo arg0) {
			int b1=this.l/block;
			int b2=arg0.l/block;
			return (b1!=b2)?(b1-b2):(this.r-arg0.r);
		}
	}

	private static long gcd(long n, long l) {
		if (l == 0)
			return n;
		return gcd(l, n % l);
	}

	private static long max(long a, long b) {
		if (a > b)
			return a;
		return b;
	}

	private static long min(long a, long b) {
		if (a < b)
			return a;
		return b;
	}

	public static void main(String[] args) throws Exception {
		new Thread(null,new Runnable(){
			@Override
			public void run() {
				
				InputReader(System.in);
				pw = new PrintWriter(System.out);
				
				soln();
				pw.close();
			}
		},"1",1<<26).start();
	}

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

	private static long[] nextLongArray(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextLong();
		}
		return arr;
	}

	private static void pArray(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static void pArray(long[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}
	private static char nextChar() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		char c1=(char)c;
		while(!isSpaceChar(c))
			c=read();
		return c1;
	}
	private interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}