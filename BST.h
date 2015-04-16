	
/*  Igor Lopes      CS_121
    April 13, 2015      Lab#11
*/
 
#include <iostream>
 
using namespace std;
 
 
 
 
class BST
{
    private:
     
    typedef struct Node
    {
        Node* leftPtr;
        Node* rightPtr;
        string title; 
 
    } *treePtr;
 
    public:
     
    treePtr root;
    string *movie_titles;
    int number_titles;
     
    
    BST(string *data, int number)
    {
	cout << number <<endl;
        root = NULL;
        movie_titles = data;
        number_titles = number;
	INSERT_ALL_TITLES();
    }
 
    ~BST()
    {
 
    }
 
    public: void INSERT_ALL_TITLES()
    {
        for(int i = 0 ; i < number_titles; i++)
        {
            string curr_title = movie_titles[i];
            INSERT_TITLE(root, curr_title);
        }
    cout << number_titles<<endl;
    PRINT_PRE_ORDER(root);
    }
    public: void INSERT_TITLE(treePtr &t, string new_title)
    {
         
        if(t == NULL)
        {
            treePtr new_element = new Node;
            new_element -> leftPtr = NULL;
            new_element -> rightPtr = NULL;
            new_element -> title = new_title;
            t = new_element;
        }
        else
        {
            if(new_title  <= t -> title)
            {
                INSERT_TITLE(t -> leftPtr, new_title);
            }
             
            if(new_title  >= t -> title)
            {
                INSERT_TITLE(t -> rightPtr, new_title);
            }            
        }
    }
     
    public: void PRINT_PRE_ORDER(treePtr &t)
    {
        if(t != NULL)
        {
            cout << t-> title <<endl;
            PRINT_PRE_ORDER(t -> leftPtr);
            PRINT_PRE_ORDER(t -> rightPtr);
        }
    }
};
