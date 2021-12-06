#include<stdio.h>
void Input(int n,int m,double s[n][m]);
double zu_Aver(int m,const double s[m]);
double Aver(int n,int m,int s[n][m]);
double Max(int n,int m,const double s[n][m]);
void Show(int n,int m,int s[n][m]);
int main()
{
    int n=3,m=5;
    double s[n][m];
    Input(n,m,s);
    Show(n,m,s);
    return 0;
}

void Input(int n,int m,double s[n][m])
{
    printf("please enter the array.\n");
    for(int i=0;i<n;i++)
    {
        printf("enter five double number by enter:\n");
        for(int j=0;j<m;j++)
            scanf("%lf",&s[i][j]);
    }
}

double zu_Aver(int m,const double s[m])
{
    double sum=0;
    for(int i=0;i<m;i++)
        sum+=s[i];
    return (sum/m);

}

double Aver(int n,int m,int s[n][m])
{
    double sum=0;
    for(int i=0;i<n;i++)    
        sum+=zu_Aver(m,s[i]);
    return (sum/n);
}

double Max(int n,int m,const double s[n][m])
{
    double max=s[0][0];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(max<s[i][j])
                max=s[i][j];
    return max;
}

void Show(int n,int m,int s[n][m])
{
    printf("the result is:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            printf("%5g ",s[i][j]);
    for(int i=0;i<n;i++)
        printf("\nthe zu average is %g\n",zu_Aver(m,s[i]));
    printf("\nthe average is %g\n",Aver(n,m,s));
    printf("\nthe max is %g\n",Max(n,m,s));
}
