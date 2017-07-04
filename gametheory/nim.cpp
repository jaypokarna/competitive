#include <iostream>
// In this game , the person who picks up
// the last one wins
// be careful about this
// also the assumption that
// both of them play optimally

using namespace std;


int main() {

    int t,n;
    cin>>t;
        while(t--)
        {
        cin>>n;
        int i,arr[n];
        for(i=0;i<n;i++)
            {
            cin>>arr[i];
        }
        int x =0;
        for(i=0;i<n;i++)
        {
          x = x^arr[i];
        }
        if(x > 0)
        {
          cout<<"First"<<endl;
        }
        else
        {
          cout<<"Second"<<endl;
        }
      }
    return 0;
}
