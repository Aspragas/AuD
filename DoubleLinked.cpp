#include <stdio.h>

struct ListNode {
    int data;
    struct ListNode* prev;
    struct ListNode* next;
    
    ListNode(int v){
        data = v;
        next = NULL;
        prev = NULL;
    }
};


class LinkedList{
    ListNode* head;
    ListNode* new_node;
    ListNode* tail;
    ListNode* temp;
    
public:

    LinkedList(){head = NULL; tail = NULL;}

    void add(int v) {add(v, head);}
    void remove()   {remove(head);}
    void print()    {print(head);}
    void delbeg()   {delbeg(head);}
    void dellast()  {dellast(tail);}
private:

    int len = 0;
    
    void add(int v, ListNode* &ptr){
        if(ptr == NULL){
            ptr = new ListNode(v);
            head = tail = ptr;
            len++;;
        }else{
            new_node = new ListNode(v);
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
            len++;
        }
    }
    void print(ListNode* &ptr){
        if(ptr == NULL) return;
        printf("Element -> %d\n" , ptr->data);
        
        print(ptr->next);
    }
    void delbeg(ListNode* &ptr){
        if(head == NULL) printf("List is empty");
        temp = head;
        head = head->next;
        head->prev = NULL;
        len--;
        delete temp;
    }
    void dellast(ListNode* &ptr){
        if(tail == NULL) printf("List is empty");
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        len--;
        delete temp;
    }
    void remove(ListNode* &ptr){
        if(head == NULL) return;
        temp = head;
        int pos;
        int i = 1;
        printf("Which position do you want to remove ? (first = 1)(current maxi pos = %d)", len);
        scanf("%d", &pos);
        if(pos == 1){
            delbeg();
        }
        else if(pos == len){
            dellast();
        }else{
            while(i<pos){
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            len--;
        }
        
    }
};

int main(){
    int choose;
    bool quit = true;
    LinkedList* l = new LinkedList();
    do{
        char w;
        printf("-------------------------------\n");
        printf("WELCOME!!!\t");
        printf("Choose your operation\n");
        printf("1- Add a new element\n");
        printf("2- Print the list\n");
        printf("3- Remove from Position\n");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                int a;
                printf("The data of new node: \n");
                scanf("%d", &a);
                l->add(a);
                break;
            case 2:
                l->print();
                printf("\n");
                break;
            case 3:
                l->remove();
                break;
            default:
                printf("Invalid operation number!\n");
        }
        printf("do you want to continue ?:\n");
        scanf(" %c", &w);
        if(w == 'q'){
            quit = false;
        }
    }while(quit == true);
}