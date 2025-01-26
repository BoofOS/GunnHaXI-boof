//
// Created by linux on 1/25/25.
//

#pragma once

enum class update_status;

update_status update();

enum class update_status {
	UPDATE_SUCCESS,
	UPDATE_FAILED,
};