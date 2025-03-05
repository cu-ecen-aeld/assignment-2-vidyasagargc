#include<stdio.h>
#include <unistd.h>  // For write() and close()
#include <fcntl.h>
#include <string.h>  // For strlen()
#include <syslog.h>

int main(int argc, char* argv[]) {
	char *writefile;
	if (argc < 3) {
		syslog(LOG_ERR, "arg1 \"%s\" not passed", argv[1]);
		return 1;
	}
	printf("%s %s", argv[1], argv[2]);
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// Write to file
	if (write(fd, argv[2], strlen(argv[2])) == -1) {
		perror("Error writing to file");
		syslog(LOG_DEBUG, "Writing \"%s\" to \"%s\"", argv[2], argv[1]);
		close(fd);
	}
}
