#include<iostream>
using namespace std;

class linked_list {

    struct Node{
        int value;
        Node *next_node;
    };

    Node *head;

    public:
        linked_list(){
            head = NULL;
        }

        // O(1)
        linked_list(int value){
            head = new Node();
            head->value = value;
            head->next_node = NULL;
        }

        // O(n)
        void push_back(int value){
            Node *temp = head;
            if (head == NULL){
                head = new Node();
                head->value = value;
                head->next_node = NULL;
                return;
            }
            while(temp->next_node != NULL){
                temp = temp->next_node;
            }
            Node *newNode = new Node();
            newNode->value = value;
            newNode->next_node = NULL;
            temp->next_node = newNode;
        }

        // 0(i)
        // -1 = item not found
        int get(int i){
            Node *temp = head;
            while (i > 0 && temp->next_node != NULL){
                --i;
                temp = temp->next_node;
            }
            if (i > 0 ){
                return -1;
            } else {
                return temp->value;
            }
        }

        // O(1)
        void push_front(int value){
            Node *temp = new Node();
            temp->value = value;
            temp->next_node = head;
            head = temp;
        }

        // O(i)
        // delete if i < linked_list.size()
        void delete_e(int i){
            Node *temp = head;
            if (i == 0){
                temp = head->next_node;
                delete head;
                head = temp;
                return;
            }
            --i;
            while (i > 0 && temp->next_node != NULL){
                --i;
                temp = temp->next_node;
            }
            if (i > 0){
                //element i does not exist
                return;
            }
            Node *deleteNode = temp->next_node;
            temp->next_node = deleteNode->next_node;
            delete deleteNode;

        }
};

int main(){
    linked_list ll = linked_list();
    ll.push_back(3);
    ll.push_back(12);
    ll.push_back(100);
    cout << ll.get(2) << endl;
    ll.push_front(99);
    cout << ll.get(3) << endl;
    ll.delete_e(3);
    cout << ll.get(2) << endl;
}