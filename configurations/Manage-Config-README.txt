1. This program needs JDK6. (http://www.oracle.com/technetwork/java/javase/downloads/index.html)    

2. This program MUST be in directory .../npr/configurations
   or
   .../mosaic/configurations

   A typical directory  might be
   c:\cygwin\home\user\evolved-art\npr\configurations

3. If untarring for npr
   /bin/rm mosaic_conf-template.txt
   mv quick-help-npr.txt quick-help.txt
   /bin/rm quick-help-mosaic.txt

   If untarring for mosaic
   /bin/rm npr-template.txt
   mv quick-help-mosaic.txt quick-help.txt
   /bin/rm quick-help-npr.txt

4. To start the program from windows, navigate to the above directory and
   double click Manage-Config.jar

5. To start the program from cygwin, cd to the above directory and type
   java -jar Manage-Config.jar &

6. Use "File">"Open" to choose your configuration file.

7. Use Quick Help to get the meanings of the parameter values.

8. You can save your configurations with "File">"Save" and 
    "File">"Save as"

9. When you are ready to do an evolutionary run click 
   "Save as Painter.txt"  or "Save as mosaic_conf.txt


