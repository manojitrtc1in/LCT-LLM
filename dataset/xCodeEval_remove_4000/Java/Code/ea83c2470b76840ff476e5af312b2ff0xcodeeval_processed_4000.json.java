
import java.util.ArrayList;
import java.util.Scanner;

 public class Main{
	 
	
	  public static void main (String[] args) {
		 
		  Scanner s=new Scanner(System.in);
	
		 int t=s.nextInt();
		 StringBuilder sb=new StringBuilder();
		 for(int ie=0;ie<t;ie++) {
			 
			 int n=s.nextInt();
			 ArrayList<Integer> list=new ArrayList<>();
			 int[] arr=new int[n];
			 
			 for(int i=0;i<n;i++) {
				arr[i]=i+1;
			 }
			
			 
			 if(n==1) {
				 sb.append(1).append("\n");
				 sb.append(1).append("\n");
			 }else if(n!=2){
				 
				 int h=-1;
				 for(int i=n-1;i>=0;i--) {
					 if(h==-1) {
						 h=arr[i];
					 }else {
						

						 h=(1+h+arr[i])/2;
						 
					 }
					 
					 
				 }
				 sb.append(h).append("\n");
				 
				 int curr=-1;
				 for(int i=n-1;i>=0;i--) {
					 if(curr==-1) {
						 curr=arr[i];
					 }else {
						 sb.append(curr+" "+arr[i]).append("\n");
						 curr=(1+curr+arr[i])/2;
						 
					 }
					 
					 
				 }
				 
					 
			 
			 
		 }else {
			 sb.append(2).append("\n");
			 sb.append(1+" "+2).append("\n");
		 }
			  
		  
		  
	  }
		 System.out.println(sb);
	  }
 }