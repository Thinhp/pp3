/******************************************************************************
 Definition file
 Class:        Population 
 Date created: 11/04/2002
 Written by:   Dylan Mawhinney

 See header file for details
******************************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

#include <sys/types.h>
#include <errno.h>
#include <time.h>

#ifdef UNIX
  #include <unistd.h>
  #include <sys/wait.h>
#endif

#include "Population.h"
#include "ProgramGenerator.h"

Population::Population(int size, char* logFileName, GPConfig *conf) :
                                   pop(NULL), 
                                   depthLimit(0), minDepth(0),
                                   numIndividuals(size), performDecimation(false),
                                   bestFitness(0.0), worstFitness(0.0),
                                   avgFitness(0.0), avgDepth(0.0),
                                   avgSize(0.0), returnType(-1),
                                   mutationRate(0.0), numForMutation(0),
                                   crossoverRate(0.0), numForCrossover(0),
                                   elitismRate(0.0), numForElitism(0),
                                   generationNumber(0), loggingFrequency(1),
                                   useCompression(false), config(conf)
{
   int i;
   pop = new GeneticProgram* [numIndividuals];

   if (pop == NULL)
      throw string("Population::Population() Error, out of memory");
  
   for(i=0; i<numIndividuals; i++)
   {
      pop[i] = new GeneticProgram(config); 

      if (pop[i] == NULL)
         throw string("Population::Population() Error, out of memory");
   }

   logFile.open(logFileName);
   if (logFile.bad())
   {
      throw string("Population::Population() Error cannot open log file");
   }
}

Population::Population(int size, int initSize, char* logFileName, GPConfig *conf) :
                                   pop(NULL), 
                                   depthLimit(0), minDepth(0),
                                   numIndividuals(initSize), initNumIndividuals(size),
								   numGenerationBeforeDecimation(0), performDecimation(true),
                                   bestFitness(0.0), worstFitness(0.0),
                                   avgFitness(0.0), avgDepth(0.0),
                                   avgSize(0.0), returnType(-1),
                                   mutationRate(0.0), numForMutation(0),
                                   crossoverRate(0.0), numForCrossover(0),
                                   elitismRate(0.0), numForElitism(0),
                                   generationNumber(0), loggingFrequency(1),
                                   useCompression(false), config(conf)
{
   int i;
   fallPerGeneration = (int)((initSize - size) / (numGenerationBeforeDecimation + 1));
   pop = new GeneticProgram* [numIndividuals];

   if (pop == NULL)
      throw string("Population::Population() Error, out of memory");
  
   for(i=0; i<numIndividuals; i++)
   {
      pop[i] = new GeneticProgram(config); 

      if (pop[i] == NULL)
         throw string("Population::Population() Error, out of memory");
   }

   logFile.open(logFileName);
   if (logFile.bad())
   {
      throw string("Population::Population() Error cannot open log file");
   }
}

Population::Population(Population &p) :
                          pop(NULL), 
                          depthLimit(p.depthLimit), minDepth(p.minDepth),
                          numIndividuals(p.numIndividuals), initNumIndividuals(p.initNumIndividuals),
						  numGenerationBeforeDecimation(p.numGenerationBeforeDecimation), performDecimation(p.performDecimation),
                          bestFitness(p.bestFitness), worstFitness(p.worstFitness),
                          avgFitness(p.avgFitness), avgDepth(p.avgDepth),
                          avgSize(p.avgSize), returnType(p.returnType),
                          mutationRate(p.mutationRate), numForMutation(p.numForMutation),
                          crossoverRate(p.crossoverRate), numForCrossover(p.numForCrossover),
                          elitismRate(p.elitismRate), numForElitism(p.numForElitism),
                          generationNumber(p.generationNumber), loggingFrequency(p.loggingFrequency),
                          useCompression(p.useCompression), config(new GPConfig(*(p.config)))
{
   int i;
   pop = new GeneticProgram* [numIndividuals];

   if (pop == NULL)
      throw string("Population::Population() Error, out of memory");
  
   for(i=0; i<numIndividuals; i++)
   {
      pop[i] = new GeneticProgram(*(p.pop[i]));

      if (pop[i] == NULL)
         throw string("Population::Population() Error, out of memory");
   }
   /* ToDo: Add code for logfilename */
}


