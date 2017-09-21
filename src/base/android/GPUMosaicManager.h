//
//  GPUMosaicManager.hpp
//  example
//
//  Created by zhoubl on 2017/9/21.
//  Copyright © 2017年 Rex. All rights reserved.
//

#ifndef GPUMosaicManager_hpp
#define GPUMosaicManager_hpp

#include "GPU.h"

class GPUMosaicManager {
public:
  GPUMosaicManager(const char * path);
  GPUMosaicManager(const uint8_t* rawData, uint32_t size);

  ~GPUMosaicManager() {
    clearProgram();
  }
  unsigned char* getMosaicBuffer();
protected:
  GPUPicture *pic;
  GPUMosaicFilter *mosaic;
  GPURawOutput *output;
  void setupProgram();
  void clearProgram();
};

#endif /* GPUMosaicManager_hpp */
