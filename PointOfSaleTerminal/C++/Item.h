#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <stdint.h>

class Item
{
public:
    Item( std::string productCodeIn, double singlePriceIn, double volumePriceIn, uint32_t volumeQuantityIn );
    virtual ~Item(){}

    // Returns the stored single unit price
    double getSingleUnitPrice() const;
    
    // returns the storeed volume price
    double getVolumeUnitPrice() const;
    
    // returns the stored volume quantity
    uint32_t getVolumeQuantity() const;

private:
    std::string _productCode;
    double _singlePrice;
    double _volumePrice;
    uint32_t _volumeQuantity;
};

#endif /* ITEM_H_ */
