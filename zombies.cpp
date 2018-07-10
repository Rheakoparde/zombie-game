/********************************************************
 * CS 103 Zombie-pocalypse PA
 * Name: Rhea Koparde
 * USC email: Koparde@usc.edu
 * Comments (you want us to know):
 *
 *
 ********************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

const int MAXPOP = 100000;

int main()
{
  // Array with enough entries for the maximum population size possible.
 	bool pop[MAXPOP];

  // Your code here
 	int N; //population
	int k; // zombies
	int M;
	int seed;
	cout << "Enter the following: N k M seed" << endl;
	cin >> N;
	cin >> k;
	cin >> M;
	cin >> seed;
	
	int max = 0;
	int min = 1000000;
	int sum = 0;
	double average = 0;
	srand(seed);

	for(int j=0; j<M; j++)
	{

		for(int i=0; i<k; i++) //  set zombies to true
		{
			pop[i] = true;
		}
		for(int i=k; i<N; i++) // set people to false
		{
			pop[i] = false;
		}

		int numberOfNights = 0;
		int numberOfNewZombies;
		int zombiesBefore = k;
		while(N > zombiesBefore) //will store number of zombies plus number of new zombies
		{	
		    numberOfNewZombies = 0;	
			
				for(int i=0;i<zombiesBefore;i++) {  // turning humans in zombies
					int bites = rand() % N;
					if (pop[bites] == false)
					{
						pop[bites] = true;
						numberOfNewZombies++; //adding new zombies
					}	
					
			
				}

			zombiesBefore = zombiesBefore + numberOfNewZombies; //calculating total zombies
			numberOfNights++;
		}
			// Print out your average, max, and min number of nights here
  			// Be sure to follow the format shown in the assignment writeup.

  			if(numberOfNights >= max) 
  			{
  				max = numberOfNights;
  			}

  			if(numberOfNights <= min)
  			{
  				min = numberOfNights;
  			}

	  		sum = sum + numberOfNights;
	  		average = sum * 1.0/M;
	  

	}	
		
	cout << "Average Nights: " << average << endl; 
	  	cout << "Max Nights: " << max << endl;
	  	cout << "Min Nights: " << min << endl;

  return 0;
		
}
