#define VECTOR_INITIAL_CAPACITY 1000

typedef struct {
  int size;      /*slots used so far*/
  int capacity;  /* total available slots */
  char **data;     /* array of integers we're storing*/
} Vector;

void vectorLine(Vector *vector);

void vectorAppend(Vector *vector, char* line);

char* vectorGet(Vector *vector, int index);

void vectorDoubleCapacityFull(Vector *vector);

void vectorFree(Vector *vector);
