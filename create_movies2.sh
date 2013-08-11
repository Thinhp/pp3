#!/bin/sh
# Script for mpeg movie creation from a collection of image frames
# Usage: sh create_mpg_movies.sh directory-name

usage()
{
	echo "Usage:"
	echo "sh create_movies2.sh directory"
}

## Runtime parameter check

#/bin/echo "Dollar0 " $0 "," $1 "," $#
if [ $# -eq 2 ]
then
	usage
	exit $?
fi

#/bin/echo "Dollar 1 " $1

cd $1

#Get the graph first
#perl ~/gpanalyse/bin/gplotgp
## Variables
# source frame variables
nth=1                   # pick every n-th best image as frame of the movie
source_frame_dir="png"  # directory to place source images for movie


# common variables
temp_dir="temporary"
#if temp_dir does not exist, create it
if [ ! -d $temp_dir ]
then
	mkdir $temp_dir
fi



### Do not modify below here ###


## Function
# cleanup clean everything in the temporary directory
# $1 = temp_dir
# $2 = param_file
cleanup()
{
	rm -R $1
#	rm $param_file
}



## Program flow
# loop and copy  the source frames file to temporary directory

# calculate and set the necessary variables
total=`ls $source_frame_dir/*.png | wc -l`
j=`expr $total / $nth \* 2 - 1`
i=1
counter=1
input="$input `printf [%.4d-%.4d] $i $j`"

# start converting and storing in the temporary directory
echo "Source Frame <-> Created Direct Frame <-> Created Reverse Frame"
for source_frame_file in `ls -1 $source_frame_dir/*.png`
do
	if [ `expr $counter % $nth` == 0 ]
	then
		direct_frame_file="frame`printf %.4d $i`.png"
		reverse_frame_file="frame`printf %.4d $j`.png"

                cp $source_frame_file $temp_dir/$direct_frame_file
                cp $source_frame_file $temp_dir/$reverse_frame_file
		echo "$source_frame_file <-> $direct_frame_file <-> $reverse_frame_file"

		i=`expr $i + 1`
		j=`expr $j - 1`

	fi
	
	counter=`expr $counter + 1`
done

# call ppmtopmeg to create the movie

tmpfile=`ls -1  temporary|head -1`

width=`pngtopnm temporary/$tmpfile|head -2|tail -n +2|cut -d" " -f1`
height=`pngtopnm temporary/$tmpfile|head -2|tail -n +2|cut -d" " -f2`
codec="-c:v libx264 -b:v 8000k"
container="mp4"

if [ `expr $width % 2` == 1 ]
then  codec="-b 2000k"; container="mpg"
else if  [ `expr $height % 2` == 1 ]
     then codec="-b 2000k"; container="mpg"
     fi       
fi

echo $codec "xx" $container
rm -f movie.$container
#ssh tango.vpac.org "module load ffmpeg;ffmpeg -f image2 -i ~/npr/$1/temporary/frame%04d.png $codec ~/npr/$1/movie.$container"
#ffmpeg -f image2 -i temporary/frame%04d.png $codec movie.$container
ffmpeg -f image2 -i temporary/frame%04d.png movie.$container
#cleanup $temp_dir

