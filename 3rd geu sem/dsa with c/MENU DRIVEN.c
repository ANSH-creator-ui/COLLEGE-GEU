#include<stdio.h>
#include<stdlib.h> //have to insert and delete using position ...by value already done

struct node{
    int data;
    struct node* next;
};

struct node* createnode(int val){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = val;
    new->next = NULL;
    return new;
}
struct node* insertAtBeginning(struct node*head,int val){
    struct node* new = createnode(val);
    if(head==NULL){
        head = new;
    } 
    else{
        new->next = head;
        head = new;
    }
    return new;
}
void print(struct node* head){
    struct node* temp = head;
    if(temp==NULL){
        printf("empty list");
        return;
    }
    
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

struct node* insertAtEnd(struct node* head,int val){
    struct node* new = createnode(val);
    struct node* temp = head;

    if(head==NULL){
        head=new;
        return head;
    }

    while(temp->next){
        temp = temp->next;
    }
    temp->next = new;
    return head;

}


struct node* insertAfterK(struct node*head,int target,int val){
   struct node*new = createnode(val);
    struct node* temp = head;

    while((temp->data)!=target){
        temp = temp->next;
    }
    new->next=temp->next;
    temp->next=new;
    return head;
}

struct node* insertBefore(struct node* head,int target,int val){
    struct node*new = createnode(val);
    struct node* temp = head;
    while((temp->next->data)!= target){
    temp=temp->next;
    }
    new->next=temp->next;
    temp->next = new;
    return head;
    }

    struct node* deleteAtEnd(struct node*head){
        struct node*temp = head;
        if(temp==NULL){
            printf("empty list");
        }
        while(temp->next->next!=NULL){
            temp=temp->next;
        }

        free(temp->next->next);
        temp->next=NULL;
        return head;

    }

    struct node* deleteAtBegin(struct node* head){
        struct node* temp = head;
        if(temp==NULL){
            printf("empty list");
        }
        head=temp->next;
        free(temp);
        return head;
    
        }
    
        struct node* deleteK(struct node* head,int val){
            struct node* temp = head;
            while(temp->next->data!=val){    //error in this section 
                temp=temp->next;
            }
            
            free(temp->next);
            temp->next=NULL;
            return head;
        }
int main() {
    struct node* head = NULL;
    int choice, value, target;
    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Value\n");
        printf("4. Insert Before Value\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete by Value\n");
        printf("8. Print List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter target value after which to insert: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAfterK(head, target, value);
                break;
            case 4:
                printf("Enter target value before which to insert: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertBefore(head, target, value);
                break;
            case 5:
                head = deleteAtBegin(head);
                break;
            case 6:
                head = deleteAtEnd(head);
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteK(head, value);
                break;
             case 8:
                print(head);
                break;
            case 9:
                printf("Exiting...\n");
                //freeList(head);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
