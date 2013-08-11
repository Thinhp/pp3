#ifndef _GENETICPROGRAM_H_
#define _GENETICPROGRAM_H_

/******************************************************************************
 Header file
 Class:        GeneticProgram 
 Date created: 26/03/2002
 Written by:   Dylan Mawhinney

 Adapted from code originally written by Peter Wilson.

 The genetic program class represents an individual in the population,
 it has a program tree which is pointed to by the root pointer.

 It can be evaluated (executed) and has a fitness associated with it.

******************************************************************************/

#include "ReturnData.h"
#include "Node.h"

class GPConfig;

class GeneticProgram 
{
   private:
      GPConfig *config;    //Configuration object for this program
      int programID;       //ID number of this program
      double fitness;      //The fitness of this program
      double adjustFitness; //The adjusted fitness 
      int depth;           //Depth of this program
      int size;            //Size of this program
      int returnType;      //Return type of this program
      Node* root;          //The root node of the program tree 

      Node* buildTree(string &programString, string::iterator &si); 
   protected:

   public:
      /*************
        Constructor 
      **************/
      GeneticProgram(GPConfig *conf);

      /******************
       Copy Constructor
      ******************/
      GeneticProgram(GeneticProgram &g);

      /********************
       Virtual destructor
      ********************/
      virtual ~GeneticProgram(); 

      /****************************
       Set and get the program ID
      ****************************/
      void setProgramID(int id);
      int getProgramID() const;

      /*****************************************
       Evaluates the entire program beginning
       at the root node and returns the result 
       through the ReturnData object.

       The out parameter must point to an object
       of the correct type for the root node
       to return it's value correctly.
      ******************************************/
      void evaluate(ReturnData *out);

      /*****************************************
       Set the root of this genetic program's
       tree, if the old genetic program tree is
       no longer to be used, then the user must
       explicitly call deleteTree() before
       calling this method, otherwise LARGE
       memory leaks will occur.
      *****************************************/
      void setRoot(Node *value);
      Node * getRoot();

      /*****************************************
       Copy this Program and return a pointer
       to the new program.
      *****************************************/
      GeneticProgram* copy();

      /********************************************
       Gets the depth and size of this particular
       program.
      ********************************************/
      int getDepth() const;
      int getSize() const;

      /********************************************
       Computes the depth and size of this program.
      ********************************************/
      void computeSizeAndDepth();

      /*****************************************
       Returns a random node in the tree 
      *****************************************/
      Node* getRandomNode();

      /****************************************
       Returns a random node in the tree which
       returns the type typeNum.
      ****************************************/
      Node* getRandomNode(int typeNum);

      /***************************************
       Deletes this programs tree.
      ****************************************/
      void deleteTree(); 

      /*****************************************
       Delete the subtree rooted at theRoot
       Careful!!!
      *****************************************/
      void deleteTree(Node *theRoot); 

      /************************************
       Print the program into the string
      *************************************/
      void print(string &s);

      /***************************************
       Set and get the return type for this
       program.
      ***************************************/
      void setReturnType(int type);
      int getReturnType() const;

      /**************************************
       Set and get the fitness for this
       program.
      **************************************/
      void setFitness(double f);
      double getFitness() const;
      void setAdjFitness(double f);
      double getAdjFitness() const;

      /***************************************
       Parse a string, build a program
       tree, based on a function originally 
       written by Peter Wilson. 
      ***************************************/
      void parseProgram(string &programString); 
};

#endif
