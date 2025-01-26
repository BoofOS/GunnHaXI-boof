//
// Created by linux on 1/25/25.
//

#pragma once
#include <string>

#if (0)
const std::string BOOF_BASE_PATH = "/usr/boof";
#else
const std::string BOOF_BASE_PATH = "/home/linux/boof";
#endif

const std::string BOOF_STORE_PATH = BOOF_BASE_PATH + "/store";

const std::string BOOF_PACKAGE_LIST = BOOF_BASE_PATH + "/Packages";
const std::string BOOF_PACKAGE_META = BOOF_BASE_PATH + "/Metadata";

const std::string BOOF_PACKAGE_URL = "https://archive.archlinux.org/packages/.all/index.0.xz";
