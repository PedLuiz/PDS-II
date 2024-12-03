#include <iostream>
#include <list>

using namespace std;

class Node {
private:
    int id;

public:
    static int node_count;
    static int auto_id;

    Node() {
        node_count++;
        auto_id++;
        id = auto_id; 
    }

    Node(int id) : id(id) {
        node_count++;
    }

    ~Node() {
        node_count--;
    }

    int getId() {
        return id;
    }

    static int getCount() {
        return node_count;
    }

    Node* getAddress() {
        return this;
    }

    void printInfo() {
        cout << id << " " << this << endl;
    }
};

int Node::node_count = 0;
int Node::auto_id = 0;

int main() {
    list<Node*> nodes;

    bool flag = true;
    char option; 

    while (flag) {
        cin >> option;

        switch (option) {
            case 'E':
                flag = false;
                break;

            case 'A': {

                Node* new_node = new Node();
                new_node->printInfo();

                nodes.push_back(new_node);
                break;
            }

            case 'C': {
                int id; cin >> id;
                if (id >= 0) {
                    cout << "ERRO" << endl;
                    break;
                }
                Node* new_node = new Node(id);
                new_node->printInfo();

                nodes.push_front(new_node);
                break;
            }

            case 'R': { 
                if (nodes.empty()) {
                    cout << "ERRO" << endl;
                    break;
                }

                Node* front = nodes.front();
                front->printInfo();

                nodes.pop_front(); 
                delete front;
                break;
            }

            case 'N':
                cout << Node::getCount() << endl;
                break;
            
            case 'P': {
                int index; cin >> index;
                int n = Node::getCount();
                if ((index < 1) || (index > n) || (n == 0)) {
                    cout << "ERRO" << endl;
                    break;
                }

                for (auto& node : nodes) {
                    index--;
                    if (index == 0) {
                        node->printInfo();
                    }
                }
                break;
            }
            
            case 'L':
                for (auto& node : nodes) {
                    node->printInfo();
                }
                break;
        }
    }
    
    for (auto& i : nodes) {
        delete i;
    }

    return 0;
}