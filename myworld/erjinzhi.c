#include <stdio.h>
#include <string.h>
#include <math.h>
#ifdef	_STDIO_H
#define	wLong	32
#else
#define	wLong	16
#endif
char *_itoa(int val0, char *buf, int d)
{
    if(d>1)
    {
        int i=0, j;
        unsigned val=d==2? val0:(val0>-1? val0:-val0);
        char tmp[wLong+1];
        while(val)
        {
            j=val%d;	
            tmp[i++]=j+(j<10? '0' :'a'-10); 
            val/=d;
        }    	
        buf[i--]=0;
        for(j=0; j<=i; j++)
            buf[j]=tmp[i-j];
        if(val0<0 && d>2)
        {
            while(i>-1)buf[1 + i-- ]=buf[i];
            buf[0]='-';
        }
    }
    else buf[0]=0;
    return buf;
}

int main()
{
    char buf[wLong+1];
    int val, d;
    puts("Input 0 0 to exit");
    while(1)
    {
        printf("Input your intVal & style:"); 
        scanf("%d %d", &val, &d);
        if(val==0)break;
        _itoa(val, buf, d);
        puts(buf);
    }
}