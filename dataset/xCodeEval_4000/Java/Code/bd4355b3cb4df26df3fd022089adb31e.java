											import java.math.BigInteger;
											import java.sql.Array;
										    import java.util.ArrayList;
											import java.util.Arrays;
											import java.util.Collection;
											import java.util.Collections;
											import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
		import java.util.HashSet;
		import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
													import java.util.Set;
													import java.util.Stack;
											import java.io.BufferedReader;
											import java.io.IOException;
											import java.io.InputStream;
											import java.io.InputStreamReader;
											import java.util.Scanner;
											import java.util.StringTokenizer;
											import java.util.TreeMap;
											import java.util.TreeSet;
										
											
											
											
											
											
											public class Main {
							
												
												static HashMap<Integer,Boolean>map;
												
											static long dp[];
											static 	boolean flag;
											
											static long mod=(long)(1e9+7);
												public static void main(String[] args) {
												StringBuilder ans=new StringBuilder();
												FastReader sc=new FastReader();
												
												int t=sc.nextInt();
												
												
												outer:while(t-->0) {
													
													int n=sc.nextInt();
													
													int eveb[]=new int [(int)(1e5)+1];
													int oddb[]=new int [(int)(1e5)+1];
													
													ArrayList<Integer>A=new ArrayList<Integer>();
													for(int i=0;i<n;i++) {
														
														A.add(sc.nextInt());
														
														
														if(i%2==0)
															++eveb[A.get(i)];
														else ++oddb[A.get(i)];
														
													}
													
													
													int evea[]=new int [(int)(1e5)+1];
													int odda[]=new int [(int)(1e5)+1];
													
													Collections.sort(A);
													for(int i=0;i<n;i++) {
														
														
														if(i%2==0)
															++evea[A.get(i)];
														else ++odda[A.get(i)];
														
													}	
													
													for(int i=0;i<=(int)(1e5);i++) {
														if(oddb[i]!=odda[i])
														{
															System.out.println("NO");
															continue outer;
														}
														if(eveb[i]!=evea[i])
														{
															System.out.println("NO");
															continue outer;
														}
													}
													
													
													System.out.println("YES");
												}
												}	
													
												
												
												
												
												static int getSum(int[] BITree, int index)
												{
												    int sum = 0; 

												 
												    

												    while (index > 0)
												    {
												        

												        sum += BITree[index];
												 
												        

												        index -= index & (-index);
												    }
												    return sum;
												}
												 
												

												

												

												

												

												static void updateBIT(int[] BITree, int n,
												                        int index, int val)
												{
												    

												    while (index <= n)
												    {
												        

												        BITree[index] += val;
												 
												        

												        index += index & (-index);
												    }
												}
												 
												

												static int getInvCount(int[] arr, int n)
												{
												    int invcount = 0; 

												 
												    

												    int maxElement = 0;
												    for (int i = 0; i < n; i++)
												        if (maxElement < arr[i])
												            maxElement = arr[i];
												 
												    

												    

												    

												    

												    int[] BIT = new int[maxElement + 1];
												    for (int i = 1; i <= maxElement; i++)
												        BIT[i] = 0;
												 
												    

												    for (int i = n - 1; i >= 0; i--)
												    {
												        

												        invcount += getSum(BIT, arr[i] - 1);
												        if(invcount%2!=0)flag=false;
												        

												        updateBIT(BIT, maxElement, arr[i], 1);
												    }
												 
												    return invcount;
												}	
												
												
												
												
												
												
												
												
												
												
												
												
												
												static int merge(int arr[], int temp[],
											            int left, int mid, int right)
											{
											    int inv_count = 0;
											 
											    
											    int i = left;
											     
											    
											    int j = mid;
											     
											    
											    int k = left;
											     
											    while ((i <= mid - 1) && (j <= right))
											    {
											        if (arr[i] <= arr[j])
											            temp[k++] = arr[i++];
											        else
											        {
											            temp[k++] = arr[j++];
											 
											            
											            inv_count = inv_count + (mid - i);
											        }
											    }
											 
											    
											    while (i <= mid - 1)
											        temp[k++] = arr[i++];
											 
											    
											    while (j <= right)
											        temp[k++] = arr[j++];
											 
											    
											    for (i=left; i <= right; i++)
											        arr[i] = temp[i];
											 
											    return inv_count;
											}
											 
											

											

											

											static int _mergeSort(int arr[], int temp[],
											                         int left, int right)
											{
											    int mid, inv_count = 0;
											    if (right > left)
											    {
											        

											        

											        

											        mid = (right + left)/2;
											 
											        
											        inv_count = _mergeSort(arr, temp,
											                                left, mid);
											                                 
											        inv_count += _mergeSort(arr, temp,
											                                mid+1, right);
											 
											        
											        inv_count += merge(arr, temp,
											                        left, mid+1, right);
											    }
											 
											    return inv_count;
											}
											 
												
												
												
											static	class Pair{
													int a;int b;
													
													Pair(int a,int b){
													
														this.a=a;
														this.b=b;
														
													}
													
													
												}
												
												
												
																				
											
												
												
												
												 static long gcd(int a, int b)
												    {
												      if (b == 0)
												        return a;
												      return gcd(b, a % b);
												    }			
													
												
												
												
												
												static void dfs(ArrayList<ArrayList<Integer>>adj,int v,boolean []visited,int t_in[],int low[],int timer,int parent) {
													
													
													visited[v]=true; 
													t_in[v]=low[v]=timer++;
													
													
													for(int u:adj.get(v)) {
														
														
													}
													
													
													
												}
												
												
									
												
												static long solve(String s,int p,int k,int n,int x,int y) {
													
													if(p>n)return 0;
													if(p<=0)return Integer.MAX_VALUE;
													
													if(dp[p]!=-1)return dp[p];
													
													if(s.charAt(p-1)!='1')
													return dp[p]= Math.min(y+solve(s,p+1,k,n-1,x,y), x+solve(s,p+k,k,n,x,y));
													
													else return  dp[p]=solve(s,p+k,k,n,x,y);
													
												}
												
												
												 static boolean isPrime(int n)
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
												  
												static long lcm(long a, long b)
											    {
											        return ((a / gcd(a, b))%mod * b%mod)%mod;
											    }
												   static long gcd(long a,long b)
												    {
												        if (a == 0)
												            return b%mod; 
												        return (gcd(b % a, a))%mod; 
												    }
												
									
												

												
											
												
												
												static void dfs(int v,boolean visited[],ArrayList<ArrayList<Integer>>adj,int div[],int t)
												{
													visited[v]=true;
													
													div[v]=t+1;
													for(int u:adj.get(v)) {
														
														
														
														if(!visited[u]) {
															dfs(u,visited,adj,div,(t+1)%2);
														}
														
													}
													
													
												}
												
												
												static class Helper{
													
													int a;int b;int t;
													public Helper(int a,int b) {
														

														
														this.a=a;
														this.b=b;
											
														
													
													}
													
													
												}
										
										
												
										
												
												
												
												
												

										
												
											
												
											
									
				

				

											
							
					
				static void solvedfs(ArrayList<ArrayList<Integer>>adj,int n,int v,int subt[],int subtAns[],boolean []visited) {
							
							
							int count=1;
							int ans=0;
							visited[v]=true;
							for(int u:adj.get(v)) {
								
								
								if(!visited[u])
								{
									

									subtAns[u]=Math.max(subtAns[u], subt[v]-subtAns[u]);
									
								solvedfs(adj, n, u, subt, subtAns, visited);			
								
								}
							}
							
						
							
							
							
							
							
						}
						
												
												
												
								static int dfs(ArrayList<ArrayList<Integer>>adj,int v,int subt[],int subtAns[],boolean []visited) {
								
									
									int count=0;
									int ans=0;
									visited[v]=true;
									for(int u:adj.get(v)) {
										
										
										if(!visited[u])
										{
											count+=ans;
											ans=Math.max(dfs(adj,u,subt,subtAns,visited),ans);
										}
									}
										subt[v]=count;
										subtAns[v]=ans;
										return ans+1;
										
									
									
									
									
									
								}
												
								
												
												
								static	int solve(ArrayList<ArrayList<Integer>>adj,int node,ArrayList<Integer>A)			
									{
										if(adj.get(node).size()==0)return 1;
										
										int count=0;
										for(int v:adj.get(node)) {
											
											count+=solve(adj,v,A);
											
										}
										
										A.set(node,count);
										return count+1;
										
										
										
									}
												
												
												
												
												
												
												
									static void dfs(String[]building,int i,int j,int n,int m, boolean visited[][]) {
										
										
										visited[i][j]=true;
										
										if(isValid(building,i+1,j,n,m,visited))
										{	visited[i+1][j]=true;
											dfs(building,i+1,j,n,m,visited);
										
										}
											if(isValid(building,i-1,j,n,m,visited))
										{
											visited[i-1][j]=true;
											dfs(building,i-1,j,n,m,visited);
										}
										 if(isValid(building,i,j+1,n,m,visited))
										{visited[i][j+1]=true;
											dfs(building,i,j+1,n,m,visited);
										}
												if(isValid(building,i,j-1,n,m,visited))
										{visited[i][j-1]=true;
											dfs(building,i,j-1,n,m,visited);
										}
										
										
										
										
									}
									static boolean isValid(String[]building,int i,int j,int n,int m, boolean visited[][])		
									{
										if(i==-1||j==-1||i==n||j==m||visited[i][j]||building[i].charAt(j)=='#')
											return false;
									return true;
									}
												
												
												
												
								static	void compute(boolean sieve[],int n) {
										
										for(int i=2;i<=n;i++) {
											if(sieve[i])continue;
											
											for(int j=2*i;j<n;j+=i)
											{
												sieve[j]=true;
											}
											
										}
											
										
										
									}
								
								static	void computeHs(boolean sieve[]) {
									int n=(int)(1e9-1e7+1);
									for(int i=1;i<n;i++) {
										if(sieve[i])continue;
										
										for(int j=2*i;j<n;j+=i)
										{
											sieve[j]=true;
										}
										
									}
									
								}
							
								
									
												
												
												static boolean isValid(StringBuilder s,int w) {
													if(w>s.length())return false;
													HashSet<Character>hs=new HashSet<Character>();
													int a[]=new int[3];
													
													for(int i=0;i<w;i++) {
													
														++a[s.charAt(i)-49];
														
													}
													
													if(a[0]>0&&a[1]>0&&a[2]>0)return true;
												
													int start=0;
													int end=w;
													
													while(end!=s.length()) {
														--a[s.charAt(start)-49];
														
															++a[s.charAt(end)-49];
														
																	start++;
																		end++;
																		if(a[0]>0&&a[1]>0&&a[2]>0)return true;
																				
													}
													return false;
													
													
													
												}
								
												
												
												
									
							
												
									static int find(int parent[],int i) {
										
										if(parent[i]==-1)return i;
										
										return parent[i]=find(parent,parent[i]);
										
									}
									static void union(int parent[],int rank[],int s1,int s2) {
										
										if(rank[s1]>=rank[s2]) {
											
											parent[s2]=s1;
											rank[s1]+=rank[s2];
										}
										
										else {
											
											parent[s1]=s2;
											rank[s2]+=rank[s1];
										}
										
										
									}
												
												
												
												
												
												
												
												
												
												
												
									static	int solve(String S,int K) {
											
											if(K<=0)return 0;
											if(S.charAt(K-1)!=S.charAt(K))
											return 1+solve(S,K-1);
											else return solve(S,K-1);
										}
										
										
										
										
				
				
					
				static	boolean isValid(int g[][],int r,int c,int n,int m,boolean visited[][],int s) {
						if(r==-1||r==n||c==-1||c==m||visited[r][c]||g[r][c]!=s)return false;
						return true;
					}
				
										
											
																					
											
									    static class FastReader {
									        BufferedReader br;
									        StringTokenizer st;
									 
									        public FastReader()
									        {
									            br = new BufferedReader(
									                new InputStreamReader(System.in));
									        }
									 
									        String next()
									        {
									            while (st == null || !st.hasMoreElements()) {
									                try {
									                    st = new StringTokenizer(br.readLine());
									                }
									                catch (IOException e) {
									                    e.printStackTrace();
									                }
									            }
									            return st.nextToken();
									        }
									 
									        int nextInt() { return Integer.parseInt(next()); }
									 
									        long nextLong() { return Long.parseLong(next()); }
									 
									        double nextDouble()
									        {
									            return Double.parseDouble(next());
									        }
									 
									        String nextLine()
									        {
									            String str = "";
									            try {
									                str = br.readLine();
									            }
									            catch (IOException e) {
									                e.printStackTrace();
									            }
									            return str;
									        }
									    }
									 
										
											}
											
											
											
											
											    