Population::~Population()
{
   int i;

   writeToFile();
   logFile.close();

   for(i=0; i<numIndividuals; i++)
   {
      delete (pop[i]);
      pop[i] = NULL;
   }
 
   delete [] pop; 
   pop = NULL;
}

GeneticProgram** Population::getPopulation() const
{
   return pop;
}

void Population::setPopulation(GeneticProgram **newPop, int size)
{
   int i;

   if (size != numIndividuals)
      throw string("Population::setPopulation error incorrect size");

   //copy new generation over old generation
   for(i=0; i<numIndividuals; i++)
   {
      delete pop[i];
      pop[i] = newPop[i];
   }
}

GeneticProgram* Population::getIndividual(int individual)
{
   GeneticProgram* tmp;

   if (individual < numIndividuals)
      tmp = pop[individual];
   else
      throw string("Population::getIndividual Error invalid individual");

   if (tmp == NULL)
      throw string("Population::getIndividual Error individual is NULL");

   return tmp;
}

void Population::setDepthLimit(int d)
{
   depthLimit = d;
}

void Population::setMinDepth(int d)
{
   minDepth = d;
}

void Population::generateInitialPopulation()
{
   config->programGenerator->generateInitialPopulation(pop, numIndividuals,
                              minDepth, depthLimit, depthLimit, returnType); 

}

void Population::correctRates()
{
   int total = numForMutation + numForCrossover + numForElitism;

   if (total > numIndividuals)
   {
      throw string("Population::correctRates Error, rates for mutation, crossover, and elitism add up to > 1.0");
   }

   if((numForCrossover % 2) != 0)
   {
      numForCrossover--;
      total--;
   }

   numForElitism += (numIndividuals - total);

   if ((numIndividuals - total) != 0)
   {
      cerr << "**** Warning Population::correctRates()***" << endl
           << "Mutation/crossover/elitism rates have been adjusted."<< endl
           << "This is usually caused by rounding errors, however it can"<< endl
           << "also be caused by not having the rates add up to 1.0" << endl
           << "or specifying rates which produce an odd" << endl
           << "number of individuals for crossover." << endl
           << "See the Population class for more details." << endl << endl; 
   }
}

bool Population::evolve(int numGenerations)
{
   int i=0;
   evaluations = 0;
   for (; i<numGenerations; i++)
   {
      assignFitness();  //Evaluate the programs and assign their fitness values
      evaluations += numIndividuals;   //Update the number of evaluations performed
      sortPopulation();    //Sort the population based on fitness
      computeStatistics(); //Calculate some statistics for the population
      writeLog();          //Write some information to the log file

      /* Decimation 
         The actual removal of individuals from the bottom of the population and the
         freeing of the memory is carried out in the numGenerationBeforeDecimation
         method.
      
      */
      if ( performDecimation )
      {
         /* If the numGenerationBeforeDecimation set to a value greater than 0
            progressive decimation is performed */
         if ( i < numGenerationBeforeDecimation )
            setNumIndividuals(numIndividuals - fallPerGeneration);
         else if ( i == numGenerationBeforeDecimation )
         {
            //Decimation is completed in this step.
            setNumIndividuals(initNumIndividuals);
            performDecimation = false;
         }
      }
  
      //If the solution has been found quit and return true to
      //indicate success 
      if (config->fitnessObject->solutionFound(pop, numIndividuals))
      {
         logFile << "Solution found!\n";
         return true;
      }

      nextGeneration();
   }

   sortPopulation();
   return false;
}

