/*
in a country of zombies each city has a certain percentage of zombies. Cities are designated as
1. A city[i] is magical if city[i] and city[i+1] have no common divisor other than 1.
2. A city is good if the percentage of zombies in the city[i] is more than percentage of zombies in city[i+1]

Find a city that is perfect, where perfect means both good and magical,
if there are more than one perfect cities, output the left-most city index. Also, the minimum number of cities in a country is 2 and there will be at least one perfect city
Input Specification:
input1: An array representing the percentage of zombies in each city
input2: Number of cities in the country
Output Specification:
Return the favourable city index "i"
*/
#include<stdio.h>

int gcd(int n, int n1){  //Finding the common difference
  int gcd=0;
  for(int i=1; i<=n && i<=n1; i++){
    if(n%i==0 && n1%i==0)
      gcd=i;
  }
  return gcd;
}

int main()
{
  int n;
  int perc_city[100];
  int good, magical;
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d", &perc_city[i]);
  }
  for(int i=0; i<n-1; i++){
    //magical city check
    int common=gcd(perc_city[i], perc_city[i+1]);
    if(common==1)
      magical=1;
    else
      magical=0;

    //good city check
    if(perc_city[i]>perc_city[i+1])
      good=1;
    else
      good=0;

    printf("magical[%d]=>%d\n",i,magical);
    printf("good[%d]=>%d\n\n",i,good);
    if(good==1 && magical==1)
    {
      printf("%d",i);
      break;
    }
  }


}
