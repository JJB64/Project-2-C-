#include <iostream>
#include <list>
#include <unordered_map>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Airports.h"
#include "Routes.h"

using namespace std;


class Node{

private :
    Airports state;
    Node* Ptr_parent;
    Routes actions;
    int pathcost;



public:
    Node(Airports state, Node parent, Routes actions);

    Node(Airports state);

    Node();

    Airports getState();

    void Solution_path();

    string to_string();


};





