#ifndef __FFPLAYER_PKTQUEUE_H__
#define __FFPLAYER_PKTQUEUE_H__

// ����ͷ�ļ�
#include "stdefine.h"

#ifdef __cplusplus
extern "C" {
#endif

// avformat.h
#include "libavformat/avformat.h"

// ��������
void* pktqueue_create (int   size);
void  pktqueue_destroy(void *ctxt);
void  pktqueue_reset  (void *ctxt);

int   pktqueue_write_request (void *ctxt, AVPacket **pppkt);
void  pktqueue_write_cancel  (void *ctxt);
void  pktqueue_write_post_a  (void *ctxt);
void  pktqueue_write_post_v  (void *ctxt);

int   pktqueue_read_request_a(void *ctxt, AVPacket **pppkt);
void  pktqueue_read_post_a   (void *ctxt);

int   pktqueue_read_request_v(void *ctxt, AVPacket **pppkt);
void  pktqueue_read_post_v   (void *ctxt);

#ifdef __cplusplus
}
#endif

#endif





