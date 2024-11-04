import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.Scanner;



public class Codeforces {
    public static final Scanner IN = new Scanner(System.in);

    public static void main(String[] args) {
        solveCodeforces(readI());
    }

    
    public static void solveCodeforces() {
        System.out.println(goCodeforces());
    }

    
    public static void solveCodeforces(int n) {
        for (int i = 0; i < n; i++) {
            System.out.println(goCodeforces());
        }
    }

    
    public static String goCodeforces() {
        int n = readI();
        int m = readI();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int a = readI();
            sum += a;
        }

        int result = Math.max(sum - m, 0);

        return result + "";
    }

    public static   BigInteger    readBI() {  return IN.nextBigInteger(); }
    public static   BigDecimal    readBD() {  return IN.nextBigDecimal(); }
    public static   String        readLN() {  return IN.nextLine();       }
    public static   String        readS()  {  return IN.next();           }
    public static   char          readC()  {  return IN.next().charAt(0); }
    public static   int           readI()  {  return IN.nextInt();        }
    public static   double        readD()  {  return IN.nextDouble();     }
    public static   long          readL()  {  return IN.nextLong();       }

    
    public static boolean isPalindrome(int a) {
        int r, sum = 0, temp = a;

        while (a > 0) {
            r = a % 10;
            sum = (sum * 10) + r;
            a = a / 10;
        }

        return (temp == sum);
    }

    
    public static boolean isPalindrome(String a) {
        String reverse = "";

        for (int i = a.length() - 1; i >= 0; i--) {
            reverse = reverse + a.charAt(i);
        }

        return a.equals(reverse);
    }

    
    public static boolean isPrime(int n) {
        boolean result = true;

        if (n <= 1) {
            result = false;
        } else {
            for (int i = 2; i < Math.sqrt(n); i++) {
                if (n % i == 0) {
                    result = false;
                    break;
                }
            }
        }

        return result;
    }

    
    public static boolean isPerfectSquare(int num) {
        double sqrt = Math.sqrt(num);

        return ((sqrt - Math.floor(sqrt)) == 0);
    }

    
    public static int primeNumberAt(int n) {
        int num = 1, count = 0, i;

        while (count < n) {
            num++;

            for (i = 2; i <= num; i++) {
                if (num % i == 0) {
                    break;
                }
            }

            if (i == num) {
                count++;
            }
        }

        return num;
    }

    
    public static int sumUpToN(int n) {
        return n * (n + 1) / 2;
    }

    public static int frequency(int n, int... array) {
        int count = 0;

        for (int el : array) {
            if (el == n) {
                count++;
            }
        }

        return count;
    }

    
    public static int reverse(int a) {
        int reverse = 0;

        while(a != 0) {
            int remainder = a % 10;
            reverse = (reverse * 10) + remainder;
            a /= 10;
        }

        return reverse;
    }

    
    public static String combineElements(String symbol, String... array) {
        StringBuilder result = new StringBuilder();

        for (String element : array) {
            result.append(element).append(symbol);
        }

        result.delete(result.lastIndexOf(symbol), result.length());

        return result.toString();
    }

    
    public static String combineElements(String symbol, int... array) {
        StringBuilder result = new StringBuilder();

        for (int element : array) {
            result.append(element).append(symbol);
        }

        result.delete(result.lastIndexOf(symbol), result.length());

        return result.toString();
    }

    
    public static String combineElements(String symbol, char... array) {
        StringBuilder result = new StringBuilder();

        for (char element : array) {
            result.append(element).append(symbol);
        }

        result.delete(result.lastIndexOf(symbol), result.length());

        return result.toString();
    }

    
    public static void printArray(String... array) {
        for (String element : array) {
            System.out.print(element + " ");
        }
    }

    
    public static void printArray(int... array) {
        for (int element : array) {
            System.out.print(element + " ");
        }
    }

    
    public static void printArray(char... array) {
        for (char element : array) {
            System.out.print(element + " ");
        }
    }

    
    public static int GCD(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        if (b == 0) return a;
        return GCD(b, a % b);
    }

    
    public static boolean oddOrNot(int number) {
        return (number & 1) == 0;
    }

    
    public static String simplify(int a, int b) {
        if (a == 0) {
            return "0";
        } else if (b == 0) {
            throw new ArithmeticException("Division by zero");
        } else if (a == b) {
            return "1";
        } else {
            int divisor = GCD(a, b);

            a /= divisor;
            b /= divisor;
        }

        if (b == 1) {
            return a + "";
        } else {
            return a + "/" + b;
        }
    }

    
    public static String simplifyBigIntegers(BigInteger a, BigInteger b) {
        if (a.equals(BigInteger.ZERO)) {
            return "0";
        } else if (b.equals(BigInteger.ZERO)) {
            throw new ArithmeticException("Division by zero");
        } else if (a.equals(b)) {
            return "1";
        } else {
            BigInteger divisor = a.gcd(b);

            a = a.divide(divisor);
            b = b.divide(divisor);
        }

        if (b.equals(BigInteger.ONE)) {
            return a + "";
        } else {
            return a + "/" + b;
        }
    }

    
    public static int countDigits(long a) {
        return (a + "").length();
    }

    
    public static int countDigits(BigInteger a) {
        return a.toString().length();
    }

    
    public static String digitsAfterDecimalPoint(int a, int b, int scale) {
        BigDecimal x = new BigDecimal(a);
        BigDecimal y = new BigDecimal(b);
        ArrayList<Integer> array = new ArrayList<>();

        return x.divide(y, scale, RoundingMode.CEILING).toString();
    }

    
    public static String convert(String input, int from, int to) {
        if (from == to) return input.toUpperCase();
        return Integer.toString(Integer.parseInt(input, from), to).toUpperCase();
    }
}