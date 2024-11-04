import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Map.Entry;


import java.util.Random;
import java.util.TreeSet;

public final class id3
{


	static boolean verb=true;
	static void log(Object X){if (verb) System.err.println(X);}
	static void log(Object[] X){if (verb) {for (Object U:X) System.err.print(U+" ");System.err.println("");}}
	static void log(int[] X){if (verb) {for (int U:X) System.err.print(U+" ");System.err.println("");}}
	static void id0(int[] X){if (verb) {for (int U:X) System.err.print(U+" ");}}
	static void log(int[] X,int L){if (verb) {for (int i=0;i<L;i++) System.err.print(X[i]+" ");System.err.println("");}}
	static void log(long[] X){if (verb) {for (long U:X) System.err.print(U+" ");System.err.println("");}}

	static void id0(Object X){if (verb) System.err.print(X);}
	static void info(Object o){	System.out.println(o);}
	static void output(Object o){id5(""+o+"\n");	}
	static void outputFlush(Object o){try {out.write(""+ o+"\n");out.flush();} catch (Exception e) {}}
	static void id5(Object o){try {out.write(""+ o);} catch (Exception e) {}}




	

	static BufferedWriter out;
	static InputReader reader;



	static long mod;

	static void check() {
		log("checking");
		int id4=10000000;
		Random r=new Random();
		for (int t=0;t<id4;t++) {
			ArrayList<Integer> all=new ArrayList<Integer>();
			ArrayList<Integer> forbid=new ArrayList<Integer>();
			int n=r.nextInt(10)+1;
			int last=-1;
			for (int i=0;i<n;i++) {
				int z=r.nextInt(2);
				all.add(i);
				if (z==1)
					forbid.add(i);
				else last=i;
			}
			if (forbid.size()<all.size()) {
				int L=n;
				int F=forbid.size();
				int hi=L-1;
				int lo=0;
				int z=all.get(hi);
				int idx=Collections.binarySearch(forbid, z);
				int y=-1;
				if (idx<0) {
					y=z;
				} else {
					while (lo+1<hi) {
						int mid=(lo+hi)/2;
						z=all.get(mid);
						idx=Collections.binarySearch(forbid, z);
						if (idx<0) {
							lo=mid;
						} else {
							

							int above1=L-1-mid;
							int above2=F-1-idx;
							if (above1>above2) {
								lo=mid;
							} else {
								hi=mid;
							}
						}
					}
					y=all.get(lo);
				}
				if (y!=last) {
					log("Error");
					log(all);
					log(forbid);
					log(last+" "+y);
					return;
				}

			}

		}

		log("done");
	}

	static void check2() {
		log("check 2");
		int id4=1000000000;
		int NMAX=10000;
		int VMAX=1000000000/2;
		Random r=new Random();

		for (int t=0;t<id4;t++) {
			int n=r.nextInt(NMAX)+3;
			int[][] mat=new int[n][n];
			int[] a=new int[n];
			HashSet<Integer> hs=new HashSet<Integer>();
			ArrayList<Integer> val=new ArrayList<Integer>();
			for (int i=0;i<n;i++) {
				a[i]=r.nextInt(VMAX)+VMAX;
				int LH=hs.size();
				hs.add(a[i]);
				if (LH!=hs.size()) 
					val.add(a[i]);

			}

			int VN=val.size();
			int nn=(VN*(VN-1))/2-1;
			int m=r.nextInt(nn);

			int tot=0;
			int[] X=new int[m];
			int[] Y=new int[m];

			while (tot<m) {
				int e=r.nextInt(VN);
				int f=r.nextInt(VN);
				if (mat[e][f]==0 && e!=f) {
					mat[e][f]=1;
					mat[f][e]=1;
					X[tot]=val.get(e);
					Y[tot]=val.get(f);
					tot++;
				}
			}



			long ans0=id2(a,X,Y,mat,val);
			long ans1=solve(a,X,Y);


			if (ans0!=ans1) {
				log("Error");
				log(1+" "+n+" "+m);
				log(a);
				for (int i=0;i<m;i++) {
					log(X[i]+" "+Y[i]);
				}
				log(ans0);
				log(ans1);
				return;
			}
		}
		log("done");
	}


