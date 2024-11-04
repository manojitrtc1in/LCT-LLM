















































































































































































#include <bits/stdc++.h>

int main() {

	int t, p1, p2, min;
	long long x1, x2;
	
	scanf("%d", &t);
	
	char* out = new char [t];
	
	for (int i=0; i<t; i++) {
	
		scanf("%lld %d", &x1, &p1);
		scanf("%lld %d", &x2, &p2);
		
		
		
		
		
		
		
		if(p1>p2)	min = p2;
		else 		min = p1;
		
		if (p1-min > 7)
			out[i] = '>';
		else if (p2-min > 7)
			out[i] = '<';
		
		else {
			for(int j=0; j<p1-min; ++j) {
		
				x1 *= 10;
			}
		
			for(int j=0; j<p2-min; ++j) {
		
				x2 *= 10;
			}
			
			if (x1>x2)			out[i] = '>';
			else if (x1<x2)		out[i] = '<';
			else 					out[i] = '=';
		}
		
		
		
		
		
		
	}
	
	for (int i=0; i<t; i++) {
			
		printf("%c\n", out[i]);
	}
	
	return 0;
}

































