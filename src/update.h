//
// Created by linux on 1/25/25.
//

#pragma once
#include <string>
#include <sys/stat.h>
#include "constants.h"
#include "fzf_search.h"
#include <cstdio>
#include <download.h>

enum class update_status;

update_status update();

enum class update_status {
	UPDATE_SUCCESS,
	UPDATE_FAILED,
};