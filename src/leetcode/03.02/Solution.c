#define MIN(x, y) ((x) < (y)) ? (x) : (y)
typedef struct {
    int val;
    int min;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} MinStack;

/** initialize your data structure here. */


MinStack* minStackCreate()
{
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->top = NULL;
    return obj;
}

void minStackPush(MinStack* obj, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = x;
    newNode->next = obj->top;
    if (newNode->next == NULL) {
        newNode->min = x;
    } else {
        newNode->min = MIN(x, minStackGetMin(obj));
    }
    obj->top = newNode;
}

void minStackPop(MinStack* obj)
{
    if (obj->top == NULL) {
        return;
    }
    Node *newTop = (obj->top)->next;
    free(obj->top);
    obj->top = newTop;
}

int minStackTop(MinStack* obj)
{
    return obj->top->val;
}

int minStackGetMin(MinStack* obj)
{
    return obj->top->min;
}

void minStackFree(MinStack* obj)
{
    while(obj->top) {
        minStackPop(obj);
    }
    free(obj);
    obj = NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/