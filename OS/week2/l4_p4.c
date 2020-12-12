#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char  *argv[])
{
	struct stat sb,sb2;
	int ret,ret2;
	//there are 2 types of links, soft and hardlink.
	//symbolic link is just a pointer. it is a softlink
	//we create a hardlink here
	symlink(argv[1], argv[2]);
	printf("NEW HARDLINK CREATED %s \n", argv[2]);
	//checking inodes of both
	ret = stat(argv[1], &sb);
	printf("Inode for original file: %ld\n", sb.st_ino);
	ret2 = stat(argv[2], &sb2);
	printf("Inode for hardlink: %ld\n", sb2.st_ino);
	//enter to unlink
	getchar();
	unlink(argv[2]);
	printf("FILE HAS BEEN UNLINKED\n");
	return 0;
}