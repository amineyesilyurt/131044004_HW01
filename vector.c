
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vectorLine(Vector *vector) {
  int i;
  /* initialize size and capacity */
  vector->size = 0;
  vector->capacity = VECTOR_INITIAL_CAPACITY;

  /* allocate memory for vector->data */
  vector->data =(char**)malloc(sizeof(char*) * vector->capacity);
  for(i=0;i<=VECTOR_INITIAL_CAPACITY;++i)
  vector->data[i]=(char*)malloc(sizeof(char) * 200);
}

void vectorAppend(Vector *vector, char* line) {
  /* make sure there's room to expand into*/
  vectorDoubleCapacityFull(vector);
    vector->size++;
  /* append the line and increment vector->size */
  strcpy(vector->data[vector->size] ,line);
}

char* vectorGet(Vector *vector, int index) {
  if (index > vector->size || index < 0) {
   /* printf("Index %d out of bounds for vector of size %d\n", index, vector->size);*/
    exit(1);
  }
  return vector->data[index];
}


void vectorDoubleCapacityFull(Vector *vector) {
  if (vector->size >= vector->capacity) {
    /* double vector->capacity and resize the allocated memory accordingly */
    vector->capacity *= 2;
    vector->data =(char **) realloc(vector->data, sizeof(char*) * vector->capacity);
  }
}

void vectorFree(Vector *vector) {
  free(vector->data);
}
