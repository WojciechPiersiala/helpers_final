#!/bin/bash
CURR_DIR=$(pwd)
DEST_DIR="converted"

##  Clear data from previous conversion
if [ -d "$DEST_DIR" ]; then
    rm -Rf $DEST_DIR; 
fi
mkdir $DEST_DIR

##  List PCD files in current directory
FILES=$(ls $CURR_DIR | grep .pcd)

##  Convert all PCD files
for f in $FILES; do
    FIL_PCD=$f
    FIL_XYZ=$DEST_DIR/"${FIL_PCD%%.*}".xyz
    touch $FIL_XYZ
    echo "converted files: " $FIL_PCD $FIL_XYZ

    ls $DEST_DIR
    sed '1,12d' $FIL_PCD > $FIL_XYZ
    head $FIL_XYZ
done