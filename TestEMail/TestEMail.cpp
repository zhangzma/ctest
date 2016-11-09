// TestEMail.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TestEMail.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

void testMail2();

#include "SMailer/SMailer/SMailer.h"
#include "SMailer/MUtils/WinSockHelper.h"

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 更改错误代码以符合您的需要
			_tprintf(_T("错误: MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: 在此处为应用程序的行为编写代码。
		}
	}
	else
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: GetModuleHandle 失败\n"));
		nRetCode = 1;
	}


	testMail2();
	//testMail();



	return nRetCode;
}


#include "CSendMail/CSendMail.h"
void testMail2()
{
	sMailInfo sm;
	sm.m_pcUserName = "这里是QQ号码";//"";
	sm.m_pcUserPassWord ="这里是QQ密码";// "";
	sm.m_pcSenderName = "爱说话的汤姆猫";
	sm.m_pcSender = "snifferzhu@qq.com";//发送者的邮箱地址  
	sm.m_pcReceiver = "w_izard@qq.com";//接收者的邮箱地址  
	sm.m_pcTitle = "测试垃圾邮件";//邮箱标题  
	sm.m_pcBody = "你想快速发家致富吗？你想一夜成名吗？访问 http://www.sb.com";//邮件文本正文  
	sm.m_pcIPAddr = "" ;//服务器的IP可以留空 
	sm.m_pcIPName ="smtp.qq.com" ;//服务器的名称（IP与名称二选一，优先取名称）  

	CSendMail csm;
	while(TRUE)
	{
		csm.SendMail(sm);
		Sleep(1000 * 20);
	}
	
}