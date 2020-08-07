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
int main()
{
	int tot_count = 0;
	FILE *fp = fopen("test","r");
        unsigned char c1,c2;
        int i=0;
        unsigned char sum,final_hex[tot_count/2];
	tot_count = get_len_of_file(fp);

	for(i=0;i<tot_count;i++)
        {
                c1 = fgetc(fp);
		//c2 = fgetc(fp);
		//c1 = ascii_to_hex(fgetc(fp));
                //c2 = ascii_to_hex(fgetc(fp));
                //sum = c1<<4 | c2;
                //final_hex[i] = sum;
                //printf("sum is: %02x ",sum);
		printf("c1 is :%x \n", c1);
		//printf("c2 is :%02x ", c2);
        }

	printf("total is: %d", tot_count);
	printf("\n");
	fclose(fp);
        printf("\n");
}
