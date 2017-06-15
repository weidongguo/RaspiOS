#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;
char final_link[100] = {'\0'};
char Buffer[3*1024];
char* buffer = 0;
char* my_strstr(char *haystack, const char *needle,int &flag) {
  flag=0;
    if (haystack == 0 || needle == 0) {
        return 0;
    }

    for ( ; *haystack; haystack++) {
        // Is the needle at this point in the haystack?
        const char *h, *n;
        for (h = haystack, n = needle; *h && *n && (*h == *n); ++h, ++n) {
            // Match is progressing
        }
        if (*n == '\0') {
            // Found match!
            return haystack;
        }
        // Didn't match here.  Try again further along haystack.
    }
    printf("no match\n" );
    flag=1;
    return 0;
}


// Parse the buffer to get the link.
char * GetLinkForPhase2(){
	 char* saveptr,*token,*token1,songlink[1000];
  // token = (char*) memset(token,'\0',100000);
  // token1 = (char*)memset(token1,'\0',100000);
  memset(songlink,'\0',sizeof(songlink));
	//saveptr = (char *)Buffer;
	//  token = strtok_r(buffer," ", &saveptr); // does nothing important.. just some trimming.
  // printf("first %s\n",token );
  int flag=0;
  token = my_strstr(buffer,"<head>",flag);
	do {
    //for(int i=0;i<200;i++)

    // token = strtok_r(0,"<head>",&saveptr);
    // printf("middle %s\n",token );
    token = my_strstr(token,"<div class=\"C234\">",flag);
    token = my_strstr(token,"<div class=\"C234\">",flag);
    token = my_strstr(token,"<a href=\"",flag);
		token1 = strtok_r(token,"\"",&saveptr);
    token1 = strtok_r(0,"\"",&saveptr);
    // printf("second %d\n",strlen(token1) );
		// token = strtok_r(0,"<div class=\"C234\">",&saveptr);
    // printf("third %s\n",saveptr );
		// token = strtok_r(0,"<a href=\"",&saveptr);
    //printf("%s\n",token1 );
		// char* token1 = strtok_r(token,"\"",&saveptr);  // this token contains the song link.
    //return token1;
    // for (size_t i = 0; i < 1; i++) {
    //   printf("%c",*(token1+i) );
    //   if(*(token1+i)=='\0')
    //   {printf("here it is \n" );}
    // }
    //printf("\n");
    strcpy(songlink, token1);
    // songlink[strlen(songlink)]='\0';
    // printf("%d\n",strlen(songlink));
    // printf("test %s\n",songlink);
    token = my_strstr(saveptr,"<div class=\"mt-icon C C5\">",flag);
    // printf("test %s\n",token );
    token = my_strstr(token,"<span class=\"iconochive-",flag);
    // printf("test %s\n",token );
		// token = strtok_r(0,"<div class=\"mt-icon C C5\">",&saveptr);
		// token = strtok_r(0,"<span class=\"iconochive-",&saveptr);
		token1 = strtok_r(token,"-",&saveptr);
    token1 = strtok_r(0,"\"",&saveptr); // token1 contains whether it's audio or video or text...
    token=saveptr;
	} while(strcmp(token1,"audio") != 0);
	return songlink;
}

// Parse the buffer to get the final link to download the song.
char* GetDownloadLink(){
	char* saveptr,*token,*token1,songlink[1000];
  // token = strtok_r(buffer," ", &saveptr); // does nothing important.. just some trimming.

	int cnt=0,len;
  int flag=0;
  token = my_strstr(buffer,"<a class=\"stealth download-pill\"",flag);

  if(flag==1)
  	{
      printf("flag=1...\n" );
      token = my_strstr(buffer,"<div>",flag);
      do{
    		cnt++;
        token = my_strstr(token,"<a class=\"format-summary download-pill\"",flag);
    		// token = strtok_r(buffer,"<a class=\"format-summary download-pill\"", &saveptr);
        token = my_strstr(token,"href=\"",flag);
    		token1 = strtok_r(token,"\"",&saveptr);
    		token1 = strtok_r(0,"\"",&saveptr);  // this token contains the download link.

        printf("songlink.. %s\n", token1 );
        strcpy(songlink, token1);
    		len = strlen(token1);
        token=saveptr;
      }while(strcmp(token1+len-3,"mp3")!=0); // If last 3 characters are
  }
  else{
    printf("flag=0...\n" );
      token = my_strstr(buffer,"<div>",flag);
      do {

        token = my_strstr(token,"<a class=\"stealth download-pill\"",flag);
        token = my_strstr(token,"href=\"",flag);

        token1 = strtok_r(token,"\"",&saveptr);
    		token1 = strtok_r(0,"\"",&saveptr);  // this token contains the download link.

        strcpy(songlink, token1);
         printf("songlink.. %s\n", songlink );
    		len = strlen(token1);
        token=saveptr;
      } while(strcmp(token1+len-3,"mp3")!=0);
  }
   printf("songlink.. %s\n", songlink );
   strcpy(final_link,songlink);
	return songlink;
}


void modifysong(char* song1,char* song2)
{
	size_t i,j;
	for ( i = 0,j=0; *(song1+i)!='\0'; i++) {
		if(*(song1+i)==' ')
		{
			 *(song2+j) = '%'; j++;
			 *(song2+j) = '2'; j++;
			 *(song2+j) = '0'; j++;
		}
		else
		{
			*(song2+j)= *(song1+i); j++;
		}
	}
	*(song2+j)='\0';
}

int main(int argc, char const *argv[]) {

  // char song[100]={'\0'};
  // char newsong[100]={'\0'};
  // strcpy(song,"adele hello world");
  // modifysong(song,newsong);
  // printf("song: %s\n",song);
  // printf("newsong: %s\n",newsong);
  // return 0;
  char const*  fileName = "search.php?query=adele"; /* should check that argc > 1 */

  //char * buffer = 0;
  long length;
  FILE * f = fopen (fileName, "rb");
  if (f)
  {
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = (char*)malloc (length);
    if (buffer)
    {
      fread (buffer, 1, length, f);
    }
    fclose (f);
  }
  printf("\n" );
  char * phase_2_link = GetLinkForPhase2();

  printf("phase_2_link... %s\n",phase_2_link );

  fileName = "archive_Adele_201703.html"; /* should check that argc > 1 */

  buffer = 0;
  f = fopen (fileName, "rb");
  if (f)
  {
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = (char*)malloc (length);
    if (buffer)
    {
      fread (buffer, 1, length, f);
    }
    fclose (f);
  }
   GetDownloadLink();
  printf("Final_download_link... %s\n",final_link );
    // FILE* file = fopen(fileName, "r"); /* should check the result */
    // char *ptr = Buffer;
  	// int totalLen = 0;
    // while (fgets(ptr, 30, file)) {
    //     //printf("%s", line);
    //     ptr += 1000;
    //     totalLen += 1000;
    //     // if(totalLen>10000)
    //     //  return 0;
    // }
    // fclose(file);
    // printf("%s\n",buffer);

  return 0;
}
