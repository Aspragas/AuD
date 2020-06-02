#include <stdio.h>
#include <iostream>

struct ListNode{
    int data;
    ListNode* next;

    ListNode(){
        next = NULL;
    }
};

class LinkedList{
    ListNode* head;

public:
    LinkedList() { head = NULL; }

    void get(){get(head);}
    void insert(){insert(head);}
    void remove(){remove(head);}
    void length(){length(head);}
    void print(){print(head);}
    void set(int a){set(a, head);}

private:
    void get(ListNode* &ptr){
        int p;
        std::cout << "which element would you like to get ?: " << std::endl;
        std::cin >> p;
        for(int i = 0; i<p; ++i){
            ptr = ptr->next;
        }
        printf("%d", ptr->data);
    }
    void print(ListNode* &ptr){
        if(ptr == NULL) return;
        printf("%d\n", ptr->data);
        print(ptr->next);
    }
    void insert(ListNode* &ptr){
        int a, p;
        std::cout << "which element do you want to insert ?:" << std::endl;
        std::cin >> p;
        for(int i = 0; i<p; ++i){
            ptr = ptr->next;
        }
        ptr->data = a;
        printf("the Element is: %d\n", a);
    }
    void remove(ListNode* &ptr){
        int p;
        std::cout << "which element do you want to remove ?:" << std::endl;
        std::cin >> p;
        for(int i = 0; i<p ; ++i){
            ptr = ptr->next;
        }
        ListNode* temp;
        temp = ptr->next;
        ptr->next = temp;
        delete temp;
    }
    void length(ListNode* &ptr){
        if(ptr == NULL)return;
        int count = 0;
        ListNode* current = head;
        while(current!= NULL){
            count++;
            current = current->next;
        }
        printf("the number of elements in the list: %d\n\n", count);
    }
    void set(int a, ListNode* &ptr){
        if(ptr == NULL){
            ptr = new ListNode();
            ptr->data = a;
        }else{
            set(a,ptr->next);
        }
    }

};

int main(){
    bool q = true;
    LinkedList* l = new LinkedList();
    do{
        int s;
        char a;
        std::cout << "which operation do you want to do with your LinkedList ?:" << std::endl;
        std::cout << "1-Set new element \n2-Remove an element \n3-Length of your list \n";
        std::cout << "4-Insert an element \n5-Get an element from the list \n6-Print the list\n";
        std::cin >> s;
        switch (s){
            case 1:
                int c;
                std::cout << "what is your new element ?: " << std::endl;
                std::cin >> c;
                l->set(c);
                break;
            case 2:
                l->remove();
                break;
            case 3:
                l->length();
                break;
            case 4:
                l->insert();
                break;
            case 5:
                l->get();
                break;
            case 6:
                l->print();
                break;
            default:
                printf("not a valid input!!\n");
                break;
        }
        std::cout << "Do you want to continue with your list ?: (y/n)" << std::endl;
        std::cin >> a;
        if(a == 'n'){
            q = false;
        }

    }while(q);
}