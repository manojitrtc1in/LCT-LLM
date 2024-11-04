import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.ObjectInputStream.GetField;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.SortedSet;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

import org.omg.CORBA.Principal;

public class Q21 {
	static long MOD = 1000000007;
	static boolean b[],c1 = false;;
	static long a,bo,c,di;
	static ArrayList<Integer>[] amp;
	static ArrayList<Integer>[][] amp2;
	static int sum[],dist[];
	static long pow[],ans = 0;
	static int p = 10000,time = 0,p1=-1,p2=-1;
	static FasterScanner sc = new FasterScanner();
	static Queue<Integer> q = new LinkedList<>();
	

	static int arr[];
	static ArrayList<Integer> parent = new ArrayList<>();
	static BufferedWriter log;
	static HashMap<Pair,Integer> hm;
	static HashSet<Integer> hs = new HashSet<>();
	static TreeMap<Integer,Pair> hsm;
	static Stack<Integer> s = new Stack<>();
	static Pair prr[];
	public static void main(String[] args) throws IOException {
		log = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = sc.nextInt();
		arr = sc.nextIntArray(n);
		SegmentTree[] st = new SegmentTree[20];
		for(int i = 0; i<20;i++){
			st[i] = new SegmentTree(n, i);
		}
		int m = sc.nextInt();
		while(m-->0){
			int t = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt();
			if(t==1){
				long ans =0;
				for(int i = 0; i< 20;i++){
					ans += 1L*st[i].queryRange(1, 0, n-1, l-1, r-1)*Math.pow(2, i);
				}
				log.write(ans+"\n");
				

			}
			else{
				int x = sc.nextInt();
				for(int i = 0; i< 20; i++){
					if((x&(1<<i))!=0) st[i].updateRange(1, 0, n-1, l-1, r-1, 1);
				}
			}
		}
		log.close();
	}

	public static void bfs(int x){
		b[x] = true;
		q.add(x);
		while(!q.isEmpty()){
			int y = q.poll();
			for(int i = 0;i<amp[y].size();i++) {
				if(!b[amp[y].get(i)]){
					q.add(amp[y].get(i));
					dist[amp[y].get(i)] = dist[y]+1;
					b[amp[y].get(i)] = true;
				}
			}
		}
	}
		
