#include <bits/stdc++.h>
using namespace std;
// cambio de signo en complemento a 2
vector<bool> complementoDos(const std::vector<bool>& binary) {
	vector<bool> cDos(binary.size());
	bool bandera = true;
	for (int i = binary.size() - 1; i >= 0; --i) {
		cDos[i] = !binary[i] ^ bandera;
		bandera = bandera && binary[i];
	}
	return cDos;
}
// suma binaria
vector<bool> sumaBinaria(vector<bool>& a,vector<bool>& b) {
	vector<bool> sB(a.size(), false);
	bool bandera = false;
	for (int i = a.size() - 1; i >= 0; --i) {
		sB[i] = a[i] ^ b[i] ^ bandera;
		bandera = (a[i] && b[i]) || (a[i] && bandera) || (b[i] && bandera);
	}
	return sB;
}

//corrimiento aritmético hacia la derecha
vector<bool> corrimientoDerecha(vector<bool>& a) {
	vector<bool> cD(a.size());
	bool bandera = a[0];
	for (int i = 1; i < a.size(); ++i) {
		cD[i - 1] = a[i];
	}
	cD[a.size() - 1] = bandera;
	return cD;
}
// algoritmo de Booth
vector<bool> multiplicacionBooth(vector<bool>& multiplicando, vector<bool>& multiplicador) {
	int n = multiplicando.size();
	vector<bool> A(n, false);
	vector<bool> Q = multiplicando;
	vector<bool> M = complementoDos(multiplicador);
	vector<bool> Q_1(n, false);
	while(m!=0){
		bool LSB_Q = Q[n - 1];
		bool LSB_Q_1 = Q_1[0];
		if (!LSB_Q && LSB_Q_1) {
			A = sumaBinaria(A, M);
		}
		else if (LSB_Q && !LSB_Q_1) {
			A = sumaBinaria(A, M);
		}
		bool MSB_A = A[0];
		Q_1 = Q; 
		Q = corrimientoDerecha(Q);
		Q[0] = MSB_A; 
		A = corrimientoDerecha(A);
		n--;
	}
	// Concatenar A y Q
	A.insert(A.end(), Q.begin(), Q.end());
	return A;
}

int main() {
	int n;
	cout << "N -> ";cin >> n;
	string M, Q;
	cout << "multiplicando-> ";
	cin >> M;
	cout << "multiplicador-> ";
	cin >> Q;
	vector<bool> MB(n);
	vector<bool> QB(n);
	for (int i = 0; i < n; ++i) {
		MB[i] = (M[i] == '1');
		QB[i] = (Q[i] == '1');
	}
	vector<bool> resultado = multiplicacionBooth(MB, QB);
	cout << "Resultado -> ";
	for (bool bit : resultado) {
		std::cout << bit;
	}
	return 0;
}
