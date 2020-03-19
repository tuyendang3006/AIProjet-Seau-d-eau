/*
    RECHERCHE PARCOURS EN PROFONDEUR D'ABORD
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include "State.h"
#include "State.cpp"

//une expression lambda pour rechercher dans la liste des états enregistrés et 
//retourner true si l'état actuel a été trouvé (c'est-à-dire 
// si la combinaison unique des deux volumes existe déjà dans la liste)
bool searcher2(state v) {
    searchValue = false;
    std::for_each(outList.begin(), outList.end(), [v](state x) {
        if (x.s1 == v.s1 && x.s2 == v.s2) {          
            searchValue = true;
        }
    });
    return searchValue;
}

// Algorithme de recherche: Parcours la meilleur d'abord 
// En case: 2 seaus
void dfs2() {
    std::stack<state> nodeStack; // créer la pile de recherche 
    state tmp;
    state v;
    state init = { 0,0};
    nodeStack.push(init); //initialiser la pile avec l'initial état 
    outList.push_back(init);
    while (!nodeStack.empty()) {// programe exécute jusqu'au la pile est vide 
        v = nodeStack.top(); // node courant 
        
		// Si le problème a une solution, "size of output" est le cout de recherche
        if (goalState == true) {
            if (v.s1 == goal.s1 && v.s2 == goal.s2) {
                for (auto &i : outList) {
					// liste d'état 
                    std::cout << i.s1 << " " << i.s2 << "\n";
                }
                std::cout << "Size of output list: " << outList.size() << "\n";
                std::cout << "Goal State Reached\n";
                return;
            }
        }

		// Début de la génération du nœud fils. Chaque nœud peut avoir <= 6 fils
        // chacun de ces générateurs appelle la fonction 'searcher' pour vérifier si le fils est déjà trouvé.
		
        // D'abord, gère les 1 fils 'fill' possibles
        if (v.s1 < capacity[0] && searcher2(fill(1, v)) == false) {
            tmp = fill(1, v);//appel la fonction 'fill'
            nodeStack.push(tmp);//empiler nouvelle noeud à pile 
            outList.push_back(tmp);// ajouter nouvelle noeud à outList 
        }
       
        //ensuite, handler the 2 possible 'empty' fils
		// 2 possible 'empty' fils
        else if (v.s1 > 0 && searcher2(empty(1, v)) == false) {
            tmp = empty(1, v);// appel la fonction 'empty'
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && searcher2(empty(2, v)) == false) {
            tmp = empty(2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
       
        //2 possible 'pour' fils
        else if (v.s1 > 0 && v.s2 < capacity[1] && searcher2(pour(1, 2, v)) == false) {
            tmp = pour(1, 2, v);// appel la fontion 'pour'
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && v.s1 < capacity[0] && searcher2(pour(2, 1, v)) == false) {
            tmp = pour(2, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		
		// enfin, "fill" un autre fils
		else if (v.s2 < capacity[1] && searcher2(fill(2, v)) == false) {
            tmp = fill(2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        
        
		//lorsqu'aucun des fils ci-dessus n'est valide, soit parce que
        //le nœud actuel n'a pas de fils, ou les fils qu'il a sont déjà
        //présent dans la liste de sortie, le nœud actuel est extrait de la pile pour permettre
        //le programme pour monter d'un niveau
        else {
            nodeStack.pop();
        }    
    }
	
	//outList de tous les nœuds trouvés et donne la taille de la liste
    for (auto &i : outList) {
        std::cout << i.s1 << " " << i.s2 <<  "\n";       
    }
	// c'est le cout de recherche
    std::cout << "Size of output list: " << outList.size() << "\n";

};


//une expression lambda pour rechercher dans la liste des états enregistrés et 
//retourner true si l'état actuel a été trouvé (c'est-à-dire 
// si la combinaison unique des trois volumes existe déjà dans la liste)
bool searcher3(state v) {
    searchValue = false;
    std::for_each(outList.begin(), outList.end(), [v](state x) {
        if (x.s1 == v.s1 && x.s2 == v.s2 && x.s3 == v.s3) {
            
            searchValue = true;
        }
    });
    return searchValue;
}


// Algorithme de recherche: Parcours en profondeur d'abord 
// En cas: 3 seaus
void dfs3() {
    std::stack<state> nodeStack; // créer la pile de recherche 
    state tmp;
    state v;
    state init = { 0,0,0 };
    nodeStack.push(init);//initialiser la pile avec l'initial état 
    outList.push_back(init);
    while (!nodeStack.empty()) {// programe exécute jusqu'au la pile est vide 
        v = nodeStack.top(); // node courant 
       
        if (goalState == true) {
            if (v.s1 == goal.s1 && v.s2 == goal.s2 && v.s3 == goal.s3) {
                for (auto &i : outList) {
					// liste d'état 
                    std::cout << i.s1 << " " << i.s2 << " " << i.s3 << "\n";
                }
                std::cout << "Size of output list: " << outList.size() << "\n";
                std::cout << "Goal State Reached\n";
                return;
            }
        }

		// début de la génération du nœud fils. chaque nœud peut avoir> = 12 fils
        // chacun de ces générateurs appelle la fonction 'searcher' pour vérifier si l'enfant est déjà trouvé
		
        // d'abord, gère 1 fils 'fill' possibles
        if (v.s1 < capacity[0] && searcher3(fill(1, v)) == false) {
            tmp = fill(1, v);//appel la fonction 'fill'
            nodeStack.push(tmp);//empiler nouvelle noeud à pile 
            outList.push_back(tmp);// ajouter nouvelle noeud à outList 
        }
		
        //ensuite, handler the 3 possible 'empty' fils
		// 3 possible 'empty' fils
        else if (v.s1 > 0 && searcher3(empty(1, v)) == false) {
            tmp = empty(1, v);// appel la fonction 'empty'
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && searcher3(empty(2, v)) == false) {
            tmp = empty(2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && searcher3(empty(3, v)) == false) {
            tmp = empty(3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		
        //6 possible 'pour' fils
        else if (v.s1 > 0 && v.s2 < capacity[1] && searcher3(pour(1, 2, v)) == false) {
            tmp = pour(1, 2, v);// appel la fontion 'pour'
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s1 > 0 && v.s3 < capacity[2] && searcher3(pour(1, 3, v)) == false) {
            tmp = pour(1, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && v.s1 < capacity[0] && searcher3(pour(2, 1, v)) == false) {
            tmp = pour(2, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && v.s3 < capacity[2] && searcher3(pour(2, 3, v)) == false) {
            tmp = pour(2, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && v.s1 < capacity[0] && searcher3(pour(3, 1, v)) == false) {
            tmp = pour(3, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && v.s2 < capacity[1] && searcher3(pour(3, 2, v)) == false) {
            tmp = pour(3, 2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		
		// enfin, "fill" autres fils
		else if (v.s2 < capacity[1] && searcher3(fill(2, v)) == false) {
            tmp = fill(2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 < capacity[2] && searcher3(fill(3, v)) == false) {
            tmp = fill(3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }

		//lorsqu'aucun des fils ci-dessus n'est valide, soit parce que
        //le nœud actuel n'a pas de fils, ou les fils qu'il a sont déjà
        //présent dans la liste de sortie, le nœud actuel est extrait de la pile pour permettre
        //le programme pour monter d'un niveau
        else {
            nodeStack.pop();
        }
        
    }
	
	//outList de tous les nœuds trouvés et donne la taille de la liste
    for (auto &i : outList) {
        std::cout << i.s1 << " " << i.s2 << " " << i.s3 << "\n";       
    }
	
	std::cout << "Size of output list: " << outList.size() << "\n";

};


//une expression lambda pour rechercher dans la liste des états enregistrés et 
//retourner true si l'état actuel a été trouvé (c'est-à-dire 
// si la combinaison unique des quatre volumes existe déjà dans la liste)
bool searcher4(state v) {
    searchValue = false;
    std::for_each(outList.begin(), outList.end(), [v](state x) {
        if (x.s1 == v.s1 && x.s2 == v.s2 && x.s3 == v.s3 && x.s4 == v.s4) {
            
            searchValue = true;
        }
    });
    return searchValue;
}

// Algorithme de recherche: Parcours en profondeur d'abord 
// En cas: 4 seaus
void dfs4() {
    std::stack<state> nodeStack; // créer la pile de recherche 
    state tmp;
    state v;
    state init = { 0,0,0,0 };
    nodeStack.push(init);//initialiser la pile avec l'initial état 
    outList.push_back(init);
    while (!nodeStack.empty()) {// programe exécute jusqu'au la pile est vide 
        v = nodeStack.top(); // node courant 
       
        if (goalState == true) {
            if (v.s1 == goal.s1 && v.s2 == goal.s2 && v.s3 == goal.s3 && v.s4 == goal.s4) {
                for (auto &i : outList) {
					// liste d'état 
                    std::cout << i.s1 << " " << i.s2 << " " << i.s3 <<  " " << i.s4 << "\n";
                }
                std::cout << "Size of output list: " << outList.size() << "\n";
                std::cout << "Goal State Reached\n";
                return;
            }
        }

		// début de la génération du nœud fils. chaque nœud peut avoir> = 20 fils
        // chacun de ces générateurs appelle la fonction 'searcher' pour vérifier si le fils est déjà trouvé
		
        // d'abord, gère les quatres fils 'fill' possibles
        if (v.s1 < capacity[0] && searcher4(fill(1, v)) == false) {
            tmp = fill(1, v);//appel la fonction 'fill'
            nodeStack.push(tmp);//empiler nouvelle noeud à pile 
            outList.push_back(tmp);// ajouter nouvelle noeud à outList 
        }
		
        //ensuite, handler 4 possible 'empty' fils
		// 4 possible 'empty' fils
        else if (v.s1 > 0 && searcher4(empty(1, v)) == false) {
            tmp = empty(1, v);// appel la fonction 'empty'
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && searcher4(empty(2, v)) == false) {
            tmp = empty(2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && searcher4(empty(3, v)) == false) {
            tmp = empty(3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && searcher4(empty(4, v)) == false) {
            tmp = empty(4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		
        //12 possible 'pour' fils
        else if (v.s1 > 0 && v.s2 < capacity[1] && searcher4(pour(1, 2, v)) == false) {
            tmp = pour(1, 2, v);// appel la fontion 'pour'
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s1 > 0 && v.s3 < capacity[2] && searcher4(pour(1, 3, v)) == false) {
            tmp = pour(1, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s1 > 0 && v.s4 < capacity[3] && searcher4(pour(1, 4, v)) == false) {
            tmp = pour(1, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && v.s1 < capacity[0] && searcher4(pour(2, 1, v)) == false) {
            tmp = pour(2, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && v.s3 < capacity[2] && searcher4(pour(2, 3, v)) == false) {
            tmp = pour(2, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s2 > 0 && v.s4 < capacity[3] && searcher4(pour(2, 4, v)) == false) {
            tmp = pour(2, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && v.s1 < capacity[0] && searcher4(pour(3, 1, v)) == false) {
            tmp = pour(3, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && v.s2 < capacity[1] && searcher4(pour(3, 2, v)) == false) {
            tmp = pour(3, 2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s3 > 0 && v.s4 < capacity[3] && searcher4(pour(3, 4, v)) == false) {
            tmp = pour(3, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && v.s1 < capacity[0] && searcher4(pour(4, 1, v)) == false) {
            tmp = pour(4, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s4 > 0 && v.s2 < capacity[1] && searcher4(pour(4, 2, v)) == false) {
            tmp = pour(4, 2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && v.s3 < capacity[2] && searcher4(pour(4, 3, v)) == false) {
            tmp = pour(4, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		
		// enfin, "fill" autres fils
		else if (v.s2 < capacity[1] && searcher4(fill(2, v)) == false) {
            tmp = fill(2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 < capacity[2] && searcher4(fill(3, v)) == false) {
            tmp = fill(3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 < capacity[3] && searcher4(fill(4, v)) == false) {
            tmp = fill(4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }


		//lorsqu'aucun des fils ci-dessus n'est valide, soit parce que
        //le nœud actuel n'a pas de fils, ou les fils qu'il a sont déjà
        //présent dans la liste de sortie, le nœud actuel est extrait de la pile pour permettre
        //le programme pour monter d'un niveau
        else {
            nodeStack.pop();
        }
        
    }
	
	//outList de tous les nœuds trouvés et donne la taille de la liste
    for (auto &i : outList) {

        std::cout << i.s1 << " " << i.s2 << " " << i.s3 << " " <<i.s4 << "\n";
        
    }
	if(outList.size() < 10000)
		std::cout << "Size of output list: " << outList.size() << "\n";
	else
		std::cout << "No solution !\n";

};

bool searcher5(state v) {
    searchValue = false;
    std::for_each(outList.begin(), outList.end(), [v](state x) {
        if (x.s1 == v.s1 && x.s2 == v.s2 && x.s3 == v.s3 && x.s4 == v.s4 && x.s5 == v.s5) {            
            searchValue = true;
        }
    });
    return searchValue;
}

// Algorithme de recherche: Parcours en profondeur d'abord 
// En cas: 5 seaus
void dfs5() {
    std::stack<state> nodeStack; // créer la pile de recherche 
    state tmp;
    state v;
    state init = { 0,0,0,0,0 };
    nodeStack.push(init);//initialiser la pile avec l'initial état 
    outList.push_back(init);
    while (!nodeStack.empty()) {// programe exécute jusqu'au la pile est vide 
        v = nodeStack.top(); // node courant 
       
        if (goalState == true) {
            if (v.s1 == goal.s1 && v.s2 == goal.s2 && v.s3 == goal.s3 && v.s4 == goal.s4 && v.s5 == goal.s5) {
                for (auto &i : outList) {
					// liste d'état 
                    std::cout << i.s1 << " " << i.s2 << " " << i.s3 <<  " " << i.s4 << " " << i.s5 << "\n";
                }
                std::cout << "Size of output list: " << outList.size() << "\n";
                std::cout << "Goal State Reached\n";
                return;
            }
        }

		// début de la génération du nœud fils. chaque nœud peut avoir> = 30 fils
        // chacun de ces générateurs appelle la fonction 'searcher' pour vérifier si le fils est déjà trouvé
		
        // d'abord, gère les 5 fils 'fill' possibles
        if (v.s1 < capacity[0] && searcher5(fill(1, v)) == false) {
            tmp = fill(1, v);//appel la fonction 'fill'
            nodeStack.push(tmp);//empiler nouvelle noeud à pile 
            outList.push_back(tmp);// ajouter nouvelle noeud à outList 
        }
		
		
        //ensuite, handler 5 possible 'empty' fils
		// 5 possible 'empty' fils
        else if (v.s1 > 0 && searcher5(empty(1, v)) == false) {
            tmp = empty(1, v);// appel la fonction 'empty'
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && searcher5(empty(2, v)) == false) {
            tmp = empty(2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && searcher5(empty(3, v)) == false) {
            tmp = empty(3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && searcher5(empty(4, v)) == false) {
            tmp = empty(4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s5 > 0 && searcher5(empty(5, v)) == false) {
            tmp = empty(5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		
        //20 possible 'pour' fils
        else if (v.s1 > 0 && v.s2 < capacity[1] && searcher5(pour(1, 2, v)) == false) {
            tmp = pour(1, 2, v);// appel la fontion 'pour'
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s1 > 0 && v.s3 < capacity[2] && searcher5(pour(1, 3, v)) == false) {
            tmp = pour(1, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s1 > 0 && v.s4 < capacity[3] && searcher5(pour(1, 4, v)) == false) {
            tmp = pour(1, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s1 > 0 && v.s5 < capacity[4] && searcher5(pour(1, 5, v)) == false) {
            tmp = pour(1, 5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && v.s1 < capacity[0] && searcher5(pour(2, 1, v)) == false) {
            tmp = pour(2, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && v.s3 < capacity[2] && searcher5(pour(2, 3, v)) == false) {
            tmp = pour(2, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s2 > 0 && v.s4 < capacity[3] && searcher5(pour(2, 4, v)) == false) {
            tmp = pour(2, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s2 > 0 && v.s5 < capacity[4] && searcher5(pour(2, 5, v)) == false) {
            tmp = pour(2, 5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && v.s1 < capacity[0] && searcher5(pour(3, 1, v)) == false) {
            tmp = pour(3, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && v.s2 < capacity[1] && searcher5(pour(3, 2, v)) == false) {
            tmp = pour(3, 2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s3 > 0 && v.s4 < capacity[3] && searcher5(pour(3, 4, v)) == false) {
            tmp = pour(3, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s3 > 0 && v.s5 < capacity[4] && searcher5(pour(3, 5, v)) == false) {
            tmp = pour(3, 5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && v.s1 < capacity[0] && searcher5(pour(4, 1, v)) == false) {
            tmp = pour(4, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s4 > 0 && v.s2 < capacity[1] && searcher5(pour(4, 2, v)) == false) {
            tmp = pour(4, 2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && v.s3 < capacity[2] && searcher5(pour(4, 3, v)) == false) {
            tmp = pour(4, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && v.s5 < capacity[4] && searcher5(pour(4, 5, v)) == false) {
            tmp = pour(4, 5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s5 > 0 && v.s1 < capacity[0] && searcher5(pour(5, 1, v)) == false) {
            tmp = pour(5, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s5 > 0 && v.s2 < capacity[1] && searcher5(pour(5, 2, v)) == false) {
            tmp = pour(5, 2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s5 > 0 && v.s3 < capacity[2] && searcher5(pour(5, 3, v)) == false) {
            tmp = pour(5, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s5 > 0 && v.s4 < capacity[3] && searcher5(pour(5, 4, v)) == false) {
            tmp = pour(5, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		
		// enfin, "fill" autres fils
		else if (v.s2 < capacity[1] && searcher5(fill(2, v)) == false) {
            tmp = fill(2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 < capacity[2] && searcher5(fill(3, v)) == false) {
            tmp = fill(3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 < capacity[3] && searcher5(fill(4, v)) == false) {
            tmp = fill(4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s5 < capacity[4] && searcher5(fill(5, v)) == false) {
            tmp = fill(5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		
		//lorsqu'aucun des fils ci-dessus n'est valide, soit parce que
        //le nœud actuel n'a pas de fils, ou les fils qu'il a sont déjà
        //présent dans la liste de sortie, le nœud actuel est extrait de la pile pour permettre
        //le programme pour monter d'un niveau
        else {
            nodeStack.pop();
        }
        
    }//outList de tous les nœuds trouvés et donne la taille de la liste
    for (auto &i : outList) {

        std::cout << i.s1 << " " << i.s2 << " " << i.s3 << " " <<i.s4 << " " << i.s5 << "\n";
        
    }
	if(outList.size() < 10000)
		std::cout << "Size of output list: " << outList.size() << "\n";
	else
		std::cout << "No solution !\n";

};

//une expression lambda pour rechercher dans la liste des états enregistrés et 
//retourner true si l'état actuel a été trouvé (c'est-à-dire 
// si la combinaison unique des six volumes existe déjà dans la liste)
bool searcher6(state v) {
    searchValue = false;
    std::for_each(outList.begin(), outList.end(), [v](state x) {
        if (x.s1 == v.s1 && x.s2 == v.s2 && x.s3 == v.s3 && x.s4 == v.s4 && x.s5 == v.s5 && x.s6 == v.s6) {            
            searchValue = true;
        }
    });
    return searchValue;
}

// Algorithme de recherche: Parcours en profondeur d'abord 
// En cas: 6 seaus
void dfs6() {
    std::stack<state> nodeStack; // créer la pile de recherche 
    state tmp;
    state v;
    state init = { 0,0,0,0,0,0 };
    nodeStack.push(init);//initialiser la pile avec l'initial état 
    outList.push_back(init);
    while (!nodeStack.empty()) {// programe exécute jusqu'au la pile est vide 
        v = nodeStack.top(); // node courant 
       
        if (goalState == true) {
            if (v.s1 == goal.s1 && v.s2 == goal.s2 && v.s3 == goal.s3 && v.s4 == goal.s4 && v.s5 == goal.s5 && v.s6 == goal.s6) {
                for (auto &i : outList) {
					// liste d'état 
                    std::cout << i.s1 << " " << i.s2 << " " << i.s3 <<  " " << i.s4 << " " << i.s5 <<" " << i.s6 << "\n";
                }
                std::cout << "Size of output list: " << outList.size() << "\n";
                std::cout << "Goal State Reached\n";
                return;
            }
        }

		// début de la génération du nœud fils. chaque nœud peut avoir> = 42 fils
        // chacun de ces générateurs appelle la fonction 'searcher' pour vérifier si le fils est déjà trouvé
		
        // d'abord, gère le 1 fils 'fill' possibles
        if (v.s1 < capacity[0] && searcher6(fill(1, v)) == false) {
            tmp = fill(1, v);//appel la fonction 'fill'
            nodeStack.push(tmp);//empiler nouvelle noeud à pile 
            outList.push_back(tmp);// ajouter nouvelle noeud à outList 
        }
        
		
        //ensuite, handler 6 possible 'empty' fils
		// 6 possible 'empty' fils
        else if (v.s1 > 0 && searcher6(empty(1, v)) == false) {
            tmp = empty(1, v);// appel la fonction 'empty'
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && searcher6(empty(2, v)) == false) {
            tmp = empty(2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && searcher6(empty(3, v)) == false) {
            tmp = empty(3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && searcher6(empty(4, v)) == false) {
            tmp = empty(4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s5 > 0 && searcher6(empty(5, v)) == false) {
            tmp = empty(5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s6 > 0 && searcher6(empty(6, v)) == false) {
            tmp = empty(6, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		
        //30 possible 'pour' fils
        else if (v.s1 > 0 && v.s2 < capacity[1] && searcher6(pour(1, 2, v)) == false) {
            tmp = pour(1, 2, v);// appel la fontion 'pour'
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s1 > 0 && v.s3 < capacity[2] && searcher6(pour(1, 3, v)) == false) {
            tmp = pour(1, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s1 > 0 && v.s4 < capacity[3] && searcher6(pour(1, 4, v)) == false) {
            tmp = pour(1, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s1 > 0 && v.s5 < capacity[4] && searcher6(pour(1, 5, v)) == false) {
            tmp = pour(1, 5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s1 > 0 && v.s6 < capacity[5] && searcher6(pour(1, 6, v)) == false) {
            tmp = pour(1, 6, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && v.s1 < capacity[0] && searcher6(pour(2, 1, v)) == false) {
            tmp = pour(2, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s2 > 0 && v.s3 < capacity[2] && searcher6(pour(2, 3, v)) == false) {
            tmp = pour(2, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s2 > 0 && v.s4 < capacity[3] && searcher6(pour(2, 4, v)) == false) {
            tmp = pour(2, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s2 > 0 && v.s5 < capacity[4] && searcher6(pour(2, 5, v)) == false) {
            tmp = pour(2, 5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s2 > 0 && v.s6 < capacity[5] && searcher6(pour(2, 6, v)) == false) {
            tmp = pour(2, 6, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && v.s1 < capacity[0] && searcher6(pour(3, 1, v)) == false) {
            tmp = pour(3, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 > 0 && v.s2 < capacity[1] && searcher6(pour(3, 2, v)) == false) {
            tmp = pour(3, 2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s3 > 0 && v.s4 < capacity[3] && searcher6(pour(3, 4, v)) == false) {
            tmp = pour(3, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s3 > 0 && v.s5 < capacity[4] && searcher6(pour(3, 5, v)) == false) {
            tmp = pour(3, 5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s3 > 0 && v.s6 < capacity[5] && searcher6(pour(3, 6, v)) == false) {
            tmp = pour(3, 6, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && v.s1 < capacity[0] && searcher6(pour(4, 1, v)) == false) {
            tmp = pour(4, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s4 > 0 && v.s2 < capacity[1] && searcher6(pour(4, 2, v)) == false) {
            tmp = pour(4, 2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && v.s3 < capacity[2] && searcher6(pour(4, 3, v)) == false) {
            tmp = pour(4, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && v.s5 < capacity[4] && searcher6(pour(4, 5, v)) == false) {
            tmp = pour(4, 5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 > 0 && v.s6 < capacity[5] && searcher6(pour(4, 6, v)) == false) {
            tmp = pour(4, 6, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s5 > 0 && v.s1 < capacity[0] && searcher6(pour(5, 1, v)) == false) {
            tmp = pour(5, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s5 > 0 && v.s2 < capacity[1] && searcher6(pour(5, 2, v)) == false) {
            tmp = pour(5, 2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s5 > 0 && v.s3 < capacity[2] && searcher6(pour(5, 3, v)) == false) {
            tmp = pour(5, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s5 > 0 && v.s4 < capacity[3] && searcher6(pour(5, 4, v)) == false) {
            tmp = pour(5, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s5 > 0 && v.s6 < capacity[5] && searcher6(pour(5, 6, v)) == false) {
            tmp = pour(5, 6, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s6 > 0 && v.s1 < capacity[0] && searcher6(pour(6, 1, v)) == false) {
            tmp = pour(6, 1, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s6 > 0 && v.s2 < capacity[1] && searcher6(pour(6, 2, v)) == false) {
            tmp = pour(6, 2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s6 > 0 && v.s3 < capacity[2] && searcher6(pour(6, 3, v)) == false) {
            tmp = pour(6, 3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s6 > 0 && v.s4 < capacity[3] && searcher6(pour(6, 4, v)) == false) {
            tmp = pour(6, 4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s6 > 0 && v.s5 < capacity[4] && searcher6(pour(6, 5, v)) == false) {
            tmp = pour(6, 5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		
		// enfin, "fill" autres fils
		else if (v.s2 < capacity[1] && searcher6(fill(2, v)) == false) {
            tmp = fill(2, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        else if (v.s3 < capacity[2] && searcher6(fill(3, v)) == false) {
            tmp = fill(3, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s4 < capacity[3] && searcher6(fill(4, v)) == false) {
            tmp = fill(4, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s5 < capacity[4] && searcher6(fill(5, v)) == false) {
            tmp = fill(5, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
		else if (v.s6 < capacity[5] && searcher6(fill(6, v)) == false) {
            tmp = fill(6, v);
            nodeStack.push(tmp);
            outList.push_back(tmp);
        }
        
		//lorsqu'aucun des fils ci-dessus n'est valide, soit parce que
        //le nœud actuel n'a pas de fils, ou les fils qu'il a sont déjà
        //présent dans la liste de sortie, le nœud actuel est extrait de la pile pour permettre
        //le programme pour monter d'un niveau
        else {
            nodeStack.pop();
        }
        
    }
	//outList de tous les nœuds trouvés et donne la taille de la liste
    for (auto &i : outList) {

        std::cout << i.s1 << " " << i.s2 << " " << i.s3 << " " <<i.s4 <<" " << i.s5 << " " <<i.s6 << "\n";
        
    }
	if(outList.size() < 10000)
		std::cout << "Size of output list: " << outList.size() << "\n";
	else
		std::cout << "No solution !\n";

};


int main()
{   
    char yn;
    goalState = false;
	
	std::cout << " WELCOM TO WATER JUG PROBLEM WITH DEPTH FIRST SEARCH \n\n";
	
	std::cout << "Enter the number of jugs: \n";
	std::cin >> nb;
	
	// Des cases de nombre de seaus
	if(nb == 2){
		//entrer les capacités
		std::cout << "Input capacities A and B, one at a time: \n";
		std::cin >> capacity[0];
		std::cin >> capacity[1];

		//permet à l'utilisateur de spécifier un état d'objectif facultatif auquel le programme s'arrêtera
		std::cout << "Goal State? y/n\n";
		std::cin >> yn;
		if (yn == 'y') {
			std::cout << "Enter Goal State: \n";
			std::cin >> goal.s1;
			std::cin >> goal.s2;

			goalState = true;
			std::cout << "\n";
		}
		//appel de fonction
		dfs2();
	}
		
	else if(nb == 3){
		
		//entrer les capacités
		std::cout << "Input capacities A, B and C, one at a time: \n";
		std::cin >> capacity[0];
		std::cin >> capacity[1];
		std::cin >> capacity[2];
		//std::cin >> capacity[4];
		//permet à l'utilisateur de spécifier un état d'objectif facultatif auquel le programme s'arrêtera
		std::cout << "Goal State? y/n\n";
		std::cin >> yn;
		if (yn == 'y') {
			std::cout << "Enter Goal State: \n";
			std::cin >> goal.s1;
			std::cin >> goal.s2;
			std::cin >> goal.s3;
			goalState = true;
			std::cout << "\n";
		}
		//appel de fonction
		dfs3();
	}
	else if(nb == 4){
		
		//entrer les capacités
		std::cout << "Input capacities A, B, C and D, one at a time: \n";
		std::cin >> capacity[0];
		std::cin >> capacity[1];
		std::cin >> capacity[2];
		std::cin >> capacity[3];
		
		//permet à l'utilisateur de spécifier un état d'objectif facultatif auquel le programme s'arrêtera
		std::cout << "Goal State? y/n\n";
		std::cin >> yn;
		if (yn == 'y') {
			std::cout << "Enter Goal State: \n";
			std::cin >> goal.s1;
			std::cin >> goal.s2;
			std::cin >> goal.s3;
			std::cin >> goal.s4;
			goalState = true;
			std::cout << "\n";
		}
		// appel de fonction 
		dfs4();
	}
	else if(nb == 5){
		
		//entrer les capacités
		std::cout << "Input capacities A, B, C, D and E, one at a time: \n";
		std::cin >> capacity[0];
		std::cin >> capacity[1];
		std::cin >> capacity[2];
		std::cin >> capacity[3];
		std::cin >> capacity[4];
		
		//permet à l'utilisateur de spécifier un état d'objectif facultatif auquel le programme s'arrêtera
		std::cout << "Goal State? y/n\n";
		std::cin >> yn;
		if (yn == 'y') {
			std::cout << "Enter Goal State: \n";
			std::cin >> goal.s1;
			std::cin >> goal.s2;
			std::cin >> goal.s3;
			std::cin >> goal.s4;
			std::cin >> goal.s5;
			goalState = true;
			std::cout << "\n";
		}
		// appel de fonction 
		dfs5();
	}
	else if(nb == 6){
		
		//entrer les capacités
		std::cout << "Input capacities A, B, C, D, E and F, one at a time: \n";
		std::cin >> capacity[0];
		std::cin >> capacity[1];
		std::cin >> capacity[2];
		std::cin >> capacity[3];
		std::cin >> capacity[4];
		std::cin >> capacity[5];
		
		//permet à l'utilisateur de spécifier un état d'objectif facultatif auquel le programme s'arrêtera
		std::cout << "Goal State? y/n\n";
		std::cin >> yn;
		if (yn == 'y') {
			std::cout << "Enter Goal State: \n";
			std::cin >> goal.s1;
			std::cin >> goal.s2;
			std::cin >> goal.s3;
			std::cin >> goal.s4;
			std::cin >> goal.s5;
			std::cin >> goal.s6;
			goalState = true;
			std::cout << "\n";
		}
		// appel de fonction 
		dfs6();
	}
	else std::cout << "Not found ! \n";
    system("PAUSE");

}