
import java.util.ArrayList;
import java.util.Scanner;

public class b{
	
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);
	
		int n=s.nextInt();
		String str=s.next();
		
	ArrayList<Long> list=new ArrayList<>();
	ArrayList<Long> list2=new ArrayList<>();

		
		long count=0;
		for(int i=0;i<str.length();i++) {
			if(str.charAt(i)=='1') {
				count++;
				list.add(count);
				count=0;
				
			}else{
				count++;
			}
		}
		
		count=0;
		for(int i=str.length()-1;i>=0;i--) {
			if(str.charAt(i)=='1') {
				count++;
				list2.add(count);
				count=0;
			}else {
				count++;
			}
			
		}
		ArrayList<Long> list3=new ArrayList<>();
		for(int i=list2.size()-1;i>=0;i--) {
			list3.add(list2.get(i));
		}
		if(n==0) {
			count=0;
			long ans=0;
			for(int i=0;i<str.length();i++) {
				if(str.charAt(i)=='0') {
					count++;
				}else {
					ans=ans+(count*(count+1))/2;
					count=0;
				}
			}
			
			ans=ans+(count*(count+1))/2;
			System.out.println(ans);
		}else if(n==1) {
			long ck=0;
			for(int i=0;i<list.size();i++) {
				ck=ck+(list.get(i)*list3.get(i));
			}
			System.out.println(ck);
		}else {
			
			int st=0;
			int end=n-1;
			long ans=0;
			

			

			while(end<list.size()) {
				ans=ans+(list.get(st)*list3.get(end));
				st++;
				end++;
			}
			System.out.println(ans);
			
			
			
		}
		
			
		
		
	
	}
}