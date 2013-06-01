using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PointOfSaleTerminal
{
    class PointOfSaleTerminal
    {
        private Logger _logger = new Logger( "PointOfSaleTernimal" );
        private PriceManager _prices = new PriceManager();
        private Dictionary<string, UInt32> _scannedItems = new Dictionary<string,uint>();

        public void SetPricing( string priceFilename )
        {
            _prices.SetPricing(priceFilename);
        }

        public bool Scan( string productCode )
        {
            bool scanned = false;
            if (string.Empty != productCode)
            {
                if (_prices.HasPrice(productCode))
                {
                    if (_scannedItems.ContainsKey(productCode))
                    {
                        _scannedItems[productCode] += 1;
                    }
                    else
                    {
                        _scannedItems[productCode] = 1;
                    }
                    _logger.Log("Scanned Product Code: " + productCode);
                }
                else
                {
                    _logger.Log("Invalid Product Code: " + productCode);
                }
            }
            return scanned;
        }

        public double CalculateTotal()
        {
            double result = 0.0;
            foreach (KeyValuePair<string, UInt32> entry in _scannedItems)
            {
                UInt32 volQuantity = _prices.GetVolumeQuantity(entry.Key);
                if (1 < volQuantity && entry.Value >= volQuantity)
                {
                    UInt32 singleUnits = entry.Value % volQuantity;
                    UInt32 volUnits = (entry.Value - singleUnits) / volQuantity;

                    double singlePrice = _prices.GetSingleUnitPrice(entry.Key);
                    double volPrice = _prices.GetVolumePrice(entry.Key);

                    result += volUnits * volPrice;
                    result += singleUnits * singlePrice;
                }
                else
                {
                    result += entry.Value * _prices.GetSingleUnitPrice(entry.Key);
                }
            }
            return result;
        }
    }
}
