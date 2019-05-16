#include <stdio.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>

int find_ip_address(char *, char *);

int main()
{
      char hostname[50], ip_address[50];
      printf("\nEnter a Hostname\t");
      scanf("%s", hostname);
      find_ip_address(hostname , ip_address);
      printf("\nIP Address of Hostname %s:\t%s\n", hostname, ip_address);
      return 0;
}

int find_ip_address(char *hostname, char *ip_address)
{
      struct hostent *host_name;
      struct in_addr **ipaddress;
      int count;
      if((host_name = gethostbyname(hostname)) == NULL)
      {
            herror("\nIP Address Not Found\n");
            return 1;
      }
      else
      {
            ipaddress = (struct in_addr **) host_name->h_addr_list;
            for(count = 0; ipaddress[count] != NULL; count++)
            {
                  strcpy(ip_address, inet_ntoa(*ipaddress[count]));
                  return 0;
            }
      }
      return 1;
}
