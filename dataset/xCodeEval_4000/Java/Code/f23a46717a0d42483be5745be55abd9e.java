
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception
	{
		Scanner s=new Scanner(System.in);
		
		

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();
			int m=s.nextInt();
			ArrayList<String> list=new ArrayList<>();
			
			for(int i=0;i<n;i++) {
				String str=s.next();
				list.add(str);
			}
			
			if(n==1) {
				System.out.println(list.get(0));
			}else {
				int x=0;
				StringBuilder sb=new StringBuilder();
				
				char[] arr=list.get(0).toCharArray();
				
				
				
				m1:for(int i=0;i<m;i++) {
					for(int j=0;j<26;j++) {
						int flag=0;
						char ch=(char)(97+j);
						char v=arr[i];
						arr[i]=ch;
						
						p1:for(int k=0;k<list.size();k++) {
							
							int g=0;
							for(int l=0;l<m;l++) {
								if(list.get(k).charAt(l)==arr[l]) {
									
								}else if(g==0){
									g=1;
								}else {
									flag=1;
									break p1;
								}
							}
						}
						
						if(flag==0) {
							x=1;
							for(int b=0;b<m;b++) {
								System.out.print(arr[b]);
							}
							break m1;
						}
						
						
						arr[i]=v;
						
					}
				}
				if(x==0) {
					System.out.print(-1);
				}
				
				System.out.println();
				
				
			}
			
			
		}
		
	} 
}