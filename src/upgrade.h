//
// Created by linux on 1/25/25.
//

#pragma once

enum class upgrade_status ;

upgrade_status upgrade();

enum class upgrade_status {
	UPGRADE_SUCCESS,
	UPGRADE_FAILED,
};