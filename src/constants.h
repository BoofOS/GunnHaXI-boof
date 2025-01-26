//
// Created by linux on 1/25/25.
//

#pragma once
#include <string>

#if (0)
const std::string BOOF_BASE_PATH = "/usr/boof";
const std::string BOOF_SYMLINK_PATH = "/usr/local/bin";
#else
const std::string BOOF_BASE_PATH = "/home/linux/boof";
const std::string BOOF_SYMLINK_PATH = "/home/linux/bin";
#endif

const std::string BOOF_STORE_PATH = BOOF_BASE_PATH + "/store";

const std::string BOOF_PACKAGE_LIST = BOOF_BASE_PATH + "/Packages";
const std::string BOOF_PACKAGE_META = BOOF_BASE_PATH + "/Metadata";

const std::string BOOF_PACKAGE_BASE_URL = "https://archive.archlinux.org/packages/.all";
const std::string BOOF_PACKAGE_URL = BOOF_PACKAGE_BASE_URL + "/index.0.xz";
