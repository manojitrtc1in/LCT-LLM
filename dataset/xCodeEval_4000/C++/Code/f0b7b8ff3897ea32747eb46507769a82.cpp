#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

const double EPS = 1e-9;
const double PI = acos(-1.0);

template<typename X> inline X abs(const X &a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X &a) { return a * a; }

std::string ans[256] = {
	"!x&x",
	"!(x|y|z)",
	"!x&!y&z",
	"!x&!y",
	"!x&!z&y",
	"!x&!z",
	"!(!y&!z|x|y&z)",
	"!(x|y&z)",
	"!x&y&z",
	"!(!y&z|!z&y|x)",
	"!x&z",
	"!(!z&y|x)",
	"!x&y",
	"!(!y&z|x)",
	"!x&(y|z)",
	"!x",
	"!y&!z&x",
	"!y&!z",
	"!(!x&!z|x&z|y)",
	"!(x&z|y)",
	"!(!x&!y|x&y|z)",
	"!(x&y|z)",
	"!(!x&!y|x&y|z)|!x&!y&z",
	"!((x|y)&z|x&y)",
	"!x&y&z|!y&!z&x",
	"!x&y&z|!y&!z",
	"!x&z|!y&!z&x",
	"!x&z|!y&!z",
	"!x&y|!y&!z&x",
	"!x&y|!y&!z",
	"!x&(y|z)|!y&!z&x",
	"!x|!y&!z",
	"!y&x&z",
	"!(!x&z|!z&x|y)",
	"!y&z",
	"!(!z&x|y)",
	"!x&!z&y|!y&x&z",
	"!x&!z|!y&x&z",
	"!x&!z&y|!y&z",
	"!x&!z|!y&z",
	"!x&y&z|!y&x&z",
	"!(!x&z|!z&x|y)|!x&y&z",
	"!(x&y)&z",
	"!(!z&x|y)|!x&z",
	"!x&y|!y&x&z",
	"!(!y&z|x)|!y&x&z",
	"!x&y|!y&z",
	"!x|!y&z",
	"!y&x",
	"!(!x&z|y)",
	"!y&(x|z)",
	"!y",
	"!x&!z&y|!y&x",
	"!x&!z|!y&x",
	"!x&!z&y|!y&(x|z)",
	"!x&!z|!y",
	"!x&y&z|!y&x",
	"!(!x&z|y)|!x&y&z",
	"!x&z|!y&x",
	"!x&z|!y",
	"!x&y|!y&x",
	"!(!x&!y&z|x&y)",
	"!x&(y|z)|!y&x",
	"!x|!y",
	"!z&x&y",
	"!(!x&y|!y&x|z)",
	"!x&!y&z|!z&x&y",
	"!x&!y|!z&x&y",
	"!z&y",
	"!(!y&x|z)",
	"!x&!y&z|!z&y",
	"!x&!y|!z&y",
	"!x&y&z|!z&x&y",
	"!(!x&y|!y&x|z)|!x&y&z",
	"!x&z|!z&x&y",
	"!(!z&y|x)|!z&x&y",
	"!(x&z)&y",
	"!(!y&x|z)|!x&y",
	"!x&z|!z&y",
	"!x|!z&y",
	"!z&x",
	"!(!x&y|z)",
	"!x&!y&z|!z&x",
	"!x&!y|!z&x",
	"!z&(x|y)",
	"!z",
	"!x&!y&z|!z&(x|y)",
	"!x&!y|!z",
	"!x&y&z|!z&x",
	"!(!x&y|z)|!x&y&z",
	"!x&z|!z&x",
	"!(!x&!z&y|x&z)",
	"!x&y|!z&x",
	"!x&y|!z",
	"!x&(y|z)|!z&x",
	"!x|!z",
	"!y&x&z|!z&x&y",
	"!(!x&y|!y&x|z)|!y&x&z",
	"!y&z|!z&x&y",
	"!(!z&x|y)|!z&x&y",
	"!y&x&z|!z&y",
	"!(!y&x|z)|!y&x&z",
	"!y&z|!z&y",
	"!(!y&!z&x|y&z)",
	"!x&y&z|!y&x&z|!z&x&y",
	"!(!x&y|!y&x|z)|!x&y&z|!y&x&z",
	"!(x&y)&z|!z&x&y",
	"!(!z&x|y)|!x&z|!z&x&y",
	"!(x&z)&y|!y&x&z",
	"!(!y&x|z)|!x&y|!y&x&z",
	"!(x&y)&z|!z&y",
	"!x|!y&z|!z&y",
	"!(y&z)&x",
	"!(!x&y|z)|!y&x",
	"!y&z|!z&x",
	"!y|!z&x",
	"!y&x|!z&y",
	"!y&x|!z",
	"!y&(x|z)|!z&y",
	"!y|!z",
	"!(y&z)&x|!x&y&z",
	"!(!x&y|z)|!x&y&z|!y&x",
	"!(x&y)&z|!z&x",
	"!x&z|!y|!z&x",
	"!(x&z)&y|!y&x",
	"!x&y|!y&x|!z",
	"!x&y|!y&z|!z&x",
	"!(x&y&z)",
	"x&y&z",
	"!(x|y|z)|x&y&z",
	"!x&!y&z|x&y&z",
	"!x&!y|x&y&z",
	"!x&!z&y|x&y&z",
	"!x&!z|x&y&z",
	"!(!y&!z|x|y&z)|x&y&z",
	"!(x|y&z)|x&y&z",
	"y&z",
	"!(x|y|z)|y&z",
	"!x&z|y&z",
	"!x&!y|y&z",
	"!x&y|y&z",
	"!x&!z|y&z",
	"!x&(y|z)|y&z",
	"!x|y&z",
	"!y&!z&x|x&y&z",
	"!y&!z|x&y&z",
	"!(!x&!z|x&z|y)|x&y&z",
	"!(x&z|y)|x&y&z",
	"!(!x&!y|x&y|z)|x&y&z",
	"!(x&y|z)|x&y&z",
	"!(!x&!y|x&y|z)|!x&!y&z|x&y&z",
	"!((x|y)&z|x&y)|x&y&z",
	"!y&!z&x|y&z",
	"!y&!z|y&z",
	"!x&z|!y&!z&x|y&z",
	"!(x&z|y)|y&z",
	"!x&y|!y&!z&x|y&z",
	"!(x&y|z)|y&z",
	"!x&(y|z)|!y&!z&x|y&z",
	"!x|!y&!z|y&z",
	"x&z",
	"!(x|y|z)|x&z",
	"!y&z|x&z",
	"!x&!y|x&z",
	"!x&!z&y|x&z",
	"!x&!z|x&z",
	"!x&!z&y|!y&z|x&z",
	"!(x|y&z)|x&z",
	"(x|y)&z",
	"!(x|y|z)|(x|y)&z",
	"z",
	"!x&!y|z",
	"!x&y|x&z",
	"!(!y&z|x)|x&z",
	"!x&y|z",
	"!x|z",
	"!y&x|x&z",
	"!y&!z|x&z",
	"!y&(x|z)|x&z",
	"!y|x&z",
	"!x&!z&y|!y&x|x&z",
	"!(x&y|z)|x&z",
	"!x&!z&y|!y&(x|z)|x&z",
	"!x&!z|!y|x&z",
	"!y&x|y&z",
	"!(!x&z|y)|y&z",
	"!y&x|z",
	"!y|z",
	"!x&y|!y&x|x&z",
	"!x&!z|!y&x|y&z",
	"!x&y|!y&x|z",
	"!x|!y|z",
	"x&y",
	"!(x|y|z)|x&y",
	"!x&!y&z|x&y",
	"!x&!y|x&y",
	"!z&y|x&y",
	"!x&!z|x&y",
	"!x&!y&z|!z&y|x&y",
	"!(x|y&z)|x&y",
	"(x|z)&y",
	"!(x|y|z)|(x|z)&y",
	"!x&z|x&y",
	"!(!z&y|x)|x&y",
	"y",
	"!x&!z|y",
	"!x&z|y",
	"!x|y",
	"!z&x|x&y",
	"!y&!z|x&y",
	"!x&!y&z|!z&x|x&y",
	"!(x&z|y)|x&y",
	"!z&(x|y)|x&y",
	"!z|x&y",
	"!x&!y&z|!z&(x|y)|x&y",
	"!x&!y|!z|x&y",
	"!z&x|y&z",
	"!(!x&y|z)|y&z",
	"!x&z|!z&x|x&y",
	"!x&!y|!z&x|y&z",
	"!z&x|y",
	"!z|y",
	"!x&z|!z&x|y",
	"!x|!z|y",
	"(y|z)&x",
	"!(x|y|z)|(y|z)&x",
	"!y&z|x&y",
	"!(!z&x|y)|x&y",
	"!z&y|x&z",
	"!(!y&x|z)|x&z",
	"!y&z|!z&y|x&y",
	"!x&!y|!z&y|x&z",
	"(x|y)&z|x&y",
	"!(x|y|z)|(x|y)&z|x&y",
	"x&y|z",
	"!x&!y|x&y|z",
	"x&z|y",
	"!x&!z|x&z|y",
	"y|z",
	"!x|y|z",
	"x",
	"!y&!z|x",
	"!y&z|x",
	"!y|x",
	"!z&y|x",
	"!z|x",
	"!y&z|!z&y|x",
	"!y|!z|x",
	"x|y&z",
	"!y&!z|x|y&z",
	"x|z",
	"!y|x|z",
	"x|y",
	"!z|x|y",
	"x|y|z",
	"!x|x"
};

