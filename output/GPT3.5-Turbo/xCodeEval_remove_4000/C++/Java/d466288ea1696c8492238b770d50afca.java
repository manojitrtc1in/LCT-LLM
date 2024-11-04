import java.util.Scanner;

class Int {
    private int[] arr;
    private int sign;
    public static int size;
    public static int max = 1000000000;

    public Int(String a) {
        int i;
        arr = new int[Int.size + 1];
        for (i = 0; i <= Int.size; i++)
            arr[i] = 0;
        sign = 0;
        if (a.charAt(0) == '-') {
            sign = 1;
            a = a.substring(1);
        }
        arr[0] = 0;
        while (a.length() > 9) {
            arr[0]++;
            arr[arr[0]] = Int.num(a.substring(a.length() - 9, a.length()));
            a = a.substring(0, a.length() - 9);
        }
        arr[0]++;
        arr[arr[0]] = Int.num(a);
    }

    public Int(Int a) {
        int i;
        arr = new int[Int.size + 1];
        for (i = 0; i <= Int.size; i++)
            arr[i] = 0;
        arr[0] = a.getArr()[0];
        for (i = 1; i <= arr[0]; i++)
            arr[i] = a.getArr()[i];
        sign = a.getSign();
    }

    public Int add(Int a) {
        int[] brr = a.getArr();
        int carry = 0, i;

        if (this.isNegative()) {
            if (a.isNegative()) {
                if (arr[0] >= brr[0]) {
                    for (i = 1; i <= brr[0]; i++) {
                        arr[i] = arr[i] + brr[i] + carry;
                        carry = arr[i] / Int.max;
                        arr[i] %= Int.max;
                    }
                    while (carry != 0) {
                        arr[i] = arr[i] + carry;
                        carry = arr[i] / Int.max;
                        arr[i] %= Int.max;
                        i++;
                    }
                    if (i == arr[0] + 2)
                        arr[0]++;
                } else {
                    Int c = new Int(this), d = new Int(a);
                    this.assign(d.add(c));
                }
            } else {
                if (this.equals(a.negate()))
                    this.assign(new Int("0"));
                else if (this.negate().isGreaterThan(a)) {
                    for (i = 1; i <= brr[0]; i++) {
                        arr[i] = arr[i] - brr[i] + carry;
                        if (arr[i] < 0) {
                            carry = -1;
                            arr[i] += Int.max;
                        } else
                            carry = 0;
                    }
                    while (carry != 0) {
                        arr[i] = arr[i] + carry;
                        if (arr[i] < 0) {
                            carry = -1;
                            arr[i] += Int.max;
                        } else
                            carry = 0;
                        i++;
                    }
                    while (arr[arr[0]] == 0 && arr[0] > 1)
                        arr[0]--;
                } else {
                    Int c = new Int(this), d = new Int(a);
                    this.assign(d.add(c));
                }
            }
        } else {
            if (a.isNegative()) {
                if (this.equals(a.negate()))
                    this.assign(new Int("0"));
                else if (this.isGreaterThan(a.negate())) {
                    for (i = 1; i <= brr[0]; i++) {
                        arr[i] = arr[i] - brr[i] + carry;
                        if (arr[i] < 0) {
                            carry = -1;
                            arr[i] += Int.max;
                        } else
                            carry = 0;
                    }
                    while (carry != 0) {
                        arr[i] = arr[i] + carry;
                        if (arr[i] < 0) {
                            carry = -1;
                            arr[i] += Int.max;
                        } else
                            carry = 0;
                        i++;
                    }
                    while (arr[arr[0]] == 0 && arr[0] > 1)
                        arr[0]--;
                } else {
                    Int c = new Int(this), d = new Int(a);
                    this.assign(d.add(c));
                }
            } else {
                Int c = new Int(this.negate()), d = new Int(a.negate());
                this.assign(d.add(c).negate());
            }
        }
        return this;
    }

    public Int add(String a) {
        return this.add(new Int(a));
    }

    public Int subtract(Int a) {
        return this.add(a.negate());
    }

    public Int subtract(String a) {
        return this.subtract(new Int(a));
    }

    public Int multiply(Int a) {
        int i;
        if (a.equals(new Int("0")))
            this.assign(new Int("0"));
        else if (a.equals(new Int(Int.max + ""))) {
            if (!this.equals(new Int("0"))) {
                for (i = arr[0]; i >= 1; i--)
                    arr[i + 1] = arr[i];
                arr[1] = 0;
                arr[0]++;
            }
        } else if (Int.abs(a).isLessThan(new Int(Int.max + ""))) {
            long tmp;
            int carry = 0;
            int[] brr = a.getArr();
            for (i = 1; i <= arr[0]; i++) {
                tmp = (long) arr[i] * (long) brr[1] + (long) carry;
                arr[i] = (int) (tmp % (long) Int.max);
                carry = (int) (tmp / (long) Int.max);
            }
            if (carry != 0) {
                arr[i] = carry;
                arr[0]++;
            }
        } else {
            Int tmp, res = new Int("0");
            int[] brr = a.getArr();
            for (i = brr[0]; i >= 1; i--) {
                tmp = this.multiply(new Int(brr[i] + ""));
                res = res.multiply(new Int(Int.max + "")).add(tmp);
            }
            this.assign(res);
        }
        sign = (sign + a.getSign()) % 2;
        return this;
    }

    public Int multiply(String a) {
        return this.multiply(new Int(a));
    }

