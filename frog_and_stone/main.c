#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int isStone(int stone[], int size, int index)
{
    for(int i = 0; i< size; i++)
    {
        if(stone[i] == (index +1))
            return 1;
    }
    return 0;
}


int main()
{
    int *dp = NULL;
    int L;
    int s, t, m;
    int stone[100] = {0};
    int log_length = 0;
    int min = 0;
    if(NULL == freopen("frog_and_stone/input.txt", "r", stdin))
    {
        return -1;
    }
    while (EOF != scanf("%d", &L))
    {
        scanf("%d %d %d", &s, &t, &m);
        memset(stone, 0, sizeof(stone));
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &stone[i]);
        }
        log_length = t - s + 1;
        dp = (int *)malloc(sizeof(int) * log_length);
        for (int i = 0; i < log_length - 1; i++)
        {
            dp[i] = -1;
        }
        dp[log_length - 1] = 0;
        for (int i = t; i < L + t; i++)
        {
            min = 0;
            for (int j = 0; j < log_length; j++)
            {

                if (dp[j] == -1)
                {//not reachable, ignore
                    continue; 
                }
                else if(min > dp[j])
                {
                    min = dp[j];
                }
                for(int k= 0; k<log_length - 1;k++)
                {// move the log for next dp
                    dp[k] = dp[k+1];
                }
                dp[log_length-1] = min + isStone(stone, m, i);
            }// for j
        }// for i
        min = 0;
        for(int i =0; i<log_length; i++)
        {
            if(dp[i] < min)
                min = dp[i];
        }
        printf("%d", min);
    }

    return 0;
}