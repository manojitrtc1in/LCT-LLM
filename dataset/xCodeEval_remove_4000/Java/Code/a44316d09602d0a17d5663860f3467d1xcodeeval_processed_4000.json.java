

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
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
  
	public static void main(String[] args) 
	{
		FastReader s=new FastReader();
		int n=s.nextInt();
		int m=s.nextInt();
		
		char[][] arr=new char[n][m];
		
		for(int i=0;i<n;i++) {
			String str=s.next();
			for(int j=0;j<m;j++) {
				arr[i][j]=str.charAt(j);
			}
		}
		
		
		pair[][] dp=new pair[n][m];
	
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				pair ob=new pair(0,0,0,0);
				dp[i][j]=ob;
			}
		}
		
		
		for(int i=1;i<n;i++) {
			for(int j=1;j<m;j++) {
				if(arr[i-1][j]=='*') {
					dp[i][j].up=dp[i-1][j].up+1;
				}else {
					dp[i][j].up=0;
				}
				
				if(arr[i][j-1]=='*') {
					dp[i][j].left=1+dp[i][j-1].left;
				}else {
					dp[i][j].left=0;
				}

				
			}
		}
		
		for(int i=n-2;i>=0;i--) {
			for(int j=m-2;j>=0;j--) {
				if(arr[i+1][j]=='*') {
					dp[i][j].down=dp[i+1][j].down+1;
				}else {
					dp[i][j].down=0;
				}
				
				if(arr[i][j+1]=='*') {
					dp[i][j].right=1+dp[i][j+1].right;
				}else {
					dp[i][j].right=0;
				}

				
			}
		}
		
		int count=0;
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				
				if(arr[i][j]=='*'||arr[i][j]=='x') {
				int min=Math.min(dp[i][j].up, dp[i][j].down);
				int min2=Math.min(dp[i][j].left, dp[i][j].right);
				
				int ans=Math.min(min, min2);
				
				if(ans!=0) {
					

					count++;
				for(int ie=i;ie<=i+ans;ie++) {
					arr[ie][j]='x';
				}
				for(int ie=j;ie<=j+ans;ie++) {
					arr[i][ie]='x';
				}
				for(int ie=j;ie>=j-ans;ie--) {
					arr[i][ie]='x';
				}
				for(int ie=i;ie>=i-ans;ie--) {
					arr[ie][j]='x';
				}
				
				sb.append((i+1)).append(" ").append((j+1)).append(" ").append(ans).append("\n");
				}
				
				}
			}
		}
		int flag=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
			if(arr[i][j]=='*') {
				flag=1;
			}
			}
			
		}
		
		if(flag==1) {
			System.out.println(-1);
		}else {
		System.out.println(count);
		System.out.println(sb);
		}
		
		












		
		
		
		
		
		
		
		
	}
}
class pair{
	int up;
	int down;
	int left;
	int right;
	
	public pair(int up,int down,int left,int right) {
		this.up=up;
		this.down=down;
		this.left=left;
		this.right=right;
	}
}


