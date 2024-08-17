#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
public:
    Node* head;
    LinkedList() : head(NULL) {}
    
    void pushBack(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        
        if(head == NULL){
            head = newNode;
        }else{
            Node* tmp = head;
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            
            tmp->next = newNode;
        }
        
    }
    
    void deleteVal(Node* &head, int key){
        //empty
        if(!head){
            return;
        }
        //head case
        if(head->data == key){
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        
        
        // normal case
        Node *tmp = head;
        Node *prev = NULL;
        while(tmp != NULL && tmp->data != key){
            prev = tmp;
            tmp = tmp->next;
        }
        
        if(tmp == NULL){
            return;
        }
        
        prev->next = tmp->next;
        delete tmp;
    }
    
    int findMax(Node* head){
        int Mx = -2e9;
        
        Node* tmp = head;
        while(tmp){
            if(Mx < tmp->data){
                Mx = tmp->data;
            }
            tmp = tmp->next;
        }
        
        return Mx;
    }
};

int main()
{
    int n; //limit of summation of staff in boxes
    cin >> n;
    vector<int> boxes;
    for(int i = 0; i < 4; i++){
        int val;
        cin >> val;
        boxes.push_back(val);
    }
    
    vector<int> boxLimit;
    for(int i = 0; i < 4; i++){
        int val = n/boxes[i];
        boxLimit.push_back(val);
    }
    
    LinkedList* ll = new LinkedList();
    for(int i = 1; i <= n; i++){
        ll->pushBack(i);
    }

    for(int a = 0; a <= boxLimit[0]; a++){
        for(int b = 0; b <= boxLimit[1]; b++){
            for(int c = 0; c <= boxLimit[2]; c++){
                for(int d = 0; d <= boxLimit[3]; d++){
                    int sum = a*boxes[0] + b*boxes[1] + c*boxes[2] + d*boxes[3];
                    if(sum > n){
                        continue;
                    }else{
                        ll->deleteVal(ll->head, sum);
                    }
                }
            }
        }
    }
    
    for(Node* tmp = ll->head; tmp != NULL; tmp = tmp->next){
        cout << tmp->data << " ";
    }
    cout << endl;
    cout << ll->findMax(ll->head) << endl;

    return 0;
}