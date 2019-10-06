using System;
using System.Collections;
using System.Collections.Generic;

namespace Random_weighted
{
    class MainClass
    {
        private static Dictionary<string, int> weights = new Dictionary<string, int>()
            {
               {"Vanilla", 15},
               {"Strawberry", 25},
               {"Chocolate", 55},
               {"Cookies and Cream", 5}
            };

        private static int sum = 0;
        private static int limit = 100;

        private static void Main()
        {
            var results = new Dictionary<string, int>()
            {
               {"Vanilla", 0},
               {"Strawberry", 0},
               {"Chocolate", 0},
               {"Cookies and Cream", 0}
            };

            foreach(var item in weights)
            {
                sum += item.Value;
            }

            for (int i=0;i<limit;i++)
            {
                results[Weigh(weights)] += 1;
            }

            foreach(var item in results)
            {
                Console.WriteLine(item.Key + " : " + item.Value + "\n");
            }

        }

        private static string Weigh(Dictionary<string, int> a)
        {
            Random random = new Random();

            int rand = random.Next(1, sum);

            foreach (var item in weights)
            {
                rand = rand - item.Value;
                if (rand <= 0)
                    return item.Key;
            }
            return "Should not reach here.";
        }

    }
}
