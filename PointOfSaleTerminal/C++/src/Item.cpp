#include "Item.h"

Item::Item( std::string productCodeIn, double singlePriceIn, double volumePriceIn, uint32_t volumeQuantityIn ) :
    _productCode( productCodeIn ), _singlePrice( singlePriceIn ), _volumePrice( volumePriceIn ), _volumeQuantity( volumeQuantityIn )
{

}

double Item::getSingleUnitPrice() const
{
    return _singlePrice;
}

double Item::getVolumeUnitPrice() const
{
    return _volumePrice;
}

uint32_t Item::getVolumeQuantity() const
{
    return _volumeQuantity;
}
