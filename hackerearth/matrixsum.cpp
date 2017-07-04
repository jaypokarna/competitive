#include <iostream>
using namespace std;

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int arr[n][m] , fin[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>arr[i][j];
            fin[i][j] = -1;
        }
    }
    fin[0][0] = arr[0][0];
    for(i=1;i<n;i++)
    {
        fin[i][0] = arr[i][0] + fin[i-1][0]; 
    }
    for(i=1;i<m;i++)
    {
        fin[0][i] = arr[0][i] + fin[0][i-1];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x ,y;
        cin>>x>>y;
        if(fin[x -1][y-1] != -1)
        {
            cout<<fin[x-1][y-1]<<endl;
            continue;
        }
        for(i=1;i<x;i++)
        {
            for(j=1;j<y;j++)
            {
                fin[i][j] = fin[i-1][j] + fin[i][j -1] - fin[i-1][j-1] + arr[i][j];
            }
        }
        cout<<fin[x -1 ][y -1 ]<<endl;
    }
    return 0;
}

