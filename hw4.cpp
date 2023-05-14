#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string.h>
#include<cmath>
using namespace std;

 
class Node {
public:
    string name;
    enum Character { SOURCE, CIV, HQ, SPY };
    Character character;
    Node(string name, Character character) {
        this->name = name;
        this->character = character;
    }
};

class Distance {
public:
    Node* node1;
    Node* node2;
    int distance;
    Distance(Node* node1, Node* node2, int distance) {
        this->node1 = node1;
        this->node2 = node2;
        this->distance = distance;
    }
};

vector<Node*> nodeTable;
vector<Distance*> distanceTable;

void insertNode(string name, Node::Character character) {
    Node* node = new Node(name, character);
    nodeTable.push_back(node);
}

void insertDistance(string node1Name, string node2Name, int distance) {
    Node* node1 = nullptr;
    Node* node2 = nullptr;
    for (Node* node : nodeTable) {
        if (node->name == node1Name) {
            node1 = node;
        }
        if (node->name == node2Name) {
            node2 = node;
        }
        if (node1 != nullptr && node2 != nullptr) {
            break;
        }
    }
    Distance* distanceObj = new Distance(node1, node2, distance);
    distanceTable.push_back(distanceObj);
}

void analyze() {
    // Implement Dijkstra's algorithm here
        
    int n = nodeTable.size();
    int dist[n];
    bool visited[n];
    int parent[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (Distance* distance : distanceTable) {
            if (distance->node1 == nodeTable[u]) {
                int v = -1;
                for (int i = 0; i < n; i++) {
                    if (nodeTable[i] == distance->node2) {
                        v = i;
                        break;
                    }
                }
                if (v == -1) {
                    continue;

}

int main() {
    // Parse the file and reserve the action slot
    // Fill in the action slot
    // Three commands are: INSERT, INSERT_EDGE, ANALYZE
    // Implement Dijkstra's algorithm
        
    string line;
    ifstream myfile("test1.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            stringstream ss(line);
            string command;
            ss >> command;
            if (command == "INSERT") {
                string name;
                string character;
                ss >> name >> character;
                Node::Character charEnum;
                if (character == "SOURCE") {
                    charEnum = Node::SOURCE;
                }
                else if (character == "CIV") {
                    charEnum = Node::CIV;
                }
                else if (character == "HQ") {
                    charEnum = Node::HQ;
                }
                else if (character == "SPY") {
                    charEnum = Node::SPY;
                }
                insertNode(name, charEnum);
            }
            else if (command == "INSERT_EDGE") {
                string node1Name;
                string node2Name;
                int distance;
                ss >> node1Name >> node2Name >> distance;
                insertDistance(node1Name, node2Name, distance);
            }
            else if (command == "ANALYZE") {
                analyze();
            }
        }
        myfile.close();
    }
    else {
        cout << "Unable to open file";
    }

    return 0;
}


// 1. Parse the file (and reserve the action slot)
// 2. Implement the slot, create the class objects and to the table (maybe a <vector>)
//      (There are two tables, node table and distance table)
//      Node: <Name, Character> ( For character SOURCE, CIV, HQ, SPY) ( also enumerate these Characters.)
//      Distance: <node1, node2, distance>
// 3. Fill in the action slot. There are three types of actions. You have to parse the action from "test1.txt" to 
// create the class objects
// 4. Three commands are: 
// INSERT <name> <character> (Node name and character)
// INSERT_EDGE <Node1> <Node2> <Word> (The Path of the dijkstra is defined as (1000/word))
// ANALYZE (output the result from dijkstra)
// The output format are as followed:
// <Name1> -> <Name2> -> ... (The nodes they passed by dijkstra's algorithm)
// <Word_count> (Sum of words)
// <Distance> (The total length they passed)
// 5. Implement Dijkstra's by diecribing the data structure of 2 Tables to the codegen. 