int tests;

void read() {
	char buf[10];
	scanf("%d", &tests);
	for (int test = 0; test < tests; test++) {
		scanf(" %s", buf);
		int t = 0;
		for (int i = 0; i < 8; i++) {
			t |= (buf[i] == '1') << i;
		}

		printf("%s\n", ans[t].c_str());
	}
}

void solve() {
}

enum class Operation {
	None = 0,
	And = 1,
	Or = 2
};

const int M = 256 + 3;

struct Expression {
	Operation operation;	
	std::string expression;
} res[M][3];

void precalc() {
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < 8; i++) {
		x |= (i / 4) << i;
		y |= ((i / 2) % 2) << i;
		z |= (i % 2) << i;
	}

	res[x][0].expression = "x";
	res[y][0].expression = "y";
	res[z][0].expression = "z";

	const int n = 1 << 8;
	while (true) {
		bool updated = false;
		

		for (int i = 0; i < n; i++) {
			for (int op = 0; op < 3; op++) {
				if (res[i][op].expression.empty()) {
					continue;
				}
				
				const auto s = res[i][op];
				const int r = (~i) & (n - 1);
				
				Expression expr;
				expr.operation = Operation::None;
				expr.expression = res[i][op].operation == Operation::None ? ("!" + s.expression) : ("!(" + s.expression + ")");

				auto& res_exp = res[r][static_cast<int>(expr.operation)];
				if (res_exp.expression.empty() || res_exp.expression.size() > expr.expression.size() || (res_exp.expression.size() == expr.expression.size() && res_exp.expression > expr.expression)) {
					res_exp = expr;
					updated = true;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int op1 = 0; op1 < 3; op1++) {
				const auto& left_s = res[i][op1];
				if (left_s.expression.empty()) {
					continue;
				}

				for (int j = 0; j < n; j++) {
					for (int op2 = 0; op2 < 3; op2++) {
						const auto& right_s = res[j][op2];
						if (right_s.expression.empty()) {
							continue;
						}

						{
							const int r = i & j;
							Expression expr;
							expr.operation = Operation::And;
							const std::string left_expression = left_s.operation == Operation::Or ? ("(" + left_s.expression + ")") : left_s.expression;
							const std::string right_expression = right_s.operation == Operation::Or ? ("(" + right_s.expression + ")") : right_s.expression;
							expr.expression = left_expression + "&" + right_expression;

							auto& res_exp = res[r][static_cast<int>(expr.operation)];
							if (res_exp.expression.empty() || res_exp.expression.size() > expr.expression.size() || (res_exp.expression.size() == expr.expression.size() && res_exp.expression > expr.expression)) {
								res_exp = expr;
								updated = true;
							}
						}

						{
							const int r = i | j;
							Expression expr;
							expr.operation = Operation::Or;
							expr.expression = left_s.expression + "|" + right_s.expression;

							auto& res_exp = res[r][static_cast<int>(expr.operation)];
							if (res_exp.expression.empty() || res_exp.expression.size() > expr.expression.size() || (res_exp.expression.size() == expr.expression.size() && res_exp.expression > expr.expression)) {
								res_exp = expr;
								updated = true;
							}
						}
					}
				}
			}
		}

		if (!updated) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		std::string ans = "";
		for (int j = 0; j < 3; j++) {
			const auto expr = res[i][j].expression;
			if (expr.empty()) {
				continue;
			}
			if (ans.empty() || ans.size() > expr.size() || (ans.size() == expr.size() && ans > expr)) {
				ans = expr;
			}
		}
		std::cout << "\"" << ans << "\"," << std::endl;
	}
}

int main() {
#ifdef MG_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	std::cout << std::setprecision(10) << std::fixed;
	std::cerr << std::setprecision(5) << std::fixed;

	


	read();
	solve();

	return 0;
}