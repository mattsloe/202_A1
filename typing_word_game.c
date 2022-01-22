#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ARRAY_SIZE 9
static char* source[ARRAY_SIZE] = {"The", "quick", "brown","fox","jumps","over","the","lazy","dog"};

void shuffle(char**);
void playGame(char**);
int strcmp(char*,char*);
int main()
{
  char * hints[ARRAY_SIZE];
    //seed srand()
  srand(time(NULL));
    //shuffle array
  shuffle(hints);
    //play game
  playGame(hints);
    //exit
  return 0;
}

//Fisher-Yates Shuffle
void shuffle(char** hint)
{
  for(int i = 0; i  < ARRAY_SIZE; i++){
    //draw a random number between 0 and i
    int j = rand() % (i+1);
    if(j != i) {
      hint[i] = hint[j];
    }
    hint[j] = source[i];
    }
}


/*Play Game*/
void playGame(char** hint)
{
  printf("\nThis is a game that tests typing speed\n\nType the following words:\n");
  struct timeval starttime;
  struct timeval endtime;
  struct timeval result;
  struct timeval totalTime;
  totalTime = (struct timeval){ 0 }; 
  int isCorrect = 0;
  char inString[10];
  for(int round = 0; round < ARRAY_SIZE; round++){
    do{
      //display prompt
      printf("word #%i is %s: ",round+1,hint[round]);
      //start timer
      gettimeofday(&starttime,NULL);
      //get user input
      scanf("%s",inString);
      //stop timer
      gettimeofday(&endtime,NULL);
      //get result
      //check user input
      if(strcmp(hint[round],inString) == 0){
        isCorrect = 1;
        timersub(&endtime,&starttime,&result);
        timeradd(&totalTime,&result,&totalTime); 
      }else{
        isCorrect = 0;
      }
    }while(isCorrect == 0);
  }
  printf("You took %ld seconds and %06ld microseconds\n",totalTime.tv_sec, totalTime.tv_usec);

}

//compares the cstring parameters by ascii value
//post: return 0 if l and r are identical, otherwise, numerical result of l[i]-r[i] if they are different
int strcmp(char* l, char* r)
{
  int a = l[0];
  int b = r[0];
  int counter = 0;
  while((a != '\0') && (b != '\0')){
    if(a != b){
      return a-b;
    }
    counter++;
    a = l[counter];
    b = r[counter];
  }
  return a-b;
}
