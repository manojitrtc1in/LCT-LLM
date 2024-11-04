





















































































































































































































import java.util.*;
import java.io.*;
public class id1{
	static class Field{
		int number;
		char direction;
		boolean contains0;
		boolean is0;
		Field(int number, boolean x){
			this.number = number;
			this.contains0 = false;
			this.is0 = x;
		}
	}
	public static int get(int a, int b) {
		if(a%b==0) {
			int c1 = 0;
			long temp = a;
			long div = b;
			while(temp>=div && temp%div==0) {
				c1++;
				temp/=div;
			}
			return c1;
		}
		return 0;
	}
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int i,j;
		int[][] o = new int[n][n];
		Field[][] m = new Field[n][n];
		for(i=0;i<n;i++) {
			String[] a = br.readLine().split(" ");
			for(j = 0;j<n;j++) {
				o[i][j] = Integer.parseInt(a[j]);
			}
		}
		for(i = 0;i<n;i++) {
			for(j = 0;j<n;j++) {
				m[i][j] = new Field(get(o[i][j],2),o[i][j]==0);
				m[i][j].contains0 = o[i][j]==0;
			}
		}
		for(i=n-1;i>=0;i--) {
			for(j=n-1;j>=0;j--) {
				if(i==n-1 && j==n-1) {
					continue;
				}
				if(o[i][j]==0) {
					m[i][j].number = 1;
					m[i][j].direction='R';
					continue;
				}
				int min = 0;
				char dir = 0;
				boolean contains0 = false;
				boolean id2 = false;
				if(i+1<n) {
					if(j+1<n) {
						if(m[i+1][j].number>m[i][j+1].number) {
							min = m[i][j+1].number;
							dir = 'R';
							contains0 = m[i][j+1].contains0;
							id2 = m[i+1][j].contains0;
						}
						else {
							if(m[i+1][j].number<m[i][j+1].number) {
								min = m[i+1][j].number;
								dir = 'D';
								contains0 = m[i+1][j].contains0;
								id2 = m[i][j+1].contains0;
							}
							else {
								if(m[i+1][j].contains0) {
									min = m[i+1][j].number;
									dir = 'D';
									contains0 = m[i+1][j].contains0;
									id2 = m[i][j+1].contains0;
								}
								else {
									min = m[i][j+1].number;
									dir = 'R';
									contains0 = m[i][j+1].contains0;
									id2 = m[i+1][j].contains0;
								}
							}
						}
					}
					else {
						min = m[i+1][j].number;
						dir = 'D';
						contains0 = m[i+1][j].contains0;
					}
				}
				else {
					min = m[i][j+1].number;
					dir = 'R';
				}
				m[i][j].number+=min;
				m[i][j].direction = dir;
				if(contains0 && m[i][j].number>=1) {
					m[i][j].number=1;
					m[i][j].contains0  = true;
				}
				if(id2 && m[i][j].number>=1) {
					m[i][j].number=1;
					m[i][j].contains0 = true;
				}
			}
		}
		String res = "";
		int x = 0, y = 0;
		for(i=0;i<2*n-2;i++) {
			res+=String.valueOf(m[x][y].direction);
			if(m[x][y].direction=='R') {
				y++;
			}
			else {
				x++;
			}
		}
		if(m[0][0].number==0) {
			System.out.println(m[0][0].number+"\n"+res);
		}
		else {
			int id0 = m[0][0].number;
			for(i = 0;i<n;i++) {
				for(j = 0;j<n;j++) {
					m[i][j] = new Field(get(o[i][j],5),o[i][j]==0);
					m[i][j].contains0 = o[i][j]==0;
				}
			}
			for(i=n-1;i>=0;i--) {
				for(j=n-1;j>=0;j--) {
					if(i==n-1 && j==n-1) {
						continue;
					}
					if(o[i][j]==0) {
						m[i][j].number = 1;
						m[i][j].direction='R';
						continue;
					}
					int min = 0;
					char dir = 0;
					boolean contains0 = false;
					boolean id2 = false;
					if(i+1<n) {
						if(j+1<n) {
							if(m[i+1][j].number>m[i][j+1].number) {
								min = m[i][j+1].number;
								dir = 'R';
								contains0 = m[i][j+1].contains0;
								id2 = m[i+1][j].contains0;
							}
							else {
								if(m[i+1][j].number<m[i][j+1].number) {
									min = m[i+1][j].number;
									dir = 'D';
									contains0 = m[i+1][j].contains0;
									id2 = m[i][j+1].contains0;
								}
								else {
									if(m[i+1][j].contains0) {
										min = m[i+1][j].number;
										dir = 'D';
										contains0 = m[i+1][j].contains0;
										id2 = m[i][j+1].contains0;
									}
									else {
										min = m[i][j+1].number;
										dir = 'R';
										contains0 = m[i][j+1].contains0;
										id2 = m[i+1][j].contains0;
									}
								}
							}
						}
						else {
							min = m[i+1][j].number;
							dir = 'D';
							contains0 = m[i+1][j].contains0;
						}
					}
					else {
						min = m[i][j+1].number;
						dir = 'R';
					}
					m[i][j].number+=min;
					m[i][j].direction = dir;
					if(contains0 && m[i][j].number>=1) {
						m[i][j].number=1;
						m[i][j].contains0  = true;
					}
					if(id2 && m[i][j].number>=1) {
						m[i][j].number=1;
						m[i][j].contains0 = true;
					}
				}
			}
			if(m[0][0].number<id0) {
				res = "";
				x = 0; y = 0;
				for(i=0;i<2*n-2;i++) {
					res+=String.valueOf(m[x][y].direction);
					if(m[x][y].direction=='R') {
						y++;
					}
					else {
						x++;
					}
				}
				System.out.println(m[0][0].number+"\n"+res);
			}
			else {
				System.out.println(id0+"\n"+res);
			}
		}
	}
}
