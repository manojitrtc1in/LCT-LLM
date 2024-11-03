#include <iostream>
#include <vector>
#include <string>

std::string z = R"("""6"k"="3,"iG"17G"6m?"C@f"2<6z"ki1,"1Y[{s"dnF)N"1j.&{o"aZ>k}1"173exa+"atUi,},"1canZ35z"b*-!Ps6l"1z<F!WJlC"fQrp~1])H"1}8l0AiPTl"nXgm)";

std::vector<int> k;

int zz(std::string x) {
    std::string q = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!";
    int a = 0;
    for (char i : x) {
        a = a * q.size() + q.find(i);
    }
    return a;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    int n, m;
    sscanf(input.c_str(), "%d %d", &n, &m);

    std::string delimiter = "\"";
    size_t pos = 0;
    std::string token;
    while ((pos = z.find(delimiter)) != std::string::npos) {
        token = z.substr(0, pos);
        k.push_back(zz(token));
        z.erase(0, pos + delimiter.length());
    }

    std::cout << k[n] % m << std::endl;

    return 0;
}
