#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
 
#define INF 987654321 
 
inline unsigned numberOfSetBits(unsigned i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
 
int getAns(unsigned state[], int n)
{
   int ans = 0, temp;
   for (int i = 0; i < n; ++i) {
      temp = numberOfSetBits(state[i]);
        temp = temp > n/2 ? n - temp : temp;
        ans += temp;
    }
   return ans; 
}

inline void flipCol(unsigned state[], int colIdx, int n) 
{
   for (int i = 0; i < n; ++i)
      state[i] ^= (1<<colIdx);
}
 
int main()
{
   int N;
   unsigned coinsStates[32] = {0,}, mask = 0;
   int curAns = INF, newAns, deltaAns;
   double t = 1.0; // temperature
   double coolingRate = 0.9997, p;
   double absoluteTemperature = 0.0003;
 
   srand((unsigned)time(NULL));
 
   scanf("%d%*c", &N);
 
   for (int i = 0; i < N; ++i) {
      char coin;
      for (int j = 0; j < N; ++j) {
         scanf("%1c", &coin);
         if (coin == 'T')
            coinsStates[i] += (1<<j);
      }
      mask += 1<<i;
      scanf("%*c");
   }

   curAns = getAns(coinsStates, N);
   while(t > absoluteTemperature) {
      int idx = rand() % N, option = rand() % 2;
      if (option == 0)
         coinsStates[idx] = ~coinsStates[idx] & mask;
      else
         flipCol(coinsStates, idx, N);
      newAns =  getAns(coinsStates, N);
      deltaAns = curAns - newAns;
      if (exp((double)deltaAns / t) > (double)rand()/RAND_MAX)
         curAns = newAns;
      else
         if (option == 0)
            coinsStates[idx] = ~coinsStates[idx] & mask;
         else
            flipCol(coinsStates, idx, N);
      t *= coolingRate;
   }
   
   printf("%d", curAns);
 
   return 0;
}