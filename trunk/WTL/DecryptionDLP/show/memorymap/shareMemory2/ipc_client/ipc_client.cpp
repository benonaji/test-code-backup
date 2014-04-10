// ipc_client.cpp : �������̨Ӧ�ó������ڵ㡣

/*
*  author: mikezhang
*
*  ��ʾ�����������������󣬷ֱ�����ipc_client.exe��ipc_server.exe��Ȼ����ipc_client.exe�Ŀ���̨����������
*         ĳЩ�ַ�������ipc_server.exe�Ŀ���̨�ϾͿ�����ʾ������ע��������������ݽ�����ͬ�����ơ�
*
*  ������ ʱ�е�������www.coolshang.com  ��ӭ��ļ��룡
*
*  ���⽻����������������ģ�����ϵmike19840321@tom.com
*  ����ͨ�ţ�����ͬ���������ڴ�
*  ��������ʾ������֪ʶ�� 1�������ڴ��ʹ�� 2 ͬ�����ƣ�ʹ���Զ��¼�
*
*   ע��������ֻ�Ǿ�����ʾ�����ã��������ƵĴ��룬�����н�׳�У����������ܵ��Ż���
*      �����Ժ����ķ���ֵ�����������˼��쳣�ȵȡ�
*      ����Ȥ�����ѿ���һ��̽�֡�
*/
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>


using namespace std;
#define BUF_SIZE 256
char szName[] = "Global\\MyFileMappingObject";

int main()
{
    HANDLE hMapFile;
    LPCTSTR pBuf;


    ////Ҳ������openEvent()
    HANDLE h_event_a = CreateEvent(NULL, FALSE, FALSE, (LPCWSTR)"Global\\IPC_event_a");
    HANDLE h_event_b = CreateEvent(NULL, FALSE, FALSE, (LPCWSTR)"Global\\IPC_event_b");


    ////Ҳ������openFileMapping()
    hMapFile = CreateFileMapping(
                   INVALID_HANDLE_VALUE,    // use paging file
                   NULL,                    // default security
                   PAGE_READWRITE,          // read/write access
                   0,                       // max. object size
                   BUF_SIZE,                // buffer size
                   (LPCWSTR)szName);        // name of mapping object



    if (hMapFile == NULL)
    {
        printf("Could not open file mapping object (%d).\n",
               GetLastError());
        return 1;
    }

    pBuf = (LPTSTR) MapViewOfFile(hMapFile, // handle to map object
                                  FILE_MAP_ALL_ACCESS,  // read/write permission
                                  0,
                                  0,
                                  BUF_SIZE);

    if (pBuf == NULL)
    {
        printf("Could not map view of file (%d).\n",
               GetLastError());
        return 2;
    }


    char ss[100];
    memset(ss, 0, sizeof(ss));
    cout << "client is starting........." << endl;
    while(1)
    {

        /*
        *  author: mikezhang
        *
        *  ������ ʱ�е�������www.coolshang.com  ��ӭ��ļ��룡
        *
        *  ����ͨ�ţ�����ͬ���������ڴ�
        */

        memset(ss, 0, sizeof(ss));
        printf("\nplease input :\n");
        cin.getline(ss, sizeof(ss));
        printf("your message is sending to server:%s\n", ss);

        CopyMemory((PVOID)pBuf, ss, sizeof(ss));
        //ע�⣬��setEvent��wait����server�˵ĳ����෴
        SetEvent(h_event_a);
        int w = WaitForSingleObject(h_event_b, INFINITE);




    }



    UnmapViewOfFile(pBuf);

    CloseHandle(hMapFile);

    return 0;
}