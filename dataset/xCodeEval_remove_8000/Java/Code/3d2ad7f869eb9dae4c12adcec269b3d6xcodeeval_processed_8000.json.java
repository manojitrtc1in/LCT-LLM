

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
		
		int n=inp.nextInt();
		long nl=n;
		long a[]=new long[n];
		input(a,n);
		long sum=0;
		for(int i=0;i<n;i++) sum+=a[i];
		long x=sum;
		long minSum=(nl*(nl-1))/2;
		x-=minSum;
		long s2=0;
		long ans[]=new long[n];
		for(int i=0;i<n;i++) {
			ans[i]=(long)i;
			ans[i]+=x/nl;
			s2+=ans[i];
		}
		int i=0;
		while(s2!=sum) {
			ans[i++]++;
			s2++;
		}
		print(ans);
	}
	
	

	static void print(long a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) {
			out.print(a[i]+" ");
		}
	}
		
	
	
		
		

		static class Pair implements Comparable<Pair> {
			long l, r;
			int initIndex;
			Pair () {}
			Pair (long l_, long r_, int i) {
			    this.l = l_;
			    this.r = r_;
			    this.initIndex=i;
			}
			@Override
	        public int compareTo(Pair other) {
	        	if(this.l==other.l) {
	        		return Long.compare(other.initIndex,this.initIndex);
	        	}
				return Long.compare(this.l, other.l);
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