	static void check3() {
		log("check 3");
		int id4=1000000000;
		int NMAX=300000;
		int VMAX=1000000000/2;
		Random r=new Random();

		for (int t=0;t<id4;t++) {
			log("====");
			

			int n=30;
			int[] a=new int[n];
			HashSet<Integer> hs=new HashSet<Integer>();
			ArrayList<Integer> val=new ArrayList<Integer>();
			for (int i=0;i<n;i++) {
				a[i]=r.nextInt(VMAX)+VMAX;
				int LH=hs.size();
				hs.add(a[i]);
				if (LH!=hs.size()) 
					val.add(a[i]);

			}
			log("step 0");
			long VN=val.size();
			int nn=(int)Math.min(300000,(VN*(VN-1))/2-1);
			int m=r.nextInt(nn);
			log("targeting m:"+m);
			int tot=0;
			int[] X=new int[m];
			int[] Y=new int[m];

			HashSet<String> znx=new HashSet<String>();
			while (tot<m) {
				int e=r.nextInt((int)VN);
				int f=r.nextInt((int)VN);
				if (e!=f) {
					String ss=Math.min(e,f)+" "+Math.max(e, f);
					if (!znx.contains(ss)) {
						X[tot]=val.get(e);
						Y[tot]=val.get(f);
						tot++;
						znx.add(ss);
					}
				}

			}
			log("done");

			

			int[] aa=new int[n];
			int[] XX=new int[m];
			int[] YY=new int[m];
			System.arraycopy(a,0,aa,0,n);
			System.arraycopy(X,0,XX,0,m);
			System.arraycopy(Y,0,YY,0,m);
			log("step 1");

			long ans0=id2(aa,XX,YY);
			log("step 2");
			long ans1=solve(a,X,Y);


			if (ans0!=ans1) {
				log("Error");
				log(1+" "+n+" "+m);
				log(a);
				for (int i=0;i<m;i++) {
					log(X[i]+" "+Y[i]);
				}
				log(ans0);
				log(ans1);
				return;
			}
		}
		log("done");
	}

	static  long id2(int[] a,int[] X,int[] Y,int[][] mat,ArrayList<Integer> val) {
		int n=a.length;
		int m=X.length;
		HashMap<Integer,Integer> cnt=new HashMap<Integer,Integer>();
		for (int x:a) {
			Integer z=cnt.get(x);
			if (z==null) {
				z=0;

			}
			cnt.put(x,z+1);
		}
		int VN=val.size();
		long best=0;
		for (int i=0;i<VN;i++)
			for (int j=0;j<VN;j++)
				if (i!=j && mat[i][j]==0) {
					int x=val.get(i);
					int y=val.get(j);
					int cnx=cnt.get(x);
					int cny=cnt.get(y);
					long cand=x+y;
					cand*=(cnx+cny);
					if (cand>best)
						best=cand;

				}
		return best;
	}

	static  long id2(int[] a,int[] X,int[] Y) {



		HashSet<String> forbid=new HashSet<String>();
		int m=X.length;
		for (int i=0;i<m;i++) {
			forbid.add(Math.min(X[i], Y[i])+" "+Math.max(X[i],Y[i]));
		}

		TreeSet<Integer> ts=new TreeSet<Integer>();
		for (int x:a)
			ts.add(x);
		int L=ts.size();
		int st=0;
		int[] ar=new int[L];
		for (int x:ts) {
			ar[st++]=x;

		}

		HashMap<Integer,Integer> cnt=new HashMap<Integer,Integer>();
		for (int x:a) {
			Integer z=cnt.get(x);
			if (z==null)
				z=0;
			z++;
			cnt.put(x,z);
		}
		long best=0;
		long tgx=-1;
		long tgy=-1;
		for (int i=0;i<L;i++)
			for (int j=i+1;j<L;j++) {
				String s=ar[i]+" "+ar[j];
				if (!forbid.contains(s)) {
					long x=ar[i];
					long y=ar[j];
					int cntx=cnt.get(ar[i]);
					int cnty=cnt.get(ar[j]);
					long cand=(cntx+cnty)*(x+y);
					if (cand>best) {
						best=cand;
						tgx=x;
						tgy=y;
					}

				}
			}
		

		return best;
	}


	

