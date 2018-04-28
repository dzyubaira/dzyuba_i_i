using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Diagnostics;

namespace paral_17._03
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch watch1 = new Stopwatch();
            watch1.Start();
            Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture("en");
            var lines1 = File.ReadAllLines(@"C:\Users\User\Desktop\parfor\parfor\matrix.csv");
            double[,] a1 = new double[lines1.Length, lines1.Length];
            int i = 0;
            foreach (string line in lines1)
            {
                string[] line_s = line.Split(',');
                int j = 0;
                foreach (string str in line_s)
                {
                    a1[i, j] = Double.Parse(str, CultureInfo.InvariantCulture);
                    ++j;
                }
                ++i;
            }
            i = 0;
            var lines2 = File.ReadAllLines(@"C:\Users\User\Desktop\parfor\parfor\matrix.csv");
            double[,] a2 = new double[lines1.Length, lines1.Length];
            foreach (string line in lines1)
            {
                string[] line_s = line.Split(',');
                int j = 0;
                foreach (string str in line_s)
                {
                    a2[i, j] = Double.Parse(str, CultureInfo.InvariantCulture);
                    ++j;
                }
                ++i;
            }
            watch1.Stop();
            Console.WriteLine("Матрицы считаны: {0}", watch1.ElapsedMilliseconds.ToString());

            Stopwatch watch12 = new Stopwatch();
            watch12.Start();
            double[,] a12 = new double[lines1.Length, lines2.Length];
            for (i = 0; i < lines1.Length; i++)
            {
                for (int j = 0; j < lines2.Length; j++)
                {
                    a12[i, j] = 0;
                    for (int k = 0; k < lines1.Length; k++)
                        a12[i, j] += a1[i, k] * a2[k, j];
                }
            }
            watch12.Stop();
            Console.WriteLine("Матрицы перемножены последовательно: {0}", watch12.ElapsedMilliseconds.ToString());

            Stopwatch watch2 = new Stopwatch();
            watch2.Start();
            double[,] a3 = new double[lines1.Length, lines2.Length];
            Parallel.For(0, lines1.Length, (l) =>
            {
                for (int j = 0; j < lines2.Length; j++)
                {
                    a3[l, j] = 0;
                    for (int k = 0; k < lines1.Length; k++)
                        a3[l, j] += a1[l, k] * a2[k, j];
                }
            }
            );
            watch2.Stop();
            Console.WriteLine("Матрицы перемножены параллельно: {0}", watch2.ElapsedMilliseconds.ToString());
            Stopwatch watch3 = new Stopwatch();
            watch3.Start();
            string first_line = a3[0, 0].ToString();
            for (i = 1; i < lines1.Length; ++i)
            {
                first_line = first_line + "," + a3[0, i].ToString();
            }
            File.WriteAllText(@"C:\Users\User\Desktop\matrix\lab3.csv", first_line);
            watch3.Stop();
            Console.WriteLine("Результирующая матрица записана: {0}", watch3.ElapsedMilliseconds.ToString());
        }
    }
}
