import java.util.Scanner;

class Main {
    static class Mint {
        static final int MOD = 1000000007;
        long value;

        Mint(long value) {
            this.value = value % MOD;
            if (this.value < 0) this.value += MOD;
        }

        Mint multiply(Mint other) {
            return new Mint(this.value * other.value);
        }

        long val() {
            return this.value;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long q = scanner.nextLong();
        while (q-- > 0) {
            long n = scanner.nextLong();
            long M = n / 4 + 1;
            Mint m = new Mint(M);
            if (n % 4 <= 1) {
                System.out.println(m.multiply(m).val());
            } else {
                System.out.println(m.multiply(new Mint(M + 1)).val());
            }
        }
        scanner.close();
    }
}
