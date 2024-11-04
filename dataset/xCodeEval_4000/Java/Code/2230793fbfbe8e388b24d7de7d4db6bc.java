
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
 
public class SuffixArray {
    private static InputStream stream;
    private static byte[] buf = new byte[1024];
    private static int curChar;
    private static int numChars;
    private static SpaceCharFilter filter;
    private static PrintWriter pw;
    private static long max = Long.MIN_VALUE;
    private static long asd=1;
    private static long mod = 1000000000+7;
    private static long mod1=(long) Math.pow(2,63);
    static int[] arr1;
    private static void soln() {
    	long ts=nextLong();
		long te=nextLong();
		long t=nextLong();
		int n=nextInt();
		if(n==0){
			System.out.println(ts);
			System.exit(0);
		}
		long min=Long.MAX_VALUE;
		long time=te;
		long[] arr=new long[n];
		for(int i=0;i<n;i++)
			arr[i]=nextLong();
		long t1=-1;
		if(arr[0]!=0 && arr[0]<=te){
			if(arr[0]>ts)
				min=0;
			else
				min=ts-(arr[0]-1);
			time=arr[0]-1;
		}
		if(arr[0]>ts && arr[0]<te)
			ts=arr[0];
		int i;
		for(i=0;i<n-1;i++){
			long x=arr[i];
			long y=arr[i+1];
			if((ts+t)>te)
				break;
			if(x<ts){
				ts+=t;
			}else{
				ts=(x+t);
			}
			if(x!=y){
				long diff=ts-(y-1);
				if(min>diff){
					min=diff;
					time=y-1;
				}
			}
		}
		if(i==n-1 && (ts+2*t)<=te && i!=0){
			pw.println(ts+t);
		}else if(i==0 && arr[0]>te)
			pw.println(ts);
		else if(min==Long.MAX_VALUE)
			pw.println(-1);
		else{
			pw.println(time);
		}
    }
    public static class Box implements Comparable<Box>{
    	String s;
    	public Box(String s1){
    		s=s1;
    	}
		@Override
		public int compareTo(Box arg0) {
			for(int i=0;i<Math.min(s.length(),arg0.s.length());i++){
				if(s.charAt(i)!=arg0.s.charAt(i))
					return s.charAt(i)-arg0.s.charAt(i);
			}
			return s.length()-arg0.s.length();
		}
    }
    public static int BFS(String s,LinkedList<Integer>[] l){
    	int ans=0;
    	boolean[] visited=new boolean[s.length()];
    	for(int i=0;i<s.length();i++){
    		if(!visited[i]){
    			int[] freq=new int[26];
    			visited[i]=true;
    			visited[s.length()-i-1]=true;
    			Queue<Integer> q=new PriorityQueue();
    			q.add(i);
    			q.add(s.length()-i-1);
    			while(!q.isEmpty()){
    				int ind=q.poll();
    				

    				freq[s.charAt(ind)-'a']++;
    				Iterator<Integer> it=l[s.charAt(ind)-'a'].listIterator();
    				while(it.hasNext()){
    					int x=it.next();
    					if(!visited[x]){
    						visited[x]=true;
    						visited[s.length()-x-1]=true;
    						q.add(x);
    						if((s.length()-x-1)!=x)
    							q.add(s.length()-x-1);
    					}
    				}
    			}
    			int max=Integer.MIN_VALUE;
    			for(int j=0;j<26;j++){
    				max=Math.max(max,freq[j]);
    				ans+=freq[j];
    				System.out.println(freq[j]);
    			}
    			ans-=max;
    		}
    	}
    	return ans;
    }
    public static int fun(Node root,int xor){
    	Node tmp=root;
    	int temp=xor;
    	int[] arr=new int[28];
    	for(int i=0;i<=27;i++){
    		arr[i]=temp%2;
    		temp=temp/2;
    	}
    	for(int i=27;i>=0;i--){
    		int val= arr[i];
    		if(tmp.arr[1-val]!=null)
    			tmp=tmp.arr[1-val];
    		else if(tmp.arr[val]!=null)
    			tmp=tmp.arr[val];
    	}
    	return xor^(tmp.val);
    }
    public static void insert(Node root,int xor){
    	Node temp=root;
    	int tmp=xor;
    	int[] arr=new int[28];
    	for(int i=0;i<=27;i++){
    		arr[i]=tmp%2;
    		tmp=tmp/2;
    	}
    	for(int i=27;i>=0;i--){
    		int val= arr[i];
    		if(temp.arr[val]==null){
    			temp.arr[val]=new Node();
    		}
    		temp=temp.arr[val];
    	}
    	temp.val=xor;
    }
    public static class Node{
    	int val;
    	Node[] arr;
    	public Node(){
    		arr=new Node[2];
    		val=0;
    		arr[1]=null;
    		arr[0]=null;
    	}
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
	
