/*
一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
'A' -> 1
'B' -> 2
...
'Z' -> 26
要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
"AAJF" ，将消息分组为 (1 1 10 6)
"KJF" ，将消息分组为 (11 10 6)
注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。
给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。
题目数据保证答案肯定是一个 32 位 的整数。
*/
int numDecodings(char* s) {
    int len = strlen(s);
    int f[len + 1];
    memset(f, 0, sizeof(f));//设置每一位为0
    f[0] = 1;//起码一种解码方法
    for (int i = 1; i <= len; i++) {

//若下列只有一个满足那么解码方法总数不变只是把总解码方法数移动到了i位上

        if (s[i - 1] != '0') //单位上不为0就单算为一种解码方法
            f[i] += f[i - 1];
        if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) 
        //单位上为0但是前一位不连续为0，并且这个二位数不超过26的，记为二位数的一种解码方法
            f[i] += f[i - 2];//如果同时满足个位和十位分别都是一位解码方法时f[i]比原来多加一
    }
    return f[len];//将解码方法总数记录在最后一位上
}
