#include <ifaddrs.h>
#include <stdio.h>
int main()
{
struct ifaddrs *id;
int val;
val = getifaddrs(&id);
printf("Network Interface Name :- %s\n",id->ifa_name);
printf("Network Address of %s :- %d\n",id->ifa_name,id->ifa_addr);
printf("Network Data :- %d \n",id->ifa_data);
printf("Socket Data : -%c\n",id->ifa_addr->sa_data);
return 0;
}
