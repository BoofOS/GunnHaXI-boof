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
	CURL *curl = curl_easy_init();
	if (curl) {
		FILE *fp = fopen(outfilename.c_str(), "wb");
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		CURLcode res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		fclose(fp);
	}
	return 0;
}