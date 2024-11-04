

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class d {
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);

		int n=s.nextInt();
		int[] arr=new int[n];
		int[] brr=new int[n];
		HashMap<Integer,Integer> map=new HashMap<>();
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
			map.put(arr[i], i+1);
		}
		
		for(int i=0;i<n;i++) {
			brr[i]=s.nextInt();
		}
		
		HashMap<Integer,Integer> map2=new HashMap<>();
		
		for(int i=0;i<n;i++) {
			if(map2.containsKey(brr[i])) 
			map2.put(brr[i], (map.get(brr[i])-(i+1)+n)%n);
		}
		
		HashMap<Integer,Integer> map3=new HashMap<>();
		for(int i=0;i<n;i++) {
			map3.put(brr[i], (-map.get(brr[i])+(i+1)+n)%n);
		}
		
		int max=-1;
		int[] ans=new int[200002];
		for(Map.Entry<Integer, Integer> entry:map2.entrySet()) {
			ans[entry.getValue()]++;
		}
		for(Map.Entry<Integer, Integer> entry:map3.entrySet()) {
			ans[entry.getValue()]++;
		}
		
		for(int i=0;i<ans.length;i++) {
			max=Math.max(ans[i], max);
		}
		System.out.println(max);
		
		
	}
}