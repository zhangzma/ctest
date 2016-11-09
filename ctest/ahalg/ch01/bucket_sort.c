/*
 * copyright (c) www.eva-tec.cn
 * bucket_sort.c
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const int SCORE_MAX = 10;
    int scores[SCORE_MAX+1];
    /* init the scores[] */
    for (int i = 0; i < SCORE_MAX+1; i++) {
        scores[i] = 0;
    }

    /* input the score of the student. */
    printf("Please input the scores (ended with -1): ");
    int sc = 0;
    do
    {
        scanf("%d", &sc);
        if (sc >=0 && sc < SCORE_MAX+1)
        {
            scores[sc] += 1;
        }
    } while (sc != -1);

    /* output the scores. */
    for (int i = 0; i < SCORE_MAX+1; i++) {
        for (int cnt = 0; cnt < scores[i]; cnt++) {
            printf("%d ", i);
        }
    }

    return 0;
}

