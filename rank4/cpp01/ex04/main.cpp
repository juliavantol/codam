/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/25 22:51:33 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/25 23:43:43 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	replace_string(std::string s1, std::string s2, std::string line)
{
	std::string		output = line;
	size_t			found = line.find(s1);

	if (s1.empty())
		return output;
	while (found != std::string::npos)
	{
		output.erase(found, s1.length());
		output.insert(found, s2);
		found = output.find(s1, found + s2.length());
	}
	return output;
}

void	write_output(std::string str, std::string filename)
{
	std::ofstream	output;

	output.open(filename.c_str());
	if (!output.is_open())
	{
		std::cout << "Unable to open output file" << std::endl;
		return;
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '\\' && i + 1 < str.length() && str[i + 1] == 'n')
		{
			output << '\n';
			i++;
		}
		else
			output << str[i];
	}
	output.close();
}

int main(int argc, char **argv)
{
	std::ifstream	input;
	std::string		whole_file;
	std::string		line;
	std::string		output_file;
	
	if (argc != 4)
	{
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	input.open(argv[1]);
	if (!input.is_open())
	{
		std::cout << "Unable to open input file" << std::endl;
		return 0;
	}
	while (getline(input, line))
	{
		if (line.empty())
			whole_file.append("\\n");
		else
		{
			whole_file.append(line);
			whole_file.append("\\n");
		}
	}
	input.close();
	output_file = replace_string(argv[2], argv[3], whole_file);
	std::string filename = std::string(argv[1]) + ".replace";
	write_output(output_file, filename);
	return 0;
}