#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main()
{
    int pts[CANT]={1,0,3,3,1};
    int auxPts;
    int dg[CANT]={8,10,5,13,4};
    int auxDg;
    int i, j;

    for(i=0; i<CANT-1; i++)
    {
        for(j=i+1; j<CANT ; j++)
        {
            if(pts[i]<pts[j])
            {
                auxPts = pts[i];
                pts[i] = pts[j];
                pts[j] = auxPts;

                auxDg = dg[i];
                dg[i] = dg[j];
                dg[j] = auxDg;
            }
            else
            {
                if(pts[i] == pts[j])
                {
                    if(dg[i] < dg[j])
                    {
                        auxDg = dg[i];
                        dg[i] = dg[j];
                        dg[j] = auxDg;
                    }
                }
            }
        }
    }

    for(i=0; i<CANT; i++)
    {
        printf("%d\t%d\n", pts[i], dg[i]);
    }

    return 0;
}
