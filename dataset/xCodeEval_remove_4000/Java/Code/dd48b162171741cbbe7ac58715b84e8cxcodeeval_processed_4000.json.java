import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;
public class id6 implements Runnable{
 
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
	public static void main(String[] args) throws Exception {
	    new Thread(null, new id6(), "Main", 1<<26).start();
	  }
	public void run() {
		OutputStream outputStream =System.out;
	    PrintWriter out =new PrintWriter(outputStream);
	FastReader s=new FastReader();
	int t=s.nextInt();
	while(t>0) {
		int n=s.nextInt();
		boolean p1=true;
		boolean p2=true;
		long c1=0;
		long c2=0;
		long[] a=new long[n];
		for(int i=0;i<n;i++) {
			a[i]=s.nextLong();
			if(i!=0) {
				if(a[i]<a[i-1]) {
					p1=false;
				}else if(a[i]>a[i-1]) {
					p2=false;
				}
			}
		}
		if(n<=2) {
			System.out.println(0
					);
		}
		else if(p1 && p2) {
			System.out.println(0);
		}else if(p1 && !p2) {
			boolean p=true;
			for(int i=2;i<n;i++) {
				if((a[i]-a[i-1]) !=(a[i-1]-a[i-2])) {
					p=false;
					break;
				}
			}
			if(p) {
				System.out.println(0);
			}else {
				System.out.println(-1);
			}
		}else if(p2 && !p1) {
			boolean p=true;
			for(int i=2;i<n;i++) {
				if((a[i-1]-a[i]) !=(a[i-2]-a[i-1])) {
					p=false;
					break;
				}
			}
			if(p) {
				System.out.println(0);
			}else {
				System.out.println(-1);
			}
		}else {
			long c=0;
			long m=0;
			for(int i=1;i<n;i++) {
				if(a[i]>a[i-1]) {
					c=a[i]-a[i-1];	
				}
			}
			for(int i=1;i<n;i++) {
				if(a[i]<a[i-1]) {
					m=a[i-1]-a[i]+c;
				}
			}
			long[] v=new long[n];
			if(m<=a[0]) {
			System.out.println(-1);
			}else {
				v[0]=a[0];
				for(int i=1;i<n;i++) {
					v[i]=(v[i-1]+c)%m;
				}
				boolean p=true;
				for(int i=0;i<n;i++) {
					if(v[i]!=a[i]) {
						p=false;
						break;
					}
				}
				if(p) {
					System.out.println(m+" "+c);
				}else {
					System.out.println(-1);
				}
			}
		}
		
				
		t--;
		
	}
	
	
	out.close();
}








	static int y=0;
	static int z=0;


































	static boolean good(long[] a,long[] b,int n,long h,int k) {
		long sum=0;
	long d=h/2;
	long count1=0;
	long count2=0;
		return(sum<k);}
	static boolean good1(long[] a,long[] b,int n,long h,long k) {
		long sum=0;
		for(int i=0;i<n;i++) {
			if(a[i]>h) {
				sum+=0;
			}else if(b[i]<h){
				sum+=b[i]-a[i]+1;
			}else {
				sum+=h-a[i];
			}
		}
		return(sum<k);
	}
	static int c=0;
	static int u=0;
	static int[] par=new int[100001];
	static int max=Integer.MAX_VALUE;


	public static boolean bfs(int n,int k,int t) {
		Queue<pair> q=new LinkedList<>();
	q.add(new pair(1,-1,0));
	vis[1]=true;
	boolean p=false;
	while(!q.isEmpty()) {
		pair g=q.poll();
		


			for(int i=0;i<d[g.a].size();i++) {


				if( d[g.a].get(i).y<=t && !vis[d[g.a].get(i).x] && level[g.a]<k) {
					par[d[g.a].get(i).x]=g.a;
				   q.add(new pair(d[g.a].get(i).x,Math.max(g.b, d[g.a].get(i).y),g.c+1));
				   vis[d[g.a].get(i).x]=true;
				   level[d[g.a].get(i).x]=g.c+1;
				   }
			}


	}
		return (level[n]<=k);
	}
	static int[] level=new int[100001];
	public static boolean id5(int n,int k,int t) {
		Queue<pair3> q=new LinkedList<>();
		ArrayList<Integer > e=new ArrayList<>();
		e.add(1);
	q.add(new pair3(1,-1,0,e));
	out:while(!q.isEmpty()) {
		pair3 g=q.poll();
		if(g.a==n && g.c<=k && g.b==max) {
		System.out.println(g.c);
		for(int i=0;i<g.h.size();i++) {
			System.out.print(g.h.get(i)+" ");
		}


		break out;	
		}else {
			for(int i=0;i<d[g.a].size();i++) {
			   ArrayList<Integer> y=new ArrayList<>();
			   y.addAll(g.h);
			   y.add(d[g.a].get(i).x);
				q.add(new pair3(d[g.a].get(i).x,Math.max(g.b, d[g.a].get(i).y),g.c+1,y));
			}
		}
	}
		return ((max!=-1) && (max<=t));
	}
	public static class pair{
		private int a;
		private int b;
		private int c;
		pair(int a,int b,int c){
			this.a=a;
			this.b=b;
			this.c=c;
		}
	}
	public static class pair3{
		private int a;
		private int b;
		private int c;
		private ArrayList<Integer> h;
		pair3(int a,int b,int c,ArrayList<Integer> h){
			this.a=a;
			this.b=b;
			this.c=c;
			this.h=h;
		}
	}
	public static ArrayList<pair1>[] d=new ArrayList[100001];
		
