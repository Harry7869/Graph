  #include <iostream>
  #include <vector>
using namespace std;
int cd(int n)
{
    int c=0;
    while(n)
    {
        int d=n%10;
        if(d==3)
            c++;
        n/=10;
    }
    return c;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int k=0;
        while(k==0)
        {
            n+=1;
            int z=cd(n);
            if(z>=3)
            {
            cout << n << endl;
            break;
        }
    }
}
}
