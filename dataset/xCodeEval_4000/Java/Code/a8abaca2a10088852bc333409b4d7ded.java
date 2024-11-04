

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);
		
		int n=s.nextInt();
		pair[] arr=new pair[2*n];
		int count=0;
		for(int i=0;i<n;i++) {
			pair ob=new pair(s.nextLong(),1l,0);
			arr[count]=ob;
			count++;
			pair obj=new pair(s.nextLong()+1,-1l,0);
			arr[count]=obj;
			count++;
		}
		
		Arrays.sort(arr,new comp());
		
		HashMap<Integer,Long> map=new HashMap<>();
		map.put(1,arr[0].st);
		arr[0].mask=1;
		int c=1;
		for(int i=1;i<2*n;i++) {
			if(arr[i].st!=arr[i-1].st) {
				c++;
				map.put(c, arr[i].st);
				arr[i].mask=c;
			}else {
				arr[i].mask=arr[i-1].mask;
			}
		}
		

		
		long[] pre=new long[c+1];
		
		for(int i=0;i<2*n;i++) {
			pre[arr[i].mask]=pre[arr[i].mask]+arr[i].end;
		}
		
		for(int i=1;i<c+1;i++) {
			pre[i]=pre[i-1]+pre[i];
		}
		
		long[] ans=new long[n+1];
		
		for(int i=1;i<c;i++) {
			ans[(int)pre[i]]=ans[(int)pre[i]]+map.get(i+1)-map.get(i);
			
		}
		
		
		
		for(int i=1;i<n+1;i++) {
			System.out.print(ans[i]+" ");
		}
		
	
		
	}
}
class pair{
	long st;
	long end;
	int mask;
	
	public pair(long st,long end,int mask) {
		this.st=st;
		this.end=end;
		this.mask=mask;
	}
}

class comp implements Comparator<pair>{
	public int compare(pair h,pair j) {
		if(h.st<j.st) {
			return -1;
		}else if(h.st==j.st) {
			
			if(h.end<j.end) {
				return -1;
			}else if(h.end==j.end) {
				return 0;
			}else {
				return 1;
			}
			
		}else {
			return 1;
		}
	}
}


