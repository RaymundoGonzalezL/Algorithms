#include <bits/stdc++.h>
using namespace std;
class Matrix{		
	public:
		int N, M; //Size of the Matrix
		vector<vector<int> > matrix;
		//Constructors
		Matrix(int N, int M, vector<vector<int> > matrix) : N(N), M(M), matrix(matrix) {}
		Matrix(int N, int M) : N(N), M(M) {
			matrix.assign(N, vector<int>());
			for(int i=0;i<N;i++){
				matrix[i].assign(M, 0);
			}
		}
		Matrix() : N(0), M(0) {}
	
		//ToDo : Change Operator
		Matrix operator* (Matrix B){
			Matrix C(N, M);
			for(int k=0;k<N;k++){
				for(int i=0;i<N;i++){
					for(int j=0;j<N;j++){
						C.matrix[i][j]+= (matrix[i][k] * B.matrix[k][j]);
					}
				}
			}
			return C;
		}
};

Matrix pow(Matrix B, int P){
	Matrix R = B;
	for(;P;P>>=1){
		if(P&1){
			R = R * B;
		}
		B = B * B;
	}
	return R;
}

int main(){
	int N = 2, M = 2;
	vector<vector<int> > matrix;
	matrix.assign(N, vector<int>());
	for(int i=0;i<N;i++){
		matrix[i].assign(M, 0);
	}
	matrix[0][0] = 1, matrix[0][1] = 1;
	matrix[1][0] = 1, matrix[1][1] = 0;
	Matrix A(N, M, matrix);
	int nth;
	cout << "Give me the Nth Fibonacci for searching: ";
	cin >> nth;
	if(nth <= 1){
		cout << "1\n";
	}else{
		A = pow(A, nth - 2);
		cout << A.matrix[0][0] + A.matrix[0][1] << "\n";
	}
}

