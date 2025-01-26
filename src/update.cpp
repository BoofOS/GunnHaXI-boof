//
// Created by linux on 1/25/25.
//

#include "update.h"

#include <fzf_search.h>

inline bool file_exists (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

int rename_package_lists();

update_status update() {
	download(BOOF_PACKAGE_URL, BOOF_PACKAGE_LIST + ".tmp.xz");
	run_command("unxz " + BOOF_PACKAGE_LIST + ".tmp.xz > " + BOOF_PACKAGE_LIST + ".tmp");
	rename_package_lists();
	std::rename((BOOF_PACKAGE_LIST + ".tmp").c_str(), BOOF_PACKAGE_LIST.c_str());
	return update_status::UPDATE_SUCCESS;
};

int rename_package_lists() {
	bool p = file_exists(BOOF_PACKAGE_LIST);
	bool p1 = file_exists(BOOF_PACKAGE_LIST + ".old1");
	bool p2 = file_exists(BOOF_PACKAGE_LIST + ".old2");
	bool p3 = file_exists(BOOF_PACKAGE_LIST + ".old3");

	if (p3 && p2) std::remove((BOOF_PACKAGE_LIST + ".old3").c_str());
	if (p2)
		std::rename((BOOF_PACKAGE_LIST + ".old2").c_str(),
		(BOOF_PACKAGE_LIST + ".old3").c_str());
	if (p2 && p1)
		std::remove((BOOF_PACKAGE_LIST + ".old2").c_str());
	if (p1)
		std::rename((BOOF_PACKAGE_LIST + ".old1").c_str(),
		(BOOF_PACKAGE_LIST + ".old2").c_str());
	if (p1 && p)
		std::remove((BOOF_PACKAGE_LIST + ".old1").c_str());
	if (p)
		std::rename((BOOF_PACKAGE_LIST).c_str(),
		(BOOF_PACKAGE_LIST + ".old1").c_str());

	return 0;
}
