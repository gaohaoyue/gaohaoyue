#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>
SparseNode * mergehelper(SparseNode * clone1, SparseNode * array_2);

/* Create a single instance of a sparse array node with a specific
 * index and value. This is a constructor function that allocates
 * memory, copies the integer values, and sets the subtree pointers to
 * NULL.
 */

SparseNode *SparseNode_create(int index, int value)
{
  SparseNode * one_node = NULL;
  one_node = malloc(sizeof(SparseNode));
  one_node -> index = index;
  one_node -> value = value;
  one_node -> left =  NULL;
  one_node -> right = NULL;
  return one_node;
  
}

/* Add a particular value into a sparse array on a particular index.
 * The sparse array uses the index as a key in a binary search tree.
 * It returns the new sparse array root
 * as its return value. If the index does not exist, create it. 
 * If the index exists, REPLACE the value to the new one. Use the index to
 * determine whether to go left or right in the tree (smaller index
 * values than the current one go left, larger ones go right).
 */

SparseNode * SparseArray_add ( SparseNode * array, int index, int value )
{
  if(value == 0)
    {
      return array;
    }
  if( array == NULL)
    {
      return SparseNode_create(index,value);
    }

  if(index == (array -> index))
    {
      array->value = value;
      return array;
      // array->value = value;
    }
  if( index < (array->index))
    {
      if(array->left == NULL)
	{
	  array->left = SparseNode_create(index,value);
	}
      else
	{
	array -> left = SparseArray_add(array -> left , index, value); 
	}
    } 
  else
    {
      if(array->right == NULL)
	{
	  array->right = SparseNode_create(index,value);
	}
      else
	{
	  array -> right = SparseArray_add(array -> right, index, value);
	}
    }
  
  return array ;
}

/* Build a sparse array from given indices and values with specific length.
 * This function takes an array of indices, an array of values, and 
 * the length as inputs.
 * It returns a sparse array. 
 * You need to insert tree nodes in order:
 * the first sparse array node contains indices[0] and values[0])
 */

SparseNode *SparseArray_build(int * indicies, int * values, int length)
{
  SparseNode * array = NULL;
  // if(length > 0)
    //    array = SparseNode_create(indicies[0], values[0]);
  int ind;
  for (ind=0; ind<length; ind++) 
    {
      array = SparseArray_add(array,indicies[ind],values[ind]);
    }
  return array;
  /*
 int ind;
  for (ind=0; ind<length; ind++) //if using second way, ind should be 0 instead of 1
    {
      SparseNode* ret = SparseArray_add(array,indicies[ind],values[ind]);
      if(array == NULL)
	array = ret; //This is the second way of doing it
    }
    return array;
 //
  int i;
  array = SparseNode_create(indicies[0],values[0]);
  for(i=1;i<length;i++)
    {
      SparseArray_add(array,indicies[i],values[i]);
    }
    return array;*/
}

/* Destroy an entire sparse array. 
 * traversing the binary tree in postorder. Use the
 * SparseNode_destroy () function to destroy each node by itself.
 */
void SparseArray_destroy ( SparseNode * array )
{
  if (array == NULL)
    {
      return;
    }
  if(array->left!= NULL)
    {
      SparseArray_destroy(array -> left);
    }
  if(array->right!= NULL)
    {
      SparseArray_destroy(array -> right);
    }
  free(array);
}
/* Retrieve the smallest index in the sparse array. 
 */
int SparseArray_getMin ( SparseNode * array )
{
  /* 
  if(array == NULL)
    {
      return 0;
    }

  while(array->left != NULL)
    {
      array = array->left;
    }
  
    return array->index;*/
  if(array != NULL)
    {
      if(array -> left != NULL)
	{
	  return  SparseArray_getMin(array -> left) ;
	}
      if(array -> left == NULL)
	{
	  return array->index;
	}
    }
  return 0;
}

/* Retrieve the largest index in the sparse array. 
 */
int SparseArray_getMax ( SparseNode * array )
{
  /*
  if(array == NULL)
    {
      return 0;
    }

  while(array->right != NULL)
    {
      array = array->right;
    }
  
  return array->index;

  */
  if(array != NULL)
    {
      if(array -> right != NULL)
	{
	  return SparseArray_getMax(array -> right) ;
	}
      if(array -> right == NULL)
	{
	  return array->index;
	}
    }
  return 0;

}

/* Retrieve the node associated with a specific index in a sparse
 * array.  It returns the value
 * associated with the index. If the index does not exist in the
 * array, it returns NULL. If the given index is smaller than the current
 * node, search left ; if it is larger, search right.
 */
SparseNode * SparseArray_getNode(SparseNode * array, int index )
{
  SparseNode*node = array;
      if(array == NULL)
	{	
	   return NULL;
	}
      if(index == node->index)
	{
	  return node;
	}
      if(index > (node -> index))
	{
	  return SparseArray_getNode(node ->right, index);
	}
      if(index < (node -> index))
	{
	  return  SparseArray_getNode(node -> left, index);
	}
      //     else
      //	{
      //	  return NULL;
      //	}
      return node;
}

