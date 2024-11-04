

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) 
	{
         Scanner s=new Scanner(System.in);
 
         int t=s.nextInt();
         for(int ie=0;ie<t;ie++) {
 
        	int n=s.nextInt();
        	int k=s.nextInt();
        	char[] arr=s.next().toCharArray();
        	int max=-1;
        	for(int i=1;i<=n;i++) {
        		int[] al=new int[26];
        		for(int j=0;j<n;j++) {
        			al[arr[j]-'a']++;
        		}
        		int count=0;
        		int[] vis=new int[i];
        		ArrayList<Integer> list=new ArrayList<>();
        		for(int j=0;j<i;j++) {
        			int curr=j;
        			while(true) {
        			if(vis[curr]==0) {
        				count++;
        				vis[curr]=1;
        				curr=(curr+k)%i;
        			}else {
        				list.add(count);
        				count=0;
        				break;
        			}
        			}
        			
        		}
        		
        		int flag=0;
        		
        		Collections.sort(list);
        		for(int j=0;j<list.size();j++) {
        			for(int ke=0;ke<26;ke++) {
        				if(al[ke]>=list.get(j)) {
        					al[ke]=al[ke]-list.get(j);
        					flag=0;
        					break;
        				}else {
        					flag=1;
        				}
        			}
        		}
        		
        		if(flag==0) {
        			max=Math.max(max, i);
        		}
        		

        	}
        	System.out.println(max);
        	 
         }
	}
}