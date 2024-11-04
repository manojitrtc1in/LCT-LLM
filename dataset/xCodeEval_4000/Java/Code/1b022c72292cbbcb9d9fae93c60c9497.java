
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

 public class Main{
	 
	  public static void main (String[] args) {
		 
		  Scanner s=new Scanner(System.in);
	StringBuilder sb=new StringBuilder();
		  int t=s.nextInt();
		  for(int ie=0;ie<t;ie++) {
	
			  int n=s.nextInt();
			  int[] arr=new int[n];
			  for(int i=0;i<n;i++) {
				  arr[i]=s.nextInt();
			  }
			  
			  int g=0;
			  int a=0; int b=0;
			  for(int i=0;i<n-1;i++) {
				  if(arr[i]==arr[i+1]) {
					  
				  }else {
					  a=i;
					  b=i+1;
					  g=1;
					  break;
				  }
			  }
			  a++;
			  b++;
			  int curr=b;
			  if(g==0) {
				sb.append("NO").append("\n");
			  }else {
				  sb.append("YES").append("\n");
				  
				  sb.append(a+" "+b).append("\n");
				  
				  for(int i=0;i<n;i++) {
					  if(i!=a-1 && i!=b-1) {
					  if(arr[i]==arr[a-1]) {
						  sb.append(b+" "+(i+1)).append("\n");
					  }else {
						  sb.append(a+" "+(i+1)).append("\n");
					  }
					  }
				  }
				  
				 
				  
			  }
			  
			  
		  }
		  System.out.println(sb);
	  }
 }