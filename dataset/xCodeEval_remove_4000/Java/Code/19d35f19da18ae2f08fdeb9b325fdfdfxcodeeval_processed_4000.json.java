import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;
import java.util.TreeSet;



public final class id6 {

	static boolean verb=true;
	static void log(Object X){if (verb) System.err.println(X);}
	static void log(Object[] X){if (verb) {for (Object U:X) System.err.print(U+" ");System.err.println("");}}
	static void log(int[] X){if (verb) {for (int U:X) System.err.print(U+" ");System.err.println("");}}
	static void log(int[] X,int L){if (verb) {for (int i=0;i<L;i++) System.err.print(X[i]+" ");System.err.println("");}}
	static void log(long[] X){if (verb) {for (long U:X) System.err.print(U+" ");System.err.println("");}}

	static void id0(Object X){if (verb) System.err.print(X);}
	static void info(Object o){	System.out.println(o);}
	static void output(Object o){id4(""+o+"\n");	}
	static void id4(Object o){try {out.write(""+ o);} catch (Exception e) {}}






	static String KO="NO";
	static String OK="YES";
	static int NMAX=100001;



	static int cur;
	static int diff;
	static char[][] res;
	static int[] stack;
	static int st;

	static void fillGood(int i){
		for (int j=0;j<res[i].length;j++){
			if (res[i][j]=='?'){
				if (j==0)
					res[i][j]='1';
				else
					res[i][j]='0';
			}
		}
	}

	static void backtrack(int i){
		while (st>0){
			int k=stack[--st];
			

			if (res[i-1][k]<'9'){
				

				res[i][k]=(char)(res[i-1][k]+1);
				diff=1;
				cur=k;
				break;
			} else {
				res[i][k]='?';
			}
		}

	}

	static String id1(String[] map){
		int n=map.length;
		for (int i=1;i<n;i++){
			if (map[i].length()<map[i-1].length()){
				return KO;
			}
		}
		res=new char[n][];
		for (int i=0;i<n;i++)
			res[i]=map[i].toCharArray();

		

		fillGood(0);

		stack=new int[NMAX];
		for (int i=1;i<n;i++){
			if (res[i].length>res[i-1].length){
				log("case 1");
				fillGood(i);

			} else 	{
				st=0;
				cur=0;
				diff=0;
				while (cur<res[i].length){
					if (res[i][cur]=='?'){
						stack[st++]=cur;
						if (diff==1)
							res[i][cur]='0';
						else {

							res[i][cur]=res[i-1][cur];
							if (cur==res[i].length-1){
								if (res[i-1][cur]=='9'){
									backtrack(i);
									if (diff!=1)
										return KO;
								} else
									res[i][cur]=(char)(res[i-1][cur]+1);
							}
						}
					} else {
						if (diff==0){
							if (res[i][cur]>res[i-1][cur]){
								

								diff=1;
							} else if ((res[i][cur]<res[i-1][cur])|| (res[i][cur]==res[i-1][cur] && cur==res[i].length-1)){
								backtrack(i);
								if (diff!=1)
									return KO;
							}
						}

					}
					cur++;
				}

			}
		}

		output("YES");
		for (int i=0;i<n;i++)
			output(new String(res[i]));

		return OK;
	}


	

