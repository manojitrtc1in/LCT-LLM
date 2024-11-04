import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class AACFCC {
	public static long mod = (long) Math.pow(10, 9) + 7;
	public static long mod2 = 998244353;
	public static int oo = 0;
	public static ArrayList<Integer> prime;
	public static int zz = -1;
	public static int ttt = 0;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		int t = 1;












		
		while (t-- > 0) {
			String[] str = br.readLine().split(" ");
			int n = (int) Long.parseLong(str[0]);
			int m = (int) Long.parseLong(str[1]);
			
			int[][]arr=new int[n][m];
			
			for(int i=0;i<n;i++) {
				String[]s1=br.readLine().split(" ");
				for(int j=0;j<m;j++) {
					arr[i][j] = Integer.valueOf(s1[j]);
				}
			}
			int no=0;
			ArrayList<String> list=new ArrayList<>();
			Queue<String> queue=new LinkedList<>();
			for(int i=0;i<n-1;i++) {
				for(int j=0;j<m-1;j++) {
					int a=arr[i][j];
					if(arr[i][j]==0) {
						arr[i][j]=arr[i+1][j+1];
					}
					int b=arr[i][j+1];
					if(arr[i][j+1]==0) {
						arr[i][j+1]=arr[i+1][j+1];
					}
					int c=arr[i+1][j];
					if(arr[i+1][j]==0) {
						arr[i+1][j]=arr[i+1][j+1];
					}
					if(arr[i][j]==arr[i+1][j]&&arr[i][j]==arr[i+1][j+1]&&arr[i][j]==arr[i][j+1]) {
						queue.add(i+" "+j);
						list.add((i+1)+" "+(j+1)+" "+arr[i+1][j+1]);
						no++;
						arr[i][j]=0;arr[i][j+1]=0;arr[i+1][j]=0;arr[i+1][j+1]=0;
					}else {
						arr[i][j]=a;
						arr[i][j+1]=b;arr[i+1][j]=c;
					}
				}
			}
			
			while(!queue.isEmpty()) {
				String[] s1=queue.remove().split(" ");
				int i=Integer.valueOf(s1[0]);
				int j=Integer.valueOf(s1[1]);
				if(i-1>=0&&j-1>=0) {
					
					int a=arr[i][j-1];
					int b=arr[i-1][j];
					int c=arr[i-1][j-1];
					if(a==b&&b==c) {
						if(a==0) {
							
						}else {
							queue.add((i-1)+" "+(j-1));
							list.add((i)+" "+(j)+" "+c);
							no++;
							arr[i][j-1]=0;arr[i-1][j]=0;
							arr[i-1][j-1]=0;
						}
					}else {
						int d=a;
						if(b!=0) {
							d=b;
						}else if(c!=0) {
							d=c;
						}
						
						if(a==0) {
							arr[i][j-1]=d;
						}if(b==0) {
							arr[i-1][j]=d;
						}if(c==0) {
							arr[i-1][j-1]=d;
						}
						if(arr[i][j-1]==arr[i-1][j]&&arr[i-1][j]==arr[i-1][j-1]) {
							arr[i][j-1]=0;arr[i-1][j]=0;arr[i-1][j-1]=0;
							no++;
							queue.add((i-1)+" "+(j-1));
							list.add((i)+" "+(j)+" "+d);
						}else {
							arr[i][j-1]=a;arr[i-1][j]=b;arr[i-1][j-1]=c;
						}
					}
				}
				if(i+2<n&&j-1>=0) {
					int a=arr[i+1][j-1];
					int b=arr[i+2][j];
					int c=arr[i+2][j-1];
					if(a==b&&b==c) {
						if(a==0) {
							
						}else {
							queue.add((i+1)+" "+(j-1));
							list.add((i+2)+" "+(j)+" "+c);
							no++;
							arr[i+1][j-1]=0;arr[i+2][j]=0;
							arr[i+2][j-1]=0;
						}
					}else {
						int d=a;
						if(b!=0) {
							d=b;
						}else if(c!=0) {
							d=c;
						}
						
						if(a==0) {
							arr[i+1][j-1]=d;
						}if(b==0) {
							arr[i+2][j]=d;
						}if(c==0) {
							arr[i+2][j-1]=d;
						}
						if(arr[i+1][j-1]==arr[i+2][j]&&arr[i+2][j]==arr[i+2][j-1]) {
							arr[i+1][j-1]=0;arr[i+2][j]=0;arr[i+2][j-1]=0;
							queue.add((i+1)+" "+(j-1));
							list.add((i+2)+" "+(j)+" "+d);
							no++;
						}else {
							arr[i+1][j-1]=a;arr[i+2][j]=b;arr[i+2][j-1]=c;
						}
					}
				}
				
				if(i-1>=0&&j+2<m) {
					int a=arr[i][j+2];
					int b=arr[i-1][j+1];
					int c=arr[i-1][j+2];
					if(a==b&&b==c) {
						if(a==0) {
							
						}else {
							queue.add((i-1)+" "+(j+1));
							list.add((i)+" "+(j+2)+" "+c);
							no++;
							arr[i][j+2]=0;arr[i-1][j+1]=0;
							arr[i-1][j+2]=0;
						}
					}else {
						int d=a;
						if(b!=0) {
							d=b;
						}else if(c!=0) {
							d=c;
						}
						
						if(a==0) {
							arr[i][j+2]=d;
						}if(b==0) {
							arr[i-1][j+1]=d;
						}if(c==0) {
							arr[i-1][j+2]=d;
						}
						if(arr[i][j+2]==arr[i-1][j+1]&&arr[i-1][j+1]==arr[i-1][j+2]) {
							arr[i][j+2]=0;arr[i-1][j+1]=0;arr[i-1][j+2]=0;
							no++;
							queue.add((i-1)+" "+(j+1));
							list.add((i)+" "+(j+2)+" "+d);
						}else {
							arr[i][j+2]=a;arr[i-1][j+1]=b;arr[i-1][j+2]=c;
						}
					}
				}
				if(i+2<n&&j+2<m) {
					int a=arr[i+1][j+2];
					int b=arr[i+2][j+1];
					int c=arr[i+2][j+2];
					if(a==b&&b==c) {
						if(a==0) {
							
						}else {
							queue.add((i+1)+" "+(j+1));
							list.add((i+2)+" "+(j+2)+" "+c);
							no++;
							arr[i+1][j+2]=0;arr[i+2][j+1]=0;
							arr[i+2][j+2]=0;
						}
					}else {
						int d=a;
						if(b!=0) {
							d=b;
						}else if(c!=0) {
							d=c;
						}
						
						if(a==0) {
							arr[i+1][j+2]=d;
						}if(b==0) {
							arr[i+2][j+1]=d;
						}if(c==0) {
							arr[i+2][j+2]=d;
						}
						if(arr[i+2][j+2]==arr[i+2][j+1]&&arr[i+2][j+2]==arr[i+1][j+2]) {
							arr[i+1][j+2]=0;arr[i+2][j+2]=0;arr[i+2][j+1]=0;
							no++;
							queue.add((i+1)+" "+(j+1));
							list.add((i+2)+" "+(j+2)+" "+d);
						}else {
							arr[i+1][j+2]=a;arr[i+2][j+2]=c;arr[i+2][j+1]=b;
						}
					}
				}
				if(i+2<n&&(arr[i+2][j]==0||arr[i+2][j+1]==0||(arr[i+2][j]==arr[i+2][j+1]))) {
					if(arr[i+2][j]==0&&arr[i+2][j+1]==0) {
						
					}else {
						int c=arr[i+2][j+1];
						if(arr[i+2][j]!=0) {
							c=arr[i+2][j];
						}
						queue.add((i+1)+" "+j);
						list.add((i+2)+" "+(j+1)+" "+c);
						no++;
						arr[i+2][j]=0;arr[i+2][j+1]=0;
					}
				}
				if(j+2<m&&(arr[i][j+2]==0||arr[i+1][j+2]==0||(arr[i][j+2]==arr[i+1][j+2]))) {
					if(arr[i][j+2]==0&&arr[i+1][j+2]==0) {
						
					}else {
						int c=arr[i+1][j+2];
						if(arr[i][j+2]!=0) {
							c=arr[i][j+2];
						}
						queue.add((i)+" "+(j+1));
						list.add((i+1)+" "+(j+2)+" "+c);
						no++;
						arr[i][j+2]=0;arr[i+1][j+2]=0;
					}
				}
				if(i-1>=0&&(arr[i-1][j]==0||arr[i-1][j+1]==0||(arr[i-1][j]==arr[i-1][j+1]))) {
					if(arr[i-1][j]==0&&arr[i-1][j+1]==0) {
						
					}else {
						int c=arr[i-1][j+1];
						if(arr[i-1][j]!=0) {
							c=arr[i-1][j];
						}
						queue.add((i-1)+" "+j);
						list.add((i)+" "+(j+1)+" "+c);
						no++;
						arr[i-1][j]=0;arr[i-1][j+1]=0;
					}
				}
				if(j-1>=0&&(arr[i][j-1]==0||arr[i+1][j-1]==0||(arr[i][j-1]==arr[i+1][j-1]))) {
					if(arr[i][j-1]==0&&arr[i+1][j-1]==0) {
						
					}else {
						int c=arr[i+1][j-1];
						if(arr[i][j-1]!=0) {
							c=arr[i][j-1];
						}
						queue.add((i)+" "+(j-1));
						list.add((i+1)+" "+(j)+" "+c);
						no++;
						arr[i][j-1]=0;arr[i+1][j-1]=0;
					}
				}
			}
			int op=0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(arr[i][j]!=0) {
						op=1;
						break;
					}
				}
			}
			if(op==1) {
				pw.println(-1);
			}else {
				Collections.reverse(list);
				pw.println(no);
				for(int i=0;i<list.size();i++) {
					pw.println(list.get(i));
				}
			}
		}
		pw.close();

	}

}









































































































































































































































































































































































































































































































