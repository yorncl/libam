# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
int main(void)
{
	printf("=========================================\n=============== FT_STRLEN ===============\n=========================================\n\n");
	printf("Test (\"\"):\nExpected result = %zu\nResult          = %zu\n\n", strlen(""), ft_strlen(""));
	printf("Test (\"zouglou\"):\nExpected result = %zu\nResult          = %zu\n\n", strlen("zouglou"), ft_strlen("zouglou"));
	printf("Test (\"zouglou danse la danse du magicien\"):\nExpected result = %zu\nResult          = %zu\n\n", strlen("zouglou danse la danse du magicien"), ft_strlen("zouglou danse la danse du magicien"));
	printf("\n=========================================\n=============== FT_STRCPY ===============\n=========================================\n\n");
	char	dst[50];
	char	dst2[50];
	char	dst3[50];
	char	dst4[50];
	char	dst_true[50];
	char	dst2_true[50];
	char	dst3_true[50];
	char	dst4_true[50];
	printf("Test (dst, \"\"):\nExpected result = %s\nResult          = %s\n\n", strcpy(dst_true, ""), ft_strcpy(dst, ""));
	printf("Test (dst, \"zouglou\"):\nExpected result = %s\nResult          = %s\n\n", strcpy(dst2_true, "zouglou"), ft_strcpy(dst2, "zouglou"));
	printf("Test (dst, \"zouglou danse la danse du magicien\"):\nExpected result = %s\nResult          = %s\n\n", strcpy(dst3_true, "zouglou danse la danse du magicien"), ft_strcpy(dst3, "zouglou danse la danse du magicien"));
	printf("Test (dst, \"zoug\\0lou danse la danse du magicien\"):\nExpected result = %s\nResult          = %s\n\n", strcpy(dst4_true, "zoug\0lou danse la danse du magicien"), ft_strcpy(dst4, "zoug\0lou danse la danse du magicien"));
	printf("\n=========================================\n=============== FT_STRCMP ===============\n=========================================\n\n");
	printf("Test (\"\", \"\"):\nExpected result = %d\nResult          = %d\n\n", strcmp("", ""), ft_strcmp("", ""));
	printf("Test (\"zouglou\", \"zouglou\"):\nExpected result = %d\nResult          = %d\n\n", strcmp("zouglou", "zouglou"), ft_strcmp("zouglou", "zouglou"));
	printf("Test (\"AAA\", \"ABC\"):\nExpected result = %d\nResult          = %d\n\n", strcmp("AAA", "ABC"), ft_strcmp("AAA", "ABC"));
	printf("Test (\"CCC\", \"ABC\"):\nExpected result = %d\nResult          = %d\n\n", strcmp("CCC", "ABC"), ft_strcmp("CCC", "ABC"));
	printf("Test (\"AAA\", \"A\"):\nExpected result = %d\nResult          = %d\n\n", strcmp("AAA", "A"), ft_strcmp("AAA", "A"));
	printf("Test (\"AAA\", \"AAAA\"):\nExpected result = %d\nResult          = %d\n\n", strcmp("AAA", "AAAA"), ft_strcmp("AAA", "AAAA"));
	printf("\n=========================================\n=============== FT_WRITE ================\n=========================================\n\n");
	printf("Test (1, \"\", 0):\n");
	printf("Expected result = %zd\nResult          = %zd\n\n", write(1, "", 0), ft_write(1, "", 0));
	printf("Test (1, \"zouglou\\n\", 8):\n");
	printf("Expected result = %zd\nResult          = %zd\n\n", write(1, "zouglou\n", 8), ft_write(1, "zouglou\n", 8));
	printf("Test (1, \"zouglou danse\\n la danse du magicien\", 14):\n");
	printf("Expected result = %zd\nResult          = %zd\n\n", write(1, "zouglou danse\n la danse du magicien\n", 14), ft_write(1, "zouglou danse\n la danse du magicien\n", 14));
	printf("Test (-25, \"zouglou\\n\", 8):\n");
	printf("Expected result = %zd\nResult          = %zd\n\n", write(-25, "zouglou\n", 8), ft_write(-25, "zouglou\n", 8));
	printf("Test (1, \"zouglou\\n\", -25):\n");
	printf("Expected result = %zd\nResult          = %zd\n\n", write(1, "zouglou\n", -25), ft_write(1, "zouglou\n", -25));
	printf("Test (1, NULL, 8):\n");
	printf("Expected result = %zd\nResult          = %zd\n", write(1, NULL, 8), ft_write(1, NULL, 8));
	printf("\n=========================================\n================ FT_READ ================\n=========================================\n\n");
	int		fd;
	int		fd2;
	int		fd_true;
	int		fd2_true;
	char	buf[50];
	char	buf2[50];
	char	buf3[50];
	char	buf_true[50];
	char	buf2_true[50];
	char	buf3_true[50];
	fd = open("./test2.c", O_RDONLY);
	fd2 = open("./test2.c", O_RDONLY);
	fd2_true = open("./test.c", O_RDONLY);
	fd_true = open("./test.c", O_RDONLY);
	buf3[0] = '\0';
	buf3_true[0] = '\0';
	printf("Test (fd, buf, 13):\nExpected result = %zd\nResult          = %zd\nBuf_true = %s\nBuf      = %s\n\n", read(fd_true, buf_true, 13), ft_read(fd, buf, 13), buf_true, buf);
	printf("Test (fd, buf, 13):\nExpected result = %zd\nResult          = %zd\nBuf_true = %s\nBuf      = %s\n\n", read(fd_true, buf_true, 13), ft_read(fd, buf, 13), buf_true, buf);
	printf("Test (fd2, buf2, 50):\nExpected result = %zd\nResult          = %zd\nBuf2_true = %s\nBuf2      = %s\n\n", read(fd2_true, buf2_true, 50), ft_read(fd2, buf2, 50), buf2_true, buf2);
	printf("Test (-1, buf3, 13):\nExpected result = %zd\nResult          = %zd\nBuf3_true = %s\nBuf3      = %s\n\n", read(-1, buf3_true, 13), ft_read(-1, buf3, 13), buf3_true, buf3);
	printf("Test (fd, NULL, 13):\nExpected result = %zd\nResult          = %zd\nNULL_true = %d\nNULL      = %d\n\n", read(fd_true, NULL, 13), ft_read(fd, NULL, 13), 0, 0);
	printf("Test (fd, buf3, -25):\nExpected result = %zd\nResult          = %zd\nBuf3_true = %s\nBuf3      = %s\n", read(fd_true, buf3_true, -25), ft_read(fd, buf3, -25), buf3_true, buf3);
	close(fd);
	close(fd2);
	close(fd2_true);
	close(fd_true);
	printf("\n=========================================\n=============== FT_STRDUP ===============\n=========================================\n\n");
	printf("Test (\"\"):\nExpected result = %s\nResult          = %s\n\n", strdup(""), ft_strdup(""));
	printf("Test (\"zouglou\"):\nExpected result = %s\nResult          = %s\n\n", strdup("zouglou"), ft_strdup("zouglou"));
	printf("Test (\"zouglou danse la danse du magicien\"):\nExpected result = %s\nResult          = %s\n\n", strdup("zouglou danse la danse du magicien"), ft_strdup("zouglou danse la danse du magicien"));
	printf("Test (\"zoug\\0lou danse la danse du magicien\"):\nExpected result = %s\nResult          = %s\n\n", strdup("zoug\0lou danse la danse du magicien"), ft_strdup("zoug\0lou danse la danse du magicien"));
	return (0);
}