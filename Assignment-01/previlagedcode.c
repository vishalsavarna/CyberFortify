//Given below are the functions which require root privileges to run it
//functions: A(),C(),D(),G()


void functionA() {
    const char* fp = "/etc/logrotate.conf";
    const char* nd = "Rotate = 90";

    FILE* file = fopen(fp, "a");
    if (file == NULL) {
        perror("No File");
        return;
    }
    fprintf(file, "%s\n", nd);  

    fclose(file);
}


void functionC() {
    struct ifaddrs *ifaddr, *ifa;
    char* snet = NULL;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        if (ifa->ifa_addr->sa_family == AF_INET &&
            !(ifa->ifa_flags & IFF_LOOPBACK) &&        
            (ifa->ifa_flags & IFF_UP) &&               
            !(ifa->ifa_flags & IFF_POINTOPOINT) &&    
            !(ifa->ifa_flags & IFF_NOARP)) {           
            struct sockaddr_in *sa_in = (struct sockaddr_in *)ifa->ifa_addr;
            struct sockaddr_in *sa_netmask = (struct sockaddr_in *)ifa->ifa_netmask;

            snet = (char*)malloc(INET_ADDRSTRLEN);
            snprintf(snet, INET_ADDRSTRLEN, "%s/24", inet_ntoa(sa_in->sin_addr));
            break;
        }
    }

    freeifaddrs(ifaddr);

    if (snet == NULL) {
        printf("Failed \n");
        return;
    }

    char command[200];
    snprintf(command, sizeof(command), "iptables -A OUTPUT -s %s -d google.com -j DROP", snet);

    int ret = system(command);

    free(snet);

    if (ret == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    if (WIFEXITED(ret) && WEXITSTATUS(ret) == 0) {
        printf(" Added successfully.\n");
    } else {
        printf("Failed to add \n");
    }
}


void functionD(const char *iName) {
    FILE *fp;
    char filename[100];

    snprintf(filename, sizeof(filename), "/etc/systemd/network/%s.network", iName);
   
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error ");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "[Match]\nName=%s\n\n[Network]\nDHCP=yes\n", iName);
 
    fclose(fp);
}



int functionG(const char* cline) {
    if (cline == NULL || strlen(cline) == 0) {
        printf("Error\n");
        return 1;
    }

    FILE* ct_file = fopen("/etc/crontab", "a");
    if (!ct_file) {
        perror("Error");
        return 1;
    }

    fprintf(ct_file, "%s\n", cline);

    fclose(ct_file);

    if (system("systemctl restart cron") != 0) {
        printf("Error\n");
        return 1;
    }

    return 0;
}

