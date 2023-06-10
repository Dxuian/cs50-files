// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
//N chota rak below 
const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //ez hai but better hash functions lookup dekh 
    int index  =  hash(word) ; 
    node* temp  =  table[index] ;  
    while(temp!=NULL)
    {
        if(strcasecmp((temp->word), word)==0)
        {
            return true  ; 
        }
        else 
        {
            temp= temp->next  ; 
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO 
    int h = 0 ;
    int po = strlen(word) ;
    for (int i = 0; i < po; i++)
    {
        if (word[i] < 97 && word[i] >= 65)
        {
            h += (word[i] - 64) ; 
        }
        else
        {
            h += (word[i] - 96) ; 
        }
    }
    return (h / po)%N;
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
     char buf[100]  ; 
     strcpy(buf , dictionary) ;  
    
    for(int i = 0 ; i<N  ;  i++)
    {
        table[i] = NULL ; 
    }
    FILE* p   =  fopen( buf  , "r") ; 
    if(p==NULL)
    {
        return false  ; 
    }
    node* temp[1000]  = {NULL} ;  
    node* n ; 
    //  if(table[index] == NULL)
    //      {
    //          table[index] =  n  ; 
    //      }
    //      else 
    //      {
    //kaam ni krta idk shit mem leak hora hai fix it 
    char* buffer = (char*)malloc(sizeof(char)*100)  ;      //      }
    while(fscanf(p ,  "%s" , buffer)!=EOF)
    {
        
         int index   = hash((char*)buffer) ; 
          n = malloc(sizeof(node)) ; 
         if(n==NULL)
         {
             return false ; 
         }
         strcpy(n->word,buffer) ; 
         n->next =  NULL ;
         if(table[index]==NULL) 
         {
             table[index] = n ;
             temp[index]  =  n  ; 
              
              continue ;
         }
         else 
         {
            temp[index]->next = n  ; 
            temp[index] = temp[index]->next  ; 
            
             continue  ; 
         }
         
    }
  
    
    free(buffer) ;
fclose(p)  ;     

    return true;
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    //chal gya yeh ignor 
    int s = 0 ; 
   node* temp  ; 
    for(int i = 0 ;  i<N  ; i++)
    {
       temp =  table[i] ;
       if(table[i]==NULL) 
       {
           
       }
       else 
       {
          while(temp!=NULL)
          {
              s++ ; 
              temp =  temp->next  ; 
          }
       }
    }
    return s ; 
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //chal rha hai check for mem leak tho 
    node* temp ;
    node* temp2  ; 
    for( int i  = 0 ;  i<= N ; i++)
    {
       if (table[i]==NULL)
       {
       }
       else  if(table[i]->next==NULL)
        {
            free(table[i]);
        }
        else  if(table[i]->next!=NULL)
        {
          temp =  table[i] ;
          temp2=  table[i]  ; 
          while(temp!=NULL)
          {
              temp = temp->next ; 
              free(temp2) ; 
              temp2 = temp ; 
          }
          
        }
    }
    return true  ;
    return false;
}
