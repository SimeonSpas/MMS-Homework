#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double x;
    double y;
}point_t;

typedef struct{
    point_t A;
    point_t B;
}rectangle_t;
typedef struct s_node{
    rectangle_t data;
    struct s_node *next;
}listNode;

void push(listNode**, rectangle_t);
rectangle_t pop(listNode**);
void clearList(listNode**);
void createRectangle(listNode**);
double area_sum(listNode*);
void filterRects(listNode**, double, double);
void print_rectangles(listNode* list);
double area(rectangle_t);

int main(){
    listNode* head = NULL;
    filterRects(&head, -10.0, 10.0);
    printf("filter: \n\n");
    clearList(&head);
    return 0;
}

void filterRects(listNode** list, double min, double max){
    if(*list == NULL){
        return;
    }
    listNode* filtered = NULL;
    listNode* current = *list;
    while(current){
        double cur_area = area(current -> data);
        if(cur_area >= min && cur_area <= max){
            push(&filtered, current -> data);
        }
        current = current -> next;
    }
    clearList(list);
    *list = filtered;
}
double area_rec (rectangle_t rec){
    double a = rec.A.x - rec.B.x;
    double b = rec.A.y - rec.B.y;
    double area = a * b;
    if (area < 0){
        area = -area;
    }
    return area;
}
void push(listNode** head, rectangle_t val){
    listNode* newnode = malloc(sizeof(listNode));
    newnode -> data = val;
    newnode -> next = *head;
}
rectangle_t pop(listNode** head){
    if(!(*head))
        exit(1);
    listNode* temp = *head;
    rectangle_t result = temp -> data;
    *head = (*head) -> next;
    free(temp);
}
void clearlist(listNode** head){
    while(*head){
        pop(head);
    }
}