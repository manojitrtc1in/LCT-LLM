		 					import java.math.BigInteger;
							import java.util.ArrayList;
							import java.util.Arrays;
						import java.util.Collection;
						import java.util.Collections;
						import java.util.Comparator;
						import java.util.HashMap;
							import java.util.Iterator;
						import java.util.LinkedList;
						import java.util.List;
						import java.util.Map;
					import java.util.Map.Entry;
					import java.util.PriorityQueue;
						import java.util.Scanner;
						import java.util.Set;
						import java.util.Stack;
						import java.io.BufferedReader; 
						import java.io.IOException; 
						import java.io.InputStreamReader; 
						import java.util.Scanner; 
						import java.util.StringTokenizer;
						import java.util.TreeMap;
						import java.util.TreeSet;
						
							public class Main {
							
								static FastReader sc= new FastReader();
								static List<Integer> C;
								static List<Integer> B;
							static	int mod=(int)1e9+9;
								static long dp[];
								static boolean prime[] = new boolean[100001]; 
								public static void main(String[] args) {

										int t=sc.nextInt();
										while(t-->0) {
									
									long z1=sc.nextInt();long o1=sc.nextInt();long t1=sc.nextInt();
									long z2=sc.nextInt();long o2=sc.nextInt();long t2=sc.nextInt();
									
									
									long total=2*Math.min(o2, t1);
									long f=Math.min(o2, t1);
									o2-=f;
									t1-=f;
									if(t1>0&&t2>0) {
										long j=t1;
										t1-=Math.min(t2, t1);
										t2-=Math.min(t2, j);

									}
							


									if(o1>0&&o2>0) {
										long j=o1;

										o1-=Math.min(o2, o1);
										o2-=Math.min(o2, j);

									}
								



									if(o1>0&&z2>0) {
										long j=o1;

										o1-=Math.min(z2, o1);
										z2-=Math.min(z2, j);

									}
									


									if(t2>0&&z1>0) {
										long j=t2;

										t2-=Math.min(z1, t2);
										z1-=Math.min(z1, j);

									}
									
								

									if(t2>0&&o1>0) {
										
										total-=2*Math.min(o1, t2);
									}
									
									
									System.out.println(total);
									
									
									
							
										}
								}
								
								
								 static final int MAXN = 100001; 
							       
								    

								    static int spf[] = new int[MAXN]; 
								       
								    

								    

								    

								    static void sieve() 
								    { 
								        spf[1] = 1; 
								        for (int i=2; i<MAXN; i++) 
								       
								            

								            

								            spf[i] = i; 
								       
								        

								        

								        for (int i=4; i<MAXN; i+=2) 
								            spf[i] = 2; 
								       
								        for (int i=3; i*i<MAXN; i++) 
								        { 
								            

								            if (spf[i] == i) 
								            { 
								                

								                for (int j=i*i; j<MAXN; j+=i) 
								       
								                    

								                    

								                    if (spf[j]==j) 
								                        spf[j] = i; 
								            } 
								        } 
								    } 
								        
								
							static	 void id4(int n) 
								    { 
								        

								        

								        

								        

								        for(int i=0;i<n;i++) 
								            prime[i] = true; 
								          
								        for(int p = 2; p*p <=n; p++) 
								        { 
								            

								            if(prime[p] == true) 
								            { 
								                

								                for(int i = p*p; i <= n; i += p) 
								                    prime[i] = false; 
								            } 
								        } 
								          
								        
								       

								    } 
								
								
								
								
								static long  solve(List<Integer> A,int n,long cost,int k,HashMap<Integer,  Integer> map) {
									

									

									if(dp[n]!=-1)return dp[n];
									if(n==0)return cost;
					

								

	
					
									if(map.containsKey(C.get(n-1))) {
										
										long addon=0l;
										if(map.get(C.get(n-1))==1)addon=2l;
										else addon=1l;
										
										map.put(C.get(n-1),map.get(C.get(n-1))+1);
										

										return dp[n]=Math.min(solve(A,n-1,cost+addon,k,map),solve(A, n-1,k+cost,k, new HashMap<Integer,Integer>(C.get(n-1),1)));
										
									}
									else {map.put(C.get(n-1), 1); return dp[n] =solve(A,  n-1, cost,k, map);
									}
									
								}
								
					
								
								
								
							static int id0(int A,  
					                       int B, int C)  
					{  
					          
					    

					    if (A == 0)  
					        return 0;  
					    if (B == 0)  
					        return 1;  
					      
					    

					    long y;  
					    if (B % 2 == 0) 
					    {  
					        y = id0(A, B / 2, C);  
					        y = (y * y) % C;  
					    }  
					      
					    

					    else 
					    {  
					        y = A % C;  
					        y = (y * id0(A, B - 1,  
					                             C) % C) % C;  
					    }  
					      
					    return (int)((y + C) % C);  
					}  
								
							static	int modulo(int a,int b,int c) {
								    long x=1;
								    long y=a;
								    while(b > 0){
								        if(b%2 == 1){
								            x=(x*y)%c;
								        }
								        y = (y*y)%c; 

								        b /= 2;
								    }
								    return (int) x%c;
								}
								
								 static int power(int x, int y, int p) 
								    { 
								        

								        int res = 1;      
								         
								        

								        

								        x = x % p;  
								  
								       if (x == 0) return 0; 

								  
								        while (y > 0) 
								        { 
								            

								            

								            if((y & 1)==1) 
								                res = (res * x) % p; 
								      
								            

								            

								            y = y >> 1;  
								            x = (x * x) % p;  
								        } 
								        return res; 
								    }
								static int N = 100000;  
							      
							    static int n; 

							      
							    

							    static int []tree = new int[2 * N]; 
										
								 static void build( int []arr)  
								    {  
								          
								        

								        for (int i = 0; i < n; i++)  
								            tree[n + i] = arr[i]; 
								          
								        

								        

								        for (int i = n - 1; i > 0; --i)  
								            tree[i] = tree[i << 1] + 
								                      tree[i << 1 | 1];  
								    } 
								      
								    

								    static void id3(int p, int value)  
								    {  
								          
								        

								        tree[p + n] = value; 
								        p = p + n; 
								          
								        

								        for (int i = p; i > 1; i >>= 1) 
								            tree[i >> 1] = tree[i] + tree[i^1]; 
								    } 
								      
								    

								    

								    static int query(int l, int r)  
								    {  
								        int res = 0; 
								          
								        

								        for (l += n, r += n; l < r; 
								                             l >>= 1, r >>= 1) 
								        { 
								            if ((l & 1) > 0)  
								                res += tree[l++]; 
								          
								            if ((r & 1) > 0)  
								                res += tree[--r]; 
								        } 
								          
								        return res; 
								    } 
								      
									
								
								
								static int a=1;
								
											
								
							static class decimal{
								int n;double d;
								public decimal(int n,double d) {
									
									this.n=n;
									this.d=d;
									

								}
							}
								
							static	boolean isPossible(List<Integer> C,int m,int k) {
									if(m==0)return false;
									for(int i=0;i<C.size();i++) {
										
										if(C.get(i)>m) {
											k-=C.get(i)/m;
										}
										if(k<0)return false;
									}
										return true;
									
									
								}
								  
								
								
								
								static boolean id5(int set[],  int n, int sum) 
						{ 
						

						

						

						boolean subset[][] = new boolean[sum + 1][n + 1]; 
						
						

						for (int i = 0; i <= n; i++) 
						subset[0][i] = true; 
						
						

						

						for (int i = 1; i <= sum; i++) 
						subset[i][0] = false; 
						
						

						

						for (int i = 1; i <= sum; i++) { 
						for (int j = 1; j <= n; j++) { 
						    subset[i][j] = subset[i][j - 1]; 
						    if (i >= set[j - 1]) 
						        subset[i][j] = subset[i][j] 
						                       || subset[i - set[j - 1]][j - 1]; 
						} 
						} 
						
						
						return subset[sum][n]; 
						} 
						
						
								
								
								static boolean search(ArrayList<Integer> a,int m,int h) {
									PriorityQueue<Integer> p=new PriorityQueue<Integer>(new Comparator<Integer>() {
											@Override
											public int compare(Integer o1, Integer o2) {
												

												return o2-o1;
											}
									});
									
									
									
									for(int i=0;i<m;i++) {
										p.add(a.get(i));
									}
									int c=0;
									

									while(!p.isEmpty()) {
										

						
										h-=p.poll();
										if(h<0)break;
										
										c++;
										
									

						
										if(!p.isEmpty()) {
										p.poll();
										c++;}
										
										
									}
								

									if(c!=m)return false;
									
									return true;
								}
							

								
								
								
								
								
								
								static boolean id1(long n) 
							    { 
							        if (n == 0) 
							            return false; 
							          
							        while (n != 1) 
							        { 
							            if (n % 2 != 0) 
							                return false; 
							            n = n / 2; 
							        } 
							        return true; 
							    } 
								
								 static boolean id2(double x)  
								    { 
								          
								        

								        

								        double sr = Math.sqrt(x); 
								      
								        

								        return ((sr - Math.floor(sr)) == 0); 
								    } 
								
								
								
								
								
								
							static	int binarySearch(ArrayList<Long> arr, int l, int r, long x,int key) 
							    { 
							        if (r >= l) { 
							            int mid =  (r + l) / 2; 
							

							            

							            

							  			
							            if (arr.get(mid) == x) 
							                return mid+1; 
							  
							            

							            

							            if (arr.get(mid) > x) {
							                return binarySearch(arr, l, mid - 1, x,key); 
							            }
							            

							            

							            key=mid+1;
							            return binarySearch(arr, mid + 1, r, x,key); 
							        } 
							  
							        

							        

							        return key; 
							    } 
								
								
								
								
								
								
								
								
							    static boolean isPrime(long n) 
							    { 
							         

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
								
								
									
							}
							
							class Sol {
								
								int value;int in;int i;
								Sol(int value,int in,int i){
									this.value=value;
									this.in=in;
									this.i=i;
								}
								
						}
					
					 class SegmentTree {
						
						SegNode st[];
						int n;
					

						public SegmentTree(int n) {
								this.n=n;
							

							st=new SegNode[4*n];
								
						}
						
						void init(long n) {
							
							for(int i=0;i<4*n;i++) {
								st[i]=new SegNode();
							}
							
						}
						
						void set(int i,long v,int x,int lx,int rx) {
							
							if(rx-lx==1) {
								st[x].sum=v;
								st[x].max=v;
								return ;
							}
							int m=lx+(rx-lx)/2;
							if(i<m) set(i,v,2*x+1,lx,m);
							else set(i,v,2*x+2,m,rx); 
							
							st[x].sum=st[2*x+1].sum+st[2*x+2].sum;
							long ma=Math.max(st[2*x+1].max,st[2*x+2].max);
								st[x].max=Math.max(ma,st[x].sum);
						}
						
						void set (int i,long v) {
							set(i,v,0,0,n);
						}
						
						long max=Integer.MIN_VALUE;
					long sum(int l,int r,int x,int lx,int rx) {
						if(lx>=r||l>=rx)return 0;
						if(lx>=l||rx<=r)return st[x].sum;
						
							int m=(rx+lx)/2;
							
							long s1=sum(l,r,2*x+1,lx,m);
							long s2=sum(l,r,2*x+2,m,rx); 	
							
							return max= Math.max(Math.max(Math.max(s1,s2),s1+s2),max);
							
						
						}
						long sum(int l,int r) {
							return sum(l,r,0,0,n);
						}
						
						
					
						
						
						
						
						
						
					
					}
						class SegNode{
							long max;long sum;
							public SegNode() {
								

								sum=0;
								max=Integer.MIN_VALUE;
								
							}
						}
							
							
							
							
