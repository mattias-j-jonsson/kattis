using System;

class dagatal
{
    static void Main(string[] argv)
    {
        int number = 0;
        string input = Console.ReadLine();
        if(int.TryParse(input, out number) == false || number < 1 || number > 12)
        {
            Console.WriteLine("only an integer 1 <= m <= 12 is acceptable as argument");
            return;
        }
        int result = 0;
        switch (number)
        {
            case 2:
                result = 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                result = 30;
                break;
            default:
                result = 31;
                break;
        }
        Console.WriteLine(result);
    }
}