    

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
    		
    		int t=inp.nextInt();
    		loop:
    		while(t-->0) {
    			int n=inp.nextInt();
    			long k=inp.nextLong();
    			long l1=inp.nextLong();
    			long r1=inp.nextLong();
    			long l2=inp.nextLong();
    			long r2=inp.nextLong();
    			Pair p[]=new Pair[2];
    			p[0]=new Pair(l1,r1);
    			p[1]=new Pair(l2,r2);
    			Arrays.sort(p);
    			

    			

    			long gg=Long.MAX_VALUE;
    			for(int i=1;i<=n;i++) {
    				long already=0,rem=k,ans=Long.MAX_VALUE,at1cost=0;
    				
    				if(l1==l2 && r1==r2) {  

    				    already=(p[0].r-p[0].l)*i;
    					rem-=already;
    					if(rem<=0) {
    						out.println(0);
    						continue loop;
    					}else {
    					    ans=rem*2;
    					}
    				}else if(l1==l2) {                      

    					already=(p[0].r-p[0].l)*i;
    					rem-=already;
    					if(rem<=0) {
    						out.println(0);
    						continue loop;
    					}
    					at1cost=(p[1].r-p[0].r);
    					if(rem<=at1cost*i) {
    						ans=rem;
    					}else {
    						ans=at1cost*i;
    						rem-=at1cost*i;
    						ans+=rem*2;
    					}
    				}
    				else if(p[0].l<p[1].l && p[0].r>p[1].r){ 

    					already=(p[1].r-p[1].l)*i;
    					rem-=already;
    					if(rem<=0) {
    						out.println(0);
    						continue loop;
    					}
    					at1cost=(p[1].l-p[0].l)+(p[0].r-p[1].r);
    					if(rem<=at1cost*i) {
    						ans=rem;
    					}else {
    						ans=at1cost*i;
    						rem-=at1cost*i;
    						ans+=rem*2;
    					}
    				}else if(p[0].l<p[1].l && p[0].r<p[1].r && p[0].r>p[1].l){ 

    					

    					already=(p[0].r-p[1].l)*i;
    					rem-=already;
    					if(rem<=0) {
    						out.println(0);
    						continue loop;
    					}
    					at1cost=(p[1].l-p[0].l)+(p[1].r-p[0].r);
    					if(rem<=at1cost*i) {
    						ans=rem;
    					}else {
    						ans=at1cost*i;
    						rem-=at1cost*i;
    						ans+=rem*2;
    					}
    				}else if(p[0].r<=p[1].l){ 

    					

    					ans=(p[1].l-p[0].r)*i;
    					at1cost=(p[1].r-p[0].l);
    					if(rem<=at1cost*i) {
    						ans+=rem;
    					}else {
    						ans+=at1cost*i;
    						rem-=at1cost*i;
    						ans+=rem*2;
    					}
    				}
    				else { 

    					already= (p[1].r-p[1].l)*i;
    					rem-=already;
    					if(rem<=0) {
    						out.println(0);
    						continue loop;
    					}
    					at1cost=(p[1].l-p[0].l);
    					if(rem<=at1cost*i) {
    						ans=rem;
    					}else {
    						ans=at1cost*i;
    						rem-=at1cost*i;
    						ans+=rem*2;
    					}
    				}
    				gg=Math.min(gg, ans);
    			}
    			
    			
    			out.println(gg);
    		}
    		
    	}
    	
     
    	
    		
    	
    	
    		
    		

    		static class Pair implements Comparable<Pair> {
    			long l, r;
    			Pair () {}
    			Pair (long l_, long r_) {
    			    this.l = l_;
    			    this.r = r_;
    			}
    			@Override
    	        public int compareTo(Pair other) {
    	        	if(this.l==other.l) {
    	        		return Long.compare(this.r, other.r);
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