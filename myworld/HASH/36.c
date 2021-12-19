bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    /*配置一个空的哈希表,一共三层，一层用来检测行，一层用来检测列，一层用来检测块*/
    int hashTable[3][9][9] = {0};
    int block ,i ,j ,num;
    for(i = 0;i < 9;i++){
        for(j = 0;j < 9;j++){
            if(board[i][j] == '.')
                continue;
            else{
                /*为了匹配hash的数组坐标为0-8，数独里的字符为1-9，此处-'1'(char)*/
                num = (int)(board[i][j] - '1');
                /*判断是在哪儿一块*/
                block = (i/3*3)+(j/3);
            /*拿前三块来看，0,1,2列属于第一块，3,4,5属于第二块，6,7,8属于第三块，所以用(j/3)表示块在哪一列，
            但还有下面六块，所以再加上(i/3*3)表示块在哪一行，每增加一行列相当于增加三列块，所以要*3*/

               if(hashTable[0][i][num] == 1 || hashTable[1][j][num] == 1 || hashTable[2][block][num] == 1)
                    return false;
                /*如果上述数字没有在行列以及块中出现过，则标记为1，意思出现了1次*/
                hashTable[0][i][num] = 1;//行
                hashTable[1][j][num] = 1;//列
                hashTable[2][block][num] = 1;//块
            }         
        }
    }
    return true;
}
