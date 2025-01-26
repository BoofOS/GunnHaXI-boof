//
// Created by linux on 1/25/25.
//

#include "download.h"
#include <curl/curl.h>
#include <string>

size_t write_data(const void *ptr, const size_t size, const size_t nmemb, FILE *stream) {
	size_t written = fwrite(ptr, size, nmemb, stream);
	return written;
}

int download(const std::string &url,const std::string &outfilename) {
	CURL *curl_handle;
	static const char *pagefilename = "page.out";
	FILE *pagefile;
	curl_global_init(CURL_GLOBAL_ALL);
	curl_handle = curl_easy_init();
	curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 0L);
	curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 0L);
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
	pagefile = fopen(outfilename.c_str(), "wb");
	if(pagefile) {
		curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);
		curl_easy_perform(curl_handle);
		fclose(pagefile);
	}
	curl_easy_cleanup(curl_handle);
	curl_global_cleanup();
	return 0;
}