#ifndef __STATE_H__
#define __STATE_H__
#include <vector>
using namespace std;

// définir une structure pour présenter des seau s1, s2,...,sn
struct state {
    int s1;
    int s2;
    int s3;
	int s4;
	int s5;
	int s6;
	//int s[5]; // possible utilisation replace s1, s2,..., sn
};

// déclarer le nombre de seau
int nb;

// VRAI si la solution, FALSE sison
bool searchValue;

// déclarer l'état final
bool goalState;
state goal;

// déclarer un array de integers qui représente la plus capacité de chaque seau
int capacity[10];
std::vector<state> outList;

// fonctions: "fill" pour remplir, "empty" pour vider, et "pour" pour transvaser pour toute les combination de seaus
state fill(int pos, state v);

state empty(int pos, state v);

state pour(int src, int tgt, state v);


#endif