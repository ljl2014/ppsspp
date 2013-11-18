#pragma once

#include <string>
#include <vector>

#include "file/file_util.h"

// Abstraction above path that lets you navigate easily.
// "/" is a special path that means the root of the file system. On Windows,
// listing this will yield drives.
class PathBrowser {
public:
	PathBrowser() {}
	PathBrowser(std::string path) { SetPath(path); }

	void SetPath(const std::string &path);
	void GetListing(std::vector<FileInfo> &fileInfo, const char *filter = 0);
	void Navigate(const std::string &path);

	std::string GetPath() {
		if (path_ != "/")
			return path_;
		else
			return "";
	}
	std::string GetFriendlyPath() {
		std::string str = GetPath();
		/*
#ifdef ANDROID
		if (!memcmp(str.c_str(), g_Config.memCardDirectory.c_str(), g_Config.memCardDirectory.size()))
		{
			str = str.substr(g_Config.memCardDirectory.size());
		}
#endif*/
		return str;
	}

	std::string path_;
};

