
using namespace std;

string s[255]={"0\n",
"1\nlea ebx, [2*eax]\n",
"1\nlea ebx, [eax + 2*eax]\n",
"1\nlea ebx, [4*eax]\n",
"1\nlea ebx, [eax + 4*eax]\n",
"2\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\n",
"2\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*eax]\n",
"1\nlea ebx, [8*eax]\n",
"1\nlea ebx, [eax + 8*eax]\n",
"2\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\n",
"2\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*eax]\n",
"2\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\n",
"2\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*ebx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 4*ecx]\n",
"2\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\n",
"2\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\n",
"2\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\n",
"2\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\n",
"2\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 2*ebx]\n",
"2\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]\n",
"2\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 4*ebx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ebx + 4*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ebx + 4*ecx]\n",
"2\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\n",
"2\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\n",
"2\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ecx + 8*ebx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 4*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ebx]\n",
"2\nlea ebx, [4*eax]\nlea ecx, [8*ebx]\n",
"2\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [4*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]\n",
"2\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*ebx]\n",
"2\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 4*ebx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 4*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 4*ecx]\n",
"2\nlea ebx, [8*eax]\nlea ecx, [ebx + 4*ebx]\n",
"2\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 8*ebx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ebx + 8*ecx]\n",
"2\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 8*ebx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 1*eax]\nlea edx, [ecx + 8*ebx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 4*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [ecx + 2*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [ebx + 2*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [eax + 4*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 4*ecx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 4*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 4*eax]\nlea eex, [ebx + 8*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 4*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [eax + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [ebx + 4*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ecx]\n",
"2\nlea ebx, [8*eax]\nlea ecx, [8*ebx]\n",
"2\nlea ebx, [8*eax]\nlea ecx, [eax + 8*ebx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [8*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [4*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 4*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [eax + 8*ebx]\nlea eex, [ecx + 4*edx]\n",
"2\nlea ebx, [8*eax]\nlea ecx, [ebx + 8*ebx]\n",
"2\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 8*ebx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ebx + 4*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [ecx + 4*ecx]\n",
"2\nlea ebx, [eax + 8*eax]\nlea ecx, [ebx + 8*ebx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 4*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ebx + 4*edx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 2*ecx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [eax + 8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ecx + 8*ecx]\nlea eex, [ebx + 2*edx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 2*ebx]\nlea edx, [ebx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 2*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [8*ebx]\nlea edx, [ecx + 2*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [eax + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [4*eax]\nlea edx, [ecx + 8*eax]\nlea eex, [ebx + 8*edx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [4*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [edx + 2*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 4*ecx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [eax + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [eax + 4*ecx]\nlea eex, [ebx + 8*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 8*ecx]\nlea eex, [ebx + 4*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [ecx + 8*eax]\nlea eex, [ecx + 4*edx]\n",
"3\nlea ebx, [eax + 8*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ebx + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ebx + 4*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ecx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*eax]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [edx + 4*ecx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [ecx + 4*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [eax + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [ebx + 8*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 8*ecx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [ebx + 8*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [edx + 8*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*eax]\nlea eex, [ecx + 8*edx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [eax + 8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [4*ebx]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [4*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [ebx + 4*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ecx + 8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [eax + 8*ebx]\nlea eex, [ecx + 8*edx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ebx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [eax + 8*ebx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 8*ebx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [ecx + 8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 4*ecx]\n",
"3\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [eax + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [eax + 4*ecx]\nlea eex, [ebx + 4*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [eax + 4*ecx]\nlea eex, [ebx + 4*edx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 2*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ebx + 8*edx]\n",
"3\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 2*ecx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 4*ebx]\nlea eex, [ebx + 8*edx]\n",
"3\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ebx + 4*ecx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [ebx + 2*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ebx + 4*edx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [8*ebx]\nlea edx, [ecx + 4*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [eax + 8*ecx]\n",
"3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ecx + 8*ecx]\n",
"3\nlea ebx, [eax + 8*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 2*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [ebx + 4*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*eax]\nlea eex, [edx + 4*ecx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 4*ecx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [eax + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [4*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [edx + 4*edx]\n",
"3\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 2*ebx]\nlea edx, [ecx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [ecx + 2*edx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ebx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [eax + 4*ecx]\nlea eex, [ecx + 4*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]\nlea eex, [edx + 4*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [ecx + 4*eax]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [eax + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ebx + 8*edx]\n",
"4\nlea ebx, [8*eax]\nlea ecx, [eax + 2*ebx]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 2*edx]\n",
"3\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ecx + 8*ecx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ecx + 8*ecx]\nlea eex, [ebx + 4*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ecx + 8*ecx]\nlea eex, [ebx + 4*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ecx + 8*ecx]\nlea eex, [ebx + 4*edx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [edx + 8*ecx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ecx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [edx + 4*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [eax + 4*ecx]\nlea eex, [ecx + 4*edx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [8*ebx]\nlea edx, [ecx + 2*ecx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [eax + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [8*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ebx + 8*edx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [4*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [eax + 4*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [8*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [edx + 2*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]\nlea eex, [edx + 4*ecx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [ebx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [ebx + 8*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [4*ecx]\nlea eex, [edx + 8*ecx]\n",
"3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 4*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 4*ecx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 4*ecx]\nlea eex, [edx + 2*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [ecx + 8*eax]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [eax + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ebx + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [ebx + 2*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ebx + 4*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [edx + 4*edx]\n",
"3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [ecx + 8*ecx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 8*ecx]\nlea eex, [ebx + 8*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 8*ecx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 8*ecx]\nlea eex, [ebx + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [ecx + 4*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [edx + 2*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ebx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [8*ebx]\nlea edx, [ecx + 4*ebx]\nlea eex, [ecx + 4*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 8*ecx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ecx + 8*eax]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ebx + 8*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 4*ebx]\nlea eex, [ecx + 4*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [ebx + 2*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [edx + 4*ecx]\n",
"4\nlea ebx, [8*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ebx + 8*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [eax + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [edx + 8*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ebx + 8*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 4*ebx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 1*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 4*ecx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [edx + 4*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [eax + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [ebx + 8*edx]\n",
"3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ecx + 8*ecx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [ebx + 2*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [ebx + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [edx + 4*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [ecx + 8*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ecx + 8*ecx]\nlea eex, [ecx + 2*edx]\n",
"4\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*eax]\nlea edx, [ecx + 2*ecx]\nlea eex, [ebx + 8*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [eax + 8*edx]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [edx + 4*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ebx + 8*edx]\n",
"4\nlea ebx, [4*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [edx + 8*edx]\n",
"4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ecx]\nlea eex, [eax + 4*edx]\n",
"5\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 4*eax]\nlea eex, [edx + 8*edx]\nlea efx, [ebx + 4*eex]\n",
"4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [edx + 4*edx]\n",
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cout<<s[n-1];
    return 0;
}