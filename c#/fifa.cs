using System;

namespace fifa
{
    class Program
    {
        static void Main()
        {
            uint n = uint.Parse(Console.ReadLine());
            uint k = uint.Parse(Console.ReadLine());

            uint result = 2022 + n/k;
            Console.WriteLine(result);
        }
    }
}