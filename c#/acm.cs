using System.IO;
using System;
using System.Collections.Generic;

class acm
{
    static void Main(string[] argv)
    {
        // StreamReader reader = new StreamReader("1.in");
        
        string[] temp;
        temp = Console.ReadLine().Split(' ');
        // temp = reader.ReadLine().Split(' ');
        int number_problems = int.Parse(temp[0]);
        int first_problem = int.Parse(temp[1]);
        temp = Console.ReadLine().Split(' ');
        // temp = reader.ReadLine().Split(' ');
        List<int> problems = new List<int>();
        for (int i = 0; i < number_problems; i++)
        {
            problems.Add(int.Parse(temp[i]));
        }

        int problems_solved = 0;
        int time_pool = 300;
        int penalty = problems[first_problem];
        time_pool -= penalty;
        if (time_pool >= 0)
        {
            problems_solved++;
        }

        problems.RemoveAt(first_problem);
        problems.Sort();
        while (time_pool >= 0 && problems.Count > 0)
        {
            time_pool -= problems[0];
            if(time_pool >= 0)
            {
                problems_solved++;
                penalty += 300 - time_pool;
            }
            problems.RemoveAt(0);
        }

        penalty = (problems_solved > 0 ? penalty : 0);
        Console.WriteLine($"{problems_solved} {penalty}");
    }
}