
int MaxEle(int a[3][2], int *r, int *c)
{
    int max = a[0][0];

    for (int i = 0; i < 6; i++)
    {
        if (a[i / 2][i % 2] >= max)
        {
            max = a[i / 2][i % 2];
            *r = i / 2 + 1;
            *c = i % 2 + 1;
        }
    }

    return max;
}
