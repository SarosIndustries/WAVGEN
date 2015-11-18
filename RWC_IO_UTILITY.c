// AUTHOR: MICHAEL BIANCONI
// AFFILIATION: LOS ALAMOS PUBLIC SCHOOLS
// CREATION DATE: NOVEMBER 18, 2015

/*------
TODO:
	WAVCONFIG_IO_UTILITY_GENERATE_WAVCONFIG() SHOULD GENERATE A RAW_WAVCONFIG FILE
	IF WAVCONFIG HAS .RWC EXTENSION, USE RWC_IO_UTILITY_READ_RWC()
	ELSE GENERATE .RWC FILE AND USE THAT
-------*/

void RWC_IO_UTILITY_READ( char *filename, RWC_IO_UTILITY_RWCDATA *data )
{
	FILE *file = fopen( filename, "r" );
	
	if ( file == NULL )
	{
		printf( "FILE DOES NOT EXIST\n" );
		return;
	}
	
	char character; // READ SPECIFIC CHARACTER IN FILE
	int i = 0; // ITERATES THROUGH RWCDATA
	
	while ( ( character = fgetc( file ) ) != EOF )
	{
		data->buffer[i++] = character;
	}
	
	fclose( file );
}

void RWC_IO_UTILITY_WRITE( WAVCONFIG_IO_UTILITY_WAVDATA *wavdata, char *filename )
{
	FILE *file = fopen( filename, "w+" );
	
	if ( file == NULL )
	{
		printf( "COULD NOT CREATE FILE\n" );
		return;
	}
	
	int i = 0; ITERATES THROUGH WAVDATA
	char *ftos;
	
	// CONVERT EACH WAVDATA VALUE TO A STRING, APPEND IT TO THE FILE, THEN GO TO THE NEXT LINE
	while ( i < wavdata->size )
	{
		sprintf( ftos, "%f", wavdata->frequency[i] );
		fputs( ftos, file );
		
		sprintf( ftos, "%f", wavdata->volume[i] );
		fputs( ftos, file );
		
		sprintf( ftos, "%f", wavdata->length[i] );
		fputs( ftos, file );
		
		fputs( "\n", file );
		
		i++;
	}
	
	fclose( file );
}

void RWC_IO_UTILITY_RWC_TO_WAVDATA( RWC_IO_UTILITY_RWCDATA *rwcdata, WAVCONFIG_IO_UTILITY_WAVDATA *wavdata )
{
	int i = 0; // ITERATES WAVDATA
	char *newline = "\n";
	char *buffer = strtok( rwcdata->buffer, newline );
	
	while ( buffer != NULL )
	{
		sscanf( buffer, "%f %f %f", &wavdata->frequency[i], &wavdata->volume[i], &wavdata->length[i] );
		buffer = strtok( NULL, newline );
		i++;
	}
}
