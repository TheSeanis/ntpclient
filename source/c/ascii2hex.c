#include<stdio.h>
int get_len_of_file(FILE *in)
{
	/*
		take in a file pointer
		iterate over it to get total num of chars
		return to variable

	*/

	char ch;
	int count = 0;


	while((ch=fgetc(in))!=EOF)
	{
		count++;
		printf("%c",ch);
	}
	return count;
}
/*
int ascii_to_hex(char c)
{
        int num = (int) c;
        if(num < 58 && num > 47)
        {
                return num - 48; 
        }
        if(num < 103 && num > 96)
        {
                return num - 87;
        }
        return num;
}
*/
int main(int argc, char* argv[]) {
    

    FILE* file = fopen("secret_file", "r");
    if(file == NULL) {
        printf("file is null\n");
        return 1;
    }

    int count = 0;
    char ch;
    do
    {
        unsigned char c = fgetc(file);
        if (feof(file))
            break;

        printf("%x", c);
    } while(1);
    printf("\n");
    fclose(file);
    return 0;
}