	public static boolean[] vis=new boolean[100001];
	
	public static long se=1000000007;
	
	public static long[] fac=new long[500001];
	public static void id2() {
		fac[0]=1;
		fac[1]=1;
		for(int i=2;i<=500000;i++) {
			fac[i]=(fac[i-1]*i)%(se);
		}
	}






























































	static int[] dp1=new int[100001];
	static int[] dp2=new int[100001];
	public static void id0(int[] a) {
		int n=a.length;
		dp1[0]=1;
		int maximum=1;
		for(int i=1;i<n;i++) {
			int max=0;
			for(int j=0;j<i;j++) {
				if(a[i]>a[j]) {
					max=Integer.max(dp1[j], max);
				}
			}
			dp1[i]=max+1;


		}
		
	}
	public static void id3(int[] a) {
		int n=a.length;
		dp2[0]=1;
		int maximum=1;
		for(int i=n-1;i>=0;i--) {
			int max=0;
			for(int j=n-1;j>i;j--) {
				if(a[i]>a[j]) {
					max=Integer.max(dp2[j], max);
				}
			}
			dp2[i]=max+1;


		}


	}
	
































































































































	public static double[] merge_sort(double[] A, int start, int end) {
		if (end > start) {
			int mid = (end + start) / 2;
			double[] v = merge_sort(A, start, mid);
			double[] o = merge_sort(A, mid + 1, end);
			return (merge(v, o));
		} else {
			double[] y = new double[1];
			y[0] = A[start];
			return y;
		}
	}
	public static double[] merge(double a[], double b[]) {


		double[] temp = new double[a.length + b.length];
		int m = a.length;
		int n = b.length;
		int i = 0;
		int j = 0;
		int c = 0;
		while (i < m && j < n) {
			if (a[i] < b[j]) {
				temp[c++] = a[i++];
			
			} else {
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


















































































































































	public static long id1(long a,long b,long n) {
		long ans=0;
		long[][] mat=new long[2][2];
		if(n<=2) {
			if(n==1) {
				return a;
			}else {
				return b;
			}
		}else {
			n-=2;		
			mat[0][1]=mat[1][1]=mat[1][0]=1;
			mat[0][0]=0;
			long[][] res=id4(mat,2,n);
			ans+=((a*res[0][1])%(1000000007) +(b*res[1][1])%(1000000007))%(1000000007);
		}
		return ans;
	}
	public static long[][] id4(long[][] mat,int n,long m){
		long[][] a=new long[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(i==j) {
					a[i][j]=(long)1;
				}else {
					a[i][j]=0;
				}
			}
		}
		while(m>0) {
			if(m%2==0) {
				mul(mat,mat,n);
				m/=2;
			}else {
				mul(a,mat,n);
				m--;
			}
		}
		return a;
	}
	public static void mul(long[][] a,long[][] b,int n1){
		long[][] res=new long[n1][n1];
		for(int i=0;i<n1;i++) {
			for(int j=0;j<n1;j++) {
				for(int k=0;k<n1;k++) {
					long g=(a[i][k]%(1000000007))*(b[k][j]%(1000000007))%(1000000007);
					res[i][j]=(res[i][j]%(1000000007)+g)%(1000000007);
				}
			}
		}
		 for (int i = 0; i < n1; i++) {
	         for (int j = 0; j < n1; j++) {
	             a[i][j] = res[i][j];
	         }
	     }
	}
	
	static class pair1{
		private int x;
		private int y;
		pair1(int x,int y){
			this.x=x;
			this.y=y;
		}
	}
	
}