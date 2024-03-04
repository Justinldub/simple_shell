#include "shell.h"
#include "util.h"
#include <dirent.h>
/**
  * ls_l - function that lists contents of the current 
  * working directory and in long format
  * @args - command line argument
  * Return: return 1 to continue the loop when the program 
  * is done executing
  */
int ls_l(char **args)
{
	DIR *dir;
	struct dirent *entry;
	struct stat file_stat;
	printf("attempting to run ls -l command");
	if(args[1] == NULL)
		return (1);
	/* Open the current directory */
	if ((dir = opendir(".")) == NULL)
	{
		perror("opendir() error");
		return 1;
	}

	/* Iterate over each entry in the directory */
	while ((entry = readdir(dir)) != NULL)
	{
	/* Get detailed information about the file */
		if (stat(entry->d_name, &file_stat) < 0)
		{
			perror("stat() error");
			continue;
		}
		/* Print file permissions */
		printf((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
		printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
		printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
		printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
		printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
		printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
		printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
		printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
		printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
		printf((file_stat.st_mode & S_IXOTH) ? "x " : "- ");

		/* Print number of hard links */
		printf("%ld ", (long)file_stat.st_nlink);

		/* Print owner name */
		struct passwd *pw = getpwuid(file_stat.st_uid);
		printf("%s ", pw ? pw->pw_name : "Unknown");

		/* Print group name */
		struct group *gr = getgrgid(file_stat.st_gid);
		printf("%s ", gr ? gr->gr_name : "Unknown");

		/* Print file size */
		printf("%lld ", (long long)file_stat.st_size);
		
		/* Print last modified time */
		char time_str[100];
		strftime(time_str, sizeof(time_str), "%b %d %H:%M", localtime(&file_stat.st_mtime));
		printf("%s ", time_str);

		/* Print file name */
		printf("%s\n", entry->d_name);
		}

		/* Close the directory */
		closedir(dir);
		return (1);
}
