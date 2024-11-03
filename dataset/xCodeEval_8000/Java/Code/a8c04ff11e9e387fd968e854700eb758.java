import java.util.*;
import java.math.*;












public class E {
	static char [] in = new char [100000];
	static long MOD = 1000003;
	public static void main (String [] arg) throws Throwable {
		
		
		long [] pr = {0, 1,2,3,5,7,11,13,17,19,23};
		

		long [][] array = new long [pr.length][11];
		array[0][0] = 1;
		for (int i = 1; i<array.length; ++i) {
			array[i][0] = 1;
			long pow = 1;
			for (int j = 1; j<array[i].length; ++j) {
				pow = (pow * pr[i]) % MOD;
				array[i][j] = pow;
			}
			

		}
		
		
		long [][] b = new long [pr.length][1];
		for (int i = 0; i<pr.length; ++i) {
			System.out.println("? " + pr[i]);
			System.out.flush();
			b[i][0] = nextInt();
			if (b[i][0] == -1) return;
		}
		
		Matrix A = new Matrix(array);
		Matrix b2 = new Matrix(b);
		Matrix x = A.solve(b2);
		
		long[] a = new long [pr.length];
		for (int i = 0; i<pr.length; ++i) {
			
			a[i] = (MOD + x.A[i][0]) % MOD;
		}
		

		
		for (long i = 0; i<MOD; ++i) {
			long eval = a[0];
			long pow = 1;
			for (int j = 1; j<a.length; ++j) {
				pow = (pow * i) % MOD;
				eval += pow * a[j];
				eval %= MOD;
			}
			while (eval < 0) eval += MOD;
			if (eval%MOD == 0) {
				System.out.println("! " + i);
				System.out.flush();
				return;
			}
		}
		System.out.println("! -1");
		System.out.flush();
		

		

		
		
	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	public static long nextLong() throws Throwable {
		long i = System.in.read();boolean neg = false;while (i < 45) i = System.in.read();if (i == 45) {neg=true;i=48;}i = i - 48;
		int j = System.in.read();while (j > 32) {i*=10;i+=j-48;j = System.in.read();}return (neg) ? -i : i;
	}
	public static int nextInt() throws Throwable {return (int)nextLong();}
	public static String next() throws Throwable {
		int i = 0; while (i < 40 && i != -1) i = System.in.read(); int cptr = 0; while (i >= 40) { in[cptr++] = (char)i; i = System.in.read();}
		return new String(in, 0,cptr);
	}
	
	public static long gcdL(long a, long b) {while (b != 0) {long tmp = b;b = (a % b);a = tmp;}return a;}
	public static int gcd(int a, int b) {while (b != 0) {int tmp = b;b = (a % b);a = tmp;}return a;}
	public static int[] sieve(int LIM) {
		int i,count = 0;
		boolean [] b = new boolean [LIM];
		for (i = 2;i<LIM; ++i) if (!b[i]) {count++; for (int j = i<<1; j<LIM; j+=i) b[j] = true;}
		int [] primes = new int[count];
		for (i = 2,count=0;i<LIM;++i) if (!b[i]) primes[count++] = i;
		return primes;
	}
	public static int[] numPrimeFactors(int LIM) {
		int i,count = 0;
		int [] b = new int [LIM];
		for (i = 2;i<LIM; ++i) if (b[i] == 0) {count++; for (int j = i; j<LIM; j+=i) b[j]++;}
		return b;
	}
	public static long moddiv(long a) {
		a = (a+MOD) % MOD;
		return BigInteger.valueOf(a).modInverse(BigInteger.valueOf(MOD)).longValue();
	}
	public static long[][] invert2(long a[][]) 
    {
        int n = a.length;
        long x[][] = new long[n][n];
        long b[][] = new long[n][n];
        int index[] = new int[n];
        for (int i=0; i<n; ++i) 
            b[i][i] = 1;
 
 

        gaussian(a, index);
 
 

        for (int i=0; i<n-1; ++i)
            for (int j=i+1; j<n; ++j)
                for (int k=0; k<n; ++k)
                    b[index[j]][k]
                    	    = (b[index[j]][k]- ((a[index[j]][i]*b[index[i]][k])%MOD) + MOD) % MOD;
 
 

        for (int i=0; i<n; ++i) 
        {
            x[n-1][i] = (b[index[n-1]][i] * moddiv(a[index[n-1]][n-1])) % MOD;
            for (int j=n-2; j>=0; --j) 
            {
                x[j][i] = b[index[j]][i];
                for (int k=j+1; k<n; ++k) 
                {
                    x[j][i] -= (a[index[j]][k]*x[k][i]) % MOD;
					x[j][i] = (x[j][i] + MOD) % MOD;
                }
                x[j][i] *= moddiv(a[index[j]][j]);
				x[j][i] %= MOD;
            }
        }
        return x;
    }
 




 
    public static void gaussian(long a[][], int index[]) 
    {
        int n = index.length;
        long c[] = new long[n];
 
 

        for (int i=0; i<n; ++i) 
            index[i] = i;
 
 

        for (int i=0; i<n; ++i) 
        {
            long c1 = 0;
            for (int j=0; j<n; ++j) 
            {
                long c0 = Math.abs(a[i][j]);
                if (c0 > c1) c1 = c0;
            }
            c[i] = c1;
        }
 
 

        int k = 0;
        for (int j=0; j<n-1; ++j) 
        {
            long pi1 = 0;
            for (int i=j; i<n; ++i) 
            {
                long pi0 = Math.abs(a[index[i]][j]);
                pi0 /= c[index[i]] + 0;
                if (pi0 > pi1) 
                {
                    pi1 = pi0;
                    k = i;
                }
            }
 
   

            int itmp = index[j];
            index[j] = index[k];
            index[k] = itmp;
            for (int i=j+1; i<n; ++i) 	
            {
                long pj = a[index[i]][j] * moddiv(a[index[j]][j]);
				pj %= MOD;
 
 

                a[index[i]][j] = pj;
 
 

                for (int l=j+1; l<n; ++l) 
                    a[index[i]][l] = (a[index[i]][l] - ((pj*a[index[j]][l])%MOD) + MOD) % MOD;
					
            }
        }
    }
}

class Matrix2 {
	static long MOD = 1000003;
	private static long determinant(long[][] matrix) {
		if (matrix.length != matrix[0].length)
			throw new IllegalStateException("invalid dimensions");

		if (matrix.length == 2)
			return (MOD + matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % MOD;

		long det = 0;
		for (int i = 0; i < matrix[0].length; i++) {
			det += (Math.pow(-1, i) * matrix[0][i]
					* determinant(minor(matrix, 0, i)));
			det = (det + MOD) % MOD;
		}
		return det;
	}

	public static long[][] inverse(long[][] matrix) {
		long [][] inverse = new long[matrix.length][matrix.length];

		

		for (int i = 0; i < matrix.length; i++)
			for (int j = 0; j < matrix[i].length; j++)
				inverse[i][j] = (MOD + (long)Math.pow(-1, i + j)
						* determinant(minor(matrix, i, j))) % MOD;

		

		long det = BigInteger.valueOf( determinant(matrix)).modInverse(BigInteger.valueOf(MOD)).longValue();
		for (int i = 0; i < inverse.length; i++) {
			for (int j = 0; j <= i; j++) {
				long temp = inverse[i][j];
				inverse[i][j] = (inverse[j][i] * det) % MOD;
				inverse[j][i] = (temp * det) % MOD;
			}
		}

		return inverse;
	}

	private static long[][] minor(long[][] matrix, int row, int column) {
		long[][] minor = new long[matrix.length - 1][matrix.length - 1];

		for (int i = 0; i < matrix.length; i++)
			for (int j = 0; i != row && j < matrix[i].length; j++)
				if (j != column)
					minor[i < row ? i : i - 1][j < column ? j : j - 1] = matrix[i][j];
		return minor;
	}

	private static long[][] multiply(long[][] a, long[][] b) {
		if (a[0].length != b.length)
			throw new IllegalStateException("invalid dimensions");

		long[][] matrix = new long[a.length][b[0].length];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b[0].length; j++) {
				long sum = 0;
				for (int k = 0; k < a[i].length; k++)
					sum += a[i][k] * b[k][j];
				matrix[i][j] = sum;
			}
		}

