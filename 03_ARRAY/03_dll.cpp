#include<bits/stdc++.h>
using namespace std;
Node* removeKvalue(Node* head, int key){
    if(head == NULL) return NULL;

    Node* temp = head;

    while (temp != NULL){
        if(temp->data == key){
            Node* todelete = temp;
            temp = temp->next;

            // if node is head
            if(todelete->back == NULL){
                head = todelete->next;
                if(head != NULL){
                    head->back = NULL;
                }
            }
            else{
                todelete->back->next = todelete->next;
                if(todelete->next != NULL){
                    todelete->next->back = todelete->back;
                }
            }

            delete todelete;
        }
        else{
            temp = temp->next;
        }
    }

    return head;
}