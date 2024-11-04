

import java.awt.List;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
			
		}
		
		ArrayList<Integer> list=new ArrayList<>();
		int count=0;
		
		
		for(int i=0;i<=n-3;i++) {
			if(arr[i]==1&&arr[i+1]==0&&arr[i+2]==1) {
				count++;
				i++;
			}else {
				list.add(count);
				count=0;
			}
		}
		list.add(count);
		int ans=0;
		
		for(int i=0;i<list.size();i++) {
			if(list.get(i)==1) {
				ans++;
			}else if(list.get(i)>0) {
				ans=ans+list.get(i)%2+list.get(i)/2;
			}
		}

		
	
		System.out.println(ans);
		}
	
}