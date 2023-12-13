#include "main.h"

/**
 * cd_shell - changes current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *datash)
{
	char *fd;
	int ishome, ishome2, isddash;

	fd = datash->args[1];

	if (fd != NULL)
	{
		ishome = _strcmp("$HOME", fd);
		ishome2 = _strcmp("~", fd);
		isddash = _strcmp("--", fd);
	}

	if (fd == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", fd) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", fd) == 0 || _strcmp("..", fd) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
