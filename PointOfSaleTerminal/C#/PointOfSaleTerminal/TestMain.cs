using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PointOfSaleTerminal
{
    class TestMain
    {
        static void Main( string[] args )
        {
            if (1 != args.Length)
            {
                System.Console.WriteLine("Usage: PointOfSaleTernimal <command file>");
            }
            else
            {
                PointOfSaleTerminal terminal = new PointOfSaleTerminal();
                System.IO.StreamReader priceFile = new System.IO.StreamReader(args[0]);
                string line = priceFile.ReadLine();
                if (null != line)
                {
                    terminal.SetPricing(line);
                    while ((line = priceFile.ReadLine()) != null)
                    {
                        terminal.Scan(line);
                    }
                }
                System.Console.WriteLine("Total sale: $" + terminal.CalculateTotal());
            }
        }
    }
}
