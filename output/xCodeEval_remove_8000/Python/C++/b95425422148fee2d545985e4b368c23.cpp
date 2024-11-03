#include <iostream>
#include <vector>
#include <string>

std::string z = R"("""6"k"="3,"iG"17G"6m?"C@f"2<6z"ki1,"1Y[{s"dnF)N"1j.&{o"aZ>k}1"173exa+"atUi,},"1canZ35z"b*-!Ps6l"1z<F!WJlC"fQrp~1])H"1}8l0AiPTl"nXgm")";

std::string q = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!";

int zz(std::string x) {
    int a = 0;
    for (char i : x) {
        a = a * q.size() + q.find(i);
    }
    return a;
}

int main() {
    std::vector<int> k;
    std::string temp;
    std::istringstream iss(z);
    while (std::getline(iss, temp, '"')) {
        k.push_back(zz(temp));
    }

    int n, m;
    std::cin >> n >> m;

    std::cout << k[n] % m << std::endl;

    return 0;
}
