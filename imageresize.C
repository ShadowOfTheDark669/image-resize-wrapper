#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {

 char cmd[2048];
 char imgmgkparam[] = "\"%w\\n%h\\n\"";
 snprintf(cmd, 2048, "identify -format %s \"%s\"",imgmgkparam, argv[1]);
 
 FILE *cmd_f;
 cmd_f = popen(cmd, "r");
 char widthstr[100], heightstr[100];
 fgets(widthstr, 100, cmd_f);
 fgets(heightstr, 100, cmd_f);
 double width = atof(widthstr), height = atof(heightstr);
 
 printf("ORIG WIDTH: %lf\n", width);
 printf("ORIG HEIGHT:%lf\n", height);

 double rd_extent = atof(argv[2]);
 printf("REDUCTION THRESHOLD: %lf\n", rd_extent);

 double rd_width = width * (rd_extent/100);
 double rd_height = height * (rd_extent/100); 
 
 printf("REDUCED WIDTH: %lf\n", rd_width);
 printf("REDUCED HEIGHT: %lf\n", rd_height);

 char cmdfinal[2048];
 snprintf(cmdfinal, 2048, "magick \"%s\" -resize \"%lf\"x\"%lf\"! \"%s\"", argv[1], rd_width, rd_height, argv[3]);
 system(cmdfinal);
 printf("IMAGE RESIZE DONE SUCCESSFULLY!\n");
 	
}
