
import java.awt.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception
	{
		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			double n=s.nextDouble();
			n=2d* n;
			
			System.out.println((Math.tan(Math.toRadians((180d-(360d/n))/2d))));
			
			
					
		}
	}
}