		return matrix;
	}

	private static long[][] transpose(long[][] matrix) {
		long[][] transpose = new long[matrix[0].length][matrix.length];

		for (int i = 0; i < matrix.length; i++)
			for (int j = 0; j < matrix[i].length; j++)
				transpose[j][i] = matrix[i][j];
		return transpose;
	}
}

class Matrix implements Cloneable, java.io.Serializable {



   
   public long[][] A;

   
   public int m, n;
   public String toString() { 
	String s = "";
	for (int i = 0; i<m; ++i) s+= Arrays.toString(A[i]) + "\n";
	return s;
   }



   

   public Matrix (int m, int n) {
      this.m = m;
      this.n = n;
      A = new long[m][n];
   }

   

   public Matrix (int m, int n, long s) {
      this.m = m;
      this.n = n;
      A = new long[m][n];
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            A[i][j] = s;
         }
      }
   }

   

   public Matrix (long[][] A) {
      m = A.length;
      n = A[0].length;
      for (int i = 0; i < m; i++) {
         if (A[i].length != n) {
            throw new IllegalArgumentException("All rows must have the same length.");
         }
      }
      this.A = A;
   }

   

   public Matrix (long[][] A, int m, int n) {
      this.A = A;
      this.m = m;
      this.n = n;
   }

   

   public Matrix (long vals[], int m) {
      this.m = m;
      n = (m != 0 ? vals.length/m : 0);
      if (m*n != vals.length) {
         throw new IllegalArgumentException("Array length must be a multiple of m.");
      }
      A = new long[m][n];
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            A[i][j] = vals[i+j*m];
         }
      }
   }



   

   public static Matrix constructWithCopy(long[][] A) {
      int m = A.length;
      int n = A[0].length;
      Matrix X = new Matrix(m,n);
      long[][] C = X.getArray();
      for (int i = 0; i < m; i++) {
         if (A[i].length != n) {
            throw new IllegalArgumentException
               ("All rows must have the same length.");
         }
         for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j];
         }
      }
      return X;
   }

   

   public Matrix copy () {
      Matrix X = new Matrix(m,n);
      long[][] C = X.getArray();
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j];
         }
      }
      return X;
   }

   

   public Object clone () {
      return this.copy();
   }

   

   public long[][] getArray () {
      return A;
   }

   

   public long[][] getArrayCopy () {
      long[][] C = new long[m][n];
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j];
         }
      }
      return C;
   }

   

   public long[] getColumnPackedCopy () {
      long[] vals = new long[m*n];
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            vals[i+j*m] = A[i][j];
         }
      }
      return vals;
   }

   

   public long[] getRowPackedCopy () {
      long[] vals = new long[m*n];
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            vals[i*n+j] = A[i][j];
         }
      }
      return vals;
   }

   

   public int getRowDimension () {
      return m;
   }

   

   public int getColumnDimension () {
      return n;
   }

   

   public long get (int i, int j) {
      return A[i][j];
   }

   

   public Matrix getMatrix (int i0, int i1, int j0, int j1) {
      Matrix X = new Matrix(i1-i0+1,j1-j0+1);
      long[][] B = X.getArray();
      try {
         for (int i = i0; i <= i1; i++) {
            for (int j = j0; j <= j1; j++) {
               B[i-i0][j-j0] = A[i][j];
            }
         }
      } catch(ArrayIndexOutOfBoundsException e) {
         throw new ArrayIndexOutOfBoundsException("Submatrix indices");
      }
      return X;
   }

   

   public Matrix getMatrix (int[] r, int[] c) {
      Matrix X = new Matrix(r.length,c.length);
      long[][] B = X.getArray();
      try {
         for (int i = 0; i < r.length; i++) {
            for (int j = 0; j < c.length; j++) {
               B[i][j] = A[r[i]][c[j]];
            }
         }
      } catch(ArrayIndexOutOfBoundsException e) {
         throw new ArrayIndexOutOfBoundsException("Submatrix indices");
      }
      return X;
   }

   

   public Matrix getMatrix (int i0, int i1, int[] c) {
      Matrix X = new Matrix(i1-i0+1,c.length);
      long[][] B = X.getArray();
      try {
         for (int i = i0; i <= i1; i++) {
            for (int j = 0; j < c.length; j++) {
               B[i-i0][j] = A[i][c[j]];
            }
         }
      } catch(ArrayIndexOutOfBoundsException e) {
         throw new ArrayIndexOutOfBoundsException("Submatrix indices");
      }
      return X;
   }

   

   public Matrix getMatrix (int[] r, int j0, int j1) {
      Matrix X = new Matrix(r.length,j1-j0+1);
      long[][] B = X.getArray();
      try {
         for (int i = 0; i < r.length; i++) {
            for (int j = j0; j <= j1; j++) {
               B[i][j-j0] = A[r[i]][j];
            }
         }
      } catch(ArrayIndexOutOfBoundsException e) {
         throw new ArrayIndexOutOfBoundsException("Submatrix indices");
      }
      return X;
   }

   

   public void set (int i, int j, long s) {
      A[i][j] = s;
   }

   

   public void setMatrix (int i0, int i1, int j0, int j1, Matrix X) {
      try {
         for (int i = i0; i <= i1; i++) {
            for (int j = j0; j <= j1; j++) {
               A[i][j] = X.get(i-i0,j-j0);
            }
         }
      } catch(ArrayIndexOutOfBoundsException e) {
         throw new ArrayIndexOutOfBoundsException("Submatrix indices");
      }
   }

   

   public void setMatrix (int[] r, int[] c, Matrix X) {
      try {
         for (int i = 0; i < r.length; i++) {
            for (int j = 0; j < c.length; j++) {
               A[r[i]][c[j]] = X.get(i,j);
            }
         }
      } catch(ArrayIndexOutOfBoundsException e) {
         throw new ArrayIndexOutOfBoundsException("Submatrix indices");
      }
   }

   

   public void setMatrix (int[] r, int j0, int j1, Matrix X) {
      try {
         for (int i = 0; i < r.length; i++) {
            for (int j = j0; j <= j1; j++) {
               A[r[i]][j] = X.get(i,j-j0);
            }
         }
      } catch(ArrayIndexOutOfBoundsException e) {
         throw new ArrayIndexOutOfBoundsException("Submatrix indices");
      }
   }

   

   public void setMatrix (int i0, int i1, int[] c, Matrix X) {
      try {
         for (int i = i0; i <= i1; i++) {
            for (int j = 0; j < c.length; j++) {
               A[i][c[j]] = X.get(i-i0,j);
            }
         }
      } catch(ArrayIndexOutOfBoundsException e) {
         throw new ArrayIndexOutOfBoundsException("Submatrix indices");
      }
   }

   

   public Matrix transpose () {
      Matrix X = new Matrix(n,m);
      long[][] C = X.getArray();
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            C[j][i] = A[i][j];
         }
      }
      return X;
   }

   

   public long norm1 () {
      long f = 0;
      for (int j = 0; j < n; j++) {
         long s = 0;
         for (int i = 0; i < m; i++) {
            s += Math.abs(A[i][j]);
         }
         f = Math.max(f,s);
      }
      return f;
   }


   

   public long normInf () {
      long f = 0;
      for (int i = 0; i < m; i++) {
         long s = 0;
         for (int j = 0; j < n; j++) {
            s += Math.abs(A[i][j]);
         }
         f = Math.max(f,s);
      }
      return f;
   }

   

   public Matrix uminus () {
      Matrix X = new Matrix(m,n);
      long[][] C = X.getArray();
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            C[i][j] = -A[i][j];
         }
      }
      return X;
   }

   

   public Matrix plus (Matrix B) {
      checkMatrixDimensions(B);
      Matrix X = new Matrix(m,n);
      long[][] C = X.getArray();
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B.A[i][j];
         }
      }
      return X;
   }

   

   public Matrix plusEquals (Matrix B) {
      checkMatrixDimensions(B);
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            A[i][j] = A[i][j] + B.A[i][j];
         }
      }
      return this;
   }

   

   public Matrix minus (Matrix B) {
      checkMatrixDimensions(B);
      Matrix X = new Matrix(m,n);
      long[][] C = X.getArray();
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B.A[i][j];
         }
      }
      return X;
   }

   

   public Matrix minusEquals (Matrix B) {
      checkMatrixDimensions(B);
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            A[i][j] = A[i][j] - B.A[i][j];
         }
      }
      return this;
   }

   

   public Matrix arrayTimes (Matrix B) {
      checkMatrixDimensions(B);
      Matrix X = new Matrix(m,n);
      long[][] C = X.getArray();
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] * B.A[i][j];
         }
      }
      return X;
   }

   

   public Matrix arrayTimesEquals (Matrix B) {
      checkMatrixDimensions(B);
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            A[i][j] = A[i][j] * B.A[i][j];
         }
      }
      return this;
   }

   

   public Matrix arrayRightDivide (Matrix B) {
      checkMatrixDimensions(B);
      Matrix X = new Matrix(m,n);
      long[][] C = X.getArray();
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] / B.A[i][j];
         }
      }
      return X;
   }

   

   public Matrix arrayRightDivideEquals (Matrix B) {
      checkMatrixDimensions(B);
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            A[i][j] = A[i][j] / B.A[i][j];
         }
      }
      return this;
   }

   

   public Matrix arrayLeftDivide (Matrix B) {
      checkMatrixDimensions(B);
      Matrix X = new Matrix(m,n);
      long[][] C = X.getArray();
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            C[i][j] = B.A[i][j] / A[i][j];
         }
      }
      return X;
   }

   

   public Matrix arrayLeftDivideEquals (Matrix B) {
      checkMatrixDimensions(B);
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            A[i][j] = B.A[i][j] / A[i][j];
         }
      }
      return this;
   }

   

   public Matrix times (long s) {
      Matrix X = new Matrix(m,n);
      long[][] C = X.getArray();
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            C[i][j] = s*A[i][j];
         }
      }
      return X;
   }

   

   public Matrix timesEquals (long s) {
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            A[i][j] = s*A[i][j];
         }
      }
      return this;
   }

   

   public Matrix times (Matrix B) {
      if (B.m != n) {
         throw new IllegalArgumentException("Matrix inner dimensions must agree.");
      }
      Matrix X = new Matrix(m,B.n);
      long[][] C = X.getArray();
      long[] Bcolj = new long[n];
      for (int j = 0; j < B.n; j++) {
         for (int k = 0; k < n; k++) {
            Bcolj[k] = B.A[k][j];
         }
         for (int i = 0; i < m; i++) {
            long[] Arowi = A[i];
            long s = 0;
            for (int k = 0; k < n; k++) {
               s += Arowi[k]*Bcolj[k];
            }
            C[i][j] = s;
         }
      }
      return X;
   }

   

   

   

   



   

   

   

   


   

   

   

   


   

   

   

   


   

   public Matrix solve (Matrix B) {
      return (new LUDecomposition(this)).solve(B);
   }

   

   public Matrix solveTranspose (Matrix B) {
      return transpose().solve(B.transpose());
   }

   

   public Matrix inverse () {
      return solve(identity(m,m));
   }

   



   



   



   

   public long trace () {
      long t = 0;
      for (int i = 0; i < Math.min(m,n); i++) {
         t += A[i][i];
      }
      return t;
   }

   

   public static Matrix identity (int m, int n) {
      Matrix A = new Matrix(m,n);
      long[][] X = A.getArray();
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            X[i][j] = (i == j ? 1 : 0);
         }
      }
      return A;
   }




   

   private void checkMatrixDimensions (Matrix B) {
      if (B.m != m || B.n != n) {
         throw new IllegalArgumentException("Matrix dimensions must agree.");
      }
   }
     
   
