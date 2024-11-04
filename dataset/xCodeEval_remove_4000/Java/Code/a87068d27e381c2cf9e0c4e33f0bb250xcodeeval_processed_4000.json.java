

import java.io.*;
import java.util.*; 
public class id0 {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;	
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);	
	public static void main(String args[]) {		    	
	   	id0 g=new id0();
	   	g.main();
	   	out.close();
	}	
	
	static boolean cycle=false;
	
	

	void main() {
		
		int n=inp.nextInt();
		int m=inp.nextInt();
		boolean e[]=new boolean[n];
		ArrayList<Integer> list1[]=new ArrayList[n];
		ArrayList<Integer> list2[]=new ArrayList[n];
		for(int i=0;i<n;i++) {
			list1[i]=new ArrayList<Integer>();
			list2[i]=new ArrayList<Integer>();
		}
		for(int i=0;i<m;i++) {
			int x=inp.nextInt()-1;
			int y=inp.nextInt()-1;
			list1[x].add(y);  

			list2[y].add(x);  

		}
		int vis[]=new int[n];
		for(int i=0;i<n;i++) {
			if(vis[i]==0) {
				dfs(i,list1,vis);
			}
		}
		
		if(cycle) {
			out.println(-1);
			return;
		}
		
		int id1[]=new int[n];
		int id2[]=new int[n];
		
		invoke(id2,list1,list2,n);
		invoke(id1,list2,list1,n);
		
		int gg=n;
		for(int i=0;i<n;i++) {
			if(id1[i]<i || id2[i]<i) {
				gg--;
				e[i]=true;
			}
		}
		out.println(gg);
		for(int i=0;i<n;i++) {
			out.print(e[i]?'E':'A');
		}
	}	
	
	static void dfs(int x ,ArrayList<Integer> list[], int vis[]) {
		vis[x]=1;
		for(int gg: list[x]) {
			if(vis[gg]==1) {
				cycle=true;
			}
			else if(vis[gg]!=2) {
				dfs(gg,list,vis);
			}
		}
		vis[x]=2;
	}
		
	static void invoke(int min[], ArrayList<Integer> list1[],ArrayList<Integer> list2[], int n) {
		
		Arrays.fill(min, n);
		int size[]=new int[n];
		for(int i=0;i<n;i++) {
			size[i]=list1[i].size();
		}
		Queue<Integer> q = new LinkedList<>();
		for(int i=0;i<n;i++) {
			if(size[i]==0) {
				min[i]=i;
				q.add(i);
			}
		}
		while(!q.isEmpty()) {
			int x=q.poll();
			min[x]=Math.min(min[x], x);
			for(int gg: list2[x]) {
				min[gg]=Math.min(min[gg], min[x]);
				size[gg]--;
				if(size[gg]==0) {
					q.add(gg);
				}
			}
		}
	}
		
		
		
		
		

	
	
	
	
		
		

	    static class Segment implements Comparable<Segment> {
			int l, r, initialIndex;
			Segment () {}
			Segment (int l_, int r_, int d_) {
			    this.l = l_;
			    this.r = r_;
			    this.initialIndex = d_;
			}
			@Override
			public int compareTo(Segment o) {
			    return l - o.l;
			}
	    }
	    
	    static class FastReader { 
	        BufferedReader br; 
	        StringTokenizer st; 
	  
	        public FastReader() { 
	            br = new BufferedReader(new InputStreamReader(System.in)); 
	        } 
	        String next() { 
	            while (st==null || !st.hasMoreElements()) { 
	                try { 
	                    st = new StringTokenizer(br.readLine()); 
	                } 
	                catch (IOException  e) { 
	                    e.printStackTrace(); 
	                } 
	            } 
	            return st.nextToken(); 
	        } 
	        int nextInt() { 
	            return Integer.parseInt(next()); 
	        } 
	        long nextLong() { 
	            return Long.parseLong(next()); 
	        } 
	        double nextDouble() { 
	            return Double.parseDouble(next()); 
	        } 
	        String nextLine() { 
	            String s=""; 
	            try { 
	                s=br.readLine(); 
	            } 
	            catch (IOException e) { 
	                e.printStackTrace(); 
	            } 
	            return s; 
	        } 
	    } 
	    
	    

	    static long gcd(long a, long b) { 
			return b==0?a:gcd(b,a%b);
		}
		static int gcd(int a, int b) { 
			return b==0?a:gcd(b,a%b);
		}
		

		public static void sort(long arr[], int start, int end) { 		
				if(start>=end)
					return;		
				int mid=(start+end)/2;
				sort(arr,start,mid);
				sort(arr,mid+1,end);
				merge(arr,start,mid,end);	
		}	
		private static void merge(long arr[], int start, int mid, int end) {		
				int i, j=mid+1,c=0;
				long temp[]= new long[end-start+1];
				for(i=start;i<=mid && j<=end;c++) {
					if(arr[i]<=arr[j]) {
						temp[c]=arr[i];
						i++;
					}
					else {
						temp[c]=arr[j];
						j++;
					}
				}
				while(i<=mid) {
					temp[c]=arr[i];
					i++;c++;
				}
				while(j<=end) {
					temp[c]=arr[j];
					j++;c++;
				}
				c=0;
				for(i=start;i<=end;i++,c++)
					arr[i]=temp[c];
		}
		
		void reverse(long[] A,int l,int r) {
	        int i=l,j=r-1;
	        while(i<j) {
	            long t=A[i];
	            A[i]=A[j];
	            A[j]=t;
	            i++;j--;
	        }
	    }
	    void reverse(int[] A,int l,int r) {
	        int i=l,j=r-1;
	        while(i<j) {
	            int t=A[i];
	            A[i]=A[j];
	            A[j]=t;
	            i++;j--;
	        }
	    }
	    
	    

		static void input(long a[], int n) {
			for(int i=0;i<n;i++) {
				a[i]=inp.nextLong();
			}
		}
		static void input(int a[], int n) {
			for(int i=0;i<n;i++) {
				a[i]=inp.nextInt();
			}
		}	
		static void input(String s[],int n) {
			for(int i=0;i<n;i++) {
				s[i]=inp.next();
			}
		}
		
}
