#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 2

// Problema 2

struct specie {
	int cod;
	int nrExemplare;
	int varsta[10];
};

void rezolvareSub2Problema2() {
	specie s[20];
}

// Problema 3

void rezolvareSub2Problema3() {
	int i, j, a[5][7];
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 7; j++) {
			if (i == 0 || j == 0) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = (a[i - 1][j] + a[i][j - 1]) % 10;
			}
		}
	}

	// Testare :
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 7; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

// Subiectul 3

// Problema 1

void fii(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (i * j == n && i > j) {
				cout << "(" << i << " " << j << ") ";
			}
		}
	}
}

void rezolvareSub3Problema1() {
	int n;
	cin >> n;
	fii(n);
}

// Problema 2

void spargere(char text[], char cuvinte[100][100], int& d) {
	d = 0;
	char* a;
	a = strtok(text, " ");
	while (a != NULL) {
		strcpy(cuvinte[d], a);
		d++;
		a = strtok(NULL, " ");
	}
}

void virgulaToPunct(char* numar) {
	for (int i = 0; i < strlen(numar); i++) {
		if (numar[i] == ',') {
			numar[i] = '.';
		}
	}
}

void rezolvareSub3Problema2() {
	char text[100] = "";
	char cuvinte[100][100];
	int d;
	cout << "Introduceti textul : ";
	cin.getline(text, 100);
	spargere(text, cuvinte, d);

	for (int i = 0; i < d; i++) {
		char r[200] = "";
		strcpy(r, cuvinte[i]);
		virgulaToPunct(r);
		double k = atof(r);
		if (k < 0) {
			cout << " ";
		}
		else {
			cout << cuvinte[i];
		}
		cout << " ";
	}
}



// Problema 3

void citire(int x[], int& n) {
	ifstream f("bac.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void bubbleSort(int x[], int n) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[i] > x[i + 1]) {
				int r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

void afisare(int x[], int n) {
	int y[3], m = 0;
	for (int i = n - 1; i > -1 && m < 3; i--) {
		if (x[i] % 100 == 20) {
			y[m] = x[i];
			m++;
		}
	}
	for (int i = 2; i > -1; i--) {
		cout << y[i] << " ";
	}
}

void rezolvareSub3Problema3() {
	int x[10000], n;
	citire(x, n);
	bubbleSort(x, n);
	afisare(x, n);
}