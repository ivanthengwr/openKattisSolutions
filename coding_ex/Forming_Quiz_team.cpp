/***
 * Let (x,y) be the integer corrdinates of a student's house on a 2D plane. There are 2N students and we want to pair them into N groups. Let di be the ditance
 * between the houses of 2 students in group i. Form N groups such that cost = Σ i = 1 to N di is minimized. Output the minimum cost as a floating point number with
 * 2 digits precision in one line. Constraints: 1<= N <= 8 and 0 <= x,y <= 1000.
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>

int maxWord, n, x[20], y[20];
double dist[20][20], dp[1<<16];

double rec(int word) 
{
    if(word==maxWord) {
        return 0;
    } else if (dp[word] !=-1) {
        return dp[word];
    } else {
        int i,j;
        double d=1<<30;
        for( i =0; i<2*n; i++) { //check if player at position i is available
            if(!(word&(1<<i))) {
                for(j=i+1; j<2*n; j++) {
                    if(!word&(1 <<j)) {
                        d = std::min(d, dist[j][j]+rec(word|(1<<i)|(i<<j)));
                    }
                }
            } 
        }
        return dp[word]=d;
    }
}

double dis(int i, int j) {   
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])); 
}

int main()
{
    //freopen("in.txt", "r", stdin); //To input test cases
    char name[20];
    int i,j,kase=1;
    scanf("%d",&n);
    while(n)
    {
        maxWord = (1<<(2*n))-1; // 2^no._of_players - 1
        for(i=0;i<2*n;i++)
            scanf("%s %d %d",name,x+i,y+i); //input
        for(i=0;i<2*n;i++)
            for(j=i+1;j<2*n;j++)
                dist[i][j]=dist[j][i]=dis(i,j); //calculate distances of probable pairs
        for(i=0;i<=maxWord;i++)
            dp[i]=-1;   //initialize
        printf("Case %d: %.2lf\n",kase++,rec(0));   //call function rec with initial word 0
        scanf("%d",&n);
    }
    return 0;
}
