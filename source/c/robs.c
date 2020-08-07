int main(int argc, char* argv[]) {
    FILE* file = fopen("secret_file", "r");
    if(file == NULL) {
        printf("file is null\n");
        return 1;
    }

    int count = 0;
    for(unsigned char ch = fgetc(in); ch != EOF; count++) {
        printf("0x%x", ch);
    }

    printf("\n");
    
    fclose(file);
    return 0;
}
