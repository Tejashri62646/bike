#include<iostream>
using namespace std;

#define INF 999

int main()
{
	int cost[4][4] , dist[4][4] , nexthop[4][4];
	int n;
	
	cout<<"Enter Number of Routers : ";
	cin>>n;
	
	cout<<"Enter Cost Matrix : ";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>cost[i][j];
			
			if(cost[i][j] == -1){
				cost[i][j] = INF;
			}
			
			dist[i][j] = cost[i][j];
			
			if(i==j){
				nexthop[i][j] = i;
			}
			else if(cost[i][j] != INF){
				nexthop[i][j] = j;
			}
			else{
				nexthop[i][j] = -1;
			}
		}
	}
	
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dist[i][k] != INF && dist[k][j] != INF)
				{
					if(dist[i][k] + dist[k][j] < dist[i][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						nexthop[i][j] = nexthop[i][k];
					}
				}
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<"\nRouter : "<<i+1<<endl;
		cout<<"Destination\tDistance\tNextHop\n";
		for(int j=0;j<n;j++)
		{
			cout<<j+1<<"\t\t";
			if(dist[i][j] == INF)
			{
				cout<<"INF\t\t-\n";
			}
			else{
				cout<<dist[i][j]<<"\t\t"<<nexthop[i][j]+1<<endl;
			}
		}
	}
	
	return 0;
}
