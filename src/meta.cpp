//
// Created by eason on 1/25/25.
//

#include "meta.h"

void log_install(std::string pkg_name){
	FILE* meta_file = std::fopen(BOOF_PACKAGE_LIST.c_str(), "a");
	std::fprintf(meta_file, "%s\n", pkg_name.c_str());
	std::fclose(meta_file);
}
void log_download(std::string pkg_name){
    FILE* meta_file = std::fopen(BOOF_PACKAGE_META.c_str(), "a");
    std::fprintf(meta_file, "%s\n", pkg_name.c_str());
	std::fclose(meta_file);
}