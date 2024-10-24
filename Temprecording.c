int avg;
int max;
int min;
void alarmsignal();
void  alarmLimit();
int b =0;
unsigned int arrMax[7],arrAvg[7];
unsigned int arrMin[7] ={100,100,100,100,100,100,100};
int dayMax=0;
unsigned int date[7];
unsigned int date1[7];
struct LinkedList *list = NULL;

void tempRecord(){
while (temp<=0){
  read_Temp();
}
 
if(ss==59){
  read_Temp();
  alarmLimit();
  int t = temp;
  struct LinkedList *newNode = Record(hh*60+mm, t);
  
if (!newNode) {
  //removesLast(&newNode);
  removesLast(&list);
}

  insertFirst(&list,newNode);
  dayMax = ((day-1)%7);
  
 if(list!=NULL){
  struct LinkedList *temp = Min(list); 
       
if(temp->sensorData < arrMin[dayMax]){
  arrMin[dayMax] = temp->sensorData;
  date1[dayMax] = temp->id;
}
  temp = Max(list);

if(temp->sensorData > arrMax[dayMax]){
  arrMax[dayMax] = temp->sensorData;
  date[dayMax] = temp->id;
}
    
  arrAvg[dayMax] = Avg(list);
  freeTheList(list);
  list = NULL;
  }
 }
}
