using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PointOfSaleTerminal
{
    class PriceManager
    {
        private Logger _logger = new Logger("PriceManager");
        private Dictionary<string, Item> _items = new Dictionary<string, Item>();

        public void SetPricing( string priceFilename )
        {
            string line;
            System.IO.StreamReader priceFile = new System.IO.StreamReader(priceFilename);
            while ((line = priceFile.ReadLine()) != null)
            {
                string[] tokens = line.Split(new string[] { ":" }, StringSplitOptions.RemoveEmptyEntries);

                if (4 == tokens.Length)
                {
                    double singlePrice = double.Parse(tokens[1]);
                    double volPrice = double.Parse(tokens[3]);
                    _items.Add( tokens[0], new Item( 
                        tokens[0], singlePrice, volPrice, UInt32.Parse(tokens[2]) ));
                }
                else if (2 == tokens.Length)
                {
                    _items.Add(tokens[0], new Item(
                        tokens[0], double.Parse(tokens[1]), double.Parse(tokens[1]), 1));
                }
            }
        }

        public bool HasPrice(string productCode)
        {
            bool found = false;
            if (_items.ContainsKey(productCode))
            {
                found = true;
            }
            return found;
        }

        public UInt32 GetVolumeQuantity(string productCode)
        {
            UInt32 volumeQuantity = 0;
            if (HasPrice(productCode))
            {
                volumeQuantity = _items[productCode].GetVolumeQuantity();
            }
            return volumeQuantity;
        }

        public double GetVolumePrice(string productCode)
        {
            double price = 0;
            if (HasPrice(productCode))
            {
                price = _items[productCode].GetVolumePrice();
            }
            return price;
        }

        public double GetSingleUnitPrice(string productCode)
        {
            double price = 0;
            if (HasPrice(productCode))
            {
                price = _items[productCode].GetSingleUnitPrice();
            }
            return price;
        }
    }
}
