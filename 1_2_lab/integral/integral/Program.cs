using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;


namespace integral
{
    class Program
    {
        static double l;
        static double r;
        static double h;
        static int numt;
        static double[] S;
        static bool norm;

        static void Main(string[] args)
        {
            norm = false;

            while (norm != true)
            {
                Console.WriteLine("Левая граница:");
                l = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("Правая граница:");
                r = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("Шаг дискретизации:");
                h = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("Количество потоков:");
                numt = Convert.ToInt32(Console.ReadLine());
                if (numt > 0 && r > l && h <= r - l && l > 0)
                    norm = true;
                else
                {
                    if (l <= 0)
                        Console.WriteLine("Невозможно вычислить логарифм от отрицательного числа или от нуля");
                    if (numt <= 0)
                        Console.WriteLine("Потоков не может быть меньше 0.");
                    if (l > r)
                        Console.WriteLine("Левая граница не должна быть больше правой.");
                    if (h > r - l)
                        Console.WriteLine("Шаг дискретизации не должен быть больше заданного интервала.");
                }
            }

            S = new double[numt];
            Task[] Tasks = new Task[numt];
            int j = 0;
            for (int i = 0; i < numt; i++)
            {
                Tasks[i] = Task.Run(() => Thread(j++));
            }
            for (int i = 0; i < numt; i++)
            {
                Tasks[i].Wait();
            }
            Console.WriteLine("Значение интеграла: {0}", S.Sum());
            Console.ReadLine();
        }

        static void Thread(int i)
        {
            double length = (r - l) / numt; 
            double start, finish;
            start = l + i * length;
            finish = start + length;
            int n = (int)((finish - start) / h);
            double sum = 0, x1, x2;
            for (int j = 0; j < n; j++)
            {
                x1 = start + j * h;
                x2 = start + (j + 1) * h;
                sum += h * (Math.Log(x1) + Math.Log(x2)) / 2;
            }
            S[i] = sum;
        }
    }
}
