

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

 public class d {
	
	 public static void main(String[] args) {
		 Scanner s=new Scanner(System.in);
		 
		 int n=s.nextInt();
		 String num=s.next();
		 int[] arr=new int[9];
		 StringBuilder sb=new StringBuilder();
		 for(int i=0;i<9;i++) {
			 arr[i]=s.nextInt();
		 }
		 
	int flag=0;
	int index=-1;
	for(int i=0;i<num.length();i++) {
		if(Integer.valueOf(num.charAt(i)+"")<arr[Integer.valueOf(num.charAt(i)+"")-1]) {
			index=i;
			flag=1;
			break;
			
		}else {
			sb.append(num.charAt(i));
		}
	}
	
	if(index==-1) {
		System.out.println(sb);
	}else {
		int g=0;
	for(int i=index;i<num.length();i++) {
		if(Integer.valueOf(num.charAt(i)+"")<=arr[Integer.valueOf(num.charAt(i)+"")-1]&&g==0) {
			sb.append(arr[Integer.valueOf(num.charAt(i)+"")-1]);
		}else {
			sb.append(num.charAt(i));
			g=1;
		}
	}
	System.out.println(sb);	 
	}
		 
	 }
 }