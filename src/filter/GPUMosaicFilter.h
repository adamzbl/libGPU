/**
 * file :	GPUMosaicFilter_h
 * author :	zhoubl
 * create :	2017-07-27 09:59
 * func :   马赛克滤镜
 * history:
 */


#ifndef GPUMosaicFilter_h
#define GPUMosaicFilter_h

#include "GPUFilter.h"

class GPUMosaicFilter : public GPUFilter {
public:
  GPUMosaicFilter(float width = 640, float height = 640, float size = 80.0);
  virtual void setExtraParameter(float p);
};
#endif /* GPUMosaicFilter_h */
