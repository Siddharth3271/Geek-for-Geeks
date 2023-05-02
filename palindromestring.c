int isPalindrome(char S[])
{
    int n=strlen(S);
    char S1[1000000];
    int j=0;
    for(int i=n-1;i>=0;i--)
    {
        S1[j]=S[i];
        j++;
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(S[i]==S1[i])
        {
            c++;
        }
    }
    if(c==n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
