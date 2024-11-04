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
	
	import java.util.BitSet;
	
	public class Main {
		private static InputStream stream;
		private static byte[] buf = new byte[1024];
		private static int curChar;
		private static int numChars;
		private static id6 filter;
		private static PrintWriter pw;
		private static long mod = 1000000000 + 7;
		private static int MAX=1000001;
		private static int block;
		private static void soln(){
			Stack<Integer> s=new Stack<>();
			int n=nextInt();
			StringBuilder sb=new StringBuilder();
			String[] s1=nextLine().split(" ");
			if((s1.length==1 ^ s1[0].equals("int"))){
				pw.println("Error occurred");
			}
			else{
				boolean f=true;
				if(s1[0].equals("int")){
					pw.println("int");
					f=false;
				}
				else{
					sb.append("pair<");
					s.push(0);
				}
				for(int i=1;i<s1.length;i++){
					if(s1[i].equals("int")){
						if(s.isEmpty()){
							pw.println("Error occurred");
							f=false;
							break;
						}
							int x=s.pop();
							while(!s.isEmpty() && x==2){
								x=s.pop();
								sb.append(">");
							}
							if(s.isEmpty() && x==2){
								pw.println("Error occurred");
								f=false;
								break;
							}
							if(x==1){
								sb.append(",int>");
							}else{
								s.push(x+1);
								sb.append("int");
							}
					}else{
						if(s.isEmpty()){
							pw.println("Error occurred");
							f=false;
							break;
						}
						int x=s.pop();
						while(!s.isEmpty() && x==2){
							x=s.pop();
							sb.append(">");
						}
						if(s.isEmpty() && x==2){
							pw.println("Error occurred");
							f=false;
							break;
						}
						if(x==1){
							sb.append(",pair<");
							s.push(x+1);
						}else{
							sb.append("pair<");
							s.push(x+1);
						}
						s.push(0);
					}
				}
				if(f){
					while(!s.isEmpty() && s.peek()==2){
						sb.append(">");
						s.pop();
					}
					if(!s.isEmpty())
						pw.println("Error occurred");
					else
						pw.println(sb.toString());
				}
			}
		}
		public static long bfs(LinkedList<Pair1>[] list,int cur,long cost,int x){
			if(cur==x+1)
				return cost;
			if(cur>x+1)
				return Long.MAX_VALUE;
			long temp=Long.MAX_VALUE;
			System.out.println(cur);
			for(Pair1 p:list[cur]){
				int r=p.i;
				long c=p.li;
				temp=Math.min(temp,bfs(list,r+1,cost+c,x));
			}
			return temp;
		}
		private static class Pair1 {
			int i;
			long li;
			public Pair1(int a,long b){
				i=a;li=i+b;
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
					m_tmp[sa[i]] = (tmp[sa[i-1]]==tmp[sa[i]] && tmp[(sa[i-1]+len>>1)%n]==tmp[(sa[i]+len>>1)%n]) ? m_tmp[sa[i-1]]:i;
				}
				int[] cnt=new int[n];
				for(int i=0;i<n;i++) cnt[i]=i;
				int[] sa_tmp=sa.clone();
				for(int i=0;i<n;i++){
					int s1=(sa_tmp[i]-len+n)%n;
					sa[cnt[m_tmp[s1]]++]=s1;
				}
			}
			return sa;
		}
		private static int[] id0(int[] sa,String s,int n){
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
		private static int[] id4(int[] sa,String s,int n){
			int[] ind=new int[n+1];
			for(int i=1;i<=n;i++)
				ind[sa[i]]=i;
			int[] lcp=new int[n+1];
			for(int i=1, k=0; i<=n; i++)
				if(ind[i] < n){
					for(int j=sa[ind[i]+1]; Math.max(i,j)+k <= n && s.charAt(i+k-1)==s.charAt(j+k-1);) k++;
					lcp[ind[i]]=k;
					if(k>0) k--;
				}
			return lcp;
		}
		static class Pair implements Comparable<Pair>{
			int i;
			int j;
			int ind;
			public Pair(int a,int b,int c){
				i=a;
				j=b;
				ind=c;
			}
			@Override
			public int compareTo(Pair arg0) {
				return this.i-arg0.i;
			}
		}
		public static class Segment {
		    private int[][] tree;
		    

		    private int size;
		    private int n;
		    private class node{
		        private int a;
		        private int b;
		        private int c;
		        public node(int x,int y,int z){
		            a=x;
		            b=y;
		            c=z;
		        }
		    }
		    public Segment(int n){
		        

		        int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
		        size = 2 * (int) Math.pow(2, x) - 1;
		        tree=new int[size][2];
		        

		        this.n=n;
		        

		    }
		    
		    public String query(int j,int i){
		        return queryUtil(j,i,0,0,n-1);
		    }
		    private String queryUtil(int j,int i,int id,int l,int r){
		        int mid=l+(r-l)/2;
		        if(l==r){
		        	return l+" "+j;
		        }
		        long val1=((long)tree[(id<<1)|1][0])*((long)i)+(long)tree[2*id+1][1];
		        

		        if(val1>=j)
		        	return queryUtil(j,i,(id<<1)|1,l,mid);
		        else
		        	return queryUtil(j-(int)val1,i,2*id+2,mid+1,r);
		    }
		    
		    public void update(int i,int f,int val){
		    	updateUtil(i,f,val,0,0,n-1);
		    }
		    public void updateUtil(int i,int f,int val,int id,int l,int r){
		        if(l==r){
		        	tree[id][f]=val;
		        	return;
		        }
		        int mid=l+(r-l)/2;
		        

		        if(l<=i && i<=mid)
		        	updateUtil(i,f,val,2*id+1,l,mid);
		        else
		        	updateUtil(i,f,val,2*id+2,mid+1,r);
		        tree[id][f]=tree[2*id+1][f]+tree[2*id+2][f];
		        

		    }
		   
		}
		private static class DSU{
			int[] parent;
			public DSU(int n){
				parent=new int[n];
				for(int i=0;i<n;i++)
					parent[i]=i;
			}
			int find(int i){
		        while(parent[i] !=i){
		        	parent[i]=parent[parent[i]];
		        	i=parent[i];
		        }
		        return i;
		    }
			void Union(int x, int y){
		        int xset = find(x);
		        int yset = find(y);
		        parent[yset]=yset;
		        parent[xset] = yset;
		    }
		}
		public static class Merge {
		    public static void sort(long inputArr[]) {
		        int length = inputArr.length;
		        id5(inputArr,0, length - 1);
		    }
		    private static void id5(long[] arr,int lowerIndex, int higherIndex) {        
		        if (lowerIndex < higherIndex) {
		            int middle = lowerIndex + (higherIndex - lowerIndex) / 2;
		            id5(arr,lowerIndex, middle);
		            id5(arr,middle + 1, higherIndex);
		            mergeParts(arr,lowerIndex, middle, higherIndex);
		        }
		    }
		    private static void mergeParts(long[]array,int lowerIndex, int middle, int higherIndex) {
		        long[] temp=new long[higherIndex-lowerIndex+1];
		        for (int i = lowerIndex; i <= higherIndex; i++) {
		            temp[i-lowerIndex] = array[i];
		        }
		        int i = lowerIndex;
		        int j = middle + 1;
		        int k = lowerIndex;
		        while (i <= middle && j <= higherIndex) {
		            if (temp[i-lowerIndex] < temp[j-lowerIndex]) {
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
	
		private static class Edge{
			int x;
			int y;
			int i;
			public Edge(int a,int b,int c){
				x=a; y=b;i=c;
			}
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
			int val;
			public Mo(int a,int b,int ind,int d) {
				l=a;r=b;i=ind;val=d;
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
	
		private static boolean id3(int c) {
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
			while (id1(c))
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
			} while (!id1(c));
			return res * sgn;
		}
	
		private static long nextLong() {
			int c = read();
			while (id1(c))
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
			} while (!id1(c));
			return res * sgn;
		}
	
		private static String nextToken() {
			int c = read();
			while (id1(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id1(c));
			return res.toString();
		}
	
		private static String nextLine() {
			int c = read();
			while (id1(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id3(c));
			return res.toString();
		}
	
		private static int[] id2(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
			}
			return arr;
		}
	
		private static long[] id7(int n) {
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
	
		private static boolean id1(int c) {
			if (filter != null)
				return filter.id1(c);
			return isWhitespace(c);
		}
		private static char nextChar() {
			int c = read();
			while (id1(c))
				c = read();
			char c1=(char)c;
			while(!id1(c))
				c=read();
			return c1;
	}
		private interface id6 {
			public boolean id1(int ch);
		}
	}