public class LUDecomposition implements java.io.Serializable {
	long MOD = 1000003;
	public long moddiv(long a) {
		a = (a+MOD) % MOD;
		return BigInteger.valueOf(a).modInverse(BigInteger.valueOf(MOD)).longValue();
	}


   
   private long[][] LU;

   
   private int m, n, pivsign; 

   
   private int[] piv;



   

   public LUDecomposition (Matrix A) {

   


      LU = A.getArrayCopy();
      m = A.getRowDimension();
      n = A.getColumnDimension();
      piv = new int[m];
      for (int i = 0; i < m; i++) {
         piv[i] = i;
      }
      pivsign = 1;
      long[] LUrowi;
      long[] LUcolj = new long[m];

      


      for (int j = 0; j < n; j++) {

         


         for (int i = 0; i < m; i++) {
            LUcolj[i] = LU[i][j];
         }

         


         for (int i = 0; i < m; i++) {
            LUrowi = LU[i];

            


            int kmax = Math.min(i,j);
            long s = 0;
            for (int k = 0; k < kmax; k++) {
               s += (LUrowi[k]*LUcolj[k]) % MOD;
            }
			s %= MOD;

            LUrowi[j] = LUcolj[i] -= s;
			LUrowi[j] = (LUrowi[j] + MOD) % MOD;
			LUrowi[i] = (LUrowi[i] + MOD) % MOD;
         }
   
         


         int p = j;
         for (int i = j+1; i < m; i++) {
            if (Math.abs(LUcolj[i]) > Math.abs(LUcolj[p])) {
               p = i;
            }
         }
         if (p != j) {
            for (int k = 0; k < n; k++) {
               long t = LU[p][k]; LU[p][k] = LU[j][k]; LU[j][k] = t;
            }
            int k = piv[p]; piv[p] = piv[j]; piv[j] = k;
            pivsign = -pivsign;
         }

         

         
         if (j < m & LU[j][j] != 0) {
            for (int i = j+1; i < m; i++) {
               LU[i][j] *= moddiv(LU[j][j]);
			   LU[i][j] %= MOD;
            }
         }
      }
   }



   

