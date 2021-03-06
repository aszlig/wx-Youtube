#ifndef DOWNLOAD_THREAD_H
#define DOWNLOAD_THREAD_H

#include <wx/thread.h>
#include "VideoInfo.hpp"
#include <cstdlib>
#include <curl/curl.h>
#include <string>
#include <iostream>
#include "DownloadCallback.hpp"


class DownloadThread : public wxThread
{

public:
    DownloadThread(VideoInfo* video_data, const std::string& url, const std::string& path, 
	   DownloadCallback* callback = 0, int (*progress_callback)(void*, double, double , double , double)=0);


    ~DownloadThread();
    virtual void* Entry();

protected:
    std::string m_url; //downolad url
    std::string m_path; //save path
    VideoInfo* m_video_data; //additional data required by callback function
    DownloadCallback* p_callback; //function object called on tread end
    int (*m_curl_progress_callback)(void*, double, double , double , double);

private:

    bool doDownload();  //fetches the file
};


#endif
