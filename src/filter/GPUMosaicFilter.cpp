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
   const vec2 mosaicSize = vec2(20., 20.);
   
   void main(void)
   {
     vec4 color;
     vec2 xy = vec2(textureCoordinate.x * texWidth, textureCoordinate.y * texHeight);
     
     vec2 xyMosaic = vec2(floor(xy.x / mosaicSize.x) * mosaicSize.x,
                          floor(xy.y / mosaicSize.y) * mosaicSize.y );
     
     vec2 xyFloor = vec2(floor(mod(xy.x, mosaicSize.x)),
                         floor(mod(xy.y, mosaicSize.y)));
     {  
       vec2 uvMosaic = vec2(xyMosaic.x / texWidth, xyMosaic.y / texHeight);
       color = texture2D( inputImageTexture, uvMosaic );
     }  
     
     gl_FragColor = color;  
   }

);

GPUMosaicFilter::GPUMosaicFilter(float width, float height):GPUFilter(g_mosaic_fragment_shader){
  setFloat("texWidth", width);
  setFloat("texHeight", height);
}
