//Given below are the functions which doesn't require any kind of root privileges to run it
//functions: B(),E(),F(),H(),I(),J()


void functionB() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("ERROR");
        return;
    }

    printf("--------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(*entry->d_name))
            continue;
         
        printf("%s\n", entry->d_name);
    }


    closedir(dir);
}



#define BUFFER_SIZE 1024
#define NUM_LINES_TO_READ 20

void functionE() {
    const char *file_path = "/var/log/syslog";
    
    char *my_strdup(const char *str) {
        size_t len = strlen(str) + 1;
        char *new_str = (char*)malloc(len);
        if (new_str) {
            strcpy(new_str, str);
        }
        return new_str;
    }

    FILE *logFile = fopen(file_path, "r");

    if (logFile == NULL) {
        perror("Error");
        return;
    }

    char buffer[BUFFER_SIZE];
    char CharsString[NUM_LINES_TO_READ + 1];
    int line_count = 0;

    while (fgets(buffer, BUFFER_SIZE, logFile) != NULL && line_count < NUM_LINES_TO_READ) {
        if (buffer[57] != '\n' && buffer[57] != '\0') {
            CharsString[line_count] = buffer[57];
            line_count++;
        }
    }

    while (line_count < NUM_LINES_TO_READ) {
        CharsString[line_count] = '\0';
        line_count++;
    }

    fclose(logFile);

    char *generatedString = my_strdup(CharsString);
    if (generatedString != NULL) {
        printf("Generated string: %s\n", generatedString);
        free(generatedString);
    } else {
        printf("Failed to generate the string.\n");
    }
}





void functionF(const char *cJ) {
    FILE *fp;
    char command[200];

    fp = fopen("/tmp/temp_cJ", "w");
    if (fp == NULL) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%s\n", cJ);

    fclose(fp);

    snprintf(command, sizeof(command), "crontab /tmp/temp_cJ");
    if (system(command) == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    remove("/tmp/temp_cJ");
}




void functionH(const char *hN) {
    struct addrinfo hints, *res;
    int status;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(hN, NULL, &hints, &res);
    if (status != 0) {
        fprintf(stderr, " error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    struct addrinfo *addr;
    for (addr = res; addr != NULL; addr = addr->ai_next) {
        char ip[INET6_ADDRSTRLEN];
        void *addr_ptr;

        if (addr->ai_family == AF_INET) { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)addr->ai_addr;
            addr_ptr = &(ipv4->sin_addr);
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)addr->ai_addr;
            addr_ptr = &(ipv6->sin6_addr);
        }

        inet_ntop(addr->ai_family, addr_ptr, ip, sizeof(ip));
        printf("%s\n", ip);
    }

    freeaddrinfo(res);

}




void I() {
    struct passwd *p;

    setpwent();
    while ((p = getpwent()) != NULL) {
        printf(": %s\n", p->pw_name);
        printf(": %d\n", p->pw_uid);
        printf(": %s\n", p->pw_dir);
        printf("\n");
    }
    endpwent();
}




void J() {
    const char *path = "/";

    struct statvfs vfs;

    if (statvfs(path, &vfs) == -1) {
        perror("Error getting file system information");
        exit(EXIT_FAILURE);
    }

    printf("Info for %s:\n", path);
    printf("------------------------------\n");
    printf("TS : %lu\n", vfs.f_frsize * vfs.f_blocks);
    printf("FS: %lu \n", vfs.f_frsize * vfs.f_bfree);
    printf("AS: %lu \n", vfs.f_frsize * vfs.f_bavail);
    printf("BS: %lu \n", vfs.f_frsize);
}

