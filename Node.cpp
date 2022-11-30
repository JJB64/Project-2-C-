#include <sstream>
#include <iostream>
#include "Node.h"
Node::Node() {
    Ptr_parent = nullptr;
}

Node::Node(Airports state, Node parent, Routes actions) {
    this->state = state;
    Ptr_parent = &parent;
}

Node::Node(Airports state) {
    this->state = state;
    Ptr_parent  = NULL;
}

Airports Node::getState() {
    return state;
}

string Node::to_string() {
    return state.getAirportId();
}

void Node::Solution_path() {
    list<Airports> airports;
    list<string> airportsdata;
    airports.push_back(this->state);
    string flightpath;
    stringstream s;
    s << this->actions.getStops();
    string stops;
    s >> stops;
    int Tpath_cost = 0;


    while (Ptr_parent != nullptr) {
        flightpath = this->actions.getAirline() + " from " + this->Ptr_parent->getState().getIata() + " to " +
                     this->state.getIata() + " is " + stops + " stops " + "\r\n";
        Node parent_node = *Ptr_parent;
        Airports ParentState = parent_node.getState();
        airportsdata.push_back(flightpath);
        parent_node = *Ptr_parent;
        Tpath_cost += 1;
    }
    stringstream num;
    num << Tpath_cost;
    string TP_cost;
    num >> TP_cost;
    string TotalFlights = "Total flights to take:" + TP_cost;
    airports.reverse();

    ofstream outfile;
    outfile.open("Output.txt");
    if (outfile) {
        int number = 0;
        for (auto v: airportsdata) {
            number = number + 1;
            outfile << number << ". " << v << "\n";
        }
    } else {
        cout << "An error has occured and data could not be written to the file" << endl;
    }
    outfile.close();
}
//    return airports;






