

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class b {
	
	
	public static void main(String[] args) {

		Scanner s=new Scanner(System.in);
StringBuilder sb=new StringBuilder(	);
int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			long n=s.nextLong();
			long one=s.nextLong();
			
			long g=(n-one)/(one+1);
			long h=g+((n-one)%(one+1));
			long total=((n*(n+1))/2)-((g*(g+1))/2)*(one-h+g+1);
			
			total=total-(((g+1)*((g+1)+1))/2)*((h-g));
			
			sb.append(total);
			sb.append("\n");
			
		}
		System.out.println(sb);
		
	}
}