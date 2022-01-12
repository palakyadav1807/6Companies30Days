#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}

class Solution
{
    public:
    void linkdelete(struct Node  *head, int m, int n)
    {
        Node* curr=head;
        while(curr!=NULL){
            int temp_m=m;
            while(curr!=NULL&&temp_m--!=1){
                curr=curr->next;
            }
            int temp_n=n;
            while(curr!=NULL&&curr->next!=NULL&&temp_n--!=0){
                Node* temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
            }
            if(curr==NULL) return;
            else curr=curr->next;
        }
    }
};

int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}