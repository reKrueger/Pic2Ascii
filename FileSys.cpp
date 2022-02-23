#include "FileSys.h"


FileSys::FileSys():matches(FileVec())
{
	_path /= fs::current_path();
}

void FileSys::get_current_path()
{
	_path /= img_folder; // setting folderpath befor ::get_current_path()
	find_files();
	return;
	
}
void FileSys::find_files()
{
	auto files = std::vector<fs::path>{};

	for (auto it = fs::directory_iterator(_path); it != fs::directory_iterator{}; ++it)
	{
		const auto current_file = *it;

		if (fs::is_regular_file(current_file.path()) && has_matching_extension(current_file.path()))
		{
			matches.push_back(current_file.path());
			
		}
	}

	return;
}

bool FileSys::has_matching_extension(fs::path path)
{
	const auto allowed_extensions = std::vector<std::string>{ ".bmp" };
	for (const auto& extension : allowed_extensions)
	{
		if (path.extension() == extension)
		{
			return true;
		}
	}

	return false;
}
