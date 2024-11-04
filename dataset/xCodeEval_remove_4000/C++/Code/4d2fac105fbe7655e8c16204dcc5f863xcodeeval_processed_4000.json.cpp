
using namespace std;

const int maxn = 256;
string ans[4][maxn], opt[maxn];

void init() {
    auto f = [&](const string &s, const string &t) { return s.size() == t.size() ? s < t : s.size() < t.size(); };
    auto cmp = [&](const tuple<string, int, int> &a, const tuple<string, int, int> &b) { return !f(get<0>(a), get<0>(b)); };
    priority_queue<tuple<string, int, int>, vector<tuple<string, int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 1; i <= 3; ++i) {
        for (int j = 0; j < maxn; ++j) {
            ans[i][j] = "";
            for (int k = 0; k < 100; ++k) ans[i][j] += '-';
        }
    }
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < 8; ++i) {
        x |= (i / 4) << i;
        y |= ((i / 2) % 2) << i;
        z |= (i & 1) << i;
    }
    pq.emplace("x", x, 1), pq.emplace("y", y, 1), pq.emplace("z", z, 1);
    ans[1][x] = "x"; ans[1][y] = "y"; ans[1][z] = "z";
    

    while (pq.size()) {
        string cur; int v, c;
        tie(cur, v, c) = pq.top(); pq.pop();
        if (f(ans[c][v], cur)) continue;
        

        ans[c][v] = cur;
        if (c == 1) {
            pq.emplace("!" + cur, v ^ 255, 1);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace(cur + "&" + ans[1][i], v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace(cur + "|" + ans[1][i], v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace(cur + "&" + "(" + ans[2][i] + ")", v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace(cur + "|" + ans[2][i], v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace(cur + "&" + ans[3][i], v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace(cur + "|" + ans[3][i], v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace(ans[1][i] + "&" + cur, v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace(ans[1][i] + "|" + cur, v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace("(" + ans[2][i] + ")" + "&" + cur, v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace(ans[2][i] + "|" + cur, v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace(ans[3][i] + "&" + cur, v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace(ans[3][i] + "|" + cur, v | i, 2);
        } 
        if (c == 2) {
            pq.emplace("!("+ cur + ")", v ^ 255, 1);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace("(" + cur + ")" + "&" + ans[1][i], v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace(cur + "|" + ans[1][i], v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace("(" + cur + ")" + "&" + "(" + ans[2][i] + ")", v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace(cur + "|" + ans[2][i], v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace("(" + cur + ")" + "&" + ans[3][i], v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace(cur + "|" + ans[3][i], v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace(ans[1][i] + "&" + "(" + cur + ")", v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace(ans[1][i] + "|" + cur, v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace("(" + ans[2][i] + ")" + "&" + "(" + cur + ")", v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace(ans[2][i] + "|" + cur, v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace(ans[3][i] + "&" + "(" + cur + ")", v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace(ans[3][i] + "|" + cur, v | i, 2);
        }
        if (c == 3) {
            pq.emplace("!(" + cur + ")", v ^ 255, 1);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace(cur + "&" + ans[1][i], v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace(cur + "|" + ans[1][i], v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace(cur + "&" + "(" + ans[2][i] + ")", v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace(cur + "|" + ans[2][i], v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace(cur + "&" + ans[3][i], v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace(cur + "|" + ans[3][i], v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace(ans[1][i] + "&" + cur, v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[1][i].size() < 100) pq.emplace(ans[1][i] + "|" + cur, v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace(ans[2][i] + "&" + "(" + cur + ")", v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[2][i].size() < 100) pq.emplace(ans[2][i] + "|" + cur, v | i, 2);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace(ans[3][i] + "&" + cur, v & i, 3);
            for (int i = 0; i < maxn; ++i) if (ans[3][i].size() < 100) pq.emplace(ans[3][i] + "|" + cur, v | i, 2);
        }
    }
    

    for (int i = 0; i < maxn; ++i) {
        vector<string> v;
        for (int j = 1; j <= 3; ++j) v.push_back(ans[j][i]);
        sort(v.begin(), v.end(), [&](const string &a, const string &b) { return f(a, b); });
        cout << "    opt[" << i << "] = " << "\"" << v[0] << "\"" << ";" << endl;
    }
}

void build() {
    opt[0] = "!x&x";
    opt[1] = "!(x|y|z)";
    opt[2] = "!x&!y&z";
    opt[3] = "!x&!y";
    opt[4] = "!x&!z&y";
    opt[5] = "!x&!z";
    opt[6] = "!(!y&!z|x|y&z)";
    opt[7] = "!(x|y&z)";
    opt[8] = "!x&y&z";
    opt[9] = "!(!y&z|!z&y|x)";
    opt[10] = "!x&z";
    opt[11] = "!(!z&y|x)";
    opt[12] = "!x&y";
    opt[13] = "!(!y&z|x)";
    opt[14] = "!x&(y|z)";
    opt[15] = "!x";
    opt[16] = "!y&!z&x";
    opt[17] = "!y&!z";
    opt[18] = "!(!x&!z|x&z|y)";
    opt[19] = "!(x&z|y)";
    opt[20] = "!(!x&!y|x&y|z)";
    opt[21] = "!(x&y|z)";
    opt[22] = "!(!x&!y|x&y|z)|!x&!y&z";
    opt[23] = "!((x|y)&z|x&y)";
    opt[24] = "!x&y&z|!y&!z&x";
    opt[25] = "!x&y&z|!y&!z";
    opt[26] = "!x&z|!y&!z&x";
    opt[27] = "!x&z|!y&!z";
    opt[28] = "!x&y|!y&!z&x";
    opt[29] = "!x&y|!y&!z";
    opt[30] = "!x&(y|z)|!y&!z&x";
    opt[31] = "!x|!y&!z";
    opt[32] = "!y&x&z";
    opt[33] = "!(!x&z|!z&x|y)";
    opt[34] = "!y&z";
    opt[35] = "!(!z&x|y)";
    opt[36] = "!x&!z&y|!y&x&z";
    opt[37] = "!x&!z|!y&x&z";
    opt[38] = "!x&!z&y|!y&z";
    opt[39] = "!x&!z|!y&z";
    opt[40] = "!x&y&z|!y&x&z";
    opt[41] = "!(!x&z|!z&x|y)|!x&y&z";
    opt[42] = "!(x&y)&z";
    opt[43] = "!(!z&x|y)|!x&z";
    opt[44] = "!x&y|!y&x&z";
    opt[45] = "!(!y&z|x)|!y&x&z";
    opt[46] = "!x&y|!y&z";
    opt[47] = "!x|!y&z";
    opt[48] = "!y&x";
    opt[49] = "!(!x&z|y)";
    opt[50] = "!y&(x|z)";
    opt[51] = "!y";
    opt[52] = "!x&!z&y|!y&x";
    opt[53] = "!x&!z|!y&x";
    opt[54] = "!x&!z&y|!y&(x|z)";
    opt[55] = "!x&!z|!y";
    opt[56] = "!x&y&z|!y&x";
    opt[57] = "!(!x&z|y)|!x&y&z";
    opt[58] = "!x&z|!y&x";
    opt[59] = "!x&z|!y";
    opt[60] = "!x&y|!y&x";
    opt[61] = "!(!x&!y&z|x&y)";
    opt[62] = "!x&(y|z)|!y&x";
    opt[63] = "!x|!y";
    opt[64] = "!z&x&y";
    opt[65] = "!(!x&y|!y&x|z)";
    opt[66] = "!x&!y&z|!z&x&y";
    opt[67] = "!x&!y|!z&x&y";
    opt[68] = "!z&y";
    opt[69] = "!(!y&x|z)";
    opt[70] = "!x&!y&z|!z&y";
    opt[71] = "!x&!y|!z&y";
    opt[72] = "!x&y&z|!z&x&y";
    opt[73] = "!(!x&y|!y&x|z)|!x&y&z";
    opt[74] = "!x&z|!z&x&y";
    opt[75] = "!(!z&y|x)|!z&x&y";
    opt[76] = "!(x&z)&y";
    opt[77] = "!(!y&x|z)|!x&y";
    opt[78] = "!x&z|!z&y";
    opt[79] = "!x|!z&y";
    opt[80] = "!z&x";
    opt[81] = "!(!x&y|z)";
    opt[82] = "!x&!y&z|!z&x";
    opt[83] = "!x&!y|!z&x";
    opt[84] = "!z&(x|y)";
    opt[85] = "!z";
    opt[86] = "!x&!y&z|!z&(x|y)";
    opt[87] = "!x&!y|!z";
    opt[88] = "!x&y&z|!z&x";
    opt[89] = "!(!x&y|z)|!x&y&z";
    opt[90] = "!x&z|!z&x";
    opt[91] = "!(!x&!z&y|x&z)";
    opt[92] = "!x&y|!z&x";
    opt[93] = "!x&y|!z";
    opt[94] = "!x&(y|z)|!z&x";
    opt[95] = "!x|!z";
    opt[96] = "!y&x&z|!z&x&y";
    opt[97] = "!(!x&y|!y&x|z)|!y&x&z";
    opt[98] = "!y&z|!z&x&y";
    opt[99] = "!(!z&x|y)|!z&x&y";
    opt[100] = "!y&x&z|!z&y";
    opt[101] = "!(!y&x|z)|!y&x&z";
    opt[102] = "!y&z|!z&y";
    opt[103] = "!(!y&!z&x|y&z)";
    opt[104] = "!x&y&z|!y&x&z|!z&x&y";
    opt[105] = "!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
    opt[106] = "!(x&y)&z|!z&x&y";
    opt[107] = "!(!z&x|y)|!x&z|!z&x&y";
    opt[108] = "!(x&z)&y|!y&x&z";
    opt[109] = "!(!y&x|z)|!x&y|!y&x&z";
    opt[110] = "!(x&y)&z|!z&y";
    opt[111] = "!x|!y&z|!z&y";
    opt[112] = "!(y&z)&x";
    opt[113] = "!(!x&y|z)|!y&x";
    opt[114] = "!y&z|!z&x";
    opt[115] = "!y|!z&x";
    opt[116] = "!y&x|!z&y";
    opt[117] = "!y&x|!z";
    opt[118] = "!y&(x|z)|!z&y";
    opt[119] = "!y|!z";
    opt[120] = "!(y&z)&x|!x&y&z";
    opt[121] = "!(!x&y|z)|!x&y&z|!y&x";
    opt[122] = "!(x&y)&z|!z&x";
    opt[123] = "!x&z|!y|!z&x";
    opt[124] = "!(x&z)&y|!y&x";
    opt[125] = "!x&y|!y&x|!z";
    opt[126] = "!x&y|!y&z|!z&x";
    opt[127] = "!(x&y&z)";
    opt[128] = "x&y&z";
    opt[129] = "!(x|y|z)|x&y&z";
    opt[130] = "!x&!y&z|x&y&z";
    opt[131] = "!x&!y|x&y&z";
    opt[132] = "!x&!z&y|x&y&z";
    opt[133] = "!x&!z|x&y&z";
    opt[134] = "!(!y&!z|x|y&z)|x&y&z";
    opt[135] = "!(x|y&z)|x&y&z";
    opt[136] = "y&z";
    opt[137] = "!(x|y|z)|y&z";
    opt[138] = "!x&z|y&z";
    opt[139] = "!x&!y|y&z";
    opt[140] = "!x&y|y&z";
    opt[141] = "!x&!z|y&z";
    opt[142] = "!x&(y|z)|y&z";
    opt[143] = "!x|y&z";
    opt[144] = "!y&!z&x|x&y&z";
    opt[145] = "!y&!z|x&y&z";
    opt[146] = "!(!x&!z|x&z|y)|x&y&z";
    opt[147] = "!(x&z|y)|x&y&z";
    opt[148] = "!(!x&!y|x&y|z)|x&y&z";
    opt[149] = "!(x&y|z)|x&y&z";
    opt[150] = "!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
    opt[151] = "!((x|y)&z|x&y)|x&y&z";
    opt[152] = "!y&!z&x|y&z";
    opt[153] = "!y&!z|y&z";
    opt[154] = "!x&z|!y&!z&x|y&z";
    opt[155] = "!(x&z|y)|y&z";
    opt[156] = "!x&y|!y&!z&x|y&z";
    opt[157] = "!(x&y|z)|y&z";
    opt[158] = "!x&(y|z)|!y&!z&x|y&z";
    opt[159] = "!x|!y&!z|y&z";
    opt[160] = "x&z";
    opt[161] = "!(x|y|z)|x&z";
    opt[162] = "!y&z|x&z";
    opt[163] = "!x&!y|x&z";
    opt[164] = "!x&!z&y|x&z";
    opt[165] = "!x&!z|x&z";
    opt[166] = "!x&!z&y|!y&z|x&z";
    opt[167] = "!(x|y&z)|x&z";
    opt[168] = "(x|y)&z";
    opt[169] = "!(x|y|z)|(x|y)&z";
    opt[170] = "z";
    opt[171] = "!x&!y|z";
    opt[172] = "!x&y|x&z";
    opt[173] = "!(!y&z|x)|x&z";
    opt[174] = "!x&y|z";
    opt[175] = "!x|z";
    opt[176] = "!y&x|x&z";
    opt[177] = "!y&!z|x&z";
    opt[178] = "!y&(x|z)|x&z";
    opt[179] = "!y|x&z";
    opt[180] = "!x&!z&y|!y&x|x&z";
    opt[181] = "!(x&y|z)|x&z";
    opt[182] = "!x&!z&y|!y&(x|z)|x&z";
    opt[183] = "!x&!z|!y|x&z";
    opt[184] = "!y&x|y&z";
    opt[185] = "!(!x&z|y)|y&z";
    opt[186] = "!y&x|z";
    opt[187] = "!y|z";
    opt[188] = "!x&y|!y&x|x&z";
    opt[189] = "!x&!z|!y&x|y&z";
    opt[190] = "!x&y|!y&x|z";
    opt[191] = "!x|!y|z";
    opt[192] = "x&y";
    opt[193] = "!(x|y|z)|x&y";
    opt[194] = "!x&!y&z|x&y";
    opt[195] = "!x&!y|x&y";
    opt[196] = "!z&y|x&y";
    opt[197] = "!x&!z|x&y";
    opt[198] = "!x&!y&z|!z&y|x&y";
    opt[199] = "!(x|y&z)|x&y";
    opt[200] = "(x|z)&y";
    opt[201] = "!(x|y|z)|(x|z)&y";
    opt[202] = "!x&z|x&y";
    opt[203] = "!(!z&y|x)|x&y";
    opt[204] = "y";
    opt[205] = "!x&!z|y";
    opt[206] = "!x&z|y";
    opt[207] = "!x|y";
    opt[208] = "!z&x|x&y";
    opt[209] = "!y&!z|x&y";
    opt[210] = "!x&!y&z|!z&x|x&y";
    opt[211] = "!(x&z|y)|x&y";
    opt[212] = "!z&(x|y)|x&y";
    opt[213] = "!z|x&y";
    opt[214] = "!x&!y&z|!z&(x|y)|x&y";
    opt[215] = "!x&!y|!z|x&y";
    opt[216] = "!z&x|y&z";
    opt[217] = "!(!x&y|z)|y&z";
    opt[218] = "!x&z|!z&x|x&y";
    opt[219] = "!x&!y|!z&x|y&z";
    opt[220] = "!z&x|y";
    opt[221] = "!z|y";
    opt[222] = "!x&z|!z&x|y";
    opt[223] = "!x|!z|y";
    opt[224] = "(y|z)&x";
    opt[225] = "!(x|y|z)|(y|z)&x";
    opt[226] = "!y&z|x&y";
    opt[227] = "!(!z&x|y)|x&y";
    opt[228] = "!z&y|x&z";
    opt[229] = "!(!y&x|z)|x&z";
    opt[230] = "!y&z|!z&y|x&y";
    opt[231] = "!x&!y|!z&y|x&z";
    opt[232] = "(x|y)&z|x&y";
    opt[233] = "!(x|y|z)|(x|y)&z|x&y";
    opt[234] = "x&y|z";
    opt[235] = "!x&!y|x&y|z";
    opt[236] = "x&z|y";
    opt[237] = "!x&!z|x&z|y";
    opt[238] = "y|z";
    opt[239] = "!x|y|z";
    opt[240] = "x";
    opt[241] = "!y&!z|x";
    opt[242] = "!y&z|x";
    opt[243] = "!y|x";
    opt[244] = "!z&y|x";
    opt[245] = "!z|x";
    opt[246] = "!y&z|!z&y|x";
    opt[247] = "!y|!z|x";
    opt[248] = "x|y&z";
    opt[249] = "!y&!z|x|y&z";
    opt[250] = "x|z";
    opt[251] = "!y|x|z";
    opt[252] = "x|y";
    opt[253] = "!z|x|y";
    opt[254] = "x|y|z";
    opt[255] = "!x|x";
}

int main() {
    

    build();
    int n; cin >> n; while (n--) {
        string s; cin >> s;
        int v = 0;
        for (int i = 0; i < 8; ++i) v |= (s[i] - '0') << i;
        cout << opt[v] << endl;
    }
    return 0;
}