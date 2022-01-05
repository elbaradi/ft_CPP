#include <fstream>
#include <string>
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error: please provide three arguments [filename] [needle] [replacement]" << std::endl;
		return -1;
	}

	std::string	filename(argv[1]);
	std::string needle(argv[2]);
	std::string	repl(argv[3]);
	if (filename.empty() || needle.empty() || repl.empty())
	{
		std::cout << "Error: arguments cannot be empty" << std::endl;
		return -1;
	}

	std::ifstream	ifs(filename);
	if (!ifs.is_open())
	{
		std::cout << "Error: unable to open " << filename << std::endl;
		return -1;
	}

	std::string	file_1;
	std::string line;
  	while (getline(ifs, line))
	{
		if (ifs.eof())
			file_1 += line;
		else
   			file_1 += line + '\n';
	}
  	ifs.close();;

	std::string	file_2;
	std::size_t	needle_len = needle.length();
	std::size_t found = 0;
	while (found != std::string::npos)
	{
		found = file_1.find(needle);
		file_2.append(file_1, 0, found);
		if (found != std::string::npos)
			file_2.append(repl);
		if (found == std::string::npos)
			break ;
		file_1 = file_1.substr(found + needle_len);
	}
	
	filename += ".replace";
	std::ofstream	ofs(filename);
	if (ofs.is_open())
	{
		ofs << file_2;
    	ofs.close();
  	}
  	else
	{
		std::cout << "Error: unable to open " << filename << std::endl;
		return -1;
	}

	return 0;
}
