bool isSubsequence(char* s, char* t) {
    int n = strlen(s), m = strlen(t);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] == t[j]) //可以不连续（只要存在就可以）
            i++;
        j++;
    }
    return i == n;
}
