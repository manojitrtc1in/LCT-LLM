


















using namespace std;
typedef long long ll;
typedef double long dl;
typedef unsigned long long ull;
const dl EPS = 1e-10;


struct wor {
    dl x = 0, y = 0;
};

dl dist(wor a, wor b) {
    dl answer = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return answer;
}















































ll vec(wor a, wor b) {
    return a.x * b.y - a.y * b.x;
}

ll scal(wor &a, wor &b) {
    return a.x * b.x + a.y * b.y;
}















wor operator-(wor a, wor b) {
    wor res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    return res;
}

wor operator+(wor a, wor b) {
    wor res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return res;
}

wor operator/(wor a, dl b) {
    wor res;
    res.x = a.x / b;
    res.y = a.y / b;
    return res;
}

void operator/=(wor &a, dl b) {
    a.x /= b;
    a.y /= b;
}

ostream &operator<<(ostream &out, const wor &a) {
    out << (ll) a.x << " " << (ll) a.y;
    return out;
}





























































































































































































































































bool id0(wor a, wor b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool id1(wor a, wor b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

wor beg;

bool by_angle(wor &a, wor &b) {
    wor a1 = a - beg;
    wor b1 = b - beg;
    return vec(a1, b1) >= 0;
}


















































































































































































































































































































































































































































































































































































































































vector<dl> line(wor a, wor lineA) {
    vector<dl> answer(3);
    answer[0] = lineA.y;
    answer[1] = -lineA.x;
    answer[2] = lineA.y * a.x - lineA.x * a.y;

    return answer;
}

wor intersect(wor a, wor lineA, wor b, wor lineB) {
    auto line1 = line(a, lineA);
    auto line2 = line(b, lineB);
    if (line1[0] == 0) {
        line1.swap(line2);
    }
    dl a1, b1, c1, a2, b2, c2;
    a1 = line1[0];
    b1 = line1[1];
    c1 = line1[2];
    a2 = line2[0];
    b2 = line2[1];
    c2 = line2[2];
    wor answer;
    answer.y = (c2 - a2 * c1 / a1) / (b2 - a2 * b1 / a1);
    answer.x = (c1 - b1 * answer.y) / a1;
    return answer;
}

wor id2(wor a, wor b, wor c) {
    wor mid1 = (a + b) / 2;
    wor mid2 = (b + c) / 2;
    wor temp = (b - a);
    wor line1;
    line1.x = -temp.y;
    line1.y = temp.x;
    temp = (c - b);
    wor line2;
    line2.x = -temp.y;
    line2.y = temp.x;
    return intersect(mid1, line1, mid2, line2);
}





































































































bool is_prime(ll a) {
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0)return false;
    }
    return true;
}































































ll ask(string a){
    if(a=="")return 0;
    cout<<a<<endl;
    ll answer ;
    cin>>answer;
    if(answer <= 0)exit(0);
    return answer;
}
void change(char & c){
    if(c=='a')c='b';else c ='a';
}
int main() {




    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string fa(300,'a');
    string fb(300,'b');
    ll a=300-ask(fa), b= 300-ask(fb);
    if(a== 0 ){
        ask(string(b,'b'));
        return 0;
    }
    if(b == 0 ){
        ask(string(a,'a'));
        return 0;
    }
    ll n = a+b;
    string cur = string(n,'a');
    ll temp = b;
    for(int i = 0 ; i < n-1; i ++){
        cur [ i] = 'b';
        if(ask(cur) > temp){
            cur[i] ='a';
        }else{
            temp--;
        }

    }
    if(temp){
        cur.back() = 'b';
    }
    ask(cur);

    return 0;
}
