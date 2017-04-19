#ifndef __FFPLAYER_HWACCEL_H__
#define __FFPLAYER_HWACCEL_H__

#ifdef __cplusplus
extern "C" {
#endif

// ����ͷ�ļ�
#include "libavcodec/avcodec.h"

// ��������
void hwaccel_init(AVCodecContext *ctxt, int hwaccel);
void hwaccel_free(AVCodecContext *ctxt);

#ifdef __cplusplus
}
#endif

#endif


