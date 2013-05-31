package com.sandbox;

public class Item
{
    private String productCode;
    private Double singlePrice;
    private Double volumePrice;
    private Integer volumeQuantity;
    
    public Item( String productCodeIn, Double singlePriceIn, Double volumePriceIn, Integer volumeQuanityIn )
    {
        productCode = productCodeIn;
        singlePrice = singlePriceIn;
        volumePrice = volumePriceIn;
        volumeQuantity = volumeQuanityIn;
    }
    
    public String getProductCode()
    {
        return productCode;
    }
    
    public Double getSingleUnitPrice()
    {
        return singlePrice;
    }
    
    public Double getVolumeUnitPrice()
    {
        return volumePrice;
    }
    
    public Integer getVolumeQuantity()
    {
        return volumeQuantity;
    }
}