void Population::nextGeneration()
{
   int indiv1, indiv2;
   int counter=0;
   int i;
   GeneticProgram* *nextPop;

   //Write the pop to a file if it's time
   if ((generationNumber % loggingFrequency) == 0)
      writeToFile();

   nextPop = new GeneticProgram* [numIndividuals];

   correctRates();

   adjustFitness();

   //copy some individuals (elitism)
   for (i=0; i<numForElitism; i++)
   { 
      nextPop[counter++] = pop[i]->copy(); 
   }

   //crossover some individuals
   for (i=0; i<numForCrossover; i += 2)
   {
      indiv1 = config->selectionOperator->select(pop, numIndividuals, config);
      indiv2 = config->selectionOperator->select(pop, numIndividuals, config);
      nextPop[counter++] = pop[indiv1]->copy();
      nextPop[counter++] = pop[indiv2]->copy();

      config->crossoverOperator->crossover(*(nextPop[counter-2]), 
                                           *(nextPop[counter-1]),
                                           100,
                                           config);
   }

   //mutate some individuals
   for (i=0; i<numForMutation; i++)
   {
      indiv1 = config->selectionOperator->select(pop, numIndividuals, config);
      nextPop[counter++] = pop[indiv1]->copy();
      config->mutationOperator->mutate(*(nextPop[counter-1]), config);
   }

   //copy new generation over old generation
   for(i=0; i<numIndividuals; i++)
   {
      delete (pop[i]);
      pop[i] = NULL;
   }

   delete [] pop;
   pop = nextPop;

   generationNumber++;
}

/*******************************************
 adjustFitness()
 Adjusts the raw fitness values for use 
 with the roullette wheel selection
 operator. Gives programs with low (better)
 raw fitnesses higher adjusted fitnesses.
*******************************************/

void Population::adjustFitness()
{
   int i;
   double totalFitness=0.0;

   for(i=0; i<numIndividuals; i++)
   {
      pop[i]->setAdjFitness(1.0 / (1.0 + pop[i]->getFitness()));
      totalFitness += pop[i]->getAdjFitness();
   }   

   for (i=0; i<numIndividuals; i++)
   {
      pop[i]->setAdjFitness(pop[i]->getAdjFitness() / totalFitness);
   }
}

/***********************************************
setInitNumIndividuals makes sure that the
initial population size is greater than the 
actual size of the population, for performing
Decimation.
************************************************/

void Population::setNumGenerationBeforeDecimation(int num)
{
   if ( performDecimation )
   {
      //Negative values are not allowed for numGenerationBeforeDecimation
      if ( num < 0 )
      {
         num = 0;
      }

      numGenerationBeforeDecimation = num;
      fallPerGeneration = (numIndividuals - initNumIndividuals) / (numGenerationBeforeDecimation + 1);
   }
}

int Population::getNumGenerationBeforeDecimation() const
{
   if ( performDecimation )
      return numGenerationBeforeDecimation;
   else
      return -1;
}

/***********************************************
 setNumIndiviuals currently resizes the 
 population. If the new size is smaller
 it truncates the old population (the last
 N programs are lost). If the new size
 is bigger then new population contains N
 copies of the last program in the population.

 If you want different behaviour, make a
 subclass of this class and overide this
 method.

 N is the difference between old and new sizes.
************************************************/

void Population::setNumIndividuals(int num)
{
   int i;
   GeneticProgram* *tmp = NULL;

   tmp = new GeneticProgram* [num];

   for(i=0; i<num && i<numIndividuals; i++)
      tmp[i] = pop[i];

   if (num > numIndividuals)
   {
      for( ; i<num; i++)
      {
         tmp[i] = new GeneticProgram(config);
         tmp[i] = tmp[numIndividuals-1]->copy(); 
      }
   }
   else
   {
      for( ; i<numIndividuals; i++)
      {
         delete pop[i];
      }
   }

   numIndividuals = num;

   delete [] pop;
   pop = tmp;

   numForMutation = (int) (numIndividuals * mutationRate);
   numForCrossover = (int) (numIndividuals * crossoverRate);
   numForElitism = (int) (numIndividuals * elitismRate);

}

int Population::getNumIndividuals() const
{
   return numIndividuals;
}

void Population::setGenerationNumber(int num)
{
   generationNumber = num;
}

int Population::getGenerationNumber() const
{
   return generationNumber;
}

void Population::setReturnType(int type)
{
   int i;

   returnType = type;

   for (i=0; i<numIndividuals; i++)
   {
      pop[i]->setReturnType(type); 
   }
}

