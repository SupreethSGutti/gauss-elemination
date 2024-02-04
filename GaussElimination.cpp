#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

bool checkzero(int** a, int row, int col)
{
    if(col==0)
    {
        return true;
    }
    if(a[row][col]==0)
    {
        checkzero(a,row,col-1);
    }
    return false;
}


int main()
{
    int n;
    cout<<"Enter the number of variables in equations"<<endl;
    cin>>n;
    int** a=new int*[n];
    for(int i=1; i<=n; i++)
    {
        a[i]=new int[n+1];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<"Enter the coefficiant of x"<<j<<" in equation "<<i<<endl;
            cin>>a[i][j];
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout<<"Enter the constant in equation "<<i<<endl;
        cin>>a[i][n+1];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n+1; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int zero=-1;
    for(int i=1; i<=n; i++)
    {
            if(checkzero(a,i,n))
            {
                zero++;
                for(int j=1; j<=n+1; j++)
                {
                    int temp=0;
                    temp=a[i][j];
                    a[i][j]=a[n-zero][j];
                    a[n-zero][j]=a[i][j];
                }
            }    
         
    }

    for(int diag=1; diag<=n; diag++)
    {
        int amul=fabs(a[diag][diag]);
        for(int bdiag=diag+1; bdiag<=n; bdiag++)
        {
            int bmul=fabs(a[bdiag][diag]);
            if(a[bdiag][diag]!=0)
            {
                if(a[diag][diag]*a[bdiag][diag]>0)
                {
                    for(int k=1; k<=n+1; k++)
                    {
                        a[bdiag][k]=amul*a[bdiag][k]-bmul*a[diag][k]; 
                    }
                }
                else
                {
                    for(int k=1; k<=n+1; k++)
                    {
                        a[bdiag][k]=amul*a[bdiag][k]+bmul*a[diag][k];
                    }
                }
                for(int i=1; i<=n; i++)
                {
                    for(int j=1; j<=n+1; j++)
                    {
                        cout<<a[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
            cout<<endl;
        }
    }

    int x[n];
    for(int i=1; i<=n; i++)
    {
        x[i]=0;
    }
    x[n]=a[n][n+1]/a[n][n];
    for(int i=n-1; i>=1; i--)
    {
        int eq=0;
        for(int j=i; j<=n; j++)
        {
            eq=eq+a[i][j]*x[j];
        }
        x[i]=a[i][n+1]/eq;
    }
    for(int i=1; i<=n; i++)
    {
        cout<<"x"<<i<<"="<<x[i]<<endl;
    }

    return 0;
}





















































































































































































































































































































































































































































































































































































































    /*
    
    */
   
   
