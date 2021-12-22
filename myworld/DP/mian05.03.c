#define Max( a , b ) ( ( ( a ) > ( b ) ) * ( a ) + ( ( a ) <= ( b ) ) * ( b ) )
int reverseBits( int num ){
    int max = 0;
    int curr = 0, pre = 0;
    for( int i = 0 ; i < 32 ; i++ ) {
        if( 1 & num ) 
            curr++;
        else {
            max = Max( max , curr + pre + 1 );
            pre = curr;
            curr = 0;
        }
        num >>= 1;
    }
    max = Max( max , curr + pre + 1 );
    ( max > 32 ) && ( max = 32 );
    return max;
}