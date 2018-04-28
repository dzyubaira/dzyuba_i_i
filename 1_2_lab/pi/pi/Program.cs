using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.IO;

namespace pi
{
    class Program
    {
        static List<double> pil = new List<double>();

        static void MonteKarlo(object num)
        {
            int nump = (int)num;
            double pi;
            double ncir = 0;
            Random r = new Random();
            for (int i = 0; i < nump; i++)
            {
                double x = r.NextDouble();
                double y = r.NextDouble();
                if ((x * x + y * y) <= 1.0)
                {
                    ncir++;
                }
            }
            pi = (4 * ncir) / nump;
            pil.Add(pi);
        }

        static void Main(string[] args)
        {
            int numt;
            int num;
            Console.WriteLine("Количество потоков: ");
            numt = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Количество точек: ");
            num = Convert.ToInt32(Console.ReadLine());
            Thread[] thr = new Thread[num];
            for (int i = 0; i < numt; i++)
            {
                thr[i] = new Thread(new ParameterizedThreadStart(MonteKarlo));
                thr[i].Start(num);
            }
            for (int i = 0; i < numt; i++)
            {
                thr[i].Join();
            }
            Console.WriteLine("Среднее значение pi: {0}", pil.Average());
            Console.ReadKey();
        }
    }
}
