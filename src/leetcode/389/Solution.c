#define ALPHANUM 26
char findTheDifference(char * s, char * t){
    int freq[ALPHANUM];
    memset(freq, 0, ALPHANUM * sizeof(int));
    for (int i = 0; i < strlen(t); i++) {
        freq[t[i] - 'a']++;
    }
    for (int i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']--;
    }
    for (int i = 0; i < ALPHANUM; i++) {
        if (freq[i]) {
            return i + 'a';
        }
    }
    return 0;
}