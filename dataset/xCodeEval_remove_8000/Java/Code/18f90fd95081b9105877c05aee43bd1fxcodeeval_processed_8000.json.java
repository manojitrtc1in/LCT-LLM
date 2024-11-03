

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
	
	
	
	

	void main() {
		
		int t=inp.nextInt();
		while(t-->0) {
			int n=inp.nextInt();
			int x=inp.nextInt();
			int a[]=new int[n];
			int sum=0;
			boolean allGood=true;
			boolean xPres=false;
			for(int i=0;i<n;i++) {
				a[i]=inp.nextInt();
				if(a[i]!=x) allGood=false;
				else xPres=true;
				sum+=a[i];
			}
			if(allGood) out.println(0);
			else if(x*n==sum || xPres) out.println(1);
			else out.println(2);
		}
		
	}
	
	
	
	static class Pair implements Comparable<Pair> {
		long f, s;
		Pair () {}
		Pair (long l_, long r_) {
		    this.f = l_;
		    this.s = r_;
		}
		@Override
        public int compareTo(Pair other) {
        	if(this.f==other.f) {
        		return Long.compare(this.s,other.s);
        	}
			return Long.compare(this.f, other.f);
		}
    }

	static void print(long a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) {
			out.print(a[i]+" ");
		}
	}
		
	
	
	public class DSU {
        int n;
        int parent[];
        int totalSets;
        DSU(int n){
            this.n=n;
            parent=new int[n];
            for(int i=0;i<n;i++)parent[i]=i;
            totalSets=n;
        }
        int find(int i){
            int x=parent[i];
            if(x==i) return x;
            return parent[i]=find(x);
        }
        boolean union(int a, int b){
            int pa=find(a);
            int pb=find(b);
            if(pa==pb) return false;
            parent[pa]=pb;
            totalSets--;
            return true;
        }
    }
	
	class SegTree {
		int n;
		int seg[];
		SegTree(int n){
			this.n=n;
			seg=new int[4*n];
		}
		void build(int x,int lx, int rx) {
			if(lx==rx) {
				seg[x]=0;
				return;
			}
			int mid=lx+rx>>1;
			build(2*x,lx,mid);
			build(2*x+1,mid+1,rx);
			seg[x]=merge(seg[2*x],seg[2*x+1]);
		}
		void set(int i) {
			set(i,1,0,n-1);
		}
		void set(int i, int x, int lx, int rx) {
			if(lx==rx) {
				seg[x]=1;
				return;
			}
			int mid=lx+rx>>1;
			if(i<=mid) set(i,2*x,lx,mid);
			else set(i,2*x+1,mid+1,rx);
			seg[x]=merge(seg[2*x],seg[2*x+1]);
		}
		int merge(int x, int y) {
			return x+y;
		}
		int query(int l, int r) {
			return query(l,r,1,0,n-1);
		}
		int query(int l, int r, int x, int lx, int rx) {
			if(l<=lx && r>=rx) return seg[x];
			if(l>rx || r<lx) return 0;
			int mid=lx+rx>>1;
			return merge(query(l,r,2*x,lx,mid),query(l,r,2*x+1,mid+1,rx));
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
				while(i<=mid) temp[c++]=arr[i++];
				while(j<=end) temp[c++]=arr[j++];
				c=0;
				while(start<=end) arr[start++]=temp[c++];
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
