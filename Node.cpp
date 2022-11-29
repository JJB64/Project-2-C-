#include "Node.h"
Node::Node() {}

Node::Node(Airports state, Node parent)
{
    this->state = state;
    Node *ptr_parent = &parent;
};

Node::Node(Airports state) {
    this->state = state;
    Node *parent  = NULL;
}

Airports Node::getState() {
    return state;
}

string Node::to_string() {
    return state.getAirportId();
}

list<Airports> Node::Solution_path() {
    list<Airports> airports;
    airports.push_back(this->state);

    if(&parent != nullptr)
    {
        Node parent_node = *parent;
        while(&parent_node != nullptr){
            Airports parent_state = parent_node.getState();
            airports.push_back(parent_state);
            parent_node = *parent;

            if(parent_node.parent == NULL){
                break;
            };
            parent_state = parent_node.state;
        };
    }
    return airports;
}




