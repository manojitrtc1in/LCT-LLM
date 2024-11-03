





































using namespace std;


typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;


typedef pair<ll, ll> pii;
const ll N = 1000005, mod = 998244353, M = 1005;
const ll inf = 1000000000000000000;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, k, i, j, ans, kaskad[N];
vector<ll> v;
ll cesh[200][20];
ll sum(ll n)
{
    ll ret = 0;
    while (n != 0)
    {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
string solven(ll n, ll k)
{
    short dig = 9 - k;
    ll x = n - k * (k + 1) / 2;
    x /= (k + 1);
    string number;
    do
    {
        short dig = min(x, 9ll);
        number += char('0' + dig);
        x -= dig;
    } while (x != 0);
    if (number.back() - '0' > dig)
    {
        char ch = '0';
        ch += number.back() - '0' - dig;
        number = ch + number;
        number.back() = char(dig + '0');
    }
    while (number.back() - '0' < dig)
    {
        bool flag = false;
        for (int i = 0; i < number.size() - 1; ++i)
        {
            if (number[i] > '1')
            {
                number[i]--;
                number.back()++;
                flag = true;
                break;
            }
        }
        if (!flag)
            break;
    }
    return number;
}
void solve()
{
    cin >> n >> k;
    if (n < k * (k + 1) / 2)
    {
        cout << -1 << endl;
        return;
    }
    if (k >= 2 || cesh[n][k] != 0)
    {
        cout << cesh[n][k] << endl;
        return;
    }
    if (n <= 30)
    {
        for (int i = 0; i < 100000; ++i)
        {
            ll s = 0;
            for (int j = i; j <= i + k; ++j)
                s += sum(j);
            if (s == n)
            {
                cesh[n][k] = i;
                cout << i << endl;
                return;
            }
        }
        cesh[n][k] = -1;
        cout << -1 << endl;
        return;
    }
    if (k == 0 || (k == 1 && n % 2 == 1))
    {
        cout << solven(n, k) << endl;
        return;
    }
    ll x = (n - 8) / 2;
    string xx = solven(x, 0);
    char ch = xx.back();
    xx.back() = '8';
    xx += ch;
    cout << xx << endl;
    return;
}
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cesh[0][2] = -1;
    cesh[1][2] = -1;
    cesh[2][2] = -1;
    cesh[3][2] = 0;
    cesh[4][2] = -1;
    cesh[5][2] = -1;
    cesh[6][2] = 1;
    cesh[7][2] = -1;
    cesh[8][2] = -1;
    cesh[9][2] = 2;
    cesh[10][2] = -1;
    cesh[11][2] = -1;
    cesh[12][2] = 3;
    cesh[13][2] = -1;
    cesh[14][2] = -1;
    cesh[15][2] = 4;
    cesh[16][2] = -1;
    cesh[17][2] = -1;
    cesh[18][2] = 5;
    cesh[19][2] = -1;
    cesh[20][2] = -1;
    cesh[21][2] = 6;
    cesh[22][2] = -1;
    cesh[23][2] = -1;
    cesh[24][2] = 7;
    cesh[25][2] = -1;
    cesh[26][2] = -1;
    cesh[27][2] = 17;
    cesh[28][2] = -1;
    cesh[29][2] = -1;
    cesh[30][2] = 27;
    cesh[31][2] = -1;
    cesh[32][2] = -1;
    cesh[33][2] = 37;
    cesh[34][2] = -1;
    cesh[35][2] = -1;
    cesh[36][2] = 47;
    cesh[37][2] = -1;
    cesh[38][2] = -1;
    cesh[39][2] = 57;
    cesh[40][2] = -1;
    cesh[41][2] = -1;
    cesh[42][2] = 67;
    cesh[43][2] = -1;
    cesh[44][2] = -1;
    cesh[45][2] = 77;
    cesh[46][2] = -1;
    cesh[47][2] = -1;
    cesh[48][2] = 87;
    cesh[49][2] = -1;
    cesh[50][2] = -1;
    cesh[51][2] = 97;
    cesh[52][2] = -1;
    cesh[53][2] = -1;
    cesh[54][2] = 197;
    cesh[55][2] = -1;
    cesh[56][2] = -1;
    cesh[57][2] = 297;
    cesh[58][2] = -1;
    cesh[59][2] = -1;
    cesh[60][2] = 397;
    cesh[61][2] = -1;
    cesh[62][2] = -1;
    cesh[63][2] = 497;
    cesh[64][2] = -1;
    cesh[65][2] = -1;
    cesh[66][2] = 597;
    cesh[67][2] = -1;
    cesh[68][2] = -1;
    cesh[69][2] = 697;
    cesh[70][2] = -1;
    cesh[71][2] = -1;
    cesh[72][2] = 797;
    cesh[73][2] = -1;
    cesh[74][2] = -1;
    cesh[75][2] = 897;
    cesh[76][2] = -1;
    cesh[77][2] = -1;
    cesh[78][2] = 997;
    cesh[79][2] = -1;
    cesh[80][2] = -1;
    cesh[81][2] = 1997;
    cesh[82][2] = -1;
    cesh[83][2] = -1;
    cesh[84][2] = 2997;
    cesh[85][2] = -1;
    cesh[86][2] = -1;
    cesh[87][2] = 3997;
    cesh[88][2] = -1;
    cesh[89][2] = -1;
    cesh[90][2] = 4997;
    cesh[91][2] = -1;
    cesh[92][2] = -1;
    cesh[93][2] = 5997;
    cesh[94][2] = -1;
    cesh[95][2] = -1;
    cesh[96][2] = 6997;
    cesh[97][2] = -1;
    cesh[98][2] = -1;
    cesh[99][2] = 7997;
    cesh[100][2] = -1;
    cesh[101][2] = -1;
    cesh[102][2] = 8997;
    cesh[103][2] = -1;
    cesh[104][2] = -1;
    cesh[105][2] = 9997;
    cesh[106][2] = -1;
    cesh[107][2] = -1;
    cesh[108][2] = 19997;
    cesh[109][2] = -1;
    cesh[110][2] = -1;
    cesh[111][2] = 29997;
    cesh[112][2] = -1;
    cesh[113][2] = -1;
    cesh[114][2] = 39997;
    cesh[115][2] = -1;
    cesh[116][2] = -1;
    cesh[117][2] = 49997;
    cesh[118][2] = -1;
    cesh[119][2] = -1;
    cesh[120][2] = 59997;
    cesh[121][2] = -1;
    cesh[122][2] = -1;
    cesh[123][2] = 69997;
    cesh[124][2] = -1;
    cesh[125][2] = -1;
    cesh[126][2] = 79997;
    cesh[127][2] = -1;
    cesh[128][2] = -1;
    cesh[129][2] = 89997;
    cesh[130][2] = -1;
    cesh[131][2] = -1;
    cesh[132][2] = 99997;
    cesh[133][2] = -1;
    cesh[134][2] = -1;
    cesh[135][2] = 199997;
    cesh[136][2] = -1;
    cesh[137][2] = -1;
    cesh[138][2] = 299997;
    cesh[139][2] = -1;
    cesh[140][2] = -1;
    cesh[141][2] = 399997;
    cesh[142][2] = -1;
    cesh[143][2] = -1;
    cesh[144][2] = 499997;
    cesh[145][2] = -1;
    cesh[146][2] = -1;
    cesh[147][2] = 599997;
    cesh[148][2] = -1;
    cesh[149][2] = -1;
    cesh[150][2] = 699997;
    cesh[0][3] = -1;
    cesh[0][4] = -1;
    cesh[0][5] = -1;
    cesh[0][6] = -1;
    cesh[0][7] = -1;
    cesh[0][8] = -1;
    cesh[0][9] = -1;
    cesh[1][3] = -1;
    cesh[1][4] = -1;
    cesh[1][5] = -1;
    cesh[1][6] = -1;
    cesh[1][7] = -1;
    cesh[1][8] = -1;
    cesh[1][9] = -1;
    cesh[2][3] = -1;
    cesh[2][4] = -1;
    cesh[2][5] = -1;
    cesh[2][6] = -1;
    cesh[2][7] = -1;
    cesh[2][8] = -1;
    cesh[2][9] = -1;
    cesh[3][3] = -1;
    cesh[3][4] = -1;
    cesh[3][5] = -1;
    cesh[3][6] = -1;
    cesh[3][7] = -1;
    cesh[3][8] = -1;
    cesh[3][9] = -1;
    cesh[4][3] = -1;
    cesh[4][4] = -1;
    cesh[4][5] = -1;
    cesh[4][6] = -1;
    cesh[4][7] = -1;
    cesh[4][8] = -1;
    cesh[4][9] = -1;
    cesh[5][3] = -1;
    cesh[5][4] = -1;
    cesh[5][5] = -1;
    cesh[5][6] = -1;
    cesh[5][7] = -1;
    cesh[5][8] = -1;
    cesh[5][9] = -1;
    cesh[6][3] = 0;
    cesh[6][4] = -1;
    cesh[6][5] = -1;
    cesh[6][6] = -1;
    cesh[6][7] = -1;
    cesh[6][8] = -1;
    cesh[6][9] = -1;
    cesh[7][3] = -1;
    cesh[7][4] = -1;
    cesh[7][5] = -1;
    cesh[7][6] = -1;
    cesh[7][7] = -1;
    cesh[7][8] = -1;
    cesh[7][9] = -1;
    cesh[8][3] = -1;
    cesh[8][4] = -1;
    cesh[8][5] = -1;
    cesh[8][6] = -1;
    cesh[8][7] = -1;
    cesh[8][8] = -1;
    cesh[8][9] = -1;
    cesh[9][3] = -1;
    cesh[9][4] = -1;
    cesh[9][5] = -1;
    cesh[9][6] = -1;
    cesh[9][7] = -1;
    cesh[9][8] = -1;
    cesh[9][9] = -1;
    cesh[10][3] = 1;
    cesh[10][4] = 0;
    cesh[10][5] = -1;
    cesh[10][6] = -1;
    cesh[10][7] = -1;
    cesh[10][8] = -1;
    cesh[10][9] = -1;
    cesh[11][3] = -1;
    cesh[11][4] = -1;
    cesh[11][5] = -1;
    cesh[11][6] = -1;
    cesh[11][7] = -1;
    cesh[11][8] = -1;
    cesh[11][9] = -1;
    cesh[12][3] = -1;
    cesh[12][4] = -1;
    cesh[12][5] = -1;
    cesh[12][6] = -1;
    cesh[12][7] = -1;
    cesh[12][8] = -1;
    cesh[12][9] = -1;
    cesh[13][3] = -1;
    cesh[13][4] = -1;
    cesh[13][5] = -1;
    cesh[13][6] = -1;
    cesh[13][7] = -1;
    cesh[13][8] = -1;
    cesh[13][9] = -1;
    cesh[14][3] = 2;
    cesh[14][4] = -1;
    cesh[14][5] = -1;
    cesh[14][6] = -1;
    cesh[14][7] = -1;
    cesh[14][8] = -1;
    cesh[14][9] = -1;
    cesh[15][3] = 9;
    cesh[15][4] = 1;
    cesh[15][5] = 0;
    cesh[15][6] = -1;
    cesh[15][7] = -1;
    cesh[15][8] = -1;
    cesh[15][9] = -1;
    cesh[16][3] = -1;
    cesh[16][4] = -1;
    cesh[16][5] = -1;
    cesh[16][6] = -1;
    cesh[16][7] = -1;
    cesh[16][8] = -1;
    cesh[16][9] = -1;
    cesh[17][3] = -1;
    cesh[17][4] = -1;
    cesh[17][5] = -1;
    cesh[17][6] = -1;
    cesh[17][7] = -1;
    cesh[17][8] = -1;
    cesh[17][9] = -1;
    cesh[18][3] = 3;
    cesh[18][4] = -1;
    cesh[18][5] = -1;
    cesh[18][6] = -1;
    cesh[18][7] = -1;
    cesh[18][8] = -1;
    cesh[18][9] = -1;
    cesh[19][3] = 19;
    cesh[19][4] = 9;
    cesh[19][5] = -1;
    cesh[19][6] = -1;
    cesh[19][7] = -1;
    cesh[19][8] = -1;
    cesh[19][9] = -1;
    cesh[20][3] = 8;
    cesh[20][4] = 2;
    cesh[20][5] = -1;
    cesh[20][6] = -1;
    cesh[20][7] = -1;
    cesh[20][8] = -1;
    cesh[20][9] = -1;
    cesh[21][3] = -1;
    cesh[21][4] = -1;
    cesh[21][5] = 1;
    cesh[21][6] = 0;
    cesh[21][7] = -1;
    cesh[21][8] = -1;
    cesh[21][9] = -1;
    cesh[22][3] = 4;
    cesh[22][4] = -1;
    cesh[22][5] = -1;
    cesh[22][6] = -1;
    cesh[22][7] = -1;
    cesh[22][8] = -1;
    cesh[22][9] = -1;
    cesh[23][3] = 29;
    cesh[23][4] = 8;
    cesh[23][5] = -1;
    cesh[23][6] = -1;
    cesh[23][7] = -1;
    cesh[23][8] = -1;
    cesh[23][9] = -1;
    cesh[24][3] = 18;
    cesh[24][4] = 19;
    cesh[24][5] = 9;
    cesh[24][6] = -1;
    cesh[24][7] = -1;
    cesh[24][8] = -1;
    cesh[24][9] = -1;
    cesh[25][3] = 7;
    cesh[25][4] = 3;
    cesh[25][5] = -1;
    cesh[25][6] = -1;
    cesh[25][7] = -1;
    cesh[25][8] = -1;
    cesh[25][9] = -1;
    cesh[26][3] = 5;
    cesh[26][4] = -1;
    cesh[26][5] = -1;
    cesh[26][6] = -1;
    cesh[26][7] = -1;
    cesh[26][8] = -1;
    cesh[26][9] = -1;
    cesh[27][3] = 39;
    cesh[27][4] = 7;
    cesh[27][5] = 2;
    cesh[27][6] = -1;
    cesh[27][7] = -1;
    cesh[27][8] = -1;
    cesh[27][9] = -1;
    cesh[28][3] = 28;
    cesh[28][4] = 18;
    cesh[28][5] = -1;
    cesh[28][6] = 1;
    cesh[28][7] = 0;
    cesh[28][8] = -1;
    cesh[28][9] = -1;
    cesh[29][3] = 17;
    cesh[29][4] = 29;
    cesh[29][5] = -1;
    cesh[29][6] = -1;
    cesh[29][7] = -1;
    cesh[29][8] = -1;
    cesh[29][9] = -1;
    cesh[30][3] = 6;
    cesh[30][4] = 4;
    cesh[30][5] = 7;
    cesh[30][6] = 9;
    cesh[30][7] = -1;
    cesh[30][8] = -1;
    cesh[30][9] = -1;
    cesh[31][3] = 49;
    cesh[31][4] = 6;
    cesh[31][5] = -1;
    cesh[31][6] = -1;
    cesh[31][7] = -1;
    cesh[31][8] = -1;
    cesh[31][9] = -1;
    cesh[32][3] = 38;
    cesh[32][4] = 17;
    cesh[32][5] = -1;
    cesh[32][6] = 8;
    cesh[32][7] = -1;
    cesh[32][8] = -1;
    cesh[32][9] = -1;
    cesh[33][3] = 27;
    cesh[33][4] = 28;
    cesh[33][5] = 3;
    cesh[33][6] = -1;
    cesh[33][7] = -1;
    cesh[33][8] = -1;
    cesh[33][9] = -1;
    cesh[34][3] = 16;
    cesh[34][4] = 39;
    cesh[34][5] = -1;
    cesh[34][6] = 7;
    cesh[34][7] = -1;
    cesh[34][8] = -1;
    cesh[34][9] = -1;
    cesh[35][3] = 59;
    cesh[35][4] = 5;
    cesh[35][5] = -1;
    cesh[35][6] = 2;
    cesh[35][7] = -1;
    cesh[35][8] = -1;
    cesh[35][9] = -1;
    cesh[36][3] = 48;
    cesh[36][4] = 16;
    cesh[36][5] = 5;
    cesh[36][6] = 6;
    cesh[36][7] = 1;
    cesh[36][8] = 0;
    cesh[36][9] = -1;
    cesh[37][3] = 37;
    cesh[37][4] = 27;
    cesh[37][5] = -1;
    cesh[37][6] = 19;
    cesh[37][7] = 9;
    cesh[37][8] = -1;
    cesh[37][9] = -1;
    cesh[38][3] = 26;
    cesh[38][4] = 38;
    cesh[38][5] = -1;
    cesh[38][6] = 5;
    cesh[38][7] = 8;
    cesh[38][8] = -1;
    cesh[38][9] = -1;
    cesh[39][3] = 69;
    cesh[39][4] = 49;
    cesh[39][5] = 4;
    cesh[39][6] = 18;
    cesh[39][7] = 7;
    cesh[39][8] = -1;
    cesh[39][9] = -1;
    cesh[40][3] = 58;
    cesh[40][4] = 15;
    cesh[40][5] = -1;
    cesh[40][6] = 4;
    cesh[40][7] = 6;
    cesh[40][8] = -1;
    cesh[40][9] = -1;
    cesh[41][3] = 47;
    cesh[41][4] = 26;
    cesh[41][5] = -1;
    cesh[41][6] = 17;
    cesh[41][7] = 5;
    cesh[41][8] = -1;
    cesh[41][9] = -1;
    cesh[42][3] = 36;
    cesh[42][4] = 37;
    cesh[42][5] = 15;
    cesh[42][6] = 3;
    cesh[42][7] = 4;
    cesh[42][8] = -1;
    cesh[42][9] = -1;
    cesh[43][3] = 79;
    cesh[43][4] = 48;
    cesh[43][5] = -1;
    cesh[43][6] = 16;
    cesh[43][7] = 3;
    cesh[43][8] = -1;
    cesh[43][9] = -1;
    cesh[44][3] = 68;
    cesh[44][4] = 59;
    cesh[44][5] = -1;
    cesh[44][6] = 29;
    cesh[44][7] = 2;
    cesh[44][8] = -1;
    cesh[44][9] = -1;
    cesh[45][3] = 57;
    cesh[45][4] = 25;
    cesh[45][5] = 14;
    cesh[45][6] = 15;
    cesh[45][7] = 19;
    cesh[45][8] = 1;
    cesh[45][9] = 0;
    cesh[46][3] = 46;
    cesh[46][4] = 36;
    cesh[46][5] = -1;
    cesh[46][6] = 28;
    cesh[46][7] = 18;
    cesh[46][8] = -1;
    cesh[46][9] = 1;
    cesh[47][3] = 89;
    cesh[47][4] = 47;
    cesh[47][5] = -1;
    cesh[47][6] = 14;
    cesh[47][7] = 17;
    cesh[47][8] = -1;
    cesh[47][9] = 2;
    cesh[48][3] = 78;
    cesh[48][4] = 58;
    cesh[48][5] = 25;
    cesh[48][6] = 27;
    cesh[48][7] = 16;
    cesh[48][8] = -1;
    cesh[48][9] = 3;
    cesh[49][3] = 67;
    cesh[49][4] = 69;
    cesh[49][5] = -1;
    cesh[49][6] = 13;
    cesh[49][7] = 15;
    cesh[49][8] = -1;
    cesh[49][9] = 4;
    cesh[50][3] = 56;
    cesh[50][4] = 35;
    cesh[50][5] = -1;
    cesh[50][6] = 26;
    cesh[50][7] = 14;
    cesh[50][8] = -1;
    cesh[50][9] = 5;
    cesh[51][3] = 189;
    cesh[51][4] = 46;
    cesh[51][5] = 24;
    cesh[51][6] = 39;
    cesh[51][7] = 13;
    cesh[51][8] = -1;
    cesh[51][9] = 6;
    cesh[52][3] = 88;
    cesh[52][4] = 57;
    cesh[52][5] = -1;
    cesh[52][6] = 25;
    cesh[52][7] = 12;
    cesh[52][8] = -1;
    cesh[52][9] = 7;
    cesh[53][3] = 77;
    cesh[53][4] = 68;
    cesh[53][5] = -1;
    cesh[53][6] = 38;
    cesh[53][7] = 29;
    cesh[53][8] = -1;
    cesh[53][9] = 8;
    cesh[54][3] = 66;
    cesh[54][4] = 79;
    cesh[54][5] = 35;
    cesh[54][6] = 24;
    cesh[54][7] = 28;
    cesh[54][8] = 11;
    cesh[54][9] = 9;
    cesh[55][3] = 289;
    cesh[55][4] = 45;
    cesh[55][5] = -1;
    cesh[55][6] = 37;
    cesh[55][7] = 27;
    cesh[55][8] = -1;
    cesh[55][9] = 10;
    cesh[56][3] = 188;
    cesh[56][4] = 56;
    cesh[56][5] = -1;
    cesh[56][6] = 23;
    cesh[56][7] = 26;
    cesh[56][8] = -1;
    cesh[56][9] = 11;
    cesh[57][3] = 87;
    cesh[57][4] = 67;
    cesh[57][5] = 34;
    cesh[57][6] = 36;
    cesh[57][7] = 25;
    cesh[57][8] = -1;
    cesh[57][9] = 12;
    cesh[58][3] = 76;
    cesh[58][4] = 78;
    cesh[58][5] = -1;
    cesh[58][6] = 49;
    cesh[58][7] = 24;
    cesh[58][8] = -1;
    cesh[58][9] = 13;
    cesh[59][3] = 389;
    cesh[59][4] = 89;
    cesh[59][5] = -1;
    cesh[59][6] = 35;
    cesh[59][7] = 23;
    cesh[59][8] = -1;
    cesh[59][9] = 14;
    cesh[60][3] = 288;
    cesh[60][4] = 55;
    cesh[60][5] = 45;
    cesh[60][6] = 48;
    cesh[60][7] = 22;
    cesh[60][8] = -1;
    cesh[60][9] = 15;
    cesh[61][3] = 187;
    cesh[61][4] = 66;
    cesh[61][5] = -1;
    cesh[61][6] = 34;
    cesh[61][7] = 39;
    cesh[61][8] = -1;
    cesh[61][9] = 16;
    cesh[62][3] = 86;
    cesh[62][4] = 77;
    cesh[62][5] = -1;
    cesh[62][6] = 47;
    cesh[62][7] = 38;
    cesh[62][8] = -1;
    cesh[62][9] = 17;
    cesh[63][3] = 489;
    cesh[63][4] = 88;
    cesh[63][5] = 44;
    cesh[63][6] = 33;
    cesh[63][7] = 37;
    cesh[63][8] = 21;
    cesh[63][9] = 18;
    cesh[64][3] = 388;
    cesh[64][4] = 189;
    cesh[64][5] = -1;
    cesh[64][6] = 46;
    cesh[64][7] = 36;
    cesh[64][8] = -1;
    cesh[64][9] = 19;
    cesh[65][3] = 287;
    cesh[65][4] = 65;
    cesh[65][5] = -1;
    cesh[65][6] = 59;
    cesh[65][7] = 35;
    cesh[65][8] = -1;
    cesh[65][9] = 20;
    cesh[66][3] = 96;
    cesh[66][4] = 76;
    cesh[66][5] = 55;
    cesh[66][6] = 45;
    cesh[66][7] = 34;
    cesh[66][8] = -1;
    cesh[66][9] = 21;
    cesh[67][3] = 589;
    cesh[67][4] = 87;
    cesh[67][5] = -1;
    cesh[67][6] = 58;
    cesh[67][7] = 33;
    cesh[67][8] = -1;
    cesh[67][9] = 22;
    cesh[68][3] = 488;
    cesh[68][4] = 188;
    cesh[68][5] = -1;
    cesh[68][6] = 44;
    cesh[68][7] = 32;
    cesh[68][8] = -1;
    cesh[68][9] = 23;
    cesh[69][3] = 387;
    cesh[69][4] = 289;
    cesh[69][5] = 54;
    cesh[69][6] = 57;
    cesh[69][7] = 49;
    cesh[69][8] = -1;
    cesh[69][9] = 24;
    cesh[70][3] = 196;
    cesh[70][4] = 75;
    cesh[70][5] = -1;
    cesh[70][6] = 43;
    cesh[70][7] = 48;
    cesh[70][8] = -1;
    cesh[70][9] = 25;
    cesh[71][3] = 689;
    cesh[71][4] = 86;
    cesh[71][5] = -1;
    cesh[71][6] = 56;
    cesh[71][7] = 47;
    cesh[71][8] = -1;
    cesh[71][9] = 26;
    cesh[72][3] = 588;
    cesh[72][4] = 187;
    cesh[72][5] = 65;
    cesh[72][6] = 69;
    cesh[72][7] = 46;
    cesh[72][8] = 31;
    cesh[72][9] = 27;
    cesh[73][3] = 487;
    cesh[73][4] = 288;
    cesh[73][5] = -1;
    cesh[73][6] = 55;
    cesh[73][7] = 45;
    cesh[73][8] = -1;
    cesh[73][9] = 28;
    cesh[74][3] = 296;
    cesh[74][4] = 389;
    cesh[74][5] = -1;
    cesh[74][6] = 68;
    cesh[74][7] = 44;
    cesh[74][8] = -1;
    cesh[74][9] = 29;
    cesh[75][3] = 789;
    cesh[75][4] = 85;
    cesh[75][5] = 64;
    cesh[75][6] = 54;
    cesh[75][7] = 43;
    cesh[75][8] = -1;
    cesh[75][9] = 30;
    cesh[76][3] = 688;
    cesh[76][4] = 186;
    cesh[76][5] = -1;
    cesh[76][6] = 67;
    cesh[76][7] = 42;
    cesh[76][8] = -1;
    cesh[76][9] = 31;
    cesh[77][3] = 587;
    cesh[77][4] = 287;
    cesh[77][5] = -1;
    cesh[77][6] = 53;
    cesh[77][7] = 59;
    cesh[77][8] = -1;
    cesh[77][9] = 32;
    cesh[78][3] = 396;
    cesh[78][4] = 388;
    cesh[78][5] = 75;
    cesh[78][6] = 66;
    cesh[78][7] = 58;
    cesh[78][8] = -1;
    cesh[78][9] = 33;
    cesh[79][3] = 889;
    cesh[79][4] = 489;
    cesh[79][5] = -1;
    cesh[79][6] = 79;
    cesh[79][7] = 57;
    cesh[79][8] = -1;
    cesh[79][9] = 34;
    cesh[80][3] = 788;
    cesh[80][4] = 95;
    cesh[80][5] = -1;
    cesh[80][6] = 65;
    cesh[80][7] = 56;
    cesh[80][8] = -1;
    cesh[80][9] = 35;
    cesh[81][3] = 687;
    cesh[81][4] = 286;
    cesh[81][5] = 74;
    cesh[81][6] = 78;
    cesh[81][7] = 55;
    cesh[81][8] = 41;
    cesh[81][9] = 36;
    cesh[82][3] = 496;
    cesh[82][4] = 387;
    cesh[82][5] = -1;
    cesh[82][6] = 64;
    cesh[82][7] = 54;
    cesh[82][8] = -1;
    cesh[82][9] = 37;
    cesh[83][3] = 989;
    cesh[83][4] = 488;
    cesh[83][5] = -1;
    cesh[83][6] = 77;
    cesh[83][7] = 53;
    cesh[83][8] = -1;
    cesh[83][9] = 38;
    cesh[84][3] = 888;
    cesh[84][4] = 589;
    cesh[84][5] = 85;
    cesh[84][6] = 63;
    cesh[84][7] = 52;
    cesh[84][8] = -1;
    cesh[84][9] = 39;
    cesh[85][3] = 787;
    cesh[85][4] = 195;
    cesh[85][5] = -1;
    cesh[85][6] = 76;
    cesh[85][7] = 69;
    cesh[85][8] = -1;
    cesh[85][9] = 40;
    cesh[86][3] = 596;
    cesh[86][4] = 386;
    cesh[86][5] = -1;
    cesh[86][6] = 89;
    cesh[86][7] = 68;
    cesh[86][8] = -1;
    cesh[86][9] = 41;
    cesh[87][3] = 1989;
    cesh[87][4] = 487;
    cesh[87][5] = 84;
    cesh[87][6] = 75;
    cesh[87][7] = 67;
    cesh[87][8] = -1;
    cesh[87][9] = 42;
    cesh[88][3] = 988;
    cesh[88][4] = 588;
    cesh[88][5] = -1;
    cesh[88][6] = 88;
    cesh[88][7] = 66;
    cesh[88][8] = -1;
    cesh[88][9] = 43;
    cesh[89][3] = 887;
    cesh[89][4] = 689;
    cesh[89][5] = -1;
    cesh[89][6] = 74;
    cesh[89][7] = 65;
    cesh[89][8] = -1;
    cesh[89][9] = 44;
    cesh[90][3] = 696;
    cesh[90][4] = 295;
    cesh[90][5] = 185;
    cesh[90][6] = 87;
    cesh[90][7] = 64;
    cesh[90][8] = 51;
    cesh[90][9] = 45;
    cesh[91][3] = 2989;
    cesh[91][4] = 486;
    cesh[91][5] = -1;
    cesh[91][6] = 73;
    cesh[91][7] = 63;
    cesh[91][8] = -1;
    cesh[91][9] = 46;
    cesh[92][3] = 1988;
    cesh[92][4] = 587;
    cesh[92][5] = -1;
    cesh[92][6] = 86;
    cesh[92][7] = 62;
    cesh[92][8] = -1;
    cesh[92][9] = 47;
    cesh[93][3] = 987;
    cesh[93][4] = 688;
    cesh[93][5] = 94;
    cesh[93][6] = 189;
    cesh[93][7] = 79;
    cesh[93][8] = -1;
    cesh[93][9] = 48;
    cesh[94][3] = 796;
    cesh[94][4] = 789;
    cesh[94][5] = -1;
    cesh[94][6] = 85;
    cesh[94][7] = 78;
    cesh[94][8] = -1;
    cesh[94][9] = 49;
    cesh[95][3] = 3989;
    cesh[95][4] = 395;
    cesh[95][5] = -1;
    cesh[95][6] = 188;
    cesh[95][7] = 77;
    cesh[95][8] = -1;
    cesh[95][9] = 50;
    cesh[96][3] = 2988;
    cesh[96][4] = 586;
    cesh[96][5] = 285;
    cesh[96][6] = 84;
    cesh[96][7] = 76;
    cesh[96][8] = -1;
    cesh[96][9] = 51;
    cesh[97][3] = 1987;
    cesh[97][4] = 687;
    cesh[97][5] = -1;
    cesh[97][6] = 187;
    cesh[97][7] = 75;
    cesh[97][8] = -1;
    cesh[97][9] = 52;
    cesh[98][3] = 896;
    cesh[98][4] = 788;
    cesh[98][5] = -1;
    cesh[98][6] = 83;
    cesh[98][7] = 74;
    cesh[98][8] = -1;
    cesh[98][9] = 53;
    cesh[99][3] = 4989;
    cesh[99][4] = 889;
    cesh[99][5] = 194;
    cesh[99][6] = 186;
    cesh[99][7] = 73;
    cesh[99][8] = 61;
    cesh[99][9] = 54;
    cesh[100][3] = 3988;
    cesh[100][4] = 495;
    cesh[100][5] = -1;
    cesh[100][6] = 289;
    cesh[100][7] = 72;
    cesh[100][8] = -1;
    cesh[100][9] = 55;
    cesh[101][3] = 2987;
    cesh[101][4] = 686;
    cesh[101][5] = -1;
    cesh[101][6] = 185;
    cesh[101][7] = 89;
    cesh[101][8] = -1;
    cesh[101][9] = 56;
    cesh[102][3] = 996;
    cesh[102][4] = 787;
    cesh[102][5] = 385;
    cesh[102][6] = 288;
    cesh[102][7] = 88;
    cesh[102][8] = -1;
    cesh[102][9] = 57;
    cesh[103][3] = 5989;
    cesh[103][4] = 888;
    cesh[103][5] = -1;
    cesh[103][6] = 184;
    cesh[103][7] = 87;
    cesh[103][8] = -1;
    cesh[103][9] = 58;
    cesh[104][3] = 4988;
    cesh[104][4] = 989;
    cesh[104][5] = -1;
    cesh[104][6] = 287;
    cesh[104][7] = 86;
    cesh[104][8] = -1;
    cesh[104][9] = 59;
    cesh[105][3] = 3987;
    cesh[105][4] = 595;
    cesh[105][5] = 294;
    cesh[105][6] = 93;
    cesh[105][7] = 85;
    cesh[105][8] = -1;
    cesh[105][9] = 60;
    cesh[106][3] = 1996;
    cesh[106][4] = 786;
    cesh[106][5] = -1;
    cesh[106][6] = 286;
    cesh[106][7] = 84;
    cesh[106][8] = -1;
    cesh[106][9] = 61;
    cesh[107][3] = 6989;
    cesh[107][4] = 887;
    cesh[107][5] = -1;
    cesh[107][6] = 389;
    cesh[107][7] = 83;
    cesh[107][8] = -1;
    cesh[107][9] = 62;
    cesh[108][3] = 5988;
    cesh[108][4] = 988;
    cesh[108][5] = 485;
    cesh[108][6] = 285;
    cesh[108][7] = 82;
    cesh[108][8] = 71;
    cesh[108][9] = 63;
    cesh[109][3] = 4987;
    cesh[109][4] = 1989;
    cesh[109][5] = -1;
    cesh[109][6] = 388;
    cesh[109][7] = 189;
    cesh[109][8] = -1;
    cesh[109][9] = 64;
    cesh[110][3] = 2996;
    cesh[110][4] = 695;
    cesh[110][5] = -1;
    cesh[110][6] = 284;
    cesh[110][7] = 188;
    cesh[110][8] = -1;
    cesh[110][9] = 65;
    cesh[111][3] = 7989;
    cesh[111][4] = 886;
    cesh[111][5] = 394;
    cesh[111][6] = 387;
    cesh[111][7] = 187;
    cesh[111][8] = -1;
    cesh[111][9] = 66;
    cesh[112][3] = 6988;
    cesh[112][4] = 987;
    cesh[112][5] = -1;
    cesh[112][6] = 193;
    cesh[112][7] = 186;
    cesh[112][8] = -1;
    cesh[112][9] = 67;
    cesh[113][3] = 5987;
    cesh[113][4] = 1988;
    cesh[113][5] = -1;
    cesh[113][6] = 386;
    cesh[113][7] = 185;
    cesh[113][8] = -1;
    cesh[113][9] = 68;
    cesh[114][3] = 3996;
    cesh[114][4] = 2989;
    cesh[114][5] = 585;
    cesh[114][6] = 489;
    cesh[114][7] = 184;
    cesh[114][8] = -1;
    cesh[114][9] = 69;
    cesh[115][3] = 8989;
    cesh[115][4] = 795;
    cesh[115][5] = -1;
    cesh[115][6] = 385;
    cesh[115][7] = 183;
    cesh[115][8] = -1;
    cesh[115][9] = 70;
    cesh[116][3] = 7988;
    cesh[116][4] = 986;
    cesh[116][5] = -1;
    cesh[116][6] = 488;
    cesh[116][7] = 92;
    cesh[116][8] = -1;
    cesh[116][9] = 71;
    cesh[117][3] = 6987;
    cesh[117][4] = 1987;
    cesh[117][5] = 494;
    cesh[117][6] = 384;
    cesh[117][7] = 289;
    cesh[117][8] = 81;
    cesh[117][9] = 72;
    cesh[118][3] = 4996;
    cesh[118][4] = 2988;
    cesh[118][5] = -1;
    cesh[118][6] = 487;
    cesh[118][7] = 288;
    cesh[118][8] = -1;
    cesh[118][9] = 73;
    cesh[119][3] = 9989;
    cesh[119][4] = 3989;
    cesh[119][5] = -1;
    cesh[119][6] = 293;
    cesh[119][7] = 287;
    cesh[119][8] = -1;
    cesh[119][9] = 74;
    cesh[120][3] = 8988;
    cesh[120][4] = 895;
    cesh[120][5] = 685;
    cesh[120][6] = 486;
    cesh[120][7] = 286;
    cesh[120][8] = -1;
    cesh[120][9] = 75;
    cesh[121][3] = 7987;
    cesh[121][4] = 1986;
    cesh[121][5] = -1;
    cesh[121][6] = 589;
    cesh[121][7] = 285;
    cesh[121][8] = -1;
    cesh[121][9] = 76;
    cesh[122][3] = 5996;
    cesh[122][4] = 2987;
    cesh[122][5] = -1;
    cesh[122][6] = 485;
    cesh[122][7] = 284;
    cesh[122][8] = -1;
    cesh[122][9] = 77;
    cesh[123][3] = 19989;
    cesh[123][4] = 3988;
    cesh[123][5] = 594;
    cesh[123][6] = 588;
    cesh[123][7] = 283;
    cesh[123][8] = -1;
    cesh[123][9] = 78;
    cesh[124][3] = 9988;
    cesh[124][4] = 4989;
    cesh[124][5] = -1;
    cesh[124][6] = 484;
    cesh[124][7] = 192;
    cesh[124][8] = -1;
    cesh[124][9] = 79;
    cesh[125][3] = 8987;
    cesh[125][4] = 995;
    cesh[125][5] = -1;
    cesh[125][6] = 587;
    cesh[125][7] = 389;
    cesh[125][8] = -1;
    cesh[125][9] = 80;
    cesh[126][3] = 6996;
    cesh[126][4] = 2986;
    cesh[126][5] = 785;
    cesh[126][6] = 393;
    cesh[126][7] = 388;
    cesh[126][8] = 91;
    cesh[126][9] = 81;
    cesh[127][3] = 29989;
    cesh[127][4] = 3987;
    cesh[127][5] = -1;
    cesh[127][6] = 586;
    cesh[127][7] = 387;
    cesh[127][8] = -1;
    cesh[127][9] = 82;
    cesh[128][3] = 19988;
    cesh[128][4] = 4988;
    cesh[128][5] = -1;
    cesh[128][6] = 689;
    cesh[128][7] = 386;
    cesh[128][8] = -1;
    cesh[128][9] = 83;
    cesh[129][3] = 9987;
    cesh[129][4] = 5989;
    cesh[129][5] = 694;
    cesh[129][6] = 585;
    cesh[129][7] = 385;
    cesh[129][8] = -1;
    cesh[129][9] = 84;
    cesh[130][3] = 7996;
    cesh[130][4] = 1995;
    cesh[130][5] = -1;
    cesh[130][6] = 688;
    cesh[130][7] = 384;
    cesh[130][8] = -1;
    cesh[130][9] = 85;
    cesh[131][3] = 39989;
    cesh[131][4] = 3986;
    cesh[131][5] = -1;
    cesh[131][6] = 584;
    cesh[131][7] = 383;
    cesh[131][8] = -1;
    cesh[131][9] = 86;
    cesh[132][3] = 29988;
    cesh[132][4] = 4987;
    cesh[132][5] = 885;
    cesh[132][6] = 687;
    cesh[132][7] = 292;
    cesh[132][8] = -1;
    cesh[132][9] = 87;
    cesh[133][3] = 19987;
    cesh[133][4] = 5988;
    cesh[133][5] = -1;
    cesh[133][6] = 493;
    cesh[133][7] = 489;
    cesh[133][8] = -1;
    cesh[133][9] = 88;
    cesh[134][3] = 8996;
    cesh[134][4] = 6989;
    cesh[134][5] = -1;
    cesh[134][6] = 686;
    cesh[134][7] = 488;
    cesh[134][8] = -1;
    cesh[134][9] = 89;
    cesh[135][3] = 49989;
    cesh[135][4] = 2995;
    cesh[135][5] = 794;
    cesh[135][6] = 789;
    cesh[135][7] = 487;
    cesh[135][8] = 191;
    cesh[135][9] = 90;
    cesh[136][3] = 39988;
    cesh[136][4] = 4986;
    cesh[136][5] = -1;
    cesh[136][6] = 685;
    cesh[136][7] = 486;
    cesh[136][8] = -1;
    cesh[136][9] = 181;
    cesh[137][3] = 29987;
    cesh[137][4] = 5987;
    cesh[137][5] = -1;
    cesh[137][6] = 788;
    cesh[137][7] = 485;
    cesh[137][8] = -1;
    cesh[137][9] = 182;
    cesh[138][3] = 9996;
    cesh[138][4] = 6988;
    cesh[138][5] = 985;
    cesh[138][6] = 684;
    cesh[138][7] = 484;
    cesh[138][8] = -1;
    cesh[138][9] = 183;
    cesh[139][3] = 59989;
    cesh[139][4] = 7989;
    cesh[139][5] = -1;
    cesh[139][6] = 787;
    cesh[139][7] = 483;
    cesh[139][8] = -1;
    cesh[139][9] = 184;
    cesh[140][3] = 49988;
    cesh[140][4] = 3995;
    cesh[140][5] = -1;
    cesh[140][6] = 593;
    cesh[140][7] = 392;
    cesh[140][8] = -1;
    cesh[140][9] = 185;
    cesh[141][3] = 39987;
    cesh[141][4] = 5986;
    cesh[141][5] = 894;
    cesh[141][6] = 786;
    cesh[141][7] = 589;
    cesh[141][8] = -1;
    cesh[141][9] = 186;
    cesh[142][3] = 19996;
    cesh[142][4] = 6987;
    cesh[142][5] = -1;
    cesh[142][6] = 889;
    cesh[142][7] = 588;
    cesh[142][8] = -1;
    cesh[142][9] = 187;
    cesh[143][3] = 69989;
    cesh[143][4] = 7988;
    cesh[143][5] = -1;
    cesh[143][6] = 785;
    cesh[143][7] = 587;
    cesh[143][8] = -1;
    cesh[143][9] = 188;
    cesh[144][3] = 59988;
    cesh[144][4] = 8989;
    cesh[144][5] = 1985;
    cesh[144][6] = 888;
    cesh[144][7] = 586;
    cesh[144][8] = 291;
    cesh[144][9] = 189;
    cesh[145][3] = 49987;
    cesh[145][4] = 4995;
    cesh[145][5] = -1;
    cesh[145][6] = 784;
    cesh[145][7] = 585;
    cesh[145][8] = -1;
    cesh[145][9] = 190;
    cesh[146][3] = 29996;
    cesh[146][4] = 6986;
    cesh[146][5] = -1;
    cesh[146][6] = 887;
    cesh[146][7] = 584;
    cesh[146][8] = -1;
    cesh[146][9] = 281;
    cesh[147][3] = 79989;
    cesh[147][4] = 7987;
    cesh[147][5] = 994;
    cesh[147][6] = 693;
    cesh[147][7] = 583;
    cesh[147][8] = -1;
    cesh[147][9] = 282;
    cesh[148][3] = 69988;
    cesh[148][4] = 8988;
    cesh[148][5] = -1;
    cesh[148][6] = 886;
    cesh[148][7] = 492;
    cesh[148][8] = -1;
    cesh[148][9] = 283;
    cesh[149][3] = 59987;
    cesh[149][4] = 9989;
    cesh[149][5] = -1;
    cesh[149][6] = 989;
    cesh[149][7] = 689;
    cesh[149][8] = -1;
    cesh[149][9] = 284;
    cesh[150][3] = 39996;
    cesh[150][4] = 5995;
    cesh[150][5] = 2985;
    cesh[150][6] = 885;
    cesh[150][7] = 688;
    cesh[150][8] = -1;
    cesh[150][9] = 285;
    ll tests = 1;
    cin >> tests;
    while (tests--)
    {
        solve();
    }
    return 0;
}