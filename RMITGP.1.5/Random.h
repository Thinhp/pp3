#ifndef _RANDOM_H_
#define _RANDOM_H_

/******************************************************************************
 Header file
 Class:        Random 
 Date created: 12/04/2002
 Written by:   Dylan Mawhinney

 The Random class is the default random number generator in the system.
 If you wish to use a different one, you must make a subclass of this
 class and implement all the methods in this class. 
 You also need to pass an object of your class to the GPConfig class. 
******************************************************************************/

class Random 
{
   private:

   protected:

   public:
      Random(int seed=0);
      virtual ~Random();

      virtual long randNum() const;
      virtual long max() const;

      virtual double randReal() const;
};

#endif
