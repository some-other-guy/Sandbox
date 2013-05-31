package com.sandbox;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class PointOfSaleTerminal
{
    private PriceManager prices = new PriceManager();
    private Logger logger = new Logger( "PointOfSaleTerminal" );
    private Map<String, Integer> scannedItems = new HashMap<String, Integer>();
    
    public PointOfSaleTerminal()
    {
        
    }
    
    // Interface method to set the pricing in the Pricing Manager
    public void setPricing( String priceFileName )
    {
        prices.setPrices( priceFileName );
    }
    
    // Interface call to scan the provided product code.
    // If the product code does not have any price information it is not added to the map of scanned items.
    // Returns true if the item is added to the map, false otherwise.
    public Boolean scan( String item )
    {
        Boolean scanned = false;
        
        // Check if the item is not empty
        if( !item.isEmpty() )
        {
            // and has pricing information
            if( prices.hasPrice( item ))
            {
                // Check if there is a previous entry for this item
                if( null != scannedItems.get( item ))
                {
                    scannedItems.put( item, scannedItems.get(item) + 1 );
                }
                else
                {
                    scannedItems.put( item, 1 );
                }
                logger.Log( "Scanned Product Code: " + item );
            }
            else
            {
                logger.Log( "Invalid Product Code: " + item );
            }
        }
        return scanned;
    }
    
    // Returns the total of all items scanned into the scanned items map.
    // If volume pricing information is available for a product code it is applied in this method.
    public Double calculateTotal()
    {
        Double total = 0.0;
        Set<Entry<String, Integer>> set = scannedItems.entrySet();
        Iterator<Entry<String, Integer>> itr = set.iterator();
        while( itr.hasNext() )
        {
            // if the number scanned for this item is greater then the volume quantity for this product code
            // then take into account the volume pricing
            Map.Entry<String, Integer> item = itr.next();
            Integer volQuantity = prices.getVolumeQuantity( item.getKey() );
            
            if( 1 < volQuantity && ( item.getValue() >= volQuantity ))
            {
                // calculate how many times we need to count the volume pricing vs single pricing
                Integer singleUnits = item.getValue() % volQuantity;
                Integer volUnits = ( item.getValue() - singleUnits ) / volQuantity;
                
                total += volUnits * prices.getVolumeUnitPricing( item.getKey() );
                total += singleUnits * prices.getSingleUnitPriceing( item.getKey() );
            }
            else
            {
                total += item.getValue() * prices.getSingleUnitPriceing( item.getKey() );
            }
        }
        return total;
    }
}
