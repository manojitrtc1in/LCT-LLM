

import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.Random;
import java.util.Arrays;
import java.util.StringTokenizer; 
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Collections;

public class C 
{ 
	static void solve(int arr[][],ArrayList<ArrayList<Integer>> steps) {
		for(ArrayList<Integer> s:steps) {
			int a=s.get(0)-1;
			int b=s.get(1)-1;
			arr[a][b]^=1;
			a=s.get(2)-1;
			b=s.get(3)-1;
			arr[a][b]^=1;
			a=s.get(4)-1;
			b=s.get(5)-1;
			arr[a][b]^=1;
			
		}
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr[0].length;j++)
				System.out.print(arr[i][j]+" ");
		System.out.println();
		}
		System.out.println();	
	}
	
	static 	ArrayList<ArrayList<Integer>> res;
	static int arr[][];
    public static void main(String[] args) 
	{ 
		FastReader sc=new FastReader(); 
		StringBuffer ans=new StringBuffer();
		int test=sc.nextInt();
		while(test-->0)
		{
			int n=sc.nextInt();
			int m=sc.nextInt();
			res=new ArrayList<>();
			char arr1[][]=new char[n][m];
			for(int i=0;i<n;i++)
				arr1[i]=sc.next().toCharArray();
			
			arr=new int[n][m];
			int brr[][]=new int[n][m];
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++)
					brr[i][j]=arr[i][j]=arr1[i][j]-'0';
			}
			
		
			for(int i=0;i<n-2;i++) {
				for(int j=0;j<m-1;j++) {
					if(arr[i][j] == 0) continue;
					ArrayList<Integer> temp=new ArrayList<>();
					temp.add(i+1);temp.add(j+1);
					if(arr[i][j+1] == 1) {
						arr[i][j+1]=0;
						temp.add(i+1);temp.add(j+1+1);
						
						if(arr[i+1][j] == 1) {
							arr[i+1][j]=0;
							temp.add(i+1+1);temp.add(j+1);
						}
						else {
							arr[i+1][j+1]^=1;
							temp.add(i+1+1);temp.add(j+1+1);
						}
					}
					else {
						arr[i+1][j]^=1;
						arr[i+1][j+1]^=1;
						temp.add(i+1+1);temp.add(j+1);
						temp.add(i+1+1);temp.add(j+1+1);
					}
					res.add(temp);
				}
				
				if(arr[i][m-1] == 0)continue;
				arr[i][m-1]=0;
				arr[i+1][m-1]^=1;
				arr[i+1][m-2]^=1;
				ArrayList<Integer> temp=new ArrayList<>();
				temp.add(i+1);temp.add(m);
				temp.add(i+1+1);temp.add(m);
				temp.add(i+1+1);temp.add(m-1);
				res.add(temp);
			}
			
			if(m%2 == 1) {
				if(arr[n-2][0] == 1) {
					ArrayList<Integer> temp=new ArrayList<>();
					temp.add(n-2+1);temp.add(0+1);
					temp.add(n-2+1);temp.add(1+1);
					temp.add(n-1+1);temp.add(0+1);
					res.add(temp);
					arr[n-2][0]=0;
					arr[n-2][1]^=1;
					arr[n-1][0]^=1;
				}
				if(arr[n-1][0] == 1) {
					ArrayList<Integer> temp=new ArrayList<>();
					temp.add(n-1+1);temp.add(0+1);
					temp.add(n-1+1);temp.add(1+1);
					temp.add(n-2+1);temp.add(1+1);
					res.add(temp);
					arr[n-2][1]^=1;
					arr[n-1][0]^=1;
					arr[n-1][1]^=1;
				}
			}
			
			
			int i=n-1;
			for(int j=(m%2 == 0?0:1);j<m-1;j+=2) {
				
				if(arr[i][j] == 0 && arr[i][j+1] == 0 && arr[i-1][j] == 0 && arr[i-1][j+1] == 0) continue;
				
				
				

				
				
				

				if(arr[i][j] == 0 && arr[i][j+1] ==1) {
					
					if(arr[i-1][j] == 0 && arr[i-1][j+1] == 0)
					{
						ink2(i,j);
					}
					else if(arr[i-1][j] == 0 && arr[i-1][j+1] == 1) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1);
						temp.add(i+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1+1);
						res.add(temp);
						arr[i][j] =1;
						arr[i-1][j+1]=arr[i][j+1]=0;
						ink1(i,j);
					}
					else if(arr[i-1][j] == 1 && arr[i-1][j+1] == 0) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1);
						temp.add(i+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1);
						res.add(temp);
						arr[i][j] =1;
						arr[i-1][j]=arr[i][j+1]=0;
						ink1(i,j);
					}
					else if(arr[i-1][j] == 1 && arr[i-1][j+1] == 1) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1);
						res.add(temp);
						arr[i][j]=arr[i-1][j]=arr[i][j+1]=arr[i-1][j+1]=0;
					}
				}
				
				
				

				
				if(arr[i][j] == 1 && arr[i][j+1] == 0) {
					
					if(arr[i-1][j] == 0 && arr[i-1][j+1] == 0)
					{
						ink1(i,j);
					}
					else if(arr[i-1][j] == 0 && arr[i-1][j+1] == 1) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1);
						temp.add(i+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1+1);
						res.add(temp);
						arr[i][j+1] =1;
						arr[i-1][j+1]=arr[i][j]=arr[i-1][j]=0;
						ink2(i,j);
					}
					else if(arr[i-1][j] == 1 && arr[i-1][j+1] == 0) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1);
						temp.add(i+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1);
						res.add(temp);
						arr[i][j+1] =1;
						arr[i-1][j+1]=arr[i][j]=arr[i-1][j]=0;
						ink2(i,j);
					}
					else if(arr[i-1][j] == 1 && arr[i-1][j+1] == 1) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1);
						temp.add(i-1+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1);
						res.add(temp);
						arr[i][j]=arr[i-1][j]=arr[i][j+1]=arr[i-1][j+1]=0;
					}
					
				}
				
				
				

				if(arr[i][j] == 1 && arr[i][j+1] ==1) {
					if(arr[i-1][j] == 0 && arr[i-1][j+1] == 0)
					{
						ink3(i,j);
					}
					else if(arr[i-1][j] == 0 && arr[i-1][j+1] == 1) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1);
						temp.add(i+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1+1);
						res.add(temp);
						arr[i][j+1] =0;
						arr[i-1][j+1]=arr[i][j]=arr[i-1][j]=0;
					}
					else if(arr[i-1][j] == 1 && arr[i-1][j+1] == 0) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1);
						temp.add(i+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1);
						res.add(temp);
						arr[i][j+1] =0;
						arr[i-1][j+1]=arr[i][j]=arr[i-1][j]=0;
					}
					else if(arr[i-1][j] == 1 && arr[i-1][j+1] == 1) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1);
						res.add(temp);
						arr[i][j]=1;
						arr[i-1][j]=arr[i][j+1]=arr[i-1][j+1]=0;
						ink1(i,j);
					}
				}
				
				

				
				if(arr[i][j] == 0 && arr[i][j+1] == 0) {
				   if(arr[i-1][j] == 0 && arr[i-1][j+1] == 1) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1);
						temp.add(i+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1+1);
						res.add(temp);
						arr[i][j+1] =arr[i][j]=1;
						arr[i-1][j+1]=arr[i-1][j]=0;
						ink3(i,j);
					}
					else if(arr[i-1][j] == 1 && arr[i-1][j+1] == 0) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1);
						temp.add(i+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1);
						res.add(temp);
						arr[i][j+1] =arr[i][j]=1;
						arr[i-1][j+1]=arr[i-1][j]=0;
						ink3(i,j);
					}
					else if(arr[i-1][j] == 1 && arr[i-1][j+1] == 1) {
						ArrayList<Integer> temp=new ArrayList<>();
						temp.add(i+1);temp.add(j+1);
						temp.add(i-1+1);temp.add(j+1+1);
						temp.add(i-1+1);temp.add(j+1);
						res.add(temp);
						arr[i][j]=1;
						arr[i-1][j]=arr[i][j+1]=arr[i-1][j+1]=0;
						ink1(i,j);
					}
				}
				


































				
			}
			ans.append(res.size()+"\n");
			for(ArrayList<Integer> t:res) {
				for(int ii:t)
					ans.append(ii+" ");
				ans.append("\n");
			}


		
		}
		
	    System.out.print(ans);
	} 
    
    static void ink1(int i,int j) {
    	
    	ArrayList<Integer> temp=new ArrayList<>();
		temp.add(i);temp.add(j+1);
		temp.add(i);temp.add(j+1+1);
		temp.add(i+1);temp.add(j+1);
		res.add(temp);
		temp=new ArrayList<>();
		temp.add(i+1);temp.add(j+1+1);
		temp.add(i+1);temp.add(j+1);
		temp.add(i);temp.add(j+1+1);
		res.add(temp);
		temp=new ArrayList<>();
		temp.add(i);temp.add(j+1);
		temp.add(i+1);temp.add(j+1+1);
		temp.add(i+1);temp.add(j+1);
		res.add(temp);
    	
		arr[i][j]=arr[i][j+1]=0;
    }
    
    static void ink2(int i,int j) {
    	
    	
    	ArrayList<Integer> temp=new ArrayList<>();
		temp.add(i+1);temp.add(j+1+1);
		temp.add(i);temp.add(j+1);
		temp.add(i);temp.add(j+1+1);
		
		res.add(temp);
		temp=new ArrayList<>();
		temp.add(i+1);temp.add(j+1+1);
		temp.add(i+1);temp.add(j+1);
		temp.add(i);temp.add(j+1+1);
		res.add(temp);
		temp=new ArrayList<>();
		temp.add(i);temp.add(j+1);
		temp.add(i+1);temp.add(j+1+1);
		temp.add(i+1);temp.add(j+1);
		res.add(temp);
		arr[i][j]=arr[i][j+1]=0;
    }
    
    static void ink3(int i,int j) {
    	
    	
    	ArrayList<Integer> temp=new ArrayList<>();
		temp.add(i+1);temp.add(j+1+1);
		temp.add(i);temp.add(j+1);
		temp.add(i);temp.add(j+1+1);
		res.add(temp);
		temp=new ArrayList<>();
		temp.add(i);temp.add(j+1);
		temp.add(i);temp.add(j+1+1);
		temp.add(i+1);temp.add(j+1);
		res.add(temp);
		arr[i][j]=arr[i][j+1]=0;
    }
    
    static final Random random=new Random();
    
	static void ruffleSort(int[] a) {
		int n=a.length;

		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	
	static void ruffleSort(long[] a) {
		int n=a.length;

		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n);
			long temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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
				catch (IOException e) 
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
