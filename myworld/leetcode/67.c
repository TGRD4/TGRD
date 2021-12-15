char * addBinary(char * a, char * b)
{
    int r = 0;	
	int length = (strlen(a)>strlen(b)? strlen(a)+2:strlen(b)+2);//可能需要进位(strlen+1+1)
	char* result = (char*)malloc(sizeof(char)*length);		
	result[length-1] = '\0';
	for(int i = strlen(a)-1,j = strlen(b)-1,k = length -2; (i >=0||j >= 0); i--,j--,k--)
	{
        int sum=r;
		sum += (i >= 0? a[i]-'0':0);
		sum += (j >= 0? b[j]-'0':0);
		r = sum /2;
		result[k] = '0'+ sum % 2;
	}
	if(r == 0)
		return result+1;    
	result[0] = '1';
	return result;
}
