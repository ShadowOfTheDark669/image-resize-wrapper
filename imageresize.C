#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

 char cmdw[2048];
 snprintf(cmdw, 2048, "identify -format %\"w\" \"%s\"", argv[1]);

 char cmdh[2048];
 snprintf(cmdh, 2048, "identify -format %\"h\" \"%s\"", argv[1]);

 FILE *cmd_w;
 cmd_w = popen(cmdw, "r\0");
 char widthstr[100];
 fgets(widthstr, 100, cmd_w);
 double width = atof(widthstr);

 FILE *cmd_h;
 cmd_h = popen(cmdh, "r\0");
 char heightstr[100];
 fgets(heightstr, 100, cmd_h);
 double height = atof(heightstr);

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
