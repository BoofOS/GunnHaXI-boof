//
// Created by eason on 1/25/25.
//
#pragma once
#include <string>
#include <sqlite3.h>
#include <vector>
#include <fstream>
#include "constants.h"

void log_install(std::string pkg_name);
void log_download(std::string pkg_name);