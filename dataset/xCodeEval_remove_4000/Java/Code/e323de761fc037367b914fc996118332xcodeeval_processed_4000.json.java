

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args){

		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			long a=s.nextLong();
			long b=s.nextLong();
			long k=s.nextLong();
			long ans=0;
			
			long how=k*b;
			ans=ans+k;
			how=how+k-1;
			
			long inc=a-1;
			 ans=ans+how/inc;
			if(how%inc!=0) {
				ans++;
			}
			System.out.println(ans);
			
		}
		
	}
}