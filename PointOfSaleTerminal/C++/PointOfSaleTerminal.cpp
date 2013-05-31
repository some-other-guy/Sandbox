#include <sstream>

#include "PointOfSaleTerminal.h"

PointOfSaleTerminal::PointOfSaleTerminal() : _logger( "PointOfSaleTerminal" )
{
}

PointOfSaleTerminal::~PointOfSaleTerminal()
{
    _scannedItems.erase( _scannedItems.begin(), _scannedItems.end() );
}

void PointOfSaleTerminal::setPricing( std::string priceFileName )
{
    _prices.setPrices( priceFileName );
}

bool PointOfSaleTerminal::scan( std::string item )
{
    bool scanned = false;
    
    // first check that item is not empty
    if( !item.empty() )
    {
        // and has pricing information
        if( _prices.hasPrice( item ))
        {
            // check if there is a previous entry for this item
            if( _scannedItems.end() != _scannedItems.find( item ))
            {
                _scannedItems[item] += 1;
            }
            else    // add as the first scan of this item
            {
                _scannedItems[item] = 1;
            }
            scanned = true;
            std::stringstream ss;
            ss << "Scanned Product Code: " << item;
            _logger.Log( ss.str() );        
        }
        else
        {
            std::stringstream ss;
            ss << "Invalid Product Code: " << item;
            _logger.Log( ss.str() );
        }
    }
    return scanned;
}

double PointOfSaleTerminal::calculateTotal()
{
    std::map<std::string, uint32_t>::iterator itr = _scannedItems.begin();
    std::map<std::string, uint32_t>::iterator itrEnd = _scannedItems.end();
    double total = 0.0;

    for( ; itr != itrEnd; ++itr )
    {
        // if the number scanned for this item is greater then the volume quantity for this product code
        // then take into account the volume pricing
        uint32_t volumeQuantity = _prices.getVolumeQuantity( itr->first );
        if( 1 < volumeQuantity && ( itr->second >= volumeQuantity ))
        {
            // calculate how many times we need to count the volume pricing vs single pricing
            uint32_t singleUnits = itr->second % volumeQuantity;
            uint32_t volumeUnits = ( itr->second - singleUnits ) / volumeQuantity;

            total += volumeUnits * _prices.getVolumeUnitPricing( itr->first );
            total += singleUnits * _prices.getSingleUnitPriceing( itr->first );
        }
        else
        {
            total += itr->second * _prices.getSingleUnitPriceing( itr->first );
        }
    }
    return total;
}
