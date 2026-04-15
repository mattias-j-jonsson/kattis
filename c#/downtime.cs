using System.IO;
using System;
// using System.Math;

namespace downtime
{
    class Program
    {
        static void Main()
        {
            // StreamReader reader = new StreamReader("input.txt");
            // string[] temp = reader.ReadLine().Split(' ');
            string[] temp = Console.ReadLine().Split(' ');

            int n = int.Parse(temp[0]);
            int k = int.Parse(temp[1]);

            int[] requests = new int[n];
            // requests[0] = int.Parse(reader.ReadLine());
            requests[0] = int.Parse(Console.ReadLine());
            int bottom_index = 0;
            int max_concurrent = 1;
            int concurrent = 1;
            for (int i = 1; i < n; i++)
            {
                // requests[i] = int.Parse(reader.ReadLine());
                requests[i] = int.Parse(Console.ReadLine());

                if (requests[i] < requests[bottom_index] + 1000)
                {
                    concurrent++;
                    if (concurrent > max_concurrent)
                    {
                        max_concurrent = concurrent;
                    }
                }
                else
                {
                    bottom_index++;
                    while (requests[i] >= requests[bottom_index] + 1000)
                    {
                        concurrent--;
                        bottom_index++;
                    }
                }
            }

            int result = (int) Math.Ceiling((double) max_concurrent/k);
            Console.WriteLine(result);
        }
    }
}