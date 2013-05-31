package com.sandbox;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class PriceManager
{
    private Logger logger = new Logger( "PriceManager" );
    private Map<String, Item> items = new HashMap<String, Item>();
        
    public PriceManager()
    {
       
    }
    
    public void setPrices( String priceFileName )
    {
        BufferedReader buffer;
        try
        {
            buffer = new BufferedReader( new FileReader( priceFileName ));
            String line;
            while(( line = buffer.readLine() ) != null )
            {
                String[] tokens = line.split( ":" );
                
                if( tokens.length == 4 )
                {
                    Double singlePrice = Double.parseDouble( tokens[1] );
                    Double volumePrice = Double.parseDouble( tokens[3] );
                    Integer volumeQuantity = Integer.parseInt( tokens[2] );
                    items.put( tokens[0], new Item( tokens[0], singlePrice, volumePrice, volumeQuantity ));
                }
                else if( tokens.length == 2 )
                {
                    Double singlePrice = Double.parseDouble( tokens[1] );
                    items.put( tokens[0], new Item( tokens[0], singlePrice, singlePrice, 1 ));
                }
            }
        } 
        catch( FileNotFoundException e )
        {
            logger.Log( e.getMessage() );
        } 
        catch( IOException e )
        {
            logger.Log( e.getMessage() );
        }
    }

    // Returns true if there is an entry in the _items map for the provided product code.
    Boolean hasPrice( String productCode )
    {
        Boolean found = false;
        
        Item item = items.get( productCode );
        if( item != null )
        {
            found = true;
        }
        return found;
    }

    // Returns the number of items to apply volume pricing to if there is a mapping for the product code.
    // Otherwise returns 1.
    Integer getVolumeQuantity( String productCode )
    {
        Integer volQuantity = 0;
        
        Item item = items.get( productCode );
        if( item != null )
        {
            volQuantity = item.getVolumeQuantity();
        }
        return volQuantity;
    }
    
    // Returns the volume price if there is a mapping for the product code.
    // Otherwise returns 0.0.
    Double getVolumeUnitPricing( String productCode )
    {
        Double volPrice = 0.0;
        
        Item item = items.get( productCode );
        if( item != null )
        {
            volPrice = item.getVolumeUnitPrice();
        }
        return volPrice;
    }
    
    // Returns the single unit price if there is a mapping for the product code.
    // Otherwise returns 0.0.
    Double getSingleUnitPriceing( String productCode )
    {
        Double singlePrice = 0.0;
        
        Item item = items.get( productCode );
        if( item != null )
        {
            singlePrice = item.getSingleUnitPrice();
        }
        return singlePrice;
    }
}
