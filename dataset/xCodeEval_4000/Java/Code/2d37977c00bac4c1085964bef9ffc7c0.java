

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
 public class b {
	 static int gmin=1000000;
	static	String h="";
	
	public static void main(String[] args)  {
	   Scanner s = new Scanner( System.in);
	
	
	   int n=s.nextInt();
	   char[] arr=s.next().toCharArray();
	   StringBuilder sb=new StringBuilder();
	
	   if(n==1) {
		   System.out.println(0);
		   System.out.println(arr[0]);
	   }else if(n==2) {
		   if(arr[0]==arr[1]) {
			   System.out.println(1);
			   if(arr[0]=='R') {
				   System.out.println("RG");
			   }else if(arr[0]=='G') {
				   System.out.println("GR");
			   }else {
				   System.out.println("BR");
			   }
		   }else {
			   System.out.println(0);
			   System.out.print(arr[0]);
			   System.out.print(arr[1]);
		   }
	   }else {
		  
		  permute("RGB",0,2,n,arr);
		  System.out.println(gmin);
		  System.out.println(h);
	
		   
	   }
	}
	public static  void permute(String str, int l, int r,int n,char[] arr) 
    { 
		
        if (l == r) {
        	 StringBuilder sb=new StringBuilder();
        	 sb.append(str);
        	 for(int i=3;i<n;i++) {
        		 sb.append(sb.charAt(i-3));
        	 }
        	 int min=0;
        	 for(int i=0;i<n;i++) {
        		 if(sb.charAt(i)!=arr[i]) {
        			 min++;
        		 }
        	 }
        	 
        	 if(gmin>min) {
        		 gmin=min;
        		 h=sb.toString();
        	 }
        }
         
        else
        { 
            for (int i = l; i <= r; i++) 
            { 
                str = swap(str,l,i); 
                permute(str, l+1, r,n,arr); 
                str = swap(str,l,i); 
            } 
        } 
    } 
  
   
    public static String swap(String a, int i, int j) 
    { 
        char temp; 
        char[] charArray = a.toCharArray(); 
        temp = charArray[i] ; 
        charArray[i] = charArray[j]; 
        charArray[j] = temp; 
        return String.valueOf(charArray); 
    } 
 }