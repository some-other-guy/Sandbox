#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>

#include "PricingManager.h"

PricingManager::PricingManager() : _logger( "PricingManager" )
{

}

PricingManager::~PricingManager()
{
    _items.erase( _items.begin(), _items.end() );
}

void PricingManager::setPrices( std::string priceFileName )
{
    // stub for now to test rest of the logic
    if( !priceFileName.empty() )
    {
        std::ifstream priceFile( priceFileName.c_str() );
        if( priceFile.is_open() )
        {
            while( !priceFile.eof() )
            {
                std::string tmpStr;
                getline( priceFile, tmpStr );
                std::vector<std::string> tokens;
                splitString( tmpStr, tokens );

                // The tokens returned from the split should be either 2 or 4
                // if there are different numbers then the file was incorrect
                if( tokens.size() == 4 )
                {
                    double singlePrice = atof( tokens[1].c_str() );
                    double volumePrice = atof( tokens[3].c_str() );
                    uint32_t volumeQuantity = atoi( tokens[2].c_str() );
                    _items[tokens[0]] = new Item( tokens[0], singlePrice, volumePrice, volumeQuantity );
                }
                else if( tokens.size() == 2 )
                {
                    // if no volume information is provided then we set the volume price to the single price 
                    // and the volume quantity to 1.
                    double singlePrice = atof( tokens[1].c_str() );
                    _items[tokens[0]] = new Item( tokens[0], singlePrice, singlePrice, 1 );
                }
            }
        }
        else
        {
            _logger.Log( "unable to open pricing file - no product pricing was added" );
        }
    }
}

bool PricingManager::hasPrice( std::string productCode )
{
    bool found = false;
    if( _items.end() != _items.find( productCode ))
    {
        found = true;
    }
    return found;
}

uint32_t PricingManager::getVolumeQuantity( std::string productCode )
{
    uint32_t volQuantity = 0;
    if( _items.end() != _items.find( productCode ))
    {
        volQuantity = _items[productCode]->getVolumeQuantity();
    }
    return volQuantity;
}

double PricingManager::getVolumeUnitPricing( std::string productCode )
{
    double volPrice = 0.0;
    if( _items.end() != _items.find( productCode ))
    {
        volPrice = _items[productCode]->getVolumeUnitPrice();
    }
    return volPrice;
}

double PricingManager::getSingleUnitPriceing( std::string productCode )
{
    double singlePrice = 0.0;
    if( _items.end() != _items.find( productCode ))
    {
        singlePrice = _items[productCode]->getSingleUnitPrice();
    }
    return singlePrice;
}

void PricingManager::splitString( std::string input, std::vector<std::string>& tokens )
{
    uint32_t start = 0;
    uint32_t stop = input.find( ":" );
    while( start < input.length() )
    {
        tokens.push_back( input.substr( start, stop - start ));
        //_logger.Log( input.substr( start, stop - start ));
        start = stop + 1;
        stop = input.find( ":", start );
        if( stop == input.npos )
        {
            stop = input.length();
        }
    }
}
