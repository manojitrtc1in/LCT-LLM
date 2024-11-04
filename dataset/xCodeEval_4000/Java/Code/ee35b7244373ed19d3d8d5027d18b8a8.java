

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b {
	
	
	public static void main(String[] args) throws Exception {

	    Scanner s=new Scanner(System.in);

	    int n=s.nextInt();
	    int[] arr=new int[n];
	    
	    for(int i=0;i<n;i++) {
	    	arr[i]=s.nextInt();
	    }
	    StringBuilder sb=new StringBuilder();
	  int ans=0;
	  for(int i=0;i<n;i++) {
		
		  if(i<n/2) {
			  if(i+1==arr[i]) {
				  
			  }else if(arr[i]<=n/2){
				ans++;
				
				sb.append(n+" "+(i+1)+"\n");
				
				  swap(arr,n-1,i);
				  
				
				ans++;
				 sb.append(n+" "+arr[n-1]+"\n");
				  swap(arr,n-1,arr[n-1]-1);
				 
				  ans++;
				  sb.append((i+1)+" "+n+"\n");
				  swap(arr,i,n-1);
				  i--;
				 
				 
			  }else if(arr[i]>n/2&&arr[i]!=n) {
				ans++;
				sb.append(n+" "+(i+1)+"\n");
				  swap(arr,n-1,i);
				  
				 
				 ans++;
				 sb.append(1+" "+n+"\n");
				  swap(arr,n-1,0);
				
				 ans++;
				 sb.append(1+" "+arr[0]+"\n");
				  swap(arr,0,(arr[0]-1));
				
				ans++;
				 sb.append(1+" "+n+"\n");
				  swap(arr,n-1,0);
				
				 ans++;
				 sb.append(n+" "+(i+1)+"\n");
				  swap(arr,i,n-1);
				  i--;
				 
			  }else if(arr[i]==n) {
				  ans++;
				  sb.append((i+1)+" "+n+"\n");
				  swap(arr,i,n-1);
				  i--;
				 
			  }
			  
			  
		  }else{
			  
			  if(i+1==arr[i]) {
				  
			  }else if(arr[i]>n/2) {
				  ans++;
				  sb.append(1+" "+(i+1)+"\n");
				  swap(arr,0,i);
				 
				  ans++;
				  sb.append(1+" "+arr[0]+"\n");
				  swap(arr,0,arr[0]-1);
				 
				  ans++;
				  sb.append(1+" "+(i+1)+"\n");
				  swap(arr,i,0);
				  i--;
				  
			  }else if(arr[i]<=n/2&&arr[i]!=1) {
				  ans++;
				  sb.append(1+" "+(i+1)+"\n");
				  swap(arr,0,i);
				 
				  ans++;
				  sb.append(1+" "+n+"\n");
				  swap(arr,0,n-1);
				 
				  ans++;
				  sb.append(n+" "+arr[n-1]+"\n");
				  swap(arr,n-1,arr[n-1]-1);
				 
				  ans++;
				  sb.append(1+" "+n+"\n");
				  swap(arr,n-1,0);
				
				  ans++;
				  sb.append(1+" "+(i+1)+"\n");
				  swap(arr,i,0);
				i--;
			  }else if(arr[i]==1) {
				  ans++;
				  sb.append(1+" "+(i+1)+"\n");
				  swap(arr,0,i);
				  i--;
				
			  }
			  
			  
			  
		  }








		  
	  }
	  System.out.println(ans);
	  System.out.println(sb);
	  
	
	}
	public static void swap(int[] arr,int a,int b) {
		int temp=arr[a];
		arr[a]=arr[b];
		arr[b]=temp;
	}
}