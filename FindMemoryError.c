    /*
    Igor Lopes             March 11, 2015
    
    Lab#7
    
    CS328 - Section#3 - University of Idaho - Spring 2015
    
    Author: Bruce M. Bolden  - University of Idaho
    
    memerror.c -- try to find (and fix!) all the memory-related errors
    in this program that
    Takes a string from the command line.
    Makes a linked-list out of it in reverse order.
    Traverse it to construct a string in reverse.
    Clean up (release memory).
    */
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h> // It's needed to work with strings
    
    
    typedef struct st_CharNode {
    char theChar;
    struct st_CharNode *next;
    } CharNode;
    
    
    void reverseIt( char *stringbuffer );
    
    int main( int argc, char *argv[] ){
    char *stringBuffer; //Dynamic array that will store the string supplied.
    
    //Check number of user supplied arguments.
    if( argc != 2 ){
    fprintf( stderr, "usage: %s string.  This reverses the string "
         "given on the command line\n" );
    exit( -1 );
    }
    
    // Copy the argument so we can make changes to it
    stringBuffer = malloc( strlen(argv[1]) + 1); // It's to add 1 due to the /0 element. The string is located in the [1] position
    
    strcpy( stringBuffer,argv[1] ); //It has to be inverted in order to successfully copy the elements.
    
    // Reverse the string
    reverseIt( stringBuffer );
    
    // Print the reversed string
    //  printf( "the reversed string is '%s'\n", stringBuffer ); //No longer needed
    
    return 0;
    }
    
    void reverseIt( char *stringbuffer ){
    CharNode *head, *node;
    int scan, stop; //It has to be Integers
    
    // initialize local vars
    head = node = NULL;
    
    // find the start and end of the string so we can walk it
    scan = 0; //It has to be zero
    stop = strlen(stringbuffer) + 1; // Set the stop point
    
    // walk the string
    while (scan < stop -1) {
    if (head == NULL){
    char aux = stringbuffer[scan]; //Will help get the character separetely
    head = malloc( sizeof(CharNode*) ); //Malloc for header
    head->theChar = aux; // Store the character
    printf("%c",aux);  // Print character
    head->next = NULL; //Set next of the header as null
    }else{
    node = malloc( sizeof(CharNode*) ); //Malloc for node
    char aux = stringbuffer[scan]; // Gets character
    node->theChar = aux; // Store the character
    printf("%c",aux); //Print character
    node->next = head; //Set node's next as header
    head = node; //Update header
    }
    scan++;
    }
    
    printf("\n");
    
    CharNode* head_copy = head; //Save header for later
    // Re-point to the buffer so we can drop the characters
    scan = 0; //Useless
    
    //  Traverse the nodes and add them to the string
    
    while( head != NULL ){
    char aux =  head->theChar; //Get character from header (Last element)
    printf("%c",aux);
    // free( head ); // It's optional.
    node = head->next; // Move to th next one.
    head = node; //Update head to move foward.
    //   scan++;  //Useless
    }
    
    // Shows the inverted list:
    while( head != NULL ){
    char aux = head_copy ->theChar; // Gets the first element
    printf("%c",aux); // Shows the content
    node = head_copy ->next; //Update to foward
    head_copy = node; // Updates node
    }
    printf("\n");
    // Release head
    free( head );
    }
