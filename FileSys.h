#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1

#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation
#include <string>
#include <iostream>



namespace fs = std::experimental::filesystem::v1;

using FileVec = std::vector<fs::path>;


class FileSys
{
public:
	FileSys();

	void get_current_path();
	fs::path img_folder = "image";
	fs::path img_path = "";
	FileVec matches;

private:
	fs::path _path;
	

	void find_files();
	bool has_matching_extension(fs::path path);
};
