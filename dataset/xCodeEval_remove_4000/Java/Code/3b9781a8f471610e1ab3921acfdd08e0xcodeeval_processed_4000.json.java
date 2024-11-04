

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

public class d {
	
	
	public static void main(String[] args) throws Exception
	{
		Scanner s=new Scanner(System.in);
	
	  int n=s.nextInt();
	  int h=s.nextInt();
	  int a=s.nextInt();
	  int b=s.nextInt();
	  int q=s.nextInt();
	 

	  
	  
	  for(int e=0;e<q;e++) {
		  int x1=s.nextInt();
		  int y1=s.nextInt();
		  int x2=s.nextInt();
		  int y2=s.nextInt();
		  
		  long ans=0;
		  ans=ans+Math.abs(x2-x1);
		  if(x1-x2!=0) {
			  if(y1<a||y1>b) {
			 if(Math.abs(y1-a)<Math.abs(y1-b)) {
				 ans=ans+Math.abs(y1-a);
				 ans=ans+Math.abs(a-y2);
			 }else if(Math.abs(y1-a)>Math.abs(y1-b)){
				 ans=ans+Math.abs(y1-b);
				 ans=ans+Math.abs(b-y2);
				 
			 }else {
				 ans=ans+Math.abs(y1-b);
				 ans=ans+Math.min(Math.abs(b-y2),Math.abs(a-y2));
			 }
			  }else {
				  ans=ans+Math.abs(y1-y2);
			  }
		  }else {
			  ans=ans+Math.abs(y1-y2);
			 
		  }
		  System.out.println(ans);
		  
	  }
		
	}
}