#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main( void )
{
	int *answer;
	int guess;

	srand( time( NULL ) );
	while( 1 )
	{
		answer = ( int * ) malloc( sizeof( int ) );
		*answer = ( int )( rand() );

		guess = -1; 

		while( guess != *answer )
		{
			printf( "Input your guess: " );
			scanf( "%d", &guess );

			if( guess < *answer )
				printf( "  Too small!!\n");
			else if( guess > *answer )
				printf( "  Too big!!\n" );
			else
				printf( "Correct! Generating new number.\n");
		}

		free( answer );
	}

	return 0;
}
