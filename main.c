#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
char 	*ft_strcpy(char *dest, const char *src);
int 	ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char 	*ft_strdup(const char *s);

void	free_od_array(char **array);

int	main(void)
{
	char	*Separator_line = "------------------------------"; //---------------
	char	*high_brightness = "\x1b[1m";
	char	*yellow = "\x1b[33m";
	char	*magenta = "\x1b[35m";
	char	*default_ = "\x1b[0m";

	printf("\n%s%s", high_brightness, yellow);
	printf("%s%s%s", Separator_line, "libasm test", Separator_line);
	printf("%s\n\n", default_);

	//testcase
	char	*test_str_nullc	= "";
	char	*test_str_blank	= " ";
	char	*test_str_hello	= "hello!";
	char	*test_str_long	= "As consumers pay more attention to package labels, and legislation starts requiring food companies to be upfront about what goes into their products, downsizing has become a popular way for good businesses to deal with increasing pressure to cut calories and boost healthiness in processed foods.";

	//ft_strlen

	size_t	rt;
	size_t	ft_rt;

	printf("%s%s", high_brightness, magenta);
	printf("%s", "1.ft_strlen");
	printf("%s\n\n", default_);

	rt = strlen(test_str_nullc);
	printf("rt = [%zu], rt = strlen(\"\");\n", rt);
	ft_rt = ft_strlen(test_str_nullc);
	printf("ft_rt = [%zu], ft_rt = ft_strlen(\"\");\n", ft_rt);

	printf("\n------------------------------------\n\n");

	rt = strlen(test_str_blank);
	printf("rt = [%zu], rt = strlen(\"%s\");\n", rt, test_str_blank);
	ft_rt = ft_strlen(test_str_blank);
	printf("ft_rt = [%zu], ft_rt = ft_strlen(\"%s\");\n", ft_rt, test_str_blank);

	printf("\n------------------------------------\n\n");

	rt = strlen(test_str_hello);
	printf("rt = [%zu], rt = strlen(%s);\n", rt, test_str_hello);
	ft_rt = ft_strlen(test_str_hello);
	printf("ft_rt = [%zu], ft_rt = ft_strlen(%s);\n", ft_rt, test_str_hello);

	printf("\n------------------------------------\n\n");

	rt = strlen(test_str_long);
	printf("rt = [%zu], rt = strlen(%s);\n", rt, test_str_long);
	ft_rt = ft_strlen(test_str_long);
	printf("ft_rt = [%zu], ft_rt = ft_strlen(%s);\n", ft_rt, test_str_long);

	printf("\n");


	//ft_strcpy

	char	*rt1;
	char	*rt2;
	char	dest1[500];
	char	dest2[500];

	printf("%s%s", high_brightness, magenta);
	printf("\n%s", "2.ft_strcpy");
	printf("%s\n\n", default_);

	rt1 = strcpy(dest1, test_str_nullc);
	printf("%s\n", "rt1 = strcpy(dest1, \"\");");
	printf("rt1 = [%s], dest1 = [%s], rt1num = [%ld], dest1num = [%ld], rt1addr = [%p], dest1addr = [%p]\n\n", rt1, dest1, strlen(rt1), strlen(dest1), rt1, dest1);

	rt2 = ft_strcpy(dest2, test_str_nullc);
	printf("%s\n", "rt2 = ft_strcpy(dest2, \"\");");
	printf("rt2 = [%s], dest2 = [%s], rt2num = [%ld], dest2num = [%ld], rt2addr = [%p], dest2addr = [%p]\n\n", rt2, dest2, strlen(rt2), strlen(dest2), rt2, dest2);

	printf("------------------------------------\n\n");

	rt1 = strcpy(dest1, test_str_blank);
	printf("%s\n", "rt1 = strcpy(dest1, \" \");");
	printf("rt1 = [%s], dest1 = [%s], rt1num = [%ld], dest1num = [%ld], rt1addr = [%p], dest1addr = [%p]\n\n", rt1, dest1, strlen(rt1), strlen(dest1), rt1, dest1);

	rt2 = ft_strcpy(dest2, test_str_blank);
	printf("%s\n", "rt2 = ft_strcpy(dest2, \" \");");
	printf("rt2 = [%s], dest2 = [%s], rt2num = [%ld], dest2num = [%ld], rt2addr = [%p], dest2addr = [%p]\n\n", rt2, dest2, strlen(rt2), strlen(dest2), rt2, dest2);

	printf("------------------------------------\n\n");

	rt1 = strcpy(dest1, test_str_hello);
	printf("%s\n", "rt1 = strcpy(dest1, \"hello!\");");
	printf("rt1 = [%s], dest1 = [%s], rt1num = [%ld], dest1num = [%ld], rt1addr = [%p], dest1addr = [%p]\n\n", rt1, dest1, strlen(rt1), strlen(dest1), rt1, dest1);

	rt2 = ft_strcpy(dest2, test_str_hello);
	printf("%s\n", "rt2 = ft_strcpy(dest2, \"hello!\");");
	printf("rt2 = [%s], dest2 = [%s], rt2num = [%ld], dest2num = [%ld], rt2addr = [%p], dest2addr = [%p]\n\n", rt2, dest2, strlen(rt2), strlen(dest2), rt2, dest2);

	printf("------------------------------------\n\n");

	rt1 = strcpy(dest1, test_str_long);
	printf("%s\n", "rt1 = strcpy(dest1, test_str_long);");
	printf("rt1 = [%s], dest1 = [%s], rt1num = [%ld], dest1num = [%ld], rt1addr = [%p], dest1addr = [%p]\n\n", rt1, dest1, strlen(rt1), strlen(dest1), rt1, dest1);

	rt2 = ft_strcpy(dest2, test_str_long);
	printf("%s\n", "rt2 = ft_strcpy(dest2, test_str_long);");
	printf("rt2 = [%s], dest2 = [%s], rt2num = [%ld], dest2num = [%ld], rt2addr = [%p], dest2addr = [%p]\n\n", rt2, dest2, strlen(rt2), strlen(dest2), rt2, dest2);

	printf("\n");


	//ft_strcmp

	int rt1cmp;
	int rt2cmp;

	printf("%s%s", high_brightness, magenta);
	printf("%s", "3.ft_strcmp");
	printf("%s\n\n", default_);

	printf("rt1cmp = [%d], %s\n", rt1cmp = strcmp("", ""), "rt1cmp = strcmp(\"\", \"\");");
	printf("rt2cmp = [%d], %s\n", rt2cmp = ft_strcmp("", ""), "rt2cmp = ft_strcmp(\"\", \"\");");

	printf("\n------------------------------------\n\n");

	printf("rt1cmp = [%d], %s\n", rt1cmp = strcmp("", "abc"), "rt1cmp = strcmp(\"\", \"abc\");");
	printf("rt2cmp = [%d], %s\n", rt2cmp = ft_strcmp("", "abc"), "rt2cmp = ft_strcmp(\"\", \"abc\");");

	printf("\n------------------------------------\n\n");

	printf("rt1cmp = [%d], %s\n", rt1cmp = strcmp("abc", ""), "rt1cmp = strcmp(\"abc\", \"\");");
	printf("rt2cmp = [%d], %s\n", rt2cmp = ft_strcmp("abc", ""), "rt2cmp = ft_strcmp(\"abc\", \"\");");

	printf("\n------------------------------------\n\n");

	printf("rt1cmp = [%d], %s\n", rt1cmp = strcmp("abc", "abc"), "rt1cmp = strcmp(\"abc\", \"abc\");");
	printf("rt2cmp = [%d], %s\n", rt2cmp = ft_strcmp("abc", "abc"), "rt2cmp = ft_strcmp(\"abc\", \"abc\");");

	printf("\n");


	//ft_write

	ssize_t write_rt;
	ssize_t ft_write_rt;
	int	errnum;
	test_str_hello = "hello!\n";

	printf("%s%s", high_brightness, magenta);
	printf("\n%s", "4.ft_write");
	printf("%s\n\n", default_);

	printf("write(1, test_str_nullc, strlen(test_str_hello));\n");
	write_rt = write(1, test_str_nullc, strlen(test_str_nullc));
	printf("write_rt = %ld", write_rt);

	printf("\n\n");

	printf("ft_write(1, test_str_nullc, strlen(test_str_nullc));\n");
	ft_write_rt = ft_write(1, test_str_nullc, strlen(test_str_nullc));
	printf("ft_write_rt = %ld", ft_write_rt);


	printf("\n\n------------------------------------\n\n");


	printf("write(1, test_str_hello, strlen(test_str_hello));\n");
	write_rt = write(1, test_str_hello, strlen(test_str_hello));
	printf("write_rt = %ld", write_rt);

	printf("\n\n");

	printf("ft_write(1, test_str_hello, strlen(test_str_hello));\n");
	ft_write_rt = ft_write(1, test_str_hello, strlen(test_str_hello));
	printf("ft_write_rt = %ld", ft_write_rt);


	printf("\n\n------------------------------------\n\n");


	printf("write(-1, test_str_hello, strlen(test_str_hello));\n");
	write_rt = write(-1, test_str_hello, strlen(test_str_hello));
	errnum = errno;
	perror("write");
	printf("write_rt = %ld, errno = %d", write_rt, errnum);

	printf("\n\n");
	errnum = 0;
	errno = 0;

	printf("ft_write(-1, test_str_hello, strlen(test_str_hello));\n");
	ft_write_rt = ft_write(-1, test_str_hello, strlen(test_str_hello));
	errnum = errno;
	perror("ft_write");
	printf("ft_write_rt = %ld, errno = %d", ft_write_rt, errnum);


	printf("\n\n");


	//ft_read

	printf("%s%s", high_brightness, magenta);
	printf("\n%s", "5.ft_read");
	printf("%s\n\n", default_);

	bool read_flag;
	errnum = 0;
	errno = 0;
	//***********************************************
	read_flag = false; //true or false;
	//***********************************************
	if (read_flag == false)
		printf("read_flag = false\n\n");
	if (read_flag)
	{
		ssize_t read_rt;
		char *buf;

		buf = malloc(sizeof(char *) * 100);
		//read_rt = read(0, buf, 100);
		read_rt = ft_read(0, buf, 100);
		errnum = errno;
		perror("read");
		buf[read_rt] = '\0';
		printf("read_rt = %ld, errno = %d", read_rt, errnum);
		printf(" buf = %s\n", buf);
		free_od_array(&buf);
	}

	printf("\n");


	//ft_strdup

	char	*rt_strdup;
	char	*rt_ft_strdup;
	errnum = 0;
	errno = 0;

	printf("%s%s", high_brightness, magenta);
	printf("%s", "6.ft_strdup");
	printf("%s\n\n", default_);

	rt_strdup = strdup("");
	printf("rt_strdup = strdup(\"\");\n");
	printf("rt_strdup = [%s]\n", rt_strdup);
	printf("strlen(rt_strdup) = [%ld]\n", strlen(rt_strdup));
	printf("\n");
	rt_ft_strdup = ft_strdup("");
	printf("rt_ft_strdup = ft_strdup(\"\");\n");
	printf("rt_ft_strdup = [%s]\n", rt_ft_strdup);
	printf("strlen(rt_ft_strdup) = [%ld]\n", strlen(rt_ft_strdup));

	free_od_array(&rt_strdup);
	free_od_array(&rt_ft_strdup);
	printf("\n------------------------------------\n\n");

	rt_strdup = strdup("hello!");
	printf("rt_strdup = strdup(\"hello!\");\n");
	printf("rt_strdup = [%s]\n", rt_strdup);
	printf("strlen(rt_strdup) = [%ld]\n", strlen(rt_strdup));
	printf("\n");
	rt_ft_strdup = ft_strdup("hello!");
	printf("rt_ft_strdup = ft_strdup(\"hello!\");\n");
	printf("rt_ft_strdup = [%s]\n", rt_ft_strdup);
	printf("strlen(rt_ft_strdup) = [%ld]\n", strlen(rt_ft_strdup));

	free_od_array(&rt_strdup);
	free_od_array(&rt_ft_strdup);
	printf("\n------------------------------------\n\n");

	rt_strdup = strdup(test_str_long);
	printf("rt_strdup = strdup(test_str_long);\n");
	printf("rt_strdup = [%s]\n", rt_strdup);
	printf("strlen(rt_strdup) = [%ld]\n", strlen(rt_strdup));
	printf("\n");
	rt_ft_strdup = ft_strdup(test_str_long);
	printf("rt_ft_strdup = ft_strdup(test_str_long);\n");
	printf("rt_ft_strdup = [%s]\n", rt_ft_strdup);
	printf("strlen(rt_ft_strdup) = [%ld]\n", strlen(rt_ft_strdup));

	free_od_array(&rt_strdup);
	free_od_array(&rt_ft_strdup);
	printf("\n");
	return (0);
}

void	free_od_array(char **array)
{
	if (array)
	{
		free(*array);
		*array = NULL;
	}
}
