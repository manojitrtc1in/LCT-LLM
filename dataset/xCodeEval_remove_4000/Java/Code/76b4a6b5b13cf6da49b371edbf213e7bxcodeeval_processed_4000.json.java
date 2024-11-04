

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
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

	public static void main(String[] args) {

		FastReader s=new FastReader();

		StringBuilder ans=new StringBuilder();
		char[] good=s.next().toCharArray();
		HashMap<Character,Integer> map=new HashMap<>();
		
		for(int i=0;i<good.length;i++) {
			map.put(good[i], 1);
		}
		char[] pat=s.next().toCharArray();
		
		int h=0;
		int in=-1;
		for(int i=0;i<pat.length;i++) {
			if(pat[i]=='*') {
				h=1;
				in=i;
				
			}
		}
		
		StringBuilder sb1=new StringBuilder();
		for(int i=0;i<pat.length;i++) {
			if(pat[i]!='*')
			sb1.append(pat[i]);
		}
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			char[] arr=s.next().toCharArray();
			
			int flag=0;
			
			int st=-1;
			int end=-1;
			int g=0;
			for(int i=0;i<arr.length;i++) {
				if(g==0) {
					if(!map.containsKey(arr[i])) {
						g=1;
						st=i;
					}
				}else {
					if(map.containsKey(arr[i])) {
						end=i-1;
						g=0;
						break;
					}
					
					
				}
			}
			
			if(g==1) {
				end=arr.length-1;
			}
			
			
			
			
			StringBuilder sb=new StringBuilder();
			
			if(h==0) {
				for(int i=0;i<arr.length;i++) {
					sb.append(arr[i]);
				}
				
				
				
			}else {
				
				if(st==-1) {
				for(int i=0;i<arr.length;i++) {
					
					sb.append(arr[i]);
				}
				
				
				
				}else {
					
					if(1==0) {
						flag=1;
					}else {
						for(int i=0;i<arr.length;i++) {
							if(i<in||i>=arr.length-pat.length+in+1)
							sb.append(arr[i]);
							else
								if(map.containsKey(arr[i]))
								{
									flag=1;
								}
						}
						
						
						
					}
					
				}
				
			}
		

			if(sb.length()!=sb1.length()) {
				flag=1;
			}else {
				
				for(int i=0;i<sb.length();i++) {
					if(sb.charAt(i)==sb1.charAt(i)) {
						
					}else if(sb1.charAt(i)=='?'&&map.containsKey(sb.charAt(i))) {
						
					}else {
						flag=1;
					}
				}
			}
			
			
			
			
			if(flag==0) {
				ans.append("YES").append("\n");
			}else {
				ans.append("NO").append("\n");
			}
			
			
		}
		
		System.out.println(ans);
			
		
		
	}
}