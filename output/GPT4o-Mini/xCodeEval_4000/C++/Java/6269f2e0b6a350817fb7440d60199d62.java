import java.util.Scanner;

class Main {
    static class ModInt {
        private static final int MOD = 1000000007;
        private long value;

        public ModInt(long value) {
            this.value = value % MOD;
            if (this.value < 0) this.value += MOD;
        }

        public long val() {
            return value;
        }

        public ModInt add(ModInt other) {
            return new ModInt(this.value + other.value);
        }

        public ModInt multiply(ModInt other) {
