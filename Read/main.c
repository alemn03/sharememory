#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}


char ** readConfigFiel()
{
    char *configData[4];
    FILE *ptr_file;
    		char buf[1000];

    		ptr_file =fopen("config.txt","r");
    		if (!ptr_file)
        		return 1;

       for(int n=0; n < sizeof *configData;n++){

        while (fgets(buf,1000, ptr_file)!=NULL)
    		{

                char** tokens;
                tokens = str_split(buf, ':');

                if (tokens)
                        {


                            int i;
                            for (i = 0; *(tokens + i); i++)
                            {

                            if(i=1){
                             printf("i=[%d]\n", i);
                             printf("%s \n", *(tokens + i));
                             configData[n]= (char*) *(tokens + i);
                             free(*(tokens + i));
                            }
                            printf("\n");
                            free(tokens);

                        }



            }
        }


        }



		fclose(ptr_file);


    		return configData;

}

int main()
{

 char *config = readConfigFiel();



    return 0;
}
