import java.util.*;
import java.io.*;

class Main {
    static final int CR = 7;
    static final int BITS = 15;
    static final int MOD = (int)1e9 + 7;

    static long n;
    static Mint[][][] dp;
    static Mint[][][] cnt;
    static Mint[][] dp2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tt = (int)System.currentTimeMillis();

        dp = new Mint[CR][BITS + 1][CR];
        cnt = new Mint[CR][CR][1 << BITS];
        dp2 = new Mint[5][CR];

        precalc();

        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0){
            n = Long.parseLong(br.readLine());

            solve();
        }

        System.err.println("TIME = " + (System.currentTimeMillis() - tt));
        tt = (int)System.currentTimeMillis();
    }

    static void precalc(){
        dp = new Mint[CR][BITS + 1][CR];
        cnt = new Mint[CR][CR][1 << BITS];

        for(int i = 0; i < CR; i++){
            for(int j = 0; j <= BITS; j++){
                for(int k = 0; k < CR; k++){
                    dp[i][j][k] = new Mint(0);
                }
            }
        }

        for(int i = 0; i < CR; i++){
            dp[i][0][i] = new Mint(1);
        }

        for(int cs = 0; cs < CR; cs++){
            for(int i = 0; i < BITS; i++){
                for(int ct = 0; ct < CR; ct++){
                    for(int x = 0; x < (1 << BITS); x++){
                        if(dp[cs][i][ct].val != 0){
                            for(int cc = 0; cc <= CR; cc++){
                                dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x] = dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x].add(dp[cs][i][ct][x]);
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < CR; i++){
            for(int j = 0; j < CR; j++){
                for(int x = 0; x < (1 << BITS); x++){
                    cnt[i][j][x] = dp[i][BITS][j][x];
                }
            }
        }
    }

    static void solve(){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < CR; j++){
                dp2[i][j] = new Mint(0);
            }
        }

        dp2[0][0] = new Mint(1);

        for(int i = 0; i < 4; i++){
            int x = (int)(n & ((1 << BITS) - 1));
            n >>= BITS;

            for(int j = 0; j < CR; j++){
                for(int k = 0; k < CR; k++){
                    dp2[i + 1][k] = dp2[i + 1][k].add(dp2[i][j].multiply(cnt[j][k][x]));
                }
            }
        }

        System.out.println(dp2[4][0].val);
    }

    static class Mint {
        int val;

        Mint(int v){
            if(v < 0) v = v % MOD + MOD;
            if(v >= MOD) v %= MOD;
            val = v;
        }

        Mint(long v){
            if(v >= MOD) v %= MOD;
            val = (int)v;
        }

        Mint(int v){
            this((long)v);
        }

        Mint inv(){
            return invMod(val);
        }

        Mint pow(long p){
            if(p < 0) return inv().pow(-p);

            Mint a = new Mint(val);
            Mint result = new Mint(1);

            while(p > 0){
                if((p & 1) == 1){
                    result = result.multiply(a);
                }
                a = a.multiply(a);
                p >>= 1;
            }

            return result;
        }

        Mint add(Mint other){
            val -= MOD - other.val;
            if(val < 0) val += MOD;
            return this;
        }

        Mint subtract(Mint other){
            val -= other.val;
            if(val < 0) val += MOD;
            return this;
        }

        Mint multiply(Mint other){
            val = (int)((long)val * other.val % MOD);
            return this;
        }

        Mint divide(Mint other){
            return multiply(other.inv());
        }

        Mint invMod(int a){
            int g = MOD, r = a, x = 0, y = 1;

            while(r != 0){
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                temp = x;
                x = y;
                y = temp;
            }

            return x < 0 ? new Mint(x + MOD) : new Mint(x);
        }
    }
}
