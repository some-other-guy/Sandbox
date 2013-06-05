#ifndef POINTOFSALETERMINAL_H_
#define POINTOFSALETERMINAL_H_

#include <map>
#include <string>
#include <stdint.h>

#include "PricingManager.h"

class PointOfSaleTerminal
{
public:
    PointOfSaleTerminal();
    virtual ~PointOfSaleTerminal();

    // Interface method to set the pricing in the Pricing Manager
    void setPricing( std::string priceFileName );
    
    // Interface call to scan the provided product code.
    // If the product code does not have any price information it is not added to the map of scanned items.
    // Returns true if the item is added to the map, false otherwise.
    bool scan( std::string item );
    
    // Returns the total of all items scanned into the scanned items map.
    // If volume pricing information is available for a product code it is applied in this method.
    double calculateTotal();

private:
    Logger _logger;
    PricingManager _prices;
    std::map<std::string, uint32_t> _scannedItems;
};


#endif /* POINTOFSALETERMINAL_H_ */
