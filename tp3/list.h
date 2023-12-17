typedef struct element {
    int data;
    struct element* next;
} Element;

typedef struct integerList{
    Element *first;
    Element *last;
    Element *current;
    int length;
} IntegerList;

void initList(IntegerList* list);
void insertStart(IntegerList* list, int data);
void insertEnd(IntegerList* list, int data);
void deleteStart( IntegerList* list);
void deleteEnd( IntegerList* list);
void deleteElement(IntegerList* list, int data);
void printList(IntegerList *list);
void findElement(IntegerList *list, int toFind);
void freeList(IntegerList* list);