int Population::getReturnType() const
{
   return returnType;
}

void Population::setMutationRate(double rate)
{
   mutationRate = rate;
   numForMutation = (int) (numIndividuals * rate); 

   if (numForMutation > numIndividuals)
      throw string("Population::setMutationRate Error, numForMutation greater than numIndividuals"); 
}

double Population::getMutationRate() 
{
   return mutationRate;
}
void Population::setNumForMutation(int num)
{
   numForMutation = num;
   mutationRate = ((double) numForMutation) / ((double) numIndividuals) ;

   if (numForMutation > numIndividuals)
      throw string("Population::setNumForMutation Error, numForMutation greater than numIndividuals"); 
}

int Population::getNumForMutation()
{
   return numForMutation;
}

void Population::setCrossoverRate(double rate)
{
   crossoverRate = rate;
   numForCrossover = (int) (rate * numIndividuals);

   if (numForCrossover > numIndividuals)
      throw string("Population::setCrossoverRate Error, numForCrossover greater than numIndividuals"); 
}

double Population::getCrossoverRate()
{
   return crossoverRate;
}

void Population::setNumForCrossover(int num)
{
   numForCrossover = num;
   crossoverRate = ((double) numForCrossover) / ((double) numIndividuals);

   if (numForCrossover > numIndividuals)
      throw string("Population::setNumForCrossover Error, numForCrossover greater than numIndividuals"); 
}

int Population::getNumForCrossover()
{
   return numForCrossover;
}

void Population::setElitismRate(double rate)
{
   elitismRate = rate;
   numForElitism = (int) (rate * numIndividuals);

   if (numForElitism > numIndividuals)
      throw string("Population::setElitismRate Error, numForElitism greater than numIndividuals"); 
}

double Population::getElitismRate()
{
   return elitismRate;
}

void Population::setNumForElitism(int num)
{
   numForElitism = num;
   elitismRate = ((double) numForElitism) / ((double) numIndividuals);

   if (numForElitism > numIndividuals)
      throw string("Population::setNumForElitism Error, numForElitism greater than numIndividuals"); 
}

int Population::getNumForElitism()
{
   return numForElitism;
}

void Population::assignFitness()
{
   config->fitnessObject->assignFitness(pop, numIndividuals);
}

//Quicksort function for sortPopulation
//Code adapted from code from 
//http://linux.wku.edu/~lamonml/algor/sort/quick.c

void Population::qSort (GeneticProgram **individuals, int left, int right)
{
   GeneticProgram* pivot;
   int l_hold, r_hold;
   int tmp;

   l_hold = left;
   r_hold = right;
   pivot = individuals[left];
   while (left < right)
   {
      while ((config->fitnessObject->isWorse(individuals[right], pivot) || 
               config->fitnessObject->isEqual(individuals[right], pivot)) &&
             (left < right))
      { 
         right--;
      }

      if (left != right)
      {
         individuals[left] = individuals[right];
         left++;
       }

       while ((config->fitnessObject->isBetter(individuals[left], pivot) || 
               config->fitnessObject->isEqual(individuals[left], pivot)) &&
             (left < right))
       {
         left++;
       }

       if (left != right)
       {
          individuals[right] = individuals[left];
          right--;
       }
   }

   individuals[left] = pivot;
   tmp = left;
   left = l_hold;
   right = r_hold;

   if (left < tmp)
      qSort(individuals, left, tmp-1);
   if (right > tmp)
      qSort(individuals, tmp+1, right);
}

void Population::sortPopulation()
{
   qSort(pop, 0, numIndividuals-1);
}

GeneticProgram* Population::getBest()
{
   int index=0;
   int i;

   for(i=0; i<numIndividuals; i++)
   {
      if (config->fitnessObject->isBetter(pop[i],pop[index]))
      {
         index = i;
      }
   }

   return pop[index];
}

GeneticProgram* Population::getWorst()
{
   int index=0;
   int i;

   for(i=0; i<numIndividuals; i++)
   {
      if (config->fitnessObject->isWorse(pop[i], pop[index]))
      {
         index = i;
      }
   }

   return pop[index];
}

