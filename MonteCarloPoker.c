#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define pips 13
#define suits 4
#define deck (pips*suits)

typedef enum suit {clubs,diamonds,hearts,spades}suit;
typedef struct card{int p;suit s;}card;
typedef struct hand{unsigned long h4,hF,h3,h2,h1,h0,total;}hand;
void shuffle(card *c)
{ 
  for(int i=0;i<deck;i++)
  {
   int rnd=rand()%(i+1); 
   card temp=c[i];
   c[i]=c[rnd];
   c[rnd]=temp;
  }
}

int intCompare(const void *p1, const void *p2)
{
    int int_a = * ( (int*) p1 );
    int int_b = * ( (int*) p2 );

    if ( int_a == int_b ) return 0;
    else if ( int_a > int_b ) return -1;
    else return 1;
}

void handstat(int A[],hand *stat)
{   
    //1.No Pair:self explained
    //2.One Pair: Whenever you match two pips of any suit---------->For example: Aâ™¦ Aâ™£
    //3.Two Pair: Two pairs---------->For example:Kâ™¥ Kâ™  5â™¥ 5â™¦
    //4.Three of a kind: match three pips---------->For example:5â™  5â™¦ 5â™£    
    //5.Full House:itâ€™s when you have three of a kind along with a pair---------->For example: Aâ™¦ Aâ™£ Aâ™¥ Jâ™¥ Jâ™ 
    //6.Four of a kind:it's when you have all four of the same card---------->For example:4â™  4â™£ 4â™¥ 4â™¦ 
    
    //checks the duplicate numbers in a[] and stores how many times num got duplicated in h[]
    int N = 7;
    int num=0;
    int h[7]={0,0,0,0,0,0,0};
    int seen[7];
    for(int i = 0; i < N; i++)
        seen[i] = 0;

    for(int i = 0; i < N; i++)
    {
        if(seen[i] == 0)
        {
            int count = 0;
            for(int j = i; j < N; j++)
            {
                if(A[j] == A[i])
                {
                    count += 1;
                    seen[j] = 1;
                }
            }
            
          h[num++]=count;
        }
    }

    //sorts h[] in a descending order
    qsort(h, 7, sizeof(int), intCompare);
    
  //evaluates hand by using the greatest two values in h[] ie:h[0],h[1] and stores them in hand stat 
    if(h[0]==4)
    {
      
      ++stat->h4;
    }
    else if (h[0]==3 && h[1]==2) 
    {
      
      ++stat->hF;
    }
    else if (h[0]==3) 
    {
      
      ++stat->h3;
    }
    else if (h[0]==2 && h[1]==2) 
    {
      
      ++stat->h2;
    }
    else if (h[0]==2) 
    {
      
      ++stat->h1;
    }
    else
    {
      
      ++stat->h0;
    }

    ++stat->total;

}



int main()
{
  //initializing the card deck
  card c[deck];
  int k=0;
  for(int i=1;i<=pips;i++)
  { 
    for(int j=1;j<=suits;j++)
    {
      c[k].p=i;
      c[k].s=j;
      ++k;
    }
  }
  
  //initializing and shuffling hand then evaluating
  hand stat={0,0,0,0,0,0,0};
  srand(time(0));  
  for(int i=0;i<20500;i++)
  {
    //initializing hand and shuffling
    int n=0;
    int h[7]={0,0,0,0,0,0,0};
    for(int j=0;j<49;j+=7)
    { 
      shuffle(c);
      for(int k=j;k<j+7;k++)
      {
        h[n]=c[k].p;
        n++;
      }
      n=0;
      //evaluating hand
      handstat(h,&stat);
    }
    
  }
    
    //printing the probablities though they wont be exactly the same
    const long double total = stat.total;
    printf("No pair probablity =  %Lf\n", stat.h0 / total);
    printf("One pair probability = %Lf\n", stat.h1 / total);
    printf("Two pair probability = %Lf\n", stat.h2 / total);
    printf("Three of a kind probablity = %Lf\n", stat.h3 / total);
    printf("Four of a kind probability = %Lf\n", stat.h4/ total);
    printf("Full house probability = %Lf\n", stat.hF / total);
  
  

}

