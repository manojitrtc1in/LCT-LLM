

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args){

		Scanner s=new Scanner(System.in);
	
			String str=s.next();
			String g="";
			for(int i=str.length()-1;i>=0;i--) {
				g=g+str.charAt(i);
			}
			
			System.out.println(str+g);
			
		}
	}