void Population::computeStatistics()
{
   int i;
   double totalFitness=0.0;
   double totalDepth=0.0;
   double totalSize=0.0;

   bestFitness = getBest()->getFitness();
   worstFitness = getWorst()->getFitness(); 

   for (i=0; i<numIndividuals; i++)
   {
      totalFitness += pop[i]->getFitness();   
      totalDepth += pop[i]->getDepth();
      totalSize += pop[i]->getSize();
   }

   avgFitness = totalFitness / numIndividuals;
   avgDepth = totalDepth / numIndividuals;
   avgSize = totalSize / numIndividuals;
}

void Population::writeToFile()
{
   char filename[50];
   ofstream outputFile;

   sprintf(filename, "gen_%06d.gen", generationNumber);
   outputFile.open(filename);
  
   if (outputFile.good()) 
      outputFile << *this;
   else
      throw string("Population::writeToFile Error could not open file");

   outputFile.close();

   if (useCompression)
      compressFile(filename);
}

void Population::readFromFile(char *fileName)
{
   ifstream inputFile;

   inputFile.open(fileName);

   if (inputFile.good())
      inputFile >> *this;
   else
      throw string("Population::readFromFile Error could not open file");

   inputFile.close();
}

ostream& operator << (ostream& o, Population& p)
{
   time_t theTime;
   int i;
   string s1;

   time(&theTime);

   o << "Population at generation " << p.generationNumber << endl 
     << "File created at " << ctime(&theTime) 
     << "numIndividuals " << p.numIndividuals << endl
     << "depthLimit " << p.depthLimit << endl
     << "minDepth " << p.minDepth << endl
     << "returnType " << p.returnType << endl
     << "mutationRate " << p.mutationRate << endl
     << "crossoverRate " << p.crossoverRate << endl
     << "elitismRate " << p.elitismRate << endl;

   for(i=0; i<p.numIndividuals; i++)
   {
      s1 = "";
      p.pop[i]->print(s1);
      o << "###################################\n"
        << "Individual " << i << endl
        << "Fitness " << p.pop[i]->getFitness() << endl
        << "Depth " << p.pop[i]->getDepth() << endl
        << "Size " << p.pop[i]->getSize() << endl
        << "Program " << s1 << endl;
   }

   return o;
}

