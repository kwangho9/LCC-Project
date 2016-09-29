#include "stdio.h"
#include "string.h"
#include "time.h"

int main (int argc, char *argv[])
{
	FILE *src, *dest;
	int c, i=0, size, offset;
	unsigned long lc;
	char name[32];
	time_t now;

	if( argc < 2 ) {
		printf("usage : %s binary-file offset [ascii-file]\n", argv[0]);
		return -3;
	}

	if( (src=fopen(argv[1],"rb")) == NULL) {
		printf("%s Binary file open error!\n", argv[1]);
		return -1;
	}

	if( argc < 4 ) {
		int l = strlen(argv[1]) - 3;
		strncpy(name, argv[1], l);
		name[l] = '\0';
		strcat(name, "h");
		if( (dest=fopen(name,"wa")) == NULL) {
			printf("%s Ascii file open error!\n", name);
			return -1;
		}
	} else {
		if( (dest=fopen(argv[3],"wa")) == NULL) {
			printf("%s Ascii file open error!\n", argv[2]);
			return -1;
		}
	}

	if( argc < 3 ) {
		offset = 0;
	} else {
		offset = atoi((const char *)argv[2]);
	}
//	printf("offset = 0x%x\n", offset);

	fseek(src, 0, SEEK_END);
	size = ftell(src) - offset;
	fseek(src, offset, SEEK_SET);

	time(&now);
	fprintf(dest,"\n\/\/ Create : %s\n", ctime(&now));
//	printf("%s", ctime(&now));
	fprintf(dest,"#pragma location = 0x100\n");
	fprintf(dest,"__root const uint32_t binraw[] = {\n");

	i = 0;
	while((c=fgetc(src))!=EOF) {
		lc = c;
		c = fgetc(src);
		lc |= (c << 8);
		c = fgetc(src);
		lc |= (c << 16);
		c = fgetc(src);
		lc |= (c << 24);
		if( !(i++ & 0x7) ) fprintf(dest, "\n ");
		if( i == size ) {
			fprintf(dest,"0x%08x ", lc);
		} else {
			fprintf(dest,"0x%08x, ", lc);
		}
	}
	fprintf(dest, "\n};");
	fprintf(dest, "\n\n");
	printf("File Conversion Done!(0x%x offset, %d size)\n", offset, i);

	fclose(src);
	fclose(dest);

	return 0;
}

