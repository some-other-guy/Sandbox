#ifndef PRICINGMANAGER_H_
#define PRICINGMANAGER_H_

#include <map>
#include <vector>

#include "Item.h"
#include "Logger.h"

class PricingManager
{
public:
    PricingManager();
    virtual ~PricingManager();

    // Reads in the priceFileName and loads the information into Item objects that are stored in a 
    // std::map ( _items ) using the product code as the key.
    void setPrices( std::string priceFileName );

    // Returns true if there is an entry in the _items map for the provided product code.
    bool hasPrice( std::string productCode );

    // Returns the number of items to apply volume pricing to if there is a mapping for the product code.
    // Otherwise returns 1.
    uint32_t getVolumeQuantity( std::string productCode );
    
    // Returns the volume price if there is a mapping for the product code.
    // Otherwise returns 0.0.
    double getVolumeUnitPricing( std::string productCode );
    
    // Returns the single unit price if there is a mapping for the product code.
    // Otherwise returns 0.0.
    double getSingleUnitPriceing( std::string productCode );

private:
    Logger _logger;
    std::map<std::string, Item*> _items;

    // Utility method to tokenize a string for price information
    void splitString( std::string input, std::vector<std::string>& tokens );
};

#endif /* PRICINGMANAGER_H_ */
