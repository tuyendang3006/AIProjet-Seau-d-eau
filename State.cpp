#include "State.h"


// fonctions: "fill" pour remplir, "empty" pour vider, et "pour" pour transvaser pour toute les combination de seaus
state fill(int pos, state v) {
    switch(pos){
    case 1: v.s1 = capacity[0];
            break;
    case 2: v.s2 = capacity[1];
            break;
    case 3: v.s3 = capacity[2];
            break;
	case 4: v.s4 = capacity[3];
            break;
	case 5: v.s5 = capacity[4];
            break;
	case 6: v.s6 = capacity[5];
            break;
    }
    return v;
}

state empty(int pos, state v) {
    switch (pos) {
    case 1: v.s1 = 0;
            break;
    case 2: v.s2 = 0;
            break;
    case 3: v.s3 = 0;
            break;
	case 4: v.s4 = 0;
	        break;
	case 5: v.s5 = 0;
	        break;
	case 6: v.s6 = 0;
            break;
    }
    return v;
}

state pour(int src, int tgt, state v) {
    /* la fonction manipule le volume d'eau dans chaque seau quand les seaus sont décrément ou inscrément
       jusqu'au la source de seau est vide ou plein*/
    switch (src) {
    case 1: 
        switch (tgt) {
        case 2: while (v.s1 > 0 && v.s2 < capacity[1]) {
            v.s1 -= 1;
            v.s2 += 1;
        }
            break;
        case 3: while (v.s1 > 0 && v.s3 < capacity[2]) {
            v.s1 -= 1;
            v.s3 += 1;
        };
		case 4: while (v.s1 > 0 && v.s4 < capacity[3]) {
            v.s1 -= 1;
            v.s4 += 1;
        };
            break;
		case 5: while (v.s1 > 0 && v.s5 < capacity[4]) {
            v.s1 -= 1;
            v.s5 += 1;
        };
		case 6: while (v.s1 > 0 && v.s6 < capacity[5]) {
            v.s1 -= 1;
            v.s6 += 1;
        };
            break;
        }
        break;
    case 2:
        switch (tgt) {
        case 1: while (v.s2 > 0 && v.s1 < capacity[0]) {
            v.s2 -= 1;
            v.s1 += 1;
        };
            break;
        case 3: while (v.s2 > 0 && v.s3 < capacity[2]) {
            v.s2 -= 1;
            v.s3 += 1;
        };
		case 4: while (v.s2 > 0 && v.s4 < capacity[3]) {
            v.s2 -= 1;
            v.s4 += 1;
        };
            break;
		case 5: while (v.s2 > 0 && v.s5 < capacity[4]) {
            v.s2 -= 1;
            v.s5 += 1;
        };
		case 6: while (v.s2 > 0 && v.s6 < capacity[5]) {
            v.s2 -= 1;
            v.s6 += 1;
        };
            break;
        }
        break;
    case 3: 
        switch (tgt) {
        case 1: while (v.s3 > 0 && v.s1 < capacity[0]) {
            v.s3 -= 1;
            v.s1 += 1;
        };
            break;
        case 2: while (v.s3 > 0 && v.s2 < capacity[1]) {
            v.s3 -= 1;
            v.s2 += 1;
        };
		case 4: while (v.s3 > 0 && v.s4 < capacity[3]) {
            v.s3 -= 1;
            v.s4 += 1;
        };
            break;
		case 5: while (v.s3 > 0 && v.s5 < capacity[4]) {
            v.s3 -= 1;
            v.s5 += 1;
        };
		case 6: while (v.s3 > 0 && v.s6 < capacity[5]) {
            v.s3 -= 1;
            v.s6 += 1;
        };
            break;
        }
        break;
	case 4: 
        switch (tgt) {
        case 1: while (v.s4 > 0 && v.s1 < capacity[0]) {
            v.s4 -= 1;
            v.s1 += 1;
        };
            break;
        case 2: while (v.s4 > 0 && v.s2 < capacity[1]) {
            v.s4 -= 1;
            v.s2 += 1;
        };
		case 3: while (v.s4 > 0 && v.s3 < capacity[2]) {
            v.s4 -= 1;
            v.s3 += 1;
        };
            break;
		case 5: while (v.s4 > 0 && v.s5 < capacity[4]) {
            v.s4 -= 1;
            v.s5 += 1;
        };
		case 6: while (v.s4 > 0 && v.s6 < capacity[5]) {
            v.s4 -= 1;
            v.s6 += 1;
        };
            break;
        }
	case 5: 
        switch (tgt) {
        case 1: while (v.s5 > 0 && v.s1 < capacity[0]) {
            v.s5 -= 1;
            v.s1 += 1;
        };
            break;
        case 2: while (v.s5 > 0 && v.s2 < capacity[1]) {
            v.s5 -= 1;
            v.s2 += 1;
        };
		case 3: while (v.s5 > 0 && v.s3 < capacity[2]) {
            v.s5 -= 1;
            v.s3 += 1;
        };
            break;
		case 4: while (v.s5 > 0 && v.s4 < capacity[3]) {
            v.s5 -= 1;
            v.s4 += 1;
        };
		case 6: while (v.s5 > 0 && v.s6 < capacity[5]) {
            v.s5 -= 1;
            v.s6 += 1;
        };
            break;
        }
	case 6: 
        switch (tgt) {
        case 1: while (v.s6 > 0 && v.s1 < capacity[0]) {
            v.s6 -= 1;
            v.s1 += 1;
        };
            break;
        case 2: while (v.s6 > 0 && v.s2 < capacity[1]) {
            v.s6 -= 1;
            v.s2 += 1;
        };
		case 3: while (v.s6 > 0 && v.s3 < capacity[2]) {
            v.s5 -= 1;
            v.s3 += 1;
        };
            break;
		case 4: while (v.s6 > 0 && v.s4 < capacity[3]) {
            v.s6 -= 1;
            v.s4 += 1;
        };
		case 6: while (v.s6 > 0 && v.s5 < capacity[4]) {
            v.s6 -= 1;
            v.s5 += 1;
        };
            break;
        }
        break;
    }
    return v;
}

