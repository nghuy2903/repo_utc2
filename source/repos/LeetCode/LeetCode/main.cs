using Logic;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    class main 
    {
        static void Main(string[] args)
        {
            Random random = new Random();

            // Initialize the List<int>
            List<int> randomNumbers = new List<int>();

            // Specify the number of elements
            int numberOfElements = 1000;

            // Populate the List with random integers
            for (int i = 0; i < numberOfElements; i++)
            {
                int randomNumber = random.Next(1,1000); // Generates a random integer
                randomNumbers.Add(randomNumber);
            }

            var evenNumbers = randomNumbers.Where(n => n % 2 == 0);
            foreach (int number in evenNumbers) 
            { 
                Console.WriteLine(number);  
            }

        }
    }
}
