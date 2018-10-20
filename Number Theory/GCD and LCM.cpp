#include <bits/stdc++.h>
using namespace std;

int gcdRecursive(int N, int M){
	return (M == 0) ? N : gcdRecursive(M, N % M);
}

int gcd(int N, int M){
	while(M){
		int R = N % M;
		N = M;
		M = R;
	}
	return N;
}

int lcm(int N, int M){
	return N * M / gcd(N, M);
}

int main(){
	cout << "GCD(4, 6) = " << gcdRecursive(4, 6) << "\n";
	cout << "GCD(4, 6) = " << gcd(4, 6) << "\n";
	cout << "LCM(4, 10) = " << lcm(4, 10) << "\n";
}

