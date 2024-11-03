

import java.io.*;
import java.util.*; 
public class _InVoker_ {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;	
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);	
	public static void main(String args[]) {		    	
	   	_InVoker_ g=new _InVoker_();
	   	g.main();
	   	out.close();
	}	
	
	

	void main() {
		
		int n=inp.nextInt();
		long a[]=new long[n];
		for(int i=0;i<n;i++) {
			a[i]=inp.nextLong();
		}
		long bit[][]=new long[n][20];
		long bit2[][]=new long[n][20];
		for(int i=0;i<n;i++) {
			long x=a[i];
			int c=19;
			while(x>0) {
				bit[i][c--]=x%2;
				x/=2;
			}
		}
		int count[]=new int[20];
		for(int i=0;i<20;i++) {
			for(int j=0;j<n;j++) {
				if(bit[j][i]==1) {
					count[i]++;
				}
			}
		}
		for(int i=0;i<20;i++) {
			int c=0;
			while(count[i]-->0) {
				bit2[c++][i]=1;
			}
		}
		long gg=0;
		for(int i=0;i<n;i++) {
			long x=get(bit2[i]);
			gg+=x*x;
		}
		out.println(gg);
		
	}
	
	static void work(long a[], long b[]) {
		for(int i=0;i<20;i++) {
			if(a[i]==1 && b[i]==0) {
				b[i]=1;
				a[i]=0;
			}
		}
	}
	
	static long get(long a[]) {
		long gg=0;
		long mul=1;
		for(int i=19;i>=0;i--) {
			if(a[i]==1) {
				gg+=mul;
			}
			mul*=2;
		}
		return gg;
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
