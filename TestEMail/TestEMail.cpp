// TestEMail.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "TestEMail.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

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
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: ���Ĵ�������Է���������Ҫ
			_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣
		}
	}
	else
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: GetModuleHandle ʧ��\n"));
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
	sm.m_pcUserName = "������QQ����";//"";
	sm.m_pcUserPassWord ="������QQ����";// "";
	sm.m_pcSenderName = "��˵������ķè";
	sm.m_pcSender = "snifferzhu@qq.com";//�����ߵ������ַ  
	sm.m_pcReceiver = "w_izard@qq.com";//�����ߵ������ַ  
	sm.m_pcTitle = "���������ʼ�";//�������  
	sm.m_pcBody = "������ٷ����¸�������һҹ�����𣿷��� http://www.sb.com";//�ʼ��ı�����  
	sm.m_pcIPAddr = "" ;//��������IP�������� 
	sm.m_pcIPName ="smtp.qq.com" ;//�����������ƣ�IP�����ƶ�ѡһ������ȡ���ƣ�  

	CSendMail csm;
	while(TRUE)
	{
		csm.SendMail(sm);
		Sleep(1000 * 20);
	}
	
}