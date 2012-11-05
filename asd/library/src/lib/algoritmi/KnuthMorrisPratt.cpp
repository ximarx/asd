/**
 * Algoritmo per lo string-matching basato su
 * KMP (backtracking migliorato);
 */

#include "../common/stdInclude.h"

typedef char pattern[21];
typedef char text[100];
typedef int vettore[20];

void spostamenti(pattern patternS, vettore offsets){
	int patternLength = strlen(patternS);
	offsets[0] = 0; 
	int k = 0; 
	for (int q = 2; q <= patternLength; q++){
		while ((k > 0) && (patternS[k] != patternS[q-1]))
			k = offsets[k-1];
		if (patternS[k] == patternS[q-1]) 
			k++;
		offsets[q-1] = k;
	}
}

int KMP(text t, pattern p){
	vettore s;
	spostamenti(p, s);
	int risposta = -1;
	int q = 0;
	int m = strlen(p);
	int n = strlen(t);
	if (n >= m) {
		for (int i = 0; (i < n && q != m); i++){
			while ((q > 0) && (p[q] != t[i])) 
				q = s[q-1];
			if (p[q] == t[i])
				q++;
			if (q == m)
				risposta = i + 1 - m;
		}
	}
	return risposta + 1;
}


