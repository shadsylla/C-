

#include <stdio.h> 
#include <file.h>
 



struct node 
{ 
  int key_value; 
  struct node *left; 
  struct node *right; 
 
}; 

/* Pointers are necessary to allow the arbitrary creation of nodes in the tree struct */ 

/* important operations in binary trees are 
   + inserting elements
   + removing elements 
   + searching for elements 
   + deleting the tree 
   */ 

   /* I have to always keep track for the root node, because it will give us acess to the others */ 

   /* this func will delete all binary tree. It will start from left bottom than to its sister, than to
     bottom right-left, then to its sister. then to the top right. then to The root node.*/ 



  void destroy_tree(struct node *leaf)
  {
    if ( leaf != 0 )
    { 
      destroy_tree(leaf->left);
      destroy_tree(leaf->right); 
      free( leaf ); 

    }
  }   


  /* this function is to create a new binary tree if necessary. I will use pointers to pointers 
     it is the way to control the non-existing Tree, since the root pointing to NULL. 
     By taking pointer to pointer it is possible to allocate memory if the root pointer is NULL. 
  */ 
   insert(int key, struct node **leaf)
   {
   	 if( *leaf == 0 )
   	 {
   	 	 *leaf = (struct node*) malloc(sizeof(struct node) ); 
   	 	 (*leaf)->key_value = key; 

   	 	 /* initialize hte children to null*/ 
   	 	 (*leaf)->left = 0; 
   	 	 (*leaf)->right = 0;
   	 	 }
   	 	 else if (key < (*leaf)->key_value )
   	 	 {
   	 	 	insert( key, &(*leaf)->left ); 

   	 	 }  
   	 	 else if ( key > (*leaf)-> key_value )
   	 	 {
   	 	 	insert( key, (*leaf)-> right ); 
   	 	 }	
   	 }
   /* The search function, moves recursively moves down the tree until either reaches a node 
   with a key value equal to the value it is searching for, or until the function reaches 
    an unutilized node, and that means that the value  being searched is not stored in this binary tree. 
     Then it returns a pointer to the node to the previous instance of the function whqich called it. */ 

     struct node *search(int key, struct node *leaf)
     {
     	if ( leaf != 0 )
     	{
     		if(key==leaf-> key-value)
     		{
     			return leaf; 
     		}
     		else if (key, leaf->key_value)
     		{
     			return search(key, leaf->left );
     		}
     		else
     		{
     			return search(key, leaf->right);
     		}  
     	}	
     } 



     int main()
     {

       insert(); 
       *search();
       destroy_tree(); 


     	return 0; 
     }