	static long solve(int[] a,int[] X,int[] Y) {
		int n=a.length;
		int m=X.length;
		Arrays.sort(a);


		ArrayList<Integer>[] lst=new ArrayList[n+1];
		for (int u=0;u<=n;u++)
			lst[u]=new ArrayList<Integer>();

		int[] values=new int[n];
		int[] val=new int[n];
		


		TreeSet<Integer> nlst=new TreeSet<Integer>();
		int nx=0;
		int ptr=0;
		int[] cnt=new int[n];

		int prev=-1;
		int id6=0;
		for (int i=0;i<n;i++) {
			if (prev>=0 && a[i]!=prev) {
				

				val[ptr]=prev;
				

				cnt[ptr]=id6;
				nlst.add(id6);
				

				lst[id6].add(ptr);
				ptr++;
				id6=0;
			}
			id6++;
			prev=a[i];
		}

		

		val[ptr]=prev;
		

		cnt[ptr]=id6;
		nlst.add(id6);
		

		lst[id6].add(ptr);

		ptr++;

		int N=ptr;

		HashSet<String> fpairs=new HashSet<String>();
		
		for (int i=0;i<m;i++) {
			

			int x=Arrays.binarySearch(val,0,ptr,X[i]);
			int y=Arrays.binarySearch(val,0,ptr,Y[i]);

			if (x<y)
				fpairs.add(x+" "+y);
			else
				fpairs.add(y+" "+x);
			
		}



		long best=0;

		int LS=nlst.size();
		int st=0;
		int[] tm=new int[LS];
		for (int cn:nlst) {
			tm[st++]=cn;
		}


		for (int tx=0;tx<LS;tx++) {
			int cntx=tm[tx];
			

			for (int sx:lst[cntx]) {
				

				long x=val[sx];
				

				for (int ty=0;ty<=tx;ty++) {

					int cnty=tm[ty];
					int L=lst[cnty].size();
					for (int i=L-1;i>=0;i--) {
						int sy=lst[cnty].get(i);
						long y=val[sy];
						String s="";
						if (sx<sy)
							s=sx+" "+sy;
						else
							s=sy+" "+sx;
						if (sx!=sy && !fpairs.contains(s)) {
							long cand=cntx+cnty;
							cand*=(x+y);
							if (cand>best)
								best=cand;
							break;
						}
					}

				}
			}
		}

		return best;
	}

	static void process() throws Exception {


		out = new BufferedWriter(new OutputStreamWriter(System.out));
		reader = new InputReader(System.in);

		log("hello");


		

		int T=reader.readInt();
		for (int t=0;t<T;t++) {
			int n=reader.readInt();
			int m=reader.readInt();
			int[] a=new int[n];
			for (int i=0;i<n;i++) {
				a[i]=reader.readInt();
			}


			int[] X=new int[m];
			int[] Y=new int[m];



			for (int i=0;i<m;i++) {
				X[i]=reader.readInt();
				Y[i]=reader.readInt();

			}

			long ans=solve(a,X,Y);
			output(ans);



		}

		try {
			out.close();
		} catch (Exception Ex) {
		}


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
			while (id1(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.append((char) c);
				c = read();
			} while (!id1(c));
			return res.toString();
		}

		public final String readString(int L) throws IOException {
			int c = read();
			while (id1(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder(L);
			do {
				res.append((char) c);
				c = read();
			} while (!id1(c));
			return res.toString();
		}

		public final int readInt() throws IOException {
			int c = read();
			boolean neg = false;
			while (id1(c)) {
				c = read();
			}
			char d = (char) c;
			

			if (d == '-') {
				neg = true;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id1(c));
			

			if (neg)
				return -res;
			return res;

		}

		public final long readLong() throws IOException {
			int c = read();
			boolean neg = false;
			while (id1(c)) {
				c = read();
			}
			char d = (char) c;
			

			if (d == '-') {
				neg = true;
				c = read();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id1(c));
			

			if (neg)
				return -res;
			return res;

		}

		private boolean id1(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	}

}
