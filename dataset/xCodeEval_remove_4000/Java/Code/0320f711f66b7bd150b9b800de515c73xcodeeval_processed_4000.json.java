
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b{
	
	
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		String str=s.next();
		
		int ans=0;
		int h=0;
		int count=0;
		for(int i=0;i<str.length();i++) {
			if(str.charAt(i)==')') {
				count--;
			}else {
				count++;
			}
			
			if(h<0) {
				if(count>h) {
					ans=ans+1;
				}
				
			}
			
			h=count;
			
		}
		
		if(count==0)
		System.out.println(ans*2);
		else
			System.out.println(-1);
	}
}