   public boolean isNonsingular () {
      for (int j = 0; j < n; j++) {
         if (LU[j][j] == 0)
            return false;
      }
      return true;
   }

   

   public Matrix getL () {
      Matrix X = new Matrix(m,n);
      long[][] L = X.getArray();
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            if (i > j) {
               L[i][j] = LU[i][j];
            } else if (i == j) {
               L[i][j] = 1;
            } else {
               L[i][j] = 0;
            }
         }
      }
      return X;
   }

   

   public Matrix getU () {
      Matrix X = new Matrix(n,n);
      long[][] U = X.getArray();
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (i <= j) {
               U[i][j] = LU[i][j];
            } else {
               U[i][j] = 0;
            }
         }
      }
      return X;
   }

   

   public Matrix solve (Matrix B) {
      if (B.getRowDimension() != m) {
         throw new IllegalArgumentException("Matrix row dimensions must agree.");
      }
      if (!this.isNonsingular()) {
         throw new RuntimeException("Matrix is singular.");
      }

      

      int nx = B.getColumnDimension();
      Matrix Xmat = B.getMatrix(piv,0,nx-1);
      long[][] X = Xmat.getArray();

      

      for (int k = 0; k < n; k++) {
         for (int i = k+1; i < n; i++) {
            for (int j = 0; j < nx; j++) {
               X[i][j] = (MOD + X[i][j] - (X[k][j]*LU[i][k]) % MOD) % MOD;
            }
         }
      }
      

      for (int k = n-1; k >= 0; k--) {
         for (int j = 0; j < nx; j++) {
            X[k][j] = (X[k][j] * moddiv(LU[k][k])) % MOD;
         }
         for (int i = 0; i < k; i++) {
            for (int j = 0; j < nx; j++) {
			   X[i][j] = (MOD + X[i][j] - (X[k][j]*LU[i][k]) % MOD) % MOD;
            }
         }
      }
      return Xmat;
   }
}


}


