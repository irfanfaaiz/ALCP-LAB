# include <iostream>
using namespace std;

int Greatest(int a[], int n)
{
int max;
for(int i = 0; i < n - 1; i++)
{
max = a[i];
if(a[i+1] > max)	
{
max = a[i+1];
}
	
}	
return max;		
}

void GreedyKnapsack(int w[], int p[], int M, int n)
{
int x[100];
int v[100];	
int v1[100];
	
for (int i = 1; i < n; i++)	
{
x[i] = 0; 	
v1[i] = v[i] = p[i]/w[i];	
}	

int weight = 0;	
	
while(weight < M)
{
int best = Greatest(v1,n);	

if((weight+w[best]) <= M)
{
x[best] = 1;
weight = weight + w[best];
}
else
{ 
x[best] = (M - weight) / w[best];
weight = M;
}		
	
}	
	
for(int i = 0; i < n; i++)
cout << x[i] << " ";
}

int main()
{
int profits[100] = {10,5,15,7,6,18,3 };	
int masses[100]	= {2,3,5,7,1,4,1 };
int size = 7;	
int M = 15;

GreedyKnapsack(masses, profits, M, size );	
	
return 0;	
}

