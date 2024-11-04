

import java.util.Scanner;
import java.util.Stack;

public class Main {
	
	
	public static void main(String[] args) throws Exception
	{
		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
		}
		
		
			
			Stack<Integer> st=new Stack<>();
			if(arr[0]%2==0)
			st.add(2);
			else
				st.add(1);
			
			for(int i=1;i<n;i++) {
				if(arr[i]%2==0) {
					if(st.size()>=1&&st.get(st.size()-1)==2) {
					st.pop();
					}else {
						st.add(2);
					}
				}else {
					
					if(st.size()>=1&&st.get(st.size()-1)==1) {
					st.pop();
					}else {
						st.add(1);
					}
				}
			}
			if(st.size()<=1) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
		}
		
		
	
}