#include <stdio.h>
#include <stdlib.h>


int size;
int Boolean = 1;
int Boolean1 = 1;

struct LinkedList {
int id;
double sensorData;
struct LinkedList *next;
};

struct LinkedList **first;
struct LinkedList *el;
struct LinkedList *creatEl(int x) {
struct LinkedList *t;
  t = (struct LinkedList *)malloc(sizeof(struct LinkedList));
  t->id = x;
  t->next = NULL;
return t;
}


// 1a
void removesLast(struct LinkedList **first) {
struct LinkedList *temp = *first;
struct LinkedList *previous;
  //*head_ref = temp->next;
  // if there is any Node
if (temp->next == NULL) {

  *first = NULL;
  size = size -1;
return;
}
  // removes den första vi la in
while (temp->next != NULL) {
  previous = temp;
  temp = temp->next;
}

  previous->next = NULL;
  size = size -1;
  free(temp);
}

void insertFirst(struct LinkedList **first, struct LinkedList *el) {
  el->next = *first;
  *first = el;
  size++;
}

int isMember(struct LinkedList **first, struct LinkedList *el) {
struct LinkedList *search;
  search = *first;

while (search) {
if (search == el) {
return (1);
}
  search = search->next;
}
return 0;
}

void printList1(struct LinkedList *first) {
  
while (first != NULL) {
  printf("%d %f\n", first->id, first->sensorData);
  first = first->next;
  }
}

// Upp2
struct LinkedList *readSensor(int id) {
struct LinkedList *t;
  t = (struct LinkedList *)malloc(sizeof(struct LinkedList));

if (!t) {
return (NULL);
}
  t->id = id;
  t->sensorData = (rand() % 10000) / 10000.0;
  t->next = NULL;
return (t);
}

void removes(struct LinkedList **first, struct LinkedList *el) {
struct LinkedList *temp = *first;
struct LinkedList *element = NULL;

while (temp != NULL) {

if (temp == el) {
if (element) {
  element->next = temp->next;
} 

else {
  *first = temp->next;
 }
}
  element = temp;
  temp = temp->next;
 }
}

void sortList(struct LinkedList **first) {
struct LinkedList *temp = *first;
struct LinkedList *node = NULL;
struct LinkedList *Btemp = *first;
int count = 0;

while ((temp = *first)) {
  
for (int i = 0; i < count; i++)
  temp = temp->next;

if (!temp)
break;
  node = Btemp = temp;
  
while (node) {
if (node->sensorData > Btemp->sensorData)
  Btemp = node;
  node = node->next;
}
  removes(first, Btemp);
  insertFirst(first, Btemp);
  count++;
 }
}

void freeTheList(struct LinkedList *first) {
struct LinkedList *temp;
//struct LinkedList *link = first;

while (first != NULL) {
 temp = first;
 first = first->next;
 free(temp);
 size =0;
 }
}

struct LinkedList *Record(unsigned int index, double data){ 
 struct LinkedList *node = ( struct LinkedList*)malloc(sizeof (struct LinkedList)); 
  
if (node){
  node -> id = index;
  node -> sensorData = data;
  node -> next = NULL;
return node;
}
else { return NULL;
 }
}



struct LinkedList *Min(struct LinkedList *first) {
struct LinkedList *minimum = first;
struct LinkedList *curr = first;
 
while (curr) {
   
if (minimum->sensorData>curr->sensorData){
  minimum = curr;
  Boolean1=0;
}
  curr = curr->next;
}
  
return minimum;
}

struct LinkedList  *Max(struct LinkedList *first) {
struct LinkedList *maximum = first, *curr = first;
while (curr) {
if (maximum->sensorData<curr->sensorData){
  maximum = curr;
  Boolean=0;
}
  curr = curr->next;
}
return maximum;
}

double AtPos(struct LinkedList *first, int a){
struct LinkedList *pos = first, *curr = first;
while (pos->id != a) {
  pos = curr;
  curr = curr->next;
}
return pos->sensorData;
}

  double Avg(struct LinkedList *first) {
  double sum = 0;
  int ant =0;
  double avreg=0;
  struct LinkedList *node = first;
  
while (node) {
  sum += node->sensorData;
  node = node->next;
  ant++;
}
  avreg = sum/ant;
return avreg;
}