    private static void DFS(int cur,int prev,LinkedList<Integer>[] l,long[][] ans){
    	Iterator<Integer> i=l[cur].listIterator();
    	long tmp1=1;
    	long tmp2=1;
    	long tmp3=1;
    	long tmp4=1;
    	long tmp5=1;
    	long tmp6=1;
    	long tmp7=1;
    	long tmp8=1;
    	while(i.hasNext()){
    		int x=i.next();
    		if(x!=prev){
    			DFS(x,cur,l,ans);
	    		tmp1=(tmp1*(ans[x][0]+ans[x][3])%mod)%mod;
	    		tmp5=(tmp5*ans[x][3])%mod;
	    		tmp2=(tmp2*(ans[x][1]+ans[x][2])%mod)%mod;
	    		tmp6=(tmp6*ans[x][2])%mod;
	    		tmp3=(tmp3*(ans[x][0]+ans[x][1])%mod)%mod;
	    		tmp7=(tmp7*ans[x][0])%mod;
	    		tmp8=(tmp8*ans[x][1])%mod;
	    		tmp4=(tmp4*(ans[x][1]+ans[x][0])%mod)%mod;
	    		

	        	

	    		System.out.println(x+" "+cur+" "+tmp1+" "+tmp2+" "+tmp3+" "+tmp4+" "+tmp5+" "+tmp6);
    		}
    	}
    	tmp3=(tmp3-tmp7+mod)%mod;
    	tmp4=(tmp4-tmp8+mod)%mod;
    	if(cur==1){
			tmp1=(tmp1-tmp5+mod)%mod;
			tmp2=(tmp2-tmp6+mod)%mod;
		}
    	if(l[cur].size()<=1 && prev!=0){
    		ans[cur][0]=1;
    		ans[cur][1]=1;
    	}else{
    		ans[cur][0]=tmp1;
    		ans[cur][1]=tmp2;
    		ans[cur][2]=tmp3;
    		ans[cur][3]=tmp4;
    	}
    	

    }
	private static long mat_power(long[][] matrix,long n){
		long[][] temp={{1,1,1},{1,0,0},{0,0,2}};
		if(n==1)
			return 3;
		mat_power(matrix,n/2);
		matrix_multiplication(matrix,matrix);
		if(n%2!=0){
			matrix_multiplication(matrix,temp);
		}
		return (matrix[0][0]+2*matrix[0][2])%mod;
	}
	private static void matrix_multiplication(long[][] a,long[][] b){
		long[][] result=new long[3][3];
		
		result[0][0]=((a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0])%mod+(a[0][2]*b[2][0])%mod)%mod;
		result[0][1]=((a[0][0]*b[0][1])%mod+(a[0][1]*b[1][1])%mod+(a[0][2]*b[2][1])%mod)%mod;
		result[0][2]=((a[0][0]*b[0][2])%mod+(a[0][1]*b[1][2])%mod+(a[0][2]*b[2][2])%mod)%mod;
		result[1][0]=((a[1][0]*b[0][0])%mod+(a[1][1]*b[1][0])%mod+(a[1][2]*b[2][0])%mod)%mod;
		result[1][1]=((a[1][0]*b[0][1])%mod+(a[1][1]*b[1][1])%mod+(a[1][2]*b[2][1])%mod)%mod;
		result[1][2]=((a[1][0]*b[0][2])%mod+(a[1][1]*b[1][2])%mod+(a[1][2]*b[2][2])%mod)%mod;
		result[2][0]=((a[2][0]*b[0][0])%mod+(a[2][1]*b[1][0])%mod+(a[2][2]*b[2][0])%mod)%mod;
		result[2][1]=((a[2][0]*b[0][1])%mod+(a[2][1]*b[1][1])%mod+(a[2][2]*b[2][1])%mod)%mod;
		result[2][2]=((a[2][0]*b[0][2])%mod+(a[2][1]*b[1][2])%mod+(a[2][2]*b[2][2])%mod)%mod;
		a[0][0]=result[0][0];
		a[0][1]=result[0][1];
		a[0][2]=result[0][2];
		a[1][0]=result[1][0];
		a[1][1]=result[1][1];
		a[1][2]=result[1][2];
		a[2][0]=result[2][0];
		a[2][1]=result[2][1];
		a[2][2]=result[2][2];
	}
    private static long power(long x,long y,long mod){
    	long ans = 1;
		while(y>0){
			if(y%2==1){
			    if(ans>mod/x) return -1;
				ans*=x;
				y-=1;
			}
			else{
			    if(x>mod/x) return -1;
				x*=x;
				y/=2;
			}
		}
		return ans;
    }
    public static class Suffix implements Comparable<Suffix>{
        int index;
        int[] rank=new int[2];
        @Override
        public int compareTo(Suffix arg0){
            return (this.rank[0]==arg0.rank[0])?(this.rank[1]<arg0.rank[1]?-1:1):(this.rank[0]<arg0.rank[0]?-1:1);
        }   
    }
    private static int[] buildSuffix(String s,int n){
        Suffix[] arr=new Suffix[n];
        for(int i=0;i<n;i++)
            arr[i]=new Suffix();
        for(int i=0;i<n;i++){
            arr[i].index=i;
            arr[i].rank[0]=s.charAt(i)-'a';
            arr[i].rank[1]=((i+1)<n)?(s.charAt(i+1)-'a'):-1;
        }
        Arrays.sort(arr);
        

            

        int[] ind=new int[n];
        for(int k=4;k<2*n;k=k*2){
            int rank=0;
            int p_rank=arr[0].rank[0];
            arr[0].rank[0]=rank;
            ind[arr[0].index]=0;
            for(int i=1;i<n;i++){
                if (arr[i].rank[0] == p_rank && arr[i].rank[1] == arr[i-1].rank[1]) {
                    p_rank = arr[i].rank[0];
                    arr[i].rank[0] = rank;
                }
                else{
                    p_rank = arr[i].rank[0];
                    arr[i].rank[0] = ++rank;
                }
                ind[arr[i].index] = i;
            }
            for(int i=0;i<n;i++){
                int n_index=arr[i].index + k/2;
                arr[i].rank[1]=(n_index<n)?arr[ind[n_index]].rank[0] : -1;
            }
            Arrays.sort(arr);
        }
        int[] suffixArr=new int[n];
        for(int i=0;i<n;i++)
            suffixArr[i]=arr[i].index;
        return suffixArr;
    }
    private static long pow(long a, long b) {
        if (b == 0)
            return 1;
        long p = pow(a, b / 2);
        p = (p * p)%mod;
        return (b % 2 == 0) ? p : (a * p)%mod;
    }
    private static long gcd(long x, long y) {
        if (y == 0)
            return x;
        return gcd(y, x % y);
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
    	new Thread(null, new Runnable() {
			public void run() {
				try {
					InputReader(System.in);
			        pw = new PrintWriter(System.out);
			        soln();
			        pw.close();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}, "1", 1 << 26).start();
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
 
    private interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}