	static String id7(String[] map){
		int n=map.length;
		for (int i=1;i<n;i++){
			if (map[i].length()<map[i-1].length()){
				

				return KO;
			}
		}
		char[][] res=new char[n][];
		for (int i=0;i<n;i++)
			res[i]=map[i].toCharArray();
		


		for (int j=0;j<res[0].length;j++){
			if (res[0][j]=='?'){
				if (j==0)
					res[0][j]='1';
				else
					res[0][j]='0';
			}
		}
		int[] stack=new int[NMAX];
		int st;
		for (int i=1;i<n;i++){
			if (res[i].length>res[i-1].length){
				

				for (int j=0;j<res[i].length;j++){
					if (res[i][j]=='?'){
						if (j==0)
							res[i][j]='1';
						else
							res[i][j]='0';
					}
				}
			} else {
				

				int diff=-2; 

				loop:for (int j=0;j<res[i].length;j++){
					if (res[i][j]=='?')
						break loop;
					if (res[i][j]<res[i-1][j]){
						

						

						return KO;
					}
					if (res[i][j]==res[i-1][j] && diff==-2)
						diff=0;
					if (res[i][j]>res[i-1][j]){
						diff=1;
						break;
					}
				}
				if (diff==1){
					

					for (int j=0;j<res[i].length;j++){
						if (res[i][j]=='?'){
							if (j==0)
								res[i][j]='1';
							else
								res[i][j]='0';
						}
					}
				}
				if (diff==0 || diff==-2){

					diff=0;
					st=0;
					int j=0;
					while (j<res[i].length){
						if (res[i][j]=='?'){
							stack[st++]=j;
							if (diff>0){
								res[i][j]='0';
							} else {
								if (j<res[i].length-1){
									res[i][j]=res[i-1][j];

								} else {
									if (res[i-1][j]<'9'){
										res[i][j]=(char)(res[i-1][j]+1);
									} else {
										

										while (st>0){
											int k=stack[--st];
											

											if (res[i-1][k]<'9'){
												

												res[i][k]=(char)(res[i-1][k]+1);
												diff=1;
												j=k;
												break;
											} else {
												res[i][k]='?';
											}
										}
										if (diff!=1){
											

											return KO;
										}
									}
								}
							}
						} else {
							if (diff!=1 && (res[i][j]<res[i-1][j] || (res[i][j]==res[i-1][j] && j==res[i].length-1))){
								

								

								while (st>0){
									int k=stack[--st];
									

									if (res[i-1][k]<'9'){
										

										res[i][k]=(char)(res[i-1][k]+1);
										diff=1;
										j=k;
										break;
									} else {
										res[i][k]='?';
									}
								}
								if (diff!=1){
									

									return KO;
								}

							} else {
								if (res[i][j]>res[i-1][j] & diff!=1)
									diff=1;
								if (res[i][j]==res[i-1][j] && diff==-2)
									diff=0;
							}

						}
						j++;
					}
					

				}

			}


		}

		output("YES");
		for (int i=0;i<n;i++)
			output(new String(res[i]));

		return OK;
	}

	static int[] solveInt(String[] map){
		int n=map.length;
		for (int i=1;i<n;i++){
			if (map[i].length()<map[i-1].length()){
				

				return null;
			}
		}
		char[][] res=new char[n][];
		for (int i=0;i<n;i++)
			res[i]=map[i].toCharArray();
		


		for (int j=0;j<res[0].length;j++){
			if (res[0][j]=='?'){
				if (j==0)
					res[0][j]='1';
				else
					res[0][j]='0';
			}
		}
		int[] stack=new int[NMAX];
		int st;
		for (int i=1;i<n;i++){
			if (res[i].length>res[i-1].length){
				

				for (int j=0;j<res[i].length;j++){
					if (res[i][j]=='?'){
						if (j==0)
							res[i][j]='1';
						else
							res[i][j]='0';
					}
				}
			} else {
				

				int diff=-2; 

				loop:for (int j=0;j<res[i].length;j++){
					if (res[i][j]=='?')
						break loop;
					if (res[i][j]<res[i-1][j]){
						

						

						return null;
					}
					if (res[i][j]==res[i-1][j] && diff==-2)
						diff=0;
					if (res[i][j]>res[i-1][j]){
						diff=1;
						break;
					}
				}
				if (diff==1){
					

					for (int j=0;j<res[i].length;j++){
						if (res[i][j]=='?'){
							if (j==0)
								res[i][j]='1';
							else
								res[i][j]='0';
						}
					}
				}
				if (diff==0 || diff==-2){

					diff=0;
					st=0;
					int j=0;
					while (j<res[i].length){
						if (res[i][j]=='?'){
							stack[st++]=j;
							if (diff>0){
								res[i][j]='0';
							} else {
								if (j<res[i].length-1){
									res[i][j]=res[i-1][j];

								} else {
									if (res[i-1][j]<'9'){
										res[i][j]=(char)(res[i-1][j]+1);
									} else {
										

										loop:while (st>0){
											int k=stack[--st];
											

											if (res[i-1][k]<'9'){
												

												res[i][k]=(char)(res[i-1][k]+1);
												diff=1;
												j=k;
												break loop;
											} else {
												res[i][k]='?';
											}
										}
									}
								}
							}
						} else {
							if (diff!=1 && (res[i][j]<res[i-1][j] || res[i][j]==res[i-1][j] && j==res[i].length-1)){
								

								

								loop:while (st>0){
									int k=stack[--st];
									

									if (res[i-1][k]<'9'){
										

										res[i][k]=(char)(res[i-1][k]+1);
										diff=1;
										j=k;
										break loop;
									} else {
										res[i][k]='?';
									}

								}
							if (diff!=1){
								

								return null;
							}

							} else {
								if (res[i][j]>res[i-1][j] & diff!=1)
									diff=1;
								if (res[i][j]==res[i-1][j] && diff==-2)
									diff=0;
							}

						}
						j++;
					}
					

				}

			}


		}
		int[] ans=new int[n];
		for (int i=0;i<n;i++)
			ans[i]=Integer.parseInt(new String(res[i]));

		return ans;
	}

