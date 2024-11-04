import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Map.Entry;




import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;


public class id1 implements Runnable{
public static int[] visited1=new int[1000001];
public static int[] visited2=new int[100001];
public static int[] visited3=new int[100001];
public static HashSet<Integer> points=new HashSet<>();
public static int[] level=new int[1000001];
public static int[] gf=new int[20000];
public static int[] col=new int[20000];
public static int[] a=new int[1000001];
public static int[] in=new int[1000001];
public static int[] low=new int[1000001];
public static Stack stack =new Stack<>();
public static int[] intstack=new int[100001];
public static ArrayList<Integer>[] forw=new ArrayList[1000001];
public static ArrayList<Integer>[] back=new ArrayList[1000001];
public static ArrayList<Integer>[] trav=new ArrayList[100001];
public static ArrayList<Integer>[] b=new ArrayList[1000001];
static int min_dist=Integer.MAX_VALUE;
static int id2=Integer.MAX_VALUE;
static int timer=1;
static long id0=0;
static int end=-1;
static int leng=0;
static boolean p=true;
















public static ArrayList<Integer> e11=new ArrayList<>();
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
 
public static boolean isPrime(int n) {
	for(int i=2;i*i<=n;i++) {
		if(n%i==0) {
			return false;
		}
	}
	return true;
}
public static boolean diff(int a,int b) {
	int cnt=0;
	while(a>0) {
		if(a%10!=b%10) {
			cnt++;
		}
		a/=10;
		b/=10;
	}
	if(cnt==1) {
		return true;
	}else {
		return false;
	}
}
public static void main(String[] args) throws Exception {
    new Thread(null, new id1(), "Main", 1<<26).start();
  }
public static class pair2{
	private int x;
	private int y;
	private int d;
  pair2(int x,int y,int d){
	  this.x=x;
	  this.y=y;
	  this.d=d;
	  
  }
}
public void run() {
	OutputStream outputStream =System.out;
    PrintWriter out =new PrintWriter(outputStream);
FastReader s=new FastReader();














































































































int t=s.nextInt();
while(t>0) {
	long a=s.nextLong();
	long b=s.nextLong();
	long ans=0;
	long x=1;
	for(int k=1;k*k<=a;k++) {
	     x++;
		long left=x;
		long right=b;
		while(left<=right) {
			long mid=(left+right)/2;
			long d=(mid+1)*k;
			if(d>a) {
				right=mid-1;
			}else {
				left=mid+1;
			}
					
		}
		if(right>=x) {
			ans+=(right-x+1)
					;
		}


	}
	out.println(ans);
	t--;
}
out.close();
}
public static long[] merge_sort(long[] A, int start, int end) {
	if (end > start) {
		int mid = (end + start) / 2;
	    long[] v = merge_sort(A, start, mid);
		long[] o = merge_sort(A, mid + 1, end);
		return (merge(v, o));
	} else {
		long[] y = new long[1];
		y[0] = A[start];
		return y;
	}
}
public static long[] merge(long a[], long b[]) {


	long[] temp = new long[a.length + b.length];
	int m = a.length;
	int n = b.length;
	int i = 0;
	int j = 0;
	int c = 0;
	while (i < m && j < n) {
		if (a[i] < b[j]) {
			temp[c++] = a[i++];
		}else {
			temp[c++] = b[j++];
		}
	}
	while (i < m) {
		temp[c++] = a[i++];
	}
	while (j < n) {
		temp[c++] = b[j++];
	}
	return temp;
}










































































































































































































































































































































































































































































































































































































































































































































}
	