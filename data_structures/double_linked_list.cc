#include<iostream>
using namespace std;

class double_linked_list {

    struct Node{
        int value;
        Node *previous_node;
        Node *next_node;
    };

    Node *head;

    public:
        double_linked_list(){
            head = NULL;
        }

        // O(1)
        double_linked_list(int value){
            head = new Node();
            head->value = value;
            head->next_node = NULL;
            head->previous_node = NULL;
        }

        // O(n)
        void push_back(int value){
            Node *temp = head;
            if (head == NULL){
                head = new Node();
                head->value = value;
                head->previous_node = NULL;
                head->next_node = NULL;
                return;
            }
            while(temp->next_node != NULL){
                temp = temp->next_node;
            }
            Node *newNode = new Node();
            newNode->value = value;
            newNode->previous_node = temp;
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
            temp->previous_node = NULL;
            temp->next_node = head;
            head->previous_node = temp;
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
                head->previous_node = NULL;
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
            if(deleteNode->next_node != NULL){
                deleteNode->next_node->previous_node = temp;
            }
            delete deleteNode;

        }
};

int main(){
    double_linked_list dll = double_linked_list();
    dll.push_back(3);
    dll.push_back(12);
    dll.push_back(100);
    cout << dll.get(2) << endl;
    dll.push_front(99);
    cout << dll.get(3) << endl;
    dll.delete_e(3);
    cout << dll.get(2) << endl;
}