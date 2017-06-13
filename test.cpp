#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

char Buffer[3*1024];
char* buffer = 0;
char* my_strstr(char *haystack, const char *needle) {
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
    return 0;
}


// Parse the buffer to get the link.
char * GetLinkForPhase2(){
	char* saveptr,*token,*token1,songlink[1000];
	//saveptr = (char *)Buffer;
	//  token = strtok_r(buffer," ", &saveptr); // does nothing important.. just some trimming.
  // printf("first %s\n",token );
  token = my_strstr(buffer,"<head>");
	do {
    //for(int i=0;i<200;i++)

    // token = strtok_r(0,"<head>",&saveptr);
    // printf("middle %s\n",token );
    token = my_strstr(token,"<div class=\"C234\">");
    token = my_strstr(token,"<div class=\"C234\">");
    token = my_strstr(token,"<a href=\"");
		token1 = strtok_r(token,"\"",&saveptr);
    token1 = strtok_r(0,"\"",&saveptr);
    // printf("second %d\n",strlen(token1) );
		// token = strtok_r(0,"<div class=\"C234\">",&saveptr);
    // printf("third %s\n",saveptr );
		// token = strtok_r(0,"<a href=\"",&saveptr);
    printf("%s\n",token1 );
		// char* token1 = strtok_r(token,"\"",&saveptr);  // this token contains the song link.
    //return token1;

		strcpy(songlink, token1);
    // songlink[strlen(songlink)]='\0';
    // printf("%d\n",strlen(songlink));
    // printf("test %s\n",songlink);
    token = my_strstr(saveptr,"<div class=\"mt-icon C C5\">");
    // printf("test %s\n",token );
    token = my_strstr(token,"<span class=\"iconochive-");
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
token = my_strstr(buffer,"<head>");
	int cnt=0,len;
	do{
		cnt++;
    token = my_strstr(token,"<a class=\"format-summary download-pill\"");
		// token = strtok_r(buffer,"<a class=\"format-summary download-pill\"", &saveptr);
    token = my_strstr(token,"href=\"");
		token1 = strtok_r(token,"\"",&saveptr);
		token1 = strtok_r(0,"\"",&saveptr);  // this token contains the download link.

    // printf("songlink.. %s\n", token1 );
    strcpy(songlink, token1);
		len = strlen(token1);
    token=saveptr;
  }while(strcmp(token1+len-4,"mp3")!=0 && cnt<4); // If last 3 characters are
	return songlink;
}


int main(int argc, char const *argv[]) {
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
  char * phase_2_link = GetLinkForPhase2();
  printf("phase_2_link... %s\n",phase_2_link );

  fileName = "index.html.1"; /* should check that argc > 1 */

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
  char * final_link = GetDownloadLink();
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
