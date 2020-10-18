int numJewelsInStones(char * J, char * S)
{
    int ans = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (strchr(J, S[i]) != NULL) {
            ans++;
        }
    }
    return ans;
}