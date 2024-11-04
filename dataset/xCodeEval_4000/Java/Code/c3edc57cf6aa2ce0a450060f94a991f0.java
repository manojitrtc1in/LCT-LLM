import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Codeforces {
    public static final FastReader in = new FastReader();

    public static void main(String[] args) {
        solveCodeforces(in.nextInt());
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
        
        long n = in.nextInt();
        long m = in.nextInt();
        long result = 0;

        result += ((1 + (m - 1)) / 2.) * (m - 1);
        result += ((m + (n * m)) / 2.) * (n);

        return result + "";
    }

    

    static class FastReader {
        BufferedReader BR;
        StringTokenizer ST;

        public FastReader() {
            BR = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (ST == null || !ST.hasMoreElements()) {
                try {
                    ST = new StringTokenizer(BR.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return ST.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble() { return Double.parseDouble(next()); }

        String nextLine() {
            String str = "";

            try {
                if (ST.hasMoreTokens()) {
                    str = ST.nextToken("\n");
                } else {
                    str = BR.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }

            return str;
        }

        int[] readInts(int size) {
            int[] array = new int[size];

            for (int i = 0; i < size; i++) {
                array[i] = nextInt();
            }

            return array;
        }

        String[] readStrings(int size) {
            String[] array = new String[size];

            for (int i = 0; i < size; i++) {
                array[i] = next();
            }

            return array;
        }

        char nextChar() { return next().charAt(0); }

        BigInteger nextBI() { return new BigInteger(next()); }

        BigDecimal nextBD() { return new BigDecimal(next()); }
    }

    public static double arithmeticMean(int... numbers) {
        int sum = 0;
        int size = numbers.length;

        for (int number : numbers) {
            sum += number;
        }

        return (sum * 1.) / size;
    }
    
    public static boolean areAnagram(String str1, String str2) {
        boolean result = false;
        
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        if (str1.length() == str2.length()) {

            char[] charArray1 = str1.toCharArray();
            char[] charArray2 = str2.toCharArray();

            Arrays.sort(charArray1);
            Arrays.sort(charArray2);

            result = Arrays.equals(charArray1, charArray2);
        }
        
        return result;
    }

    
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
        StringBuilder reverse = new StringBuilder();

        for (int i = a.length() - 1; i >= 0; i--) {
            reverse.append(a.charAt(i));
        }

        return a.equals(reverse.toString());
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

    
    public static void printArray(String symbol, String... array) {
        for (String element : array) {
            System.out.print(element + symbol);
        }
    }

    
    public static void printArray(String symbol, int... array) {
        for (int element : array) {
            System.out.print(element + symbol);
        }
    }

    
    public static void printArray(String symbol, char... array) {
        for (char element : array) {
            System.out.print(element + symbol);
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

        return x.divide(y, scale, RoundingMode.CEILING).toString();
    }

    
    public static String systemConvert(String input, int from, int to) {
        if (from == to) return input.toUpperCase();
        return Integer.toString(Integer.parseInt(input, from), to).toUpperCase();
    }
}

enum NumberConverter {
    I(1), IV(4), V(5), IX(9), X(10),
    XL(40), L(50), XC(90), C(100),
    CD(400), D(500), CM(900), M(1000);

    private final int value;

    NumberConverter(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public static List getReverseSortedValues() {
        return Arrays.stream(values())
                .sorted(Comparator.comparing((NumberConverter e) -> e.value).reversed())
                .collect(Collectors.toList());
    }

    public static int romanToArabic(String input) {
        String romanNumeral = input.toUpperCase();

        int result = 0;

        List romanNumerals = Converter.getReverseSortedValues();

        int i = 0;

        while ((romanNumeral.length() > 0) && (i < romanNumerals.size())) {

            Converter symbol = (Converter) romanNumerals.get(i);

            if (romanNumeral.startsWith(symbol.name())) {

                result += symbol.getValue();
                romanNumeral = romanNumeral.substring(symbol.name().length());

            } else {
                i++;
            }
        }

        if (romanNumeral.length() > 0) {
            throw new IllegalArgumentException(input + " cannot be converted to a Roman Numeral");
        }

        if ((result < 1) || (result > 3999)) throw new IllegalArgumentException("ERROR");

        return result;
    }

    public static String arabicToRoman(int number) {
        List romanNumerals = Converter.getReverseSortedValues();

        int i = 0;

        StringBuilder sb = new StringBuilder();

        while ((number > 0) && (i < romanNumerals.size())) {

            Converter currentSymbol = (Converter) romanNumerals.get(i);

            if (currentSymbol.getValue() <= number) {

                sb.append(currentSymbol.name());
                number -= currentSymbol.getValue();

            } else {
                i++;
            }
        }

        return sb.toString();
    }
}