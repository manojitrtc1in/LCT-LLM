#include <iostream>
#include <string>
#include <vector>

std::string z = R"("""6"k"="3,"iG"17G"6m?"C@f"2<6z"ki1,"1Y[{s"dnF)N"1j.&{o"aZ>k}1"173exa+"atUi,},"1canZ35z"b*-!Ps6l"1z<F!WJlC"fQrp~1])H"1}8l0AiPTl"nXgm)";

std::string q = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!";

long long zz(const std::string& x) {
    long long a = 0;
    for (char i : x) {
        a = a * q.length() + q.find(i);
    }
    return a;
}

int main() {
    std::vector<long long> k;
    size_t pos = 0;
    std::string token;
    while ((pos = z.find('"')) != std::string::npos) {
        token = z.substr(0, pos);
        k.push_back(zz(token));
        z.erase(0, pos + 1);
    }

    int n, m;
    std::cin >> n >> m;

    std::cout << k[n] % m << std::endl;

    return 0;
}
