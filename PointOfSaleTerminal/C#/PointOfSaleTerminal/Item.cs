using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PointOfSaleTerminal
{
    class Item
    {
        private string _productCode;
        private double _singleUnitPrice;
        private double _volumePrice;
        private UInt32 _volumeQuantity;

        public Item(string productCodeIn, double singlePriceIn, double volumePriceIn, UInt32 volumeQuantityIn)
        {
            _productCode = productCodeIn;
            _singleUnitPrice = singlePriceIn;
            _volumePrice = volumePriceIn;
            _volumeQuantity = volumeQuantityIn;
        }

        public double GetSingleUnitPrice()
        {
            return _singleUnitPrice;
        }

        public double GetVolumePrice()
        {
            return _volumePrice;
        }

        public UInt32 GetVolumeQuantity()
        {
            return _volumeQuantity;
        }
    }
}