    public Int negate() {
        Int c = new Int(this);
        c.setSign((sign + 1) % 2);
        return c;
    }

    public boolean isGreaterThan(Int a) {
        int[] brr = a.getArr();
        int i;
        if (sign != a.getSign())
            return sign < a.getSign();
        if (sign == 0) {
            if (arr[0] != brr[0])
                return arr[0] > brr[0];
            for (i = arr[0]; i >= 1; i--)
                if (arr[i] != brr[i])
                    return arr[i] > brr[i];
            return false;
        }
        if (arr[0] != brr[0])
            return arr[0] < brr[0];
        for (i = arr[0]; i >= 1; i--)
            if (arr[i] != brr[i])
                return arr[i] < brr[i];
        return false;
    }

    public boolean isLessThan(Int a) {
        return a.isGreaterThan(this);
    }

    public boolean equals(Int a) {
        return !(a.isGreaterThan(this) || a.isLessThan(this));
    }

    public boolean isNotEqual(Int a) {
        return !this.equals(a);
    }

    public boolean isLessThanOrEqual(Int a) {
        return !this.isGreaterThan(a);
    }

    public boolean isGreaterThanOrEqual(Int a) {
        return !this.isLessThan(a);
    }

    public boolean isGreaterThan(String a) {
        return this.isGreaterThan(new Int(a));
    }

    public boolean isLessThan(String a) {
        return this.isLessThan(new Int(a));
    }

    public boolean equals(String a) {
        return this.equals(new Int(a));
    }

    public boolean isNotEqual(String a) {
        return this.isNotEqual(new Int(a));
    }

    public boolean isLessThanOrEqual(String a) {
        return this.isLessThanOrEqual(new Int(a));
    }

    public boolean isGreaterThanOrEqual(String a) {
        return this.isGreaterThanOrEqual(new Int(a));
    }

    public Int negateAndAssign() {
        this.assign(this.negate());
        return this;
    }

    public Int addAndAssign(Int a) {
        return this.add(a);
    }

    public Int addAndAssign(String a) {
        return this.add(a);
    }

    public Int subtractAndAssign(Int a) {
        return this.subtract(a);
    }

    public Int subtractAndAssign(String a) {
        return this.subtract(a);
    }

    public Int multiplyAndAssign(Int a) {
        return this.multiply(a);
    }

    public Int multiplyAndAssign(String a) {
        return this.multiply(a);
    }

    public String toString() {
        StringBuilder res = new StringBuilder();
        int i, j, k;
        int[] brr = this.getArr();
        if (this.isNegative())
            res.append('-');
        res.append(brr[brr[0]]);
        for (i = brr[0] - 1; i >= 1; i--) {
            k = Int.max;
            for (j = 0; j < 9; j++)
                res.append((char) ((brr[i] % k) / (k /= 10) + '0'));
        }
        return res.toString();
    }

    public int[] getArr() {
        return arr;
    }

    public int getSign() {
        return sign;
    }

    public void setSign(int k) {
        sign = k;
    }

    public static void setSize(int k) {
        Int.size = k;
    }

    public static int num(String a) {
        int res = 0, i;
        for (i = 0; i < a.length(); i++)
            res = res * 10 + a.charAt(i) - '0';
        return res;
    }

    public static String str(int a) {
        StringBuilder res = new StringBuilder();
        int h = (a < 0 ? 1 : 0);
        a = (a < 0 ? -a : a);
        while (a != 0) {
            res.insert(0, (char) (a % 10 + '0'));
            a /= 10;
        }
        if (res.length() == 0)
            res.append('0');
        if (h == 1)
            res.insert(0, '-');
        return res.toString();
    }

    public static Int abs(Int a) {
        return a.isNegative() ? a.negate() : a;
    }
}

public class d466288ea1696c8492238b770d50afcaxcodeeval_processed_4000.json {
    private static int qanak;

    private static Int solve(String s, int h) {
        boolean[] u = new boolean[26];
        Int answer = new Int("1");
        int k = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '?')
                k++;
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')
                u[s.charAt(i) - 'A'] = true;
        }
        for (int i = 0; i < k; ++i)
            qanak++;

        k = 0;
        for (int i = 0; i < 26; ++i)
            if (u[i])
                k++;
        if (k > 10)
            return new Int("0");
        for (int i = 0; i < k; ++i)
            answer = answer.multiply(new Int("10").subtract(new Int(i + h + "")));
        return answer;
    }

    public static void main(String[] args) {
        qanak = 0;
        Int.setSize(12);
        Int answer = new Int("0");
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        if (s.length() == 1) {
            if (s.charAt(0) == '?' || (s.charAt(0) >= 'A' && s.charAt(0) <= 'Z'))
                answer = new Int("9");
            else
                answer = new Int("1");
            System.out.println(answer);
            return;
        }
        if (s.charAt(0) == '?') {
            String st = s.substring(1);
            answer = new Int("9").multiply(solve(st));
        } else if (s.charAt(0) >= 'A' && s.charAt(0) <= 'Z') {
            for (int k = 1; k < 10; ++k) {
                String st = s;
                qanak = 0;
                for (int i = 0; i < st.length(); ++i)
                    if (st.charAt(i) == s.charAt(0))
                        st = st.substring(0, i) + (char) ('0' + k) + st.substring(i + 1);
                answer = answer.add(solve(st, 1));
            }
        } else
            answer = solve(s);
        System.out.print(answer);
        for (int i = 0; i < qanak; ++i)
            System.out.print(0);
        System.out.println();
    }
}
