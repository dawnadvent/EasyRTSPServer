#pragma once


#include "getsps.h"
#include "EasyRTSPClient/EasyRTSPClientAPI.h"
#include "EasyRTSPServer/EasyRtspServerAPI.h"
#include <time.h>
#ifdef _WIN32
//===============Windows==============
#if 1
//32λ����ʹ��Win32�ļ��������ӿ�
#pragma comment(lib, "EasyRTSPClient/Win32/libEasyRTSPClient.lib")
#pragma comment(lib, "EasyRTSPServer/Win32/libEasyRTSPServer.lib")
#else
//64λ����ʹ��Win64�ļ��������ӿ�
#pragma comment(lib, "EasyRTSPClient/Win64/libEasyRTSPClient.lib")
#pragma comment(lib, "EasyRTSPServer/Win64/libEasyRTSPServer.lib")
#endif
#else
//===============Linux=================
#include <unistd.h>
#define	Sleep(x)	{usleep(x*1000);}
#endif

#ifdef _WIN32
static const char *RTSPCLIENT_LIC =	"6D75724D7A4969576B5A75414B304A646F723355512B314659584E35556C525455454E73615756756443356C65475673567778576F502F442F69426C59584E35";
static const char *RTSPSERVER_LIC =	"243AE7D5A4A727B5D3264F530D2C51A43830324335463544323630303030303031373030303030303435363137333739353337343732363536313644363936453637353336353732373636353732324536353738363538303241323535443035303030303030363336463644373033313739373336313635";
#else
static const char *RTSPCLIENT_LIC =	"6D75724D7A4A4F576B5971414B304A646F723355512F4A6C59584E35636E527A634778705A573530567778576F502F442F69426C59584E35";
static const char *RTSPSERVER_LIC =	"A6229FBB84748D1781AFDCF7EC24EABF3830324335463544323630303030303031373030303030303435363137333739353337343732363536313644363936453637353336353732373636353732324536353738363538303241323535443035303030303030363336463644373033313739373336313635";
#endif


typedef struct __RTSP_CHANNEL_T
{
	char		url[256];
	char		resourcename[256];
	char		username[36];
	char		password[36];
	
	EASY_RTSPSERVER_MEDIA_INFO_T		mediaInfo;		//Դý����Ϣ

	Easy_Handle	rtspClientHandle;			//rtsp�ͻ��˾��

	int			status;		//
	EASY_CHANNEL_HANDLE	channelHandle;
}RTSP_CHANNEL_T;





class EasyStreamingServer
{
public:
	EasyStreamingServer(void);
	~EasyStreamingServer(void);

	int		Startup(int rtspPort);
	void	Shutdown();

	void	ResetChannel(int channelId);
};