/* Remove a value associated with a particular index from the sparse
 * array. It returns the new
 * sparse array ( binary tree root ). HINT : You will need to isolate
 * several different cases here :
 * - If the array is empty ( NULL ), return NULL
 * - Go left or right if the current node index is different.

 * - If both subtrees are empty, you can just remove the node.

 * - If one subtree is empty, you can just remove the current and
 * replace it with the non - empty child.

 * - If both children exist, you must find the immediate successor of
 * the current node ( leftmost of right branch ), swap its values with
 * the current node ( BOTH index and value ), and then delete the
 * index in the right subtree.
*/
SparseNode * SparseArray_remove ( SparseNode * array, int index )
{
  if(array == NULL)
    {
      return NULL;
    }
  if(index < array->index)
    {
      array-> left = SparseArray_remove(array->left, index);
      return array;
    }
  if(index > array->index)
    {
      array->right = SparseArray_remove(array->right,index);
      return array;
    }
  if((array->left == NULL) && (array->right == NULL))
    {
      free(array);
      return NULL;
    }
  if(array->left ==NULL)
    {
      SparseNode * r = array->right;
      free(array);
      return r;
    }
  if(array->right ==NULL)
    {
      SparseNode * l = array->left;
      free(array);
      return l;
    }
  SparseNode * succ = array->right;
  while((succ->left) != NULL)
    {
      succ = succ->left; 
    }
  array->index = succ->index;
  succ->index = index;
  array->value = succ->value;
  array->right = SparseArray_remove(array->right,index);
  return array;
  
}

/* The function makes a copy of the input sparse array 
 * and it returns a new copy. 
 */

SparseNode * SparseArray_copy(SparseNode * array)
{
  // /*
  if (array == NULL)
    {
      return NULL;
    }
  SparseNode*arraycopy = SparseNode_create(array->index,array->value);
  if (array->left != NULL)
    {
      arraycopy->left = SparseArray_copy(array->left);
    }
  if(array->right != NULL)
    {
      arraycopy->right = SparseArray_copy(array->right);
    }

  return arraycopy;//*/
  /*

  if (array == NULL)
    {
      return NULL;
    }
  SparseNode*arraycopy = SparseNode_create(array->index,array->value);
  while(array != NULL)
    {
      if(array->left !=NULL && arraycopy->left !=NULL)
	{
	  arraycopy.left = SparseArray_add(array,array->index,array->value);
	  array = array->left;			
	  arraycopy = arraycopy->left;
	}
      else if(array->right !=NULL &&arraycoyp->right != NULL)
	{
	  arraycopy.right =  SparseArray_add(array,array->index,array->value);
	   array = array->right;
	   arraycopy = arraycopy->right;	   
	}
      else
	{
	  array = array.
	}
    }
  */
}

/* Merge array_1 and array_2, and return the result array. 
 * This function WILL NOT CHANGE the contents in array_1 and array_2.
 * When merging two sparse array:
 * 1. The contents in array_1 and array_2 should not be changed. You should make
 *    a copy of array_1, and do merging in this copy.
 * 2. array_2 will be merged to array_1. This means you need to read nodes in 
 *    array_2 and insert them into array_1.
 * 3. You need to use POST-ORDER to traverse the array_2 tree. 
 * 4. Values of two nodes need to be added only when the indices are the same.
 * 5. A node with value of 0 should be removed.
 * 6. if array_2 has nodes with index different than any nodes in array_1, you
 *    should insert those nodes into array_1.
 * 
 */

SparseNode * SparseArray_merge(SparseNode * array_1, SparseNode * array_2)
{
  if (array_1 == NULL)
    {
      return array_2;
    }/*
  if(array_2 == NULL)
    {
      return array_1;
      }*/
  SparseNode*clone1 = SparseArray_copy(array_1);
  clone1 = mergehelper(clone1,array_2);
  return clone1;
}

SparseNode * mergehelper(SparseNode * clone_root, SparseNode * array_2)
{
   if(array_2 == NULL)
    {
      return clone_root;
    }   
   SparseNode * node2 = array_2;
   SparseNode * node1 = SparseArray_getNode(clone_root,node2->index);

   

   mergehelper(clone_root, array_2->left); 
   mergehelper(clone_root, array_2->right); 

  if(node1 == NULL)
    {
      clone_root= SparseArray_add(clone_root, node2->index, node2->value );
    }
  else
    {
      node1->value += node2->value;
      if(node1->value == 0)
	  {
	    clone_root = SparseArray_remove(clone_root, node2->index);
	  }
    }
  return clone_root;
}


  // In a pre-order traversal, you "do-the-work", and then "visit-the-children"
  // In a post-order traversal, you "visit-the-children", and then "do-the-work"
  
  // post-order is like this:
  // call mergehelpr on array_2->left 
  // call mergehelpr on array_2->right
  // ALWAYS keep track of clone_root
  // Now "do-the-work"
  //  printf("[#%d] %d\n", array_2->index, array_2->value);

  // In step three, you /know/ the node of interest, and you
  // merge it into the tree rooted at clone_root, /without/, losing
  // track of clone_root. Clone_root /never/ changes.
  // Use the functions you already wrote:
  // + get, add, remove
