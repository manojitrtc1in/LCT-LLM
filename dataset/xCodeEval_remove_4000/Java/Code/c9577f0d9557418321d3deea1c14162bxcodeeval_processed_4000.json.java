

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
		
		int q=s.nextInt();
		ArrayList<Integer> two=new ArrayList<>();
		pair[] one=new pair[n];
		for(int ie=0;ie<q;ie++) {
			int a=s.nextInt();
			if(a==1) {
				int p=s.nextInt();
				int x=s.nextInt();
				pair ob=new pair(x,ie);
				one[p-1]=ob;
				two.add(Integer.MIN_VALUE);
				
			}else {
				int x=s.nextInt();
				two.add(x);
				
			}
		}
		
		int[] pret=new int[two.size()];
		
		pret[two.size()-1]=two.get(two.size()-1);
		for(int i=two.size()-2;i>=0;i--) {
			pret[i]=Math.max(two.get(i), pret[i+1]);
		}
		
		for(int i=0;i<n;i++) {
			if(one[i]!=null) {
				arr[i]=Math.max(one[i].val, pret[one[i].in]);
			}else {
				arr[i]=Math.max(arr[i], pret[0]);
			}
		}
		
		for(int i=0;i<n;i++) {
			System.out.print(arr[i]+" ");
			 
		}
		
		
		
				
		
	}
}
class pair{
	int val;
	int in;
	public pair(int val,int in) {
		this.val=val;
		this.in=in;
	}
}