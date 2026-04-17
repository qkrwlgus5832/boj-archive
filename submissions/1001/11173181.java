using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string[] values = s.Split(' ');
            int a = int.Parse(values[0]);
            int b = int.Parse(values[1]);
            Console.WriteLine(a - b);
        }
    }
}
