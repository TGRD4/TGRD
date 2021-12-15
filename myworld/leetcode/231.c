bool isPowerOfTwo(int n) 
{
    return n > 0 && (n & (n - 1)) == 0;//同理
}
bool isPowerOfTwo(int n) 
{
    return n > 0 && (n & -n) == n;//2(n)取反做与运算后仍然等于本身
}
/*2的n次方补码仅一位是1，因为其本身就是n个2相乘，所以仅有最高位会剩下一个1*/