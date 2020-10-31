
 #include <bits/stdc++.h>
 using namespace std;
 double tavg=0.0,wavg=0.0;
  void input(int a[],int b[],int n)
 {
   cout << "Enter arrival time of process"  << endl;
   for(int i=0;i<n;i++)
   {
       cin >> a[i];
   }
   cout << "Enter burst time of process"  << endl;

   for(int i=0;i<n;i++)
   {
       cin >> b[i];
   }
 }
 void waitingTime(int a[],int b[],int c[],int w[],int n)
 {
     //computing completion time;
     int rt[n];
     for(int i=0;i<n;i++)
     {
        rt[i]=b[i];
      }
      int time=0;
      bool vis[n];
      memset(vis,false,sizeof(vis));
     int mini=INT_MAX;
      int procnt=0;
      int j=-1;
     while(procnt<n)
     {
         for(int i=0;i<n;i++)
        {
            if(a[i]<=time&&rt[i]>0)
            {
               if(rt[i]<mini)
               {
                 j=i;
                 mini=rt[i];
               }
            }
        }
        mini=INT_MAX;
       if(j!=-1&&rt[j]>0)
        {
            rt[j]-=1;
            time+=1;
            if(rt[j]==0)
            {
              if(time>=a[j])
               {
                   c[j]=time;
                   w[j]=time-a[j]-b[j];
                    wavg+=w[j];
               }

                procnt++;
             //cout << c[j] << " " << w[j] << endl;
           }
       }
      else
      {
          time+=1;

      }
   }
 }
 void turnaroundTime(int b[],int w[],int t[],int n)
{
    for(int i=0;i<n;i++)
   {
     t[i]=w[i]+b[i];
     tavg+=t[i];
   }
}
void output(int c[],int w[],int t[],int n)
{
    cout << "Completion     Waiting time    " << "Turnaround Time" << endl ;
    for(int i=0;i<n;i++)
      {
          cout << c[i] << "                  "<< w[i] << "                   " << t[i] << endl;
       }

}
 int main()
 {
   cout << "Enter no of process" << endl;
   int n;
   cin >> n;
   int a[n],b[n],c[n],w[n],t[n];
   input(a,b,n);
   waitingTime(a,b,c,w,n);
   turnaroundTime(b,w,t,n);
   tavg=tavg/(double)n;
   wavg=wavg/(double)n;
   output(c,w,t,n);
   cout << "Average Waiting Time "  <<  wavg << endl;
   cout << "Average Turnaround Time "  <<  tavg << endl;


 }