istream& operator >> (istream& i, Population& p)
{
   const int MAXLINE = 1000;
   char line[MAXLINE];   
   string programString;
   char tmpChar;

   int individual=0;

   int iValue=0;
   double dValue=0.0;

   //First loop reads the header info in the pop file
   while (true)
   {
      //Get a line of input from the stream
      if (!(i.getline(line, MAXLINE, '\n')))
      {
         if (i.eof() || i.bad())
            break;

         i.clear();
      }


      //If we read a hash at the start of the line, then
      //the header info is finished
      if (line[0] == '#')   
         break;

      if (strncmp(line, "numIndividuals", strlen("numIndividuals")) == 0)
      {
         sscanf(line+(strlen("numIndividuals")), "%d", &iValue);
         cerr << "Setting numIndividuals to supplied value " << iValue << endl;
         p.setNumIndividuals(iValue); 
      }
      else if (strncmp(line, "depthLimit", strlen("depthLimit")) == 0)
      {
         sscanf(line+(strlen("depthLimit")), "%d", &iValue);
         cerr << "Setting depthLimit to supplied value " << iValue << endl;
         p.setDepthLimit(iValue); 
      }
      else if (strncmp(line, "minDepth", strlen("minDepth")) == 0)
      {
         sscanf(line+(strlen("minDepth")), "%d", &iValue);
         cerr << "Setting minDepth to supplied value " << iValue << endl;
         p.setMinDepth(iValue); 
      }
      else if (strncmp(line, "returnType", strlen("returnType")) == 0)
      {
         sscanf(line+(strlen("returnType")), "%d", &iValue);
         cerr << "Setting returnType to supplied value " << iValue << endl;
         p.setReturnType(iValue); 
      }
      else if (strncmp(line, "mutationRate", strlen("mutationRate")) == 0)
      {
         sscanf(line+(strlen("mutationRate")), "%lf", &dValue);
         cerr << "Setting mutationRate to supplied value " << dValue << endl;
         p.setMutationRate(dValue); 
      }
      else if (strncmp(line, "crossoverRate", strlen("crossoverRate")) == 0)
      {
         sscanf(line+(strlen("crossoverRate")), "%lf", &dValue);
         cerr << "Setting crossoverRate to supplied value " << dValue << endl;
         p.setCrossoverRate(dValue); 
      }
      else if (strncmp(line, "elitismRate", strlen("elitismRate")) == 0)
      {
         sscanf(line+(strlen("elitismRate")), "%lf", &dValue);
         cerr << "Setting elitismRate to supplied value " << dValue << endl;
         p.setElitismRate(dValue); 
      }
      else
      {
         cerr << "Ignoring line " << line << endl;
      }
   }

   while (true)
   {
      if (individual >= p.numIndividuals)
         break;

      if (!(i.getline(line, MAXLINE, '\n')))
      {
         if (i.eof() || i.bad())
            break;

         i.clear();
      }

      if (line[0] == '#')
      {
         individual++;
         continue;
      }

      if (strncmp(line, "Individual", strlen("Individual")) == 0)
      {
         sscanf(line+(strlen("Individual")), "%d", &iValue);
         cerr << "Reading individual " << iValue 
              << " into slot " << individual << endl;
      }
      else if (strncmp(line, "Fitness", strlen("Fitness")) == 0)
      {
         sscanf(line+(strlen("Fitness")), "%lf", &dValue);
         cerr << "Setting fitness to " << dValue << endl;
         p.pop[individual]->setFitness(dValue);
      }
      else if (strncmp(line, "Program", strlen("Program")) == 0)
      {
         programString = line + strlen("Program");

         if ((signed)i.gcount() != MAXLINE && strlen(line) == MAXLINE-1)
         {
            do 
            {
               i.get(tmpChar);
               programString.append(1, tmpChar);
            } while (tmpChar != '\n');
         }

         p.pop[individual]->parseProgram(programString);          
      }
      else
      {
         cerr << "Ignoring line " << line << endl;
      }
   }

   if (individual < p.getNumIndividuals())
   {
      cerr << "**** Warning ****" << endl
           << "Number of programs in population file is less than " 
           << p.getNumIndividuals() << endl;
   }

   return i;
}

void Population::setLogFrequency(int freq)
{
   loggingFrequency = freq;
}

int Population::getLogFrequency() const
{
   return loggingFrequency;
}

void Population::compressGenerationFiles(bool value)
{
   useCompression = value;
}

bool Population::getCompressFiles() const
{
   return useCompression;
}

void Population::writeLog()
{
   time_t theTime;
   time(&theTime);

   logFile << "*****************************************\n"
           << "Generation " << generationNumber << endl
           << "Time " << ctime(&theTime)
           << "BestFitness " << bestFitness << endl
           << "WorstFitness " << worstFitness << endl
           << "AverageFitness " << avgFitness << endl
           << "AverageDepth " << avgDepth << endl
           << "AverageSize " << avgSize << endl
           << "Evaluation " << evaluations << endl;
}

/***********************************************
 compressFile assumes that gzip is installed on
 the system and is in the PATH environment 
 variable. If this is not the case, you will
 need to sublcass the population class and 
 implement this method.
 Adapted from code written by Peter Wilson
 and modified by Dylan Mawhinney.
***********************************************/
void Population::compressFile(char *fileName)
{
#ifdef UNIX
   pid_t pid = fork();
   int loc;

   if (pid == 0)
   {
      execlp("gzip", "gzip", "-f", fileName, NULL);
      throw string("Population::compressFile could not exec gzip");
   }
   else if (pid == -1)
   {
      throw string("Population::compressFile could not fork new process");
   }
   else
   {
      while (waitpid(pid, &loc, 0) <= 0)   
      {
         if (errno != EINTR)
            break;
      }
   }
#else
   throw string("Population::compressFile Error should only be called from UNIX");
#endif
}
