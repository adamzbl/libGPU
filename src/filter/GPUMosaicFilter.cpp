//
//  GPUMosaicFilter.cpp
//  libGPU
//
//  Created by zhoubl on 2017/7/27.
//  Copyright © 2017年 Rex. All rights reserved.
//

#include "GPUMosaicFilter.h"

const static char* g_mosaic_fragment_shader = SHADER_STRING (
   uniform sampler2D inputImageTexture;
   varying vec2 textureCoordinate;
   uniform float texWidth;
   uniform float texHeight;
   uniform float mosaicSizeX;
   uniform float mosaicSizeY;

   void main(void)
   {
     vec4 color;
     vec2 xy = vec2(textureCoordinate.x * texWidth, textureCoordinate.y * texHeight);
     
     vec2 xyMosaic = vec2(floor(xy.x / mosaicSizeX) * mosaicSizeX,
                          floor(xy.y / mosaicSizeY) * mosaicSizeY );
     
     vec2 xyFloor = vec2(floor(mod(xy.x, mosaicSizeX)),
                         floor(mod(xy.y, mosaicSizeY)));
     {  
       vec2 uvMosaic = vec2(xyMosaic.x / texWidth, xyMosaic.y / texHeight);
       color = texture2D( inputImageTexture, uvMosaic );
     }  
     
     gl_FragColor = color;  
   }

);

GPUMosaicFilter::GPUMosaicFilter(float width, float height, float size):GPUFilter(g_mosaic_fragment_shader){
  setFloat("texWidth", width);
  setFloat("texHeight", height);
  setFloat("mosaicSizeX", size);
  setFloat("mosaicSizeY", size);
}

void GPUMosaicFilter::setExtraParameter(float p) {
  setFloat("mosaicSizeX", p);
  setFloat("mosaicSizeY", p);
}
