#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[]) {
	for (int i = 0; i < 6; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k, string s[]) {
	bool apareSacou=0, aparePantofi=0, apareCravata=0;
	for (int i = 0; i <= k; i++) {
		if (s[i] == s[k] && i != k) {
			return 0;
		}
		if (s[i]== "sacou") {
			apareSacou = 1;
		}
		if (s[i] == "cravata") {
			if (apareSacou == 1) {
				return 0;
			}
			apareCravata = 1;
		}
		if (s[i] == "camasa" && (apareCravata == 1 || apareSacou == 1)) {
			return 0;
		}
		if (s[i] == "pantofi") {
			aparePantofi = 1;
		}
		if ((s[i] == "pantaloni" || s[i] == "sosete") && aparePantofi == 1) {
			return 0;
		}
	}
	return 1;
}

bool solutie1(int k) {
	if (k == 5) {
		return 1;
	}
	return 0;
}

void back(string x[], string s[], int k) {
	for (int i = 0; i < 6; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
			if (solutie1(k)) {
				tipar(s);
			}
			else {
				back(x, s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[6] = { "camasa","cravata","pantaloni","pantofi","sacou","sosete" };
	string s[10];

	back(x, s, 0);
}

// Subiectul 2

// Problema 2

struct solutie {
	double pre;
	double pim;
};

struct ecuatie {
	int nr;
	solutie solutie[100];
};

void rezolvareSub2Problema2() {
	ecuatie s;
}

// Subiectul 3

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

	int count = 0;
	for (int i = 0; i < d; i++) {
		char numar[100] = "";
		strcpy(numar, cuvinte[i]);
		int ki = atoi(numar);
		if (!(ki == 0 && numar[0] != '0')) {
			virgulaToPunct(numar);
			double kd = atof(numar);
			if (ki == kd) {
				count++;
			}
		}
	}
	cout << count << endl;
}

// Problema 3

void citireLast(int x[], int& n) {
	ifstream f("bac.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

int maxSuma(int x[], int n) {
	int max = x[0];
	for (int i = 0; i < n; i++) {
		int suma = 0;
		for (int j = i; j < n; j++) {
			suma += x[j];
			if (suma > max) {
				max = suma;
			}
		}
	}
	return max;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireLast(x, n);
	cout << maxSuma(x, n);
}