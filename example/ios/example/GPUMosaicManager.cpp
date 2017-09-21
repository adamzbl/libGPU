//
//  GPUMosaicManager.cpp
//  example
//
//  Created by zhoubl on 2017/9/21.
//  Copyright © 2017年 Rex. All rights reserved.
//

#include "GPUMosaicManager.h"

GPUMosaicManager::GPUMosaicManager(const char * path)
{
  pic = new GPUPicture(path);
  setupProgram();
}

GPUMosaicManager::GPUMosaicManager(const uint8_t* rawData, uint32_t size)
{
  pic = new GPUPicture(rawData, size);
  setupProgram();
}


void GPUMosaicManager::setupProgram()
{
  mosaic = new GPUMosaicFilter(pic->m_image_size.width,pic->m_image_size.height);
  output = new GPURawOutput();
  
  pic->addTarget(mosaic);
  mosaic->addTarget(output);
  pic->processImage();
}

unsigned char* GPUMosaicManager::getMosaicBuffer()
{
  return output->getBuffer();
}

void GPUMosaicManager::clearProgram()
{
  output->removeAllSources();
  delete output;
  mosaic->removeAllTargets();
  delete mosaic;
  pic->removeAllTargets();
  delete pic;
}
