#define SPECIES 2
#define CAT 0
#define DOG 1

typedef struct Node {
    int order;
    int id;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *pseudohead;
    struct Node *tail;
} Queue;

typedef struct {
    int cnt;
    struct Queue *animal;
} AnimalShelf;

void QueueInit(struct Queue *q)
{
    q->pseudohead = (struct Node*)malloc(sizeof(Node));
    (q->pseudohead)->next = NULL;
    q->tail = q->pseudohead;
}

void QueuePush(Queue *q, struct Node *node)
{
    (q->tail)->next = node;
    q->tail = node;
}

bool QueueEmpty(Queue *q)
{
    return q->pseudohead->next == NULL;
}

bool QueuePop(Queue *q)
{
    if (QueueEmpty(q)) {
        return false;
    }
    Node *popnode = q->pseudohead->next;
    q->pseudohead->next = popnode->next;
    free(popnode);
    popnode = NULL;
    if (q->pseudohead->next == NULL) {
        q->tail = q->pseudohead;
    }
    return true;
}

int QueuePeekId(Queue *q)
{
    if (QueueEmpty(q)) {
        return -1;
    }
    return (q->pseudohead->next)->id;
}

int QueuePeekOrder(Queue *q)
{
    if (QueueEmpty(q)) {
        return -1;
    }
    return q->pseudohead->next->order;
}

AnimalShelf* animalShelfCreate()
{
    AnimalShelf *obj = (AnimalShelf *)malloc(sizeof(AnimalShelf));
    obj->animal = (Queue *)malloc(sizeof(Queue) * SPECIES);
    obj->cnt = 0;
    for (int i = 0; i < SPECIES; i++) {
        QueueInit((obj->animal) + i);
    }
    return obj;
}

void animalShelfEnqueue(AnimalShelf* obj, int* animal, int animalSize)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->id = animal[0];
    newnode->next = NULL;
    newnode->order = obj->cnt++;
    QueuePush(obj->animal + animal[1], newnode);
}

int* animalShelfDequeueAny(AnimalShelf* obj, int* retSize)
{
    *retSize = 2;
    int *ans = (int *)malloc(sizeof(int) * 2);
    ans[0] = -1;
    ans[1]= -1;
    int minorder = INT_MAX;
    for (int i = 0; i < SPECIES; i++) {
        if (QueueEmpty(obj->animal + i)) {
            continue;
        }
        int noworder = QueuePeekOrder(obj->animal + i);
        if (noworder < minorder) {
            minorder = noworder;
            ans[0] = QueuePeekId(obj->animal + i);
            ans[1] = i;
        }
    }
    if (ans[0] != -1) {
        QueuePop(obj->animal + ans[1]);
    }
    return ans;
}

int* animalShelfDequeueOne(AnimalShelf *obj, int *retSize, int species)
{
    *retSize = 2;
    int *ans = (int *)malloc(sizeof(int) * 2);
    ans[0] = -1;
    ans[1]= -1;
    if (QueueEmpty(obj->animal + species)) {
        return ans;
    }
    ans[0] = QueuePeekId(obj->animal + species);
    ans[1] = species;
    QueuePop(obj->animal + species);
    return ans;
}

int* animalShelfDequeueDog(AnimalShelf* obj, int* retSize)
{
    return animalShelfDequeueOne(obj, retSize, DOG);
}

int* animalShelfDequeueCat(AnimalShelf* obj, int* retSize)
{
    return animalShelfDequeueOne(obj, retSize, CAT);
}

void animalShelfFree(AnimalShelf* obj)
{
    for (int i = 0; i < SPECIES; i++) {
        while(!QueueEmpty(obj->animal + i)) {
            QueuePop(obj->animal + i);
        }
        free((obj->animal[i]).pseudohead);
    }
    free(obj->animal);
    free(obj);
}

/**
 * Your AnimalShelf struct will be instantiated and called as such:
 * AnimalShelf* obj = animalShelfCreate();
 * animalShelfEnqueue(obj, animal, animalSize);
 
 * int* param_2 = animalShelfDequeueAny(obj, retSize);
 
 * int* param_3 = animalShelfDequeueDog(obj, retSize);
 
 * int* param_4 = animalShelfDequeueCat(obj, retSize);
 
 * animalShelfFree(obj);
*/