	public static void seive(long n){
		b = new boolean[(int) (n+1)];
		Arrays.fill(b, true);
		b[0] = false;
		b[1] = false;
		for(int i = 2;i*i<=n;i++){
			if(b[i]){
				for(int p = 2*i;p<=n;p+=i){
					b[p] = false;
				}
			}
		}
	}
	public static void buildGraph(int n){
		for(int i =0;i<n;i++){
			int x = sc.nextInt(), y = sc.nextInt();
			amp[--x].add(--y);
			amp[y].add(x);
		}
	}
	public static void dfs(int x){
		b[x] = true;
		for(int i =0 ;i<amp[x].size();i++){
			if(!b[amp[x].get(i)]){
				dfs(amp[x].get(i));
			}
			sum[amp[x].get(i)]++;
		}
	}
	public static void multiBfs(){
		

		while(!q.isEmpty()){
			int x = q.poll();
			for(int e:amp[x]){
				if(!b[e]){
				q.add(e);
				b[e] = true;
				sum[e] = x;
				}
				else{
					if(!hs.contains(x) && e!=sum[x]){
						System.out.println("NO");
						System.exit(0);
					}
				}
			}
		}
	}
	public static void getCycle(int x){
		b[x] = true;
		for(int e:amp[x]){
			if(b[e]){
				p2 = x;
				if(e!=sum[x]){
					p1 = e;
					c1 = true;
					return;
				}
			}
			else{
				sum[e] = x;
				

				getCycle(e);
				if(c1) return;
			}
		}
		if(c1) return;
	}
	public static long count(long x,boolean b,long ans){
		String str = Long.toString(x,2);
		if(x==1) return (ans+1)%MOD;
		if(x==0 && b) return (ans+1)%MOD;
		else if(x==0) return ans;
		if(str.length()>1)
		ans= (long) ((ans+ Math.pow(2, str.length()-2)%MOD)%MOD);
		return count((long) (x-Math.pow(2, str.length()-1)),!b,ans);
	}
	static boolean KMP(String pat, String txt)
    {
        int M = pat.length();
        int N = txt.length();
 
        

        

        int lps[] = new int[M];
        int j = 0;  

 
        

        

        computeLPSArray(pat,M,lps);
 
        int i = 0;  

        while (i < N)
        {
            if (pat.charAt(j) == txt.charAt(i))
            {
                j++;
                i++;
            }
            if (j == M)
            {

                j = lps[j-1];
                return true;
            }
 
            

            else if (i < N && pat.charAt(j) != txt.charAt(i))
            {
                

                

                if (j != 0)
                    j = lps[j-1];
                else
                    i = i+1;
            }
        }
        return false;
    }
 static void computeLPSArray(String pat, int M, int lps[])
    {
        

        int len = 0;
        int i = 1;
        lps[0] = 0;  

 
        

        while (i < M)
        {
            if (pat.charAt(i) == pat.charAt(len))
            {
                len++;
                lps[i] = len;
                i++;
            }
            else  

            {
                

                

                

                if (len != 0)
                {
                    len = lps[len-1];
 
                    

                    

                }
                else  

                {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }
	static long power(long x, long y, long m)
	{
	    if (y == 0)
	        return 1;
	    long p = power(x, y/2, m) % m;
	    p = (p * p) % m;
	 
	    return (y%2 == 0)? p : (x * p) % m;
	}
	private static void permutation(String prefix, String str) {
	    int n = str.length();
	   

	   

	        for (int i = 0; i < n; i++)
	            permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
	    

	}
	public static char give(char c1,char c2){
		if(c1!='a' && c2!='a') return 'a';
		if(c1!='b' && c2!='b') return 'b';
		return 'c';
	}
	static class Graph{
		int vertex;
		long weight;
	}
	public static void buildTree(int n){
		int arr[] = sc.nextIntArray(n);
		for(int i = 0;i<n;i++){
			int x = arr[i]-1;
			amp[i+1].add(x);
			amp[x].add(i+1);
		}
	}

		
	
	static class Pair implements Comparable<Pair> {
		int u;
		int v;
		public Pair(){
			
		}
		public Pair(int u, int v) {
			this.u = u;
			this.v = v;
		}
		
		public int hashCode() {
			int hu = (int) (u ^ (u >>> 32));
			int hv = (int) (v ^ (v >>> 32));
			return 31*hu + hv;
		}

		public boolean equals(Object o) {
			Pair other = (Pair) o;
			return (u == other.u && v == other.v);
		}

		public int compareTo(Pair other) {
			return Integer.compare(u, other.u) != 0 ? (Integer.compare(u, other.u)) : (Integer.compare(v, other.v));
		}
		
		public String toString() {
			return "[u=" + u + ", v=" + v + "]";
		}
	}
	static class SegmentTree{
		long st[];
		long lazy[];
		int id;
		SegmentTree( int n, int id){
			int size = 4*n;
			this.id = id;
			st = new long[size];
			lazy = new long[size];
			build(0,n-1,1);
		}
		long build(int ss, int se, int si){
			if(ss==se){
				st[si] = (arr[ss]&(1<<id))==0?0:1;
				return st[si];
			}
			int mid = (ss+se)/2;
			st[si] = build(ss,mid,si*2)+build(mid+1,se,si*2+1);
			return st[si];
		}
		void updateRange(int si, int ss, int se, int qs, int qe, int val){
			if(lazy[si]!=0){
				st[si] = (se - ss + 1) - st[si];
				if(ss!=se){
					lazy[si*2] ^= lazy[si];
					lazy[si*2+1] ^= lazy[si];
				}
				lazy[si] = 0;
			}
			if(ss>se || ss>qe || se<qs) return;
			if(ss>=qs && se<=qe){
				st[si] = (se - ss + 1) - st[si];
				if(ss!=se){
					lazy[si*2+1] ^= val;
					lazy[si*2] ^= val;
				}
				return;
			}
			int mid = (ss+se)/2;
			updateRange(2*si, ss, mid, qs, qe, val);
			updateRange(2*si+1, mid+1, se, qs, qe, val);
			st[si] = st[si*2+1]+st[si*2];
		}
		long queryRange(int si, int ss, int se, int qs, int qe){
			

			if(ss>se || ss>qe || qs>se){
				return 0;
			}
			if(lazy[si]!=0){
				st[si] = (se - ss + 1) - st[si];
				if(ss!=se){
					lazy[si*2+1] ^= lazy[si];
					lazy[si*2] ^= lazy[si];
				}
				lazy[si] = 0;  
			}
			if(ss>=qs && se<=qe) return st[si];
			int mid = (ss+se)/2;
			return queryRange(2*si, ss, mid, qs, qe) + queryRange(2*si+1, mid+1, se, qs, qe);
		}
		long getXor(int qs, int qe, int ss, int se, int si){
			if(qe<ss || qs>se){
				return 0;
			}
			if(qs<=ss && qe>=se) return st[si];
			int mid = (ss+se)/2;
            return getXor(qs,qe,ss,mid,2*si+1)^getXor(qs,qe, mid+1, se, 2*si+2);
		}
		void print(){
			for(int i = 0;i<st.length;i++){
				System.out.print(st[i]+" ");
			}
			System.out.println();
		}
	}
	static int convert(int x){
		int cnt = 0;
		String str = Integer.toBinaryString(x);
		

		for(int i = 0;i<str.length();i++){
			if(str.charAt(i)=='1'){
				cnt++;
			}
		}
		int ans = (int) Math.pow(3, 6-cnt);
		return ans;
	}
	static class Node2{
		Node2 left = null;
		Node2 right = null;
		Node2 parent = null;
		int data;
	}
	static class BinarySearchTree{
		Node2 root = null;
		int height = 0;
		int max = 0;
		int cnt = 1;
		ArrayList<Integer> parent = new ArrayList<>();
		HashMap<Integer, Integer> hm = new HashMap<>();
		public void insert(int x){
			Node2 n = new Node2();
			n.data = x;
			if(root==null){
				root = n;
			}
			else{
				Node2 temp = root,temp2 = null;
				while(temp!=null){
					temp2 = temp;
					if(x>temp.data) temp = temp.right;
					else temp = temp.left;
				}
				if(x>temp2.data) temp2.right = n;
				else temp2.left = n;
				n.parent = temp2;
				parent.add(temp2.data);
			}
		}
		public Node2 getSomething(int x, int y, Node2 n){
			if(n.data==x || n.data==y) return n;
			else if(n.data>x && n.data<y) return n;
			else if(n.data<x && n.data<y) return getSomething(x,y,n.right);
			else return getSomething(x,y,n.left);
		}
		public Node2 search(int x,Node2 n){
			if(x==n.data){
				max = Math.max(max, n.data);
				return n;
			}
			if(x>n.data){
				max = Math.max(max, n.data);
				return search(x,n.right);
			}
			else{
				max = Math.max(max, n.data);
				return search(x,n.left);
			}
		}
		public int getHeight(Node2 n){
			if(n==null) return 0;
			height = 1+ Math.max(getHeight(n.left), getHeight(n.right));
			return height;
		}
	}
	static long findDiff(long[] arr, long[] brr, int m){
		int i = 0, j = 0;
		long fa = 1000000000000L;
		while(i<m && j<m){
			long x = arr[i]-brr[j];
			if(x>=0){
				if(x<fa) fa = x;
				j++;
			}
			else{
				if((-x)<fa) fa = -x;
				i++;
			}
		}
		return fa;
	}
	public static long max(long x, long y, long z){
		if(x>=y && x>=z) return x;
		if(y>=x && y>=z) return y;
		return z;
	}
	
	
	static long modInverse(long a, long mOD2){
	            return  power(a, mOD2-2, mOD2);
	}
	
	static long power2(long x,BigInteger y,long m){
		long ans = 1;
		BigInteger two = new BigInteger("2");
		while(y.compareTo(BigInteger.ZERO)>0){
			if(y.getLowestSetBit()==y.bitCount()){
				x = (x*x)%MOD;
				y = y.divide(two);
			}
			else{
				ans = (ans*x)%MOD;
				y = y.subtract(BigInteger.ONE);
			}
		}
		return ans;
	}
	static BigInteger power2(BigInteger x, BigInteger y, BigInteger m){
		BigInteger ans = new BigInteger("1");
		BigInteger one  = new BigInteger("1");
		BigInteger two  = new BigInteger("2");
		BigInteger zero  = new BigInteger("0");
		while(y.compareTo(zero)>0){
			

			if(y.mod(two).equals(one)){
				ans = ans.multiply(x).mod(m);
				y = y.subtract(one);
			}
			else{
				x = x.multiply(x).mod(m);
				y = y.divide(two);
			}
		}
		return ans;
	}
	static BigInteger power(BigInteger x, BigInteger y, BigInteger m)
	{
	    if (y.equals(0))
	        return (new BigInteger("1"));
	    BigInteger p = power(x, y.divide(new BigInteger("2")), m).mod(m);
	    p = (p.multiply(p)).mod(m);
	 
	    return (y.mod(new BigInteger("2")).equals(0))? p : (p.multiply(x)).mod(m);
	}
	static long d,x,y;
	public static void extendedEuclidian(long a, long b){
		if(b == 0) {
	        d = a;
	        x = 1;
	        y = 0;
	    }
	    else {
	        extendedEuclidian(b, a%b);
	        int temp = (int) x;
	        x = y;
	        y = temp - (a/b)*y;
	    }
	}
	
	public static long gcd(long n, long m){
		if(m!=0) return gcd(m,n%m);
		else return n;
	}
	
	
	public static class FasterScanner {
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
 
		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = System.in.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
 
		public String nextLine() {
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
 
		public String nextString() {
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
 
		public long nextLong() {
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
 
		public int nextInt() {
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
	        
	    public int[] nextIntArray(int n) {
	        return nextIntArray(n, 0);
	    }
	    
	    public int[] nextIntArray(int n, int off) {
	    	int[] arr = new int[n + off];
	    	for (int i = 0; i < n; i++) {
	    		arr[i + off] = nextInt();
	    	}
	    	return arr;
	    }
	    
	    public long[] nextLongArray(int n) {
	    	return nextLongArray(n, 0);
	    }
        
		public long[] nextLongArray(int n, int off) {
		    long[] arr = new long[n + off];
		    for (int i = 0; i < n; i++) {
		        arr[i + off] = nextLong();
		    }
		    return arr;
		}
 
	    private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
 
		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}
}