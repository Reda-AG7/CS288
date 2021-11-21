#include <stdio.h>
#include <unistd.h>

//my_uniq –c –d -u -f fields -s char input_file output_file 
int main(int argc, char *argv[])
{
  int opt;
  while((opt=getopt(argc,argv,":cduf:s:"))!=-1){
    switch(opt) {
      case 'c':
      case 'd':
      case 'u':
        printf("option: %c\n", opt); break;
      case 'f':
      case 's':
        printf("field: %s\n", optarg); break;
      case ':':
        printf("option %c needs a value\n", optopt); break;
      case '?':
        printf("unknown option: %c\n", optopt); break;
    }
  }
  for(; optind < argc; optind++)
    printf("argument: %s\n", argv[optind]);
  return 0;
}