	static boolean isCompat(int x,String b){
		String a=""+x;
		if (a.length()!=b.length())
			return false;
		for (int i=0;i<a.length();i++){
			if (a.charAt(i)!=b.charAt(i) & b.charAt(i)!='?')
				return false;
		}
		return true;
	}

	static int[] id5(String[] map){
		

		

		int n=map.length;
		int[] ans=new int[n];
		int x=0;
		while (!isCompat(x,map[0]))
			x++;
		ans[0]=x;
		for (int i=1;i<n;i++){
			

			x=0;
			while ((!isCompat(x,map[i])  || x<=ans[i-1]) && (""+x).length()<=map[i].length()){
				x++;
			}
			

			

			


			if ((""+x).length()>map[i].length() || x<=ans[i-1])
				return null;
			ans[i]=x;
		}
		return ans;
	}

	static void test(){
		log("testing");
		int id2=100000;
		int L=4;
		Random r=new Random();
		String ref="0123456789?";
		for (int t=0;t<id2;t++){
			String[] map=new String[2];
			for (int e=0;e<2;e++){
				map[e]="";
				for (int i=0;i<L;i++){
					int x=r.nextInt(11);
					if (x==0 && i==0)
						x=1;
					map[e]+=ref.charAt(x);
				}
			}
			try{
				int[] ans1=solveInt(map);

				int[] ans2=id5(map);
				if ((ans1==null && ans2!=null)||(ans1!=null && ans2==null)||(ans1!=null && ans2!=null && (ans1[0]!=ans2[0] || ans1[1]!=ans2[1]))){ 
					log("Error");
					log(2);
					log(map[0]);
					log(map[1]);
					id0("=======solveInt://");
					if (ans1!=null)	log(ans1);
					log("");
					id0("=======id5://");
					if (ans2!=null) log(ans2);
					log("");


					return;
				}
			} catch (Exception E){
				log(map);
				log(E);
				return;
			}
		}
		log("done");
	}


	


	

	static BufferedWriter out;
	static InputReader reader;




	static void process() throws Exception {

		


		out = new BufferedWriter(new OutputStreamWriter(System.out));
		reader=new InputReader(System.in);

		int n=reader.readInt();
		String[] map=new String[n];
		for (int i=0;i<n;i++)
			map[i]=reader.readString();

		String ans=id1(map);
		if (ans==KO){
			output("NO");
		}



		try {
			out.close();
		}
		catch (Exception EX){}


	}




	public static void main(String[] args) throws Exception {
		process();

	}

	static final class InputReader {
		private final InputStream stream;
		private final byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		private int read() throws IOException {
			if (curChar >= numChars) {
				curChar = 0;
				numChars = stream.read(buf);
				if (numChars <= 0) {
					return -1;
				}
			}
			return buf[curChar++];
		}


		public final String readString() throws IOException {
			int c = read();
			while (id3(c)) {
				c = read();
			}
			StringBuilder res=new StringBuilder();
			do {
				res.append((char)c);
				c = read();
			} while (!id3(c));
			return res.toString();
		}

		public final int readInt() throws IOException {
			int c = read();
			boolean neg=false;
			while (id3(c)) {
				c = read();
			}
			char d=(char)c;
			

			if (d=='-') {
				neg=true;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id3(c));
			

			if (neg)
				return -res;
			return res;

		}

		public final long readLong() throws IOException {
			int c = read();
			boolean neg=false;
			while (id3(c)) {
				c = read();
			}
			char d=(char)c;
			

			if (d=='-') {
				neg=true;
				c = read();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id3(c));
			

			if (neg)
				return -res;
			return res;

		}




		private boolean id3(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	}


}