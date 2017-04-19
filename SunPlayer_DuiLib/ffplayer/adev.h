#ifndef __FFPLAYER_ADEV_H__
#define __FFPLAYER_ADEV_H__

// ����ͷ�ļ�
#include "ffrender.h"

#ifdef __cplusplus
extern "C" {
#endif

#if 0
// ���Ͷ���
typedef struct {
    BYTE  *lpdata;
    DWORD  buflen;
} AUDIOBUF;
#endif

// ��������
void* adev_create  (int type, int bufnum, int buflen);
void  adev_destroy (void *ctxt);
void  adev_request (void *ctxt, AUDIOBUF **ppab);
void  adev_post    (void *ctxt, int64_t pts);
void  adev_pause   (void *ctxt, int pause);
void  adev_reset   (void *ctxt);
void  adev_syncapts(void *ctxt, int64_t *apts);
void  adev_curdata (void *ctxt, void **buf, int *len );
void  adev_setparam(void *ctxt, DWORD id, void *param);
void  adev_getparam(void *ctxt, DWORD id, void *param);

#ifdef __cplusplus
}
#endif

#endif

